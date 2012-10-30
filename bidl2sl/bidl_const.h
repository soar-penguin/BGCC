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
 * @file     bidl_const.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月09日 17时26分58秒
 *  
 **/
#ifndef _BIDL2SL_CONST_H_
#define _BIDL2SL_CONST_H_

#include "bidl_type.h"

class BidlConst : public BidlType {
public:
    BidlConst() : BidlType(), _field_type(NULL), _value(NULL) {
        _type_id = CONST;
    }

    virtual ~BidlConst() {
        if (_field_type) {
            delete _field_type;
        }

        if (_value) {
            delete _value;
        }
    }

    void set_field_type(BidlType* bt) {
        _field_type = bt;
    }

    void set_value(BidlType* bt) {
        _value = bt;
    }

    const BidlType* get_field_type() const {
        return _field_type;
    }

    const BidlType* get_value() const {
        return _value;
    }

    virtual std::string get_tag() const {
        return "const";
    }
    
    virtual std::string get_tag(const SourceWriter* sw) const {
        return sw->get_const_tag();
    }

private:
    BidlType* _field_type;
    BidlType* _value;
};
#endif // _BIDL2SL_CONST_H_

