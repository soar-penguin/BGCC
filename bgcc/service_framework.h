/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_SERVICE_FRAMEWORK_H_
#define _BGCC2_SERVICE_FRAMEWORK_H_

#include <stdlib.h>
#include "bgcc_stdint.h"

namespace bgcc {

    /**
     * @brief 读取状态枚举值
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月04日 14时01分03秒
     */
    enum reading_state_t {
        S_SIZE_READING,
        S_DATA_READING,
        S_READING_END
    };

    /**
     * @brief 用于表示当前的读取状态
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月04日 14时01分26秒
     */
    struct reading_item_t {
        enum reading_state_t    state;  /** 当前的读状态*/
        int32_t                 nexpected;  /** 还期望读多少字节*/
        int32_t                 nread;  /** 已经读取了多少字节*/
        char                    head_buf[20]; /** 消息头部缓冲区 */
        char*                   data;   /** 消息缓冲区。使用mempoll申请和释放*/

        reading_item_t() {
            state = S_SIZE_READING;
            nexpected = 20;
            nread = 0;
            data = NULL;
        }

        void reset() {
            state = S_SIZE_READING;
            nexpected = 20;
            nread = 0;
            data = NULL;
        }
    };

    /**
     * @brief 用于表示当前的写出状态
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月04日 14时04分02秒
     */
    struct writing_item_t {
        int32_t nexpected;  /** 还期望读多少字节*/
        int32_t nwritten;   /** 已经写了多少字节*/
        char* data; /** 消息缓冲区。使用mempoll释放*/
    };
}
#endif // _BGCC2_SERVICE_FRAMEWORK_H_

