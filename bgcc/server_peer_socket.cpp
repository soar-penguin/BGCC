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
#else
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <errno.h>
#endif

#include <string.h>

#include <sys/types.h>
#include "server_peer_socket.h"
#include "socket_util.h"
#include "bgcc_error.h"

namespace bgcc {

	ServerPeerSocket::ServerPeerSocket(SOCKET socket) {
        
		_socket = socket;
		int initresult = InitPeerInfo();
        if(initresult != 0){
		}
	}
    
    typedef SharedPointer<PeerInfo> PeerInfoSharedPointer;
#ifdef _WIN32
	typedef  int socklen_t;
#endif
    int ServerPeerSocket::InitPeerInfo(){

        if(_socket<0){
            return -1;
        }

        PeerInfo tmp("", 0);
        int32_t ret = getpeerinfo((int32_t)_socket, tmp);
        if (ret != 0) {
            return ret;
        }
        _peerinfo = SharedPointer<PeerInfo>(new PeerInfo(tmp.GetHost(), tmp.GetPort()));
 
        return 0;
    }
    
    SharedPointer<PeerInfo> ServerPeerSocket::GetPeerInfo(){
        return _peerinfo;
    }
}
