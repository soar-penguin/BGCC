/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_BINARY_PROTOCOL_H_
#define _BGCC_BINARY_PROTOCOL_H_

#include "bgcc_stdint.h"
#include "protocol.h"
#include "nb_data_buffer.h"

namespace bgcc {

    /**
     * @class BinaryProtocol 
     * @brief 实现二进制协议序列化与反序列化
     *
     * 提供数据序列化、反序列化的二进制接口。
     */

    class BinaryProtocol : public IProtocol {
    public:
        /**
         * @brief   构造函数
         * @param   transport 底层的传输层智能指针
         */
        BinaryProtocol(TransportSharedPointer transport);
        /**
         * @brief   布尔值序列化
         * @param   value 待序列化的布尔值。
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeBool(const bool value);

        /**
         * @brief   8位整数序列化
         * @param   value 待序列化的8位整数值。
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeByte(const int8_t value);

        /**
         * @brief   16位整数序列化
         * @param   value 待序列化的16位整数值。
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeInt16(const int16_t value);

        /**
         * @brief   32位整数序列化
         * @param   value 待序列化的32位整数值。
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeInt32(const int32_t value);

        /**
         * @brief   64位整数序列化
         * @param   value 待序列化的64位整数值。
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeInt64(const int64_t value);

        /**
         * @brief   浮点数序列化
         * @param   value 待序列化的浮点数。
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeFloat(const float value);

        /**
         * @brief   字符串序列化
         * @param   value 待序列化的字符串。
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeString(const std::string& value);

        /**
         * @brief   二进制数据序列化
         * @param   value 待序列化的二进制数据。
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeBinary(const void* data, const int32_t size);

        /**
         * @brief   消息序列化开始
         * @param   msgName 消息名称
         * @param   msgType 消息类型
         * @param   seqNO   消息序列号
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeMessageBegin(
                const std::string& processor_name,
                const std::string& function_name,
                const MsgTypeID msg_type,
                const SequenceNOType seq_no);

        /**
         * @brief   消息序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeMessageEnd();

        /**
         * @brief   struct序列化开始
         * @param   name set名称
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeStructBegin(const std::string& name);

        /**
         * @brief   struct序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeStructEnd();

        /**
         * @brief   域序列化开始
         * @param   name       域名称
         * @param   fieldType 域类型标识
         * @param   fieldId   ？待定
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeFieldBegin(
                const std::string& name,
                const DataTypeID fieldType,
                const FieldIDType fieldId);

        /**
         * @brief   域序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeFieldEnd();

        /**
         * @brief   结束域序列化, 用于标识一系列域的结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeFieldStop();

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
                const int32_t size);

        /**
         * @brief   map序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeMapEnd();

        /**
         * @brief   list序列化开始
         * @param   elemType 元素类型标识
         * @param   size 元素个数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeListBegin(
                const DataTypeID elemType,
                const int32_t size);

        /**
         * @brief   list序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeListEnd();

        /**
         * @brief   set序列化开始
         * @param   elemType 元素类型标识
         * @param   size 元素个数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeSetBegin(
                const DataTypeID elemType,
                const int32_t size);

        /**
         * @brief   set序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t writeSetEnd();

        /**
         * @brief   布尔值反序列化
         * @param   value 反序列化后得到的布尔值
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readBool(bool& value);

        /**
         * @brief   8位整数反序列化
         * @param   value 反序列化后得到的8位整数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readByte(int8_t& value);

        /**
         * @brief   16位整数反序列化
         * @param   value 反序列化后得到的16位整数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readInt16(int16_t& value);

        /**
         * @brief   32位整数反序列化
         * @param   value 反序列化后得到的32位整数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readInt32(int32_t& value);

        /**
         * @brief   64位整数反序列化
         * @param   value 反序列化后得到的64位整数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readInt64(int64_t& value);

        /**
         * @brief   浮点数反序列化
         * @param   value 反序列化后得到的浮点数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readFloat(float& value);

        /**
         * @brief   字符串反序列化
         * @param   value 反序列化后得到的字符串
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readString(std::string& value);

        /**
         * @brief   二进制数据反序列化
         * @param   value 反序列化后得到的二进制数据
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readBinary(std::string& value);

        /**
         * @brief   set反序列化开始
         * @param   elemType 反序列化后得到的set元素类型标识
         * @param   size 反序列化后得到的set元素个数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readSetBegin(DataTypeID& elemType, int32_t& size);

        /**
         * @brief   set反序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readSetEnd();

        /**
         * @brief   list反序列化开始
         * @param   elemType 反序列化后得到的list元素类型标识
         * @param   size 反序列化后得到的list元素个数
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readListBegin(DataTypeID& elemType, int32_t& size);

        /**
         * @brief   list反序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readListEnd();

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
                int32_t& size);

        /**
         * @brief   map反序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readMapEnd();

        /**
         * @brief   struct反序列化开始
         * @param   name 反序列化后得到的struct名称
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readStructBegin(std::string& name);

        /**
         * @brief   struct反序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readStructEnd();

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
                SequenceNOType& seqNO);

        /**
         * @brief   消息反序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readMessageEnd();

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
                FieldIDType& fieldID);

        /**
         * @brief   域反序列化结束
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t readFieldEnd();

        /**
         * @brief   设置本协议所对应的底层传输层智能指针对象
         * @param   transport 待设置的传输层智能指针对象
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t setTransport(TransportSharedPointer transport);

        /**
         * @brief   获取本协议所对应的底层传输层智能指针对象
         * @return  传输层智能指针对象
         */
        virtual TransportSharedPointer getTransport();

