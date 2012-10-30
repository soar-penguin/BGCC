/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_PROTOCOL_H_
#define _BGCC_PROTOCOL_H_

#include <string>
#include "shareable.h"
#include "transport.h"
#include "shared_pointer.h"
#include "bgcc_stdint.h"

namespace bgcc {

    /** 
     * @class DataTypeID
     * @brief 类型标识
     */
    enum DataTypeID {
        IDSTOP,
        IDVOID,
        IDBOOL,
        IDBYTE,
        IDINT16,
        IDINT32,
        IDINT64,
        IDFLOAT,
        IDSTR,
        IDBIN,
        IDSTRUCT,
        IDMAP,
        IDSET,
        IDLIST,
        IDFIELD,
        IDSERVICE,
        IDMSG
    };

    /**
     * @class MsgTypeID
     * @brief 消息类型标识
     */
    enum MsgTypeID {
        CALL = 1,
        REPLY,
        EXCEPTION,
        ONEWAY
    };

    typedef int32_t FieldIDType;
    typedef int32_t SequenceNOType;
    /**
     * @class IProtocol
     * @brief 协议类接口
     *
     * 提供数据序列化、数据反序列化接口。
     */
    class IProtocol : public Shareable {
        public:
        typedef SharedPointer<ITransport> TransportSharedPointer;

