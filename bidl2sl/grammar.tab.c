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

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



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




/* Copy the first part of user declarations.  */
#line 1 "grammar.y"

#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "common.h"
#include "util.h"

extern char* yytext;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 18 "grammar.y"
typedef union YYSTYPE {
	char*			szstr;
	bool			boolval;
	BidlType*		bidltype;
	std::vector<BidlType*>* bidltype_vector;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 181 "grammar.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

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


/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 205 "grammar.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   define YYSTACK_ALLOC alloca
#  endif
# else
#  if defined (alloca) || defined (_ALLOCA_H)
#   define YYSTACK_ALLOC alloca
#  else
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYLTYPE_IS_TRIVIAL) && YYLTYPE_IS_TRIVIAL \
             && defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   382

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  38
/* YYNRULES -- Number of rules. */
#define YYNRULES  131
/* YYNRULES -- Number of states. */
#define YYNSTATES  190

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    13,    16,    17,    20,
      22,    24,    26,    28,    30,    32,    34,    41,    44,    48,
      53,    59,    66,    68,    70,    72,    74,    76,    78,    80,
      82,    84,    86,    88,    90,    92,    94,    96,    98,   100,
     102,   104,   108,   109,   111,   115,   119,   123,   124,   126,
     130,   134,   135,   137,   141,   146,   149,   153,   158,   160,
     162,   164,   166,   168,   170,   177,   180,   184,   189,   195,
     202,   207,   210,   214,   219,   224,   227,   231,   236,   242,
     245,   249,   254,   260,   262,   266,   270,   276,   280,   284,
     290,   296,   299,   303,   308,   314,   316,   319,   323,   326,
     330,   336,   339,   343,   348,   354,   357,   361,   366,   372,
     374,   377,   384,   387,   391,   396,   398,   400,   401,   403,
     407,   409,   413,   417,   420,   423,   427,   431,   434,   438,
     440,   442
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      44,     0,    -1,    45,    47,    -1,    -1,    45,    46,    -1,
      21,     4,    -1,    21,     1,    -1,    -1,    47,    48,    -1,
      49,    -1,    60,    -1,    66,    -1,    68,    -1,    72,    -1,
      71,    -1,     1,    -1,    22,    50,     3,    31,    52,    40,
      -1,    22,     1,    -1,    22,    50,     1,    -1,    22,    50,
       3,     1,    -1,    22,    50,     3,    31,     1,    -1,    22,
      50,     3,    31,    52,     1,    -1,     3,    -1,    51,    -1,
      62,    -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,
      12,    -1,    13,    -1,    14,    -1,    15,    -1,    16,    -1,
       7,    -1,     5,    -1,     6,    -1,     4,    -1,    58,    -1,
      56,    -1,    53,    -1,    35,    54,    36,    -1,    -1,    55,
      -1,    54,    34,    55,    -1,    52,    39,    52,    -1,    32,
      57,    33,    -1,    -1,    52,    -1,    57,    34,    52,    -1,
      41,    59,    42,    -1,    -1,    52,    -1,    59,    34,    52,
      -1,    23,    61,     3,    40,    -1,    23,     1,    -1,    23,
      61,     1,    -1,    23,    61,     3,     1,    -1,     3,    -1,
      51,    -1,    62,    -1,    63,    -1,    64,    -1,    65,    -1,
      18,    32,    61,    34,    61,    33,    -1,    18,     1,    -1,
      18,    32,     1,    -1,    18,    32,    61,     1,    -1,    18,
      32,    61,    34,     1,    -1,    18,    32,    61,    34,    61,
       1,    -1,    19,    32,    61,    33,    -1,    19,     1,    -1,
      19,    32,     1,    -1,    19,    32,    61,     1,    -1,    20,
      32,    61,    33,    -1,    20,     1,    -1,    20,    32,     1,
      -1,    20,    32,    61,     1,    -1,    24,     3,    35,    67,
      36,    -1,    24,     1,    -1,    24,     3,     1,    -1,    24,
       3,    35,     1,    -1,    24,     3,    35,    67,     1,    -1,
       3,    -1,     3,    31,     5,    -1,    67,    34,     3,    -1,
      67,    34,     3,    31,     5,    -1,     3,    31,     1,    -1,
      67,    34,     1,    -1,    67,    34,     3,    31,     1,    -1,
      25,     3,    35,    69,    36,    -1,    25,     1,    -1,    25,
       3,     1,    -1,    25,     3,    35,     1,    -1,    25,     3,
      35,    69,     1,    -1,    70,    -1,    69,    70,    -1,    61,
       3,    40,    -1,    61,     1,    -1,    61,     3,     1,    -1,
      27,     3,    35,    47,    36,    -1,    27,     1,    -1,    27,
       3,     1,    -1,    27,     3,    35,     1,    -1,    26,     3,
      35,    73,    36,    -1,    26,     1,    -1,    26,     3,     1,
      -1,    26,     3,    35,     1,    -1,    26,     3,    35,    73,
       1,    -1,    74,    -1,    73,    74,    -1,    75,     3,    37,
      76,    38,    40,    -1,    75,     1,    -1,    75,     3,     1,
      -1,    75,     3,    37,     1,    -1,    61,    -1,    17,    -1,
      -1,    78,    -1,    77,    34,    78,    -1,    78,    -1,    77,
      34,    78,    -1,    77,    34,     1,    -1,    77,     1,    -1,
      61,     3,    -1,    79,    61,     3,    -1,    41,    80,    42,
      -1,    41,     1,    -1,    41,    80,     1,    -1,    28,    -1,
      29,    -1,    30,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   114,   114,   133,   137,   146,   157,   165,   169,   178,
     182,   186,   190,   194,   198,   202,   212,   230,   235,   240,
     245,   250,   258,   268,   273,   281,   287,   293,   299,   305,
     311,   317,   323,   329,   338,   343,   349,   355,   361,   366,
     371,   379,   395,   398,   403,   412,   423,   437,   440,   445,
     454,   468,   471,   476,   485,   500,   505,   510,   518,   527,
     531,   538,   542,   546,   553,   566,   571,   576,   581,   586,
     594,   605,   610,   615,   623,   634,   639,   644,   652,   670,
     675,   680,   685,   693,   709,   728,   745,   765,   770,   775,
     783,   801,   806,   811,   816,   823,   829,   838,   856,   861,
     868,   896,   901,   906,   914,   939,   944,   949,   954,   962,
     967,   974,  1001,  1006,  1011,  1019,  1020,  1029,  1032,  1037,
    1045,  1050,  1055,  1060,  1068,  1098,  1131,  1137,  1142,  1150,
    1157,  1164
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_IDENTIFIER", "TOKEN_LITERAL",
  "TOKEN_INTEGER", "TOKEN_DECIMAL", "TOKEN_BOOLVAL", "TOKEN_BOOLEAN",
  "TOKEN_INT8", "TOKEN_INT16", "TOKEN_INT32", "TOKEN_INT64", "TOKEN_FLOAT",
  "TOKEN_DOUBLE", "TOKEN_STRING", "TOKEN_BINARY", "TOKEN_VOID",
  "TOKEN_MAP", "TOKEN_SET", "TOKEN_SEQUENCE", "TOKEN_INCLUDE",
  "TOKEN_CONST", "TOKEN_TYPEDEF", "TOKEN_ENUM", "TOKEN_STRUCT",
  "TOKEN_CLASS", "TOKEN_NAMESPACE", "TOKEN_IN", "TOKEN_OUT", "TOKEN_ALL",
  "TOKEN_EQ", "TOKEN_LESS", "TOKEN_MORE", "TOKEN_COMMA",
  "TOKEN_LEFT_CURLY_BRACKET", "TOKEN_RIGHT_CURLY_BRACKET",
  "TOKEN_LEFT_BRACKET", "TOKEN_RIGHT_BRACKET", "TOKEN_COLON",
  "TOKEN_SEMICOLON", "TOKEN_LEFT_SQUARE_BRACKET",
  "TOKEN_RIGHT_SQUARE_BRACKET", "$accept", "document",
  "include_clause_list", "include_clause", "definition_clause_list",
  "definition_clause", "const_clause", "const_type", "basic_type",
  "const_value", "const_map", "const_map_field_list", "const_map_field",
  "const_set", "const_set_field_list", "const_sequence",
  "const_sequence_field_list", "typedef_clause", "data_type",
  "container_type", "map_type", "set_type", "sequence_type", "enum_clause",
  "enum_field_list", "struct_clause", "struct_field_list", "struct_field",
  "namespace_clause", "class_clause", "function_list", "function",
  "function_type", "function_field_list", "function_field_list2",
  "function_field", "function_field_direction", "direction", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    48,    48,    48,    48,    48,    49,    49,    49,    49,
      49,    49,    50,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    53,    54,    54,    54,    55,    56,    57,    57,    57,
      58,    59,    59,    59,    60,    60,    60,    60,    61,    61,
      61,    62,    62,    62,    63,    63,    63,    63,    63,    63,
      64,    64,    64,    64,    65,    65,    65,    65,    66,    66,
      66,    66,    66,    67,    67,    67,    67,    67,    67,    67,
      68,    68,    68,    68,    68,    69,    69,    70,    70,    70,
      71,    71,    71,    71,    72,    72,    72,    72,    72,    73,
      73,    74,    74,    74,    74,    75,    75,    76,    76,    76,
      77,    77,    77,    77,    78,    78,    79,    79,    79,    80,
      80,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     2,     0,     2,     2,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     6,     2,     3,     4,
       5,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     1,     3,     3,     3,     0,     1,     3,
       3,     0,     1,     3,     4,     2,     3,     4,     1,     1,
       1,     1,     1,     1,     6,     2,     3,     4,     5,     6,
       4,     2,     3,     4,     4,     2,     3,     4,     5,     2,
       3,     4,     5,     1,     3,     3,     5,     3,     3,     5,
       5,     2,     3,     4,     5,     1,     2,     3,     2,     3,
       5,     2,     3,     4,     5,     2,     3,     4,     5,     1,
       2,     6,     2,     3,     4,     1,     1,     0,     1,     3,
       1,     3,     3,     2,     2,     3,     3,     2,     3,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       3,     0,     7,     1,     0,     4,     0,     6,     5,    15,
       0,     0,     0,     0,     0,     0,     8,     9,    10,    11,
      12,    14,    13,    17,    22,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,     0,     0,     0,    23,    24,
      61,    62,    63,    55,    58,    59,     0,    60,    79,     0,
      91,     0,   105,     0,   101,     0,    65,     0,    71,     0,
      75,     0,    18,     0,    56,     0,    80,     0,    92,     0,
     106,     0,   102,     0,    66,     0,    72,     0,    76,     0,
      19,     0,    57,    54,    81,    83,     0,    93,     0,     0,
      95,   107,   116,   115,     0,   109,     0,   103,     0,    67,
       0,    73,    70,    77,    74,    20,    37,    35,    36,    34,
      47,    42,    51,     0,    40,    39,    38,     0,    82,     0,
      78,    98,     0,    94,    90,    96,   108,   104,   110,   112,
       0,   100,    68,     0,    48,     0,     0,     0,    43,    52,
       0,    21,    16,    87,    84,    88,    85,    99,    97,   113,
       0,    69,    64,    46,     0,     0,     0,    41,     0,    50,
       0,   114,     0,     0,     0,     0,   120,     0,    49,    45,
      44,    53,    89,    86,   127,   129,   130,   131,     0,   124,
       0,   123,     0,     0,   128,   126,   111,   122,   121,   125
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     1,     2,     5,     6,    16,    17,    37,    45,   136,
     114,   137,   138,   115,   135,   116,   140,    18,    88,    47,
      40,    41,    42,    19,    86,    20,    89,    90,    21,    22,
      94,    95,    96,   164,   165,   166,   167,   178
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -81
static const short yypact[] =
{
     -81,   114,   126,   -81,    92,   -81,   181,   -81,   -81,   -81,
     228,   248,    34,    94,    97,    98,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,    91,   105,   117,   101,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   102,   -81,   -81,    23,
     -81,    24,   -81,    35,   -81,    56,   -81,   268,   -81,   288,
     -81,   308,   -81,   107,   -81,     2,   -81,   110,   -81,   328,
     -81,   208,   -81,   119,   -81,    19,   -81,     6,   -81,    76,
     -81,    75,   -81,   -81,   -81,    -3,     4,   -81,   147,   150,
     -81,   -81,   -81,   -81,   116,   -81,   171,   -81,   153,   -81,
     348,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
      80,    80,    80,     7,   -81,   -81,   -81,    26,   -81,   182,
     -81,   -81,     9,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
       8,   -81,   -81,    89,   -81,    18,   118,   154,   -81,   -81,
      -8,   -81,   -81,   -81,   -81,   -81,   109,   -81,   -81,   -81,
       3,   -81,   -81,   -81,    80,    80,    80,   -81,    80,   -81,
      28,   -81,   166,   170,   146,    54,   149,   362,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,     1,   -81,
     151,   -81,    53,   189,   -81,   -81,   -81,   -81,   155,   -81
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
     -81,   -81,   -81,   -81,   124,   -81,   -81,   -81,   188,   -80,
     -81,   -81,    43,   -81,   -81,   -81,   -81,   -81,   -11,   190,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   112,   -81,   -81,
     -81,   108,   -81,   -81,   -81,    30,   -81,   -81
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -120
static const short yytable[] =
{
      46,   113,   184,    82,   161,   118,    44,   101,   141,   149,
     147,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      99,    34,    35,    36,    66,    68,   158,   143,   117,   172,
     134,   144,   139,   173,   159,    48,    70,    49,   119,   102,
     120,  -117,    83,   185,   162,   150,    75,   142,    77,   148,
      79,   153,   154,   100,   187,   181,    44,    72,    67,    69,
      93,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      71,    34,    35,    36,   168,   169,   105,   103,   171,   106,
     107,   108,   109,    93,   106,   107,   108,   109,   182,   133,
     151,    73,    56,     7,   162,    50,     8,    51,    52,    54,
      53,    55,    62,    64,    63,    65,    58,   110,    80,   104,
     111,    84,   110,    85,     3,   111,   112,   126,    60,    44,
      97,   112,   152,    57,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    92,    34,    35,    36,    59,    81,   163,
     160,    -7,    -7,    -7,    -7,    -7,    -7,     4,   121,    61,
     122,   123,   127,    44,     9,    -7,   183,   155,    25,    26,
      27,    28,    29,    30,    31,    32,    33,   174,    34,    35,
      36,   163,   129,   179,   130,    10,    11,    12,    13,    14,
      15,    -2,     9,   145,   180,   146,   124,  -118,   156,   131,
     157,   186,   189,  -119,   175,   176,   177,    98,    38,   170,
      39,   125,   128,    10,    11,    12,    13,    14,    15,    91,
       0,    44,   188,     0,     0,     0,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    92,    34,    35,    36,    23,
       0,    24,     0,     0,     0,     0,    25,    26,    27,    28,
      29,    30,    31,    32,    33,     0,    34,    35,    36,    43,
       0,    44,     0,     0,     0,     0,    25,    26,    27,    28,
      29,    30,    31,    32,    33,     0,    34,    35,    36,    74,
       0,    44,     0,     0,     0,     0,    25,    26,    27,    28,
      29,    30,    31,    32,    33,     0,    34,    35,    36,    76,
       0,    44,     0,     0,     0,     0,    25,    26,    27,    28,
      29,    30,    31,    32,    33,     0,    34,    35,    36,    78,
       0,    44,     0,     0,     0,     0,    25,    26,    27,    28,
      29,    30,    31,    32,    33,     0,    34,    35,    36,    87,
       0,    44,     0,     0,     0,     0,    25,    26,    27,    28,
      29,    30,    31,    32,    33,     0,    34,    35,    36,   132,
       0,    44,     0,     0,     0,     0,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    44,    34,    35,    36,     0,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     0,
      34,    35,    36
};

static const short yycheck[] =
{
      11,    81,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       1,    18,    19,    20,     1,     1,    34,     1,    31,     1,
     110,     5,   112,     5,    42,     1,     1,     3,    34,    33,
      36,    38,    40,    42,    41,    37,    57,    40,    59,    40,
      61,    33,    34,    34,     1,     1,     3,     1,    35,    35,
      71,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      35,    18,    19,    20,   154,   155,     1,     1,   158,     4,
       5,     6,     7,    94,     4,     5,     6,     7,    34,   100,
       1,    35,     1,     1,    41,     1,     4,     3,     1,     1,
       3,     3,     1,     1,     3,     3,     1,    32,     1,    33,
      35,     1,    32,     3,     0,    35,    41,     1,     1,     3,
       1,    41,    33,    32,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    32,    31,   150,
      31,    22,    23,    24,    25,    26,    27,    21,     1,    32,
       3,     1,    36,     3,     1,    36,   167,    39,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     1,    18,    19,
      20,   182,     1,     3,     3,    22,    23,    24,    25,    26,
      27,     0,     1,     1,    38,     3,    36,    38,    34,    36,
      36,    40,     3,    38,    28,    29,    30,    73,    10,   156,
      10,    89,    94,    22,    23,    24,    25,    26,    27,     1,
      -1,     3,   182,    -1,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     1,
      -1,     3,    -1,    -1,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,     1,
      -1,     3,    -1,    -1,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,     1,
      -1,     3,    -1,    -1,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,     1,
      -1,     3,    -1,    -1,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,     1,
      -1,     3,    -1,    -1,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,     1,
      -1,     3,    -1,    -1,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,     1,
      -1,     3,    -1,    -1,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     3,    18,    19,    20,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      18,    19,    20
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    44,    45,     0,    21,    46,    47,     1,     4,     1,
      22,    23,    24,    25,    26,    27,    48,    49,    60,    66,
      68,    71,    72,     1,     3,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    18,    19,    20,    50,    51,    62,
      63,    64,    65,     1,     3,    51,    61,    62,     1,     3,
       1,     3,     1,     3,     1,     3,     1,    32,     1,    32,
       1,    32,     1,     3,     1,     3,     1,    35,     1,    35,
       1,    35,     1,    35,     1,    61,     1,    61,     1,    61,
       1,    31,     1,    40,     1,     3,    67,     1,    61,    69,
      70,     1,    17,    61,    73,    74,    75,     1,    47,     1,
      34,     1,    33,     1,    33,     1,     4,     5,     6,     7,
      32,    35,    41,    52,    53,    56,    58,    31,     1,    34,
      36,     1,     3,     1,    36,    70,     1,    36,    74,     1,
       3,    36,     1,    61,    52,    57,    52,    54,    55,    52,
      59,     1,    40,     1,     5,     1,     3,     1,    40,     1,
      37,     1,    33,    33,    34,    39,    34,    36,    34,    42,
      31,     1,    41,    61,    76,    77,    78,    79,    52,    52,
      55,    52,     1,     5,     1,    28,    29,    30,    80,     3,
      38,     1,    34,    61,     1,    42,    40,     1,    78,     3
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
   ((Current).first_line   = (Rhs)[1].first_line,	\
    (Current).first_column = (Rhs)[1].first_column,	\
    (Current).last_line    = (Rhs)[N].last_line,	\
    (Current).last_column  = (Rhs)[N].last_column)
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value, Location);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if defined (YYMAXDEPTH) && YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;
  (void) yylocationp;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yytype, yyvaluep, yylocationp)
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;
  (void) yylocationp;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  YYLTYPE *yylerrsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
  *++yylsp = yylloc;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, yylsp - yylen, yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 115 "grammar.y"
    {
	msg_dbg("document \t-> include_clause_list definition_clause_list\n");
	std::vector<BidlType*>::iterator itr;

	for (itr = yyvsp[-1].bidltype_vector->begin(); itr != yyvsp[-1].bidltype_vector->end(); ++itr) {
		g_parseresult->bt->append(*itr);
	}
	delete yyvsp[-1].bidltype_vector;

	for (itr = yyvsp[0].bidltype_vector->begin(); itr != yyvsp[0].bidltype_vector->end(); ++itr) {
		g_parseresult->bt->append(*itr);
	}
	delete yyvsp[0].bidltype_vector;
;}
    break;

  case 3:
