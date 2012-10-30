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
 * @file     bidl_set.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月09日 16时17分01秒
 *  
 **/
#ifndef _BIDL2SL_SET_H_
#define _BIDL2SL_SET_H_

#include "bidl_type.h"

class BidlSet : public BidlType {
public:
    BidlSet() : BidlType(), _sub_type(NULL) {
        _type_id = SET;
    }

    virtual ~BidlSet() {
        if (_sub_type) {
            delete _sub_type;
        }
    }

    virtual std::string get_tag() const {
        std::string str;
        str.append("set<");
        if (_sub_type) {
            str.append(_sub_type->get_tag());
        }
        str.append("> ");
        return str;
    }

    virtual std::string get_tag(const SourceWriter* sw) const {
        std::string str;
        str.append(sw->get_set_tag());
        str.append("<");
        if (_sub_type) {
            str.append(_sub_type->get_tag(sw));
        }
        str.append("> ");
        return str;
    }

    void set_sub_type(BidlType* bt) {
        _sub_type = bt;
    }

    const BidlType* get_sub_type() const {
        return _sub_type;
    }

    virtual std::string get_bgcc_type_name(const std::string& lang = "cpp") const {
        if ("cpp" == lang) {
            return "bgcc::IDSET";
        }
        else {
            return "DataType.IDSET";
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
        std::string str;
        str.append("Set<");
        if (_sub_type) {
            str.append(_sub_type->get_real_type()->get_general_type_name());
        }
        str.append(">");
        return str;
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
        return get_return_type_name();
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
        return get_return_type_name();
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
        std::string str;
        str.append("Holder<");
        str.append(get_return_type_name());
        str.append(">");
        return str;
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
        std::string str;
        str.append("new HashSet<");
        if (_sub_type) {
            str.append(_sub_type->get_real_type()->get_general_type_name());
        }
        str.append(">()");
        return str;
    }

private:
    BidlType* _sub_type;
};
#endif // _BIDL2SL_SET_H_

