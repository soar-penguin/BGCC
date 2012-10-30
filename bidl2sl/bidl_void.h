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
 * @file     bidl_void.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月10日 10时21分37秒
 *  
 **/
#ifndef _BIDL2SL_VOID_H_
#define _BIDL2SL_VOID_H_

#include "bidl_type.h"

class BidlVoid : public BidlType {
public:
    BidlVoid() : BidlType() {
        _type_id = VOID;
    }

    virtual ~BidlVoid() {
    }

    virtual std::string get_tag() const {
        return "void";
    }

    virtual std::string get_tag(const SourceWriter* sw) const {
        return sw->get_void_tag();
    }

    virtual std::string get_return_type_name() const {
        return "void";
    }

};
#endif // _BIDL2SL_VOID_H_

