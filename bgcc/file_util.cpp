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
#include <unistd.h>
#else
#include <io.h>
#define close _close
#endif

#include <errno.h>
#include "file_util.h"

namespace bgcc {
    int32_t FileUtil::close_r(int32_t fd) {
        int32_t ret;

        do {
            ret = close(fd);
        } while(-1 == ret && EINTR == errno);
        return ret;
    }
}

