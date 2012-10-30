/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include <stdio.h>
#include "mutex.h"
#include "time_util.h"
#include "bgcc_error.h"

namespace bgcc {

    Mutex::Mutex() {
#ifdef _WIN32
        _mutex = CreateMutex(NULL, FALSE, NULL);
#else
        int32_t ret = 0;
        pthread_mutexattr_t attr;

        ret = pthread_mutexattr_init(&attr);
        if (0 != ret) {
            ret = pthread_mutex_init(&this->_mutex, NULL);
        } else {
            ret = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK_NP);
            ret = pthread_mutex_init(&_mutex, &attr);
            pthread_mutexattr_destroy(&attr);
        }
#endif
    }

    Mutex::~Mutex() {
#ifdef _WIN32
        BOOL ret = CloseHandle(_mutex);
        if (0 != ret) {
            _mutex = NULL;
        }
#else
        pthread_mutex_destroy(&_mutex);
#endif
    }

    int32_t Mutex::lock(uint32_t millisecond) {
#ifdef _WIN32
        if (NULL == _mutex) {
            return E_BGCC_NULL_POINTER;
        }

        DWORD ret = WaitForSingleObject(_mutex, millisecond);
        if (WAIT_OBJECT_0 == ret) {
            return 0;
        }
        else if (WAIT_TIMEOUT == ret) {
            return E_BGCC_TIMEOUT;
        }
        else {
            return E_BGCC_SYSERROR;
        }
#else
        int32_t ret = 0;

        if (BGCC_MUTEX_WAIT_INFINITE == millisecond) {
            ret = pthread_mutex_lock(&_mutex);
        }
        else {
            struct timespec ts = {0, 0};
            TimeUtil::get_abs_timespec(&ts, millisecond);
            ret = pthread_mutex_timedlock(&_mutex, &ts);
        }

        if (0 != ret) {
            int32_t e = BgccGetLastError();
            if (ETIMEDOUT == e) {
                return E_BGCC_TIMEOUT;
            }
            else {
                return E_BGCC_SYSERROR;
            }
        }
        return 0;
#endif
    }

    int32_t Mutex::try_lock() {
#ifdef _WIN32
        return lock(1);
#else
        int32_t ret = 0;
        ret = pthread_mutex_trylock(&_mutex);
        return (0 == ret ? 0 : E_BGCC_SYSERROR);
#endif
    }

    int32_t Mutex::unlock() {
#ifdef _WIN32
        BOOL ret = FALSE;

        if (NULL != _mutex) {
            ret = ReleaseMutex(_mutex);
        }
        return (0 != ret ? 0 : E_BGCC_SYSERROR);
#else
        int32_t ret = 0;
        ret = pthread_mutex_unlock(&_mutex);
        return (0 == ret ? 0 : E_BGCC_SYSERROR);
#endif
    } 

}
