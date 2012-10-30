/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_MEMPOOL_H_
#define _BGCC2_MEMPOOL_H_

#include <map>
#include <vector>
#include "mutex.h"
#include "bgcc_stdint.h"

namespace bgcc {

    class Mempool {
    public:
        static Mempool* get_instance();
        ~Mempool();

        void* get_mem_block(int32_t size);
        void put_mem_block(void* mem_block);

        int32_t get_size(int32_t size);
    private:
        Mempool();
        Mempool& operator=(const Mempool& );

    private:
        int32_t adjust_size(int32_t size);
        void free_mem_block(int32_t size);
        std::map<int32_t, std::vector<void*> > _mem_blocks;

        mutable Mutex _mutex;

    }; // end of class Mempool

}
#endif // _BGCC2_MEMPOOL_H_

