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
 * @file     bidl_struct.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月09日 12时29分27秒
 *  
 **/
#ifndef _BIDL2SL_STRUCT_H_
#define _BIDL2SL_STRUCT_H_

#include "bidl_type.h"

class BidlStructField : public BidlType {
public:
    BidlStructField(const std::string& name) : BidlType(name), _field_id(0), _field_type(NULL) {
        _type_id = STRUCTFIELD;
    }

    virtual ~BidlStructField() {
        if (_field_type) {
            delete _field_type;
        }
    }

    int get_field_id() const {
        return _field_id;
    }

    void set_field_id(int field_id) {
        _field_id = field_id;
    }

    BidlType* get_field_type() const {
        return _field_type;
    }

    void set_field_type(BidlType* bt) {
        _field_type = bt;
    }

private:
    int _field_id;
    BidlType* _field_type;
};

class BidlStruct : public BidlType {
public:
    BidlStruct() : BidlType(), _field_id(0) {
        _type_id = STRUCT;
    }

    virtual ~BidlStruct() {
    }

    virtual void append(BidlType* bt) {
        BidlStructField* sf = dynamic_cast<BidlStructField*>(bt);
        assert(sf != NULL);
        sf->set_field_id(++_field_id);
        BidlType::append(bt);
    }

    virtual std::string get_tag() const {
        return "struct";
    }

    virtual std::string get_bgcc_type_name(const std::string& lang = "cpp") const {
        if ("cpp" == lang) {
            return "bgcc::IDSTRUCT";
        }
        else {
            return "DataType.IDSTRUCT";
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
        return "new " + this->get_name() + "()";
    }
private:
    int _field_id;
};
#endif // _BIDL2SL_STRUCT_H_

