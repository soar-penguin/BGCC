#ifndef _BIDL2SL_ADDRESS_H_
#define _BIDL2SL_ADDRESS_H_

#include <string>
#include <vector>
#include <set>
#include <map>
#include <bgcc.h>

namespace common {
    class Address {
    public:
        Address();
        ~Address();

        std::string city;
        std::string road;
        int32_t number;

        bool operator==(const Address& rhs) const;
        bool operator!=(const Address& rhs) const;
        bool operator< (const Address& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto);
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

}


#endif
