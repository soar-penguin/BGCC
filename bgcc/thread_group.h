/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_THREADGROUP_H_
#define _BGCC_THREADGROUP_H_

#include <vector>
#include "thread.h"
#include "shared_pointer.h"

namespace bgcc {

    /**
     * @class ThreadGroup
     * @brief ThreadGroup是Thread的集合，方便管理一组相关线程
     */
    class ThreadGroup {
	public:
        ThreadGroup();
        ~ThreadGroup();

        /**
         * @brief   添加新线程
         * @param   thread 待添加的新线程
         * @return  成功返回true
         */
		bool addThread(SharedPointer<Thread> thread);

        /**
         * @brief   等待线程组中的所有线程执行结束
         * @param   
         * @return  成功返回true
         */
		bool join();

        /**
         * @brief   获取线程组中的线程个数
         * @param   
         * @return  线程组中的线程个数
         */
		size_t size();

        /**
         * @brief   终止线程组中的所有线程的执行
         * @param   
         * @return  成功返回true
         */
		bool terminateAll();
	private:
        ThreadGroup(const ThreadGroup&);
        ThreadGroup& operator=(const ThreadGroup&);

		std::vector<SharedPointer<Thread> > _threads;
        typedef std::vector<SharedPointer<Thread> >::const_iterator citr_type;
	};
}

#endif // _BGCC_THREADGROUP_H_