        /**
         * @brief   略过指定类型的数据
         * @param   dataTypeID待略过的数据类型标识
         * @return  成功时返回0。出错时返回错误码。
         */
        virtual int32_t skip(DataTypeID dataTypeID);

        int32_t getDataCopy(void** ppdata, int32_t& size);
        ///////////////////////////////////////////////////////
        /**
         * @brief   布尔值反序列化
         * @param   value 反序列化后得到的布尔值
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readBool(char* request, int32_t request_len, bool& value);

        /**
         * @brief   8位整数反序列化
         * @param   value 反序列化后得到的8位整数
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readByte(char* request, int32_t request_len, int8_t& value);

        /**
         * @brief   16位整数反序列化
         * @param   value 反序列化后得到的16位整数
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readInt16(char* request, int32_t request_len, int16_t& value);

        /**
         * @brief   32位整数反序列化
         * @param   value 反序列化后得到的32位整数
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readInt32(char* request, int32_t request_len, int32_t& value);

        /**
         * @brief   64位整数反序列化
         * @param   value 反序列化后得到的64位整数
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readInt64(char* request, int32_t request_len, int64_t& value);

        /**
         * @brief   浮点数反序列化
         * @param   value 反序列化后得到的浮点数
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readFloat(char* request, int32_t request_len, float& value);

        /**
         * @brief   字符串反序列化
         * @param   value 反序列化后得到的字符串
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readString(char* request, int32_t request_len, std::string& value);

        /**
         * @brief   二进制数据反序列化
         * @param   value 反序列化后得到的二进制数据
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readBinary(char* request, int32_t request_len, std::string& value);

        /**
         * @brief   set反序列化开始
         * @param   elemType 反序列化后得到的set元素类型标识
         * @param   size 反序列化后得到的set元素个数
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readSetBegin(char* request, int32_t request_len, DataTypeID& elemType, int32_t& size);

        /**
         * @brief   set反序列化结束
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readSetEnd(char* request, int32_t request_len);

        /**
         * @brief   list反序列化开始
         * @param   elemType 反序列化后得到的list元素类型标识
         * @param   size 反序列化后得到的list元素个数
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readListBegin(char* request, int32_t request_len, DataTypeID& elemType, int32_t& size);

        /**
         * @brief   list反序列化结束
         * @return  成功时返回0。出错时返回错误码。
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readListEnd(char* request, int32_t request_len);

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
                int32_t& size);

        /**
         * @brief   map反序列化结束
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readMapEnd(char* request, int32_t request_len);

        /**
         * @brief   struct反序列化开始
         * @param   name 反序列化后得到的struct名称
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readStructBegin(char* request, int32_t request_len, std::string& name);

        /**
         * @brief   struct反序列化结束
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readStructEnd(char* request, int32_t request_len);

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
                SequenceNOType& seqNO);

        /**
         * @brief   消息反序列化结束
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readMessageEnd(char* request, int32_t request_len);

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
                FieldIDType& fieldID);

        /**
         * @brief   域反序列化结束
         * @return  返回消耗的request的字节数。错误时返回-1
         */
        virtual int32_t readFieldEnd(char* request, int32_t request_len);

