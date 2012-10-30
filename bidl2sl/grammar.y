%{
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "common.h"
#include "util.h"

extern char* yytext;

%}

%locations
%expect 1

%union {
	char*			szstr;
	bool			boolval;
	BidlType*		bidltype;
	std::vector<BidlType*>* bidltype_vector;
}

%type	<bidltype>		definition_clause
%type	<bidltype>		const_clause
%type	<bidltype>		const_value
%type	<bidltype>		const_type
%type	<bidltype>		basic_type
%type	<bidltype>		include_clause
%type	<bidltype>		data_type
%type	<bidltype>		typedef_clause
%type	<bidltype>		map_type
%type	<bidltype>		set_type
%type	<bidltype>		sequence_type
%type	<bidltype>		container_type
%type	<bidltype>		enum_field_list
%type	<bidltype>		enum_clause
%type	<bidltype>		class_clause

%type	<bidltype>		struct_field
%type	<bidltype>		struct_clause
%type	<bidltype>		struct_field_list
%type	<bidltype>		namespace_clause
%type	<bidltype>		direction
%type	<bidltype>		function_field_direction
%type	<bidltype>		function_field
%type	<bidltype>		function_type
%type	<bidltype>		function

%type	<bidltype>		const_sequence
%type	<bidltype>		const_set
%type	<bidltype>		const_map
%type	<bidltype>		const_map_field
%type	<bidltype_vector>	const_sequence_field_list
%type	<bidltype_vector>	const_set_field_list
%type	<bidltype_vector>	const_map_field_list

%type	<bidltype_vector>		definition_clause_list
%type	<bidltype_vector>		include_clause_list
%type	<bidltype_vector>		function_field_list
%type	<bidltype_vector>		function_field_list2
%type	<bidltype_vector>		function_list


%token	<szstr>			TOKEN_IDENTIFIER	/* 标识符 */
%token	<szstr>			TOKEN_LITERAL		/* 字面量 */
%token	<szstr>			TOKEN_INTEGER		/* 整数值 */
%token	<szstr>			TOKEN_DECIMAL		/* 浮点数 */
%token	<boolval>		TOKEN_BOOLVAL		/* 布尔值 */

%token	<szstr>			TOKEN_BOOLEAN
%token	<szstr>			TOKEN_INT8
%token	<szstr>			TOKEN_INT16
%token	<szstr>			TOKEN_INT32
%token	<szstr>			TOKEN_INT64
%token	<szstr>			TOKEN_FLOAT
%token	<szstr>			TOKEN_DOUBLE
%token	<szstr>			TOKEN_STRING
%token	<szstr>			TOKEN_BINARY
%token	<szstr>			TOKEN_VOID

%token	<szstr>			TOKEN_MAP
%token	<szstr>			TOKEN_SET
%token	<szstr>			TOKEN_SEQUENCE

%token	<szstr>			TOKEN_INCLUDE
%token	<szstr>			TOKEN_CONST
%token	<szstr>			TOKEN_TYPEDEF
%token	<szstr>			TOKEN_ENUM
%token	<szstr>			TOKEN_STRUCT
%token	<szstr>			TOKEN_CLASS
%token	<szstr>			TOKEN_NAMESPACE
%token	<szstr>			TOKEN_IN
%token	<szstr>			TOKEN_OUT
%token	<szstr>			TOKEN_ALL

%token	<szstr>			TOKEN_EQ
%token	<szstr>			TOKEN_LESS
%token	<szstr>			TOKEN_MORE
%token	<szstr>			TOKEN_COMMA
%token	<szstr>			TOKEN_LEFT_CURLY_BRACKET
%token	<szstr>			TOKEN_RIGHT_CURLY_BRACKET
%token	<szstr>			TOKEN_LEFT_BRACKET
%token	<szstr>			TOKEN_RIGHT_BRACKET
%token	<szstr>			TOKEN_COLON
%token	<szstr>			TOKEN_SEMICOLON
%token	<szstr>			TOKEN_LEFT_SQUARE_BRACKET
%token	<szstr>			TOKEN_RIGHT_SQUARE_BRACKET

%%

document:
	include_clause_list definition_clause_list
{
	msg_dbg("document \t-> include_clause_list definition_clause_list\n");
	std::vector<BidlType*>::iterator itr;

	for (itr = $1->begin(); itr != $1->end(); ++itr) {
		g_parseresult->bt->append(*itr);
	}
	delete $1;

	for (itr = $2->begin(); itr != $2->end(); ++itr) {
		g_parseresult->bt->append(*itr);
	}
	delete $2;
}
;

