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
 * @file     bidl_parser.cpp
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月16日 16时18分07秒
 *  
 **/

#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include "bidl_parser.h"
#include "global_parser.h"
#include "common.h"
#include "parse_result.h"
#include "source_writer.h"

BidlParser::BidlParser() {
    memset(matrix, 0, sizeof(matrix));
}

BidlParser::~BidlParser() {
    std::map<std::string, ParseResult*>::const_iterator citr;
    for (citr = _filename2parseresult.begin();
            citr != _filename2parseresult.end();
            ++citr) {
        delete citr->second;
    }
}

void BidlParser::check4circle() const {
    int32_t i, j;

    for (i = 0; i < _input_bidls.size(); ++i) {
        if (1 == matrix[i][i]) {
            myerror("bidl can not include self: %s", _input_bidls[i].c_str());
        }
    }
}

std::vector<std::string> BidlParser::get_ordered_bidl() {
    int32_t matrix_size = _input_bidls.size();
    int32_t* count = new int32_t[matrix_size];
    int32_t i, j;

    for (i = 0; i < matrix_size; ++i) {
        count[i] = 0;
        for (j = 0; j < matrix_size; ++j) {
            count[i] += matrix[i][j];
        }
    }

    std::vector<std::string> ordered_input_bidls;
    while (true) {
        for (i = 0; i < matrix_size; ++i) {
            if (count[i] == 0) {
                ordered_input_bidls.push_back(_input_bidls[i]);
                break;
            }
        }

        if (i < matrix_size) {
            count[i] = -1;
            for (j = 0; j < matrix_size; ++j) {
                if (matrix[j][i] > 0) {
                    matrix[j][i] = 0;
                    count[j] -= 1;
                }
            }
        }
        else {
            break;
        }
    }

    //check for directly circle
    if (ordered_input_bidls.size() < matrix_size) {
        output_matrix();
        myerror("circle exist in include bidls");
    }
    delete[] count;
    return ordered_input_bidls;
}

void BidlParser::output_matrix() const {
    int32_t matrix_size = _input_bidls.size();
    int32_t i, j;
    int32_t width = 15;

    fprintf(stderr, "%*s", width, "");
    for (i = 0; i < matrix_size; ++i) {
        fprintf(stderr, "%*s", width, _input_bidls[i].c_str());
    }
    fprintf(stderr, "\n");

    for (i = 0; i < matrix_size; ++i) {
        fprintf(stderr, "%*s", width, _input_bidls[i].c_str());
        for (j = 0; j < matrix_size; ++j) {
            fprintf(stderr, "%*d", width, matrix[i][j]);
        }
        fprintf(stderr, "\n");
    }
}

void BidlParser::parse(const std::string& bidl) {
    do_parse(bidl);

    int32_t matrix_size = _input_bidls.size();
    if (matrix_size > MATRIX_SIZE) {
        myerror("too mary include bidls. max size is %d", MATRIX_SIZE);
    }

    relation2matrix();
    check4circle();

    std::vector<std::string> ordered_input_bidls = get_ordered_bidl();

    std::vector<std::string>::const_iterator itr;
    for (itr = ordered_input_bidls.begin();
            itr != ordered_input_bidls.end();
            ++itr) {
        check_symbol(*itr);
    }
    generate_source_code();
}

void BidlParser::generate_source_code() {
    std::string bidl = _input_bidls[0];
    SourceWriter* sw = SourceWriter::make_source_writer(bidl);
    if (!sw) {
        return;
    }
    BidlType* bt = _filename2parseresult[bidl]->bt;
    sw->write_header(bt);
    sw->write_implement(bt);
    delete sw;
}

void BidlParser::check_symbol(const std::string& bidl) {
    /** virtual global element*/
    BidlNamespace* ns = _filename2parseresult[bidl]->bt;

    std::vector<BidlType*>& children = ns->get_children();
    std::vector<BidlType*>::const_iterator citr;

    for (citr = children.begin(); citr != children.end(); ++citr) {
        do_check_symbol(*citr);
    }
}

