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
 * @file     bidl_namespace.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月08日 16时24分57秒
 *  
 **/
#ifndef _BIDL2SL_NAMESPACE_H_
#define _BIDL2SL_NAMESPACE_H_

#include "bidl_type.h"

class BidlNamespace : public BidlType {
public:
    BidlNamespace(const std::string name = "root") : BidlType(name) {
        _type_id = NAMESPACE;
    }

    virtual ~BidlNamespace() {
    }

    virtual std::string get_tag() const {
        return "namespace";
    }

    virtual std::string get_tag(const SourceWriter* sw) const {
        return sw->get_namespace_tag();
    }
};
#endif // _BIDL2SL_NAMESPACE_H_

