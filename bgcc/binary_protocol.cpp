/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _WIN32
#include <netinet/in.h> // for ntohl ntohs htonl htons
#endif

#include <string.h>
#include "binary_protocol.h"
#include "byte_order.h"
#include "log.h"

namespace bgcc {
    BinaryProtocol::BinaryProtocol(TransportSharedPointer transport)
        :_transport(transport) { }

    int32_t BinaryProtocol::writeBool(const bool value) {
        return _data.append_bool(value);
    }

    int32_t BinaryProtocol::readBool(bool& value) {
        uint8_t tmp;
        int32_t ret;

        ret = _transport->read(&tmp, 1);
        if (0 == ret) {
            value = (1 == tmp) ? true : false;
        } else {
        }

        return ret;
    }

    int32_t BinaryProtocol::writeByte(const int8_t value) {
        return _data.append_int8(value);
    }

    int32_t BinaryProtocol::readByte(int8_t& value) {
        int8_t tmp;
        int32_t ret;

        ret = _transport->read(&tmp, 1);
        if (0 == ret) {
            value = tmp;
        } else {
        }

        return ret;
    }

    int32_t BinaryProtocol::writeInt16(const int16_t value) {
        return _data.append_int16(value);
    }

    int32_t BinaryProtocol::readInt16(int16_t& value) {
        union bytes {
            uint8_t b[2];
            uint16_t all;
        }data;
        int32_t ret;

        ret = _transport->read(data.b, 2);
        if (0 == ret) {
            value = (int16_t)::ntohs(data.all);
        } else {
        }

        return ret;
    }

    int32_t BinaryProtocol::writeInt32(const int32_t value) {
        return _data.append_int32(value);
    }

    int32_t BinaryProtocol::readInt32(int32_t& value) {
        union bytes {
            uint8_t b[4];
            uint32_t all;
        }data;
        int32_t ret;

        ret = _transport->read(data.b, 4);
        if (0 == ret) {
            value = (int32_t)::ntohl(data.all);
        } else {
        }

        return ret;
    }

    int32_t BinaryProtocol::writeInt64(const int64_t value) {
        return _data.append_int64(value);
    }

    int32_t BinaryProtocol::readInt64(int64_t& value) {
        union bytes {
            uint8_t b[8];
            uint64_t all;
        }data;
        int32_t ret;

        ret = _transport->read(data.b, 8);
        if (0 == ret) {
            data.all = NTOHLL(data.all);
            value = (int64_t)data.all;
        } else {
        }

        return ret;
    }

    int32_t BinaryProtocol::writeFloat(const float value) {
        return _data.append_float(value);
    }

    int32_t BinaryProtocol::readFloat(float& value) {
        union bytes {
            uint8_t b[4];
            uint32_t w;
            float f;
        }data;
        int32_t ret;

        ret = _transport->read(data.b, 4);
        if (0 == ret) {
            data.w = ::ntohl(data.w);
            value = data.f;
        } else {
        }

        return ret;
    }

    int32_t BinaryProtocol::writeString(const std::string& value) {
        return _data.append_string(value);
    }

    int32_t BinaryProtocol::readString(std::string& value) {
        int32_t len;
        int32_t ret;

        ret = readInt32(len);
        if (0 != ret) {
            return ret;
        }

        if (len < 0) {
            return -1;
        } else if (0 == len) {
            value = "";
            return 0;
        }

        char *buffer = (char*)malloc(len);
        if (NULL != buffer) {
            ret = _transport->read(buffer, len);
            if (0 != ret) {
                free(buffer);
                return ret;
            }

            value = std::string(buffer, len);
            free(buffer);


            return 0;
        } else {
            return -1;
        }
    }

    int32_t BinaryProtocol::writeBinary(const void* data, const int32_t size) {
        return _data.append_binary(data, size);
    }

