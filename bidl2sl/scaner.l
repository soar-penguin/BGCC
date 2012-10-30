%{
#include <string>
#include "common.h"
#include "grammar.tab.h"

int yycolumn = 1;

%}

%option noyywrap nounput yylineno

identifier ([a-zA-Z_][\.a-zA-Z_0-9]*)
integer ([+|-]?[0-9]+)
decimal ([+|-]?[0-9]+(\.[0-9]+)?((E|e)[+|-]?[0-9]+)?)
string (\"[^\"\n]*\"|'[^'\n]*')
nostring (\"[^\"\n]*\n|'[^'\n]*\n)

whitespace    ([ \t\r\n]*)
sillycomm     ("/*""*"*"*/")
multicomm     ("/*"([^*/]|[^*]"/"|"*"[^/])*"*"*"*/")
comment       ("//"[^\n]*)

newline	([\n])

%%

{whitespace}         { }
{sillycomm}          { }
{multicomm}          { }
{comment}            { }

"__CLASS__" 	{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }			
"__DIR__"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"__FILE__"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"__LINE__"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"__METHOD__"	{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }			
"__NAMESPACE__"	{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }			
"abstract"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"alias"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"alignas"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"alignof"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"and"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"and_eq"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"args"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"as"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"asm"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"assert"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"auto"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"BEGIN"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"bitand"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"bitor"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"bool"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"break"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"byte"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"case"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"catch"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"char"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"char16_t"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"char32_t"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"clone"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"compl"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"const_cast"	{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }			
"constexpr"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"continue"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"cpp"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"cpp_type"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"declare"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"decltype"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"def"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"default"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"del"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"delete"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"do"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"double"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"dynamic"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"dynamic_cast"	{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }			
"elif"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"else"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"elseif"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"elsif"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"END"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"enddeclare"	{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }			
"endfor"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"endforeach"	{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }			
"endif"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"endswitch"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"endwhile"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"ensure"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"except"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"exec"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"explicit"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"export"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"extends"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"extern"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"final"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"finally"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"for"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"foreach"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"friend"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"function"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"global"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"goto"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"if"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"implements"	{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }			
"import"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"inline"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"instanceof"	{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }			
"int"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"interface"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"is"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"java"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"lambda"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"long"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"module"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"mutable"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"native"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"new"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"next"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"nil"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"noexcept"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"not"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"not_eq"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"null"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"nullptr "		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"operator"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"optional"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"or"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"or_eq"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"package"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"pass"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"print"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"private"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"protected"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"protocol"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"public"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"raise"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"redo"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"register"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"reinterpret_cast" {myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }			
"request"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"request_len"	{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }			
"required"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"rescue"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"retry"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"return"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"self"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"short"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"signed"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"sizeof"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"static"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"static_assert"	{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }			
"static_cast"	{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }			
"strictfp"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"super"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"switch"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"synchronized"	{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }			
"template"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"then"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"this"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"thread_local"	{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }			
"throw"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"throws"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"transient"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"try"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"typeid"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"typename"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"undef"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"union"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"unless"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"unsigned"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"until"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"use"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"using"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"var"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"virtual"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"volatile"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"wchar_t"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"when"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"while"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"with"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"xor"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	
"xor_eq"		{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }		
"yield"			{myerror("%s: %d: error: reserved word: %s", g_cur_bidl_file_name.c_str(), yylineno, yytext); }	

"boolean"|"bool" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_BOOLEAN;
}

"int8"|"byte" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_INT8;
}

"int16" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_INT16;
}

"int32" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_INT32;
}

"int64" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_INT64;
}

"float" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_FLOAT;

	//"double" {
	//
	//	yylloc.first_line = yylloc.last_line = yylineno;
	//	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	//	yycolumn += yyleng;
	//
	//	yylval.szstr = strdup(yytext);
	//	return TOKEN_DOUBLE;
	//}
}

"string" { 
	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_STRING;
}

"binary" { 
	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_BINARY;
}

"map" { 
	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_MAP;
}

"set" { 
	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_SET;
}

"sequence" { 
	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_SEQUENCE;
}

"enum" { 
	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_ENUM;
}

"struct" { 
	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_STRUCT;
}

"class" { 
	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_CLASS;
}

"namespace" { 
	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_NAMESPACE;
}

"true"|"TRUE" {
	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.boolval = true;
	return TOKEN_BOOLVAL;
}

"false"|"FALSE" {
	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.boolval = false;
	return TOKEN_BOOLVAL;
}

"include"	{ 

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_INCLUDE;
}

"typedef" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_TYPEDEF;
}

"const" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_CONST;
}

"in" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_IN;
}

"out" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_OUT;
}

"all" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_ALL;
}

"void" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_VOID;
}

"=" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_EQ;
}

":" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_COLON;
}

";" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_SEMICOLON;
}

"," {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_COMMA;
}

">" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_MORE;
}

"<" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_LESS;
}

"{" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_LEFT_CURLY_BRACKET;
}

"}" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_RIGHT_CURLY_BRACKET;
}

"(" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_LEFT_BRACKET;
}

")" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_RIGHT_BRACKET;
}

"[" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_LEFT_SQUARE_BRACKET;
}

"]" {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_RIGHT_SQUARE_BRACKET;
}

{identifier} {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_IDENTIFIER;
}

{integer} {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_INTEGER;
}

{decimal} {

	yylloc.first_line = yylloc.last_line = yylineno;
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1;
	yycolumn += yyleng;

	yylval.szstr = strdup(yytext);
	return TOKEN_DECIMAL;
}

{string} {
	std::string tmp(yytext+1, yyleng-2);
	yylval.szstr = strdup(tmp.c_str());
	return TOKEN_LITERAL;
}


{nostring} {
	myerror("invalid string: `%s'", yytext);
}

. { myerror("unexpected char `%s'", yytext); }

%%
