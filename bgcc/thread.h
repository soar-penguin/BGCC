/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_THREAD_H_
#define _BGCC2_THREAD_H_


#include "shareable.h"
#include "runnable.h"
#include "shared_pointer.h"
#include "sema.h"

#ifdef _WIN32
#include <Windows.h>
#endif

namespace bgcc {

    typedef void* (*run_func_t)(void*);
    typedef SharedPointer<Runnable> RunnableSharedPointer;
    typedef SharedPointer<Runnable> RunnableSP;
    /**
     * @brief 操作系统线程模型的抽象，负责线程的创建、执行、等待、休眠以及销毁
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月13日 19时57分32秒
     */
    class Thread : public Shareable {
    private:
        enum state_t {
            INIT,
            START,
            JOINED,
            STOP
        };
    public:
        /**
         * @brief Thread 构造函数
         *
         * @param runner 线程执行的任务
         * @param detached 是否分离
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月13日 20时07分35秒
         */
        Thread(const RunnableSP& runner, bool detached = false);

        /**
         * @brief Thread 构造函数
         *
         * @param func 线程执行的任务
         * @param detached 是否分离
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月13日 20时08分00秒
         */
        Thread(run_func_t func, void* arg = NULL, bool detached = false);

        /**
         * @brief ~Thread 析构函数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月13日 20时08分21秒
         */
        ~Thread();

        /**
         * @brief start 启动线程的执行
         *
         * @return 成功返回true
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月13日 20时08分32秒
         */
        bool start();

        /**
         * @brief join 等待线程执行结束
         *
         * @return 成功返回true
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月13日 20时08分59秒
         */
        bool join();

        /**
         * @brief stop 终止线程的执行
         *
         * @return 成功返回true
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月13日 20时09分15秒
         */
        bool stop();

#ifdef _WIN32
        /**
         * @brief get_thread_id 返回线程ID，仅在Windows下使用
         *
         * @return 线程ID
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月13日 20时09分49秒
         */
        DWORD get_thread_id() const;

        /**
         * @brief HANDLE 返回线程句柄，仅在Windows下使用
         *
         * @return 线程句柄
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月13日 20时10分19秒
         */
        operator HANDLE();

#else
        /**
         * @brief get_thread_id 返回线程ID，仅在Linux下使用
         *
         * @return 线程ID
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月13日 20时10分46秒
         */
        pthread_t get_thread_id() const;
#endif

    private:
        bool setDetached();
#ifdef _WIN32
        static DWORD __stdcall thread_start_func(LPVOID lpParam);
#else
        static void* thread_start_func(void* arg);
#endif
    private:
        bool _use_functor;
        RunnableSP _functor;
        run_func_t _func_ptr;
        void* _func_arg;
        Semaphore _sema;
        mutable bool _detached;
        state_t _state;

#ifdef _WIN32
        HANDLE _handle;
        DWORD _thread_id;
#else
        pthread_t _thread;
#endif

    };
}
#endif // _BGCC2_THREAD_H_

