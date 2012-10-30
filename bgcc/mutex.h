/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_MUTEX_H_
#define _BGCC_MUTEX_H_

#ifdef _WIN32
#include <Windows.h>
#else
#include <pthread.h>
#include <limits.h>
#endif

#include "bgcc_stdint.h"

#ifdef _WIN32
#define BGCC_MUTEX_WAIT_INFINITE INFINITE
#define bgcc_mutex_t HANDLE
#else
#define BGCC_MUTEX_WAIT_INFINITE UINT_MAX
#define bgcc_mutex_t pthread_mutex_t
#endif

namespace bgcc {

    /**
     * @brief 实现线程间的互斥访问
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年05月30日 17时23分40秒
     */
    class Mutex {
    public:
        /**
         * @brief Mutex 构造函数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 17时24分08秒
         */
        Mutex();

        /**
         * @brief ~Mutex 构造函数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 17时24分14秒
         */
        ~Mutex();

        /**
         * @brief lock 加锁操作
         *
         * @param millisecond 超时时长（毫秒）
         *
         * @return 加锁成功返回0；否则返回错误码
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 17时24分23秒
         */
        int32_t lock(uint32_t millisecond = BGCC_MUTEX_WAIT_INFINITE);

        /**
         * @brief try_lock 尝试加锁操作
         *
         * @return 加锁成功返回0；否则返回错误码
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 17时24分57秒
         */
        int32_t try_lock();

        /**
         * @brief unlock 解锁操作
         *
         * @return 解锁成功返回0；否则返回错误码
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 17时25分44秒
         */
        int32_t unlock();

    protected:
        /**
         * @brief Mutex 禁用拷贝构造函数
         *
         * @param Mutex
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 17时28分45秒
         */
        Mutex(const Mutex&);

        /**
         * @brief operator= 禁用赋值运算符
         *
         * @param Mutex
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 17时29分08秒
         */
        Mutex& operator=(const Mutex&);

    private:
        bgcc_mutex_t _mutex;

    }; // end of class Mutex

}

#endif // _BGCC_MUTEX_H_

