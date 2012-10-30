/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_SOCKET_UTIL_H_
#define _BGCC2_SOCKET_UTIL_H_

#include <string.h>
#include "peer_info.h"

namespace bgcc {

    int32_t getpeerinfo(int32_t sockfd, PeerInfo& peerInfo); 
}

#endif // _BGCC2_SOCKET_UTIL_H_

