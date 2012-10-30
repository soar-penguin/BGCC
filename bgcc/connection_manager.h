/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_CONNECTION_MANAGER_H_
#define _BGCC2_CONNECTION_MANAGER_H_

#include <map>
#include <string>
#include "sync_vector.h"
#include "shared_pointer.h"
#include "server_peer_socket.h"
#include "mutex.h"
#include "thread.h"

#ifdef _WIN32
typedef SOCKET socket_t;
#else
typedef int32_t socket_t;
#endif

namespace bgcc {

    class ConnectionManager {
    public:
        static ConnectionManager* get_instance() {
            static ConnectionManager cm;
            return &cm;
        }


        int32_t enroll(const std::string& proxy_name, socket_t fd);

        SharedPointer<ServerPeerSocket>
            get_connection(const std::string& proxy_name);

        ~ConnectionManager();
    private:
        ConnectionManager();
        ConnectionManager(const ConnectionManager&);
        ConnectionManager& operator=(const ConnectionManager&);

    private:
        std::map<std::string, SharedPointer<SyncVector<socket_t> > > _proxy_name2connections;
        Mutex _mutex;

        static void* clear_disconnected_socket(void* arg);
        SharedPointer<Thread> _clear_disconnected_socket_thread;
    };
}
#endif // _BGCC2_CONNECTION_MANAGER_H_

