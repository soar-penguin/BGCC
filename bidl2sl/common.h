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
 * @file     common.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月03日 19时41分04秒
 *  
 **/
#ifndef BIDL_COMMON_H
#define BIDL_COMMON_H

#include <list>
#include <string>
#include <stack>

#include "bidl_type.h"
#include "bidl_namespace.h"
#include "bidl_enum.h"
#include "bidl_struct.h"
#include "bidl_boolean.h"
#include "bidl_int8.h"
#include "bidl_int16.h"
#include "bidl_int32.h"
#include "bidl_int64.h"
#include "bidl_float.h"
#include "bidl_double.h"
#include "bidl_string.h"
#include "bidl_binary.h"
#include "bidl_identifier.h"
#include "bidl_sequence.h"
#include "bidl_set.h"
#include "bidl_map.h"
#include "bidl_typedef.h"
#include "bidl_const.h"
#include "bidl_const_integer.h"
#include "bidl_const_literal.h"
#include "bidl_const_decimal.h"
#include "bidl_const_boolean.h"
#include "bidl_class.h"
#include "bidl_void.h"
#include "bidl_function.h"
#include "bidl_function_field.h"
#include "bidl_field_direction.h"
#include "bidl_include.h"
#include "bidl_const_sequence.h"
#include "bidl_const_set.h"

#include "global_parser.h"
#include "parse_result.h"

extern GlobalParser g_parser;

extern ParseResult* g_parseresult;

extern bool g_debug_mode;
extern std::list<std::string> g_input_bidl_files;

extern void yyerror(const char* fmt, ...);
extern void myerror(const char* fmt, ...);
extern int yylex(void);
extern int yyparse(void);

struct YYLTYPE;
void lyyerror(YYLTYPE t, const char* s, ...);

void msg_dbg(const char* fmt, ...);

#define print_message yyerror

extern FILE* yyin;
extern int yycolumn;
extern int yylineno;
extern int yyleng;

extern std::string g_cur_bidl_file_name;

#if _BIDL_DEBUG > 0
extern void output_namespace(BidlType* bt, int level);
extern void output_enum(BidlType* bt, int level);
extern void output_struct(BidlType* bt, int level);
extern void output_struct_field(BidlType* bt, int level);
extern void output_enum_field(BidlType* ef, int level, bool last);
extern void output_element(BidlType* bt, int level);
extern void output_source(BidlNamespace* ns);
extern BidlNamespace* g_cur_bidl_namespace;
#endif
#endif // BIDL_COMMON_H

