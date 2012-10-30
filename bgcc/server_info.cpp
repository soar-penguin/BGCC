/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "server_info.h"

namespace bgcc {

    ServerInfo::ServerInfo(const std::string& serverIp, int32_t port)
    {
        _serverip = serverIp;
        _serverport = port;
    }

    std::string ServerInfo::getIP() const {
        return _serverip;
    }

    int32_t ServerInfo::getPort() const {
        return _serverport;
    }

}
