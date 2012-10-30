/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_STRING_UTIL_H_
#define _BGCC2_STRING_UTIL_H_

#include <vector>   // for std::vector
#include <string>   // for std::string
#include <sstream>  // for std::stringstream

#include <string.h>
#include <stdio.h>
#include "bgcc_stdint.h"

namespace bgcc {

    class StringUtil {
    public:
        /**
         * @brief toupper_inplace 将C风格字符串str转换为大写，原字符串被改写
         *
         * @param str 待转换的C风格字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 10时57分10秒
         */
        static void toupper_inplace(char* str);

        /**
         * @brief toupper 将C风格字符串str转换为大写，原字符串保持不变
         *
         * @param str 待转换的C风格字符串
         *
         * @return 字符串str的大写形式
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 10时57分48秒
         */
        static std::string toupper(const char* str);

        /**
         * @brief toupper 将字符串str转换为大写，原字符串保持不变
         *
         * @param str 待转换的字符串
         *
         * @return 字符串str的大写形式
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 11时02分40秒
         */
        static std::string toupper(const std::string& str);

        /**
         * @brief tolower_inplace 将C风格字符串str转换为小写，原字符串被改写
         *
         * @param str 待转换的C风格字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 11时17分45秒
         */
        static void tolower_inplace(char* str);

        /**
         * @brief tolower 将C风格字符串str转换为小写，原字符串保持不变
         *
         * @param str 待转换的C风格字符串
         *
         * @return 字符串str的小写形式
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 11时19分13秒
         */
        static std::string tolower(const char* str);

        /**
         * @brief tolower 将字符串str转换为小写，原字符串保持不变
         *
         * @param str 待转换的字符串
         *
         * @return 字符串str的小写形式
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 11时21分42秒
         */
        static std::string tolower(const std::string& str);

        /**
         * @brief ltrim_inplace 去除字符串左端的空白，原地修改
         *
         * @param str 原字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 12时33分44秒
         */
        static void ltrim_inplace(char* str);

        /**
         * @brief ltrim 去除字符串左端的空白，原字符串保持不变
         *
         * @param str 原字符串
         *
         * @return 去除左端空白的字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 12时34分31秒
         */
        static std::string ltrim(const char* str);

        /**
         * @brief ltrim 去除字符串左端的空白，原字符串保持不变
         *
         * @param str 原字符串
         *
         * @return 去除左端空白的字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 12时35分48秒
         */
        static std::string ltrim(const std::string& str);

        /**
         * @brief rtrim_inplace 去除字符串右端的空白，原地修改
         *
         * @param str 原字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 13时33分39秒
         */
        static void rtrim_inplace(char* str);

        /**
         * @brief rtrim 去除字符串右端的空白
         *
         * @param str 原字符串
         *
         * @return 去除右端空白的字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 13时34分00秒
         */
        static std::string rtrim(const char* str);

        /**
         * @brief rtrim 去除字符串右端的空白
         *
         * @param str 原字符串
         *
         * @return 去除右端空白的字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 13时34分42秒
         */
        static std::string rtrim(const std::string& str);

        /**
         * @brief trim_inplace 去除C风格字符串两端空白，原地修改
         *
         * @param str 原字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 16时53分47秒
         */
        static void trim_inplace(char* str);

        /**
         * @brief trim 去除C风格字符串两端空白
         *
         * @param str 原字符串
         *
         * @return 去除两端空白的字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 16时54分19秒
         */
        static std::string trim(const char* str);

        /**
         * @brief trim 去除字符串两端空白
         *
         * @param str 原字符串
         *
         * @return  去除两端空白的字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 16时54分48秒
         */
        static std::string trim(const std::string& str);

        /**
         * @brief split_string 切分子串
         *
         * @param str 原字符串
         * @param separator 分隔串
         * @param container 子串结果
         * @param filter_empty 是否过滤空子串(length == 0)
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 16时57分03秒
         */
        static void split_string(const std::string& str, const std::string& separator,
                std::vector<std::string>& container, bool filter_empty = false);

