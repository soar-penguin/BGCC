/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_CONF_UNIT_H_
#define _BGCC2_CONF_UNIT_H_

#include <string>
#include <map>
#include <vector>
#include "bgcc_stdint.h"

namespace bgcc {

    /**
     * @brief 配置单元
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月11日 14时04分23秒
     */
    class ConfUnit {
    public:
        typedef std::vector<ConfUnit*>::const_iterator const_iterator;
        typedef std::vector<ConfUnit*>::iterator iterator;

        /**
         * @brief 配置单元的类型标识
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时04分12秒
         */
        enum unit_type_t {
            UT_BOOL,
            UT_INT32,
            UT_INT64,
            UT_DOUBLE,
            UT_STRING,
            UT_ARRAY,
            UT_GROUP
        };

        /**
         * @brief ConfUnit 构造函数。通过类型标识构造
         *
         * @param type
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时06分20秒
         */
        explicit ConfUnit(unit_type_t type);

        /**
         * @brief ConfUnit 构造函数。构造bool类型配置单元
         *
         * @param b 初始值
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时06分42秒
         */
        explicit ConfUnit(bool b);

        /**
         * @brief ConfUnit 构造函数。构造int32_t类型配置单元
         *
         * @param i 初始值
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时07分00秒
         */
        explicit ConfUnit(int32_t i);

        /**
         * @brief ConfUnit 构造函数。构造int64_t类型配置单元
         *
         * @param l 初始值
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时07分28秒
         */
        explicit ConfUnit(int64_t l);

        /**
         * @brief ConfUnit 构造函数。构造double类型配置单元
         *
         * @param d 初始值
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时07分47秒
         */
        explicit ConfUnit(double d);

        /**
         * @brief ConfUnit 构造函数。构造string类型配置单元
         *
         * @param str C风格字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 15时37分00秒
         */
        explicit ConfUnit(const char* str);

        /**
         * @brief ConfUnit 构造函数。构造string类型配置单元
         *
         * @param str 初始值
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时08分00秒
         */
        explicit ConfUnit(const std::string& str);

        /**
         * @brief ~ConfUnit 析构函数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时08分39秒
         */
        ~ConfUnit();

        /**
         * @brief get_type 获取配置单元类型
         *
         * @return 配置单元类型
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时10分18秒
         */
        int32_t get_type() const;

        /**
         * @brief is_bool 判断配置单元是否为bool类型
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时10分46秒
         */
        bool is_bool() const;

        /**
         * @brief is_int32 判断配置单元是否为int32类型
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时11分24秒
         */
        bool is_int32() const;

        /**
         * @brief is_int64 判断配置单元是否为int64类型
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时11分47秒
         */
        bool is_int64() const;

        /**
         * @brief is_double 判断配置单元是否为dobule类型
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时12分06秒
         */
        bool is_double() const;

        /**
         * @brief is_string 判断配置单元是否为string类型
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时12分25秒
         */
        bool is_string() const;

        /**
         * @brief is_array 判断配置单元是否为array类型
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时12分41秒
         */
        bool is_array() const;

        /**
         * @brief is_group 判断配置单元是否为group类型
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时12分56秒
         */
        bool is_group() const;

        /**
         * @brief to_bool 取出配置单元中的bool值
         *
         * @return bool值
         * @see
         * @note 若配置单元不是bool类型，将抛出std::exception异常
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时13分24秒
         */
        bool to_bool() const;

        /**
         * @brief to_int32 取出配置单元中的int32值
         *
         * @return int32值
         * @see
         * @note 若配置单元不是int32类型，将抛出std::exception异常
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时15分47秒
         */
        int32_t to_int32() const;

        /**
         * @brief to_int64 取出配置单元中的int64值
         *
         * @return int64值
         * @see
         * @note 若配置单元不是int32或是int64类型，将抛出std::exception异常
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时19分22秒
         */
        int64_t to_int64() const;

        /**
         * @brief to_double 取出配置单元中的double值
         *
         * @return double值
         * @see
         * @note 若配置单元不是double或int32或int64类型，将抛出std::exception异常
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时21分35秒
         */
        double to_double() const;