include_clause_list:
	/* 空 */
{
	msg_dbg("include_clause_list \t-> \n");
	$$ = new std::vector<BidlType*>();
}
	| include_clause_list include_clause
{
	msg_dbg("include_clause_list \t-> include_clause_list include_clause\n");
	$$ = $1;
	$$->push_back($2);
}
;

include_clause:
	TOKEN_INCLUDE TOKEN_LITERAL
{
	msg_dbg("include_clause	\t-> include %s\n", $2);
	
	g_parseresult->include_bidls.push_back($2);
	$$ = new BidlInclude;
	$$->set_name($2);

	free($1);
	free($2);
}
	| TOKEN_INCLUDE error
{
	myerror("%s: %d : error: expect literal after `include'\n", g_cur_bidl_file_name.c_str(), @1.first_line);
}
;

definition_clause_list:
	/* 空 */
{
	msg_dbg("definition_clause_list \t-> \n");
	$$ = new std::vector<BidlType*>();
}
	| definition_clause_list definition_clause
{
	msg_dbg("definition_clause_list \t-> definition_clause_list definition_clause\n");
	$$ = $1;
	$$->push_back($2);
}
;

definition_clause:
	const_clause
{
	msg_dbg("definition_clause \t-> const_clause\n");
}
	| typedef_clause
{
	msg_dbg("definition_clause \t-> typedef_clause\n");
}
	| enum_clause
{
	msg_dbg("definition_clause \t-> enum_clause\n");
}
	| struct_clause
{
	msg_dbg("definition_clause \t-> struct_clause\n");
}
	| class_clause
{
	msg_dbg("definition_clause \t-> class_clause\n");
}
	| namespace_clause
{
	msg_dbg("definition_clause \t-> namespace_clause\n");
}
	| error
{
	myerror("%s: %d: error: invalid definition clause\n"
			"\t expect include/const/typedef/enum/struct/class/namespace\n",
			g_cur_bidl_file_name.c_str(),
			yylineno);
}
;

const_clause:
	TOKEN_CONST const_type TOKEN_IDENTIFIER TOKEN_EQ const_value TOKEN_SEMICOLON
{
	msg_dbg("const_clause \t-> const const_type %s = const_value ;\n", $3);

	BidlConst* t = new BidlConst;
	t->set_line(@1.first_line);
	t->set_filename(g_cur_bidl_file_name);
	t->set_name($3);
	t->set_field_type($2);
	t->set_value($5);

	$$ = t;
	
	free($1);
	free($3);
	free($4);
	free($6);
}
	| TOKEN_CONST error
{
	myerror("%s: %d: error: expect a type name after `const'\n",
		g_cur_bidl_file_name.c_str(), @1.first_line);
}
	| TOKEN_CONST const_type error
{
	myerror("%s: %d: error: expect a identifier after `%s'\n",
		g_cur_bidl_file_name.c_str(), @2.first_line, "SEAT");
}
	| TOKEN_CONST const_type TOKEN_IDENTIFIER error
{
	myerror("%s: %d: error: expect `=' after identifier `%s'\n",
		g_cur_bidl_file_name.c_str(), @3.first_line, $3);
}
	| TOKEN_CONST const_type TOKEN_IDENTIFIER TOKEN_EQ error
{
	myerror("%s: %d: error: expect const value after `='\n",
		g_cur_bidl_file_name.c_str(), @4.first_line);
}
	| TOKEN_CONST const_type TOKEN_IDENTIFIER TOKEN_EQ const_value error
{
	myerror("%s: %d: error: expect `;' after const value\n",
		g_cur_bidl_file_name.c_str(), @5.first_line);
}
;

const_type:
	TOKEN_IDENTIFIER
{
	msg_dbg("const_type \t-> %s\n", $1);
	BidlIdentifier* t = new BidlIdentifier($1);
    t->set_line(@1.first_line);
    t->set_filename(g_cur_bidl_file_name);
	$$ = t;

	free($1);
}
	| basic_type
{
	msg_dbg("const_type \t-> basic_type\n");
	$$ = $1;
}
	| container_type
{
	msg_dbg("const_type \t-> container_type\n");
	$$ = $1;
}
;

