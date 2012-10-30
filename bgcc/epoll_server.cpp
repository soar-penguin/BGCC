/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _WIN32

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/poll.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <map>
#include <string>
#include <sstream>
#include <signal.h>
#include <string.h>

#include "epoll_server.h"
#include "service_framework.h"
#include "bgcc_error.h"
#include "log.h"
#include "thread_pool.h"
#include "server_task.h"
#include "server_peer_socket.h"
#include "binary_protocol.h"
#include "connection_manager.h"
#include "socket_util.h"

namespace bgcc {

    static std::map<int32_t, reading_item_t> _fd_readitem_map;

    static void read_callback(EventLoop* el, int32_t fd, void* arg);

    static void accept_callback(EventLoop* el, int32_t fd, void* arg) {
        int32_t newfd;
        struct sockaddr_in sin;
        socklen_t addrlen = sizeof(struct sockaddr);

        newfd = accept(fd, (struct sockaddr*)&sin, &addrlen);

        //BGCC1.0仅支持处理MAXNFD个连接
        if (newfd >= MAXNFD) {
            BGCC_TRACE("bgcc", "Too many client. Reject the new one");
            close(newfd);
            return;
        }

        if (-1 != newfd) {

            PeerInfo tmp("", 0);
            int32_t ret = getpeerinfo(newfd, tmp);
            if (ret != 0) {
                return;
            }

            BGCC_NOTICE("bgcc", "Accept an client from %s:%d", tmp.GetHost().c_str(), tmp.GetPort());

            Event e;
            e.fd = newfd;
            e.mask = EVENT_READ;
            e.read_cb = read_callback;
            e.read_cb_arg = arg;

            el->add_event(&e);
        }
    }

    static void enroll_proxy(const std::string& proxy_name, int32_t fd) {
        bgcc::ConnectionManager::get_instance()->enroll(proxy_name, fd);
    }

    static void read_callback(EventLoop* el, int32_t fd, void* arg) {
        int32_t ret;
        std::map<int32_t, reading_item_t>::iterator itr;
        bgcc::Mempool* mempool = bgcc::Mempool::get_instance();
        bgcc::ServiceManager* service_manager = ((bgcc::EpollServer*)arg)->get_service_manager();
        bgcc::ThreadPool* thread_pool = ((bgcc::EpollServer*)arg)->get_thread_pool();

        itr = _fd_readitem_map.find(fd);
        if (_fd_readitem_map.end() == itr) {
            itr = _fd_readitem_map.insert(std::make_pair(fd, reading_item_t())).first;
        }

        reading_item_t& item = itr->second;
        item.reset();
        char* p = item.head_buf;

        while (true) {
            ret = recv(fd, p + item.nread, item.nexpected, 0);
            if (ret < 0) {
                if (EINTR == errno) {
                    continue;
                }
                else if (EAGAIN == errno || EWOULDBLOCK == errno) {
                    return;
                }
                else {
                    BGCC_WARN("bgcc", "Counter an error. So remove fd %d from epoll and close it", fd);
                    goto END;
                }
            }
            else if (0 == ret) {
                BGCC_TRACE("bgcc", "Return value is 0 from SysCall `recv'. So remove fd %d from epoll and close it.", fd);
                goto END;
            }
            else if (ret > 0) {
                item.nread += ret;
                item.nexpected -= ret;
                if (0 == item.nexpected) {
                    if (S_SIZE_READING == item.state) {
                        item.state = S_DATA_READING;
                        item.nexpected = (int32_t)ntohl(*(uint32_t*)(p + 16));
                        if (item.nexpected < 0) {
                            BGCC_WARN("bgcc", "Message body's length is too short");
                            goto END;
                        }
                        item.nread = 0;
                        //TODO:if nexpected is negtive, then close it
                        item.data = (char*)mempool->get_mem_block(item.nexpected);
                        p = item.data;

                        continue;
                    }
                    else if (S_DATA_READING == item.state) {
                        //dispatch the data;
                        char* p_item_data = item.data;
                        int32_t processor_name_len = (int32_t)ntohl(*(uint32_t*)(p_item_data));
                        std::string processor_name(p_item_data + 4, processor_name_len);
                        BGCC_TRACE("bgcc", "\nMessage body\n"
                                "Processor name: %s",
                                processor_name.c_str());

                        if (processor_name == "bgcc::BaseProcessor_enroll") {
                            int32_t func_name_len = (int32_t)ntohl(*(uint32_t*)(
                                        p_item_data + 4 + processor_name_len + 8));
                            int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)(
                                        p_item_data + 4 + processor_name_len + 8
                                        + 4 + func_name_len));

                            std::string proxy_name(p_item_data + 4 + processor_name_len + 8
                                    + 4 + func_name_len + 4, proxy_name_len);
                            enroll_proxy(proxy_name, fd);
                            Event e;
                            e.fd = fd; 
                            e.mask = EVENT_READ;
                            el->del_event(&e);
                            mempool->put_mem_block(item.data);
                            return;
                        }

                        SharedPointer<IProcessor> processor = service_manager->get_service(processor_name);
                        if (processor.is_valid()) {
                            SharedPointer<ITransport> trans(new ServerPeerSocket(fd));
                            SharedPointer<IProtocol> proto(new BinaryProtocol(trans));
                            SharedPointer<Runnable> task(new ServerTask(processor, item.data, item.nread, proto));
                            thread_pool->addTask(task);
                        }
                        else {
                            BGCC_TRACE("bgcc", "Cannot find processor `%s`. Try to find ._baseservice_2012", processor_name.c_str());
                            processor = service_manager->get_service("._baseservice_2012");
                            if (processor.is_valid()) {
                                BGCC_TRACE("bgcc", "find ._baseservice_2012");
                                SharedPointer<BinaryProtocol> bp(new BinaryProtocol(SharedPointer<ITransport>(NULL)));

                                bp->writeMessageBegin("xx", "__service_not_found", bgcc::CALL, 0);
                                bp->writeInt32(0);
                                bp->writeString("__service_not_found");
                                bp->writeBool(false);

                                NBDataBuffer* db = bp->get_data_buffer();
                                Mempool::get_instance()->put_mem_block(item.data);
                                item.data = NULL;
                                item.nread = 0;

                                void* data = NULL;
                                db->get_data(&data, item.nread);

                                item.data = (char*)mempool->get_mem_block(item.nread);
                                memcpy(item.data, ((char*)data) + 20, item.nread - 20);

                                SharedPointer<ITransport> trans(new ServerPeerSocket(fd));
                                SharedPointer<IProtocol> proto(new BinaryProtocol(trans));
                                SharedPointer<Runnable> task(new ServerTask(processor, item.data, item.nread, proto));
                                thread_pool->addTask(task);
                            }
                        }

                        return;
                    }
                }
            }
        }
