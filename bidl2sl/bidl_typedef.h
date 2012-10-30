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
 * @file     bidl_typedef.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月09日 17时04分25秒
 *  
 **/
#ifndef _BIDL2SL_TYPEDEF_H_
#define _BIDL2SL_TYPEDEF_H_

#include "bidl_type.h"

class BidlTypedef : public BidlType {
public:
    BidlTypedef() : BidlType(), _sub_type(NULL) {
        _type_id = TYPEDEF;
    }

    virtual ~BidlTypedef() {
        if (_sub_type) {
            delete _sub_type;
        }
    }

    void set_sub_type(const BidlType* bt) {
        _sub_type = bt;
    }

    const BidlType* get_sub_type() const {
        return _sub_type;
    }

    virtual std::string get_tag() const {
        return "typedef";
    }

    virtual const BidlType* get_real_type() const {
        if (_sub_type && _sub_type->is_identifier()) {
            return _sub_type->get_real_type();
        }
        else {
            return _sub_type;
        }
    }

private:
   const BidlType*  _sub_type;
};

#endif // _BIDL2SL_TYPEDEF_H_