basic_type:
	TOKEN_BOOLEAN
{
	msg_dbg("basic_type \t-> boolean\n");
	$$ = new BidlBoolean;
	free($1);
}
	| TOKEN_INT8
{
	msg_dbg("basic_type \t-> int8\n");
	$$ = new BidlInt8;
	free($1);
}
	| TOKEN_INT16
{
	msg_dbg("basic_type \t-> int16\n");
	$$ = new BidlInt16;
	free($1);
}
	| TOKEN_INT32 
{
	msg_dbg("basic_type \t-> int32\n");
	$$ = new BidlInt32;
	free($1);
}
	| TOKEN_INT64 
{
	msg_dbg("basic_type \t-> int64\n");
	$$ = new BidlInt64;
	free($1);
}
	| TOKEN_FLOAT
{
	msg_dbg("basic_type \t-> float\n");
	$$ = new BidlFloat;
	free($1);
}
	| TOKEN_DOUBLE
{
	msg_dbg("basic_type \t-> double\n");
	$$ = new BidlDouble;
	free($1);
}
	| TOKEN_STRING
{
	msg_dbg("basic_type \t-> string\n");
	$$ = new BidlString;
	free($1);
}
	| TOKEN_BINARY
{
	msg_dbg("basic_type \t-> binary\n");
	$$ = new BidlBinary;
	free($1);
}
;

const_value:
	TOKEN_BOOLVAL
{
	msg_dbg("const_value \t-> %s\n", $1?"true":"false");
	$$ = new BidlConstBoolean($1);
}
	| TOKEN_INTEGER
{
	msg_dbg("const_value \t-> %d\n", atoi($1));
	$$ = new BidlConstInteger($1);
	free($1);
}
	| TOKEN_DECIMAL
{
	msg_dbg("const_value \t-> %f\n", atof($1));
	$$ = new BidlConstDecimal($1);
	free($1);
}
	| TOKEN_LITERAL
{
	msg_dbg("const_value \t-> %s\n", $1);
	$$ = new BidlConstLiteral($1);
	free($1);
}
	| const_sequence
{
	msg_dbg("const_value \t-> const_sequence\n");
	$$ = $1;
}
	| const_set
{
	msg_dbg("const_value \t-> const_set\n");
	$$ = $1;
}
	| const_map
{
	msg_dbg("const_value \t->const_map\n");
	$$ = $1;
}
;

const_map:
	TOKEN_LEFT_CURLY_BRACKET const_map_field_list TOKEN_RIGHT_CURLY_BRACKET
{
	msg_dbg("const_map \t-> { const_map_field_list }\n");
	$$ = new BidlMap;
	std::vector<BidlType*>::iterator itr;
	for (itr = $2->begin(); itr != $2->end(); ++itr) {
		$$->append(*itr);
	}
	delete $2;
	free($1);
	free($3);
}
;

const_map_field_list:
	/*空*/
{
	$$ = new std::vector<BidlType*>();
}
	| const_map_field
{
	$$ = new std::vector<BidlType*>();
	$$->push_back($1);
}
	| const_map_field_list TOKEN_COMMA const_map_field
{
	$$ = $1;
	$$->push_back($3);
	free($2);
}
;

const_map_field:
	const_value TOKEN_COLON const_value
{
	BidlMap* tmp = new BidlMap;
	tmp->set_key_type($1);
	tmp->set_value_type($3);
	$$ = tmp;
	free($2);
}
;

const_set:
	TOKEN_LESS const_set_field_list TOKEN_MORE
{
	$$ = new BidlConstSet;
	std::vector<BidlType*>::iterator itr;
	for (itr = $2->begin(); itr != $2->end(); ++itr) {
		$$->append(*itr);
	}
	delete $2;
	free($1);
	free($3);
}
;

const_set_field_list:
{
	$$ = new std::vector<BidlType*>();
}
	| const_value
{
	$$ = new std::vector<BidlType*>();
	$$->push_back($1);
}
	| const_set_field_list TOKEN_COMMA const_value
{
	$$ = $1;
	$$->push_back($3);
	free($2);
}
;

const_sequence:
	TOKEN_LEFT_SQUARE_BRACKET const_sequence_field_list TOKEN_RIGHT_SQUARE_BRACKET
{
	$$ = new BidlConstSequence;
	std::vector<BidlType*>::iterator itr;
	for (itr = $2->begin(); itr != $2->end(); ++itr) {
		$$->append(*itr);
	}
	delete $2;
	free($1);
	free($3);
}
;