END:
        Event e;
        e.fd = fd;
        e.mask = EVENT_READ;
        el->del_event(&e);
        close(fd);
        if (item.data) {
            mempool->put_mem_block(item.data);
        }
    }

    EpollServer::EpollServer(ServiceManager* service_manager,
            ThreadPool* thread_pool,
            uint16_t port,
            const std::string & node) :
        _service_manager(service_manager),
        _thread_pool(thread_pool),
        _port(port),
        _state(S_UNINIT),
        _listenfd(-1),
        _node(node) {
        }

    int32_t EpollServer::init() {
        signal(SIGPIPE, SIG_IGN);
        if (S_UNINIT != _state) {
            BGCC_NOTICE("bgcc", "Instance of EpoolServer has already been initialized!\n");
            return E_BGCC_SERVER_ALREADY_INIT;
        }

        if (0 != _loop.create()) {
            return E_BGCC_SERVER_INIT_FAILED;
        }
        _state = S_INIT;
        return 0;
    }

    int32_t EpollServer::serve() {

        int32_t ret;
        if (0 != (ret = init())) {
            return ret;
        }

        if (S_INIT != _state) {
            BGCC_NOTICE("bgcc", "Need to call `init' before `serve' on Instance of EpollServer\n");
            return E_BGCC_SERVER_NEED_INIT;
        }

        _listenfd = socket_init();
        if (-1 == _listenfd) {
            return E_BGCC_SERVER_CREATE_LISTENFD_FAILED;
        }

        Event e;
        e.fd = _listenfd;
        e.mask = EVENT_READ;
        e.read_cb = accept_callback;
        e.read_cb_arg = const_cast<EpollServer*>(this);
        _loop.add_event(&e);

        BGCC_TRACE("bgcc", "Place listenfd %d into epoll for accept new client", _listenfd);

        _state = S_SERVE;
        BGCC_TRACE("bgcc", "Server goes into the loop of epoll_wait and then handle the fd(s) ready to read or write");
        return _loop.loop();
    }

    int32_t EpollServer::stop() {
        if (S_SERVE != _state) {
            return -1;
        }

        _loop.unloop();
        _loop.destroy();

        if (-1 != _listenfd) {
#ifndef _WIN32
            close(_listenfd);
#else
            closesocket(_listenfd);
#endif
            _listenfd = -1;
        }
        return 0;
    }

    ServiceManager* EpollServer::get_service_manager() {
        return _service_manager;
    }

    ThreadPool* EpollServer::get_thread_pool() {
        return _thread_pool;
    }

    int32_t EpollServer::socket_init() {
        int32_t ret = 0;
        char buffer[BUFSIZ];

        struct addrinfo hints, *res, *res0;
        memset(&hints, 0, sizeof(struct addrinfo));
        hints.ai_family = PF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_PASSIVE;

        std::stringstream ss;
        std::string port;
        ss << _port;
        ss >> port;

        ret = getaddrinfo(_node.empty() ? NULL : _node.c_str(), port.c_str(), &hints, &res0);
        if (0 != ret) {
            BGCC_WARN("bgcc", "Failed to call getaddrinfo");
            BGCC_WARN("bgcc", "[SYSINFO]%s\n", bgcc::bgcc_strerror_r(errno, buffer, BUFSIZ));
            freeaddrinfo(res0);
            return -1;
        }

        int listener;
        res = res0;
        if ((listener = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
            BGCC_WARN("bgcc", "Failed to create socket");
            BGCC_WARN("bgcc", "[SYSINFO]%s\n", bgcc::bgcc_strerror_r(errno, buffer, BUFSIZ));
            freeaddrinfo(res0);
            return -1;
        } 

        int so_reuseaddr = 1;
        setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &so_reuseaddr, sizeof(so_reuseaddr));

        if (bind(listener, res->ai_addr, res->ai_addrlen) == -1) {
            BGCC_WARN("bgcc", "Failed to bind port %d", _port);
            BGCC_WARN("bgcc", "[SYSINFO]%s\n", bgcc::bgcc_strerror_r(errno, buffer, BUFSIZ));
            freeaddrinfo(res0);
            close(listener);
            return -1;
        }
        freeaddrinfo(res0);

        if (listen(listener, MAXNFD) == -1) {
            BGCC_WARN("bgcc", "Failed to listen on port %d", _port);
            BGCC_WARN("bgcc", "[SYSINFO]%s\n", bgcc::bgcc_strerror_r(errno, buffer, BUFSIZ));
            close(listener);
            return -1;
        } 

        return listener;
    }
}

#endif // _WIN32



