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
 * @file     global_parser.cpp
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月16日 14时43分02秒
 *  
 **/

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "global_parser.h"
#include "common.h"
#include "format_checker.h"
#include "bidl_parser.h"

GlobalParser::GlobalParser() :
    _debuged(false), _lang_setted(false), _language("cpp"), _outdir_setted(false), _outdir("./output-" + _language + "/") {
        _bidl_incldue_dirs.push_back("./");
}

void GlobalParser::add_bidl(const std::string& bidl) {
    _bidls.push_back(bidl);
}

void GlobalParser::parse() {
    if (_bidls.empty()) {
        myerror("WARN: No input bidl file.");
    }

    std::vector<std::string>::const_iterator citr;
    for (citr = _bidls.begin(); citr != _bidls.end(); ++citr) {
        if (!FormatChecker::is_bidl_filename_valid(*citr)) {
            std::cerr << "WARN: " << *citr << " is an invalid bidl filename. Please check the Bgcc Manual." << std::endl;
            continue;
        }

        if (!is_file_exist(*citr)) {
            std::cerr << "WARN: " << *citr << " is not exist." << std::endl;
            continue;
        }

        BidlParser parser;
        parser.parse(*citr);
        std::cerr << "parse " << *citr << " done." << std::endl;
    }
}

void GlobalParser::add_bidl_include_dir(const std::string& dir) {
    if (dir[dir.length()-1] != '/') {
        _bidl_incldue_dirs.push_back(dir + "/");
    }
    else {
        _bidl_incldue_dirs.push_back(dir);
    }
}

bool GlobalParser::is_bidl_exist_in_bidl_include_dirs(const std::string& bidl, std::string& dir) {
    std::vector<std::string>::const_iterator citr;
    for (citr = _bidl_incldue_dirs.begin(); citr != _bidl_incldue_dirs.end(); ++citr) {
        if (is_file_exist(*citr + bidl)) {
            dir = *citr;
            return true;
        }
    }
    return false;
}

bool GlobalParser::is_file_exist(const std::string& full_name) {
    return access(full_name.c_str(), F_OK) == 0;
}

bool GlobalParser::is_dir_exist(const std::string& dir) {
    struct stat s;
    int32_t ret = stat(dir.c_str(), &s);
    if (-1 == ret && ENOENT == errno) {
        return false;
    }
    else if (-1 == ret) {
        myerror("error: %s", strerror(errno));
        return false;
    }

    if (!S_ISDIR(s.st_mode)) {
        myerror("%s exist, but is not a directory", dir.c_str());
        return false;
    }
    return true;
}
