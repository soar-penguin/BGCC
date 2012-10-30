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
 * @file     bidl_const_set.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月28日 14时57分21秒
 *  
 **/
#ifndef _BIDL2SL_CONST_SET_H_
#define _BIDL2SL_CONST_SET_H_

#include "bidl_type.h"

class BidlConstSet : public BidlType {
public:
    BidlConstSet() {
        _type_id = CONSTSET;
    }

};

#endif // _BIDL2SL_CONST_SET_H_

