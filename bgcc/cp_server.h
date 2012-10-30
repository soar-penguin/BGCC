/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_CP_SERVER_H_
#define _BGCC2_CP_SERVER_H_

#ifdef _WIN32

#include "server.h"
#include "mempool.h"
#include "service_manager.h"
#include "thread_pool.h"
#include "bgcc_stdint.h"
#include "server_socket.h"

namespace bgcc {

#define WSAEVENT HANDLE
    class CpServer : public IServer {
    public:
        CpServer(ServiceManager* service_manager,
                ThreadPool* thread_pool,
                uint16_t port,
                const std::string& node = "");

        virtual ~CpServer() {
        }

        virtual int32_t init();
        virtual int32_t serve();
        virtual int32_t stop();

        ServiceManager* get_service_manager();
        ThreadPool* get_thread_pool();

        SOCKET get_listen_socket();
        WSAEVENT get_accept_event();
        HANDLE get_shutdown_event();
        HANDLE get_iocp();
    private:
        enum state_t {
            S_UNINIT,
            S_INIT,
            S_SERVE,
            S_STOPPED
        };

        int32_t socket_init();
        int32_t init_iocp();

        ServiceManager* _service_manager;
        ThreadPool* _thread_pool;
        uint16_t _port;
        state_t _state;

        SOCKET _listen_socket;
        HANDLE _hiocp;
        WSAEVENT _haccept_event;
        HANDLE _haccept_thread;
        HANDLE _hshutdown_event;
        std::string _node;

    };

    typedef CpServer Server;
}

#endif // _WIN32

#endif // _BGCC2_CP_SERVER_H_

