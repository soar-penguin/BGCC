/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _WIN32
#include <netinet/in.h>
#endif

#include <string.h>

#include "nb_data_buffer.h"
#include "byte_order.h"
#include "bgcc_error.h"

namespace bgcc {

    NBDataBuffer::NBDataBuffer() :_size(0), _maxsize(0), _data(NULL) { }

    NBDataBuffer::~NBDataBuffer() {
        clear();
    }

    int32_t NBDataBuffer::append_bool(bool b) {
        uint8_t tmp = b ? 1 : 0;
        return append(&tmp, sizeof(uint8_t));
    }

    int32_t NBDataBuffer::append_int8(int8_t i8) {
        return append(&i8, sizeof(int8_t));
    }

    int32_t NBDataBuffer::append_int16(int16_t i16) {
        uint16_t tmp = htons((uint16_t)i16);
        return append(&tmp, sizeof(uint16_t));
    }

    int32_t NBDataBuffer::append_int32(int32_t i32) {
        uint32_t tmp = htonl((uint32_t)i32);
        return append(&tmp, sizeof(uint32_t));
    }

    int32_t NBDataBuffer::append_int64(int64_t i64) {
        uint64_t tmp = HTONLL((uint64_t)i64);
        return append(&tmp, sizeof(uint64_t));
    }

    int32_t NBDataBuffer::append_float(float f) {
        uint32_t tmp = htonl(*(uint32_t*)&f);
        return append(&tmp, sizeof(uint32_t));
    }

    int32_t NBDataBuffer::append_string(const std::string& str) {
        int32_t ret;
        int32_t len = (int32_t)str.length();

        ret = append_int32(len);
        if (0 != ret) {
            return ret;
        }

        return append(str.data(), len);
    }

    int32_t NBDataBuffer::append_binary(const void* buffer, int32_t buflen) {
        int32_t ret;

        ret = append_int32(buflen);
        if (0 != ret) {
            return ret;
        }

        return append(buffer, buflen);
    } 

    int32_t NBDataBuffer::append(const void* buffer, int32_t buflen) {
        if (NULL == buffer) {
            return E_BGCC_NULL_POINTER;
        }

        if (buflen < 0) {
            return E_BGCC_INVALID_PARAM;
        }
        else if (0 == buflen) {
            return 0;
        }

        if (_size + buflen > _maxsize) {
            int32_t newsize = (buflen + _maxsize) * 2;
            void *ptr;
            ptr = realloc(_data, newsize);
            if (NULL == ptr) {
                newsize = _size + buflen;
                ptr = realloc(_data, newsize);
                if (NULL == ptr) {
                    return E_BGCC_NOMEM;
                }
            }
            _data = ptr;
            _maxsize = newsize;
        }

        memcpy((char*)_data + _size, buffer, buflen);
        _size += buflen;
        return 0;
    }

    int32_t NBDataBuffer::get_data(void** ppdata, int32_t& size) {
        if (NULL == ppdata) {
            return E_BGCC_NULL_POINTER;
        }

        *ppdata = _data;
        size = _size;
        return 0;
    }

    int32_t NBDataBuffer::get_data_copy(void** ppdata, int32_t& size) {
        if (NULL == ppdata) {
            return E_BGCC_NULL_POINTER;
        }

        if (0 == _size) {
            *ppdata = NULL;
        }
        else {
            *ppdata = malloc(_size);
            if (NULL == *ppdata) {
                return E_BGCC_NOMEM;
            }
            else {
                memcpy(*ppdata, _data, _size);
            }
        }
        size = _size;
        return 0;
    }

    int32_t NBDataBuffer::clear(bool keepAllocatedMem) {
        _size = 0;
        if (NULL != _data && !keepAllocatedMem) {
            free(_data);
            _data = NULL;
            _maxsize = 0;
        }
        return 0;
    }
}

