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
 * @file     bidl_const_boolean.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月09日 19时14分46秒
 *  
 **/
#ifndef _BIDL2SL_CONST_BOOLEAN_H_
#define _BIDL2SL_CONST_BOOLEAN_H_

#include "bidl_type.h"

class BidlConstBoolean : public BidlType {
public:
    BidlConstBoolean(bool value) : BidlType(), _value(value) {
        _type_id = CONSTBOOLEAN;
    }

    virtual ~BidlConstBoolean() {
    }

    bool get_value() const {
        return _value;
    }

    virtual std::string get_tag() const {
        return _value ? "true" : "false";
    }

private:
    bool _value;
};
#endif // _BIDL2SL_CONST_BOOLEAN_H_