std::map<std::string, const BidlType*>::const_iterator
BidlParser::find_bidlptr_by_symbol(std::string symbol) {
    std::map<std::string, const BidlType*>::iterator itr;
    int32_t ndot = std::count(symbol.begin(), symbol.end(), '.');
    while ( ndot >= 1) {
        itr = _symtab.find(symbol);

        if (itr != _symtab.end()) {
            return itr;
        }

        if (ndot > 1) {
            size_t last_dot = symbol.find_last_of(".");
            size_t first_dot = symbol.find_last_of(".", last_dot - 1);

            std::string tmp = symbol.substr(0, first_dot);
            tmp += symbol.substr(last_dot);

            symbol = tmp;
            ndot -= 1;
        }
        else {
            break;
        }
    }

    return _symtab.end();
}

void BidlParser::check_type_and_value(const BidlType* bt) {
    if (!bt) {
        return;
    }

    const BidlConst* c = dynamic_cast<const BidlConst*>(bt);
    if (!c) {
        return;
    }

    const BidlType* field_type = c->get_field_type();
    const BidlType* value = c->get_value();

    if (!field_type || !value) {
        return;
    }

    const BidlType* real_field_type = field_type->get_real_type();
    if (!real_field_type) {
        return;
    }

    if (!do_check_type_and_value(real_field_type, value)) {
        myerror("%s: %d: error: type and value mismatched: %s\n",
                bt->get_filename().c_str(),
                bt->get_line(),
                bt->get_name().c_str());
    }
}

bool BidlParser::do_check_type_and_value(const BidlType* real_field_type, const BidlType* value) {
    if (!real_field_type || !value) {
        return false;
    }

    if ((real_field_type->get_type_id() == BidlType::BOOLEAN && value->get_type_id() == BidlType::CONSTBOOLEAN)
            || (real_field_type->get_type_id() == BidlType::INT8 && value->get_type_id() == BidlType::INTEGER  )
            || (real_field_type->get_type_id() == BidlType::INT16 && value->get_type_id() == BidlType::INTEGER )
            || (real_field_type->get_type_id() == BidlType::INT32 && value->get_type_id() == BidlType::INTEGER )
            || (real_field_type->get_type_id() == BidlType::INT64 && value->get_type_id() == BidlType::INTEGER )
            || (real_field_type->get_type_id() == BidlType::FLOAT && value->get_type_id() == BidlType::DECIMAL )
            || (real_field_type->get_type_id() == BidlType::STRING && value->get_type_id() == BidlType::LITERAL)
            || (real_field_type->get_type_id() == BidlType::BINARY && value->get_type_id() == BidlType::LITERAL)) {

        return true;
    }
    else if (real_field_type->get_type_id() == BidlType::SEQUENCE) {
        if (BidlType::CONSTSEQUENCE != value->get_type_id()) {
            return false;
        }

        const BidlType* sequence_sub_type = dynamic_cast<const BidlSequence*>(real_field_type)->get_sub_type();
        if (!sequence_sub_type) {
            return false;
        }

        const BidlType* sequence_sub_real_type = sequence_sub_type->get_real_type();
        if (!sequence_sub_real_type) {
            return false;
        }

        const std::vector<BidlType*>& children = value->get_children();
        std::vector<BidlType*>::const_iterator itr;
        for (itr = children.begin(); itr != children.end(); ++itr) {
            bool ret = do_check_type_and_value(sequence_sub_real_type, *itr);
            if (ret == false) {
                return false;
            }
        }

        return true;
    }
    else if (real_field_type->get_type_id() == BidlType::SET) {
        if (BidlType::CONSTSET != value->get_type_id()) {
            return false;
        }

        const BidlType* set_sub_type = dynamic_cast<const BidlSet*>(real_field_type)->get_sub_type();
        if (!set_sub_type) {
            return false;
        }

        const BidlType* set_sub_real_type = set_sub_type->get_real_type();
        if (!set_sub_real_type) {
            return false;
        }

        const std::vector<BidlType*>& children = value->get_children();
        std::vector<BidlType*>::const_iterator itr;
        for (itr = children.begin(); itr != children.end(); ++itr) {
            bool ret = do_check_type_and_value(set_sub_real_type, *itr);
            if (ret == false) {
                return false;
            }
        }
        return true;
    }
    else if (real_field_type->get_type_id() == BidlType::MAP) {
        if (BidlType::MAP != value->get_type_id()) {
            return false;
        }

        const BidlType* key_type = dynamic_cast<const BidlMap*>(real_field_type)->get_key_type();
        if (!key_type) {
            return false;
        }
        key_type = key_type->get_real_type();
        if (!key_type) {
            return false;
        }

        const BidlType* value_type = dynamic_cast<const BidlMap*>(real_field_type)->get_value_type();
        if (!value_type) {
            return false;
        }
        value_type = value_type->get_real_type();
        if (!value_type) {
            return false;
        }

        const std::vector<BidlType*>& children = value->get_children();
        std::vector<BidlType*>::const_iterator itr;
        for (itr = children.begin(); itr != children.end(); ++itr) {
            bool ret = do_check_type_and_value(key_type, dynamic_cast<BidlMap*>(*itr)->get_key_type());
            if (ret == false) {
                return false;
            }

            ret = do_check_type_and_value(value_type, dynamic_cast<BidlMap*>(*itr)->get_value_type());
            if (ret == false) {
                return false;
            }
        }

        return true;
    }
    return false;
}


