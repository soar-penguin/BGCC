/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_SEMAPHORE_H_
#define _BGCC2_SEMAPHORE_H_

#ifdef _WIN32
#include <Windows.h>
#else
#include <semaphore.h>
#include <limits.h>
#endif

#include "bgcc_stdint.h"

#ifdef _WIN32
#define BGCC_SEMA_WAIT_INFINITE INFINITE
#define bgcc_sem_t HANDLE
#else
#define BGCC_SEMA_WAIT_INFINITE UINT_MAX
#define bgcc_sem_t sem_t
#endif

namespace bgcc {

    /**
     * @brief 实现线程间的任务同步
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年05月30日 14时19分15秒
     */
    class Semaphore {
    public:
        /**
         * @brief Semaphore 构造函数
         *
         * @param ninit 信号量的初始值
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 14时22分46秒
         */
        Semaphore(int32_t ninit = 0);

        /**
         * @brief ~Semaphore 构造函数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 14时19分48秒
         */
        ~Semaphore();

        /**
         * @brief wait 等待信号量
         *
         * @param millisecond 超时时长（毫秒）
         *
         * @return 成功返回0；否则返回错误码。错误码可使用ErrorUtil::strbgccerror_r转化为文本信息
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 14时20分33秒
         */
        int32_t wait(uint32_t millisecond = BGCC_SEMA_WAIT_INFINITE);

        /**
         * @brief signal 触发信号量
         *
         * @return 成功返回0；否则返回错误码。错误码可使用ErrorUtil::strbgccerror_r转化为文本信息
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 14时21分34秒
         */
        int32_t signal();

    protected:
        /**
         * @brief Semaphore 禁用拷贝构造函数
         *
         * @param Semaphore
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 14时20分00秒
         */
        Semaphore(const Semaphore&);

        /**
         * @brief operator= 禁用赋值运算符
         *
         * @param Semaphore
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 14时20分19秒
         */
        Semaphore& operator=(const Semaphore&);

    private:
        bgcc_sem_t _sem;

    }; // end of class Semaphore

}

#endif // _BGCC2_SEMAPHORE_H_