        /**
         * @brief   布尔值序列化
         * @param   value 待序列化的布尔值。
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeBool(const bool value)  = 0;

        /**
         * @brief   8位整数序列化
         * @param   value 待序列化的8位整数值。
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeByte(const int8_t value) = 0;

        /**
         * @brief   16位整数序列化
         * @param   value 待序列化的16位整数值。
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeInt16(const int16_t value) = 0;

        /**
         * @brief   32位整数序列化
         * @param   value 待序列化的32位整数值。
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeInt32(const int32_t value) = 0;

        /**
         * @brief   64位整数序列化
         * @param   value 待序列化的64位整数值。
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeInt64(const int64_t value) = 0;

        /**
         * @brief   浮点数序列化
         * @param   value 待序列化的浮点数。
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeFloat(const float value) = 0;

        /**
         * @brief   字符串序列化
         * @param   value 待序列化的字符串。
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeString(const std::string& value) = 0;

        /**
         * @brief   二进制数据序列化
         * @param   value 待序列化的二进制数据。
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeBinary(const void* data, const int32_t size) = 0;

        /**
         * @brief   消息序列化开始
         * @param   msgName 消息名称
         * @param   msgType 消息类型
         * @param   seqNo   消息序列号
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeMessageBegin(
            const std::string& processor_name,
            const std::string& function_name,
            const MsgTypeID msg_type,
            const SequenceNOType seq_no) = 0;

        /**
         * @brief   消息序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeMessageEnd() = 0;

        /**
         * @brief   struct序列化开始
         * @param   name set名称
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeStructBegin(const std::string& name) = 0;

        /**
         * @brief   struct序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeStructEnd() = 0;

        /**
         * @brief   域序列化开始
         * @param   name       域名称
         * @param   fieldType 域类型标识
         * @param   fieldId   ？待定
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeFieldBegin(
                const std::string& name,
                const DataTypeID fieldtype,
                const FieldIDType fieldId) = 0;

        /**
         * @brief   域序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeFieldEnd() = 0;

        /**
         * @brief   结束域序列化, 用于标识一系列域的结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeFieldStop() = 0;

        /**
         * @brief   map序列化开始
         * @param   keyType 键类型标识
         * @param   valueType 值类型标识
         * @param   size 元素个数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeMapBegin(
                const DataTypeID keyType,
                const DataTypeID valueType,
                const int32_t size) = 0;

        /**
         * @brief   map序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeMapEnd() = 0;

        /**
         * @brief   list序列化开始
         * @param   elemType 元素类型标识
         * @param   size 元素个数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeListBegin(
                const DataTypeID elemType,
                const int32_t size) = 0;

        /**
         * @brief   list序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeListEnd() = 0;

        /**
         * @brief   set序列化开始
         * @param   elemType 元素类型标识
         * @param   size 元素个数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeSetBegin(
                const DataTypeID elemType,
                const int32_t size) = 0;

        /**
         * @brief   set序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeSetEnd() = 0;

        /**
         * @brief   布尔值反序列化
         * @param   value 反序列化后得到的布尔值
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readBool(bool& value) = 0;

        /**
         * @brief   8位整数反序列化
         * @param   value 反序列化后得到的8位整数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readByte(int8_t& value) = 0;

        /**
         * @brief   16位整数反序列化
         * @param   value 反序列化后得到的16位整数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readInt16(int16_t& value) = 0;

        /**
         * @brief   32位整数反序列化
         * @param   value 反序列化后得到的32位整数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readInt32(int32_t& value) = 0;

        /**
         * @brief   64位整数反序列化
         * @param   value 反序列化后得到的64位整数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readInt64(int64_t& value) = 0;

        /**
         * @brief   浮点数反序列化
         * @param   value 反序列化后得到的浮点数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readFloat(float& value) = 0;

        /**
         * @brief   字符串反序列化
         * @param   value 反序列化后得到的字符串
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readString(std::string& value) = 0;

        /**
         * @brief   二进制数据反序列化
         * @param   value 反序列化后得到的二进制数据
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readBinary(std::string& value) = 0;

        /**
         * @brief   set反序列化开始
         * @param   elemType 反序列化后得到的set元素类型标识
         * @param   size 反序列化后得到的set元素个数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readSetBegin(DataTypeID& elemType, int32_t& size) = 0;

        /**
         * @brief   set反序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readSetEnd() = 0;

        /**
         * @brief   list反序列化开始
         * @param   elemType 反序列化后得到的list元素类型标识
         * @param   size 反序列化后得到的list元素个数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readListBegin(DataTypeID& elemType, int32_t& size) = 0;

        /**
         * @brief   list反序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readListEnd() = 0;

        /**
         * @brief   map反序列化开始
         * @param   keyType 反序列化后得到的map键类型标识
         * @param   valueType 反序列化后得到的map值类型标识
         * @param   size 反序列后得到的元素个数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readMapBegin(
                DataTypeID& keyType,
                DataTypeID& valueType,
                int32_t& size) = 0;

        /**
         * @brief   map反序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readMapEnd() = 0;

        /**
         * @brief   struct反序列化开始
         * @param   name 反序列化后得到的struct名称
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readStructBegin(std::string& name) = 0;

        /**
         * @brief   struct反序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readStructEnd() = 0;

        /**
         * @brief   消息反序列化开始
         * @param   msgName 反序列化后得到的消息名称
         * @param   msgType 反序列化后得到的消息类型
         * @param   seqNO 反序列化得到的消息序列号
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readMessageBegin(
                std::string& msgName,
                MsgTypeID& msgType,
                SequenceNOType& seqNO) = 0;

        /**
         * @brief   消息反序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readMessageEnd() = 0;

        /**
         * @brief   域反序列化开始
         * @param   name 反序列化后得到的域名称
         * @param   field_type 反序列化后得到的域类型标识
         * @param   field_id ？待定
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readFieldBegin(
                std::string& name,
                DataTypeID& fieldType,
                FieldIDType& fieldID) = 0;

        /**
         * @brief   域反序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readFieldEnd() = 0;

        /**
         * @brief   获取本协议所对应的底层传输层智能指针对象
         * @return  传输层智能指针对象
         */
        virtual TransportSharedPointer getTransport() = 0;

