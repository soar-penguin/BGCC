/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include <signal.h>
#ifndef _WIN32
#include <sys/epoll.h>
#endif
#include "base_proxy.h"
#include "protocol.h"
#include "log.h"
#include "client_socket.h"
#include "string_util.h"
#include "thread_util.h"

namespace bgcc {

    void* call_back_thread_func(void* param) {
        BGCC_TRACE("bgcc", "enroll self");


        callback_thread_arg_t* arg = (callback_thread_arg_t*)param;
        std::string proxy_name = arg->proxy_name;
        std::string server_ip = arg->server_ip;
        int32_t server_port = arg->server_port;
        ServiceManager* service_manager = arg->service_manager;
        Semaphore* sema = arg->sema;

        SharedPointer<ClientSocket> connect;
        SharedPointer<BinaryProtocol> proto;

#ifndef _WIN32
        int32_t ep = epoll_create(1);
        struct epoll_event ee;
        struct epoll_event revents[1];

#endif
RECON:
        connect = SharedPointer<ClientSocket>(
                new(std::nothrow) ClientSocket(server_ip, server_port));

        connect->open();

        connect->set_recv_timeout(60*60*24*30);
        proto = SharedPointer<BinaryProtocol>(
                new(std::nothrow) BinaryProtocol(connect));
        int32_t ret = 0;

        ret = proto->writeMessageBegin("bgcc::BaseProcessor_enroll", "__enroll", bgcc::CALL, 0);
        if (ret < 0) {
            return NULL;
        }
        ret = proto->writeString(proxy_name);
        if (ret < 0) {
            return NULL;
        }
        proto->writeMessageEnd();
        sema->signal();
#ifndef _WIN32
        ee.data.fd = connect->get_socket();
        ee.events = EPOLLIN;
        epoll_ctl(ep, EPOLL_CTL_ADD, connect->get_socket(), &ee);
#endif
        while (true) {
#ifndef _WIN32
            int32_t nevent = epoll_wait(ep, revents, 1, -1);
            BGCC_TRACE("bgcc", "epoll_wait return %d", nevent);
            if (nevent >= 1) {
#endif
                char buffer[BUFSIZ];
                int32_t xxret;
                xxret = connect->read(buffer, 20);
                BGCC_TRACE("bgcc", "ret value read %d", xxret);
                if (0 != xxret) {
#ifndef _WIN32
                    epoll_ctl(ep, EPOLL_CTL_DEL, connect->get_socket(), &ee);
#endif
                    goto RECON;
                }
                int32_t body_len = (int32_t)ntohl(*(uint32_t*)(buffer +16));
                BGCC_TRACE("bgcc", "body size %d", body_len);
                char body[BUFSIZ];
                xxret = connect->read(body, body_len);
                BGCC_TRACE("bgcc", "body ret value read %d", xxret);
                if (0 != xxret) {
#ifndef _WIN32
                    epoll_ctl(ep, EPOLL_CTL_DEL, connect->get_socket(), &ee);
#endif
                    goto RECON;
                }
                int32_t processor_name_len = (int32_t)ntohl(*(uint32_t*)(body));
                std::string processor_name(body + 4, processor_name_len);
                SharedPointer<IProcessor> processor =
                    service_manager->get_service(processor_name);
                if (processor.is_valid()) {
                    processor->process(
                            body + 4 + processor_name_len,
                            body_len - 4 - processor_name_len,
                            proto);
                }

                /* added for handling unexist service*/
                else {
                    processor = service_manager->get_service("._baseservice_2012");
                    if (processor.is_valid()) {
                        SharedPointer<BinaryProtocol> bp(new BinaryProtocol(SharedPointer<ITransport>(NULL)));

                        bp->writeMessageBegin("xx", "__service_not_found", bgcc::CALL, 0);
                        bp->writeInt32(0);
                        bp->writeString("__service_not_found");
                        bp->writeBool(false);

                        void* data = NULL;
                        int32_t head_body_size;
                        NBDataBuffer* db = bp->get_data_buffer();
                        db->get_data(&data, head_body_size);
                        processor->process(
                                (char*)data + 20 + 4 + 2,
                                head_body_size - 20 - 4 - 2,
                                proto);

                    }
                }
#ifndef _WIN32
            }
#endif
        }

//#ifdef _WIN32
        return NULL;
//#endif

    }