    int32_t BinaryProtocol::readBinary(std::string& value) {
        int32_t ret;
        ret = readString(value);
        if (0 == ret) {
        } else {
        }
        return ret;
    }

    int32_t BinaryProtocol::writeMessageBegin(
            const std::string& processor_name,
            const std::string& function_name,
            const MsgTypeID msg_type,
            const SequenceNOType seq_no) {

        // msg header 
        int32_t ret;

        if ((ret = writeByte(0x62)) != 0) {   //magic
            return ret;
        }
        if ((ret = writeByte(0x67)) != 0) {   //magic
            return ret;
        }
        if ((ret = writeByte(0x63)) != 0) {   //magic
            return ret;
        }
        if ((ret = writeByte(0x50)) != 0) {   //magic
            return ret;
        }

        if ((ret = writeByte(0x01)) != 0) {   //version
            return ret;
        }
        if ((ret = writeByte(0x00)) != 0) {   //version
            return ret;
        }

        if ((ret = writeByte(0x01)) != 0) {   //proto type
            return ret;
        }

        if ((ret = writeByte(0x00)) != 0) {   //reserved
            return ret;
        }

        if ((ret = writeInt32(0)) != 0) {     //logid
            return ret;
        }

        if ((ret = writeInt32(seq_no)) != 0) { //ticketid
            return ret;
        }

        if ((ret = writeInt32(0)) != 0) {     //body size
            return ret;
        }

        //msg body 

        if ((ret = writeString(processor_name)) != 0) { //processor name
            return ret;
        }

        if ((ret = writeInt16(msg_type)) != 0) { //msg type
            return ret;
        }

        if ((ret = writeInt32(seq_no)) != 0) { //ticketid  故意重复
            return ret;
        }

        if ((ret = writeInt16(0)) != 0) {     //function version
            return ret;
        }

        if ((ret = writeString(function_name)) != 0) { //function name
            return ret;
        }

        return 0;
    }

    int32_t BinaryProtocol::writeMessageEnd() {
        void *pdata;
        int32_t size;
        int32_t body_size;
        int32_t ret;

        ret = _data.get_data_copy(&pdata, size);
        body_size = (int32_t)htonl(size - 20);   /** 除去头的20个字节长度*/
        if (0 == ret && pdata) {
            memcpy((uint8_t*)pdata+16, &body_size, 4);
            ret = _transport->write(pdata, size);
            free(pdata);

            if (0 != ret) {
            }
        } else {
        }
        _data.clear();

        return ret;
    }

    int32_t BinaryProtocol::readMessageBegin(std::string& msgName,
            MsgTypeID& msgType,
            SequenceNOType& seqNO) {

        int32_t ret = 0;
        int8_t t8;

        ret = readByte(t8);
        if (0 != ret) {
            return ret;
        }
        ret = readByte(t8);
        if (0 != ret) {
            return ret;
        } 
        ret = readByte(t8);
        if (0 != ret) {
            return ret;
        } 
        ret = readByte(t8);
        if (0 != ret) {
            return ret;
        }
        ret = readByte(t8);
        if (0 != ret) {
            return ret;
        } 
        ret = readByte(t8);
        if (0 != ret) {
            return ret;
        }
        ret = readByte(t8);
        if (0 != ret) {
            return ret;
        }
        ret = readByte(t8);
        if (0 != ret) {
            return ret;
        }

        int32_t t32;
        ret = readInt32(t32);
        if (0 != ret) {
            return ret;
        }
        ret = readInt32(t32);
        if (0 != ret) {
            return ret;
        } 
        ret = readInt32(t32);
        if (0 != ret) {
            return ret;
        }

        std::string tstr;
        ret = readString(tstr);
        if (0 != ret) {
            return ret;
        }

        int16_t t16;
        ret = readInt16(t16);
        if (0 != ret) {
            return ret;
        }
        msgType = (MsgTypeID)t16;

        ret = readInt32(t32);
        if (0 != ret) {
            return ret;
        }
        seqNO = (SequenceNOType)t32;

        ret = readInt16(t16);
        if (0 != ret) {
            return ret;
        }

        ret = readString(msgName);
        if (0 != ret) {
            return ret;
        }
        return 0;
    }