        /**
         * @brief replace_string 替换子串
         *
         * @param str 原字符串
         * @param target 目标串
         * @param replacement 替换串
         *
         * @return 替换完成后的字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 18时29分39秒
         */
        static std::string replace_string(const std::string& str, const std::string& target,
                const std::string& replacement);

        /**
         * @brief str2uint32 将数字字符串转化为32位无符号整数
         *
         * @param str 数字字符串
         * @param number 结果整数
         *
         * @return true表示转换成功；否则返回false
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 18时26分35秒
         */
        static bool str2uint32(const char* str, uint32_t& number);

        /**
         * @brief str2int32 将数字字符串转化为32位有符号整数
         *
         * @param str 数字字符串
         * @param number 结果整数
         *
         * @return true表示转换成功；否则返回false
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 19时00分08秒
         */
        static bool str2int32(const char* str, int32_t& number);

        /**
         * @brief str2uint64 将数字字符串转化为64位无符号整数
         *
         * @param str 数字字符串
         * @param number 结果整数
         *
         * @return true表示转换成功；否则返回false
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 19时00分41秒
         */
        static bool str2uint64(const char* str, uint64_t& number);

        /**
         * @brief str2int64 将数字字符串转化为64位有符号整数
         *
         * @param str 数字字符串
         * @param number 结果整数
         *
         * @return true表示转换成功；否则返回false
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 19时01分29秒
         */
        static bool str2int64(const char* str, int64_t& number);

        /**
         * @brief generate_uuid 生成uuid
         *
         * @return 返回“1b4e28ba-2fa1-11d2-883f-b9a76”格式的uuid字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 19时36分37秒
         */
        static std::string generate_uuid();

        /**
         * @brief ipv4_ntoa 整型ip地址转换为字符串形式
         *
         * @param src 整型IP
         * @param dest 接收字符串形式的IP
         *
         * @return 成功转换返回true；否则返回false
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 20时04分57秒
         */
        static bool ipv4_ntoa(uint32_t src, std::string& dest);

        /**
         * @brief ipv4_aton 字符串IP地址转换为整型
         *
         * @param src 字符串形式的IP
         * @param dest 整型IP
         *
         * @return 成功转换返回true；否则返回false
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 20时05分50秒
         */
        static bool ipv4_aton(const char* src, uint32_t& dest);

        /**
         * @brief xstrncpy 功能同strncpy。区别在于xstrncpy返回值为成功复制的字节数
         *
         * @param dest 目的缓冲区
         * @param src 源字符串
         * @param n 目的缓冲区大小
         *
         * @return 成功复制的字节数。错误时返回-1
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月22日 18时38分48秒
         */
        static int32_t xstrncpy(char* dest, const char* src, int32_t n);

        /**
         * @brief rand_string 取得一个随机数的字符串形式
         *
         * @return 随机数字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 14时32分41秒
         */
        static std::string rand_string();
    private:
        /**
         * @brief rtrim 去除字符串右端空白
         *
         * @param str C风格字符串
         * @param len C风格字符串长度
         *
         * @return 去除右端空白的字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 16时23分34秒
         */
        static std::string rtrim(const char* str, int32_t len);

        /**
         * @brief str2integer 将数字字符串转换成为T型的数字
         *
         * @tparam T 数字类型
         * @param str C风格字符串
         * @param number 结果数据
         *
         * @return 成功返回true；否则返回false
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年05月31日 20时03分22秒
         */
        template <typename T>
            static bool str2integer(const char* str, T& number) {
                if (NULL == str) {
                    return false;
                }

                std::stringstream ss;
                T tmp;
                bool ret = false;

                ss << StringUtil::trim(str);
                if (ss.str().length() > 0) {
                    try {
                        ss >> tmp;
                        if (ss.eof() && !ss.fail()) {
                            ret = true;
                            number = tmp;
                        }
                    }
                    catch(std::ios_base::failure& ) {
                    }
                }

                return ret;
            }
    }; // end of class StringUtil

}

#endif // _BGCC2_STRING_UTIL_H_

