/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_NB_DATA_H_
#define _BGCC2_NB_DATA_H_

#include <string>
#include "shareable.h"
#include "bgcc_stdint.h"

namespace bgcc {

    /**
     * @brief 网络字节序数据缓冲区
     * @see
     * @note 非线程安全
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年05月30日 20时01分30秒
     */
    class NBDataBuffer : public Shareable {
    public:
        /**
         * @brief NBDataBuffer 构造函数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 20时02分12秒
         */
        NBDataBuffer();

        /**
         * @brief ~NBDataBuffer 析构函数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 20时02分18秒
         */
        ~NBDataBuffer();

        /**
         * @brief append_bool 向缓冲区中追加布尔值。
         * 当b为true时，追加一个字节的1，为false时，追加一个字节的0
         *
         * @param value 待追加的布尔值
         *
         * @return 成功返回0；否则返回错误码
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 20时02分46秒
         */
        int32_t append_bool(bool b);

        /**
         * @brief append_int8 向缓冲区中追加8位整数。
         *
         * @param i8 待追加的8位整数
         *
         * @return 成功返回0；否则返回错误码
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 20时04分19秒
         */
        int32_t append_int8(int8_t i8);

        /**
         * @brief append_int16 向缓冲区中追加16位整数。
         *
         * @param i16 待追加的16位整数
         *
         * @return 成功返回0；否则返回错误码
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 20时05分35秒
         */
        int32_t append_int16(int16_t i16);

        /**
         * @brief append_int32 向缓冲区中追加32位整数。
         *
         * @param i32 待追加的32位整数
         *
         * @return 成功返回0；否则返回错误码
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 20时06分09秒
         */
        int32_t append_int32(int32_t i32);

        /**
         * @brief append_int64 向缓冲区中追加64位整数。
         *
         * @param i64 待追加的64位整数
         *
         * @return 成功返回0；否则返回错误码
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 20时06分46秒
         */
        int32_t append_int64(int64_t i64);

        /**
         * @brief append_float 向缓冲区中追加浮点数
         *
         * @param f 待追加的浮点数
         *
         * @return 成功返回0；否则返回错误码
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 20时07分22秒
         */
        int32_t append_float(float f);

        /**
         * @brief append_string 向缓冲区中追加4个字节的字符串长度及字符串
         *
         * @param str 待追加的字符串
         *
         * @return 成功返回0；否则返回错误码
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 20时08分08秒
         */
        int32_t append_string(const std::string& str);

        /**
         * @brief append_binary 向缓冲区中追加二进制数据长度及二进制数据
         *
         * @param buffer 待追加的二进制数据首地址
         * @param buflen 待追加的二进制数据长度
         *
         * @return 成功返回0；否则返回错误码
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 20时09分13秒
         */
        int32_t append_binary(const void* buffer, int32_t buflen);

        /**
         * @brief append 向缓冲区中追加数据（不追加数据的长度）
         *
         * @param buffer 待追加的二进制数据首地址
         * @param buflen 待追加的二进制数据长度
         *
         * @return 成功返回0；否则返回错误码
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 20时10分11秒
         */
        int32_t append(const void* buffer, int32_t buflen);

        /**
         * @brief get_data 将缓冲区数据复制到临时区域
         *
         * @param ppdata 数据的首地址
         * @param size 用于接收数据的字节数
         *
         * @return 成功返回0；否则返回错误码
         * @see
         * @note 调用者请勿free返回的数据
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 20时11分23秒
         */
        int32_t get_data(void** ppdata, int32_t& size);

        /**
         * @brief get_data_copy 
         *
         * @param ppdata 用于存放数据的首地址，调用者负责释放空间
         * @param size 用于存放临时区域字节数
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 20时15分00秒
         */
        int32_t get_data_copy(void** ppdata, int32_t& size);

        /**
         * @brief clear 清空缓冲区数据
         *
         * @param keep_allocted_mem 已申请内存保留标志，默认不保留
         *
         * @return 成功返回0；否则返回错误码
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 20时17分37秒
         */
        int32_t clear(bool keep_allocted_mem = false);

    protected:
        /**
         * @brief NBDataBuffer 禁用拷贝构造函数
         *
         * @param NBDataBuffer
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 20时22分04秒
         */
        NBDataBuffer(const NBDataBuffer&);

        /**
         * @brief operator= 禁用复制运算符
         *
         * @param NBDataBuffer
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月30日 20时22分18秒
         */
        NBDataBuffer& operator=(const NBDataBuffer&);

    private:
        int32_t _size;
        int32_t _maxsize;
        void* _data;
    }; // end of class NBDataBuffer

}

#endif // _BGCC2_NB_DATA_H_