    int32_t BinaryProtocol::readMessageEnd() {
        return 0;
    }

    int32_t BinaryProtocol::writeStructBegin(const std::string& name) {
        return writeString(name);
    }

    int32_t BinaryProtocol::writeStructEnd() {
        return 0;
    }

    int32_t BinaryProtocol::readStructBegin(std::string& name) {
        int32_t ret;
        ret = readString(name);
        if (0 != ret) {
        } else {
        }
        return ret;
    }

    int32_t BinaryProtocol::readStructEnd() {
        return 0;
    }

    int32_t BinaryProtocol::writeFieldBegin(const std::string& name,
            const DataTypeID fieldType,
            const FieldIDType fieldId) {

        int32_t ret;

        // 先写入fieldType
        ret = writeInt32(fieldType);
        if (0 != ret) {
            return ret;
        }

        ret = writeString(name);
        if (0 != ret) {
            return ret;
        }

        ret = writeInt32(fieldId);
        if (0 != ret) {
        } else {
        }

        return ret;
    }

    int32_t BinaryProtocol::writeFieldEnd() {
        return 0;
    }

    int32_t BinaryProtocol::readFieldBegin(std::string& name,
            DataTypeID& fieldType,
            FieldIDType& fieldID) {
        int32_t ret;
        int32_t tmp;

        // 先读取fieldType
        ret = readInt32(tmp);
        if (0 != ret) {
            return ret;
        }
        fieldType = (DataTypeID)tmp;

        if (IDSTOP == fieldType) {
            return ret;
        }

        ret = readString(name);
        if (0 != ret) {
            return ret;
        }

        ret = readInt32(tmp);
        if (0 == ret) {
            fieldID = (FieldIDType)tmp;
        } else {
        }

        return ret;
    }

    int32_t BinaryProtocol::readFieldEnd() {
        return 0;
    }

    int32_t BinaryProtocol::writeFieldStop() {
        return writeInt32(IDSTOP);
    }

    int32_t BinaryProtocol::writeMapBegin(const DataTypeID keyType,
            const DataTypeID valueType,
            const int32_t size) {
        int32_t ret;

        ret = writeInt32(keyType);
        if (0 != ret) {
            return ret;
        }

        ret = writeInt32(valueType);
        if (0 != ret) {
            return ret;
        }

        ret = writeInt32(size);
        if (0 != ret) {
        } else {
        }
        return ret;
    }

    int32_t BinaryProtocol::writeMapEnd() {
        return 0;
    }

    int32_t BinaryProtocol::readMapBegin(DataTypeID& keyType,
            DataTypeID& valueType,
            int32_t& size) {
        int32_t ret;
        int32_t tmp;

        ret = readInt32(tmp);
        if (0 != ret) {
            return ret;
        }
        keyType = (DataTypeID)tmp;

        ret = readInt32(tmp);
        if (0 != ret) {
            return ret;
        }
        valueType = (DataTypeID)tmp;

        ret = readInt32(size);
        if (0 != ret) {
        } else {
        }

        return ret;
    }

    int32_t BinaryProtocol::readMapEnd() {
        return 0;
    }

    int32_t BinaryProtocol::writeListBegin(const DataTypeID elemType,
            const int32_t size) {
        int32_t ret;

        ret = writeInt32(elemType);
        if (0 != ret) {
            return ret;
        }

        ret = writeInt32(size);
        if (0 != ret) {
        } else {
        }
        return ret;
    }

    int32_t BinaryProtocol::writeListEnd() {
        return 0;
    }

