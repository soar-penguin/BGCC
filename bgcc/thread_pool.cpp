/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include <iostream>
#include "thread_pool.h"
#include "thread_manager.h"

namespace bgcc {

    /**
     * @class ThreadPoolRunner
     * @brief 线程池任务类型
     */
    class ThreadPool::ThreadPoolRunner : public Runnable {
    public:
        /**
         * @brief   线程池构造函数
         * @param   tp 线程池
         * @return  
         */
        ThreadPoolRunner(ThreadPool* tp);

        /**
         * @brief   执行体
         * @param   
         * @return  
         */
        virtual int32_t operator()(void* param);
    private:
        ThreadPool* _tp;
    };

    ThreadPool::ThreadPoolRunner::ThreadPoolRunner(ThreadPool* tp) : _tp(tp) {
    }

    int32_t ThreadPool::ThreadPoolRunner::operator()(void* param) {
        while (true) {
            RunnableSharedPointer pr;
            _tp->_tasks.get(pr, BGCC_SEMA_WAIT_INFINITE);
            if (pr.is_valid()) {
                (*pr)();
            }
        }
        return 1;
    }

    ThreadPool::ThreadPool() : _state(UNINITIALIZED) {
    }

    ThreadPool::~ThreadPool() {
        terminate();
    }

    int ThreadPool::init(int nThreads) {
        int ret = 0;
        if (UNINITIALIZED == _state) {
            _state = INITIALIZED;

            addWorker(nThreads);
        }

        return ret;
    }

    bool ThreadPool::addTask(RunnableSharedPointer pr) {
        return 0 == _tasks.put(pr);
    }

    bool ThreadPool::join() {
        return _threadGroup.join();
    }

    size_t ThreadPool::size() {
        return _threadGroup.size();
    }

    bool ThreadPool::terminate() {
        return _threadGroup.terminateAll();
    }

    int ThreadPool::addWorker(int nWorker) {
        int ret = 0;
        for (int i = 0; i < nWorker; ++i) {
            SharedPointer<Thread> workerThread = ThreadManager::createThread(
                    RunnableSharedPointer(new ThreadPoolRunner(this)));
            if (workerThread.is_valid()) {
                _threadGroup.addThread(workerThread);
                ++ret;
            }
        }
        return ret;
    }
}