void BidlParser::do_check_symbol(const BidlType* bt) {
    if (!bt) {
        myerror("why NULL?");
    }

    std::map<std::string, const BidlType*>::const_iterator itr;

    switch(bt->get_type_id()) {
    case BidlType::CONST:
        /*no break;*/
    case BidlType::CLASS:
        /*no break;*/
    case BidlType::ENUM:
        /*no break;*/
    case BidlType::ENUMFIELD:
        /*no break;*/
    case BidlType::STRUCT:
        /*no break;*/
    case BidlType::STRUCTFIELD:
        /*no break;*/
    case BidlType::TYPEDEF:
        /*no break;*/
    case BidlType::FUNCTION:
        /*no break;*/
    case BidlType::FUNCTIONFIELD:
        itr = _symtab.find(bt->_symtab_name);
        if (itr != _symtab.end()) {
            myerror("%s: %d: error: duplicate definition: %s\n"
                    "first defined at %s: %d\n",
                    bt->get_filename().c_str(),
                    bt->get_line(),
                    bt->get_name().c_str(),
                    itr->second->get_filename().c_str(),
                    itr->second->get_line());
        }
        _symtab.insert(std::make_pair(bt->_symtab_name, bt));
        break;
    case BidlType::IDENTIFIER:
        itr = find_bidlptr_by_symbol(bt->_symtab_name);
        if (itr == _symtab.end()) {
            myerror("%s : %d: error: type %s undefined",
                    bt->get_filename().c_str(),
                    bt->get_line(),
                    bt->get_name().c_str());
        }
        else if ( itr->second->get_type_id() != BidlType::TYPEDEF
                && itr->second->get_type_id() != BidlType::ENUM
                && itr->second->get_type_id() != BidlType::STRUCT
                && itr->second->get_type_id() != BidlType::CLASS
                ){
            myerror("%s : %d: error: %s defined at %s : %d, but it is not a type",
                    bt->get_filename().c_str(),
                    bt->get_line(),
                    bt->get_name().c_str(),
                    itr->second->get_filename().c_str(),
                    itr->second->get_line()
                   );
        }
        const_cast<BidlType*>(bt)->set_real_type(itr->second->get_real_type());
        break;
    }


    //以下几行为检测被引用的类型是否存在
    const BidlType* tmp_type = NULL;
    switch(bt->get_type_id()) {
    case BidlType::CONST:
        tmp_type = dynamic_cast<const BidlConst*>(bt)->get_field_type();
        break;
    case BidlType::TYPEDEF:
        tmp_type = dynamic_cast<const BidlTypedef*>(bt)->get_sub_type();
        break;
    case BidlType::STRUCTFIELD:
        tmp_type = dynamic_cast<const BidlStructField*>(bt)->get_field_type();
        break;
    case BidlType::FUNCTION:
        tmp_type = dynamic_cast<const BidlFunction*>(bt)->get_return_type();
        break;
    case BidlType::FUNCTIONFIELD:
        tmp_type = dynamic_cast<const BidlFunctionField*>(bt)->get_field_type();
        break;
    case BidlType::SEQUENCE:
        do_check_symbol(dynamic_cast<const BidlSequence*>(bt)->get_sub_type());
        break;
    case BidlType::SET:
        do_check_symbol(dynamic_cast<const BidlSet*>(bt)->get_sub_type());
        break;
    case BidlType::MAP:
        do_check_symbol(dynamic_cast<const BidlMap*>(bt)->get_key_type());
        do_check_symbol(dynamic_cast<const BidlMap*>(bt)->get_value_type());
        break;
    default:
            break;
    }

    if (bt->get_type_id() == BidlType::CONST
            || bt->get_type_id() == BidlType::TYPEDEF
            || bt->get_type_id() == BidlType::STRUCTFIELD
            || bt->get_type_id() == BidlType::FUNCTION
            || bt->get_type_id() == BidlType::FUNCTIONFIELD) {
        if (BidlType::IDENTIFIER == tmp_type->get_type_id()) {
            do_check_symbol(tmp_type);
        }
        else if (BidlType::SEQUENCE == tmp_type->get_type_id()) {
            do_check_symbol(dynamic_cast<const BidlSequence*>(tmp_type)->get_sub_type());
        }
        else if (BidlType::SET == tmp_type->get_type_id()) {
            do_check_symbol(dynamic_cast<const BidlSet*>(tmp_type)->get_sub_type());
        }
        else if (BidlType::MAP == tmp_type->get_type_id()) {
            do_check_symbol(dynamic_cast<const BidlMap*>(tmp_type)->get_key_type());
            do_check_symbol(dynamic_cast<const BidlMap*>(tmp_type)->get_value_type());
        }
    }

    if (bt->get_type_id() == BidlType::CONST) {
        check_type_and_value(bt);
    }

    const std::vector<BidlType*>& children = bt->get_children();
    std::vector<BidlType*>::const_iterator citr;
    for (citr = children.begin(); citr != children.end(); ++citr) {
        do_check_symbol(*citr);
    }
}

