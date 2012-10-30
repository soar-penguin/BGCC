/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_SOCKET_BASE_H_
#define _BGCC_SOCKET_BASE_H_

#ifdef _WIN32 
#include <windows.h>
#define BGCC_EINTR  WSAEINTR
#else 
typedef int32_t SOCKET;
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define BGCC_EINTR  EINTR
#endif

#include "bgcc_stdint.h"
#include "shareable.h"
#include "transport.h"
#include "mutex.h"
#include "guard.h"

namespace bgcc {

    /**
     * @class Socket 
     * @brief Socket部分公共接口实现
     */
    class Socket :  public ITransport {
    public:

        virtual ~Socket();

        /**
         * @brief   打开连接，虚函数，在client、server类中具体实现
         * @return  操作成功返回0；否则返回错误码。
         */
        virtual int32_t open();

        /**
         * @brief   关闭连接并初始化，windows下需要进行特殊处理
         * @return  操作成功返回0；否则返回错误码。
         */
        virtual int32_t close();

        /**
         * @brief   读取数据
         * @param   buffer 进行recv数据的存储空间
         * @param   length 接受数据的长度
         * @return  操作成功返回0；否则返回错误码。
         */
        virtual int32_t read(void * buffer, int32_t length);

        /**
         * @brief   写数据
         * @param   buffer 进行write数据的存储空间
         * @param   length 写数据的长度
         * @return  操作成功返回0；否则返回错误码。
         */
        virtual int32_t write(const void* buffer, int32_t length);

        /**
         * @brief   判断socket是否打开，用于流程合法判断，虚函数，client、server分别实现
         * @return  成功返回ture，失败返回false
         */
        virtual bool is_open() const;

        /**
         * @brief   用来查看是否有可用数据
         * @return  操作成功返回0；否则返回错误码。
         */
        virtual bool peek() const;

        /**
         * @brief   设置socket超时时间
         * @param   seconds 超时时长
         * @param   optname 表示发送还是接受
         * @return  操作成功返回0；否则返回错误码。
         */
        int32_t set_timeout(int32_t seconds, int32_t optname);
        /**
         * @brief   设置发送超时时长
         * @param   buffer 进行recv数据的存储空间
         * @return  操作成功返回0；否则返回错误码。
         */
        int32_t set_send_timeout(int32_t seconds);

        /**
         * @brief   设置接收超时时长
         * @param   buffer 进行recv数据的存储空间
         * @return  操作成功返回0；否则返回错误码。
         */
        int32_t set_recv_timeout(int32_t second);

        SOCKET get_socket() const {
            return _socket;
        }
    protected:
        Socket();
        /**全局socket编号*/
        SOCKET _socket;
        int32_t _send_timeout;
        int32_t _recv_timeout;

        /**超时时长*/
        //int32_t _send_timeout;

        /**接收超时时长*/
        // int32_t _recv_timeout;

    protected:
        /**
         * @brief   初始化主要为了完成对Winsock DLL的加载。
         * @return  成功逆初始化返回0；否则返回Windows错误码。
         */
        int32_t init();

        /**
         * @brief   逆初始化主要完成对Winsock DLL的卸载。
         * @return  操作成功返回0；否则返回错误码。
         */
        int32_t uninit();

    private:
        static int32_t _nofSockets;
        static Mutex _mutex;
    };
}

#endif

