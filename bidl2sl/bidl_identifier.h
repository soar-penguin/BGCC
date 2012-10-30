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
 * @file     bidl_identifier.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月09日 15时40分52秒
 *  
 **/
#ifndef _BIDL2SL_IDENTIFIER_H_
#define _BIDL2SL_IDENTIFIER_H_

#include "bidl_type.h"

class BidlIdentifier : public BidlType {
public:
    BidlIdentifier(const std::string& name) : BidlType(name) {
        _type_id = IDENTIFIER;
    }

    virtual ~BidlIdentifier() {
    }

    virtual std::string get_tag() const {
        return get_name();
    }

    virtual std::string get_tag(const SourceWriter* sw) const {
        return sw->get_identifier_tag(get_name());
    }

    virtual const BidlType* get_real_type() const {
        if (_real_type && _real_type->is_identifier()) {
            return _real_type->get_real_type();
        }
        else {
            return _real_type;
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
        return this->get_real_type()->get_return_type_name();
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
        return this->get_real_type()->get_parameter_type_name();
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
        return this->get_real_type()->get_general_type_name();
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
        return this->get_real_type()->get_holder_type_name();
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
        return this->get_real_type()->get_init_clause();
    }
};

#endif // _BIDL2SL_IDENTIFIER_H_