    int32_t BinaryProtocol::readListBegin(DataTypeID& elemType, int32_t& size) {
        int32_t ret;
        int32_t tmp;

        ret = readInt32(tmp);
        if (0 != ret) {
            return ret;
        }
        elemType = (DataTypeID)tmp;

        ret = readInt32(size);
        if (0 != ret) {
        } else {
        }
        return ret;
    }

    int32_t BinaryProtocol::readListEnd() {
        return 0;
    }

    int32_t BinaryProtocol::writeSetBegin(const DataTypeID elemType,
            const int32_t size) {
        int32_t ret;

        ret = writeInt32(elemType);
        if (0 != ret) {
            return ret;
        }

        ret = writeInt32(size);
        if (0 != ret) {
        } else {
        }
        return ret;
    }

    int32_t BinaryProtocol::writeSetEnd() {
        return 0;
    }

    int32_t BinaryProtocol::readSetBegin(DataTypeID& elemType, int32_t& size) {
        int32_t ret;
        int32_t tmp;

        ret = readInt32(tmp);
        if (0 != ret) {
            return ret;
        }
        elemType = (DataTypeID)tmp;

        ret = readInt32(size);
        if (0 != ret) {
        } else {
        }
        return ret;
    }

    int32_t BinaryProtocol::readSetEnd() {
        return 0;
    }

    int32_t BinaryProtocol::setTransport(TransportSharedPointer transport) {
        _transport = transport;
        return 0;
    }

    BinaryProtocol::TransportSharedPointer BinaryProtocol::getTransport() {
        return _transport;
    }

    int32_t BinaryProtocol::skip(DataTypeID dataTypeID) {
        int32_t ret = 0;

        switch(dataTypeID) {
        case IDSTOP:
            break;
        case IDBOOL:
            ret = skipBool();
            break;
        case IDBYTE:
            ret = skipByte();
            break;
        case IDINT16:
            ret = skipInt16();
            break;
        case IDINT32:
            ret = skipInt32();
            break;
        case IDINT64:
            ret = skipInt64();
            break;
        case IDFLOAT:
            ret = skipFloat();
            break;
        case IDSTR:
            ret = skipString();
            break;
        case IDBIN:
            ret = skipBinary();
            break;
        case IDSTRUCT:
            ret = skipStruct();
            if (0 != ret) {
            } else {
            }
            break;
        case IDMAP:
            ret = skipMap();
            if (0 != ret) {
            } else {
            }
            break;
        case IDSET:
            ret = skipSet();
            if (0 != ret) {
            } else {
            }
            break;
        case IDLIST:
            ret = skipList();
            if (0 != ret) {
            } else {
            }
            break;
        default:
            ret = -1;
        }

        return ret;
    }

    int32_t BinaryProtocol::skipBool() {
        bool value;
        int32_t ret;

        ret = readBool(value);
        if (0 != ret) {
        } else {
        }
        return ret;
    }

    int32_t BinaryProtocol::skipByte() {
        int8_t value;
        int32_t ret;

        ret = readByte(value);
        if (0 != ret) {
        } else {
        }
        return ret;
    }

    int32_t BinaryProtocol::skipInt16() {
        int16_t value;
        int32_t ret;

        ret = readInt16(value);
        if (0 != ret) {
        } else {
        }
        return ret;
    }

    int32_t BinaryProtocol::skipInt32() {
        int32_t value;
        int32_t ret;

        ret = readInt32(value);
        if (0 != ret) {
        } else {
        }
        return ret;
    }

    int32_t BinaryProtocol::skipInt64() {
        int64_t value;
        int32_t ret;

        ret = readInt64(value);
        if (0 != ret) {
        } else {
        }
        return ret;
    }

    int32_t BinaryProtocol::skipFloat() {
        float value;
        int32_t ret;

        ret = readFloat(value);
        if (0 != ret) {
        } else {
        }
        return ret;
    }

    int32_t BinaryProtocol::skipString() {
        std::string value;
        int32_t ret;

        ret = readString(value);
        if (0 != ret) {
        } else {
        }
        return ret;
    }

