/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_SERVER_SOCKET_H_
#define _BGCC_SERVER_SOCKET_H_

#ifdef _WIN32
#include <iostream>
#include <winsock.h>
#else
#include <sys/poll.h>
#include <errno.h>
#include <sys/socket.h>
#endif
#include "exception.h"
#include "server_peer_socket.h"
#include "bgcc_error.h"
#include "shared_pointer.h"
#include "thread.h"
#include "socket_base.h"

namespace bgcc {

    /**
     * @class ServerSocket 
     * @brief server socket类，继承Socket类 
     */
    class ServerSocket : public Socket {
    public:
        /**
         * @brief   构造函数，用于初始化服务器PORT等信息
         * @param   host   服务器端口
         * @param   npending
         * @return  无
         */
        ServerSocket(int port, int npending) : _port(port), _npending(npending) {

#ifdef _WIN32
            _flag = true;
#else
            _sock1_for_interrupt = INVALID_SOCKET;
            _sock2_for_interrupt = INVALID_SOCKET;
#endif
        }

        /**
         * @brief   关闭server侧用于中断的socket
         * @return  成功0
         */
        int32_t CloseInterruptSock()
        {
#ifdef _WIN32
            return 0;
#else
            if(_sock1_for_interrupt != INVALID_SOCKET)
            {
                shutdown(_sock1_for_interrupt,SHUT_RDWR);
                if(-1 == ::close(_sock1_for_interrupt)){
                }

            }

            if(_sock2_for_interrupt != INVALID_SOCKET)
            {
                shutdown(_sock2_for_interrupt,SHUT_RDWR);
                if(-1 == ::close(_sock2_for_interrupt)){
                }

            }
            _sock1_for_interrupt = INVALID_SOCKET;
            _sock2_for_interrupt = INVALID_SOCKET;
            return 0;
#endif
        }

        /**
         * @brief   打开服务端连接，主要发起bind、listen操作
         * @return  操作成功返回0；否则返回错误码
         */
        virtual int open();
        /**
         * @brief   判断server连接是否打开
         * @return  操作成功返回true；否则返回false
         */
        virtual bool is_open() const;
        int32_t interrupt() {
#ifdef _WIN32
            _flag = false;
#else
            if (_sock1_for_interrupt >= 0) {
                uint8_t b = 0;
                if (-1 == ::send(_sock1_for_interrupt, &b, 1, 0)) {
                    return SOCKETINTERRUPT;
                }
            }
#endif	
            return 0;
        }
        /**
         * @brief   接受客户端的连接
         * @return  返回只向SERVERPEERSOCKET对象的指针
         */
        typedef SharedPointer<ServerPeerSocket> ServerPeerSocketSharedPointer;
        ServerPeerSocketSharedPointer accept() 
        {
            int errorcode = 0;
            if (_socket < 0) {
                return ServerPeerSocketSharedPointer( NULL);
            }

#ifdef _WIN32
            int maxfdp = 0;
            fd_set fds;
			struct ::timeval timeout={0,0};
            while(true)
            {
                if(_flag == false)
                {
                    return ServerPeerSocketSharedPointer(NULL);
                }
                else
                {
                    FD_ZERO(&fds);
                    FD_SET(_socket,&fds);
                    maxfdp = (int32_t)_socket + 1;
                    int retcode = select(maxfdp,&fds,NULL,NULL,&timeout);
                    if (retcode < 0) 
                    {
                        errorcode = BgccSockGetLastError();
                        if (errorcode == WSAEINTR) 
                        {
                            continue;
                        }
                        return ServerPeerSocketSharedPointer(NULL);
                    } 
                    else if (retcode > 0 && FD_ISSET(_socket,&fds)) 
                    {
                        break;
                    }
                    else
                    {
                        errorcode = BgccSockGetLastError();
                        continue;
                    }
                }
            }

#else
            struct pollfd fds[2];
            while (true) {
                memset(fds, 0, sizeof(fds));
                fds[0].fd = _socket;
                fds[0].events = POLLIN;
                if (_sock2_for_interrupt >= 0) {
                    fds[1].fd = _sock2_for_interrupt;
                    fds[1].events = POLLIN;
                }

                int32_t ret = poll(fds, 2, -1);

                if (ret < 0) {
                    errorcode = BgccSockGetLastError();    
                    if (errorcode == EINTR) {
                        continue;
                    }
                    return ServerPeerSocketSharedPointer(NULL);

                } else if (ret > 0) {
                    if (_sock2_for_interrupt >= 0 && (fds[1].revents & POLLIN)) {
                        int8_t b;
                        if (-1 == recv(_sock2_for_interrupt, &b, sizeof(int8_t), 0)) {
                            errorcode = BgccSockGetLastError();    
                            return ServerPeerSocketSharedPointer(NULL);
                        }
                        return ServerPeerSocketSharedPointer(NULL);
                    }

                    if (fds[0].revents & POLLIN) {
                        break;
                    }
                } else {
                    continue;
                }
            }
#endif
#ifndef _WIN32
            struct sockaddr_storage client_addr;
            uint32_t size = sizeof(client_addr);

            int32_t client_socket = ::accept(_socket,
                    (struct sockaddr*)&client_addr, (socklen_t*)&size);
#else
            SOCKET client_socket = ::accept(_socket,0,0);
#endif

            if (client_socket < 0) {
                return ServerPeerSocketSharedPointer(NULL);
            }

            ServerPeerSocketSharedPointer ptrans = ServerPeerSocketSharedPointer(new ServerPeerSocket(client_socket));

            if (ptrans.is_valid()) {
                ptrans->set_send_timeout(get_timeout_info(SO_SNDTIMEO));
                ptrans->set_recv_timeout(get_timeout_info(SO_RCVTIMEO));
            }

            return ptrans;
        }
    private:
        int32_t get_timeout_info(int optname);
        int _port;
        int _npending;
#ifdef _WIN32
        bool _flag;
#else
        SOCKET _sock1_for_interrupt;
        SOCKET _sock2_for_interrupt;
#endif
    };
}
#endif