void BidlParser::relation2matrix() {
    std::map<std::string, ParseResult*>::const_iterator citr;
    for (citr = _filename2parseresult.begin();
            citr != _filename2parseresult.end();
            ++citr) {
        int32_t idx1 = get_index(citr->first);
        std::vector<std::string>& include_bidls = citr->second->include_bidls;
        std::vector<std::string>::const_iterator vcitr;
        for (vcitr = include_bidls.begin(); vcitr != include_bidls.end(); ++vcitr) {
            int32_t idx2 = get_index(*vcitr);
            matrix[idx1][idx2] = 1;
        }
    }
}


int32_t BidlParser::get_index(const std::string& bidl) const {
    return std::find(_input_bidls.begin(), _input_bidls.end(), bidl) - _input_bidls.begin();
}

void BidlParser::do_parse(const std::string& bidl) {
    std::string dir;
    if (!g_parser.is_bidl_exist_in_bidl_include_dirs(bidl, dir)) {
        myerror("file %s is not exist", bidl.c_str());
    }
    std::string fullname = dir + bidl;
    if (is_bidl_parsed(bidl)) {
        return;
    }

    _input_bidls.push_back(bidl);
    g_cur_bidl_file_name = bidl;

    FILE* fp = fopen(fullname.c_str(), "r");
    if (!fp) {
        myerror("open %s failed: %s", fullname.c_str(), strerror(errno));
    }

    ParseResult* pr;
    pr = parse_fp(fp);
    fclose(fp);

    if (!pr || !pr->bt) {
        myerror("parse %s failed", fullname.c_str());
    }
    _filename2parseresult.insert(std::make_pair(bidl, pr));

    std::vector<std::string>::const_iterator citr;
    for (citr = pr->include_bidls.begin();
            citr != pr->include_bidls.end();
            ++citr) {
        do_parse(*citr);
    }

    g_parseresult = NULL;
}

