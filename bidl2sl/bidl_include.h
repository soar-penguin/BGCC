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
 * @file     bidl_include.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月14日 20时02分28秒
 *  
 **/
#ifndef _BIDL2SL_INCLUDE_H_
#define _BIDL2SL_INCLUDE_H_

#include "bidl_type.h"

class BidlInclude : public BidlType {
    public:
        BidlInclude() : BidlType() {
            _type_id = INCLUDE;
        }
};
#endif // _BIDL2SL_INCLUDE_H_