    BaseProxy::BaseProxy(
            ServerInfo serverinfo,
            int32_t nprotocols,
            ServiceManager* service_manager,
            int32_t tryCount,
            int32_t tryInterval)
        :_serverinfo(serverinfo.getIP(),serverinfo.getPort()),
        _service_manager(service_manager)
    {
        _name = StringUtil::generate_uuid();
        _nProtocols = nprotocols;
        _tryCount = tryCount;
        _tryInterval = tryInterval;

        init();
    }

    BaseProxy::~BaseProxy() {
        uninit();
    }

    int32_t BaseProxy::init() {
        int32_t ncreated = 0;

#ifndef _WIN32
        signal(SIGPIPE, SIG_IGN);
#endif

        if (_service_manager) {
            struct callback_thread_arg_t arg;
            arg.proxy_name = get_name();
            arg.server_ip = _serverinfo.getIP();
            arg.server_port = _serverinfo.getPort();
            arg.service_manager = _service_manager;
            arg.sema = new Semaphore;

            _callback_thread = SharedPointer<Thread>(
                    new Thread(call_back_thread_func, &arg));
            if (_callback_thread.is_valid()) {
                BGCC_TRACE("bgcc", "before thread start");
                _callback_thread->start();
                BGCC_TRACE("bgcc", "before sema");
                arg.sema->wait();
                BGCC_TRACE("bgcc", "after sema");
            }
        }

        for (int32_t i = 0; i < _nProtocols; ++i) {
            SharedPointer<ClientSocket> connect(
                    new(std::nothrow) ClientSocket(_serverinfo.getIP(), _serverinfo.getPort()));
            if (connect.is_valid() && connect->open() == 0) {
                SharedPointer<BinaryProtocol> proto(
                        new(std::nothrow) BinaryProtocol(connect));
                if (proto.is_valid()) {
                    if (_protocols.put(proto) == 0) {
                        ++ncreated;
                    }
                }
            }
        }
        BGCC_TRACE("bgcc", "Proxy %s create %d conntections to server(%s:%d)",
                _name.c_str(), ncreated, _serverinfo.getIP().c_str(), _serverinfo.getPort());

        return ncreated;
    }

    int32_t BaseProxy::uninit() {
        if (_callback_thread.is_valid()) {
            _callback_thread->stop();
        }
        return 0;
    }

    int32_t BaseProxy::__get_ticket_id(
            const std::string& fun,
            int32_t& ticket_id,
            bool belast,
            SharedPointer<IProtocol> __iprot,
            SharedPointer<IProtocol> __oprot)
    {
        int32_t ret = 0;
        int32_t tid = (int32_t)bgcc::ThreadUtil::self_id();
        std::string fname;
        MsgTypeID msg_type;
        int32_t msg_seqid;
        ret = __oprot->writeMessageBegin(_whoami.c_str(), "__get_ticket_id", bgcc::CALL, 0);
        if (ret < 0) { goto end; }
        ret = __oprot->writeInt32(tid);
        if (ret < 0) { goto end; }
        ret = __oprot->writeString(fun);
        if (ret < 0) { goto end; }
        ret = __oprot->writeBool(belast);
        if (ret < 0) { goto end; }
        __oprot->writeMessageEnd();

        ret = __iprot->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret < 0) { 
            BGCC_TRACE("bgcc", "read message begin get ticket id");
            goto end;}
            if (msg_type == bgcc::EXCEPTION) {
                int32_t remote_code = 0;
                ret = __iprot->readInt32(remote_code);
                if(ret >= 0) { ret = remote_code; }
                goto end;
            }
            if (msg_type != bgcc::REPLY || fname != "__get_ticket_id") {
                ret = __iprot->skip(bgcc::IDINT32);
                if(ret < 0) { goto end;} 
                ret = __iprot->readMessageEnd();
                if(ret < 0) { goto end;} 
            }
            ret = __iprot->readInt32(ticket_id);
            BGCC_TRACE("bgcc", "ticket id %d", ticket_id);
            __iprot->readMessageEnd();
end:
            set_errno(ret);
            return ret;
    }

    std::string BaseProxy::get_name() const {
        return _name;
    }

    void BaseProxy::set_name(const std::string& name) {
        _name = name;
    }

    std::string BaseProxy::get_whoami() const {
        return _whoami;
    }

    void BaseProxy::set_whoami(const std::string& whoami) {
        _whoami = whoami;
    }

} // namespace
