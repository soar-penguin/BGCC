/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include <string.h>
#include "bgcc_error.h"

namespace bgcc {
    char* bgcc_strerror_r(int32_t errcode, char* buffer, int32_t buflen) {
#ifdef _WIN32
		(void)buffer;
		(void)buflen;
		return strerror(errcode);
#else
		if (NULL == buffer || -1 == buflen) {
			return NULL;
		}
		return strerror_r(errcode, buffer, buflen);
#endif
    }
}

