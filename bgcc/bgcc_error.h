/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_ERROR_H_
#define _BGCC2_ERROR_H_

#include "bgcc_stdint.h"

#ifdef _WIN32 
#include <Windows.h>
#define BgccGetLastError() GetLastError()
#define BgccSockGetLastError() WSAGetLastError()
#else
#include <errno.h>
#include <stdlib.h>
#define BgccGetLastError() errno
#define BgccSockGetLastError() errno
#endif

namespace bgcc {

    enum {
        S_BGCC_SUCCESS,
        E_BGCC_NULL_POINTER = -10000,
        E_BGCC_CONF_ERROR,
        E_BGCC_NOMEM,
        E_BGCC_INVALID_PARAM,
        E_BGCC_SYSERROR,
        E_BGCC_TIMEOUT,
        E_BGCC_SERVER_ALREADY_INIT,
        E_BGCC_SERVER_INIT_FAILED,
        E_BGCC_SERVER_NEED_INIT,
        E_BGCC_SERVER_CREATE_LISTENFD_FAILED,
        E_BGCC_SERVICE_NOT_FOUND,
        E_BGCC_OUT_MAX_TRY_COUNT
    };

    char* bgcc_strerror_r(int32_t errcode, char* buffer = NULL, int32_t buflen = -1);
}
#endif // _BGCC2_ERROR_H_

