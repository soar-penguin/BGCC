/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_PEERINFO_H_
#define _BGCC_PEERINFO_H_

#ifdef _WIN32
    #include <winsock.h>
#else
    #include <sys/socket.h>
#endif

#include <string>
#include "socket_base.h"
#include "shareable.h"

namespace bgcc {

    /**
	 * @class Peerinfo 
	 * @brief peerinfo类，继承Shareable类 
	*/
	class PeerInfo : public Shareable {
	public:
        /**
		 * @brief   构造函数，初始化对端IP、端口
		 * @param   IP、PORT信息
		 * @return  无
		 */
		PeerInfo(std::string host,int32_t port):_host(host),_port(port){}
        /**
		 * @brief   获取对端IP地址
		 * @param   无
		 * @return  对端IP地址
		 */
        std::string GetHost(){
            return _host;
        }
        /**
		 * @brief   获取对端PORT
		 * @param   无
		 * @return  对端PORT
		 */
        int32_t GetPort() {
            return _port;
        }

        void SetHost(const std::string& host) {
            _host = host;
        }

        void SetPort(int32_t port) {
            _port = port;
        }
    private:
        std::string  _host;
        int32_t _port;
	};

}

#endif //_BGCC_PEERINFO_H_

