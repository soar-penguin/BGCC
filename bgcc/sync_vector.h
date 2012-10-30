/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_SYNC_VECTOR_H_
#define _BGCC_SYNC_VECTOR_H_

#include <vector>
#include "mutex.h"
#include "sema.h"
#include "guard.h"
#include "bgcc_error.h"
#include "shareable.h"

/**
 * @brief 线程安全vector
 * @see
 * @note
 * @author  liuxupeng(liuxupeng@baidu.com)
 * @date    2012年05月30日 16时42分56秒
 */
namespace bgcc {

    template <typename ElemType>
        class SyncVector : public Shareable {
        public:
            SyncVector() { }
            typedef Guard<Mutex> ScopedGuard;

            /**
             * @brief put 向同步vector中添加元素（允许重复）。同时触发信号量
             *
             * @param elem 新元素
             *
             * @return 添加成功返回0；否则返回错误码
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012年05月30日 19时11分24秒
             */
            int32_t put(ElemType elem) {
                {
                    ScopedGuard guard(&_mutex);
                    if (guard.is_locked()) {
                        try {
                            _vector.push_back(elem);
                        }
                        catch(std::bad_alloc &) {
                            return E_BGCC_NOMEM;
                        }
                    }
                    else {
                        return E_BGCC_SYSERROR;
                    }
                }
                _sem.signal();
                return 0;
            }

            /**
             * @brief get 从同步vector中取元素。如果同步vector为空，将阻塞指定时长
             * BGCC_SEMA_WAIT_INFINITE表示无限阻塞。
             *
             * @param elem 取得的元素
             * @param millisecond 超时时长（毫秒）
             *
             * @return 成功返回0；否则返回错误码: E_BGCC_TIMEOUT表示超时.
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012年05月30日 19时12分19秒
             */
            int32_t get(ElemType& elem, int millisecond) {
                int32_t ret = _sem.wait(millisecond);

                if (0 == ret) {
                    {
                        ScopedGuard guard(&_mutex);
                        if (guard.is_locked()) {
                            elem = _vector.back();
                            _vector.pop_back();
                        }
                        else {
                            return E_BGCC_SYSERROR;
                        }
                    }
                    return 0;
                }
                else {
                    return ret;
                }
            }

            int32_t size() {
                ScopedGuard guard(&_mutex);
                return (int32_t)_vector.size();
            }

        protected:
            SyncVector(const SyncVector&);
            SyncVector& operator=(const SyncVector&);

        private:
            std::vector<ElemType> _vector;
            Mutex _mutex;
            Semaphore _sem;

        }; // end of class SyncVector
}

#endif // _BGCC_SYNC_VECTOR_H_
