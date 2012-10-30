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
 * @file     bidl_class.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月09日 20时26分51秒
 *  
 **/
#ifndef _BIDL2SL_CLASS_H_
#define _BIDL2SL_CLASS_H_

#include "bidl_type.h"

class BidlClass : public BidlType {
public:
    BidlClass() : BidlType() {
        _type_id = CLASS;
    }

    virtual ~BidlClass() {
    }

    virtual std::string get_tag() const {
        return "class";
    }

    virtual std::string get_tag(const SourceWriter* sw) const {
        return sw->get_class_tag();
    }
};
#endif // _BIDL2SL_CLASS_H_

