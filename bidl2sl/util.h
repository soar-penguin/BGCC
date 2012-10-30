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
 * @file     util.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月08日 15时51分51秒
 *  
 **/
#ifndef _BIDL2SL_H_
#define _BIDL2SL_H_

#include <string>
#include <vector>

bool is_c_identifier(const char* id);

std::string replace_string(const std::string& str, const std::string& target,
        const std::string& replacement);

std::string string_toupper(const char* str);

void split_string(const std::string& str, const std::string& separator,
        std::vector<std::string>& container, bool filter_empty = false);

std::string get_java_identifier(const std::string& id);

#endif // _BIDL2SL_H_