#line 133 "grammar.y"
    {
	msg_dbg("include_clause_list \t-> \n");
	yyval.bidltype_vector = new std::vector<BidlType*>();
;}
    break;

  case 4:
#line 138 "grammar.y"
    {
	msg_dbg("include_clause_list \t-> include_clause_list include_clause\n");
	yyval.bidltype_vector = yyvsp[-1].bidltype_vector;
	yyval.bidltype_vector->push_back(yyvsp[0].bidltype);
;}
    break;

  case 5:
#line 147 "grammar.y"
    {
	msg_dbg("include_clause	\t-> include %s\n", yyvsp[0].szstr);
	
	g_parseresult->include_bidls.push_back(yyvsp[0].szstr);
	yyval.bidltype = new BidlInclude;
	yyval.bidltype->set_name(yyvsp[0].szstr);

	free(yyvsp[-1].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 6:
#line 158 "grammar.y"
    {
	myerror("%s: %d : error: expect literal after `include'\n", g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 7:
#line 165 "grammar.y"
    {
	msg_dbg("definition_clause_list \t-> \n");
	yyval.bidltype_vector = new std::vector<BidlType*>();
;}
    break;

  case 8:
#line 170 "grammar.y"
    {
	msg_dbg("definition_clause_list \t-> definition_clause_list definition_clause\n");
	yyval.bidltype_vector = yyvsp[-1].bidltype_vector;
	yyval.bidltype_vector->push_back(yyvsp[0].bidltype);
;}
    break;

  case 9:
#line 179 "grammar.y"
    {
	msg_dbg("definition_clause \t-> const_clause\n");
;}
    break;

  case 10:
#line 183 "grammar.y"
    {
	msg_dbg("definition_clause \t-> typedef_clause\n");
;}
    break;

  case 11:
#line 187 "grammar.y"
    {
	msg_dbg("definition_clause \t-> enum_clause\n");
;}
    break;

  case 12:
#line 191 "grammar.y"
    {
	msg_dbg("definition_clause \t-> struct_clause\n");
;}
    break;

  case 13:
#line 195 "grammar.y"
    {
	msg_dbg("definition_clause \t-> class_clause\n");
;}
    break;

  case 14:
#line 199 "grammar.y"
    {
	msg_dbg("definition_clause \t-> namespace_clause\n");
;}
    break;

  case 15:
#line 203 "grammar.y"
    {
	myerror("%s: %d: error: invalid definition clause\n"
			"\t expect include/const/typedef/enum/struct/class/namespace\n",
			g_cur_bidl_file_name.c_str(),
			yylineno);
;}
    break;

  case 16:
#line 213 "grammar.y"
    {
	msg_dbg("const_clause \t-> const const_type %s = const_value ;\n", yyvsp[-3].szstr);

	BidlConst* t = new BidlConst;
	t->set_line(yylsp[-5].first_line);
	t->set_filename(g_cur_bidl_file_name);
	t->set_name(yyvsp[-3].szstr);
	t->set_field_type(yyvsp[-4].bidltype);
	t->set_value(yyvsp[-1].bidltype);

	yyval.bidltype = t;
	
	free(yyvsp[-5].szstr);
	free(yyvsp[-3].szstr);
	free(yyvsp[-2].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 17:
#line 231 "grammar.y"
    {
	myerror("%s: %d: error: expect a type name after `const'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 18:
#line 236 "grammar.y"
    {
	myerror("%s: %d: error: expect a identifier after `%s'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line, "SEAT");
;}
    break;

  case 19:
#line 241 "grammar.y"
    {
	myerror("%s: %d: error: expect `=' after identifier `%s'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line, yyvsp[-1].szstr);
;}
    break;

  case 20:
#line 246 "grammar.y"
    {
	myerror("%s: %d: error: expect const value after `='\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 21:
#line 251 "grammar.y"
    {
	myerror("%s: %d: error: expect `;' after const value\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 22:
#line 259 "grammar.y"
    {
	msg_dbg("const_type \t-> %s\n", yyvsp[0].szstr);
	BidlIdentifier* t = new BidlIdentifier(yyvsp[0].szstr);
    t->set_line(yylsp[0].first_line);
    t->set_filename(g_cur_bidl_file_name);
	yyval.bidltype = t;

	free(yyvsp[0].szstr);
;}
    break;

  case 23:
#line 269 "grammar.y"
    {
	msg_dbg("const_type \t-> basic_type\n");
	yyval.bidltype = yyvsp[0].bidltype;
;}
    break;

  case 24:
#line 274 "grammar.y"
    {
	msg_dbg("const_type \t-> container_type\n");
	yyval.bidltype = yyvsp[0].bidltype;
;}
    break;

  case 25:
#line 282 "grammar.y"
    {
	msg_dbg("basic_type \t-> boolean\n");
	yyval.bidltype = new BidlBoolean;
	free(yyvsp[0].szstr);
;}
    break;

  case 26:
#line 288 "grammar.y"
    {
	msg_dbg("basic_type \t-> int8\n");
	yyval.bidltype = new BidlInt8;
	free(yyvsp[0].szstr);
;}
    break;

  case 27:
#line 294 "grammar.y"
    {
	msg_dbg("basic_type \t-> int16\n");
	yyval.bidltype = new BidlInt16;
	free(yyvsp[0].szstr);
;}
    break;

  case 28:
#line 300 "grammar.y"
    {
	msg_dbg("basic_type \t-> int32\n");
	yyval.bidltype = new BidlInt32;
	free(yyvsp[0].szstr);
;}
    break;

  case 29:
#line 306 "grammar.y"
    {
	msg_dbg("basic_type \t-> int64\n");
	yyval.bidltype = new BidlInt64;
	free(yyvsp[0].szstr);
;}
    break;

  case 30:
#line 312 "grammar.y"
    {
	msg_dbg("basic_type \t-> float\n");
	yyval.bidltype = new BidlFloat;
	free(yyvsp[0].szstr);
;}
    break;

  case 31:
#line 318 "grammar.y"
    {
	msg_dbg("basic_type \t-> double\n");
	yyval.bidltype = new BidlDouble;
	free(yyvsp[0].szstr);
;}
    break;

  case 32:
#line 324 "grammar.y"
    {
	msg_dbg("basic_type \t-> string\n");
	yyval.bidltype = new BidlString;
	free(yyvsp[0].szstr);
;}
    break;

  case 33:
#line 330 "grammar.y"
    {
	msg_dbg("basic_type \t-> binary\n");
	yyval.bidltype = new BidlBinary;
	free(yyvsp[0].szstr);
;}
    break;

  case 34:
#line 339 "grammar.y"
    {
	msg_dbg("const_value \t-> %s\n", yyvsp[0].boolval?"true":"false");
	yyval.bidltype = new BidlConstBoolean(yyvsp[0].boolval);
;}
    break;

  case 35:
#line 344 "grammar.y"
    {
	msg_dbg("const_value \t-> %d\n", atoi(yyvsp[0].szstr));
	yyval.bidltype = new BidlConstInteger(yyvsp[0].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 36:
#line 350 "grammar.y"
    {
	msg_dbg("const_value \t-> %f\n", atof(yyvsp[0].szstr));
	yyval.bidltype = new BidlConstDecimal(yyvsp[0].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 37:
#line 356 "grammar.y"
    {
	msg_dbg("const_value \t-> %s\n", yyvsp[0].szstr);
	yyval.bidltype = new BidlConstLiteral(yyvsp[0].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 38:
#line 362 "grammar.y"
    {
	msg_dbg("const_value \t-> const_sequence\n");
	yyval.bidltype = yyvsp[0].bidltype;
;}
    break;

  case 39:
#line 367 "grammar.y"
    {
	msg_dbg("const_value \t-> const_set\n");
	yyval.bidltype = yyvsp[0].bidltype;
;}
    break;

  case 40:
#line 372 "grammar.y"
    {
	msg_dbg("const_value \t->const_map\n");
	yyval.bidltype = yyvsp[0].bidltype;
;}
    break;

  case 41:
#line 380 "grammar.y"
    {
	msg_dbg("const_map \t-> { const_map_field_list }\n");
	yyval.bidltype = new BidlMap;
	std::vector<BidlType*>::iterator itr;
	for (itr = yyvsp[-1].bidltype_vector->begin(); itr != yyvsp[-1].bidltype_vector->end(); ++itr) {
		yyval.bidltype->append(*itr);
	}
	delete yyvsp[-1].bidltype_vector;
	free(yyvsp[-2].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 42:
#line 395 "grammar.y"
    {
	yyval.bidltype_vector = new std::vector<BidlType*>();
;}
    break;

  case 43:
#line 399 "grammar.y"
    {
	yyval.bidltype_vector = new std::vector<BidlType*>();
	yyval.bidltype_vector->push_back(yyvsp[0].bidltype);
;}
    break;

  case 44:
#line 404 "grammar.y"
    {
	yyval.bidltype_vector = yyvsp[-2].bidltype_vector;
	yyval.bidltype_vector->push_back(yyvsp[0].bidltype);
	free(yyvsp[-1].szstr);
;}
    break;

  case 45:
#line 413 "grammar.y"
    {
	BidlMap* tmp = new BidlMap;
	tmp->set_key_type(yyvsp[-2].bidltype);
	tmp->set_value_type(yyvsp[0].bidltype);
	yyval.bidltype = tmp;
	free(yyvsp[-1].szstr);
;}
    break;

  case 46:
#line 424 "grammar.y"
    {
	yyval.bidltype = new BidlConstSet;
	std::vector<BidlType*>::iterator itr;
	for (itr = yyvsp[-1].bidltype_vector->begin(); itr != yyvsp[-1].bidltype_vector->end(); ++itr) {
		yyval.bidltype->append(*itr);
	}
	delete yyvsp[-1].bidltype_vector;
	free(yyvsp[-2].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 47:
#line 437 "grammar.y"
    {
	yyval.bidltype_vector = new std::vector<BidlType*>();
;}
    break;

  case 48:
#line 441 "grammar.y"
    {
	yyval.bidltype_vector = new std::vector<BidlType*>();
	yyval.bidltype_vector->push_back(yyvsp[0].bidltype);
;}
    break;

  case 49:
#line 446 "grammar.y"
    {
	yyval.bidltype_vector = yyvsp[-2].bidltype_vector;
	yyval.bidltype_vector->push_back(yyvsp[0].bidltype);
	free(yyvsp[-1].szstr);
;}
    break;

  case 50:
#line 455 "grammar.y"
    {
	yyval.bidltype = new BidlConstSequence;
	std::vector<BidlType*>::iterator itr;
	for (itr = yyvsp[-1].bidltype_vector->begin(); itr != yyvsp[-1].bidltype_vector->end(); ++itr) {
		yyval.bidltype->append(*itr);
	}
	delete yyvsp[-1].bidltype_vector;
	free(yyvsp[-2].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 51:
#line 468 "grammar.y"
    {
	yyval.bidltype_vector = new std::vector<BidlType*>();
;}
    break;

  case 52:
#line 472 "grammar.y"
    {
	yyval.bidltype_vector = new std::vector<BidlType*>();
	yyval.bidltype_vector->push_back(yyvsp[0].bidltype);
;}
    break;

  case 53:
#line 477 "grammar.y"
    {
	yyval.bidltype_vector = yyvsp[-2].bidltype_vector;
	yyval.bidltype_vector->push_back(yyvsp[0].bidltype);
	free(yyvsp[-1].szstr);
;}
    break;

  case 54:
#line 486 "grammar.y"
    {
	msg_dbg("typedef_clause \t-> typedef data_type %s ;\n", yyvsp[-1].szstr);
	
	BidlTypedef* t = new BidlTypedef;
	t->set_sub_type(yyvsp[-2].bidltype);
	t->set_name(yyvsp[-1].szstr);
	t->set_line(yylsp[-1].first_line);
	t->set_filename(g_cur_bidl_file_name);
	yyval.bidltype = t;

	free(yyvsp[-3].szstr);
	free(yyvsp[-1].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 55:
#line 501 "grammar.y"
    {
	myerror("%s: %d: error: expect data type after `typedef'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 56:
#line 506 "grammar.y"
    {
	myerror("%s: %d: error: expect identifier after %s\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line, "SEAT");
;}
    break;

  case 57:
#line 511 "grammar.y"
    {
	myerror("%s: %d: error: expect `;' after `%s'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line, yyvsp[-1].szstr);
;}
    break;

  case 58:
#line 519 "grammar.y"
    {
	msg_dbg("data_type \t-> %s\n", yyvsp[0].szstr);
	//TODO: to search id
	yyval.bidltype = new BidlIdentifier(yyvsp[0].szstr);
    yyval.bidltype->set_line(yylsp[0].first_line);
    yyval.bidltype->set_filename(g_cur_bidl_file_name);
	free(yyvsp[0].szstr);
;}
    break;

  case 59:
#line 528 "grammar.y"
    {
	msg_dbg("data_type \t-> basic_type\n");
;}
    break;

  case 60:
#line 532 "grammar.y"
    {
	msg_dbg("data_type \t-> container_type\n");
;}
    break;

  case 61:
#line 539 "grammar.y"
    {
	msg_dbg("container_type \t-> map_type\n");
;}
    break;

  case 62:
#line 543 "grammar.y"
    {
	msg_dbg("container_type \t-> set_type\n");
;}
    break;

  case 63:
#line 547 "grammar.y"
    {
	msg_dbg("container_type \t-> sequence_type\n");
;}
    break;

  case 64:
#line 554 "grammar.y"
    {
	msg_dbg("map_type \t-> map<data_type, data_type>\n");
	BidlMap* t = new BidlMap;
	t->set_key_type(yyvsp[-3].bidltype);
	t->set_value_type(yyvsp[-1].bidltype);
	yyval.bidltype = t;

	free(yyvsp[-5].szstr);
	free(yyvsp[-4].szstr);
	free(yyvsp[-2].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 65:
#line 567 "grammar.y"
    {
	myerror("%s: %d: error: expect `<' after `map'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 66:
#line 572 "grammar.y"
    {
	myerror("%s: %d: error: expect key type after `<'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 67:
#line 577 "grammar.y"
    {
	myerror("%s: %d: error: expect `,' after `%s'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line, "SEAT");
;}
    break;

  case 68:
#line 582 "grammar.y"
    {
	myerror("%s: %d: error: expect value type after `,'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 69:
#line 587 "grammar.y"
    {
	myerror("%s: %d: error: expect `>' after `%s'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line, "SEAT");
;}
    break;

  case 70:
#line 595 "grammar.y"
    {
	msg_dbg("set_type \t-> set<data_type>\n");
	BidlSet* t = new BidlSet;
	t->set_sub_type(yyvsp[-1].bidltype);
	yyval.bidltype = t;

	free(yyvsp[-3].szstr);
	free(yyvsp[-2].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 71:
#line 606 "grammar.y"
    {
	myerror("%s: %d: error: expect `<' after `set'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 72:
#line 611 "grammar.y"
    {
	myerror("%s: %d: error: expect data type after `<'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 73:
#line 616 "grammar.y"
    {
	myerror("%s: %d: error: expect `>' after `%s'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line, "SEAT");
;}
    break;

  case 74:
#line 624 "grammar.y"
    {
	msg_dbg("sequence_type \t-> sequence<data_type>\n");
	BidlSequence* t = new BidlSequence;
	t->set_sub_type(yyvsp[-1].bidltype);
	yyval.bidltype = t;

	free(yyvsp[-3].szstr);
	free(yyvsp[-2].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 75:
#line 635 "grammar.y"
    {
	myerror("%s: %d: error: expect `<' after `sequence'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 76:
#line 640 "grammar.y"
    {
	myerror("%s: %d: error: expect data type after `<'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 77:
#line 645 "grammar.y"
    {
	myerror("%s: %d: error: expect `>' after `%s'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line, "SEAT");
;}
    break;

  case 78:
#line 653 "grammar.y"
    {
	msg_dbg("enum_clause \t-> enum %s { enum_field_list }\n", yyvsp[-3].szstr);
	yyval.bidltype = yyvsp[-1].bidltype;
	if (!is_c_identifier(yyvsp[-3].szstr)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			yylsp[-3].first_line,
			yyvsp[-3].szstr);
	}
	yyval.bidltype->set_name(yyvsp[-3].szstr);
	yyval.bidltype->set_line(yylsp[-3].first_line);
	yyval.bidltype->set_filename(g_cur_bidl_file_name);
	free(yyvsp[-4].szstr);
	free(yyvsp[-3].szstr);
	free(yyvsp[-2].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 79:
#line 671 "grammar.y"
    {
	myerror("%s: %d: error: expect identifier after `enum'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 80:
#line 676 "grammar.y"
    {
	myerror("%s: %d: error: expect `{' after `%s'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line, yyvsp[-1].szstr);
;}
    break;

  case 81:
#line 681 "grammar.y"
    {
	myerror("%s: %d: error: invalid enum field(s)\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 82:
#line 686 "grammar.y"
    {
	myerror("%s: %d: error: expect `}' or `,' after enum fields\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].last_line);
;}
    break;

  case 83:
#line 694 "grammar.y"
    {
	if (!is_c_identifier(yyvsp[0].szstr)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			yylsp[0].first_line,
			yyvsp[0].szstr);
	}
	msg_dbg("enum_field_list \t-> %s\n", yyvsp[0].szstr);
	BidlEnumField* f = new BidlEnumField(yyvsp[0].szstr);
	f->set_line(yylsp[0].first_line);
	f->set_filename(g_cur_bidl_file_name);
	yyval.bidltype = new BidlEnum;
	yyval.bidltype->append(f);
	free(yyvsp[0].szstr);
;}
    break;

  case 84:
#line 710 "grammar.y"
    {
	msg_dbg("enum_field_list \t-> %s = %d\n", yyvsp[-2].szstr, atoi(yyvsp[0].szstr));
	//TODO: check integer 
	if (!is_c_identifier(yyvsp[-2].szstr)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			yylsp[-2].first_line,
			yyvsp[-2].szstr);
	}
	BidlEnumField* f = new BidlEnumField(yyvsp[-2].szstr, atoi(yyvsp[0].szstr));
	f->set_line(yylsp[-2].first_line);
	f->set_filename(g_cur_bidl_file_name);
	yyval.bidltype = new BidlEnum;
	yyval.bidltype->append(f);
	free(yyvsp[-2].szstr);
	free(yyvsp[-1].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 85:
#line 729 "grammar.y"
    {
	yyval.bidltype = yyvsp[-2].bidltype;
	if (!is_c_identifier(yyvsp[0].szstr)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			yylsp[0].first_line,
			yyvsp[0].szstr);
	}
	BidlEnumField* f = new BidlEnumField(yyvsp[0].szstr);
	f->set_line(yylsp[0].first_line);
	f->set_filename(g_cur_bidl_file_name);
	yyval.bidltype->append(f);
	msg_dbg("enum_field_list \t-> enum_field_list, %s\n", yyvsp[0].szstr);
	free(yyvsp[-1].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 86:
#line 746 "grammar.y"
    {
	yyval.bidltype = yyvsp[-4].bidltype;
	//TODO:check integer
	if (!is_c_identifier(yyvsp[-2].szstr)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			yylsp[-2].first_line,
			yyvsp[-2].szstr);
	}
	BidlEnumField* f = new BidlEnumField(yyvsp[-2].szstr, atoi(yyvsp[0].szstr));
	f->set_line(yylsp[-2].first_line);
	f->set_filename(g_cur_bidl_file_name);
	yyval.bidltype->append(f);
	msg_dbg("enum_field_list \t-> enum_field_list, %s = %d\n", yyvsp[-2].szstr, atoi(yyvsp[0].szstr));
	free(yyvsp[-3].szstr);
	free(yyvsp[-2].szstr);
	free(yyvsp[-1].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 87:
#line 766 "grammar.y"
    {
	myerror("%s: %d: error: expect integer after `='\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 88:
#line 771 "grammar.y"
    {
	myerror("%s: %d: error: expect identifier after `,'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 89:
#line 776 "grammar.y"
    {
	myerror("%s: %d: error: expect integer after `='\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 90:
#line 784 "grammar.y"
    {
	msg_dbg("struct_clause \t-> struct %s { struct_field_list }\n", yyvsp[-3].szstr);
	yyval.bidltype = yyvsp[-1].bidltype;
	if (!is_c_identifier(yyvsp[-3].szstr)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			yylsp[-3].first_line,
			yyvsp[-3].szstr);
	}
	yyval.bidltype->set_name(yyvsp[-3].szstr);
	yyval.bidltype->set_line(yylsp[-3].first_line);
	yyval.bidltype->set_filename(g_cur_bidl_file_name);
	free(yyvsp[-4].szstr);
	free(yyvsp[-3].szstr);
	free(yyvsp[-2].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 91:
#line 802 "grammar.y"
    {
	myerror("%s: %d: error: expect identifier after `struct'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 92:
#line 807 "grammar.y"
    {
	myerror("%s: %d: error: expect `{' after `%s'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line, yyvsp[-1].szstr);
;}
    break;

  case 93:
#line 812 "grammar.y"
    {
	myerror("%s: %d: error: invalid struct field after `{'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 94:
#line 817 "grammar.y"
    {
	myerror("line: %d: error: expect `}' after `%s'\n", yylsp[-1].last_line, "SEAT");
;}
    break;

  case 95:
#line 824 "grammar.y"
    {
	msg_dbg("struct_field_list \t-> struct_field\n");
	yyval.bidltype = new BidlStruct;
	yyval.bidltype->append(yyvsp[0].bidltype);
;}
    break;

  case 96:
#line 830 "grammar.y"
    {
	msg_dbg("struct_field_list \t-> struct_field_list struct_field\n");
	yyval.bidltype = yyvsp[-1].bidltype;
	yyval.bidltype->append(yyvsp[0].bidltype);
;}
    break;

  case 97:
#line 839 "grammar.y"
    {
	msg_dbg("struct_field \t-> data_type %s;\n", yyvsp[-1].szstr);
	if (!is_c_identifier(yyvsp[-1].szstr)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			yylsp[-1].first_line,
			yyvsp[-1].szstr);
	}
	BidlStructField* t = new BidlStructField(yyvsp[-1].szstr);
	t->set_field_type(yyvsp[-2].bidltype);
	t->set_line(yylsp[-1].first_line);
	t->set_filename(g_cur_bidl_file_name);
	yyval.bidltype = t;
	
	free(yyvsp[-1].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 98:
#line 857 "grammar.y"
    {
	myerror("%s: %d: error: expect identifier after `%s'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line, "SEAT");
;}
    break;

  case 99:
#line 862 "grammar.y"
    {
	myerror("%s: %d: error: expect `;' after `%s'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line, yyvsp[-1].szstr);
;}
    break;

  case 100:
#line 869 "grammar.y"
    {
	msg_dbg("namespace_clause \t-> namespace %s { definition_clause_list }\n", yyvsp[-3].szstr);
	yyval.bidltype = new BidlNamespace;

	if (!is_c_identifier(yyvsp[-3].szstr)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			yylsp[-3].first_line,
			yyvsp[-3].szstr);
	}

	yyval.bidltype->set_name(yyvsp[-3].szstr);
	yyval.bidltype->coordination.line = yylsp[-3].first_line;
	yyval.bidltype->coordination.column = yylsp[-3].first_column;
	yyval.bidltype->coordination.filename = g_cur_bidl_file_name;

	std::vector<BidlType*>::iterator itr;
	for (itr = yyvsp[-1].bidltype_vector->begin(); itr != yyvsp[-1].bidltype_vector->end(); ++itr) {
		yyval.bidltype->append(*itr);
	}
	delete yyvsp[-1].bidltype_vector;

	free(yyvsp[-4].szstr);
	free(yyvsp[-3].szstr);
	free(yyvsp[-2].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 101:
#line 897 "grammar.y"
    {
	myerror("%s: %d: error: expect identifier after `namespace'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 102:
#line 902 "grammar.y"
    {
	myerror("%s: %d: error: expect `{' after `%s'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line, yyvsp[-1].szstr);
;}
    break;

  case 103:
#line 907 "grammar.y"
    {
	myerror("%s: %d: error: invalid definition clause after `{' or missing `}'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 104:
#line 915 "grammar.y"
    {
	msg_dbg("class_clause \t-> class %s { function_list }\n", yyvsp[-3].szstr);
	yyval.bidltype = new BidlClass;
	if (!is_c_identifier(yyvsp[-3].szstr)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			yylsp[-3].first_line,
			yyvsp[-3].szstr);
	}
	yyval.bidltype->set_name(yyvsp[-3].szstr);
	yyval.bidltype->set_line(yylsp[-3].first_line);
	yyval.bidltype->set_filename(g_cur_bidl_file_name);

	std::vector<BidlType*>::iterator itr;
	for (itr = yyvsp[-1].bidltype_vector->begin(); itr != yyvsp[-1].bidltype_vector->end(); ++itr) {
		yyval.bidltype->append(*itr);
	}
	delete yyvsp[-1].bidltype_vector;

	free(yyvsp[-4].szstr);
	free(yyvsp[-3].szstr);
	free(yyvsp[-2].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 105:
#line 940 "grammar.y"
    {
	myerror("%s: %d: error: expect identifier after `class'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 106:
#line 945 "grammar.y"
    {
	myerror("%s: %d: error: expect `{' after `%s'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line, yyvsp[-1].szstr);
;}
    break;

  case 107:
#line 950 "grammar.y"
    {
	myerror("%s: %d: error: invalid function list after `{'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 108:
#line 955 "grammar.y"
    {
	myerror("%s: %d: error: expect `}'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].last_line);
;}
    break;

  case 109:
#line 963 "grammar.y"
    {
	yyval.bidltype_vector = new std::vector<BidlType*>();
	yyval.bidltype_vector->push_back(yyvsp[0].bidltype);
;}
    break;

  case 110:
#line 968 "grammar.y"
    {
	yyval.bidltype_vector->push_back(yyvsp[0].bidltype);
;}
    break;

  case 111:
#line 975 "grammar.y"
    {
	msg_dbg("function \t-> function_type %s(function_field_list);\n", yyvsp[-4].szstr);
	BidlFunction* t = new BidlFunction;
	if (!is_c_identifier(yyvsp[-4].szstr)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			yylsp[-4].first_line,
			yyvsp[-4].szstr);
	}
	t->set_name(yyvsp[-4].szstr);
	t->set_return_type(yyvsp[-5].bidltype);
	t->set_line(yylsp[-4].first_line);
	t->set_filename(g_cur_bidl_file_name);

	std::vector<BidlType*>::iterator itr;
	for (itr = yyvsp[-2].bidltype_vector->begin(); itr != yyvsp[-2].bidltype_vector->end(); ++itr) {
		t->append(*itr);
	}
	delete yyvsp[-2].bidltype_vector;

	yyval.bidltype = t;
	free(yyvsp[-4].szstr);
	free(yyvsp[-3].szstr);
	free(yyvsp[-1].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 112:
#line 1002 "grammar.y"
    {
	myerror("%s: %d: error: expect identifier after function_type `%s'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line, "SEAT");
;}
    break;

  case 113:
#line 1007 "grammar.y"
    {
	myerror("%s: %d: error: expect `(' after `%s'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line, yyvsp[-1].szstr);
;}
    break;

  case 114:
#line 1012 "grammar.y"
    {
	myerror("%s: %d: error: invalid function field list after `('\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 116:
#line 1021 "grammar.y"
    {
	yyval.bidltype = new BidlVoid;
	free(yyvsp[0].szstr);
;}
    break;

  case 117:
#line 1029 "grammar.y"
    {
	yyval.bidltype_vector = new std::vector<BidlType*>();
;}
    break;

  case 118:
#line 1033 "grammar.y"
    {
	yyval.bidltype_vector = new std::vector<BidlType*>();
	yyval.bidltype_vector->push_back(yyvsp[0].bidltype);
;}
    break;

  case 119:
#line 1038 "grammar.y"
    {
	yyval.bidltype_vector->push_back(yyvsp[0].bidltype);
	free(yyvsp[-1].szstr);
;}
    break;

  case 120:
#line 1046 "grammar.y"
    {
	yyval.bidltype_vector = new std::vector<BidlType*>();
	yyval.bidltype_vector->push_back(yyvsp[0].bidltype);
;}
    break;

  case 121:
#line 1051 "grammar.y"
    {
	yyval.bidltype_vector->push_back(yyvsp[0].bidltype);
	free(yyvsp[-1].szstr);
;}
    break;

  case 122:
#line 1056 "grammar.y"
    {
	myerror("%s: %d: error: invalid function field after `,'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 123:
#line 1061 "grammar.y"
    {
	myerror("%s: %d: error: expect `,'",
		g_cur_bidl_file_name.c_str(), yylsp[-1].last_line);
;}
    break;

  case 124:
#line 1069 "grammar.y"
    {
	BidlFunctionField* t = new BidlFunctionField;
	t->set_field_type(yyvsp[-1].bidltype);
	if (!is_c_identifier(yyvsp[0].szstr)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			yylsp[0].first_line,
			yyvsp[0].szstr);
	}
	t->set_name(yyvsp[0].szstr);
	t->set_line(yylsp[0].first_line);
	t->set_filename(g_cur_bidl_file_name);
	yyval.bidltype = t;
	free(yyvsp[0].szstr);

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

;}
    break;

  case 125:
#line 1099 "grammar.y"
    {
	BidlFunctionField* t = new BidlFunctionField;
	t->set_field_direction(yyvsp[-2].bidltype);
	t->set_field_type(yyvsp[-1].bidltype);
	if (!is_c_identifier(yyvsp[0].szstr)) {
		myerror("%s: %d: error: invalid identifier: %s",
			g_cur_bidl_file_name.c_str(),
			yylsp[0].first_line,
			yyvsp[0].szstr);
	}
	t->set_name(yyvsp[0].szstr);
	t->set_line(yylsp[0].first_line);
	t->set_filename(g_cur_bidl_file_name);
	yyval.bidltype = t;
	free(yyvsp[0].szstr);
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
;}
    break;

  case 126:
#line 1132 "grammar.y"
    {
	yyval.bidltype = yyvsp[-1].bidltype;
	free(yyvsp[-2].szstr);
	free(yyvsp[0].szstr);
;}
    break;

  case 127:
#line 1138 "grammar.y"
    {
	myerror("%s: %d: error: expect in/out/all after `['\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line);
;}
    break;

  case 128:
#line 1143 "grammar.y"
    {
	myerror("%s: %d: error: expect `]' after `%s'\n",
		g_cur_bidl_file_name.c_str(), yylsp[-1].first_line, "SEAT");
;}
    break;

  case 129:
#line 1151 "grammar.y"
    {
	BidlFieldDirection* t = new BidlFieldDirection;
	t->set_direction(BidlFieldDirection::IN);
	yyval.bidltype = t;
	free(yyvsp[0].szstr);
;}
    break;

  case 130:
#line 1158 "grammar.y"
    {
	BidlFieldDirection* t = new BidlFieldDirection;
	t->set_direction(BidlFieldDirection::OUT);
	yyval.bidltype = t;
	free(yyvsp[0].szstr);
;}
    break;

  case 131:
#line 1165 "grammar.y"
    {
	BidlFieldDirection* t = new BidlFieldDirection;
	t->set_direction(BidlFieldDirection::ALL);
	yyval.bidltype = t;
	free(yyvsp[0].szstr);
;}
    break;


    }

/* Line 1000 of yacc.c.  */
#line 2684 "grammar.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;
  yylsp -= yylen;

  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }

  yylerrsp = yylsp;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {
		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
		 yydestruct (yystos[*yyssp], yyvsp, yylsp);
	       }
        }
      else
	{
	  YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
	  yydestruct (yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	  *++yylerrsp = yylloc;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

  yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  yylerrsp = yylsp;
  *++yylerrsp = yyloc;
  yylsp -= yylen;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
  YYLLOC_DEFAULT (yyloc, yylsp, yylerrsp - yylsp);
  *++yylsp = yyloc;

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 1173 "grammar.y"


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


