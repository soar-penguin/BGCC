/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_SERVERTASK_H_
#define _BGCC_SERVERTASK_H_

#include "runnable.h"
#include "protocol.h"
#include "processor.h"

namespace bgcc {
    /**
     * @class ServerTask
     * @brief 可被ThreadPool执行的任务类型
     */
    class ServerTask : public Runnable {
        public:
            /** 
             * @brief   构造函数
             * @param   processor 处理器对象
             * @param   in 读入数据协议对象
             * @param   out 写出数据协议对象
             **/
            ServerTask(SharedPointer<IProcessor> processor,
                    void* request,
                    int32_t request_len,
                    SharedPointer<IProtocol> out);

            /**
             * @brief   任务执行体
             * @param   
             * @return  
             */
            virtual int32_t operator()(void* param = NULL);

            virtual ~ServerTask() { }

        private:
			/** 任务处理器对象 */
            SharedPointer<IProcessor> _processor;

            void* _request;
            int32_t _request_len;

			/** 写出数据协议对象 */
            SharedPointer<IProtocol> _out;
    };
}

#endif