bool BidlParser::is_bidl_parsed(const std::string& bidl) {
    return _input_bidls.end() != std::find(_input_bidls.begin(), _input_bidls.end(), bidl);
}

ParseResult* BidlParser::parse_fp(FILE* fp) {
    if (!fp) {
        return NULL;
    }

    ParseResult* parse_result = new ParseResult;
    if (!parse_result) {
        return NULL;
    }

    parse_result->bt = new BidlNamespace;
    if (!parse_result->bt) {
        delete parse_result;
        parse_result = NULL;
        g_cur_bidl_namespace = NULL;
        return NULL;
    }

    g_parseresult = parse_result;
    yyin = fp;
    yylineno = 1;

    if (0 != yyparse()) {
        myerror("failed to parse bidl file %s", g_cur_bidl_file_name.c_str());
    }

    set_symtab_name(parse_result->bt, "");

    return parse_result;
}

void BidlParser::set_symtab_name(BidlType* bt, const std::string& prefix) {
    if (!bt) {
        return;
    }

    if (prefix.empty()) {
        bt->_symtab_name = "global";
    }
    else {
        if (bt->get_name().find('.') != std::string::npos) {
            bt->_symtab_name = "global." + bt->get_name();
        }
        else {
            bt->_symtab_name = prefix + "." + bt->get_name();
        }
    }

    switch(bt->get_type_id()) {
    case BidlType::SEQUENCE:
        set_symtab_name(
                const_cast<BidlType*>(dynamic_cast<BidlSequence*>(bt)->get_sub_type())
                , prefix);
        break;
    case BidlType::SET:
        set_symtab_name(
                const_cast<BidlType*>(dynamic_cast<BidlSet*>(bt)->get_sub_type())
                , prefix);
        break;
    case BidlType::MAP:
        set_symtab_name(
                const_cast<BidlType*>(dynamic_cast<BidlMap*>(bt)->get_key_type())
                , prefix);
        set_symtab_name(
                const_cast<BidlType*>(dynamic_cast<BidlMap*>(bt)->get_value_type())
                , prefix);
        break;
        break;
    case BidlType::CONST:
        set_symtab_name(
                const_cast<BidlType*>(dynamic_cast<BidlConst*>(bt)->get_field_type())
                , prefix);
        break;
    case BidlType::TYPEDEF:
        set_symtab_name(
                const_cast<BidlType*>(dynamic_cast<BidlTypedef*>(bt)->get_sub_type())
                , prefix);
        break;
    case BidlType::STRUCTFIELD:
        {
            std::string new_prefix(prefix, 0, prefix.find_last_of('.'));
            set_symtab_name(
                    const_cast<BidlType*>(dynamic_cast<BidlStructField*>(bt)->get_field_type())
                    , new_prefix);
        }
        break;
    case BidlType::FUNCTION:
        {
            std::string new_prefix(prefix, 0, prefix.find_last_of('.'));
            set_symtab_name(
                    const_cast<BidlType*>(dynamic_cast<BidlFunction*>(bt)->get_return_type())
                    , new_prefix);
        }
        break;
    case BidlType::FUNCTIONFIELD:
        {
            std::string tmp(prefix, 0, prefix.find_last_of('.'));
            std::string new_prefix(tmp, 0, tmp.find_last_of('.'));
            set_symtab_name(
                    const_cast<BidlType*>(dynamic_cast<BidlFunctionField*>(bt)->get_field_type())
                    , new_prefix);
        }
        break;
    default:
        break;
    }

    std::vector<BidlType*>& children = bt->get_children();
    std::vector<BidlType*>::iterator itr;
    for (itr = children.begin(); itr != children.end(); ++itr) {
        set_symtab_name(*itr, bt->_symtab_name);
    }
}
