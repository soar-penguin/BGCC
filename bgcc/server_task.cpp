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
#ifndef _WIN32
#include <netinet/in.h>
#endif
#include "server_task.h"
#include "mempool.h"
#include "log.h"

namespace bgcc {

    ServerTask::ServerTask(
            SharedPointer<IProcessor> processor,
            void* request,
            int32_t request_len,
            SharedPointer<IProtocol> out) :
        _processor(processor), 
        _request(request),
        _request_len(request_len),
        _out(out) {
        }

    int32_t ServerTask::operator()(void* param) {
        int32_t ret;
        char* p = (char*)_request;
        int32_t processor_name_len = (int32_t)ntohl(*(uint32_t*)p);
        p += (4 + processor_name_len);
        ret = _processor->process(p, _request_len - 4 - processor_name_len, _out);
        Mempool::get_instance()->put_mem_block(_request);
        _request = NULL;
        _request_len = 0;
        return ret;
    }
}
