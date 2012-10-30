/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_SHAREABLE_H_
#define _BGCC2_SHAREABLE_H_

#include "mutex.h"
#include "bgcc_stdint.h"

namespace bgcc {

    /**
     * @brief 提供具有原子增减的通用计数器功能，可被多个智能指针对象共享
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月13日 15时30分12秒
     */
    class Shareable {
    public:
        /**
         * @brief ~Shareable 析构函数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月13日 15时32分46秒
         */
        virtual ~Shareable() { }

        /**
         * @brief inc 增加引用计数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月13日 15时32分53秒
         */
        void inc();

        /**
         * @brief dec 减少引用计数
         *
         * @return 引用计数减1后的值
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月13日 15时33分02秒
         */
        int32_t dec();

        /**
         * @brief get_count 获取当前引用计数
         *
         * @return 当前引用计数值
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月13日 15时33分25秒
         */
        int32_t get_count();
    protected:
        /**
         * @brief Shareable 禁用显式构造，仅可通过子类构造
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月13日 15时33分46秒
         */
        Shareable();
    private:
        int32_t _count;
        Mutex _mutex;
    private:
        /**
         * @brief Shareable 禁用拷贝构造功能
         *
         * @param Shareable
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月13日 15时29分11秒
         */
        Shareable(const Shareable&);

        /**
         * @brief operator= 禁用赋值运算符
         *
         * @param Shareable
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月13日 15时29分36秒
         */
        Shareable& operator=(const Shareable&);
    };
}

#endif // _BGCC2_SHAREABLE_H_

