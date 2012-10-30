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
 * @file     format_checker.cpp
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月16日 15时48分50秒
 *  
 **/

#include <stdint.h>
#include "format_checker.h"

bool FormatChecker::is_bidl_filename_valid(const std::string& bidl) {
    static const std::string suffix = ".bidl";
    static int32_t suffix_len = suffix.length();

    int32_t bidl_len = bidl.length();
    if (bidl_len <= suffix_len) {
        return false;
    }

    std::string parts(bidl.c_str() + bidl_len - suffix_len);
    return parts == suffix;
}

