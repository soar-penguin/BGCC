/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef __BASE_PROXY_HH__
#define __BASE_PROXY_HH__

#include "protocol.h"
#include "sync_vector.h"
#include "server_info.h"
#include "binary_protocol.h"
#include "exception.h"
#include "service_manager.h"
#include "time_util.h"
#include "thread.h"
#include "sema.h"

#define GetNewProtocol(prot)\
{\
    SharedPointer<BinaryProtocol> prottmp(new(std::nothrow) BinaryProtocol(client));\
    if(!prot.is_valid())\
    {\
        return false;\
    }\
    prot = prottmp;\
}

namespace bgcc {

    typedef SharedPointer<BinaryProtocol> BinaryProtocolSharedPtr;

    struct callback_thread_arg_t {
        std::string proxy_name;
        std::string server_ip;
        int32_t server_port;
        ServiceManager* service_manager;
		Semaphore* sema;
    };

    class BaseProxy : public Exception {
    public:
        int32_t __get_ticket_id(
                const std::string& fun,
                int32_t& ticket_id,
                bool belast,
                SharedPointer<IProtocol> __iprot,
                SharedPointer<IProtocol> __oprot);

        BaseProxy(
                ServerInfo serverinfo,
                int32_t nprotocols,
                ServiceManager* service_manager = NULL,
                int32_t tryCount = 3,
                int32_t tryInterval = 3000);

        ~BaseProxy();

        std::string get_name() const;
        void set_name(const std::string& name);

        std::string get_whoami() const;
        void set_whoami(const std::string& whoami);
    protected:
        /**
         * @brief init 初始化代理
         *
         * @return 返回成功建立的连接个数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月19日 23时27分05秒
         */
        int32_t init();
        int32_t uninit();

        std::string _name;

        std::string _whoami;

    public:
        SyncVector<SharedPointer<BinaryProtocol> > _protocols;
    protected:
        int32_t _nProtocols;
        ServerInfo _serverinfo;
        int32_t _tryCount;
        int32_t _tryInterval;
        SharedPointer<Thread> _callback_thread;
        ServiceManager* _service_manager;
    };

} // namespace


#endif //__BASE_SERVICES_HH__

