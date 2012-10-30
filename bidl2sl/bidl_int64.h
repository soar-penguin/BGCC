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
 * @file     bidl_int64.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月09日 14时31分28秒
 *  
 **/
#ifndef _BIDL2SL_INT64_H_
#define _BIDL2SL_INT64_H_

#include "bidl_type.h"

class BidlInt64 : public BidlType {
public:
    BidlInt64() : BidlType() {
        _type_id = INT64;
    }

    virtual ~BidlInt64() {
    }

    virtual std::string get_tag() const {
        return "int64";
    }

    virtual std::string get_tag(const SourceWriter* sw) const {
        return sw->get_int64_tag();
    }

    virtual std::string get_bgcc_type_name(const std::string& lang = "cpp") const {
        if ("cpp" == lang) {
            return "bgcc::IDINT64";
        }
        else {
            return "DataType.IDINT64";
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
        return "long";
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
        return "long";
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
        return "Long";
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
        return "LongHolder";
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
        return "0";
    }
};

#endif // _BIDL2SL_INT64_H_

