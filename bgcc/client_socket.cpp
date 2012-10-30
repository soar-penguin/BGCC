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
typedef int socklen_t;
#include <winsock2.h>
#include <ws2tcpip.h>

#else
#include <sys/socket.h>
#include <sstream>   
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#endif

#include <string.h>

#include "transport.h"
#include "client_socket.h"
#include "exception.h"
#include "bgcc_error.h"
#include "log.h"
#include "string_util.h"

namespace bgcc {

    ClientSocket::~ClientSocket() {
        close();
    }

    bool ClientSocket::is_open() const 
    {
        if(_socket == INVALID_SOCKET){
            return false;
        }
        else{
#ifdef _WIN32
            int   optval,   optlen   =   sizeof(int); 
            getsockopt(_socket, SOL_SOCKET, SO_ERROR,(char*)&optval,&optlen); 
            if(optval == 0)      
#else

                struct tcp_info info;
            int len = sizeof(info);
            getsockopt(_socket,IPPROTO_TCP,TCP_INFO,&info,(socklen_t*)&len);
            if(info.tcpi_state == TCP_ESTABLISHED || info.tcpi_state == TCP_LISTEN)
#endif
            {
                return true;
            }
            else
            {
                return false;
            }

        }
    }   
    /*待合入接口后，实现内部*/
    int32_t ClientSocket::get_timeout_info(int optname ){
        int timeout;
#ifndef _WIN32
        timeout = 5;
#else
        timeout = 5000;
#endif
        return timeout;
    }

    int32_t ClientSocket::open_impl(struct addrinfo *res) {
        if (res == NULL) {
            return E_BGCC_NULL_POINTER;
        }

        //create a socket
        _socket = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        if (-1 == _socket) {
            return -1;
        }

        //connect to server
        int32_t ret = connect(_socket, res->ai_addr, (int32_t)res->ai_addrlen);
        if (0 != ret) {
            close();
            _socket = -1;
            return -1;
        }

        return 0;
    }
    int32_t ClientSocket::get_address_list(struct addrinfo **ppres) {		

        struct addrinfo hints;
        memset((void*)&hints, 0, sizeof(struct addrinfo));
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;

        std::stringstream ss;
        ss << _port;
        std::string port;
        ss >> port;

        int32_t ret = getaddrinfo(_host.empty() ? NULL: _host.c_str(), port.c_str(), &hints, ppres);
        if (0 != ret) {
            close();
            return -1;
        }

        return 0;
    }

    int ClientSocket::open() {
        if(is_open()){
            return 0;
        }

        int ret = init();
        if(0 != ret){
            return ret;
        }

        ret = 0;
        struct addrinfo *res, *res0;
        ret = get_address_list(&res0);
        if (0 != ret) {
            return ret;
        }

        for (res = res0; NULL != res; res = res->ai_next) {
            ret = open_impl(res);
            if (0 == ret) {
                set_send_timeout(get_timeout_info(SO_SNDTIMEO));
                set_recv_timeout(get_timeout_info(SO_RCVTIMEO));
                break;
            } 
        }   

        freeaddrinfo(res0);
        if (0 == ret) {
            return 0;
        } else {
            return ret;
        }
    }
}