const_sequence_field_list:
{
	$$ = new std::vector<BidlType*>();
}	
	| const_value
{
	$$ = new std::vector<BidlType*>();
	$$->push_back($1);
}
	| const_sequence_field_list TOKEN_COMMA const_value
{
	$$ = $1;
	$$->push_back($3);
	free($2);
}
;

typedef_clause:
	TOKEN_TYPEDEF data_type TOKEN_IDENTIFIER TOKEN_SEMICOLON
{
	msg_dbg("typedef_clause \t-> typedef data_type %s ;\n", $3);
	
	BidlTypedef* t = new BidlTypedef;
	t->set_sub_type($2);
	t->set_name($3);
	t->set_line(@3.first_line);
	t->set_filename(g_cur_bidl_file_name);
	$$ = t;

	free($1);
	free($3);
	free($4);
}
	| TOKEN_TYPEDEF error
{
	myerror("%s: %d: error: expect data type after `typedef'\n",
		g_cur_bidl_file_name.c_str(), @1.first_line);
}
	| TOKEN_TYPEDEF data_type error
{
	myerror("%s: %d: error: expect identifier after %s\n",
		g_cur_bidl_file_name.c_str(), @2.first_line, "SEAT");
}
	| TOKEN_TYPEDEF data_type TOKEN_IDENTIFIER error
{
	myerror("%s: %d: error: expect `;' after `%s'\n",
		g_cur_bidl_file_name.c_str(), @3.first_line, $3);
}
;

data_type:
	TOKEN_IDENTIFIER
{
	msg_dbg("data_type \t-> %s\n", $1);
	//TODO: to search id
	$$ = new BidlIdentifier($1);
    $$->set_line(@1.first_line);
    $$->set_filename(g_cur_bidl_file_name);
	free($1);
}
	| basic_type
{
	msg_dbg("data_type \t-> basic_type\n");
}
	| container_type
{
	msg_dbg("data_type \t-> container_type\n");
}
;

container_type:
	map_type
{
	msg_dbg("container_type \t-> map_type\n");
}
	| set_type
{
	msg_dbg("container_type \t-> set_type\n");
}
	| sequence_type
{
	msg_dbg("container_type \t-> sequence_type\n");
}
;

map_type:
	TOKEN_MAP TOKEN_LESS data_type TOKEN_COMMA data_type TOKEN_MORE
{
	msg_dbg("map_type \t-> map<data_type, data_type>\n");
	BidlMap* t = new BidlMap;
	t->set_key_type($3);
	t->set_value_type($5);
	$$ = t;

	free($1);
	free($2);
	free($4);
	free($6);
}
	| TOKEN_MAP error
{
	myerror("%s: %d: error: expect `<' after `map'\n",
		g_cur_bidl_file_name.c_str(), @1.first_line);
}
	| TOKEN_MAP TOKEN_LESS error
{
	myerror("%s: %d: error: expect key type after `<'\n",
		g_cur_bidl_file_name.c_str(), @2.first_line);
}
	| TOKEN_MAP TOKEN_LESS data_type error
{
	myerror("%s: %d: error: expect `,' after `%s'\n",
		g_cur_bidl_file_name.c_str(), @3.first_line, "SEAT");
}
	| TOKEN_MAP TOKEN_LESS data_type TOKEN_COMMA error
{
	myerror("%s: %d: error: expect value type after `,'\n",
		g_cur_bidl_file_name.c_str(), @4.first_line);
}
	| TOKEN_MAP TOKEN_LESS data_type TOKEN_COMMA data_type error
{
	myerror("%s: %d: error: expect `>' after `%s'\n",
		g_cur_bidl_file_name.c_str(), @5.first_line, "SEAT");
}
;

set_type:
	TOKEN_SET TOKEN_LESS data_type TOKEN_MORE
{
	msg_dbg("set_type \t-> set<data_type>\n");
	BidlSet* t = new BidlSet;
	t->set_sub_type($3);
	$$ = t;

	free($1);
	free($2);
	free($4);
}
	| TOKEN_SET error
{
	myerror("%s: %d: error: expect `<' after `set'\n",
		g_cur_bidl_file_name.c_str(), @1.first_line);
}
	| TOKEN_SET TOKEN_LESS error
{
	myerror("%s: %d: error: expect data type after `<'\n",
		g_cur_bidl_file_name.c_str(), @2.first_line);
}
	| TOKEN_SET TOKEN_LESS data_type error
{
	myerror("%s: %d: error: expect `>' after `%s'\n",
		g_cur_bidl_file_name.c_str(), @3.first_line, "SEAT");
}
;

