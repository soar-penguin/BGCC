/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_I_SERVER_H_
#define _BGCC2_I_SERVER_H_

#include "bgcc_stdint.h"
#include "shareable.h"

namespace bgcc {

    /**
     * @brief 服务器接口类
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月15日 14时54分02秒
     */
    class IServer : public Shareable {
    public:
        /**
         * @brief ~IServer 析构函数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月15日 14时54分11秒
         */
        virtual ~IServer() { }

        /**
         * @brief init 初始化函数
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月15日 14时54分20秒
         */
        virtual int32_t init() {
            return 0;
        }

        /**
         * @brief serve 启动服务
         *
         * @return 成功返回0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月15日 14时54分30秒
         */
        virtual int32_t serve() = 0;

        /**
         * @brief stop 停止服务
         *
         * @return 成功返回0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月15日 14时54分45秒
         */
        virtual int32_t stop() = 0;
    };
}

#endif // _BGCC2_I_SERVER_H_

