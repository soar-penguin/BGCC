/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include <utility>
#include <stdlib.h>
#include "mempool.h"
#include "guard.h"

namespace bgcc {

    Mempool* Mempool::get_instance() {
        static Mempool mp;
        return &mp;
    }

    Mempool::Mempool() {
        _mem_blocks.insert(std::make_pair(128, std::vector<void*>()));
        _mem_blocks.insert(std::make_pair(256, std::vector<void*>()));
        _mem_blocks.insert(std::make_pair(512, std::vector<void*>()));
        _mem_blocks.insert(std::make_pair(1024, std::vector<void*>()));
    }

    Mempool::~Mempool() {
        free_mem_block(128);
        free_mem_block(256);
        free_mem_block(512);
        free_mem_block(1024);
        _mem_blocks.clear();
    }

    void Mempool::free_mem_block(int32_t size) {
        std::vector<void*>& v = _mem_blocks[size];
        std::vector<void*>::iterator itr;

        for (itr = v.begin(); itr != v.end(); ++itr) {
            void* buf = (char*)*itr - 4;
            free(buf);
        }
        v.clear();
    }

    void* Mempool::get_mem_block(int32_t size) {
        void* ret = NULL;
        size = adjust_size(size);

        if (size <= 1024) {
            Guard<Mutex> guard(&_mutex);
            std::vector<void*>& v = _mem_blocks[size];
            if (v.size() > 0) {
                ret = v.back();
                v.pop_back();
            }
        }

        if (NULL == ret) {
            ret = malloc(size + 4);
            if (NULL != ret) {
                int32_t* pi = (int32_t*)ret;
                *pi = size;
                ret = (char*)ret + 4;
            }
        }
        return ret;
    }

    void Mempool::put_mem_block(void* mem_block) {
        if (NULL == mem_block) {
            return;
        }

        int32_t* pi = (int32_t*)((char*)mem_block - 4);
        if (*pi > 1024) {
            free(pi);
        }
        else {
            Guard<Mutex> guard(&_mutex);
            _mem_blocks[*pi].push_back(mem_block);
        }
    }

    int32_t Mempool::adjust_size(int32_t size) {
        if (size <= 128) {
            return 128;
        }
        else if (size <= 256) {
            return 256;
        }
        else if (size <= 512) {
            return 512;
        }
        else if (size <= 1024) {
            return 1024;
        }
        else {
            return size;
        }
    }

    int32_t Mempool::get_size(int32_t size) {
        Guard<Mutex> guard(&_mutex);
        return (int32_t)_mem_blocks[size].size();
    }
}

