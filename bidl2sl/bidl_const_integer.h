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
 * @file     bidl_const_integer.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月09日 18时17分20秒
 *  
 **/
#ifndef _BIDL2SL_CONST_INTEGER_H_
#define _BIDL2SL_CONST_INTEGER_H_

#include <stdint.h>
#include "bidl_type.h"

class BidlConstInteger : public BidlType {
public:
    BidlConstInteger(const std::string& value) : BidlType(), _value(value) {
        _type_id = INTEGER;
    }

    virtual ~BidlConstInteger() {
    }

    virtual std::string get_tag() const {
        return _value;
    }

    std::string get_value() const {
        return _value;
    }

    void set_value(const std::string& value) {
        _value = value;
    }

private:
    std::string _value;
};
#endif // _BIDL2SL_CONST_INTEGER_H_

