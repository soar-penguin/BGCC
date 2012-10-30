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
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/poll.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#endif

#include <string.h>
#include <sstream>

#include "transport.h"
#include "server_socket.h"
#include "shareable.h"
#include "exception.h"
#include "conf_loader.h"
#include "string_util.h"

namespace bgcc {

    int32_t ServerSocket::get_timeout_info(int optname ){
        int timeout = 0;
        std::string strtimeout;

        if(optname == SO_SNDTIMEO)
        {
            timeout = _send_timeout * 60;
        }
        else
        {
            timeout = _recv_timeout * 60;
        }

        return timeout;
    }
    bool ServerSocket::is_open() const 
    {
        if(_socket == INVALID_SOCKET){
            return false;
        }
        return true;
    }   
    int ServerSocket::open() {

        if(is_open()){
            return 0;
        }
        if(_port < 0){
            return -1;
        }

        int ret = init();

        if(OPERSUCCESS != ret){
            return ret;
        }
#ifndef _WIN32

        int32_t sp[2];
        if (-1 == socketpair(AF_LOCAL, SOCK_STREAM, 0, sp)) {
            return CREATEINTERSOCKFAIL;
        } else {
            _sock1_for_interrupt = sp[0];
            _sock2_for_interrupt = sp[1];
        }
#endif

        struct addrinfo hints, *res, *res0;
        memset(&hints, 0, sizeof(struct addrinfo));
        hints.ai_family = PF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_PASSIVE;


        std::stringstream ss;
        ss << _port;
        std::string port;
        ss >> port;

        //get the server address information
        ret = 0;
        ret = getaddrinfo(NULL, port.c_str(), &hints, &res0);

        if (0 != ret) {
            freeaddrinfo(res0);
            return GETADDRFAIL;
        }

        //create a socket for listening
        res = res0;
        _socket = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

        if (-1 == _socket) { 
            freeaddrinfo(res0);
            return CREATESOCKETFAIL;
        }

        int reuse = 1;
        setsockopt(_socket,SOL_SOCKET,SO_REUSEADDR,(char*)&reuse,sizeof(reuse));

        //bind the socket
        if (0 != bind(_socket,res->ai_addr, (int32_t)res->ai_addrlen)) {
            freeaddrinfo(res0);
            return BINDSOCKETFAIL;
        }
        freeaddrinfo(res0);

        //listen
        if (0 != ::listen(_socket, _npending)) {
            CloseInterruptSock();
            close();
            return LISTENFAIL;
        }

        return OPERSUCCESS;
    }


}
