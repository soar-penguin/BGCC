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
 * @file     bidl_function.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月10日 10时35分32秒
 *  
 **/
#ifndef _BIDL2SL_FUNCTION_H_
#define _BIDL2SL_FUNCTION_H_

#include "bidl_type.h"

class BidlFunction : public BidlType {
public:
    BidlFunction() : BidlType(), _return_type(NULL) {
        _type_id = FUNCTION;
    }

    virtual ~BidlFunction() {
        if (_return_type) {
            delete _return_type;
        }
    }

    void set_return_type(const BidlType* bt) {
        _return_type = bt;
    }

    const BidlType* get_return_type() const {
        return _return_type;
    }

    virtual std::string get_tag() const {
        return "function " + get_name();
    }

private:
    const BidlType* _return_type;
};
#endif // _BIDL2SL_FUNCTION_H_

