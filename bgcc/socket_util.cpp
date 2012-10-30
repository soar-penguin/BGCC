/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifdef _WIN32
#include <WinSock.h>
typedef int socklen_t;
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#endif

#include <sys/types.h>
#include "server_peer_socket.h"
#include "socket_util.h"
#include "socket_base.h"

namespace bgcc {
    int32_t getpeerinfo(int32_t sockfd, PeerInfo& peerInfo) {
        struct sockaddr_in addr;

        memset(&addr,0,sizeof addr);

        int len = sizeof addr;
        int ret = getpeername(sockfd,(struct sockaddr*)&addr,(socklen_t*)&len);
        if(ret != 0){
            return -1;
        }

        peerInfo.SetHost(inet_ntoa(addr.sin_addr));
        peerInfo.SetPort(ntohs(addr.sin_port));
        return 0;
    }
}