sequence_type:
	TOKEN_SEQUENCE TOKEN_LESS data_type TOKEN_MORE
{
	msg_dbg("sequence_type \t-> sequence<data_type>\n");
	BidlSequence* t = new BidlSequence;
	t->set_sub_type($3);
	$$ = t;

	free($1);
	free($2);
	free($4);
}
	| TOKEN_SEQUENCE error
{
	myerror("%s: %d: error: expect `<' after `sequence'\n",
		g_cur_bidl_file_name.c_str(), @1.first_line);
}
	| TOKEN_SEQUENCE TOKEN_LESS error
{
	myerror("%s: %d: error: expect data type after `<'\n",
		g_cur_bidl_file_name.c_str(), @2.first_line);
}
	| TOKEN_SEQUENCE TOKEN_LESS data_type error
{
	myerror("%s: %d: error: expect `>' after `%s'\n",
		g_cur_bidl_file_name.c_str(), @3.first_line, "SEAT");
}
;

enum_clause:
	TOKEN_ENUM TOKEN_IDENTIFIER TOKEN_LEFT_CURLY_BRACKET enum_field_list TOKEN_RIGHT_CURLY_BRACKET
{
	msg_dbg("enum_clause \t-> enum %s { enum_field_list }\n", $2);
	$$ = $4;
	if (!is_c_identifier($2)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			@2.first_line,
			$2);
	}
	$$->set_name($2);
	$$->set_line(@2.first_line);
	$$->set_filename(g_cur_bidl_file_name);
	free($1);
	free($2);
	free($3);
	free($5);
}
	| TOKEN_ENUM error
{
	myerror("%s: %d: error: expect identifier after `enum'\n",
		g_cur_bidl_file_name.c_str(), @1.first_line);
}
	| TOKEN_ENUM TOKEN_IDENTIFIER error
{
	myerror("%s: %d: error: expect `{' after `%s'\n",
		g_cur_bidl_file_name.c_str(), @2.first_line, $2);
}
	| TOKEN_ENUM TOKEN_IDENTIFIER TOKEN_LEFT_CURLY_BRACKET error
{
	myerror("%s: %d: error: invalid enum field(s)\n",
		g_cur_bidl_file_name.c_str(), @3.first_line);
}
	| TOKEN_ENUM TOKEN_IDENTIFIER TOKEN_LEFT_CURLY_BRACKET enum_field_list error
{
	myerror("%s: %d: error: expect `}' or `,' after enum fields\n",
		g_cur_bidl_file_name.c_str(), @4.last_line);
}
;

enum_field_list:
	TOKEN_IDENTIFIER
{
	if (!is_c_identifier($1)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			@1.first_line,
			$1);
	}
	msg_dbg("enum_field_list \t-> %s\n", $1);
	BidlEnumField* f = new BidlEnumField($1);
	f->set_line(@1.first_line);
	f->set_filename(g_cur_bidl_file_name);
	$$ = new BidlEnum;
	$$->append(f);
	free($1);
}
	| TOKEN_IDENTIFIER TOKEN_EQ TOKEN_INTEGER
{
	msg_dbg("enum_field_list \t-> %s = %d\n", $1, atoi($3));
	//TODO: check integer 
	if (!is_c_identifier($1)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			@1.first_line,
			$1);
	}
	BidlEnumField* f = new BidlEnumField($1, atoi($3));
	f->set_line(@1.first_line);
	f->set_filename(g_cur_bidl_file_name);
	$$ = new BidlEnum;
	$$->append(f);
	free($1);
	free($2);
	free($3);
}
	| enum_field_list TOKEN_COMMA TOKEN_IDENTIFIER
{
	$$ = $1;
	if (!is_c_identifier($3)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			@3.first_line,
			$3);
	}
	BidlEnumField* f = new BidlEnumField($3);
	f->set_line(@3.first_line);
	f->set_filename(g_cur_bidl_file_name);
	$$->append(f);
	msg_dbg("enum_field_list \t-> enum_field_list, %s\n", $3);
	free($2);
	free($3);
}
	| enum_field_list TOKEN_COMMA TOKEN_IDENTIFIER TOKEN_EQ TOKEN_INTEGER	
{
	$$ = $1;
	//TODO:check integer
	if (!is_c_identifier($3)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			@3.first_line,
			$3);
	}
	BidlEnumField* f = new BidlEnumField($3, atoi($5));
	f->set_line(@3.first_line);
	f->set_filename(g_cur_bidl_file_name);
	$$->append(f);
	msg_dbg("enum_field_list \t-> enum_field_list, %s = %d\n", $3, atoi($5));
	free($2);
	free($3);
	free($4);
	free($5);
}
	| TOKEN_IDENTIFIER TOKEN_EQ error
{
	myerror("%s: %d: error: expect integer after `='\n",
		g_cur_bidl_file_name.c_str(), @2.first_line);
}
	| enum_field_list TOKEN_COMMA error
{
	myerror("%s: %d: error: expect identifier after `,'\n",
		g_cur_bidl_file_name.c_str(), @2.first_line);
}
	| enum_field_list TOKEN_COMMA TOKEN_IDENTIFIER TOKEN_EQ error
{
	myerror("%s: %d: error: expect integer after `='\n",
		g_cur_bidl_file_name.c_str(), @4.first_line);
}
;

