#include "address.h"

namespace common {
    Address::Address() {
    }

    Address::~Address() {
    }

    bool Address::operator==(const Address& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (city != rhs.city) {
            return false;
        }
        if (road != rhs.road) {
            return false;
        }
        if (number != rhs.number) {
            return false;
        }
        return true;
    }

    bool Address::operator!=(const Address& rhs) const {
        return !(*this == rhs);
    }

    bool Address::operator< (const Address& rhs) const {
        if (this == &rhs) {
            return false;
        }

        if (city < rhs.city) {
            return true;
        }
        else if (rhs.city < city) {
            return false;
        }

        if (road < rhs.road) {
            return true;
        }
        else if (rhs.road < road) {
            return false;
        }

        if (number < rhs.number) {
            return true;
        }
        else if (rhs.number < number) {
            return false;
        }

        return false;
    }

    int32_t Address::read(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid;

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if(ret < 0) { return ret; }

            if(ftype == bgcc::IDSTOP){
                break;
            }

            switch(fid) {
            case 1:
                ret = proto->readString(city);
                if (ret < 0) { return ret; }
                break;
            case 2:
                ret = proto->readString(road);
                if (ret < 0) { return ret; }
                break;
            case 3:
                ret = proto->readInt32(number);
                if (ret < 0) { return ret; }
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    int32_t Address::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0;
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid;

        ret = proto->readStructBegin(request + nread, request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while(true) {
            ret = proto->readFieldBegin(request + nread, request_len - nread, fname, ftype, fid);
            if(ret < 0) { return ret; }
            nread += ret;

            if(ftype == bgcc::IDSTOP){
                break;
            }

            switch(fid) {
            case 1:
                ret = proto->readString(request + nread, request_len - nread, city);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 2:
                ret = proto->readString(request + nread, request_len - nread, road);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 3:
                ret = proto->readInt32(request + nread, request_len - nread, number);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    int32_t Address::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;

        ret = proto->writeStructBegin("Address");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("city", bgcc::IDSTR, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeString(city);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("road", bgcc::IDSTR, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeString(road);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("number", bgcc::IDINT32, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(number);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }
}