        /**
         * @brief   设置本协议所对应的底层传输层智能指针对象
         * @param   transport 待设置的传输层智能指针对象
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t setTransport(TransportSharedPointer transport) = 0;

        /**
         * @brief   略过指定类型的数据
         * @param   dataTypeID待略过的数据类型标识
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t skip(DataTypeID dataTypeID) = 0;

        ///////////////////////////////////////////////////////
        /**
         * @brief   布尔值反序列化
         * @param   value 反序列化后得到的布尔值
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readBool(char* request, int32_t request_len, bool& value) = 0;

        /**
         * @brief   8位整数反序列化
         * @param   value 反序列化后得到的8位整数
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readByte(char* request, int32_t request_len, int8_t& value) = 0;

        /**
         * @brief   16位整数反序列化
         * @param   value 反序列化后得到的16位整数
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readInt16(char* request, int32_t request_len, int16_t& value) = 0;

        /**
         * @brief   32位整数反序列化
         * @param   value 反序列化后得到的32位整数
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readInt32(char* request, int32_t request_len, int32_t& value) = 0;

        /**
         * @brief   64位整数反序列化
         * @param   value 反序列化后得到的64位整数
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readInt64(char* request, int32_t request_len, int64_t& value) = 0;

        /**
         * @brief   浮点数反序列化
         * @param   value 反序列化后得到的浮点数
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readFloat(char* request, int32_t request_len, float& value) = 0;

        /**
         * @brief   字符串反序列化
         * @param   value 反序列化后得到的字符串
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readString(char* request, int32_t request_len, std::string& value) = 0;

        /**
         * @brief   二进制数据反序列化
         * @param   value 反序列化后得到的二进制数据
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readBinary(char* request, int32_t request_len, std::string& value) = 0;

        /**
         * @brief   set反序列化开始
         * @param   elemType 反序列化后得到的set元素类型标识
         * @param   size 反序列化后得到的set元素个数
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readSetBegin(char* request, int32_t request_len, DataTypeID& elemType, int32_t& size) = 0;

        /**
         * @brief   set反序列化结束
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readSetEnd(char* request, int32_t request_len) = 0;

        /**
         * @brief   list反序列化开始
         * @param   elemType 反序列化后得到的list元素类型标识
         * @param   size 反序列化后得到的list元素个数
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readListBegin(char* request, int32_t request_len, DataTypeID& elemType, int32_t& size) = 0;

        /**
         * @brief   list反序列化结束
         * @return  成功时返回0。出错时返回错误码。
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readListEnd(char* request, int32_t request_len) = 0;

        /**
         * @brief   map反序列化开始
         * @param   keyType 反序列化后得到的map键类型标识
         * @param   valueType 反序列化后得到的map值类型标识
         * @param   size 反序列后得到的元素个数
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readMapBegin(char* request, int32_t request_len, 
                DataTypeID& keyType,
                DataTypeID& valueType,
                int32_t& size) = 0;

        /**
         * @brief   map反序列化结束
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readMapEnd(char* request, int32_t request_len) = 0;

        /**
         * @brief   struct反序列化开始
         * @param   name 反序列化后得到的struct名称
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readStructBegin(char* request, int32_t request_len, std::string& name) = 0;

        /**
         * @brief   struct反序列化结束
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readStructEnd(char* request, int32_t request_len) = 0;

        /**
         * @brief   消息反序列化开始
         * @param   msgName 反序列化后得到的消息名称
         * @param   msgType 反序列化后得到的消息类型
         * @param   seqNO 反序列化得到的消息序列号
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readMessageBegin(char* request, int32_t request_len, 
                std::string& msgName,
                MsgTypeID& msgType,
                SequenceNOType& seqNO) = 0;

        /**
         * @brief   消息反序列化结束
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readMessageEnd(char* request, int32_t request_len) = 0;

        /**
         * @brief   域反序列化开始
         * @param   name 反序列化后得到的域名称
         * @param   field_type 反序列化后得到的域类型标识
         * @param   field_id ？待定
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readFieldBegin(char* request, int32_t request_len, 
                std::string& name,
                DataTypeID& fieldType,
                FieldIDType& fieldID) = 0;

        /**
         * @brief   域反序列化结束
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readFieldEnd(char* request, int32_t request_len) = 0;
    };

}

#endif