    int32_t BinaryProtocol::skipBinary() {
        std::string value;
        int32_t ret;

        ret = readBinary(value);
        if (0 != ret) {
        } else {
        }
        return ret;
    }

    int32_t BinaryProtocol::skipStruct() {
        int32_t ret = 0;
        std::string name;

        ret = readStructBegin(name);
        if (0 != ret) {
            return ret;
        }

        ret = skipStructFields();
        if (0 != ret) {
            return ret;
        }

        ret = readStructEnd();
        return ret;
    }

    int32_t BinaryProtocol::skipStructFields() {
        int32_t ret = 0;
        bool stop = false;

        while(!stop) {
            ret = skipStructField(stop);
            if (0 != ret) {
                break;
            }
        }

        return ret;
    }

    int32_t BinaryProtocol::skipStructField(bool& stop) {
        int32_t ret = 0;
        std::string fieldName;
        DataTypeID fieldType;
        FieldIDType fieldID;

        ret = readFieldBegin(fieldName, fieldType, fieldID);
        if (0 != ret) {
            return ret;
        }

        if (IDSTOP == fieldType) {
            stop = true;
            return 0;
        }

        ret = skip(fieldType);
        if (0 != ret) {
            return ret;
        }

        ret = readFieldEnd();
        return ret;
    }

    int32_t BinaryProtocol::skipMap() {
        int32_t ret = 0;
        DataTypeID keyType;
        DataTypeID valueType;
        int32_t size;

        ret = readMapBegin(keyType, valueType, size);
        if (0 != ret) {
            return ret;
        }

        ret = skipMapElements(keyType, valueType, size);
        if (0 != ret) {
            return ret;
        }

        ret = readMapEnd();
        return ret;
    }

    int32_t BinaryProtocol::skipMapElements(DataTypeID keyType,
            DataTypeID valueType,
            int32_t size) {
        int32_t ret = 0;

        for (int32_t i = 0; i < size; ++i) {
            ret = skip(keyType);
            if (0 != ret) {
                return ret;
            }

            ret = skip(valueType);
            if (0 != ret) {
                return ret;
            }
        }

        return ret;
    }

    int32_t BinaryProtocol::skipSet() {
        int32_t ret = 0;
        DataTypeID elemType;
        int32_t size;

        ret = readSetBegin(elemType, size);
        if (0 != ret) {
            return ret;
        }

        ret = skipSetElements(elemType, size);
        if (0 != ret) {
            return ret;
        }

        ret = readSetEnd();
        return ret;
    }

    int32_t BinaryProtocol::skipSetElements(DataTypeID elemType,
            int32_t size) {
        int32_t ret = 0;

        for (int32_t i = 0; i < size; ++i) {
            ret = skip(elemType);
            if (0 != ret) {
                break;
            }
        }

        return ret;
    }

    int32_t BinaryProtocol::skipList() {
        int32_t ret = 0;
        DataTypeID elemType;
        int32_t size;

        ret = readListBegin(elemType, size);
        if (0 != ret) {
            return ret;
        }

        ret = skipListElements(elemType, size);
        if (0 != ret) {
            return ret;
        }

        ret = readListEnd();
        return ret;
    }

    int32_t BinaryProtocol::skipListElements(DataTypeID elemType,
            int32_t size) {
        int32_t ret = 0;

        for (int32_t i = 0; i < size; ++i) {
            ret = skip(elemType);
            if (0 != ret) {
                break;
            }
        }

        return ret;
    }

    int32_t BinaryProtocol::getDataCopy(void** ppdata, int32_t& size) {
        if (NULL == ppdata) {
            return -1;
        } else {
            return _data.get_data_copy(ppdata, size);
        }
    }