        /**
         * @brief to_string 取出配置单元中的string值
         *
         * @return string值
         * @see
         * @note 若配置单元不是string类型，将抛出std::exception异常
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时22分38秒
         */
        std::string to_string() const;

        /**
         * @brief set_bool 设置bool类型配置的bool值
         *
         * @param b 值
         * @see
         * @note 若配置单元不是bool类型，将抛出std::exception异常
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 15时07分39秒
         */
        void set_bool(bool b);

        /**
         * @brief set_int32 设置int32类型配置的int32值
         *
         * @param i 值
         * @see
         * @note 若配置单元不是int32类型，将抛出std::exception异常
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 15时08分23秒
         */
        void set_int32(int32_t i);

        /**
         * @brief set_int64 设置int64类型配置的int64值
         *
         * @param l 值
         * @see
         * @note 若配置单元不是int64类型，将抛出std::exception异常
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 15时08分52秒
         */
        void set_int64(int64_t l);

        /**
         * @brief set_double 设置double类型配置单元的double值
         *
         * @param d 值
         * @see
         * @note 若配置单元不是double类型，将抛出std::exception异常
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 15时09分32秒
         */
        void set_double(double d);

        /**
         * @brief set_string 设置string类型配置单元的string值
         *
         * @param str 值
         * @see
         * @note 若配置单元不是string类型，将抛出std::exception异常
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 15时10分07秒
         */
        void set_string(const std::string& str);

        /**
         * @brief begin 取出array类型的首迭代器
         *
         * @return 首迭代器
         * @see
         * @note 若配置单元不是array类型，将抛出std::explicit异常
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时23分53秒
         */
        const_iterator begin() const;

        /**
         * @brief end 取出array类型的尾迭代器
         *
         * @return 尾迭代器
         * @see
         * @note 若配置单元不是array类型，将抛出std::exception异常
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时24分53秒
         */
        const_iterator end() const;

        /**
         * @brief operator[] 取出对应下标上的配置单元指针
         *
         * @param index 下标
         *
         * @return 配置单元指针，若找不到则返回NULL
         * @see
         * @note 若配置单元不是group类型，将抛出std::exception异常
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时26分08秒
         */
        ConfUnit* operator[](const std::string& index);

        /**
         * @brief push_back 将新元素插入array中
         *
         * @param punit 新元素
         *
         * @return 新元素
         * @see
         * @note 若配置单元不是array类型，将抛出std::exception异常
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时27分52秒
         */
        ConfUnit* push_back(ConfUnit* punit);

        /**
         * @brief pop_back 从array中弹出元素
         * @see
         * @note 若配置单元不是array类型，将抛出std::exception异常
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时29分43秒
         */
        void pop_back();

        /**
         * @brief insert 将新元素作为属性key插入group中
         *
         * @param key 属性名
         * @param punit 新元素
         * @see
         * @note 若配置单元不是group类型，将抛出std::exception异常
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时30分55秒
         */
        void insert(const std::string& key, ConfUnit* punit);

        /**
         * @brief erase 从group中删除属性名key对应的配置单元
         *
         * @param key 属性名
         * @see
         * @note 若配置单元不是group类型，将抛出std::exception异常
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时32分07秒
         */
        void erase(const std::string& key);

        /**
         * @brief clear 清空array或group
         * @see
         * @note 若配置单元不是array或group类型，将抛出std::exception异常
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 14时33分02秒
         */
        void clear();

        /**
         * @brief size 返回配置单元元素个数
         *
         * @return 元素个数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月11日 19时54分56秒
         */
        int32_t size() const;

    private:
        unit_type_t _type;
        union {
            bool b;
            int32_t i;
            int64_t l;
            double d;
        }_union;
        std::string _string;
        std::vector<ConfUnit*> _vector;
        std::map<std::string, ConfUnit*> _map;
    }; // end of class ConfUnit
}

#endif // _BGCC2_CONF_UNIT_H_