        NBDataBuffer* get_data_buffer() {
            return &_data;
        }
    private:
        /** 底层的传输层对象智能指针 */
        TransportSharedPointer _transport;
        NBDataBuffer _data;

    private:
        /**
         * @brief   过滤布尔值
         * @param   
         * @return  成功时返回0.出错时返回错误码。
         */
        int32_t skipBool();

        /**
         * @brief   过滤8位整数
         * @param   
         * @return  成功时返回0.出错时返回错误码。
         */
        int32_t skipByte();

        /**
         * @brief   过滤16位整数
         * @param   
         * @return  成功时返回0.出错时返回错误码。
         */
        int32_t skipInt16();

        /**
         * @brief   过滤32位整数
         * @param   
         * @return  成功时返回0.出错时返回错误码。
         */
        int32_t skipInt32();

        /**
         * @brief   过滤64位整数
         * @param   
         * @return  成功时返回0.出错时返回错误码。
         */
        int32_t skipInt64();

        /**
         * @brief   过滤浮点数
         * @param   
         * @return  成功时返回0.出错时返回错误码。
         */
        int32_t skipFloat();

        /**
         * @brief   过滤字符串
         * @param   
         * @return  成功时返回0.出错时返回错误码。
         */
        int32_t skipString();

        /**
         * @brief   过滤二进制数据
         * @param   
         * @return  成功时返回0.出错时返回错误码。
         */
        int32_t skipBinary();

        /**
         * @brief   过滤结构体
         * @param   
         * @return  成功时返回0.出错时返回错误码。
         */
        int32_t skipStruct();

        /**
         * @brief   过滤结构体域
         * @param   
         * @return  成功时返回0.出错时返回错误码。
         */
        int32_t skipStructFields();

        /**
         * @brief   过滤结构体单个域
         * @param   stop [out] 通知调用者是否已遇到stop域
         * @return  成功时返回0.出错时返回错误码。
         */
        int32_t skipStructField(bool& stop);

        /**
         * @brief   过滤map
         * @param   
         * @return  成功时返回0.出错时返回错误码。
         */
        int32_t skipMap();

        /**
         * @brief   过滤map元素
         * @param   keyType map元素的键类型标识
         * @param   valueType map元素的值类型标识
         * @param   size map元素个数
         * @return  成功时返回0.出错时返回错误码。
         */
        int32_t skipMapElements(DataTypeID keyType,
                DataTypeID valueType,
                int32_t size);

        /**
         * @brief   过滤set
         * @param   
         * @return  成功时返回0.出错时返回错误码。
         */
        int32_t skipSet();

        /**
         * @brief   过滤set元素
         * @param   elemType set元素类型标识
         * @param   size set元素个数
         * @return  成功时返回0.出错时返回错误码。
         */
        int32_t skipSetElements(DataTypeID elemType,
                int32_t size);

        /**
         * @brief   过滤list
         * @param   
         * @return  成功时返回0.出错时返回错误码。
         */
        int32_t skipList();


        /**
         * @brief   过滤list元素
         * @param   elemType list元素类型标识
         * @param   size list元素个数
         * @return  成功时返回0.出错时返回错误码。
         */
        int32_t skipListElements(DataTypeID elemType,
                int32_t size);
    };
}

#endif
