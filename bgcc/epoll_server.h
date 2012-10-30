/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_EPOLL_SERVER_H_
#define _BGCC2_EPOLL_SERVER_H_

#ifndef _WIN32

#include <stdint.h>
#include "server.h"
#include "event_poll.h"
#include "mempool.h"
#include "service_manager.h"
#include "thread_pool.h"

namespace bgcc {

    class EpollServer : public IServer {
    public:
        EpollServer(ServiceManager* service_manager,
                ThreadPool* thread_pool,
                uint16_t port,
                const std::string& node = "");

        virtual ~EpollServer() {
        }

        virtual int32_t init();
        virtual int32_t serve();
        virtual int32_t stop();

        ServiceManager* get_service_manager();
        ThreadPool* get_thread_pool();

    private:
        enum state_t {
            S_UNINIT,
            S_INIT,
            S_SERVE,
            S_STOPPED
        };
        int32_t socket_init();

        ServiceManager* _service_manager;
        ThreadPool* _thread_pool;
        uint16_t _port;
        state_t _state;
        int32_t _listenfd;
        EventLoop _loop;
        std::string _node;
    };

    typedef EpollServer Server;
}

#endif // _WIN32

#endif // _BGCC2_EPOLL_SERVER_H_

