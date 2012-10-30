/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_ITRANSPORT_H_
#define _BGCC_ITRANSPORT_H_

#include "bgcc_stdint.h"
#include "shareable.h"

namespace bgcc {

    /**
     * @class ITransport 
     * @brief 传输层抽象接口类，方法均由派生类实现
     */
    class ITransport : public Shareable {
    public:
        virtual ~ITransport() { }

        /**
         * @brief  打开连接，客户端程序用于connect、服务器程序用于bind、listen
         * @return  操作成功返回0；否则返回错误码。
         */
        virtual int32_t open() = 0;

        /**
         * @brief   关闭socket操作、windows下进行系统清理
         * @return  操作成功返回0；否则返回错误码。
         */
        virtual int32_t close() = 0;

        /**
         * @brief   读取数据
         * @param   buffer 进行recv数据的存储空间
         * @param   length 接受数据的长度
         * @return  操作成功返回0；否则返回错误码。
         */
        virtual int32_t read(void* buffer, int32_t length) = 0;

        /**
         * @brief   向socket send数据
         * @param   buffer 进行send数据的存储空间
         * @param   length send数据的长度
         * @return  操作成功返回0；否则返回错误码。
         */
        virtual int32_t write(const void* buffer, int32_t length) = 0;

        /**
         * @brief   判断连接是否打开
         * @return  操作成功返回true；否则返回false。
         */
        virtual bool is_open() const = 0;

        /**
         * @brief   检测当前接受缓冲区是否有可用数据
         * @return  操作成功返回true；否则返回false。
         */
        virtual bool peek() const = 0;

    };

}

#endif 

