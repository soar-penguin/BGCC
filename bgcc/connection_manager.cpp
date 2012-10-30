/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "connection_manager.h"
#include "guard.h"
#include "time_util.h"
#include "log.h"

namespace bgcc {

    void* ConnectionManager::clear_disconnected_socket(void* arg) {
        ConnectionManager* cm = (ConnectionManager*)arg;

        while (true) {
            bgcc::TimeUtil::safe_sleep_s(2);
            BGCC_TRACE("bgcc", "clear_disconnected_socket");
            Guard<Mutex> guard(&cm->_mutex);
            std::map<std::string, SharedPointer<SyncVector<socket_t> > >::iterator itr;
            char b[1];
            int32_t ret;
            BGCC_TRACE("bgcc", "cm->_proxy_name2connections.size() %d", (int32_t)cm->_proxy_name2connections.size());
            for (itr = cm->_proxy_name2connections.begin();
                    itr != cm->_proxy_name2connections.end();
                ) {
                SharedPointer<SyncVector<socket_t> > v = itr->second;
                int32_t size = v->size();
                if (0 == size) {
                    cm->_proxy_name2connections.erase(itr++);
                }
                else {
                    std::vector<socket_t> tmp_v;
                    socket_t s;
                    int32_t i;

                    for (i = 0; i < size; ++i) {
                        ret = v->get(s, 10);
                        if (0 == ret) {
                            fd_set rfds;
                            struct timeval tv;
                            int retval;

                            FD_ZERO(&rfds);
                            FD_SET(s, &rfds);
                            tv.tv_sec = 1;
                            tv.tv_usec = 0;

                            retval = select((int32_t)s+1, &rfds, NULL, NULL, &tv);
                            if (retval == 1) {
                                ret = recv(s, b, 1, MSG_PEEK);
                                if (0 == ret || -1 == ret) {
#ifdef _WIN32
                                    closesocket(s);
#else
                                    close(s);
#endif
                                }
                            }
#ifdef _WIN32
                            else if (retval == -1 && WSAGetLastError() == WSAEINTR) {
                                closesocket(s);
                            }
#else
                            else if (retval == -1 && errno != EINTR) {
                                close(s);
                            }
#endif
                            else {
                                tmp_v.push_back(s);
                            }
                        }
                        else {
                            break;
                        }
                    }


                    size = (int32_t)tmp_v.size();
                    if (0 == size) {
                        cm->_proxy_name2connections.erase(itr++);
                    }
                    else {
                        for (i = 0; i < size; ++i) {
                            v->put(tmp_v[i]);
                        }
                        ++itr;
                    }
                }
            }
        }
        return NULL;
    }

    ConnectionManager::ConnectionManager() {
#ifndef _WIN32
        _clear_disconnected_socket_thread = 
            SharedPointer<Thread>(new Thread(clear_disconnected_socket, this));
        _clear_disconnected_socket_thread->start();
#endif
    }

    ConnectionManager::~ConnectionManager() {
#ifndef _WIN32
        _clear_disconnected_socket_thread->stop();
#endif
    }

    int32_t ConnectionManager::enroll(const std::string& proxy_name, socket_t fd) {
        Guard<Mutex> guard(&_mutex);
        std::map<std::string, SharedPointer<SyncVector<socket_t> > >::iterator itr;
        itr = _proxy_name2connections.find(proxy_name);
        if (itr == _proxy_name2connections.end()) {
            SharedPointer<SyncVector<socket_t> > v(new SyncVector<socket_t>());
            itr = _proxy_name2connections.insert(std::make_pair(proxy_name, v)).first;
        }

        itr->second->put(fd);
        return 0;
    }

    SharedPointer<ServerPeerSocket>
        ConnectionManager::get_connection(const std::string& proxy_name) {
            Guard<Mutex> guard(&_mutex);
            std::map<std::string, SharedPointer<SyncVector<socket_t> > >::iterator itr;
            itr = _proxy_name2connections.find(proxy_name);

            if (itr == _proxy_name2connections.end()) {
                return SharedPointer<ServerPeerSocket>(NULL);
            }
            else {
                socket_t fd;
                int32_t ret;
                ret = itr->second->get(fd, 10);
                if (0 == ret) {
                    ServerPeerSocket* s = new ServerPeerSocket(fd);
                    s->set_send_timeout(60*60*24*30);
                    s->set_recv_timeout(60*60*24*30);
                    return SharedPointer<ServerPeerSocket>(s);
                }
                else {
                    return SharedPointer<ServerPeerSocket>(NULL);
                }
            }
        }
}