struct_clause:
	TOKEN_STRUCT TOKEN_IDENTIFIER TOKEN_LEFT_CURLY_BRACKET struct_field_list TOKEN_RIGHT_CURLY_BRACKET
{
	msg_dbg("struct_clause \t-> struct %s { struct_field_list }\n", $2);
	$$ = $4;
	if (!is_c_identifier($2)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			@2.first_line,
			$2);
	}
	$$->set_name($2);
	$$->set_line(@2.first_line);
	$$->set_filename(g_cur_bidl_file_name);
	free($1);
	free($2);
	free($3);
	free($5);
}
	| TOKEN_STRUCT error
{
	myerror("%s: %d: error: expect identifier after `struct'\n",
		g_cur_bidl_file_name.c_str(), @1.first_line);
} 
	| TOKEN_STRUCT TOKEN_IDENTIFIER error
{
	myerror("%s: %d: error: expect `{' after `%s'\n",
		g_cur_bidl_file_name.c_str(), @2.first_line, $2);
} 
	| TOKEN_STRUCT TOKEN_IDENTIFIER TOKEN_LEFT_CURLY_BRACKET error
{
	myerror("%s: %d: error: invalid struct field after `{'\n",
		g_cur_bidl_file_name.c_str(), @3.first_line);
} 
	| TOKEN_STRUCT TOKEN_IDENTIFIER TOKEN_LEFT_CURLY_BRACKET struct_field_list error
{
	myerror("line: %d: error: expect `}' after `%s'\n", @4.last_line, "SEAT");
} 
;

struct_field_list:
	struct_field
{
	msg_dbg("struct_field_list \t-> struct_field\n");
	$$ = new BidlStruct;
	$$->append($1);
}
	| struct_field_list struct_field
{
	msg_dbg("struct_field_list \t-> struct_field_list struct_field\n");
	$$ = $1;
	$$->append($2);
}
;

struct_field:
	data_type TOKEN_IDENTIFIER TOKEN_SEMICOLON
{
	msg_dbg("struct_field \t-> data_type %s;\n", $2);
	if (!is_c_identifier($2)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			@2.first_line,
			$2);
	}
	BidlStructField* t = new BidlStructField($2);
	t->set_field_type($1);
	t->set_line(@2.first_line);
	t->set_filename(g_cur_bidl_file_name);
	$$ = t;
	
	free($2);
	free($3);
}
	| data_type error
{
	myerror("%s: %d: error: expect identifier after `%s'\n",
		g_cur_bidl_file_name.c_str(), @1.first_line, "SEAT");
}
	| data_type TOKEN_IDENTIFIER error
{
	myerror("%s: %d: error: expect `;' after `%s'\n",
		g_cur_bidl_file_name.c_str(), @2.first_line, $2);
}
;
namespace_clause:
	TOKEN_NAMESPACE TOKEN_IDENTIFIER TOKEN_LEFT_CURLY_BRACKET definition_clause_list TOKEN_RIGHT_CURLY_BRACKET
{
	msg_dbg("namespace_clause \t-> namespace %s { definition_clause_list }\n", $2);
	$$ = new BidlNamespace;

	if (!is_c_identifier($2)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			@2.first_line,
			$2);
	}

	$$->set_name($2);
	$$->coordination.line = @2.first_line;
	$$->coordination.column = @2.first_column;
	$$->coordination.filename = g_cur_bidl_file_name;

	std::vector<BidlType*>::iterator itr;
	for (itr = $4->begin(); itr != $4->end(); ++itr) {
		$$->append(*itr);
	}
	delete $4;

	free($1);
	free($2);
	free($3);
	free($5);
}
	| TOKEN_NAMESPACE error
{
	myerror("%s: %d: error: expect identifier after `namespace'\n",
		g_cur_bidl_file_name.c_str(), @1.first_line);
}
	| TOKEN_NAMESPACE TOKEN_IDENTIFIER error
{
	myerror("%s: %d: error: expect `{' after `%s'\n",
		g_cur_bidl_file_name.c_str(), @2.first_line, $2);
}
	| TOKEN_NAMESPACE TOKEN_IDENTIFIER TOKEN_LEFT_CURLY_BRACKET error
{
	myerror("%s: %d: error: invalid definition clause after `{' or missing `}'\n",
		g_cur_bidl_file_name.c_str(), @3.first_line);
}
;

