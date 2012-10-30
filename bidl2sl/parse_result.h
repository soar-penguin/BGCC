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
 * @file     parse_result.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月16日 19时00分28秒
 *  
 **/
#ifndef _BIDL2SL_PARSE_RESULT_H_
#define _BIDL2SL_PARSE_RESULT_H_

class BidlNamespace;

class ParseResult {
public:
    ParseResult() : bt(NULL) { }
    ~ParseResult() {
        if (bt) {
            delete bt;
        }
    }

    std::vector<std::string> include_bidls;
    BidlNamespace* bt;

};

#endif // _BIDL2SL_PARSE_RESULT_H_

