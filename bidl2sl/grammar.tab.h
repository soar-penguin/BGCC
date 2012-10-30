/* A Bison parser, made by GNU Bison 1.875c.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_IDENTIFIER = 258,
     TOKEN_LITERAL = 259,
     TOKEN_INTEGER = 260,
     TOKEN_DECIMAL = 261,
     TOKEN_BOOLVAL = 262,
     TOKEN_BOOLEAN = 263,
     TOKEN_INT8 = 264,
     TOKEN_INT16 = 265,
     TOKEN_INT32 = 266,
     TOKEN_INT64 = 267,
     TOKEN_FLOAT = 268,
     TOKEN_DOUBLE = 269,
     TOKEN_STRING = 270,
     TOKEN_BINARY = 271,
     TOKEN_VOID = 272,
     TOKEN_MAP = 273,
     TOKEN_SET = 274,
     TOKEN_SEQUENCE = 275,
     TOKEN_INCLUDE = 276,
     TOKEN_CONST = 277,
     TOKEN_TYPEDEF = 278,
     TOKEN_ENUM = 279,
     TOKEN_STRUCT = 280,
     TOKEN_CLASS = 281,
     TOKEN_NAMESPACE = 282,
     TOKEN_IN = 283,
     TOKEN_OUT = 284,
     TOKEN_ALL = 285,
     TOKEN_EQ = 286,
     TOKEN_LESS = 287,
     TOKEN_MORE = 288,
     TOKEN_COMMA = 289,
     TOKEN_LEFT_CURLY_BRACKET = 290,
     TOKEN_RIGHT_CURLY_BRACKET = 291,
     TOKEN_LEFT_BRACKET = 292,
     TOKEN_RIGHT_BRACKET = 293,
     TOKEN_COLON = 294,
     TOKEN_SEMICOLON = 295,
     TOKEN_LEFT_SQUARE_BRACKET = 296,
     TOKEN_RIGHT_SQUARE_BRACKET = 297
   };
#endif
#define TOKEN_IDENTIFIER 258
#define TOKEN_LITERAL 259
#define TOKEN_INTEGER 260
#define TOKEN_DECIMAL 261
#define TOKEN_BOOLVAL 262
#define TOKEN_BOOLEAN 263
#define TOKEN_INT8 264
#define TOKEN_INT16 265
#define TOKEN_INT32 266
#define TOKEN_INT64 267
#define TOKEN_FLOAT 268
#define TOKEN_DOUBLE 269
#define TOKEN_STRING 270
#define TOKEN_BINARY 271
#define TOKEN_VOID 272
#define TOKEN_MAP 273
#define TOKEN_SET 274
#define TOKEN_SEQUENCE 275
#define TOKEN_INCLUDE 276
#define TOKEN_CONST 277
#define TOKEN_TYPEDEF 278
#define TOKEN_ENUM 279
#define TOKEN_STRUCT 280
#define TOKEN_CLASS 281
#define TOKEN_NAMESPACE 282
#define TOKEN_IN 283
#define TOKEN_OUT 284
#define TOKEN_ALL 285
#define TOKEN_EQ 286
#define TOKEN_LESS 287
#define TOKEN_MORE 288
#define TOKEN_COMMA 289
#define TOKEN_LEFT_CURLY_BRACKET 290
#define TOKEN_RIGHT_CURLY_BRACKET 291
#define TOKEN_LEFT_BRACKET 292
#define TOKEN_RIGHT_BRACKET 293
#define TOKEN_COLON 294
#define TOKEN_SEMICOLON 295
#define TOKEN_LEFT_SQUARE_BRACKET 296
#define TOKEN_RIGHT_SQUARE_BRACKET 297




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 18 "grammar.y"
typedef union YYSTYPE {
	char*			szstr;
	bool			boolval;
	BidlType*		bidltype;
	std::vector<BidlType*>* bidltype_vector;
} YYSTYPE;
/* Line 1275 of yacc.c.  */
#line 128 "grammar.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;


