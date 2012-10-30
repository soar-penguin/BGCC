/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_SERVERINFO_H_
#define _BGCC_SERVERINFO_H_

#include <string>
#include "bgcc_stdint.h"

namespace bgcc {
    
    class ServerInfo {
        public:
            ServerInfo(const std::string& serverIp, int32_t port); 
            std::string getIP() const;
            int32_t getPort() const;
        private:
            std::string _serverip;
            int32_t _serverport;
    };

}

#endif
