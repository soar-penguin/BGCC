/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_BYTE_ORDER_H_
#define _BGCC2_BYTE_ORDER_H_

#define bswap_64(x) ((uint64_t)( \
            (((uint64_t)(x) & (uint64_t)0x00000000000000ffull) << 56) | \
            (((uint64_t)(x) & (uint64_t)0x000000000000ff00ull) << 40) | \
            (((uint64_t)(x) & (uint64_t)0x0000000000ff0000ull) << 24) | \
            (((uint64_t)(x) & (uint64_t)0x00000000ff000000ull) << 8)  | \
            (((uint64_t)(x) & (uint64_t)0x000000ff00000000ull) >> 8)  | \
            (((uint64_t)(x) & (uint64_t)0x0000ff0000000000ull) >> 24) | \
            (((uint64_t)(x) & (uint64_t)0x00ff000000000000ull) >> 40) | \
            (((uint64_t)(x) & (uint64_t)0xff00000000000000ull) >> 56)))

#ifdef _BIG_ENDIAN
#define htonll(x) (x)
#define ntohll(x) (x)
#else
#define HTONLL(x) bswap_64(x)
#define NTOHLL(x) bswap_64(x)
#endif

#endif // _BGCC2_BYTE_ORDER_H_

