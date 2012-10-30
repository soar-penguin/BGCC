/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_CLIENTSOCKET_H_
#define _BGCC_CLIENTSOCKET_H_

#include <string>
#ifdef _WIN32
    #include <WinSock.h>
#else
    #include <sys/socket.h>
	#include <netdb.h>
#endif

#include "socket_base.h"

namespace bgcc {

    /**
	 * @class ClientSocket 
	 * @brief client socket类，继承Socket类 
	*/
	class ClientSocket : public Socket {
	public:
        /**
		 * @brief   构造函数，用于初始化服务器IP、PORT信息
		 * @param   host   服务器地址
		 * @param   port   服务器端口
		 * @return  无
		 */
		ClientSocket(const std::string& host, int port) : _host(host), _port(port) {}

        virtual ~ClientSocket();
        
        /**
		 * @brief   打开客户端连接，主要发起connect操作
		 * @return  操作成功返回0；否则返回错误码
		 */
        virtual int open();
        
        /**
		 * @brief   判断client连接是否打开
		 * @return  操作成功返回true；否则返回false
		 */
        virtual bool is_open() const;
    
    private:

        /**
		 * @brief   获取本地地址资源，用于发起连接，屏蔽底层协议差异
		 * @param   ppres   本地符合条件的地址列表
		 * @return  成功返回0，失败返回错误码
		 */
		int32_t get_address_list(struct addrinfo **ppres);
        /**
		 * @brief   创建socket、connect服务器
		 * @param   res  地址列表
		 * @return  成功返回0，失败返回错误码 
		 */
		int32_t open_impl(struct addrinfo *res);
        /**
		 * @brief   读取配置文件，获取超时时间，读取失败返回默认值
		 * @param   optname  方向，接受or发送
		 * @return  返回超时时间
		 */
		int32_t get_timeout_info(int optname);
		std::string _host;
		int _port;
	};
}

#endif

