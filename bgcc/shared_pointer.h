/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_SHARED_POINTER_H_
#define _BGCC2_SHARED_POINTER_H_

#include <stdlib.h>

namespace bgcc {

    /**
     * @brief 智能指针类
     *
     * @tparam ElementType 要求该类型有inc()和dec()两函数或继承自bgcc::Shareable类
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月13日 15时19分35秒
     */
    template <typename ElementType>
        class SharedPointer {
        public:
            /**
             * @brief SharedPointer 构造函数
             *
             * @param ptr 资源指针
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012年06月13日 14时33分20秒
             */
            explicit SharedPointer(ElementType* ptr = NULL) : _pointer(ptr) {
                if (NULL != _pointer) {
                    _pointer->inc();
                }
            }

            /**
             * @brief SharedPointer 拷贝构造函数
             *
             * @param other SharedPointer引用
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012年06月13日 15时13分35秒
             */
            SharedPointer(const SharedPointer &other) : _pointer(other._pointer) {
                if (NULL != _pointer) {
                    _pointer->inc();
                }
            }

            /**
             * @brief SharedPointer 拷贝构造函数
             *
             * @tparam U U为SharedPointer子类型
             * @param other other持有ElementType派生类的指针
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012年06月13日 15时14分17秒
             */
            template <typename U>
                SharedPointer(const SharedPointer<U> &other) : _pointer(NULL) {
                    _pointer = other.get();
                    if (NULL != _pointer) {
                        _pointer->inc();
                    }
                }

            /**
             * @brief ~SharedPointer 构造函数，如果引用计数减为0，则释放资源
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012年06月13日 15时15分16秒
             */
            ~SharedPointer() {
                if (NULL != _pointer) {
                    if (_pointer->dec() == 0) {
                        delete _pointer;
                        _pointer = NULL;
                    }
                }
            }

            /**
             * @brief operator= 赋值运算符
             *
             * @param r 赋值运算符右操作数
             *
             * @return 
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012年06月13日 15时15分53秒
             */
            SharedPointer & operator=(const SharedPointer& r) {
                if(_pointer != r._pointer) { //已经判断(this != &r)
                    if (NULL != r._pointer) {
                        r._pointer->inc();
                    }

                    ElementType *ptr = _pointer;
                    _pointer = r._pointer;
                    if (NULL != ptr) {
                        if(ptr->dec() == 0){
                            delete ptr;
                            ptr = NULL;
                        }
                    }
                }

                return *this;
            }

            /**
             * @brief get 获取底层资源指针
             *
             * @return  底层资源指针
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012年06月13日 15时16分21秒
             */
            ElementType* get() const {
                return _pointer;
            }

            /**
             * @brief operator-> 返回底层资源指针
             *
             * @return 资源指针
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012年06月13日 15时17分41秒
             */
            ElementType* operator->() const {
                return _pointer;
            }

            /**
             * @brief operator 返回底层资源引用
             *
             * @return 资源引用
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012年06月13日 15时18分09秒
             */
            ElementType& operator*() const {
                return *_pointer;
            }

            /**
             * @brief is_valid 判断本智能指针是否持有合法的资源
             *
             * @return 返回true，表示合法；否则，返回false 
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012年06月13日 15时18分46秒
             */
            bool is_valid() const {
                return _pointer ? true : false;
            }

        private:
            ElementType* _pointer;  /** 底层资源指针*/
        };
}
#endif // _BGCC2_SHARED_POINTER_H_

