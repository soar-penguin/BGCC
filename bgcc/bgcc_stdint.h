/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_BGCC_STDINT_H_
#define _BGCC_BGCC_STDINT_H_

#if defined _WIN32 && _MSC_VER < 1600
typedef __int8				int8_t;
typedef __int16				int16_t;
typedef __int32				int32_t;
typedef __int64				int64_t;

typedef unsigned __int8		uint8_t;
typedef unsigned __int16	uint16_t;
typedef unsigned __int32	uint32_t;
typedef unsigned __int64	uint64_t;

#pragma warning( disable : 4065 4267 )

#else
#include <stdint.h>
#endif

#endif // _BGCC_BGCC_STDINT_H_