    int32_t BinaryProtocol::readBool(char* request, int32_t request_len, bool& value) {
        uint8_t tmp;

        if (request_len < 1) {
            return -1;
        }

        tmp = *(uint8_t*)request;
        value = (1 == tmp) ? true : false;
        return 1;
    }

    int32_t BinaryProtocol::readByte(char* request, int32_t request_len, int8_t& value) { 
        if (request_len < 1) {
            return -1;
        }

        value = *(int8_t*)request;
        return 1;
    }

    int32_t BinaryProtocol::readInt16(char* request, int32_t request_len, int16_t& value) {
        if (request_len < 2) {
            return -1;
        }

        value = (int16_t)::ntohs(*(uint16_t*)request);
        return 2;
    }

    int32_t BinaryProtocol::readInt32(char* request, int32_t request_len, int32_t& value) {
        if (request_len < 4) {
            return -1;
        }

        value = (int32_t)::ntohl(*(uint32_t*)request);
        return 4;
    }

    int32_t BinaryProtocol::readInt64(char* request, int32_t request_len, int64_t& value) {
        if (request_len < 8) {
            return -1;
        }

        value = (int64_t)NTOHLL(*(uint64_t*)request);
        return 8;
    }

    int32_t BinaryProtocol::readFloat(char* request, int32_t request_len, float& value) {
        if (request_len < 4) {
            return -1;
        }

        int32_t tmp = (int32_t)::ntohl(*(uint32_t*)request);
        value = *(float*)&tmp;
        return 4;
    }

    int32_t BinaryProtocol::readString(char* request, int32_t request_len, std::string& value) {
        if (request_len < 4) {
            return -1;
        }

        int32_t ret;
        int32_t len;
        ret = readInt32(request, request_len, len);
        if (ret < 0) {
            return ret;
        }

        if (request_len < len + 4) {
            return -1;
        }
        value = std::string(request + 4, len);
        return(4 + len);
    }

    int32_t BinaryProtocol::readBinary(char* request, int32_t request_len, std::string& value) {
        return readString(request, request_len, value);
    }

    int32_t BinaryProtocol::readSetBegin(char* request, int32_t request_len, DataTypeID& elemType, int32_t& size) {
        int32_t nread = 0;
        int32_t ret;

        int32_t xxx;
        ret = readInt32(request + nread, request_len - nread, xxx);
        if (ret < 0) {
            return ret;
        }
        elemType = (DataTypeID)xxx;
        nread += ret;

        ret = readInt32(request + nread, request_len - nread, size);
        if (ret < 0) {
            return ret;
        }
        nread += ret;

        return nread;
    }

    int32_t BinaryProtocol::readSetEnd(char* request, int32_t request_len) {
        return 0;
    }

    int32_t BinaryProtocol::readListBegin(char* request, int32_t request_len, DataTypeID& elemType, int32_t& size) {
        int32_t nread = 0;
        int32_t ret;

        int32_t xxx;
        ret = readInt32(request + nread, request_len - nread, xxx);
        if (ret < 0) {
            return ret;
        }
        elemType = (DataTypeID)xxx;
        nread += ret;

        ret = readInt32(request + nread, request_len - nread, size);
        if (ret < 0) {
            return ret;
        }
        nread += ret;

        return nread;
    }

    int32_t BinaryProtocol::readListEnd(char* request, int32_t request_len) {
        return 0;
    }

    int32_t BinaryProtocol::readMapBegin(char* request, int32_t request_len, 
            DataTypeID& keyType,
            DataTypeID& valueType,
            int32_t& size) {
        int32_t nread = 0;
        int32_t ret;

        int32_t xxx;
        ret = readInt32(request + nread, request_len - nread, xxx);
        if (ret < 0) {
            return ret;
        }
        keyType = (DataTypeID)xxx;
        nread += ret;

        ret = readInt32(request + nread, request_len - nread, xxx);
        if (ret < 0) {
            return ret;
        }
        valueType = (DataTypeID)xxx;
        nread += ret;

        ret = readInt32(request + nread, request_len - nread, size);
        if (ret < 0) {
            return ret;
        }
        nread += ret;

        return nread;
    }

