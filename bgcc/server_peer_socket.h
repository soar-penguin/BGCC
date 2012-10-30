/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_SERVERPEERSOCKET_H_
#define _BGCC_SERVERPEERSOCKET_H_

#ifdef _WIN32
    #include <winsock.h>
#else
    #include <sys/socket.h>
#endif

#include "socket_base.h"
#include "shared_pointer.h"
#include "peer_info.h"

namespace bgcc {
    /**
	 * @class ServerSocket 
	 * @brief server socket类，继承Socket类 
	*/
	class ServerPeerSocket : public Socket {
    public:
        /**
		 * @brief   对端socket连接信息，返回连接socket
		 * @param   socket socketID
		 * @return  无
		 */
		ServerPeerSocket(SOCKET socket);
        ~ServerPeerSocket() {
        }
        /**
		 * @brief   初始化对端信息类对象、获取对端连接信息
		 * @return  成功返回0，失败返回错误码
		 */
        int InitPeerInfo();
        /**
		 * @brief   返回对端信息对象
		 * @return  对端信息对象
		 */
        SharedPointer<PeerInfo> GetPeerInfo();
    private:
        
        SharedPointer<PeerInfo>  _peerinfo;
	};

}

#endif //_BGCC_SERVERPEERSOCKET_H_

