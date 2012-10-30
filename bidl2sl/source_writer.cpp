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
 * @file     source_writer.cpp
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月17日 14时23分36秒
 *  
 **/

#include "source_writer.h"
#include "cpp_source_writer.h"
#include "java_source_writer.h"
#include "common.h"

SourceWriter* SourceWriter::make_source_writer(const std::string& bidl) {
    std::string lang = g_parser.get_language();
    if ("cpp" == lang) {
        return new CppSourceWriter(bidl);
    }
    else if ("java" == lang) {
        return new JavaSourceWriter(bidl);
    }
    else {
        myerror("unknown language %s", lang.c_str());
        return NULL;
    }
}

std::string SourceWriter::get_indent(int level) {
    std::string level_str;
    for (int i = 0; i < level; ++i) {
        level_str.append(GlobalParser::get_desent());
    }
    return level_str;
}
