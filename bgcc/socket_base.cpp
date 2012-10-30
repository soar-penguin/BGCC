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
#include <winsock.h>
#else
#include <sys/socket.h>
#include <sstream>
#include <netinet/in.h>
#include <netinet/tcp.h>
#endif

#include "socket_base.h"
#include "bgcc_error.h"
#include <stdio.h>
#include <errno.h>
#include "log.h"

namespace bgcc {

    Socket::~Socket() {
    }

    int32_t Socket::open() {
        return 0;
    }

    int32_t Socket::close() {
        int32_t ret = 0;

        if (INVALID_SOCKET != _socket) {
#ifdef _WIN32 
            if(SOCKET_ERROR == ::closesocket(_socket)){
#else
                shutdown(_socket,SHUT_RDWR);
                if(-1 == ::close(_socket)){
#endif	
                    return -1;
                }
                _socket = INVALID_SOCKET;
                ret = uninit();
            }
            return ret;
        }

        int32_t Socket::read(void* buffer, int32_t length)
        {
            char logbuffer[BUFSIZ];
            int32_t nread = 0;
            int32_t err = 0;

            if(!buffer){
                BGCC_DEBUG("bgcc", "Param buf is NULL. Please check.");
                return E_BGCC_NULL_POINTER;
            }

            if(!is_open()){
                BGCC_DEBUG("bgcc", "socket is not opened");
                return -1;
            }

            while( nread < length) {
                int32_t xread = recv(_socket, (char*)buffer + nread, length - nread, 0);
#ifndef _WIN32
                if(-1 == xread){
#else
                    if(SOCKET_ERROR == xread) {
#endif

                        err = BgccSockGetLastError();
#ifndef _WIN32
                        if(err == EINTR){
                            continue;
                        }
#else
                        if (err == WSAEWOULDBLOCK) {
                            continue;
                        }
#endif

                        BGCC_WARN("bgcc", "[SYS] %d %s", err, bgcc::bgcc_strerror_r(err, logbuffer, BUFSIZ));
                        return E_BGCC_SYSERROR;
                    }
                    else if (0 == xread) {
                        err = BgccSockGetLastError();
                        BGCC_WARN("bgcc", "[SYS] %d %s", err, bgcc::bgcc_strerror_r(err, logbuffer, BUFSIZ));
                        return -1;
                    }
                    nread += xread;
                }
                return 0;
            }

            int32_t Socket::write(const void* buffer, int32_t length) {
                int32_t nwrite = 0;
                int32_t xwrite = 0;
                int32_t errno_cp = 0;
                if (!buffer) {
                    return E_BGCC_NULL_POINTER;
                }
                if (!is_open()) {
                    return -1;
                }

                while(nwrite < length) {
                    xwrite = send(_socket, (const char*)buffer + nwrite, length - nwrite, 0);
                    if (-1 == xwrite) {
                        errno_cp = BgccGetLastError();
#ifdef _WIN32
                        if(errno_cp == WSAEWOULDBLOCK){
#else
                            if(errno_cp == EWOULDBLOCK || errno_cp == EAGAIN){
#endif
                                xwrite = 0;
                            }
                            else {
                                return -1;
                            }
                        }

                        nwrite += xwrite;
                    }
                    return 0;
                }

                bool Socket::is_open() const {
                    return true;
                }

                bool Socket::peek() const {
                    char buffer[1];
                    int32_t ret  = 0;

                    if (!is_open()) {
                        return false;
                    }

                    ret = recv(_socket, buffer, 1, MSG_PEEK);
                    if (ret == -1) {
                        return false;
                    }
                    return (ret == 1);
                }

                Socket::Socket()
                    :_socket(INVALID_SOCKET),
                    _send_timeout(5),
                    _recv_timeout(5) 
                {
                    init();
                }

                /*INIT函数，成功返回0，失败返回负数*/
                int32_t Socket::init() {
#if defined _WIN32 && !defined SERVER
                    Guard<Mutex> guard(&_mutex);
                    int32_t errno_cp = 0;
                    if (0 == _nofSockets) 
                    {
                        WSADATA info;
                        int32_t ret = 0;
                        ret = WSAStartup(MAKEWORD(2, 0), &info);
                        if (0 != ret) 
                        {
                            /*将错误码打印出来*/
                            errno_cp = BgccGetLastError();
                            return errno_cp;
                        }
                    }
                    ++_nofSockets;
#endif
                    return 0;
                }

                /*UNINIT函数，成功返回0，失败返回负数*/
                int32_t Socket::uninit() {
#if defined _WIN32 && !defined SERVER
                    Guard<Mutex> guard(&_mutex);
                    int32_t errno_cp = 0;
                    if (0 == --_nofSockets) 
                    {
                        if (0 != WSACleanup())
                        {
                            /*将错误码打印日志*/
                            errno_cp = BgccGetLastError();
                            return errno_cp;
                        }
                    }
#endif
                    return 0;
                }

                int32_t Socket::set_timeout(int32_t seconds, int32_t optname) {
                    int32_t ret = 0;

                    if (!is_open()) {
                        return 0;
                    }

                    if (seconds < 0) {
                        seconds = 0;
                    }

                    if (SO_SNDTIMEO == optname) {
                        _send_timeout = seconds;
                    }
                    else{
                        _recv_timeout = seconds;
                    }

#ifdef _WIN32
                    int32_t tv = seconds;
                    ret = setsockopt(_socket, SOL_SOCKET, optname, (const char*)&tv, sizeof(int32_t));

#else
                    struct timeval tv;
                    tv.tv_sec = seconds;
                    tv.tv_usec = 0;
                    socklen_t optlen = sizeof(tv);
                    ret = setsockopt(_socket, SOL_SOCKET, optname, (const void*)&tv, optlen);
#endif
                    if (-1 == ret) { 
                        return -1;
                    }

                    return 0;
                }

                int32_t Socket::set_send_timeout(int32_t seconds){
                    return set_timeout(seconds,SO_SNDTIMEO);
                }

                int32_t Socket::set_recv_timeout(int32_t seconds){
                    return set_timeout(seconds,SO_RCVTIMEO);
                }

                int32_t Socket::_nofSockets = 0;
                Mutex Socket::_mutex;
            }
