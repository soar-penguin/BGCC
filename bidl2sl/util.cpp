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
 * @file     util.cpp
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月08日 15时52分35秒
 *  
 **/

#include <ctype.h>
#include <algorithm>
#include "util.h"

bool is_c_identifier(const char* id) {
    if (!id) {
        return false;
    }

    if (!isalpha(*id) && '_' != *id) {
        return false;
    }

    while (*++id) {
        if (!isalnum(*id) && '_' != *id) {
            return false;
        }
    }
    return true;
}

std::string replace_string(const std::string& str, const std::string& target,
        const std::string& replacement) {
    std::string ret;
    std::string::size_type target_len = target.length();

    if (0 == target_len) {
        return str;
    }


    std::string::size_type pos_begin = 0;
    std::string::size_type pos_target = str.find(target, pos_begin);
    const char *str_head = str.data();

    while (pos_target != std::string::npos) {
        ret.append(str_head + pos_begin, pos_target - pos_begin);
        ret += replacement;
        pos_begin = pos_target + target_len;
        pos_target = str.find(target, pos_begin);
    }   

    if (pos_begin < str.length()) {
        ret.append(str.begin() + pos_begin, str.end());
    }   
    return ret;
}

std::string string_toupper(const char* str) {
    if (NULL == str) {
        return ""; 
    }   

    std::string tmp(str);
    std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
    return tmp;
}

void split_string(const std::string& str, const std::string& separator,
        std::vector<std::string>& container, bool filter_empty) {
    std::string::size_type pos;
    std::string::size_type lastPos = 0;

    container.clear();

    while (true) {
        pos = str.find_first_of(separator, lastPos);
        if (pos == std::string::npos) {
            pos = str.length();

            if(pos != lastPos || false == filter_empty) {
                container.push_back(std::string(str.data() + lastPos, pos - lastPos));
            }

            break;
        }
        else {
            if(pos != lastPos || false == filter_empty) {
                container.push_back(std::string(str.data() + lastPos, pos - lastPos));
            }
        }

        lastPos = pos + 1;
    }
}

std::string get_java_identifier(const std::string& id) {
    std::string str = id;
    if (str.size() > 0) {
        str[0] = ::toupper(str[0]);
    }
    return str;
}