class_clause:
	TOKEN_CLASS TOKEN_IDENTIFIER TOKEN_LEFT_CURLY_BRACKET function_list TOKEN_RIGHT_CURLY_BRACKET
{
	msg_dbg("class_clause \t-> class %s { function_list }\n", $2);
	$$ = new BidlClass;
	if (!is_c_identifier($2)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			@2.first_line,
			$2);
	}
	$$->set_name($2);
	$$->set_line(@2.first_line);
	$$->set_filename(g_cur_bidl_file_name);

	std::vector<BidlType*>::iterator itr;
	for (itr = $4->begin(); itr != $4->end(); ++itr) {
		$$->append(*itr);
	}
	delete $4;

	free($1);
	free($2);
	free($3);
	free($5);
}
	| TOKEN_CLASS error
{
	myerror("%s: %d: error: expect identifier after `class'\n",
		g_cur_bidl_file_name.c_str(), @1.first_line);
}
	| TOKEN_CLASS TOKEN_IDENTIFIER error
{
	myerror("%s: %d: error: expect `{' after `%s'\n",
		g_cur_bidl_file_name.c_str(), @2.first_line, $2);
}
	| TOKEN_CLASS TOKEN_IDENTIFIER TOKEN_LEFT_CURLY_BRACKET error
{
	myerror("%s: %d: error: invalid function list after `{'\n",
		g_cur_bidl_file_name.c_str(), @3.first_line);
}
	| TOKEN_CLASS TOKEN_IDENTIFIER TOKEN_LEFT_CURLY_BRACKET function_list error
{
	myerror("%s: %d: error: expect `}'\n",
		g_cur_bidl_file_name.c_str(), @4.last_line);
}
;

function_list:
	function
{
	$$ = new std::vector<BidlType*>();
	$$->push_back($1);
}
	| function_list function
{
	$$->push_back($2);
}
;

function:
	function_type TOKEN_IDENTIFIER TOKEN_LEFT_BRACKET function_field_list TOKEN_RIGHT_BRACKET TOKEN_SEMICOLON
{
	msg_dbg("function \t-> function_type %s(function_field_list);\n", $2);
	BidlFunction* t = new BidlFunction;
	if (!is_c_identifier($2)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			@2.first_line,
			$2);
	}
	t->set_name($2);
	t->set_return_type($1);
	t->set_line(@2.first_line);
	t->set_filename(g_cur_bidl_file_name);

	std::vector<BidlType*>::iterator itr;
	for (itr = $4->begin(); itr != $4->end(); ++itr) {
		t->append(*itr);
	}
	delete $4;

	$$ = t;
	free($2);
	free($3);
	free($5);
	free($6);
}
	| function_type error
{
	myerror("%s: %d: error: expect identifier after function_type `%s'\n",
		g_cur_bidl_file_name.c_str(), @1.first_line, "SEAT");
}
	| function_type TOKEN_IDENTIFIER error
{
	myerror("%s: %d: error: expect `(' after `%s'\n",
		g_cur_bidl_file_name.c_str(), @2.first_line, $2);
}
	| function_type TOKEN_IDENTIFIER TOKEN_LEFT_BRACKET error
{
	myerror("%s: %d: error: invalid function field list after `('\n",
		g_cur_bidl_file_name.c_str(), @3.first_line);
}
;

function_type:
	data_type
	| TOKEN_VOID
{
	$$ = new BidlVoid;
	free($1);
}
;

