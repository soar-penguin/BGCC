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
 * @file     BidlParser.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月16日 16时15分49秒
 *  
 **/
#ifndef _BIDL2SL_BIDL_PARSER_H_
#define _BIDL2SL_BIDL_PARSER_H_

#include <string>
#include <vector>
#include <map>
#include <stdio.h>

#include "common.h"

#define MATRIX_SIZE 100

class BidlParser {
public:
    BidlParser();
    ~BidlParser();
    void parse(const std::string& bidl);
    bool is_bidl_parsed(const std::string& bidl);

    static ParseResult* parse_fp(FILE* fp);
private:
    void do_parse(const std::string& bidl);
    int32_t get_index(const std::string& bidl) const;
    void relation2matrix();
    void check4circle() const;
    void check_symbol(const std::string& bidl);
    void do_check_symbol(const BidlType* bt);
    void output_matrix() const;
    std::vector<std::string> get_ordered_bidl();
    void generate_source_code();

    static void set_symtab_name(BidlType* bt, const std::string& prefix = "");
    int32_t matrix[MATRIX_SIZE][MATRIX_SIZE];
    std::map<std::string, const BidlType*>::const_iterator
        find_bidlptr_by_symbol(std::string symbol);
    void check_type_and_value(const BidlType* bt);
    bool do_check_type_and_value(const BidlType* real_field_type, const BidlType* value);
private:
    std::vector<std::string> _input_bidls;
    std::map<std::string, ParseResult*> _filename2parseresult;
    std::map<std::string, const BidlType*> _symtab;
};
#endif // _BIDL2SL_BIDL_PARSER_H_

