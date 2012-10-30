/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "thread_util.h"

namespace bgcc {
	int64_t ThreadUtil::self_id() {
#ifdef _WIN32
		return (int64_t)GetCurrentThreadId();
#else
		return (int64_t)pthread_self();
#endif
	}
}

