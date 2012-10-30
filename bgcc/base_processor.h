/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef __BASE_PROCESSOR_HH__
#define __BASE_PROCESSOR_HH__

#include <map>
#include "bgcc.h"
#include <iostream>

#include "processor.h"
#include "exception.h"

namespace bgcc {

    class BaseProcessor : virtual public bgcc::IProcessor, public bgcc::Exception {
    public: 
        BaseProcessor();

        virtual ~BaseProcessor(){};

        virtual int32_t process(
                char* request,
                int32_t request_len,
                SharedPointer<IProtocol> proto);
    protected:
        virtual int32_t do_function__(
                char* request,
                int32_t request_len,
                SharedPointer<IProtocol> proto,
                const std::string& fname,
                int32_t seqid);

    private:
        virtual std::string get_name() const;

        int32_t do___get_ticket_id(
                char* request,
                int32_t request_len,
                SharedPointer<IProtocol> proto,
                int32_t seqid);

        int32_t do___service_not_found(
                char* request,
                int32_t request_len,
                SharedPointer<IProtocol> proto,
                int32_t seqid);

        typedef int32_t (BaseProcessor::* do_function_ptr)(
                char* request,
                int32_t request_len,
                SharedPointer<IProtocol> proto,
                int32_t seqid);
        std::map<std::string, do_function_ptr> __fun_map;
    };

} // namespace


#endif //__BASE_SERVICES_HH__