    int32_t BinaryProtocol::readMapEnd(char* request, int32_t request_len) {
        return 0;
    }

    int32_t BinaryProtocol::readStructBegin(char* request, int32_t request_len, std::string& name) {
        int32_t nread = 0;
        int32_t ret;

        ret = readString(request + nread, request_len - nread, name);
        if (ret < 0) {
            return ret;
        }
        nread += ret;

        return nread;
    }

    int32_t BinaryProtocol::readStructEnd(char* request, int32_t request_len) {
        return 0;
    }

    int32_t BinaryProtocol::readFieldBegin(char* request, int32_t request_len, 
            std::string& name,
            DataTypeID& fieldType,
            FieldIDType& fieldID) {
        int32_t nread = 0;
        int32_t ret;

        int32_t xxx;
        ret = readInt32(request + nread, request_len - nread, xxx);
        if (ret < 0) {
            BGCC_NOTICE("bgcc", "BinaryProtocol::readFieldBegin read dataType failed");
            return ret;
        }
        fieldType = (DataTypeID)xxx;
        nread += ret;

        BGCC_TRACE("bgcc", "BinaryProtocol::readFieldBegin dataType %d", xxx);

        if (IDSTOP == fieldType) {
            return nread;
        }

        ret = readString(request + nread, request_len - nread, name);
        if (ret < 0) {
            BGCC_NOTICE("bgcc", "BinaryProtocol::readFieldBegin read name failed");
            return ret;
        }
        nread += ret;

        ret = readInt32(request + nread, request_len - nread, xxx);
        if (ret < 0) {
            BGCC_NOTICE("bgcc", "BinaryProtocol::readFieldBegin read fieldType failed");
            return ret;
            return ret;
        }
        fieldID = (FieldIDType)xxx;
        nread += ret;

        return nread;
    }

    int32_t BinaryProtocol::readFieldEnd(char* request, int32_t request_len) {
        return 0;
    }

    int32_t BinaryProtocol::readMessageBegin(char* request, int32_t request_len, 
            std::string& msgName,
            MsgTypeID& msgType,
            SequenceNOType& seqNO) {
        int32_t nread = 0;
        int32_t ret;

        int16_t t16;
        ret = readInt16(request + nread, request_len - nread, t16);
        if (ret < 0) {
            BGCC_TRACE("bgcc", "BinaryProtocol::readMessageBegin, read msgType. retvalue: %d", ret);
            return ret;
        }
        msgType = (MsgTypeID)t16;
        nread += ret;
        BGCC_TRACE("bgcc", "msg type %d", (int32_t)t16);

        int32_t t32;
        ret = readInt32(request + nread, request_len - nread, t32);
        if (ret < 0) {
            BGCC_TRACE("bgcc", "BinaryProtocol::readMessageBegin, read seqno. retvalue: %d", ret);
            return ret;
        }
        seqNO = (SequenceNOType)t32;
        nread += ret;

        ret = readInt16(request + nread, request_len - nread, t16);
        if (ret < 0) {
            BGCC_TRACE("bgcc", "BinaryProtocol::readMessageBegin, read t int16. retvalue: %d", ret);
            return ret;
        }
        nread += ret;

        BGCC_TRACE("bgcc", "Before readString %d", request_len - nread);
        ret = readString(request + nread, request_len - nread, msgName);
        BGCC_TRACE("bgcc", "End readString %s", msgName.c_str());
        if (ret < 0) {
            BGCC_TRACE("bgcc", "BinaryProtocol::readMessageBegin, read msgName. retvalue: %d", ret);
            return ret;
        }
        nread += ret;
        return nread;
    }

    int32_t BinaryProtocol::readMessageEnd(char* request, int32_t request_len) {
        return 0;
    }
}