function_field_list:
	/*空*/
{
	$$ = new std::vector<BidlType*>();
}
	| function_field
{
	$$ = new std::vector<BidlType*>();
	$$->push_back($1);
}
	| function_field_list2 TOKEN_COMMA function_field
{
	$$->push_back($3);
	free($2);
}
;

function_field_list2:
	function_field
{
	$$ = new std::vector<BidlType*>();
	$$->push_back($1);
}
	| function_field_list2 TOKEN_COMMA function_field
{
	$$->push_back($3);
	free($2);
}
	| function_field_list2 TOKEN_COMMA error
{
	myerror("%s: %d: error: invalid function field after `,'\n",
		g_cur_bidl_file_name.c_str(), @2.first_line);
}
	| function_field_list2 error
{
	myerror("%s: %d: error: expect `,'",
		g_cur_bidl_file_name.c_str(), @1.last_line);
}
;

function_field:
	data_type TOKEN_IDENTIFIER
{
	BidlFunctionField* t = new BidlFunctionField;
	t->set_field_type($1);
	if (!is_c_identifier($2)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			@2.first_line,
			$2);
	}
	t->set_name($2);
	t->set_line(@2.first_line);
	t->set_filename(g_cur_bidl_file_name);
	$$ = t;
	free($2);

//	| data_type TOKEN_IDENTIFIER TOKEN_EQ const_value
//{
//	BidlFunctionField* t = new BidlFunctionField;
//	t->set_field_type($1);
//	t->set_name($2);
//	t->set_value($4);
//	t->set_line(@2.first_line);
//	t->set_filename(g_cur_bidl_file_name);
//	$$ = t;
//	free($2);
//	free($3);
//}

}
	| function_field_direction data_type TOKEN_IDENTIFIER
{
	BidlFunctionField* t = new BidlFunctionField;
	t->set_field_direction($1);
	t->set_field_type($2);
	if (!is_c_identifier($3)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			@3.first_line,
			$3);
	}
	t->set_name($3);
	t->set_line(@3.first_line);
	t->set_filename(g_cur_bidl_file_name);
	$$ = t;
	free($3);
//	| function_field_direction data_type TOKEN_IDENTIFIER TOKEN_EQ const_value
//{
//	BidlFunctionField* t = new BidlFunctionField;
//	t->set_field_direction($1);
//	t->set_field_type($2);
//	t->set_name($3);
//	t->set_value($5);
//	t->set_line(@3.first_line);
//	t->set_filename(g_cur_bidl_file_name);
//	$$ = t;
//	free($3);
//	free($4);
//}
}
;

function_field_direction:
	TOKEN_LEFT_SQUARE_BRACKET direction TOKEN_RIGHT_SQUARE_BRACKET
{
	$$ = $2;
	free($1);
	free($3);
}
	| TOKEN_LEFT_SQUARE_BRACKET error
{
	myerror("%s: %d: error: expect in/out/all after `['\n",
		g_cur_bidl_file_name.c_str(), @1.first_line);
}
	| TOKEN_LEFT_SQUARE_BRACKET direction error
{
	myerror("%s: %d: error: expect `]' after `%s'\n",
		g_cur_bidl_file_name.c_str(), @2.first_line, "SEAT");
}
;

direction:
	TOKEN_IN
{
	BidlFieldDirection* t = new BidlFieldDirection;
	t->set_direction(BidlFieldDirection::IN);
	$$ = t;
	free($1);
}
	| TOKEN_OUT
{
	BidlFieldDirection* t = new BidlFieldDirection;
	t->set_direction(BidlFieldDirection::OUT);
	$$ = t;
	free($1);
}
	| TOKEN_ALL
{
	BidlFieldDirection* t = new BidlFieldDirection;
	t->set_direction(BidlFieldDirection::ALL);
	$$ = t;
	free($1);
}
;

%%

void msg_dbg(const char* fmt, ...) {
	if (!g_parser.is_debuged()) {
		return;
	}

	va_list var;

	va_start(var, fmt);
	vfprintf(stderr, fmt, var);
	va_end(var);
}

void yyerror(const char* fmt, ...) {
	va_list var;

	va_start(var, fmt);
	vfprintf(stderr, fmt, var);
	fprintf(stderr, "\n");
	va_end(var);
}

void myerror(const char* fmt, ...) {
	va_list var;

	va_start(var, fmt);
	vfprintf(stderr, fmt, var);
	fprintf(stderr, "\n");
	va_end(var);
	exit(1);
}

