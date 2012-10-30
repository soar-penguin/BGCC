/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

/**
 * @file     bidl_enum.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月08日 17时05分28秒
 *  
 **/
#ifndef _BIDL2SL_ENUM_H_
#define _BIDL2SL_ENUM_H_

#include <assert.h>
#include "bidl_type.h"

class BidlEnumField : public BidlType {
public:
    BidlEnumField(const std::string& name) : BidlType(name), _value(0), _has_value(false) {
        _type_id = ENUMFIELD;
    }

    BidlEnumField(const std::string& name, int value) : BidlType(name), _value(value), _has_value(true) {
        _type_id = ENUMFIELD;
    }

    void set_value(int value) {
        _value = value;
    }

    int get_value() const {
        return _value;
    }

    bool has_value() const {
        return _has_value;
    }
private:
    int _value;
    bool _has_value;
};

class BidlEnum : public BidlType {
public:
    BidlEnum() : BidlType(), _value(-1) {
        _type_id = ENUM;
    }

    virtual ~BidlEnum() {
    }

    virtual void append(BidlType* bt) {
        BidlEnumField* ef = dynamic_cast<BidlEnumField*>(bt);
        assert(ef != NULL);
        if (ef->has_value()) {
            _value = ef->get_value();
        }
        else {
            ef->set_value(++_value);
        }
        BidlType::append(bt);
    }

    virtual std::string get_tag() const {
        return "enum";
    }

    virtual std::string get_bgcc_type_name(const std::string& lang = "cpp") const {
        if ("cpp" == lang) {
            return "bgcc::IDINT32";
        }
        else {
            return "DataType.IDINT32";
        }
    }

    /**
     * @brief get_return_type_name 
     * 返回在生成Java代码时，本类型作为返回值类型的字符串表示
     *
     * @return 类型字符串
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年09月08日 14时32分23秒
     */
    virtual std::string get_return_type_name() const {
        size_t first_dot = _symtab_name.find_first_of('.');
        return _symtab_name.substr(first_dot + 1);
    }

    /**
     * @brief get_parameter_type_name 
     * 返回在生成Java代码时，本类型作为参数类型的字符串表示
     *
     * @return 类型字符串
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年09月08日 14时37分33秒
     */
    virtual std::string get_parameter_type_name() const {
        return this->get_return_type_name();
    }

    /**
     * @brief get_general_type_name 
     * 返回在生成Java代码时，本类型作为泛型类型的字符串表示
     *
     * @return 类型字符串
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年09月08日 14时38分19秒
     */
    virtual std::string get_general_type_name() const {
        return this->get_return_type_name();
    }

    /**
     * @brief get_holder_type_name 
     * 返回在生成Java代码时，本类型作为传出类型的字符串表示
     *
     * @return 类型字符串
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年09月08日 14时45分41秒
     */
    virtual std::string get_holder_type_name() const {
        return this->get_return_type_name() + "Holder";
    }

    /**
     * @brief get_init_clause 
     * 返回在生成Java代码时，本类型的初始化语句
     *
     * @return 类型初始化语句
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年09月08日 14时41分00秒
     */
    virtual std::string get_init_clause() const {
        return this->get_name() + ".findByValue(0)";
    }

private:
    int _value;
};
#endif // _BIDL2SL_ENUM_H_

