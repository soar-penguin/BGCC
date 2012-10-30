/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_GUARD_H_
#define _BGCC2_GUARD_H_

#include <stdlib.h>

namespace bgcc {

    /**
     * @brief 
     *
     * @tparam LockType
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年05月30日 19时19分33秒
     */
    template <typename LockType>
        class Guard {
        public:
            /**
             * @brief Guard 构造函数，对Mutex加锁
             *
             * @param lock 待加锁指针
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012年05月30日 19时26分09秒
             */
            Guard(LockType* lock) : _locked(false), _lock(lock) {
                if (NULL != _lock) {
                    if (0 == _lock->lock()) {
                        _locked = true;
                    }
                }
            }

            /**
             * @brief is_locked 检测加锁是否成功
             *
             * @return 加锁成功返回true；否则返回false
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012年05月30日 19时26分33秒
             */
            bool is_locked() const {
                return _locked;
            }

            /**
             * @brief ~Guard 析构函数，对Mutex解锁
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012年05月30日 19时27分12秒
             */
            ~Guard() {
                if (NULL != _lock) {
                    if (0 == _lock->unlock()) {
                        _locked = false;
                    }
                }
            }
        private:
            mutable bool _locked;
            LockType* _lock;
        };
}

#endif // _BGCC2_GUARD_H_

