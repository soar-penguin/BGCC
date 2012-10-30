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
 * @file     bidl_function_field.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月10日 10时44分57秒
 *  
 **/
#ifndef _BIDL2SL_FUNCTION_FIELD_H_
#define _BIDL2SL_FUNCTION_FIELD_H_

#include "bidl_type.h"

class BidlFunctionField : public BidlType {
public:
    BidlFunctionField() :
        BidlType(), _is_set_field_direction(false),
        _field_direction(NULL), _field_type(NULL), _is_set_value(false),
        _value(NULL) {
            _type_id = FUNCTIONFIELD;
        }

    virtual ~BidlFunctionField() {
        if (_field_direction) {
            delete _field_direction;
        }

        if (_field_type) {
            delete _field_type;
        }

        if (_value) {
            delete _value;
        }
    }

    void set_field_direction(const BidlType* bt) {
        _field_direction = bt;
        _is_set_field_direction = true;
    }

    void set_field_type(const BidlType* bt) {
        _field_type = bt;
    }

    void set_value(const BidlType* bt) {
        _value = bt;
        _is_set_value = true;
    }

    bool is_set_value() const {
        return _is_set_value;
    }

    bool is_set_field_direction() const {
        return _is_set_field_direction;
    }

    const BidlType* get_field_direction() const {
        return _field_direction;
    }

    const BidlType* get_field_type() const {
        return _field_type;
    } 

private:
    bool _is_set_field_direction;
    const BidlType* _field_direction;
    const BidlType* _field_type;
    bool _is_set_value;
    const BidlType* _value;

};
#endif // _BIDL2SL_FUNCTION_FIELD_H_

