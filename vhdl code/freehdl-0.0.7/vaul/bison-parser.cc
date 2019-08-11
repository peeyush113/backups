
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 35 "bison-parser.yy"


#include <freehdl/vaul-chunk.h>
#include <freehdl/vaul-lexer.h>
#include <freehdl/vaul-parser.h>
#include <freehdl/vaul-dunit.h>
#include <freehdl/vaul-list.h>
#include <freehdl/vaul-util.h>
#include <vaul/vaulgens-chunk.h>

#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#if HAVE_MALLOC_H
#include <malloc.h>
#endif

using namespace std;

#define YYINITDEPTH 10000
#define YYMAXDEPTH 100000

#define yylex(sem, loc) lex->lex(sem, loc)
#define yyparse		vaul_parser::bison_parse
#define yyerror		BisonError

#define YYSTYPE vaul_yystype
#define YYLTYPE vaul_yyltype

/* This is a hack to prevent the bison sceleton to declare a prototype
   for yyparse.  Since yyparse is a qualified name, it can't be used
   in a prototype. */

#define YYPARSE_PARAM dummy

#if 1
// Erweiterte Fehlermeldungen waeren ja ganz schön, aber die
// Namen fuer die Token sind nicht sehr elegant.
#define YYDEBUG 1
#define YYERROR_VERBOSE
#endif

// XXX - tidy up, used only for RANGE attribute resolution

static void
iterate_for_kind (pIIR_Declaration d, void *cl)
{
  IR_Kind &basic_k = *(IR_Kind *)cl;
  IR_Kind this_k = d->kind();
  
  if (basic_k == IR_INVALID)
    basic_k = this_k;
  else if (basic_k != this_k && !tree_is (this_k, basic_k)) 
    {
      while (!tree_is (basic_k, this_k))
	this_k = tree_base (this_k);
      basic_k = this_k;
    }
}



/* Line 189 of yacc.c  */
#line 136 "bison-parser.cc"

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

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     t_ACCESS = 258,
     t_AFTER = 259,
     t_ALIAS = 260,
     t_ALL = 261,
     t_AND = 262,
     t_ARCHITECTURE = 263,
     skip_t_ARCHITECTURE = 264,
     t_ARRAY = 265,
     t_ASSERT = 266,
     t_ATTRIBUTE = 267,
     t_BEGIN = 268,
     t_BLOCK = 269,
     t_BODY = 270,
     skip_t_BODY = 271,
     t_BUFFER = 272,
     t_BUS = 273,
     t_CASE = 274,
     t_COMPONENT = 275,
     t_CONFIGURATION = 276,
     skip_t_CONFIGURATION = 277,
     t_CONSTANT = 278,
     t_DISCONNECT = 279,
     t_DOWNTO = 280,
     t_ELSE = 281,
     t_ELSIF = 282,
     t_END = 283,
     t_ENTITY = 284,
     t_EXIT = 285,
     t_FILE = 286,
     t_FOR = 287,
     t_FUNCTION = 288,
     t_GENERATE = 289,
     t_GENERIC = 290,
     t_GUARDED = 291,
     t_IF = 292,
     t_IMPURE = 293,
     t_IN = 294,
     t_INERTIAL = 295,
     t_INOUT = 296,
     t_IS = 297,
     t_LABEL = 298,
     t_LIBRARY = 299,
     t_LINKAGE = 300,
     t_LOOP = 301,
     t_MAP = 302,
     t_NAND = 303,
     t_NEW = 304,
     t_NEXT = 305,
     t_NOR = 306,
     t_NULL = 307,
     t_OF = 308,
     t_ON = 309,
     t_OPEN = 310,
     t_OR = 311,
     t_OTHERS = 312,
     t_OUT = 313,
     t_PACKAGE = 314,
     t_PORT = 315,
     t_POSTPONED = 316,
     t_PROCEDURE = 317,
     t_PROCESS = 318,
     t_PURE = 319,
     t_RANGE = 320,
     t_REVERSE_RANGE = 321,
     t_RECORD = 322,
     t_REGISTER = 323,
     t_REJECT = 324,
     t_REPORT = 325,
     t_RETURN = 326,
     t_ROL = 327,
     t_ROR = 328,
     t_SELECT = 329,
     t_SEVERITY = 330,
     t_SIGNAL = 331,
     t_SLA = 332,
     t_SLL = 333,
     t_SRA = 334,
     t_SRL = 335,
     t_SUBTYPE = 336,
     t_THEN = 337,
     t_TO = 338,
     t_TRANSPORT = 339,
     t_TYPE = 340,
     t_UNITS = 341,
     t_UNTIL = 342,
     t_USE = 343,
     t_VARIABLE = 344,
     t_WAIT = 345,
     t_WHEN = 346,
     t_WHILE = 347,
     t_WITH = 348,
     t_XNOR = 349,
     t_XOR = 350,
     t_GESym = 351,
     t_GTSym = 352,
     t_LESym = 353,
     t_LTSym = 354,
     t_NESym = 355,
     t_EQSym = 356,
     t_Ampersand = 357,
     t_Minus = 358,
     t_Plus = 359,
     MED_PRECEDENCE = 360,
     t_REM = 361,
     t_MOD = 362,
     t_Slash = 363,
     t_Star = 364,
     MAX_PRECEDENCE = 365,
     t_NOT = 366,
     t_ABS = 367,
     t_DoubleStar = 368,
     t_Apostrophe = 369,
     t_LeftParen = 370,
     t_RightParen = 371,
     t_Comma = 372,
     t_VarAsgn = 373,
     t_Colon = 374,
     t_Semicolon = 375,
     t_Arrow = 376,
     t_Box = 377,
     t_Bar = 378,
     t_Dot = 379,
     t_AbstractLit = 380,
     t_CharacterLit = 381,
     t_Identifier = 382,
     t_StringLit = 383
   };
#endif
/* Tokens.  */
#define t_ACCESS 258
#define t_AFTER 259
#define t_ALIAS 260
#define t_ALL 261
#define t_AND 262
#define t_ARCHITECTURE 263
#define skip_t_ARCHITECTURE 264
#define t_ARRAY 265
#define t_ASSERT 266
#define t_ATTRIBUTE 267
#define t_BEGIN 268
#define t_BLOCK 269
#define t_BODY 270
#define skip_t_BODY 271
#define t_BUFFER 272
#define t_BUS 273
#define t_CASE 274
#define t_COMPONENT 275
#define t_CONFIGURATION 276
#define skip_t_CONFIGURATION 277
#define t_CONSTANT 278
#define t_DISCONNECT 279
#define t_DOWNTO 280
#define t_ELSE 281
#define t_ELSIF 282
#define t_END 283
#define t_ENTITY 284
#define t_EXIT 285
#define t_FILE 286
#define t_FOR 287
#define t_FUNCTION 288
#define t_GENERATE 289
#define t_GENERIC 290
#define t_GUARDED 291
#define t_IF 292
#define t_IMPURE 293
#define t_IN 294
#define t_INERTIAL 295
#define t_INOUT 296
#define t_IS 297
#define t_LABEL 298
#define t_LIBRARY 299
#define t_LINKAGE 300
#define t_LOOP 301
#define t_MAP 302
#define t_NAND 303
#define t_NEW 304
#define t_NEXT 305
#define t_NOR 306
#define t_NULL 307
#define t_OF 308
#define t_ON 309
#define t_OPEN 310
#define t_OR 311
#define t_OTHERS 312
#define t_OUT 313
#define t_PACKAGE 314
#define t_PORT 315
#define t_POSTPONED 316
#define t_PROCEDURE 317
#define t_PROCESS 318
#define t_PURE 319
#define t_RANGE 320
#define t_REVERSE_RANGE 321
#define t_RECORD 322
#define t_REGISTER 323
#define t_REJECT 324
#define t_REPORT 325
#define t_RETURN 326
#define t_ROL 327
#define t_ROR 328
#define t_SELECT 329
#define t_SEVERITY 330
#define t_SIGNAL 331
#define t_SLA 332
#define t_SLL 333
#define t_SRA 334
#define t_SRL 335
#define t_SUBTYPE 336
#define t_THEN 337
#define t_TO 338
#define t_TRANSPORT 339
#define t_TYPE 340
#define t_UNITS 341
#define t_UNTIL 342
#define t_USE 343
#define t_VARIABLE 344
#define t_WAIT 345
#define t_WHEN 346
#define t_WHILE 347
#define t_WITH 348
#define t_XNOR 349
#define t_XOR 350
#define t_GESym 351
#define t_GTSym 352
#define t_LESym 353
#define t_LTSym 354
#define t_NESym 355
#define t_EQSym 356
#define t_Ampersand 357
#define t_Minus 358
#define t_Plus 359
#define MED_PRECEDENCE 360
#define t_REM 361
#define t_MOD 362
#define t_Slash 363
#define t_Star 364
#define MAX_PRECEDENCE 365
#define t_NOT 366
#define t_ABS 367
#define t_DoubleStar 368
#define t_Apostrophe 369
#define t_LeftParen 370
#define t_RightParen 371
#define t_Comma 372
#define t_VarAsgn 373
#define t_Colon 374
#define t_Semicolon 375
#define t_Arrow 376
#define t_Box 377
#define t_Bar 378
#define t_Dot 379
#define t_AbstractLit 380
#define t_CharacterLit 381
#define t_Identifier 382
#define t_StringLit 383




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
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


/* Line 264 of yacc.c  */
#line 446 "bison-parser.cc"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2290

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  129
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  575
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1136
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1922

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   383

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    10,    12,    14,    16,
      18,    20,    22,    24,    27,    28,    30,    33,    35,    39,
      42,    43,    46,    48,    50,    52,    54,    56,    58,    60,
      62,    64,    66,    70,    74,    76,    80,    81,    82,    94,
      95,    97,    99,   102,   105,   109,   113,   114,   117,   118,
     121,   124,   126,   127,   129,   130,   131,   145,   146,   149,
     152,   154,   155,   167,   168,   171,   174,   176,   177,   186,
     187,   190,   193,   195,   196,   206,   207,   210,   214,   216,
     218,   220,   222,   224,   226,   228,   230,   232,   234,   236,
     238,   240,   242,   244,   246,   248,   250,   252,   254,   256,
     258,   260,   262,   264,   266,   268,   270,   272,   274,   276,
     278,   280,   282,   284,   286,   288,   290,   292,   294,   296,
     298,   301,   303,   307,   314,   315,   317,   319,   320,   322,
     323,   334,   335,   337,   339,   340,   342,   343,   346,   347,
     350,   351,   354,   355,   358,   363,   364,   368,   376,   377,
     379,   380,   382,   383,   385,   387,   389,   391,   393,   395,
     400,   402,   403,   407,   412,   413,   417,   421,   423,   425,
     427,   429,   433,   435,   437,   439,   441,   443,   445,   447,
     449,   451,   453,   457,   461,   463,   467,   471,   475,   479,
     483,   487,   491,   495,   497,   501,   505,   509,   513,   517,
     521,   523,   525,   529,   533,   537,   541,   545,   549,   551,
     553,   557,   561,   565,   567,   570,   573,   575,   577,   581,
     585,   589,   593,   595,   597,   601,   604,   607,   609,   611,
     613,   615,   617,   619,   623,   625,   627,   629,   631,   633,
     637,   641,   643,   645,   647,   649,   652,   655,   658,   661,
     664,   667,   670,   672,   675,   676,   680,   683,   689,   694,
     698,   704,   708,   713,   717,   720,   721,   723,   727,   729,
     732,   733,   737,   739,   741,   743,   745,   750,   751,   754,
     756,   758,   760,   762,   764,   766,   768,   770,   774,   777,
     778,   781,   788,   789,   792,   795,   800,   807,   810,   811,
     815,   819,   824,   825,   827,   830,   836,   837,   840,   845,
     848,   852,   858,   860,   863,   865,   869,   872,   876,   877,
     879,   882,   887,   888,   892,   894,   896,   898,   902,   903,
     906,   908,   912,   915,   917,   919,   926,   934,   935,   937,
     944,   945,   948,   950,   952,   954,   956,   958,   960,   968,
     976,   977,   980,   981,   985,   986,   988,   990,   998,  1001,
    1003,  1005,  1006,  1010,  1016,  1024,  1028,  1031,  1033,  1035,
    1036,  1040,  1042,  1044,  1046,  1048,  1050,  1052,  1054,  1056,
    1058,  1060,  1062,  1064,  1066,  1068,  1070,  1072,  1074,  1077,
    1082,  1085,  1088,  1089,  1092,  1093,  1096,  1098,  1100,  1102,
    1103,  1108,  1110,  1112,  1114,  1116,  1118,  1120,  1122,  1124,
    1126,  1128,  1130,  1131,  1132,  1133,  1134,  1151,  1152,  1155,
    1156,  1159,  1160,  1163,  1164,  1168,  1169,  1172,  1173,  1176,
    1183,  1190,  1195,  1198,  1202,  1205,  1206,  1208,  1212,  1213,
    1215,  1219,  1221,  1224,  1227,  1229,  1232,  1233,  1235,  1237,
    1240,  1242,  1245,  1252,  1255,  1256,  1262,  1265,  1266,  1270,
    1273,  1274,  1277,  1279,  1281,  1282,  1284,  1294,  1299,  1300,
    1306,  1307,  1317,  1318,  1321,  1322,  1325,  1327,  1329,  1331,
    1333,  1335,  1337,  1339,  1341,  1342,  1355,  1356,  1370,  1371,
    1373,  1374,  1377,  1378,  1382,  1385,  1386,  1390,  1392,  1394,
    1395,  1398,  1400,  1402,  1404,  1406,  1408,  1410,  1412,  1414,
    1416,  1418,  1420,  1422,  1424,  1430,  1435,  1436,  1439,  1440,
    1443,  1452,  1457,  1458,  1461,  1471,  1472,  1475,  1476,  1482,
    1484,  1485,  1495,  1496,  1498,  1499,  1502,  1507,  1512,  1513,
    1516,  1519,  1521,  1523,  1526,  1529,  1533,  1534,  1536,  1542,
    1543,  1545,  1547,  1551,  1556,  1562,  1563,  1566,  1567,  1570,
    1571,  1574,  1575,  1585,  1586,  1595,  1596,  1599,  1600,  1603,
    1605,  1607,  1608,  1617,  1618,  1620,  1621,  1624,  1627,  1632,
    1636,  1638,  1640,  1642,  1644,  1646,  1647,  1648,  1655,  1658,
    1660,  1664,  1667,  1669,  1670,  1674,  1676,  1678,  1680,  1682,
    1684,  1686,  1688,  1690,  1693,  1694,  1696,  1699,  1701,  1705,
    1709,  1711,  1715,  1716,  1718,  1720,  1723,  1726,  1730,  1734,
    1735,  1737,  1738,  1739,  1753,  1754,  1757,  1760,  1762,  1763,
    1775,  1776,  1779,  1782,  1784,  1785,  1795,  1796,  1799,  1803,
    1805,  1807,  1809,  1811,  1813,  1815,  1817,  1819,  1821,  1823,
    1825,  1827,  1829,  1831,  1833,  1835,  1837,  1839,  1841,  1843,
    1845,  1847,  1849,  1851,  1853,  1855,  1857,  1859,  1861,  1863,
    1866,  1868,  1872,  1879,  1880,  1882,  1884,  1885,  1887,  1888,
    1898,  1899,  1901,  1902,  1905,  1906,  1909,  1910,  1913,  1914,
    1917,  1922,  1923,  1927,  1935,  1936,  1938,  1939,  1941,  1942,
    1944,  1946,  1948,  1950,  1952,  1954,  1959,  1961,  1962,  1966,
    1971,  1972,  1976,  1980,  1982,  1984,  1986,  1988,  1992,  1994,
    1996,  1998,  2000,  2002,  2004,  2006,  2008,  2010,  2012,  2016,
    2020,  2022,  2026,  2030,  2034,  2038,  2042,  2046,  2050,  2054,
    2056,  2060,  2064,  2068,  2072,  2076,  2080,  2082,  2084,  2088,
    2092,  2096,  2100,  2104,  2108,  2110,  2112,  2116,  2120,  2124,
    2126,  2129,  2132,  2134,  2136,  2140,  2144,  2148,  2152,  2154,
    2156,  2160,  2163,  2166,  2168,  2170,  2172,  2174,  2176,  2178,
    2182,  2184,  2186,  2188,  2190,  2192,  2196,  2200,  2202,  2204,
    2206,  2208,  2211,  2214,  2217,  2220,  2223,  2226,  2229,  2231,
    2234,  2235,  2239,  2242,  2248,  2253,  2257,  2263,  2267,  2272,
    2276,  2279,  2280,  2282,  2286,  2288,  2291,  2292,  2296,  2298,
    2300,  2302,  2304,  2309,  2310,  2313,  2315,  2317,  2319,  2321,
    2323,  2325,  2327,  2329,  2333,  2336,  2337,  2340,  2347,  2348,
    2351,  2354,  2359,  2366,  2369,  2370,  2374,  2378,  2383,  2389,
    2390,  2393,  2398,  2401,  2405,  2411,  2414,  2416,  2420,  2423,
    2427,  2428,  2430,  2433,  2438,  2439,  2443,  2445,  2447,  2449,
    2453,  2454,  2457,  2459,  2463,  2466,  2468,  2470,  2477,  2485,
    2486,  2488,  2495,  2496,  2499,  2501,  2503,  2505,  2507,  2509,
    2511,  2519,  2527,  2528,  2531,  2532,  2536,  2537,  2539,  2541,
    2549,  2552,  2554,  2556,  2557,  2561,  2567,  2575,  2579,  2582,
    2584,  2586,  2587,  2591,  2593,  2595,  2597,  2599,  2601,  2603,
    2605,  2607,  2609,  2611,  2613,  2615,  2617,  2619,  2621,  2623,
    2625,  2628,  2633,  2636,  2639,  2640,  2643,  2644,  2647,  2649,
    2651,  2653,  2654,  2659,  2661,  2663,  2665,  2667,  2669,  2671,
    2673,  2675,  2677,  2679,  2681,  2682,  2683,  2684,  2685,  2702,
    2703,  2706,  2707,  2710,  2711,  2714,  2715,  2719,  2720,  2723,
    2724,  2727,  2734,  2741,  2746,  2749,  2753,  2756,  2757,  2759,
    2763,  2764,  2766,  2770,  2772,  2775,  2778,  2780,  2783,  2784,
    2786,  2788,  2791,  2793,  2796,  2803,  2806,  2807,  2813,  2816,
    2817,  2821,  2824,  2825,  2828,  2830,  2832,  2833,  2835,  2845,
    2850,  2851,  2857,  2858,  2868,  2869,  2872,  2873,  2876,  2878,
    2880,  2882,  2884,  2886,  2888,  2890,  2892,  2893,  2906,  2907,
    2921,  2922,  2924,  2925,  2928,  2929,  2933,  2936,  2937,  2941,
    2943,  2945,  2946,  2949,  2951,  2953,  2955,  2957,  2959,  2961,
    2963,  2965,  2967,  2969,  2971,  2973,  2975,  2981,  2986,  2987,
    2990,  2991,  2994,  3003,  3008,  3009,  3012,  3022,  3023,  3026,
    3027,  3033,  3035,  3036,  3046,  3047,  3049,  3050,  3053,  3058,
    3063,  3064,  3067,  3070,  3072,  3074,  3077,  3080,  3084,  3085,
    3087,  3093,  3094,  3096,  3098,  3102,  3107,  3113,  3114,  3117,
    3118,  3121,  3122,  3125,  3126,  3136,  3137,  3146,  3147,  3150,
    3151,  3154,  3156,  3158,  3159,  3168,  3169,  3171,  3172,  3175,
    3178,  3183,  3187,  3189,  3191,  3193,  3195,  3197,  3198,  3199,
    3206,  3209,  3211,  3215,  3218,  3220,  3221
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     130,     0,    -1,   131,    -1,    -1,   139,    -1,   127,    -1,
     128,    -1,   125,    -1,   126,    -1,   137,    -1,    52,    -1,
     126,    -1,   127,    -1,   136,   127,    -1,    -1,   125,    -1,
     125,   127,    -1,   127,    -1,   138,   117,   127,    -1,   140,
     141,    -1,    -1,   140,   142,    -1,   146,    -1,   161,    -1,
     165,    -1,   156,    -1,   169,    -1,   446,    -1,   441,    -1,
     450,    -1,   143,    -1,   144,    -1,    44,   138,   120,    -1,
      88,   145,   120,    -1,   235,    -1,   145,   117,   235,    -1,
      -1,    -1,    29,   127,    42,   147,   149,   152,   148,   153,
      28,   154,   120,    -1,    -1,   150,    -1,   151,    -1,   150,
     151,    -1,   151,   150,    -1,    35,   193,   120,    -1,    60,
     191,   120,    -1,    -1,   152,   174,    -1,    -1,    13,   315,
      -1,    29,   155,    -1,   155,    -1,    -1,   127,    -1,    -1,
      -1,     8,   127,    53,   127,    42,   157,   159,    13,   158,
     316,    28,   160,   120,    -1,    -1,   159,   175,    -1,     8,
     155,    -1,   155,    -1,    -1,    21,   127,    53,   127,    42,
     162,   163,   408,    28,   164,   120,    -1,    -1,   163,   180,
      -1,    21,   155,    -1,   155,    -1,    -1,    59,   127,    42,
     166,   167,    28,   168,   120,    -1,    -1,   167,   176,    -1,
      59,   155,    -1,   155,    -1,    -1,    59,    15,   127,    42,
     170,   171,    28,   172,   120,    -1,    -1,   171,   177,    -1,
      59,    15,   155,    -1,   155,    -1,   254,    -1,   275,    -1,
     289,    -1,   297,    -1,   296,    -1,   181,    -1,   144,    -1,
     173,    -1,   186,    -1,   304,    -1,   305,    -1,   301,    -1,
     290,    -1,   173,    -1,   186,    -1,   406,    -1,   304,    -1,
     305,    -1,   417,    -1,   301,    -1,   290,    -1,   173,    -1,
     406,    -1,   304,    -1,   305,    -1,   301,    -1,   290,    -1,
     173,    -1,   186,    -1,   173,    -1,   186,    -1,   304,    -1,
     305,    -1,   292,    -1,   173,    -1,   186,    -1,   304,    -1,
     305,    -1,   292,    -1,   305,    -1,   144,    -1,   182,   120,
      -1,   183,    -1,    62,   127,   185,    -1,   184,    33,   132,
     185,    71,   276,    -1,    -1,    64,    -1,    38,    -1,    -1,
     195,    -1,    -1,   182,    42,   187,   190,    13,   372,    28,
     188,   189,   120,    -1,    -1,    62,    -1,    33,    -1,    -1,
     132,    -1,    -1,   190,   178,    -1,    -1,   192,   197,    -1,
      -1,   194,   197,    -1,    -1,   196,   197,    -1,   115,   199,
     198,   116,    -1,    -1,   198,   120,   199,    -1,   202,   138,
     119,   201,   276,   200,   293,    -1,    -1,    18,    -1,    -1,
     203,    -1,    -1,   294,    -1,    39,    -1,    58,    -1,    41,
      -1,    17,    -1,    45,    -1,   115,   209,   206,   116,    -1,
     204,    -1,    -1,   206,   117,   209,    -1,   115,   210,   208,
     116,    -1,    -1,   208,   117,   210,    -1,   211,   121,   212,
      -1,   212,    -1,   209,    -1,   284,    -1,   233,    -1,   211,
     123,   233,    -1,   215,    -1,    55,    -1,   127,    -1,   235,
      -1,   215,    -1,   217,    -1,   218,    -1,   219,    -1,   220,
      -1,   221,    -1,   216,    48,   216,    -1,   216,    51,   216,
      -1,   221,    -1,   216,     7,   216,    -1,   217,     7,   216,
      -1,   216,    56,   216,    -1,   218,    56,   216,    -1,   216,
      95,   216,    -1,   219,    95,   216,    -1,   216,    94,   216,
      -1,   220,    94,   216,    -1,   223,    -1,   222,   101,   222,
      -1,   222,   100,   222,    -1,   222,    99,   222,    -1,   222,
      98,   222,    -1,   222,    97,   222,    -1,   222,    96,   222,
      -1,   223,    -1,   225,    -1,   224,    78,   224,    -1,   224,
      80,   224,    -1,   224,    77,   224,    -1,   224,    79,   224,
      -1,   224,    72,   224,    -1,   224,    73,   224,    -1,   225,
      -1,   226,    -1,   224,   104,   227,    -1,   224,   103,   227,
      -1,   224,   102,   227,    -1,   228,    -1,   104,   227,    -1,
     103,   227,    -1,   228,    -1,   230,    -1,   227,   109,   229,
      -1,   227,   108,   229,    -1,   227,   107,   229,    -1,   227,
     106,   229,    -1,   230,    -1,   232,    -1,   231,   113,   231,
      -1,   112,   231,    -1,   111,   231,    -1,   232,    -1,   233,
      -1,   133,    -1,   244,    -1,   246,    -1,   247,    -1,   115,
     214,   116,    -1,   213,    -1,   234,    -1,   128,    -1,   241,
      -1,   238,    -1,   233,   124,   237,    -1,   236,   124,   127,
      -1,   127,    -1,   132,    -1,   126,    -1,     6,    -1,   213,
     207,    -1,   234,   207,    -1,   213,   114,    -1,   234,   114,
      -1,   239,    65,    -1,   239,    66,    -1,   239,   127,    -1,
     240,    -1,   240,   243,    -1,    -1,   115,   214,   116,    -1,
     245,   116,    -1,   115,   250,   121,   214,   116,    -1,   115,
     249,   117,   249,    -1,   245,   117,   249,    -1,   213,   114,
     115,   214,   116,    -1,   213,   114,   244,    -1,    49,   213,
     213,   248,    -1,    49,   213,   248,    -1,    49,   246,    -1,
      -1,   207,    -1,   250,   121,   214,    -1,   214,    -1,   252,
     251,    -1,    -1,   251,   123,   252,    -1,   215,    -1,   284,
      -1,    57,    -1,   127,    -1,    85,   253,   255,   120,    -1,
      -1,    42,   256,    -1,   257,    -1,   280,    -1,   260,    -1,
     264,    -1,   268,    -1,   270,    -1,   273,    -1,   274,    -1,
     115,   258,   116,    -1,   134,   259,    -1,    -1,   117,   258,
      -1,   280,    86,   262,   261,    28,    86,    -1,    -1,   261,
     263,    -1,   127,   120,    -1,   127,   101,   135,   120,    -1,
      10,   115,   265,   116,    53,   276,    -1,   267,   266,    -1,
      -1,   117,   267,   266,    -1,   213,    65,   122,    -1,    10,
     281,    53,   276,    -1,    -1,   127,    -1,    67,   155,    -1,
      67,   272,   271,    28,   269,    -1,    -1,   271,   272,    -1,
     138,   119,   276,   120,    -1,     3,   277,    -1,    31,    53,
     213,    -1,    81,   253,    42,   276,   120,    -1,   277,    -1,
     213,   279,    -1,   278,    -1,   213,   213,   280,    -1,   213,
     280,    -1,   213,   213,   279,    -1,    -1,   207,    -1,    65,
     287,    -1,   115,   283,   282,   116,    -1,    -1,   282,   117,
     283,    -1,   276,    -1,   286,    -1,   278,    -1,   215,   288,
     214,    -1,    -1,   288,   214,    -1,   242,    -1,   214,   288,
     214,    -1,   215,   285,    -1,    83,    -1,    25,    -1,    23,
     138,   119,   276,   293,   120,    -1,    76,   138,   119,   276,
     291,   293,   120,    -1,    -1,   295,    -1,    89,   138,   119,
     276,   293,   120,    -1,    -1,   118,   214,    -1,    23,    -1,
      76,    -1,    89,    -1,    31,    -1,    18,    -1,    68,    -1,
       5,   127,   119,   276,    42,   233,   120,    -1,    31,   127,
     119,   276,   298,   299,   120,    -1,    -1,    55,   214,    -1,
      -1,    42,   300,   214,    -1,    -1,    39,    -1,    58,    -1,
      24,   302,   119,   213,     4,   214,   120,    -1,   371,   303,
      -1,    57,    -1,     6,    -1,    -1,   303,   117,   371,    -1,
      12,   127,   119,   213,   120,    -1,    12,   127,    53,   306,
      42,   214,   120,    -1,   307,   119,   309,    -1,   132,   308,
      -1,    57,    -1,     6,    -1,    -1,   308,   117,   132,    -1,
      29,    -1,     8,    -1,    59,    -1,    21,    -1,    20,    -1,
      43,    -1,    85,    -1,    81,    -1,    62,    -1,    33,    -1,
      76,    -1,    89,    -1,    23,    -1,   312,    -1,   313,    -1,
     313,    -1,   314,    -1,    37,   385,    -1,    32,   127,    39,
     283,    -1,    92,   385,    -1,   316,   317,    -1,    -1,   316,
     317,    -1,    -1,   318,   319,    -1,   320,    -1,   321,    -1,
     323,    -1,    -1,   127,   119,   322,   324,    -1,   342,    -1,
     343,    -1,   345,    -1,   363,    -1,   325,    -1,   336,    -1,
     342,    -1,   343,    -1,   345,    -1,   358,    -1,   363,    -1,
      -1,    -1,    -1,    -1,    14,   333,   366,   326,   332,   327,
     331,   328,   330,    13,   329,   316,    28,    14,   155,   120,
      -1,    -1,   330,   175,    -1,    -1,   151,   334,    -1,    -1,
     150,   335,    -1,    -1,   115,   385,   116,    -1,    -1,   341,
     120,    -1,    -1,   339,   120,    -1,   419,    35,    47,   205,
     340,   120,    -1,   419,    60,    47,   205,   338,   120,    -1,
     337,   338,   340,   120,    -1,    20,   419,    -1,    29,   236,
     427,    -1,    21,   213,    -1,    -1,   339,    -1,    35,    47,
     205,    -1,    -1,   341,    -1,    60,    47,   205,    -1,   375,
      -1,    61,   375,    -1,   213,   120,    -1,   396,    -1,    61,
     394,    -1,    -1,    61,    -1,   346,    -1,    61,   346,    -1,
     355,    -1,    61,   355,    -1,   353,    98,   354,   400,   347,
     120,    -1,   348,   349,    -1,    -1,   348,   349,    91,   385,
      26,    -1,   351,   350,    -1,    -1,   350,   117,   351,    -1,
     214,   352,    -1,    -1,     4,   214,    -1,   233,    -1,   244,
      -1,    -1,    36,    -1,    93,   214,    74,   353,    98,   354,
     400,   356,   120,    -1,   357,   349,    91,   250,    -1,    -1,
     357,   349,    91,   250,   117,    -1,    -1,   310,    34,   359,
     360,   315,    28,    34,   155,   120,    -1,    -1,   361,    13,
      -1,    -1,   361,   362,    -1,   173,    -1,   186,    -1,   406,
      -1,   304,    -1,   305,    -1,   417,    -1,   301,    -1,   290,
      -1,    -1,    63,   368,   366,   364,   367,    13,   372,    28,
     344,    63,   155,   120,    -1,    -1,    61,    63,   368,   366,
     365,   367,    13,   372,    28,   344,    63,   155,   120,    -1,
      -1,    42,    -1,    -1,   367,   179,    -1,    -1,   115,   369,
     116,    -1,   371,   370,    -1,    -1,   370,   117,   371,    -1,
     233,    -1,   373,    -1,    -1,   373,   374,    -1,   375,    -1,
     376,    -1,   379,    -1,   391,    -1,   382,    -1,   386,    -1,
     390,    -1,   393,    -1,   394,    -1,   397,    -1,   399,    -1,
     401,    -1,   402,    -1,    11,   385,   378,   377,   120,    -1,
      70,   214,   377,   120,    -1,    -1,    75,   214,    -1,    -1,
      70,   214,    -1,    19,   214,    42,   380,   381,    28,    19,
     120,    -1,    91,   250,   121,   372,    -1,    -1,   381,   380,
      -1,    37,   385,    82,   372,   384,   383,    28,    37,   120,
      -1,    -1,    26,   372,    -1,    -1,   384,    27,   385,    82,
     372,    -1,   214,    -1,    -1,   389,   388,    46,   387,   372,
      28,    46,   155,   120,    -1,    -1,   311,    -1,    -1,   127,
     119,    -1,    50,   155,   392,   120,    -1,    30,   155,   392,
     120,    -1,    -1,    91,   385,    -1,    52,   120,    -1,   395,
      -1,   396,    -1,   213,   120,    -1,   234,   120,    -1,    71,
     398,   120,    -1,    -1,   214,    -1,   353,    98,   400,   349,
     120,    -1,    -1,    84,    -1,    40,    -1,    69,   214,    40,
      -1,   353,   118,   214,   120,    -1,    90,   405,   404,   403,
     120,    -1,    -1,    32,   214,    -1,    -1,    87,   385,    -1,
      -1,    54,   369,    -1,    -1,    20,   127,   366,   407,   149,
      28,    20,   155,   120,    -1,    -1,    32,   233,   409,   411,
     410,    28,    32,   120,    -1,    -1,   410,   412,    -1,    -1,
     411,   144,    -1,   408,    -1,   413,    -1,    -1,    32,   418,
     416,   414,   415,    28,    32,   120,    -1,    -1,   408,    -1,
      -1,   425,   120,    -1,   422,   120,    -1,    32,   418,   421,
     120,    -1,   420,   119,   419,    -1,   213,    -1,   138,    -1,
       6,    -1,    57,    -1,   422,    -1,    -1,    -1,   423,    88,
     426,   424,   338,   340,    -1,   339,   340,    -1,   341,    -1,
      29,   236,   427,    -1,    21,   213,    -1,    55,    -1,    -1,
     115,   127,   116,    -1,   127,    -1,   128,    -1,   125,    -1,
     126,    -1,   433,    -1,    52,    -1,   126,    -1,   127,    -1,
     432,   127,    -1,    -1,   125,    -1,   125,   127,    -1,   127,
      -1,   434,   117,   127,    -1,    88,   436,   120,    -1,   513,
      -1,   436,   117,   513,    -1,    -1,   438,    -1,   439,    -1,
     438,   439,    -1,   439,   438,    -1,    35,   471,   120,    -1,
      60,   469,   120,    -1,    -1,   127,    -1,    -1,    -1,     9,
     127,    53,   127,    42,   442,   444,    13,   443,   592,    28,
     445,   120,    -1,    -1,   444,   455,    -1,     9,   440,    -1,
     440,    -1,    -1,    22,   127,    53,   127,    42,   447,   448,
     684,    28,   449,   120,    -1,    -1,   448,   459,    -1,    22,
     440,    -1,   440,    -1,    -1,    59,    16,   127,    42,   451,
     452,    28,   453,   120,    -1,    -1,   452,   456,    -1,    59,
      16,   440,    -1,   440,    -1,   532,    -1,   552,    -1,   565,
      -1,   573,    -1,   572,    -1,   460,    -1,   435,    -1,   454,
      -1,   465,    -1,   682,    -1,   580,    -1,   581,    -1,   693,
      -1,   577,    -1,   566,    -1,   454,    -1,   465,    -1,   454,
      -1,   465,    -1,   580,    -1,   581,    -1,   568,    -1,   454,
      -1,   465,    -1,   580,    -1,   581,    -1,   568,    -1,   581,
      -1,   435,    -1,   461,   120,    -1,   462,    -1,    62,   127,
     464,    -1,   463,    33,   428,   464,    71,   553,    -1,    -1,
      64,    -1,    38,    -1,    -1,   473,    -1,    -1,   461,    42,
     466,   468,    13,   648,    28,   467,   120,    -1,    -1,   428,
      -1,    -1,   468,   457,    -1,    -1,   470,   475,    -1,    -1,
     472,   475,    -1,    -1,   474,   475,    -1,   115,   477,   476,
     116,    -1,    -1,   476,   120,   477,    -1,   480,   434,   119,
     479,   553,   478,   569,    -1,    -1,    18,    -1,    -1,   481,
      -1,    -1,   570,    -1,    39,    -1,    58,    -1,    41,    -1,
      17,    -1,    45,    -1,   115,   487,   484,   116,    -1,   482,
      -1,    -1,   484,   117,   487,    -1,   115,   488,   486,   116,
      -1,    -1,   486,   117,   488,    -1,   489,   121,   490,    -1,
     490,    -1,   487,    -1,   560,    -1,   511,    -1,   489,   123,
     511,    -1,   493,    -1,    55,    -1,   127,    -1,   513,    -1,
     493,    -1,   495,    -1,   496,    -1,   497,    -1,   498,    -1,
     499,    -1,   494,    48,   494,    -1,   494,    51,   494,    -1,
     499,    -1,   494,     7,   494,    -1,   495,     7,   494,    -1,
     494,    56,   494,    -1,   496,    56,   494,    -1,   494,    95,
     494,    -1,   497,    95,   494,    -1,   494,    94,   494,    -1,
     498,    94,   494,    -1,   501,    -1,   500,   101,   500,    -1,
     500,   100,   500,    -1,   500,    99,   500,    -1,   500,    98,
     500,    -1,   500,    97,   500,    -1,   500,    96,   500,    -1,
     501,    -1,   503,    -1,   502,    78,   502,    -1,   502,    80,
     502,    -1,   502,    77,   502,    -1,   502,    79,   502,    -1,
     502,    72,   502,    -1,   502,    73,   502,    -1,   503,    -1,
     504,    -1,   502,   104,   505,    -1,   502,   103,   505,    -1,
     502,   102,   505,    -1,   506,    -1,   104,   505,    -1,   103,
     505,    -1,   506,    -1,   508,    -1,   505,   109,   507,    -1,
     505,   108,   507,    -1,   505,   107,   507,    -1,   505,   106,
     507,    -1,   508,    -1,   510,    -1,   509,   113,   509,    -1,
     112,   509,    -1,   111,   509,    -1,   510,    -1,   511,    -1,
     429,    -1,   522,    -1,   524,    -1,   525,    -1,   115,   492,
     116,    -1,   491,    -1,   512,    -1,   128,    -1,   519,    -1,
     516,    -1,   511,   124,   515,    -1,   514,   124,   127,    -1,
     127,    -1,   428,    -1,   126,    -1,     6,    -1,   491,   485,
      -1,   512,   485,    -1,   491,   114,    -1,   512,   114,    -1,
     517,    65,    -1,   517,    66,    -1,   517,   127,    -1,   518,
      -1,   518,   521,    -1,    -1,   115,   492,   116,    -1,   523,
     116,    -1,   115,   528,   121,   492,   116,    -1,   115,   527,
     117,   527,    -1,   523,   117,   527,    -1,   491,   114,   115,
     492,   116,    -1,   491,   114,   522,    -1,    49,   491,   491,
     526,    -1,    49,   491,   526,    -1,    49,   524,    -1,    -1,
     485,    -1,   528,   121,   492,    -1,   492,    -1,   530,   529,
      -1,    -1,   529,   123,   530,    -1,   493,    -1,   560,    -1,
      57,    -1,   127,    -1,    85,   531,   533,   120,    -1,    -1,
      42,   534,    -1,   535,    -1,   556,    -1,   538,    -1,   542,
      -1,   546,    -1,   547,    -1,   550,    -1,   551,    -1,   115,
     536,   116,    -1,   430,   537,    -1,    -1,   117,   536,    -1,
     556,    86,   540,   539,    28,    86,    -1,    -1,   539,   541,
      -1,   127,   120,    -1,   127,   101,   431,   120,    -1,    10,
     115,   543,   116,    53,   553,    -1,   545,   544,    -1,    -1,
     117,   545,   544,    -1,   491,    65,   122,    -1,    10,   557,
      53,   553,    -1,    67,   549,   548,    28,    67,    -1,    -1,
     548,   549,    -1,   434,   119,   553,   120,    -1,     3,   553,
      -1,    31,    53,   491,    -1,    81,   531,    42,   553,   120,
      -1,   491,   555,    -1,   554,    -1,   491,   491,   556,    -1,
     491,   556,    -1,   491,   491,   555,    -1,    -1,   485,    -1,
      65,   563,    -1,   115,   559,   558,   116,    -1,    -1,   558,
     117,   559,    -1,   553,    -1,   562,    -1,   554,    -1,   493,
     564,   492,    -1,    -1,   564,   492,    -1,   520,    -1,   492,
     564,   492,    -1,   493,   561,    -1,    83,    -1,    25,    -1,
      23,   434,   119,   553,   569,   120,    -1,    76,   434,   119,
     553,   567,   569,   120,    -1,    -1,   571,    -1,    89,   434,
     119,   553,   569,   120,    -1,    -1,   118,   492,    -1,    23,
      -1,    76,    -1,    89,    -1,    31,    -1,    18,    -1,    68,
      -1,     5,   127,   119,   553,    42,   511,   120,    -1,    31,
     127,   119,   553,   574,   575,   120,    -1,    -1,    55,   492,
      -1,    -1,    42,   576,   492,    -1,    -1,    39,    -1,    58,
      -1,    24,   578,   119,   491,     4,   492,   120,    -1,   647,
     579,    -1,    57,    -1,     6,    -1,    -1,   579,   117,   647,
      -1,    12,   127,   119,   491,   120,    -1,    12,   127,    53,
     582,    42,   492,   120,    -1,   583,   119,   585,    -1,   428,
     584,    -1,    57,    -1,     6,    -1,    -1,   584,   117,   428,
      -1,    29,    -1,     8,    -1,    59,    -1,    21,    -1,    20,
      -1,    43,    -1,    85,    -1,    81,    -1,    62,    -1,    33,
      -1,    76,    -1,    89,    -1,    23,    -1,   588,    -1,   589,
      -1,   589,    -1,   590,    -1,    37,   661,    -1,    32,   127,
      39,   559,    -1,    92,   661,    -1,   592,   593,    -1,    -1,
     592,   593,    -1,    -1,   594,   595,    -1,   596,    -1,   597,
      -1,   599,    -1,    -1,   127,   119,   598,   600,    -1,   618,
      -1,   619,    -1,   621,    -1,   639,    -1,   601,    -1,   612,
      -1,   618,    -1,   619,    -1,   621,    -1,   634,    -1,   639,
      -1,    -1,    -1,    -1,    -1,    14,   609,   642,   602,   608,
     603,   607,   604,   606,    13,   605,   592,    28,    14,   440,
     120,    -1,    -1,   606,   455,    -1,    -1,   439,   610,    -1,
      -1,   438,   611,    -1,    -1,   115,   661,   116,    -1,    -1,
     617,   120,    -1,    -1,   615,   120,    -1,   695,    35,    47,
     483,   616,   120,    -1,   695,    60,    47,   483,   614,   120,
      -1,   613,   614,   616,   120,    -1,    20,   695,    -1,    29,
     514,   703,    -1,    21,   491,    -1,    -1,   615,    -1,    35,
      47,   483,    -1,    -1,   617,    -1,    60,    47,   483,    -1,
     651,    -1,    61,   651,    -1,   491,   120,    -1,   672,    -1,
      61,   670,    -1,    -1,    61,    -1,   622,    -1,    61,   622,
      -1,   631,    -1,    61,   631,    -1,   629,    98,   630,   676,
     623,   120,    -1,   624,   625,    -1,    -1,   624,   625,    91,
     661,    26,    -1,   627,   626,    -1,    -1,   626,   117,   627,
      -1,   492,   628,    -1,    -1,     4,   492,    -1,   511,    -1,
     522,    -1,    -1,    36,    -1,    93,   492,    74,   629,    98,
     630,   676,   632,   120,    -1,   633,   625,    91,   528,    -1,
      -1,   633,   625,    91,   528,   117,    -1,    -1,   586,    34,
     635,   636,   591,    28,    34,   440,   120,    -1,    -1,   637,
      13,    -1,    -1,   637,   638,    -1,   454,    -1,   465,    -1,
     682,    -1,   580,    -1,   581,    -1,   693,    -1,   577,    -1,
     566,    -1,    -1,    63,   644,   642,   640,   643,    13,   648,
      28,   620,    63,   440,   120,    -1,    -1,    61,    63,   644,
     642,   641,   643,    13,   648,    28,   620,    63,   440,   120,
      -1,    -1,    42,    -1,    -1,   643,   458,    -1,    -1,   115,
     645,   116,    -1,   647,   646,    -1,    -1,   646,   117,   647,
      -1,   511,    -1,   649,    -1,    -1,   649,   650,    -1,   651,
      -1,   652,    -1,   655,    -1,   667,    -1,   658,    -1,   662,
      -1,   666,    -1,   669,    -1,   670,    -1,   673,    -1,   675,
      -1,   677,    -1,   678,    -1,    11,   661,   654,   653,   120,
      -1,    70,   492,   653,   120,    -1,    -1,    75,   492,    -1,
      -1,    70,   492,    -1,    19,   492,    42,   656,   657,    28,
      19,   120,    -1,    91,   528,   121,   648,    -1,    -1,   657,
     656,    -1,    37,   661,    82,   648,   660,   659,    28,    37,
     120,    -1,    -1,    26,   648,    -1,    -1,   660,    27,   661,
      82,   648,    -1,   492,    -1,    -1,   665,   664,    46,   663,
     648,    28,    46,   440,   120,    -1,    -1,   587,    -1,    -1,
     127,   119,    -1,    50,   440,   668,   120,    -1,    30,   440,
     668,   120,    -1,    -1,    91,   661,    -1,    52,   120,    -1,
     671,    -1,   672,    -1,   491,   120,    -1,   512,   120,    -1,
      71,   674,   120,    -1,    -1,   492,    -1,   629,    98,   676,
     625,   120,    -1,    -1,    84,    -1,    40,    -1,    69,   492,
      40,    -1,   629,   118,   492,   120,    -1,    90,   681,   680,
     679,   120,    -1,    -1,    32,   492,    -1,    -1,    87,   661,
      -1,    -1,    54,   645,    -1,    -1,    20,   127,   642,   683,
     437,    28,    20,   440,   120,    -1,    -1,    32,   511,   685,
     687,   686,    28,    32,   120,    -1,    -1,   686,   688,    -1,
      -1,   687,   435,    -1,   684,    -1,   689,    -1,    -1,    32,
     694,   692,   690,   691,    28,    32,   120,    -1,    -1,   684,
      -1,    -1,   701,   120,    -1,   698,   120,    -1,    32,   694,
     697,   120,    -1,   696,   119,   695,    -1,   491,    -1,   434,
      -1,     6,    -1,    57,    -1,   698,    -1,    -1,    -1,   699,
      88,   702,   700,   614,   616,    -1,   615,   616,    -1,   617,
      -1,    29,   514,   703,    -1,    21,   491,    -1,    55,    -1,
      -1,   115,   127,   116,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   465,   465,   469,   470,   474,   475,   479,   483,   484,
     485,   489,   490,   494,   503,   504,   508,   513,   515,   524,
     527,   529,   533,   534,   535,   536,   537,   538,   539,   540,
     544,   545,   549,   553,   557,   558,   567,   574,   566,   588,
     590,   591,   592,   593,   604,   619,   625,   627,   630,   632,
     636,   637,   641,   642,   647,   657,   646,   672,   674,   678,
     679,   685,   684,   701,   702,   706,   707,   713,   712,   726,
     727,   731,   732,   738,   737,   752,   753,   757,   758,   766,
     767,   768,   769,   770,   771,   772,   776,   777,   778,   779,
     780,   781,   785,   786,   787,   788,   789,   790,   791,   792,
     796,   797,   798,   799,   800,   801,   805,   806,   810,   811,
     812,   813,   814,   818,   819,   820,   821,   822,   826,   827,
     835,   845,   858,   862,   870,   871,   872,   876,   877,   882,
     881,   939,   940,   941,   945,   946,   949,   951,   960,   960,
     975,   975,   990,   990,  1000,  1016,  1017,  1033,  1046,  1047,
    1051,  1052,  1056,  1057,  1061,  1062,  1063,  1064,  1065,  1069,
    1080,  1087,  1088,  1100,  1114,  1115,  1129,  1136,  1146,  1147,
    1151,  1152,  1156,  1157,  1165,  1166,  1170,  1177,  1178,  1179,
    1180,  1181,  1182,  1184,  1189,  1196,  1198,  1203,  1205,  1210,
    1212,  1217,  1219,  1224,  1225,  1229,  1233,  1237,  1241,  1245,
    1252,  1259,  1260,  1264,  1268,  1272,  1276,  1280,  1287,  1294,
    1295,  1299,  1303,  1310,  1311,  1315,  1322,  1329,  1330,  1334,
    1338,  1342,  1349,  1356,  1357,  1361,  1365,  1372,  1379,  1380,
    1381,  1382,  1383,  1384,  1389,  1390,  1394,  1395,  1396,  1400,
    1404,  1405,  1409,  1410,  1411,  1415,  1427,  1443,  1444,  1449,
    1451,  1457,  1459,  1478,  1499,  1500,  1505,  1509,  1516,  1524,
    1535,  1537,  1543,  1549,  1556,  1573,  1574,  1582,  1584,  1589,
    1599,  1600,  1617,  1625,  1629,  1640,  1644,  1652,  1653,  1657,
    1658,  1659,  1660,  1661,  1662,  1663,  1664,  1668,  1675,  1684,
    1685,  1689,  1717,  1718,  1725,  1733,  1746,  1753,  1761,  1764,
    1771,  1778,  1786,  1789,  1793,  1800,  1819,  1822,  1831,  1845,
    1860,  1871,  1913,  1927,  1941,  1945,  1949,  1953,  1960,  1961,
    1965,  1969,  1981,  1984,  1995,  2005,  2012,  2023,  2033,  2036,
    2052,  2063,  2070,  2091,  2092,  2100,  2113,  2124,  2125,  2129,
    2139,  2140,  2144,  2145,  2146,  2147,  2151,  2152,  2156,  2163,
    2172,  2175,  2185,  2188,  2198,  2201,  2205,  2212,  2219,  2224,
    2229,  2237,  2238,  2258,  2276,  2283,  2290,  2295,  2299,  2306,
    2307,  2314,  2315,  2316,  2317,  2318,  2319,  2320,  2321,  2322,
    2323,  2324,  2325,  2326,  2334,  2335,  2339,  2340,  2344,  2348,
    2356,  2364,  2367,  2369,  2373,  2373,  2381,  2382,  2386,  2409,
    2408,  2436,  2437,  2438,  2439,  2443,  2444,  2445,  2446,  2447,
    2448,  2449,  2454,  2465,  2470,  2476,  2453,  2491,  2493,  2497,
    2498,  2502,  2503,  2507,  2508,  2512,  2513,  2517,  2518,  2535,
    2546,  2556,  2569,  2573,  2577,  2588,  2589,  2593,  2597,  2598,
    2602,  2606,  2611,  2618,  2623,  2628,  2635,  2636,  2640,  2645,
    2650,  2655,  2662,  2669,  2684,  2685,  2700,  2714,  2715,  2728,
    2735,  2736,  2740,  2741,  2745,  2746,  2750,  2758,  2766,  2769,
    2777,  2776,  2795,  2797,  2800,  2802,  2806,  2807,  2808,  2809,
    2810,  2811,  2812,  2813,  2818,  2817,  2838,  2837,  2856,  2858,
    2861,  2863,  2867,  2868,  2872,  2880,  2881,  2889,  2908,  2912,
    2913,  2925,  2926,  2927,  2928,  2929,  2930,  2931,  2932,  2933,
    2934,  2935,  2936,  2937,  2941,  2949,  2958,  2961,  2970,  2973,
    2981,  2997,  3006,  3009,  3020,  3038,  3039,  3043,  3044,  3070,
    3079,  3078,  3090,  3091,  3095,  3096,  3103,  3110,  3117,  3118,
    3122,  3126,  3127,  3131,  3138,  3145,  3182,  3183,  3187,  3194,
    3195,  3196,  3197,  3206,  3213,  3220,  3221,  3225,  3226,  3230,
    3231,  3240,  3239,  3256,  3256,  3270,  3271,  3274,  3276,  3280,
    3281,  3286,  3285,  3300,  3301,  3305,  3306,  3307,  3311,  3319,
    3327,  3336,  3337,  3338,  3346,  3350,  3352,  3350,  3361,  3366,
    3374,  3378,  3382,  3389,  3390,  3397,  3398,  3402,  3404,  3405,
    3406,  3410,  3411,  3415,  3420,  3421,  3425,  3430,  3431,  3446,
    3451,  3452,  3472,  3474,  3475,  3476,  3477,  3491,  3505,  3532,
    3533,  3538,  3543,  3537,  3548,  3549,  3553,  3554,  3560,  3559,
    3568,  3569,  3573,  3574,  3600,  3599,  3607,  3608,  3612,  3613,
    3621,  3622,  3623,  3624,  3625,  3626,  3627,  3642,  3643,  3644,
    3645,  3646,  3647,  3648,  3649,  3664,  3665,  3669,  3670,  3671,
    3672,  3673,  3677,  3678,  3679,  3680,  3681,  3685,  3686,  3694,
    3699,  3704,  3706,  3712,  3713,  3714,  3718,  3719,  3724,  3723,
    3733,  3734,  3737,  3739,  3748,  3748,  3754,  3754,  3760,  3760,
    3766,  3771,  3772,  3777,  3783,  3784,  3788,  3789,  3793,  3794,
    3798,  3799,  3800,  3801,  3802,  3806,  3811,  3816,  3817,  3823,
    3828,  3829,  3834,  3836,  3841,  3842,  3846,  3847,  3851,  3852,
    3860,  3861,  3865,  3870,  3871,  3872,  3873,  3874,  3875,  3877,
    3882,  3888,  3890,  3895,  3897,  3902,  3904,  3909,  3911,  3916,
    3917,  3920,  3923,  3926,  3929,  3932,  3938,  3944,  3945,  3948,
    3951,  3954,  3957,  3960,  3966,  3972,  3973,  3976,  3979,  3985,
    3986,  3989,  3995,  4001,  4002,  4005,  4008,  4011,  4017,  4023,
    4024,  4027,  4030,  4036,  4042,  4043,  4044,  4045,  4046,  4047,
    4051,  4052,  4056,  4057,  4058,  4062,  4066,  4067,  4071,  4072,
    4073,  4077,  4079,  4085,  4086,  4091,  4092,  4097,  4098,  4117,
    4122,  4123,  4128,  4130,  4135,  4137,  4142,  4144,  4150,  4152,
    4154,  4159,  4160,  4168,  4170,  4175,  4180,  4181,  4186,  4188,
    4190,  4199,  4203,  4208,  4209,  4213,  4214,  4215,  4216,  4217,
    4218,  4219,  4220,  4224,  4229,  4234,  4235,  4239,  4247,  4248,
    4253,  4258,  4263,  4268,  4274,  4275,  4280,  4285,  4290,  4296,
    4297,  4302,  4307,  4312,  4321,  4326,  4327,  4331,  4333,  4335,
    4340,  4341,  4345,  4349,  4355,  4356,  4361,  4363,  4368,  4370,
    4377,  4378,  4392,  4394,  4399,  4404,  4405,  4413,  4419,  4425,
    4426,  4430,  4435,  4436,  4440,  4441,  4442,  4443,  4447,  4448,
    4452,  4457,  4464,  4465,  4471,  4472,  4478,  4480,  4483,  4489,
    4494,  4496,  4498,  4503,  4504,  4513,  4518,  4523,  4528,  4530,
    4532,  4537,  4538,  4543,  4544,  4545,  4546,  4547,  4548,  4549,
    4550,  4551,  4552,  4553,  4554,  4555,  4563,  4564,  4568,  4569,
    4573,  4577,  4582,  4590,  4593,  4595,  4599,  4599,  4605,  4606,
    4610,  4617,  4616,  4625,  4626,  4627,  4628,  4632,  4633,  4634,
    4635,  4636,  4637,  4638,  4643,  4645,  4647,  4650,  4642,  4656,
    4658,  4662,  4663,  4667,  4668,  4672,  4673,  4677,  4678,  4682,
    4683,  4697,  4703,  4708,  4716,  4718,  4720,  4729,  4730,  4734,
    4738,  4739,  4743,  4747,  4750,  4755,  4758,  4761,  4766,  4767,
    4771,  4774,  4777,  4780,  4785,  4790,  4795,  4796,  4801,  4806,
    4807,  4812,  4817,  4818,  4822,  4823,  4827,  4828,  4832,  4838,
    4844,  4845,  4851,  4850,  4860,  4862,  4865,  4867,  4871,  4872,
    4873,  4874,  4875,  4876,  4877,  4878,  4883,  4882,  4891,  4890,
    4899,  4901,  4904,  4906,  4910,  4911,  4915,  4920,  4921,  4926,
    4935,  4939,  4940,  4945,  4946,  4947,  4948,  4949,  4950,  4951,
    4952,  4953,  4954,  4955,  4956,  4957,  4961,  4967,  4973,  4974,
    4980,  4981,  4986,  4994,  5000,  5001,  5006,  5012,  5013,  5017,
    5018,  5023,  5028,  5027,  5035,  5036,  5040,  5041,  5046,  5051,
    5056,  5057,  5061,  5065,  5066,  5070,  5075,  5080,  5085,  5086,
    5090,  5095,  5096,  5097,  5098,  5103,  5108,  5113,  5114,  5118,
    5119,  5123,  5124,  5133,  5132,  5140,  5140,  5148,  5149,  5152,
    5154,  5158,  5159,  5164,  5163,  5171,  5172,  5176,  5177,  5178,
    5182,  5187,  5192,  5197,  5198,  5199,  5207,  5211,  5213,  5211,
    5219,  5221,  5226,  5228,  5230,  5235,  5236
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "t_ACCESS", "t_AFTER", "t_ALIAS",
  "t_ALL", "t_AND", "t_ARCHITECTURE", "skip_t_ARCHITECTURE", "t_ARRAY",
  "t_ASSERT", "t_ATTRIBUTE", "t_BEGIN", "t_BLOCK", "t_BODY", "skip_t_BODY",
  "t_BUFFER", "t_BUS", "t_CASE", "t_COMPONENT", "t_CONFIGURATION",
  "skip_t_CONFIGURATION", "t_CONSTANT", "t_DISCONNECT", "t_DOWNTO",
  "t_ELSE", "t_ELSIF", "t_END", "t_ENTITY", "t_EXIT", "t_FILE", "t_FOR",
  "t_FUNCTION", "t_GENERATE", "t_GENERIC", "t_GUARDED", "t_IF", "t_IMPURE",
  "t_IN", "t_INERTIAL", "t_INOUT", "t_IS", "t_LABEL", "t_LIBRARY",
  "t_LINKAGE", "t_LOOP", "t_MAP", "t_NAND", "t_NEW", "t_NEXT", "t_NOR",
  "t_NULL", "t_OF", "t_ON", "t_OPEN", "t_OR", "t_OTHERS", "t_OUT",
  "t_PACKAGE", "t_PORT", "t_POSTPONED", "t_PROCEDURE", "t_PROCESS",
  "t_PURE", "t_RANGE", "t_REVERSE_RANGE", "t_RECORD", "t_REGISTER",
  "t_REJECT", "t_REPORT", "t_RETURN", "t_ROL", "t_ROR", "t_SELECT",
  "t_SEVERITY", "t_SIGNAL", "t_SLA", "t_SLL", "t_SRA", "t_SRL",
  "t_SUBTYPE", "t_THEN", "t_TO", "t_TRANSPORT", "t_TYPE", "t_UNITS",
  "t_UNTIL", "t_USE", "t_VARIABLE", "t_WAIT", "t_WHEN", "t_WHILE",
  "t_WITH", "t_XNOR", "t_XOR", "t_GESym", "t_GTSym", "t_LESym", "t_LTSym",
  "t_NESym", "t_EQSym", "t_Ampersand", "t_Minus", "t_Plus",
  "MED_PRECEDENCE", "t_REM", "t_MOD", "t_Slash", "t_Star",
  "MAX_PRECEDENCE", "t_NOT", "t_ABS", "t_DoubleStar", "t_Apostrophe",
  "t_LeftParen", "t_RightParen", "t_Comma", "t_VarAsgn", "t_Colon",
  "t_Semicolon", "t_Arrow", "t_Box", "t_Bar", "t_Dot", "t_AbstractLit",
  "t_CharacterLit", "t_Identifier", "t_StringLit", "$accept", "start",
  "opt_design_unit", "designator", "literal", "enumeration_literal",
  "physical_literal", "opt_t_AbstractLit", "physical_literal_no_default",
  "idf_list", "design_unit", "context_list", "lib_unit", "context_item",
  "lib_clause", "use_clause", "sel_list", "entity_declaration", "@1",
  "$@2", "opt_generic_and_port_clauses", "generic_clause", "port_clause",
  "entity_decl_part", "opt_entity_stats", "opt_entity_end",
  "opt_t_Identifier", "architecture_body", "@3", "$@4",
  "architecture_decl_part", "opt_architecture_end",
  "configuration_declaration", "@5", "configuration_decl_part",
  "opt_configuration_end", "package_declaration", "$@6",
  "package_decl_part", "opt_package_end", "package_body", "$@7",
  "package_body_decl_part", "opt_package_body_end", "common_decltve_item",
  "entity_decltve_item", "block_decltve_item", "package_decltve_item",
  "package_body_decltve_item", "subprog_decltve_item", "proc_decltve_item",
  "config_decltve_item", "subprog_decl", "subprog_spec",
  "proc_or_func_spec", "pure_or_impure", "opt_interf_list", "subprog_body",
  "@8", "opt_function_or_procedure_t", "opt_designator",
  "subprog_body_decl_part", "port_interf_list", "$@9",
  "generic_interf_list", "$@10", "interf_list", "$@11", "interf_list_1",
  "opt_more_interf_elements", "interf_element", "opt_t_BUS", "opt_mode",
  "opt_object_class", "mode", "association_list", "named_association_list",
  "association_list_1", "gen_association_list", "gen_association_list_1",
  "association_elements", "gen_association_elements", "formal_part",
  "actual_part", "mark", "expr", "expr_or_attr", "relation",
  "and_expression", "or_expression", "xor_expression", "xnor_expression",
  "relation_or_attr", "shift_expression", "shift_expression_or_attr",
  "simple_expression", "simple_expression_or_attr", "signed_term_or_attr",
  "term", "term_or_attr", "factor", "factor_or_attr", "primary",
  "primary_or_attr", "name", "name2", "sel_name", "simple_sel_name",
  "suffix", "ifts_name", "attribute_prefix", "range_attribute_name",
  "attribute_name", "range_attribute_name_with_param",
  "opt_attribute_param", "aggregate", "rev_element_association_list2",
  "qualified_expr", "allocator", "opt_index_association_list",
  "element_association", "choices", "opt_more_choices", "choice",
  "decl_Identifier", "type_decl", "opt_type_def", "type_definition",
  "enumeration_type_definition", "enumeration_literal_decls",
  "opt_more_enumeration_literals", "physical_type_definition",
  "secondary_unit_decls", "primary_unit_decl", "secondary_unit_decl",
  "unconstrained_array_definition", "index_subtype_defs",
  "opt_more_index_subtype_defs", "index_subtype_definition",
  "constrained_array_definition", "opt_record_end",
  "record_type_definition", "opt_more_element_decls", "element_decl",
  "access_type_definition", "file_type_definition", "subtype_decl",
  "subtype_indic", "subtype_indic_opt_incomplete", "subtype_indic1",
  "opt_index_constraint", "range_constraint", "index_constraint",
  "opt_more_discrete_ranges", "discrete_range", "discrete_range1",
  "opt_direction_expr", "range_spec", "range_spec2", "direction",
  "constant_decl", "signal_decl", "opt_signal_kind", "variable_decl",
  "opt_var_init", "object_class", "signal_kind", "alias_decl", "file_decl",
  "opt_open_mode", "opt_file_name", "opt_file_mode", "disconnection_spec",
  "signal_list", "opt_more_signal_list", "attribute_decl",
  "attribute_spec", "entity_spec", "entity_name_list",
  "opt_more_entity_name_list", "entity_class", "generation_scheme",
  "iteration_scheme", "if_scheme", "for_scheme", "while_scheme",
  "concurrent_stats", "opt_concurrent_stats", "concurrent_stat", "$@12",
  "concurrent_stat_1", "concurrent_stat_without_label",
  "concurrent_stat_with_label", "$@13", "concurrent_stat_without_label_1",
  "concurrent_stat_with_label_1", "block_stat", "@14", "$@15", "$@16",
  "$@17", "block_decl_part", "block_port_stuff", "block_generic_stuff",
  "block_guard", "opt_port_map_semi", "opt_generic_map_semi",
  "comp_inst_stat", "comp_mark_with_keyword", "opt_generic_map",
  "generic_map", "opt_port_map", "port_map", "concurrent_assertion_stat",
  "concurrent_procedure_call", "opt_postponed",
  "concurrent_signal_assign_stat", "condal_signal_assign",
  "condal_wavefrms", "condal_wavefrms_1", "wavefrm",
  "reverse_more_wavefrm", "wavefrm_element", "opt_wavefrm_after", "target",
  "opt_guarded", "sel_signal_assign", "sel_wavefrms", "sel_wavefrms_1",
  "generate_stat", "@18", "generate_declarative_items_block",
  "generate_declarative_items", "generate_declarative_item", "proc_stat",
  "@19", "@20", "opt_t_IS", "proc_decl_part", "opt_proc_sensitivity_list",
  "sensitivity_list", "reverse_opt_more_sensitivities", "signal_name",
  "seq_stats", "rev_seq_stats", "seq_stat", "assertion_stat",
  "report_stat", "opt_assertion_severity", "opt_assertion_report",
  "case_stat", "case_stat_alternative", "more_case_stat_alternatives",
  "if_stat", "if_stat_2", "if_stat_1", "condition", "loop_stat", "$@21",
  "opt_iteration_scheme", "opt_label", "next_stat", "exit_stat",
  "opt_when", "null_stat", "procedure_call_stat",
  "procedure_call_stat_without_args", "procedure_call_stat_with_args",
  "return_stat", "opt_expr", "signal_assign_stat", "delay_mechanism",
  "variable_assign_stat", "wait_stat", "opt_wait_for", "opt_wait_until",
  "opt_wait_on", "comp_decl", "@22", "block_config", "@23", "config_items",
  "use_clauses", "config_item", "comp_config", "@24", "opt_block_config",
  "opt_comp_binding_indic", "config_spec", "comp_spec", "comp_mark",
  "inst_list", "binding_indic", "pre_binding_indic", "@25", "$@26",
  "incremental_binding_indic", "entity_aspect", "opt_arch_id",
  "skip_designator", "skip_literal", "skip_enumeration_literal",
  "skip_physical_literal", "skip_opt_t_AbstractLit",
  "skip_physical_literal_no_default", "skip_idf_list", "skip_use_clause",
  "skip_sel_list", "skip_opt_generic_and_port_clauses",
  "skip_generic_clause", "skip_port_clause", "skip_opt_t_Identifier",
  "skip_architecture_body", "$@27", "$@28", "skip_architecture_decl_part",
  "skip_opt_architecture_end", "skip_configuration_declaration", "$@29",
  "skip_configuration_decl_part", "skip_opt_configuration_end",
  "skip_package_body", "$@30", "skip_package_body_decl_part",
  "skip_opt_package_body_end", "skip_common_decltve_item",
  "skip_block_decltve_item", "skip_package_body_decltve_item",
  "skip_subprog_decltve_item", "skip_proc_decltve_item",
  "skip_config_decltve_item", "skip_subprog_decl", "skip_subprog_spec",
  "skip_proc_or_func_spec", "skip_pure_or_impure", "skip_opt_interf_list",
  "skip_subprog_body", "$@31", "skip_opt_designator",
  "skip_subprog_body_decl_part", "skip_port_interf_list", "$@32",
  "skip_generic_interf_list", "$@33", "skip_interf_list", "$@34",
  "skip_interf_list_1", "skip_opt_more_interf_elements",
  "skip_interf_element", "skip_opt_t_BUS", "skip_opt_mode",
  "skip_opt_object_class", "skip_mode", "skip_association_list",
  "skip_named_association_list", "skip_association_list_1",
  "skip_gen_association_list", "skip_gen_association_list_1",
  "skip_association_elements", "skip_gen_association_elements",
  "skip_formal_part", "skip_actual_part", "skip_mark", "skip_expr",
  "skip_expr_or_attr", "skip_relation", "skip_and_expression",
  "skip_or_expression", "skip_xor_expression", "skip_xnor_expression",
  "skip_relation_or_attr", "skip_shift_expression",
  "skip_shift_expression_or_attr", "skip_simple_expression",
  "skip_simple_expression_or_attr", "skip_signed_term_or_attr",
  "skip_term", "skip_term_or_attr", "skip_factor", "skip_factor_or_attr",
  "skip_primary", "skip_primary_or_attr", "skip_name", "skip_name2",
  "skip_sel_name", "skip_simple_sel_name", "skip_suffix", "skip_ifts_name",
  "skip_attribute_prefix", "skip_range_attribute_name",
  "skip_attribute_name", "skip_range_attribute_name_with_param",
  "skip_opt_attribute_param", "skip_aggregate",
  "skip_rev_element_association_list2", "skip_qualified_expr",
  "skip_allocator", "skip_opt_index_association_list",
  "skip_element_association", "skip_choices", "skip_opt_more_choices",
  "skip_choice", "skip_decl_Identifier", "skip_type_decl",
  "skip_opt_type_def", "skip_type_definition",
  "skip_enumeration_type_definition", "skip_enumeration_literal_decls",
  "skip_opt_more_enumeration_literals", "skip_physical_type_definition",
  "skip_secondary_unit_decls", "skip_primary_unit_decl",
  "skip_secondary_unit_decl", "skip_unconstrained_array_definition",
  "skip_index_subtype_defs", "skip_opt_more_index_subtype_defs",
  "skip_index_subtype_definition", "skip_constrained_array_definition",
  "skip_record_type_definition", "skip_opt_more_element_decls",
  "skip_element_decl", "skip_access_type_definition",
  "skip_file_type_definition", "skip_subtype_decl", "skip_subtype_indic",
  "skip_subtype_indic1", "skip_opt_index_constraint",
  "skip_range_constraint", "skip_index_constraint",
  "skip_opt_more_discrete_ranges", "skip_discrete_range",
  "skip_discrete_range1", "skip_opt_direction_expr", "skip_range_spec",
  "skip_range_spec2", "skip_direction", "skip_constant_decl",
  "skip_signal_decl", "skip_opt_signal_kind", "skip_variable_decl",
  "skip_opt_var_init", "skip_object_class", "skip_signal_kind",
  "skip_alias_decl", "skip_file_decl", "skip_opt_open_mode",
  "skip_opt_file_name", "skip_opt_file_mode", "skip_disconnection_spec",
  "skip_signal_list", "skip_opt_more_signal_list", "skip_attribute_decl",
  "skip_attribute_spec", "skip_entity_spec", "skip_entity_name_list",
  "skip_opt_more_entity_name_list", "skip_entity_class",
  "skip_generation_scheme", "skip_iteration_scheme", "skip_if_scheme",
  "skip_for_scheme", "skip_while_scheme", "skip_concurrent_stats",
  "skip_opt_concurrent_stats", "skip_concurrent_stat", "$@35",
  "skip_concurrent_stat_1", "skip_concurrent_stat_without_label",
  "skip_concurrent_stat_with_label", "$@36",
  "skip_concurrent_stat_without_label_1",
  "skip_concurrent_stat_with_label_1", "skip_block_stat", "$@37", "$@38",
  "$@39", "$@40", "skip_block_decl_part", "skip_block_port_stuff",
  "skip_block_generic_stuff", "skip_block_guard", "skip_opt_port_map_semi",
  "skip_opt_generic_map_semi", "skip_comp_inst_stat",
  "skip_comp_mark_with_keyword", "skip_opt_generic_map",
  "skip_generic_map", "skip_opt_port_map", "skip_port_map",
  "skip_concurrent_assertion_stat", "skip_concurrent_procedure_call",
  "skip_opt_postponed", "skip_concurrent_signal_assign_stat",
  "skip_condal_signal_assign", "skip_condal_wavefrms",
  "skip_condal_wavefrms_1", "skip_wavefrm", "skip_reverse_more_wavefrm",
  "skip_wavefrm_element", "skip_opt_wavefrm_after", "skip_target",
  "skip_opt_guarded", "skip_sel_signal_assign", "skip_sel_wavefrms",
  "skip_sel_wavefrms_1", "skip_generate_stat", "$@41",
  "skip_generate_declarative_items_block",
  "skip_generate_declarative_items", "skip_generate_declarative_item",
  "skip_proc_stat", "$@42", "$@43", "skip_opt_t_IS", "skip_proc_decl_part",
  "skip_opt_proc_sensitivity_list", "skip_sensitivity_list",
  "skip_reverse_opt_more_sensitivities", "skip_signal_name",
  "skip_seq_stats", "skip_rev_seq_stats", "skip_seq_stat",
  "skip_assertion_stat", "skip_report_stat", "skip_opt_assertion_severity",
  "skip_opt_assertion_report", "skip_case_stat",
  "skip_case_stat_alternative", "skip_more_case_stat_alternatives",
  "skip_if_stat", "skip_if_stat_2", "skip_if_stat_1", "skip_condition",
  "skip_loop_stat", "$@44", "skip_opt_iteration_scheme", "skip_opt_label",
  "skip_next_stat", "skip_exit_stat", "skip_opt_when", "skip_null_stat",
  "skip_procedure_call_stat", "skip_procedure_call_stat_without_args",
  "skip_procedure_call_stat_with_args", "skip_return_stat",
  "skip_opt_expr", "skip_signal_assign_stat", "skip_delay_mechanism",
  "skip_variable_assign_stat", "skip_wait_stat", "skip_opt_wait_for",
  "skip_opt_wait_until", "skip_opt_wait_on", "skip_comp_decl", "$@45",
  "skip_block_config", "$@46", "skip_config_items", "skip_use_clauses",
  "skip_config_item", "skip_comp_config", "$@47", "skip_opt_block_config",
  "skip_opt_comp_binding_indic", "skip_config_spec", "skip_comp_spec",
  "skip_comp_mark", "skip_inst_list", "skip_binding_indic",
  "skip_pre_binding_indic", "$@48", "$@49",
  "skip_incremental_binding_indic", "skip_entity_aspect",
  "skip_opt_arch_id", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   129,   130,   131,   131,   132,   132,   133,   133,   133,
     133,   134,   134,   135,   136,   136,   137,   138,   138,   139,
     140,   140,   141,   141,   141,   141,   141,   141,   141,   141,
     142,   142,   143,   144,   145,   145,   147,   148,   146,   149,
     149,   149,   149,   149,   150,   151,   152,   152,   153,   153,
     154,   154,   155,   155,   157,   158,   156,   159,   159,   160,
     160,   162,   161,   163,   163,   164,   164,   166,   165,   167,
     167,   168,   168,   170,   169,   171,   171,   172,   172,   173,
     173,   173,   173,   173,   173,   173,   174,   174,   174,   174,
     174,   174,   175,   175,   175,   175,   175,   175,   175,   175,
     176,   176,   176,   176,   176,   176,   177,   177,   178,   178,
     178,   178,   178,   179,   179,   179,   179,   179,   180,   180,
     181,   182,   183,   183,   184,   184,   184,   185,   185,   187,
     186,   188,   188,   188,   189,   189,   190,   190,   192,   191,
     194,   193,   196,   195,   197,   198,   198,   199,   200,   200,
     201,   201,   202,   202,   203,   203,   203,   203,   203,   204,
     205,   206,   206,   207,   208,   208,   209,   209,   210,   210,
     211,   211,   212,   212,   213,   213,   214,   215,   215,   215,
     215,   215,   215,   215,   216,   217,   217,   218,   218,   219,
     219,   220,   220,   221,   221,   221,   221,   221,   221,   221,
     222,   223,   223,   223,   223,   223,   223,   223,   224,   225,
     225,   225,   225,   226,   226,   226,   227,   228,   228,   228,
     228,   228,   229,   230,   230,   230,   230,   231,   232,   232,
     232,   232,   232,   232,   233,   233,   234,   234,   234,   235,
     236,   236,   237,   237,   237,   238,   238,   239,   239,   240,
     240,   241,   241,   242,   243,   243,   244,   244,   245,   245,
     246,   246,   247,   247,   247,   248,   248,   249,   249,   250,
     251,   251,   252,   252,   252,   253,   254,   255,   255,   256,
     256,   256,   256,   256,   256,   256,   256,   257,   258,   259,
     259,   260,   261,   261,   262,   263,   264,   265,   266,   266,
     267,   268,   269,   269,   269,   270,   271,   271,   272,   273,
     274,   275,   276,   277,   277,   278,   278,   278,   279,   279,
     280,   281,   282,   282,   283,   283,   284,   284,   285,   285,
     286,   286,   287,   288,   288,   289,   290,   291,   291,   292,
     293,   293,   294,   294,   294,   294,   295,   295,   296,   297,
     298,   298,   299,   299,   300,   300,   300,   301,   302,   302,
     302,   303,   303,   304,   305,   306,   307,   307,   307,   308,
     308,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   310,   310,   311,   311,   312,   313,
     314,   315,   316,   316,   318,   317,   319,   319,   320,   322,
     321,   323,   323,   323,   323,   324,   324,   324,   324,   324,
     324,   324,   326,   327,   328,   329,   325,   330,   330,   331,
     331,   332,   332,   333,   333,   334,   334,   335,   335,   336,
     336,   336,   337,   337,   337,   338,   338,   339,   340,   340,
     341,   342,   342,   343,   343,   343,   344,   344,   345,   345,
     345,   345,   346,   347,   348,   348,   349,   350,   350,   351,
     352,   352,   353,   353,   354,   354,   355,   356,   357,   357,
     359,   358,   360,   360,   361,   361,   362,   362,   362,   362,
     362,   362,   362,   362,   364,   363,   365,   363,   366,   366,
     367,   367,   368,   368,   369,   370,   370,   371,   372,   373,
     373,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   375,   376,   377,   377,   378,   378,
     379,   380,   381,   381,   382,   383,   383,   384,   384,   385,
     387,   386,   388,   388,   389,   389,   390,   391,   392,   392,
     393,   394,   394,   395,   396,   397,   398,   398,   399,   400,
     400,   400,   400,   401,   402,   403,   403,   404,   404,   405,
     405,   407,   406,   409,   408,   410,   410,   411,   411,   412,
     412,   414,   413,   415,   415,   416,   416,   416,   417,   418,
     419,   420,   420,   420,   421,   423,   424,   422,   425,   425,
     426,   426,   426,   427,   427,   428,   428,   429,   429,   429,
     429,   430,   430,   431,   432,   432,   433,   434,   434,   435,
     436,   436,   437,   437,   437,   437,   437,   438,   439,   440,
     440,   442,   443,   441,   444,   444,   445,   445,   447,   446,
     448,   448,   449,   449,   451,   450,   452,   452,   453,   453,
     454,   454,   454,   454,   454,   454,   454,   455,   455,   455,
     455,   455,   455,   455,   455,   456,   456,   457,   457,   457,
     457,   457,   458,   458,   458,   458,   458,   459,   459,   460,
     461,   462,   462,   463,   463,   463,   464,   464,   466,   465,
     467,   467,   468,   468,   470,   469,   472,   471,   474,   473,
     475,   476,   476,   477,   478,   478,   479,   479,   480,   480,
     481,   481,   481,   481,   481,   482,   483,   484,   484,   485,
     486,   486,   487,   487,   488,   488,   489,   489,   490,   490,
     491,   491,   492,   493,   493,   493,   493,   493,   493,   493,
     494,   495,   495,   496,   496,   497,   497,   498,   498,   499,
     499,   499,   499,   499,   499,   499,   500,   501,   501,   501,
     501,   501,   501,   501,   502,   503,   503,   503,   503,   504,
     504,   504,   505,   506,   506,   506,   506,   506,   507,   508,
     508,   508,   508,   509,   510,   510,   510,   510,   510,   510,
     511,   511,   512,   512,   512,   513,   514,   514,   515,   515,
     515,   516,   516,   517,   517,   518,   518,   519,   519,   520,
     521,   521,   522,   522,   523,   523,   524,   524,   525,   525,
     525,   526,   526,   527,   527,   528,   529,   529,   530,   530,
     530,   531,   532,   533,   533,   534,   534,   534,   534,   534,
     534,   534,   534,   535,   536,   537,   537,   538,   539,   539,
     540,   541,   542,   543,   544,   544,   545,   546,   547,   548,
     548,   549,   550,   551,   552,   553,   553,   554,   554,   554,
     555,   555,   556,   557,   558,   558,   559,   559,   560,   560,
     561,   561,   562,   562,   563,   564,   564,   565,   566,   567,
     567,   568,   569,   569,   570,   570,   570,   570,   571,   571,
     572,   573,   574,   574,   575,   575,   576,   576,   576,   577,
     578,   578,   578,   579,   579,   580,   581,   582,   583,   583,
     583,   584,   584,   585,   585,   585,   585,   585,   585,   585,
     585,   585,   585,   585,   585,   585,   586,   586,   587,   587,
     588,   589,   590,   591,   592,   592,   594,   593,   595,   595,
     596,   598,   597,   599,   599,   599,   599,   600,   600,   600,
     600,   600,   600,   600,   602,   603,   604,   605,   601,   606,
     606,   607,   607,   608,   608,   609,   609,   610,   610,   611,
     611,   612,   612,   612,   613,   613,   613,   614,   614,   615,
     616,   616,   617,   618,   618,   619,   619,   619,   620,   620,
     621,   621,   621,   621,   622,   623,   624,   624,   625,   626,
     626,   627,   628,   628,   629,   629,   630,   630,   631,   632,
     633,   633,   635,   634,   636,   636,   637,   637,   638,   638,
     638,   638,   638,   638,   638,   638,   640,   639,   641,   639,
     642,   642,   643,   643,   644,   644,   645,   646,   646,   647,
     648,   649,   649,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   651,   652,   653,   653,
     654,   654,   655,   656,   657,   657,   658,   659,   659,   660,
     660,   661,   663,   662,   664,   664,   665,   665,   666,   667,
     668,   668,   669,   670,   670,   671,   672,   673,   674,   674,
     675,   676,   676,   676,   676,   677,   678,   679,   679,   680,
     680,   681,   681,   683,   682,   685,   684,   686,   686,   687,
     687,   688,   688,   690,   689,   691,   691,   692,   692,   692,
     693,   694,   695,   696,   696,   696,   697,   699,   700,   698,
     701,   701,   702,   702,   702,   703,   703
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     1,     2,     1,     3,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     0,     0,    11,     0,
       1,     1,     2,     2,     3,     3,     0,     2,     0,     2,
       2,     1,     0,     1,     0,     0,    13,     0,     2,     2,
       1,     0,    11,     0,     2,     2,     1,     0,     8,     0,
       2,     2,     1,     0,     9,     0,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     6,     0,     1,     1,     0,     1,     0,
      10,     0,     1,     1,     0,     1,     0,     2,     0,     2,
       0,     2,     0,     2,     4,     0,     3,     7,     0,     1,
       0,     1,     0,     1,     1,     1,     1,     1,     1,     4,
       1,     0,     3,     4,     0,     3,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     1,     1,
       3,     3,     3,     1,     2,     2,     1,     1,     3,     3,
       3,     3,     1,     1,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     0,     3,     2,     5,     4,     3,
       5,     3,     4,     3,     2,     0,     1,     3,     1,     2,
       0,     3,     1,     1,     1,     1,     4,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     0,
       2,     6,     0,     2,     2,     4,     6,     2,     0,     3,
       3,     4,     0,     1,     2,     5,     0,     2,     4,     2,
       3,     5,     1,     2,     1,     3,     2,     3,     0,     1,
       2,     4,     0,     3,     1,     1,     1,     3,     0,     2,
       1,     3,     2,     1,     1,     6,     7,     0,     1,     6,
       0,     2,     1,     1,     1,     1,     1,     1,     7,     7,
       0,     2,     0,     3,     0,     1,     1,     7,     2,     1,
       1,     0,     3,     5,     7,     3,     2,     1,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       2,     2,     0,     2,     0,     2,     1,     1,     1,     0,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     0,     0,     0,    16,     0,     2,     0,
       2,     0,     2,     0,     3,     0,     2,     0,     2,     6,
       6,     4,     2,     3,     2,     0,     1,     3,     0,     1,
       3,     1,     2,     2,     1,     2,     0,     1,     1,     2,
       1,     2,     6,     2,     0,     5,     2,     0,     3,     2,
       0,     2,     1,     1,     0,     1,     9,     4,     0,     5,
       0,     9,     0,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     0,    12,     0,    13,     0,     1,
       0,     2,     0,     3,     2,     0,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     0,     2,     0,     2,
       8,     4,     0,     2,     9,     0,     2,     0,     5,     1,
       0,     9,     0,     1,     0,     2,     4,     4,     0,     2,
       2,     1,     1,     2,     2,     3,     0,     1,     5,     0,
       1,     1,     3,     4,     5,     0,     2,     0,     2,     0,
       2,     0,     9,     0,     8,     0,     2,     0,     2,     1,
       1,     0,     8,     0,     1,     0,     2,     2,     4,     3,
       1,     1,     1,     1,     1,     0,     0,     6,     2,     1,
       3,     2,     1,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     1,     2,     1,     3,     3,
       1,     3,     0,     1,     1,     2,     2,     3,     3,     0,
       1,     0,     0,    13,     0,     2,     2,     1,     0,    11,
       0,     2,     2,     1,     0,     9,     0,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     6,     0,     1,     1,     0,     1,     0,     9,
       0,     1,     0,     2,     0,     2,     0,     2,     0,     2,
       4,     0,     3,     7,     0,     1,     0,     1,     0,     1,
       1,     1,     1,     1,     1,     4,     1,     0,     3,     4,
       0,     3,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     1,     3,     3,
       3,     3,     3,     3,     1,     1,     3,     3,     3,     1,
       2,     2,     1,     1,     3,     3,     3,     3,     1,     1,
       3,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       0,     3,     2,     5,     4,     3,     5,     3,     4,     3,
       2,     0,     1,     3,     1,     2,     0,     3,     1,     1,
       1,     1,     4,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     0,     2,     6,     0,     2,
       2,     4,     6,     2,     0,     3,     3,     4,     5,     0,
       2,     4,     2,     3,     5,     2,     1,     3,     2,     3,
       0,     1,     2,     4,     0,     3,     1,     1,     1,     3,
       0,     2,     1,     3,     2,     1,     1,     6,     7,     0,
       1,     6,     0,     2,     1,     1,     1,     1,     1,     1,
       7,     7,     0,     2,     0,     3,     0,     1,     1,     7,
       2,     1,     1,     0,     3,     5,     7,     3,     2,     1,
       1,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     2,     2,     0,     2,     0,     2,     1,     1,
       1,     0,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     0,     0,     0,    16,     0,
       2,     0,     2,     0,     2,     0,     3,     0,     2,     0,
       2,     6,     6,     4,     2,     3,     2,     0,     1,     3,
       0,     1,     3,     1,     2,     2,     1,     2,     0,     1,
       1,     2,     1,     2,     6,     2,     0,     5,     2,     0,
       3,     2,     0,     2,     1,     1,     0,     1,     9,     4,
       0,     5,     0,     9,     0,     2,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     0,    12,     0,    13,
       0,     1,     0,     2,     0,     3,     2,     0,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     0,     2,
       0,     2,     8,     4,     0,     2,     9,     0,     2,     0,
       5,     1,     0,     9,     0,     1,     0,     2,     4,     4,
       0,     2,     2,     1,     1,     2,     2,     3,     0,     1,
       5,     0,     1,     1,     3,     4,     5,     0,     2,     0,
       2,     0,     2,     0,     9,     0,     8,     0,     2,     0,
       2,     1,     1,     0,     8,     0,     1,     0,     2,     2,
       4,     3,     1,     1,     1,     1,     1,     0,     0,     6,
       2,     1,     3,     2,     1,     0,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
      20,     0,     2,     4,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,    19,    21,    30,    31,    22,    25,
      23,    24,    26,    28,    27,    29,     0,     0,     0,     0,
       0,    17,     0,     0,     0,     0,   174,   236,     0,   234,
       0,   235,   175,   238,     0,   252,   237,     0,     0,     0,
       0,    36,     0,    32,     0,     0,    67,     0,    33,   247,
       0,   245,     0,   248,   246,   249,   250,   251,     0,     0,
       0,     0,    39,    18,    73,   634,    69,   175,     0,    10,
     173,     0,     0,     0,     0,     0,     7,     8,   229,     9,
     168,   164,     0,   167,   234,   172,     0,   177,   178,   179,
     180,   181,     0,   193,     0,   201,   209,     0,   213,   217,
       0,   223,   228,   175,   230,     0,   231,   232,   326,   169,
     244,   243,     5,     6,   242,   239,    54,   621,    61,   628,
     140,   138,    46,    40,    41,    75,   636,   124,   265,   264,
     234,   215,   216,   228,   214,   226,   227,   225,   274,   268,
     176,     0,     0,   270,   273,    16,     0,     0,     0,     0,
     247,   318,   316,   334,   333,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,     0,    57,   624,
      63,   630,     0,     0,     0,     0,    37,    42,    43,   124,
     673,     0,     0,     0,     0,     0,    52,     0,   126,     0,
     125,     0,     0,     0,    85,   100,    70,    84,     0,   121,
       0,    79,    80,    81,   105,    83,    82,   104,   102,   103,
     101,   266,   265,   263,   233,     0,     0,   269,   163,     0,
     166,   172,   171,   328,   320,     0,   261,   245,   317,   315,
     327,   176,   185,   184,   182,   183,   187,   191,   189,   186,
     188,   190,   192,   199,   200,   198,   197,   196,   195,   194,
     206,   208,   207,   204,   202,   205,   203,   212,   211,   210,
     221,   222,   220,   219,   218,   224,   268,   259,     0,   124,
     673,     0,     0,    44,   152,   141,    45,   139,    48,    86,
      47,     0,    87,    91,    90,    88,    89,    52,   106,    76,
     107,     0,     0,   619,     0,   675,     0,   674,     0,     0,
       0,   646,   655,   637,   645,     0,   670,     0,   656,   640,
     641,   642,   644,   643,     0,     0,   488,     0,   360,   359,
     497,     0,   361,    52,    53,    72,     0,     0,   127,     0,
     275,     0,   277,   120,     0,   262,   258,   267,     0,   165,
     332,     0,   268,     0,    55,     0,    92,    58,    93,    99,
      98,    95,    96,    94,    97,     0,   622,     0,     0,     0,
       0,   647,   625,   648,   654,   653,   650,   651,   649,   652,
       0,     0,   119,    64,   118,     0,     0,     0,   668,   631,
     667,     0,   342,   345,   343,   344,   145,     0,   153,   392,
       0,   129,     0,    78,     0,     0,   607,     0,     0,   620,
     639,     0,     0,   676,   821,     0,   823,   720,   782,     0,
     780,     0,   781,   721,   784,     0,   798,   783,   678,   669,
       0,     0,     0,     0,   489,   561,     0,     0,   358,    71,
      68,     0,   122,   128,     0,     0,     0,     0,     0,   127,
     257,   272,   271,   329,   260,   267,   392,   582,   583,   581,
     585,     0,     0,   934,  1030,   902,   901,  1039,   721,     0,
     903,  1124,  1125,  1123,  1127,     0,     0,     0,   563,    52,
       0,  1105,   619,     0,     0,    49,   394,    52,   136,    52,
      74,     0,     0,     0,   619,   635,     0,   671,   677,     0,
       0,     0,     0,     0,   609,   793,     0,   791,     0,   794,
     792,   795,   796,   797,   682,   595,   596,   676,   318,     0,
     312,   314,   368,   367,   369,     0,     0,   234,    39,   340,
     234,     0,   350,   143,   337,     0,     0,     0,     0,     0,
       0,   278,   279,   281,   282,   283,   284,   285,   286,   280,
     276,     0,   394,     0,   584,     0,     0,     0,     0,   936,
    1031,  1103,     0,   900,     0,  1126,     0,     0,     0,   567,
      52,    66,     0,  1109,   619,   633,     0,   144,   152,   150,
     393,     0,    52,     0,    51,   124,    77,   860,     0,   856,
     608,   882,   638,   892,   698,   689,     0,     0,     0,     0,
       0,     0,     0,   824,   825,   827,   828,   829,   830,   831,
     832,   826,   822,   721,     0,   600,   719,     0,     0,     0,
       0,     0,   597,   598,   775,   599,   714,   710,     0,   713,
     780,   718,     0,   723,   724,   725,   726,   727,     0,   739,
       0,   747,   755,     0,   759,   763,     0,   769,   774,   776,
       0,   777,   778,   868,   715,   790,   789,   788,   785,   673,
       0,   313,     0,   366,     0,     0,   363,     0,     0,     0,
       0,   362,     0,   352,   346,   347,   340,   338,   311,   309,
       0,     0,     0,     0,   306,    11,    12,   289,     0,     0,
       0,    52,   393,   578,     0,   580,   579,   910,   909,   911,
       0,     0,   780,   619,   935,     0,   612,   780,     0,  1120,
       0,  1122,  1121,   879,   565,    65,    62,  1107,   632,   629,
     146,   157,   154,   156,   158,   155,     0,   151,     0,     0,
     492,     0,     0,   174,   234,   462,   235,   463,   395,   396,
     397,   398,   401,   402,   403,   448,     0,   450,   404,   441,
     444,    50,    38,   499,     0,   108,   137,   109,   112,   110,
     111,   791,   860,   855,   858,     0,     0,     0,     0,   894,
     884,   887,   885,   886,   691,     0,   699,   854,   852,     0,
       0,     0,   780,   870,   774,   862,     0,   849,   601,   602,
     835,     0,     0,   811,   810,   761,   762,   760,   772,   773,
     771,   820,   814,   722,     0,     0,   816,   819,   606,     0,
       0,     0,   793,   876,   875,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   802,     0,  1041,     0,
     657,   683,   658,   661,   659,   660,     0,     0,     0,     0,
     372,   375,   374,   383,   371,   380,   376,   373,   379,   381,
     378,   377,   382,   365,     0,   341,   335,     0,   351,   354,
       0,     0,   234,     0,   252,   330,     0,   298,   324,   322,
     325,     0,   234,     0,     0,     0,   288,   287,     0,   292,
     123,    52,    60,     0,     0,     0,   592,   586,   908,     0,
       0,   905,   619,   627,     0,     0,     0,  1034,     0,     0,
     720,   780,  1004,   781,  1005,   937,   938,   939,   940,   943,
     944,   945,   990,     0,   992,   946,   983,   986,   686,   684,
       0,   613,   614,     0,   904,     0,     0,  1134,  1128,   888,
     889,   882,   880,   568,     0,  1110,     0,   148,   529,   518,
     492,   234,   449,   451,   442,   445,   541,   542,     0,   488,
       0,   399,   443,   544,   464,     0,   498,     0,   859,   857,
       0,   883,   722,   877,   893,   896,     0,     0,     0,   780,
       0,   798,   872,     0,   844,   866,   864,   867,     0,   780,
     874,     0,     0,     0,     0,   834,   833,     0,   838,   812,
     811,   809,   779,     0,     0,   815,   709,     0,   712,   718,
     717,     0,   807,   869,   731,   730,   728,   729,   733,   737,
     735,   732,   734,   736,   738,   745,   746,   744,   743,   742,
     741,   740,   752,   754,   753,   750,   748,   751,   749,   758,
     757,   756,   767,   768,   766,   765,   764,   770,   814,   805,
       0,     0,  1040,     0,   672,   348,   370,   364,    52,   357,
     355,   356,     0,   349,   336,     0,     0,     0,   253,     0,
       0,   297,     0,   301,     0,   302,   307,   290,   294,     0,
      59,    56,   591,   241,   593,   435,     0,     0,   914,   917,
     916,   925,   913,   922,   918,   915,   921,   923,   920,   919,
     924,   907,   626,   623,  1071,  1060,  1034,   780,   991,   993,
     984,   987,  1083,  1084,     0,  1030,     0,   941,   985,  1086,
    1006,     0,     0,     0,     0,     0,   615,   616,     0,  1133,
     787,  1135,   977,     0,     0,     0,   569,   566,   570,     0,
       0,  1111,  1108,  1112,   149,   340,     0,   516,   488,   543,
       0,   495,   484,     0,     0,   465,   549,   131,     0,    52,
       0,    52,     0,     0,   546,   559,   174,     0,   500,   501,
     502,   503,   505,   506,   532,   507,   504,   508,   509,   510,
     511,   512,   513,     0,   890,   897,   898,     0,   891,   690,
     698,   696,     0,     0,     0,   799,     0,     0,   843,     0,
     847,   871,     0,     0,   850,   836,   840,     0,   808,   804,
     813,     0,   711,   814,     0,   680,     0,   619,     0,   619,
       0,     0,  1088,  1101,   720,     0,  1042,  1043,  1044,  1045,
    1047,  1048,  1074,  1049,  1046,  1050,  1051,  1052,  1053,  1054,
    1055,     0,     0,   353,   300,   331,     0,     0,   234,   298,
     321,     0,   308,    52,   303,   305,     0,     0,   293,     0,
       0,   590,     0,   438,   436,   912,   906,     0,  1058,  1030,
    1085,     0,  1037,  1026,     0,     0,  1007,  1091,   617,   687,
     618,   685,   619,   899,     0,     0,  1132,     0,   980,   978,
     878,     0,   174,   575,     0,   720,  1117,   147,   519,     0,
       0,   486,   493,   494,   490,     0,   423,     0,     0,     0,
       0,     0,   234,     0,   384,   385,   400,   405,   406,   435,
     407,   408,   409,   410,   411,     0,   551,     0,   550,   454,
     133,   132,   134,     0,   538,     0,   538,   540,   516,   547,
       0,     0,   557,   535,   549,     0,     0,   533,   386,   387,
       0,   340,   895,   692,   703,   700,   702,   704,   701,     0,
     697,   846,   873,     0,     0,   780,   844,   863,     0,   851,
     848,     0,     0,   839,   803,   818,   817,   806,   813,   681,
       0,     0,  1080,     0,  1080,  1082,  1058,  1089,     0,     0,
    1099,  1077,  1091,     0,     0,     0,  1075,   928,   929,     0,
     882,   562,   255,   296,     0,   299,   234,   323,   304,   291,
      14,     0,   240,     0,     0,   587,   439,  1061,     0,     0,
    1028,  1035,  1036,  1032,     0,   965,     0,     0,     0,     0,
     780,     0,   926,   927,   942,   947,   948,   977,   949,   950,
     951,   952,   953,     0,  1093,     0,  1092,   996,     0,     0,
     786,     0,     0,  1129,   981,   564,   438,   589,   571,     0,
       0,  1106,   980,  1131,  1113,     0,     0,   517,   514,   490,
       0,   124,   464,     0,   488,   432,   434,   593,     0,   388,
     470,   438,     0,     0,     0,     0,     0,   135,     0,     0,
       0,     0,   499,     0,     0,   545,   560,     0,   555,     0,
       0,   390,   530,     0,   694,   801,   842,     0,   845,   780,
     865,   837,   604,   679,     0,     0,     0,  1041,     0,     0,
    1087,  1102,     0,  1097,     0,     0,     0,   932,  1072,     0,
      15,     0,     0,   594,     0,   160,   437,     0,  1059,  1056,
    1032,     0,   673,  1006,     0,  1030,   974,   976,  1135,   930,
    1012,   980,     0,     0,     0,     0,     0,  1104,  1136,     0,
     706,   979,     0,   588,   573,   577,   576,  1130,  1115,  1119,
    1118,   124,   496,   499,   113,   491,   114,   117,   115,   116,
     549,     0,   412,   433,     0,   474,     0,     0,     0,   552,
     452,   460,   453,   457,   130,     0,   522,   539,   537,   527,
     536,   515,   558,     0,     0,     0,   553,   499,   339,   695,
     882,   605,     0,     0,     0,  1064,  1081,  1079,  1069,  1078,
    1057,  1100,     0,     0,  1002,     0,   999,  1095,     0,  1041,
     881,   295,    13,   161,   440,   673,  1038,  1041,   662,  1033,
     663,   666,   664,   665,  1091,     0,   954,   975,  1016,     0,
       0,     0,  1094,   994,   995,   707,   982,   574,     0,  1116,
       0,   499,     0,   468,   424,   421,   389,   392,   124,   431,
     438,   435,     0,   459,     0,   456,     0,     0,   525,   556,
     554,   548,     0,   693,   841,   603,     0,     0,  1067,  1098,
    1096,     0,  1001,  1090,   998,   931,     0,     0,  1041,     0,
    1010,   966,   963,   934,   673,   973,   980,   977,     0,     0,
       0,     0,     0,   446,     0,     0,   427,   413,     0,   473,
     476,   477,   483,   482,   479,   480,   475,   478,   481,     0,
       0,   461,     0,     0,   499,     0,   523,   499,     0,     0,
       0,  1041,     0,  1065,  1041,     0,     0,  1003,     0,     0,
     159,     0,     0,   988,     0,     0,   969,   955,     0,   936,
    1015,  1018,  1019,  1025,  1024,  1021,  1022,  1017,  1020,  1023,
       0,     0,     0,   705,     0,     0,     0,   446,   447,     0,
     466,     0,   422,     0,   419,     0,   429,   430,   455,   458,
     521,     0,   526,     0,     0,    52,  1063,     0,  1068,     0,
       0,  1000,   619,   162,   988,   989,     0,  1008,     0,   964,
       0,   961,     0,   935,   971,   972,   997,   708,   572,  1114,
       0,    52,     0,   428,   425,   414,    52,   520,   499,     0,
       0,  1062,  1041,     0,     0,     0,   619,     0,   970,   967,
     956,   619,    52,     0,   467,   420,     0,   417,     0,   528,
     524,   531,  1070,  1066,  1073,   619,     0,  1009,   962,     0,
     959,     0,     0,   485,   469,   426,   124,   471,     0,  1027,
    1011,   968,   673,  1013,   487,   415,   418,  1029,   957,   960,
     392,   934,   394,   936,     0,     0,    52,   619,     0,     0,
     416,   958
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   124,    88,   707,  1561,  1562,    89,   479,
       3,     4,    14,    15,    16,   224,    38,    18,    72,   308,
     132,   133,   134,   206,   420,   603,   355,    19,   198,   476,
     299,   923,    20,   200,   301,   592,    21,    76,   137,   356,
      22,   135,   209,   424,   376,   310,   377,   226,   319,   776,
    1605,   403,   227,   311,   229,   230,   462,   378,   508,  1362,
    1518,   605,   204,   205,   202,   203,   463,   464,   305,   503,
     416,  1175,   746,   417,   747,  1565,  1566,  1727,    61,   156,
      90,    91,    92,    93,   140,   978,   261,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     290,   109,   110,   111,   143,    41,   113,  1114,   125,    43,
      44,    45,    46,   905,  1098,   114,   115,   116,   117,   243,
     151,   152,   247,   153,   361,   231,   468,   561,   562,   708,
     916,   563,  1109,   919,  1288,   564,   906,  1101,   907,   565,
    1285,   566,   914,   704,   567,   568,   232,   908,   540,   541,
     681,   162,   701,  1102,   909,   154,   370,   910,   254,   165,
     233,   379,   696,  1607,   689,   418,   697,   235,   236,   693,
     900,  1092,   380,   351,   458,   381,   382,   545,   546,   683,
     893,  1343,  1377,  1344,  1345,  1379,   505,   506,   712,   601,
     758,   759,   760,  1184,   761,  1346,  1347,  1695,  1814,  1877,
    1910,  1896,  1855,  1747,  1504,  1875,  1812,  1348,  1349,  1293,
    1294,  1445,  1446,   762,   763,  1809,   764,   765,  1515,  1516,
    1622,  1705,  1623,  1703,   766,  1186,   767,  1744,  1745,  1353,
    1615,  1697,  1698,  1756,   768,  1334,  1499,   455,  1501,   989,
    1180,  1333,  1181,   995,   996,  1198,   769,  1200,  1330,  1177,
    1201,  1626,  1707,  1202,  1769,  1708,   979,  1203,  1637,  1380,
    1204,  1205,  1206,  1521,  1207,   985,   986,   770,  1209,  1370,
    1210,  1359,  1211,  1212,  1634,  1528,  1372,   383,   548,   405,
     589,   974,   734,  1167,  1168,  1594,  1688,  1488,   384,   480,
     716,   481,   573,   574,   575,  1115,  1490,   927,  1291,   537,
     644,   810,  1642,  1643,   645,   493,   331,   439,   960,   961,
     962,   430,    23,   199,   483,   300,   934,    24,   201,   302,
     596,    25,   136,   210,   431,   391,   392,   333,   871,  1669,
     409,   334,   335,   336,   337,   517,   393,   534,  1410,   679,
    1153,  1154,  1151,  1152,   518,   519,   615,  1007,   794,  1640,
    1389,   795,  1390,  1590,  1591,  1739,   527,   829,   646,   647,
     648,   649,   802,  1134,  1002,   652,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   664,  1072,   665,
     666,   667,   804,   442,   488,  1161,   678,   444,   445,   446,
     447,  1012,  1225,   669,   670,   671,   672,  1031,   824,   825,
    1035,   826,   435,   339,   522,   623,   624,   811,  1025,   625,
    1237,  1028,  1403,   626,  1013,  1228,  1014,   627,   628,  1023,
     807,   629,   630,   340,  1015,   609,   783,   784,   800,  1229,
    1016,   827,  1020,  1017,   805,   835,   341,   394,   971,  1671,
     787,   796,   972,   342,   343,   789,  1006,  1217,   395,   489,
     583,   396,   397,   720,   721,   928,  1131,  1461,  1426,  1462,
    1427,  1428,  1788,   579,   724,   725,   945,   946,   947,  1305,
     948,  1464,  1465,  1732,  1841,  1890,  1911,  1902,  1870,  1787,
    1575,  1888,  1839,  1466,  1467,  1318,  1319,  1483,  1484,   949,
     950,  1836,   951,   952,  1585,  1586,  1655,  1724,  1656,  1722,
     953,  1307,   954,  1784,  1785,  1471,  1678,  1733,  1734,  1797,
     955,  1453,  1570,   581,  1572,  1145,  1301,  1452,  1302,  1081,
    1082,  1256,   956,  1258,  1449,  1298,  1259,  1645,  1717,  1260,
    1776,  1718,  1135,  1261,  1659,  1429,  1262,  1263,  1264,  1546,
    1265,  1141,  1142,   957,  1267,  1418,  1268,  1477,  1269,  1270,
    1653,  1553,  1420,   398,   726,   411,   593,   976,   737,  1172,
    1173,  1598,  1690,  1494,   399,   494,   732,   495,   584,   585,
     586,  1162,  1496,   968,  1316
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1615
static const yytype_int16 yypact[] =
{
     164,   185, -1615, -1615,  1168, -1615,    65,    92,   114,   199,
     295,   359,   120,   510, -1615, -1615, -1615, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615, -1615, -1615,   259,   416,   443,   460,
     189, -1615,   315,   407,   417,   509, -1615, -1615,   489,   592,
     449,   795,   605, -1615,   423, -1615, -1615,   440,   491,   533,
     540, -1615,   548, -1615,   538,   649, -1615,   510, -1615, -1615,
    1832, -1615,   128, -1615, -1615, -1615, -1615, -1615,   659,   671,
     703,   721,   166, -1615, -1615, -1615, -1615,   657,   510, -1615,
   -1615,  1008,  1008,   924,   924,  1871,   613, -1615, -1615, -1615,
   -1615, -1615,   248, -1615,   950,   131,   648,   763,   699,   680,
     717,   728,  1300,  1493,  1447,  2021, -1615,  1377,  1450, -1615,
     684,   707,   748, -1615, -1615,   876, -1615, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
   -1615, -1615, -1615,   780,   812, -1615, -1615,  1795,  1023, -1615,
     889,  1377, -1615,   449,  1377, -1615, -1615, -1615, -1615,   734,
     362,   747,   755, -1615, -1615, -1615,   908,  1832,   510,  1961,
     753,   623, -1615, -1615, -1615,  1961,  1961,  1961,  1961,  1961,
    1961,  1961,  1961,  1961,  1961,  1961,  1961,  1961,  1961,  1961,
    1961,  1961,  1961,  1961,  1961,  1961,  1961,  1961,  1008,  1008,
    1008,  1008,  1008,  1008,  1008,   924, -1615,  1871, -1615, -1615,
   -1615, -1615,   760,   772,   771,   772,  1837, -1615, -1615,   767,
    1030,   793,   804,   820,   359,   137,    93,   825, -1615,   830,
   -1615,   359,   843,   843, -1615, -1615, -1615, -1615,   779, -1615,
     895, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
   -1615,   751,   821, -1615, -1615,  1871,  1961,   857, -1615,  1832,
   -1615, -1615,   449,   131, -1615,  1871, -1615,  1098, -1615, -1615,
   -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
     781, -1615,   781,   781,   781,   781,   781,  1377,  1377,  1377,
   -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,   878,  1593,
    1667,   135,   326, -1615,   643, -1615, -1615, -1615,  1001, -1615,
   -1615,   102, -1615, -1615, -1615, -1615, -1615,   111, -1615, -1615,
   -1615,   891,   929,   178,   932, -1615,   935, -1615,   945,   945,
     901, -1615, -1615, -1615, -1615,   104, -1615,  1051, -1615, -1615,
   -1615, -1615, -1615, -1615,   980,   129,  1067,   387, -1615, -1615,
     449,   998, -1615,   994, -1615, -1615,  1019,  1026,  1027,   403,
   -1615,  1117,  1145, -1615,   948, -1615, -1615,  1048,  1871, -1615,
   -1615,  1961,  1052,  1961, -1615,   124, -1615, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615, -1615,  1065, -1615,  1076,   201,   149,
     929, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
    1079,   510, -1615, -1615, -1615,  1183,  1097,   901, -1615, -1615,
   -1615,  1189, -1615, -1615, -1615, -1615, -1615,   359, -1615, -1615,
    1201, -1615,  1218, -1615,  1125,  1131, -1615,   719,  1241, -1615,
   -1615,  1154,  1172,  1179, -1615,  1254,  1257, -1615, -1615,   668,
    1015,  1177,  1058,   679, -1615,   475, -1615, -1615, -1615, -1615,
    1068,   510,   233,   510, -1615, -1615,   510,   510,  1186, -1615,
   -1615,   510, -1615, -1615,   772,   510,   510,   397,  1185,  1027,
   -1615,   131, -1615, -1615, -1615, -1615, -1615, -1615, -1615,  1190,
   -1615,  1203,   243, -1615,  1274, -1615, -1615,  1177, -1615,  1207,
   -1615, -1615, -1615,  1216, -1615,  1217,   847,  1290,   449,   130,
    1292,  1177,   119,   285,   855, -1615, -1615,   108, -1615,   994,
   -1615,   901,  1226,   901,  1230, -1615,   901, -1615, -1615,  1245,
     901,   490,  1244,   901, -1615, -1615,  1877, -1615,   247, -1615,
   -1615, -1615, -1615, -1615, -1615, -1615, -1615,  1179,   867,  1325,
   -1615, -1615, -1615, -1615, -1615,  1327,  1261,   698,   166,  1265,
     173,   510,  1334, -1615,   312,  1272,   510,  1289,  1353,   359,
    1126, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,  1322,
   -1615,  1343,  1392,  1310, -1615,  1349,   510,   257,   901,  1398,
   -1615, -1615,   901,  1293,  1313, -1615,  1350,   901,   901, -1615,
     994, -1615,  1323, -1615,  1230, -1615,  1333, -1615,   643,  1193,
    1414,   409,   994,  1336, -1615,   865, -1615,  1148,  1405, -1615,
   -1615,  1330, -1615,  1397,   718, -1615,  1337,   901,  1344,  1401,
    1980,   929,  1144, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
   -1615,  1374, -1615,   725,   901, -1615, -1615,  1367,  1367,  1133,
    1133,  1913,  1354, -1615, -1615, -1615, -1615, -1615,   709, -1615,
    1170,   138,   846,  1454,  1408,  1370,  1372,   907,  1548,  1612,
    2037,  2049, -1615,  1501,  1520, -1615,  1359,  1363,   801, -1615,
    1165, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,  1242,
    1417, -1615,   510,  1373,  1961,  1382, -1615,  1470,  1961,  1379,
    1961, -1615,  1961,  1464, -1615, -1615,  1265, -1615, -1615, -1615,
    1961,  1455,   510,  1005, -1615, -1615, -1615,  1390,  1399,  1389,
     510,   134, -1615, -1615,   418,   821, -1615, -1615, -1615, -1615,
    1479,  1404,   729,   123, -1615,   535,   621,   184,   901, -1615,
     453,   853, -1615,   390,  1440, -1615, -1615,  1443, -1615, -1615,
   -1615, -1615, -1615, -1615, -1615, -1615,   510, -1615,  1961,   218,
    1418,  1961,  1871,  1413,   743,   449,   893, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615, -1615, -1615,  1437, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615,   359, -1615, -1615, -1615, -1615, -1615,
   -1615,  1123,   700, -1615, -1615,   901,  1980,  1416,  1980,  1496,
   -1615, -1615, -1615, -1615, -1615,   929, -1615, -1615, -1615,  1980,
    1487,   901,  1175,   138,  1177, -1615,  1009, -1615, -1615, -1615,
    1424,  1427,  1420,  1307, -1615,  1501, -1615,  1501, -1615, -1615,
   -1615, -1615,  1428,   412,  1431,  1433, -1615, -1615, -1615,  1197,
    1877,   901,  1430, -1615, -1615,  1980,  1980,  1980,  1980,  1980,
    1980,  1980,  1980,  1980,  1980,  1980,  1980,  1980,  1980,  1980,
    1980,  1980,  1980,  1980,  1980,  1980,  1980,  1980,  1367,  1367,
    1367,  1367,  1367,  1367,  1367,  1133, -1615,  1913, -1615,   929,
   -1615, -1615, -1615, -1615, -1615, -1615,   901,   438,   948,  1432,
   -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615,  1542, -1615, -1615,  1444, -1615,   392,
    1445,  1448,  1235,   131,   567, -1615,  1463,  1465, -1615, -1615,
   -1615,   510,   923,   510,   122,  1126, -1615, -1615,  1461, -1615,
   -1615,   994, -1615,  1475,   510,  1456, -1615, -1615,  1480,  1980,
    1865, -1615,  1230, -1615,  1482,  1980,   531,  1484,  1980,  1913,
    1495,   971,  1177,   987, -1615, -1615, -1615, -1615, -1615, -1615,
   -1615, -1615, -1615,  1505, -1615, -1615, -1615, -1615, -1615, -1615,
    1587,  1558,  1584,  1980, -1615,   901,  1494, -1615, -1615, -1615,
   -1615,  1330, -1615, -1615,   629, -1615,   726,  1605, -1615,  1560,
    1418,  1040, -1615, -1615, -1615, -1615, -1615, -1615,   510,  1067,
    1559, -1615, -1615, -1615,  1598,  1614,   789,  1029, -1615, -1615,
     637, -1615, -1615, -1615, -1615,   513,  1531,   646,  1090,  1386,
     138,   827, -1615,  1536,  1539, -1615, -1615, -1615,   901,  1084,
   -1615,  1980,   901,   141,  1144, -1615, -1615,  1533, -1615,   864,
     853, -1615, -1615,  1913,  1980,  1537, -1615,  1877, -1615, -1615,
    1177,  1913, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
   -1615, -1615,   882, -1615,   882,   882,   882,   882,   882,  1501,
    1501,  1501, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
    1543,  1635,   919,  1103, -1615, -1615, -1615, -1615,   994, -1615,
   -1615, -1615,  1961, -1615, -1615,   978,  1961,  1961, -1615,  1613,
     510, -1615,  1222, -1615,  1550,   107, -1615, -1615, -1615,   151,
   -1615, -1615,   821, -1615,   200,  1632,  1068,  1551, -1615, -1615,
   -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615, -1615,  1603,  1484,  1122, -1615, -1615,
   -1615, -1615, -1615, -1615,   901,  1274,  1601, -1615, -1615, -1615,
    1640,  1557,  1245,  1562,  1245,  1665, -1615, -1615,  1569,   853,
   -1615,   375,  1651,  1572,  1662,   266, -1615, -1615, -1615,  1668,
     268, -1615, -1615, -1615, -1615,  1265,  1961,  1622,  1067, -1615,
    1585, -1615, -1615,   499,   689, -1615,   507,   156,  1961,   994,
    1961,   994,  1582,  1961,  1961,  1650,  1597,    97, -1615, -1615,
   -1615, -1615, -1615, -1615,   286, -1615, -1615, -1615, -1615, -1615,
   -1615, -1615, -1615,   510, -1615, -1615, -1615,  1980, -1615, -1615,
     718,  1276,  1941,  1980,  1980, -1615,  1664,   901, -1615,  1225,
   -1615, -1615,  1599,  1663, -1615, -1615, -1615,   180, -1615, -1615,
    1602,  1913, -1615,  1626,  1980,  1068,  1980,  1230,  1980,  1230,
    1624,  1980,  1980,  1692,  1630,   300, -1615, -1615, -1615, -1615,
   -1615, -1615,   320, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
   -1615,   901,  1631, -1615, -1615, -1615,  1634,   510,   520,  1465,
   -1615,  1961, -1615,   994, -1615, -1615,  1670,  1652, -1615,  1633,
    1636, -1615,  1710,  1698, -1615, -1615, -1615,  1980,  1690,  1274,
   -1615,  1658, -1615, -1615,   600,  1034, -1615,   563, -1615, -1615,
   -1615, -1615,  1230, -1615,  1639,  1648, -1615,  1720,  1716, -1615,
   -1615,  1659,  1111,   369,  1666,  1150,   582, -1615, -1615,  1961,
    1672, -1615, -1615,  1673, -1615,  1684,  1669,   510,   510,  1456,
    1656,  1961,   445,  1761, -1615, -1615, -1615, -1615, -1615,  1632,
   -1615, -1615, -1615, -1615, -1615,   642, -1615,  1961, -1615, -1615,
   -1615, -1615,   948,  1756,  1711,  1719,  1711, -1615,  1622, -1615,
    1685,   510,  1717, -1615,   507,  1961,  1961, -1615, -1615, -1615,
    1760,  1265, -1615, -1615, -1615, -1615, -1615, -1615, -1615,   901,
   -1615, -1615, -1615,  1693,   901,   565,  1539, -1615,  1980, -1615,
   -1615,  1722,  1709, -1615, -1615,   138, -1615, -1615, -1615, -1615,
    1694,  1770,  1725,  1735,  1725, -1615,  1690, -1615,  1700,   901,
    1734, -1615,   563,  1980,  1695,  1980, -1615, -1615, -1615,  1778,
    1330, -1615, -1615, -1615,  1706, -1615,   400, -1615, -1615, -1615,
    1707,  1724, -1615,  1723,  1788, -1615, -1615, -1615,  1980,  1727,
   -1615, -1615,  1728, -1615,  1750,  1737,   901,   901,  1494,  1980,
     713,  1822, -1615, -1615, -1615, -1615, -1615,  1651, -1615, -1615,
   -1615, -1615, -1615,   663, -1615,  1980, -1615, -1615,  1738,  1748,
   -1615,  1751,  1820, -1615, -1615, -1615,  1698, -1615, -1615,  1752,
    1754, -1615,  1716, -1615, -1615,  1757,  1758, -1615, -1615, -1615,
     510,  1297,  1598,  1961,  1067, -1615,   821,   200,  1840, -1615,
   -1615,  1698,  1835,  1842,  1850,  1771,  1961, -1615,  1772,  1805,
    1961,  1780, -1615,  1782,  1784, -1615, -1615,  1961,  1873,  1961,
    1786, -1615, -1615,  1789,  1892, -1615, -1615,  1792, -1615,   791,
   -1615, -1615,  1790, -1615,  1826,  1980,  1791, -1615,  1801,  1810,
   -1615, -1615,  1980,  1899,  1980,  1813,  1898, -1615, -1615,  1814,
   -1615,  1818,  1812, -1615,  1832, -1615, -1615,  1723, -1615, -1615,
   -1615,   901,  1306,  1640,  1980,  1274, -1615,   853,   375, -1615,
   -1615,  1716,  1893,  1901,  1902,  1825,  1980, -1615, -1615,  1877,
   -1615, -1615,  1751, -1615,  1917, -1615, -1615, -1615,  1919, -1615,
   -1615,  1499, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
     507,  1836, -1615, -1615,  1961,   558,  1833,  1723,  1723, -1615,
   -1615,  1951,  1872, -1615, -1615,  1871, -1615, -1615, -1615, -1615,
   -1615, -1615, -1615,  1961,  1841,  1844, -1615, -1615, -1615, -1615,
    1330, -1615,  1847,  1829,  1913, -1615, -1615, -1615, -1615, -1615,
   -1615, -1615,  1980,  1848,  1965,  1851, -1615, -1615,  1980, -1615,
   -1615, -1615, -1615, -1615, -1615,  1573, -1615, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615,   563,  1856, -1615, -1615,   653,  1853,
    1751,  1751, -1615, -1615,  1885, -1615, -1615, -1615,  1949, -1615,
    1950, -1615,  1956, -1615, -1615,   812, -1615, -1615,  1683, -1615,
    1698,  1632,  1961, -1615,  1961,  1862,  1864,   126,  1329, -1615,
   -1615, -1615,  1959, -1615, -1615, -1615,  1874,   275,  1345, -1615,
   -1615,  1980, -1615, -1615,  1883, -1615,  1963,  1301, -1615,  1966,
   -1615, -1615,  1584, -1615,  1749, -1615,  1716,  1651,  1980,  1312,
    1969,  1974,  1979,  1947,  1889,  1961,  1632, -1615,  1983, -1615,
   -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,  1894,
    1900, -1615,  1986,  1961, -1615,  1996, -1615, -1615,  1961,  1990,
    1973, -1615,  2002, -1615, -1615,  1980,  1994, -1615,  1980,  1981,
   -1615,  1832,  1998,  1970,  1914,  1980,  1651, -1615,  2005, -1615,
   -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
    1915,  1916,  2011, -1615,  1877,  1922,  1923,  1947, -1615,  1991,
   -1615,  1964, -1615,  1954,   780,  2036, -1615, -1615, -1615, -1615,
   -1615,  1955, -1615,  1989,  2048,   994, -1615,  1976, -1615,  2008,
    2060, -1615,  1230, -1615,  1970, -1615,  2039, -1615,  2012, -1615,
    1984,  1558,  2077,  2084, -1615, -1615, -1615, -1615, -1615, -1615,
    2050,   994,  1871, -1615,  1698, -1615,   994, -1615, -1615,  1999,
    2000, -1615, -1615,  2016,  2017,  2055,  1230,  1913, -1615,  1716,
   -1615,  1230,   994,  2018,  2031, -1615,  2029, -1615,  2030, -1615,
   -1615, -1615, -1615, -1615, -1615,  1230,  2070,  2080, -1615,  2078,
   -1615,  2079,  2081, -1615, -1615, -1615,  1765, -1615,  2082, -1615,
   -1615, -1615,  1831, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
   -1615, -1615,  2172,  2175,  2190,  2191,   994,  1230,  2086,  2087,
   -1615, -1615
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1615, -1615, -1615,  -339, -1615, -1615, -1615, -1615, -1615,    19,
   -1615, -1615, -1615, -1615, -1615,    33, -1615, -1615, -1615, -1615,
    1660,  -122,  -130, -1615, -1615, -1615,  -296, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615,  -127, -1615,   313, -1615, -1615, -1615,
   -1615, -1615, -1615,  2073, -1615, -1615,  1742,  -189, -1615, -1615,
   -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,  -114, -1615,
    1615, -1615, -1615, -1615, -1615, -1615, -1107, -1615,   -12, -1615,
   -1468,  1967, -1615,  2057,   -13,   -80,   -59,  1566, -1615, -1615,
   -1615, -1615,  1988,  1547,  1870,  1875,  1895, -1615,   342,   541,
     828,   768,    75,    88,    10,  -540,   187,   873, -1615, -1615,
   -1615,  -666, -1615, -1615, -1615,  -142, -1615,  2137, -1615,  1975,
     157,  -193, -1615,  1852,  1995, -1615, -1615, -1615, -1615,  1304,
   -1615, -1615, -1615, -1615, -1615, -1615, -1615,   942,  1124, -1615,
   -1615, -1615, -1615,  1308, -1615, -1615, -1615,  -410,  1671,   -58,
    2062,   -90, -1615, -1615, -1217,    52, -1615, -1615, -1615,  -213,
   -1615,  -129, -1615,  1620,  -657, -1615, -1615, -1615, -1615, -1615,
   -1615, -1615,  -123, -1615, -1615,  -126,  -128, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615,  1022, -1615,   532,  -470,  1726, -1615,
   -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1280,
   -1237, -1378, -1265,  1044,  1046,   424,  1049,  1485, -1615, -1615,
   -1426, -1615,   472, -1615,  -881,   735,  1489, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615,  1055, -1615, -1615,  -905,   737,  1260,
     870, -1615,  -208, -1425, -1615, -1615,  -659, -1615,   874, -1615,
   -1615,   536, -1615, -1615, -1615, -1615, -1114, -1615, -1615, -1615,
   -1615, -1615, -1615,   879, -1615,  1248, -1615,  -656, -1615, -1615,
   -1615, -1279, -1615, -1615, -1615, -1615, -1615,  -121, -1615,  -929,
   -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,   549,  1081,
   -1070, -1615, -1615,   925, -1615, -1615, -1615, -1615,   742,  -485,
   -1615, -1615, -1615, -1615, -1615,  -272,  -239, -1615, -1615,  -931,
    -926,  -478, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615, -1615,  -195,   348, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615, -1615,  1714,  -188, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615, -1615, -1615,   -85, -1615,  1032, -1615,
   -1615, -1615, -1615, -1615, -1239, -1615,  -414, -1615, -1484,  1219,
   -1615,  1423,  -231,   245,  -458,  1328, -1615, -1615, -1615, -1615,
    1338,  1284,  1296,  1332,  1339, -1615,  -477,  -433,   317,   777,
    -538,  -533,    61,  -665,  -219,   796, -1615, -1615, -1615,  -757,
   -1615, -1615, -1615,  -652, -1615,  1621, -1615,  1227,  -747,  -835,
   -1615,  1017,  1930, -1615, -1615, -1615, -1615,  1236, -1615, -1615,
   -1615, -1615, -1615, -1615, -1615,   866,  1036, -1615, -1615, -1615,
    1238, -1615, -1615, -1615,  -389,  -488,  1483,  -434, -1615, -1615,
   -1323,  -473, -1615, -1615, -1615,  -693, -1615,   530, -1615,  1588,
    -923, -1615, -1615, -1615, -1615, -1615, -1615, -1615,   534, -1615,
   -1615,  -646,  -289, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
     961, -1615, -1615, -1614,   480, -1615, -1615, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615, -1615, -1393, -1267, -1371, -1277,   965,
     966,   439,   967,  1340, -1615, -1615, -1477, -1615,   496, -1615,
    -988,   702,  1341, -1615, -1615, -1615, -1615, -1615, -1615, -1615,
     973, -1615, -1615, -1083,   710,  1143,   862, -1615,  -369, -1407,
   -1615, -1615,  -813, -1615,   868, -1615, -1615,   566, -1615, -1615,
   -1615, -1615, -1182, -1615, -1615, -1615, -1615, -1615, -1615,   871,
   -1615,  1200, -1615,  -807, -1615, -1615, -1615, -1333, -1615, -1615,
   -1615, -1615, -1615,   552, -1615,  -922, -1615, -1615, -1615, -1615,
   -1615, -1615, -1615, -1615,   553,  1118, -1177, -1615, -1615,   963,
   -1615, -1615, -1615, -1615,   712
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1128
static const yytype_int16 yytable[] =
{
      39,    95,   118,   207,   298,   149,   572,   352,   234,   239,
     225,   238,   208,   410,   237,   332,   240,   312,   256,   490,
     320,   423,   338,    40,   595,   469,   150,   118,   530,    64,
      32,  1157,  1080,   874,   904,  1156,   612,    17,   673,   901,
     371,   539,  1011,   677,    39,  1166,   549,    94,  1163,  1493,
     427,   552,   298,   674,  1171,   554,   555,   459,  1487,  1492,
     943,   756,  1303,   408,  1437,   138,  1413,    40,   651,  1511,
     112,   259,    94,   944,  1581,  1540,  1365,   313,   316,   309,
     315,   161,   318,   314,  1182,   260,  1486,   631,    40,  1554,
     984,   307,   719,   987,  1255,  1529,  1663,  1629,   251,   440,
     253,   818,   820,  1635,    40,  1685,   819,   819,  1593,  1684,
    1021,   443,   119,   544,  1355,  1197,   738,   296,   496,  1789,
    1079,  1597,   608,  1140,   611,   242,   241,   613,  1473,  1143,
     477,   616,   932,  1616,   120,    33,    34,   602,   150,   118,
    1648,   594,   921,   348,   421,    39,   448,   400,    40,   257,
    1105,   590,   353,   673,  1765,   491,   163,   440,   145,   147,
     815,   817,   803,   833,    -3,   296,   367,   401,   252,  1233,
     422,   146,   146,   404,  1283,   372,   440,   690,  1692,  1286,
    1042,   478,   452,   823,    94,     5,   150,   118,   963,  1360,
      95,   118,    26,   781,   349,  1374,   150,   118,  1080,   733,
      42,   130,    39,   591,   816,   816,   492,   485,  1401,   756,
    1679,   604,  1712,   606,   164,  1375,  1450,  1625,  1361,    27,
     354,   834,   363,    13,   449,   350,   131,  1509,   798,   748,
     241,    51,    94,   347,  1284,   354,    94,   428,   354,   542,
     359,    28,    94,  1557,    77,   933,   429,    35,   453,    31,
     429,    31,  1726,   675,   121,   122,   123,   354,   486,   112,
    1729,   354,  1531,   717,    36,    37,  1742,  1505,   426,  1257,
     295,   943,   477,  1331,   491,  1143,   426,  1579,  1287,  1576,
     607,   980,   607,   146,   944,   607,  1239,    59,    60,   607,
     543,   473,   440,   475,   735,   650,   577,  1913,   525,   526,
     920,   119,  1335,  1772,   633,   429,   771,  1402,  1838,   471,
     118,   751,    47,  1833,   718,  1289,  1454,  1223,  1340,  1811,
    1847,  1782,  1759,   478,  1290,   492,    29,  1077,   437,   438,
     694,  1693,   819,   752,   402,  1725,   977,  1199,   406,  1820,
     987,  1730,  1822,   691,  1801,    36,    37,   722,   999,   806,
     553,   727,  1424,  1686,   297,    94,   731,   607,   407,   964,
     122,   123,   578,  1646,  1826,  1800,  1644,  1828,   781,   157,
    1651,   158,  1039,   676,   535,   536,   782,   569,  1376,   673,
     695,  1069,  1070,  1071,   535,   536,   607,   163,    39,  1611,
     875,   441,  1675,  1322,    37,  1325,   438,  1696,  1422,  1029,
     556,   597,   366,   813,  1292,   598,  1627,   557,   969,   823,
     650,   498,  1425,  1632,   330,   922,   777,   943,  1423,   782,
     748,  1760,    30,   141,   144,   816,   816,   816,   558,  1444,
     944,  1090,    52,  1879,  -318,    53,   504,   833,   538,   924,
     547,  1736,  1737,   538,   550,   164,  -318,   925,   538,   487,
    1091,   673,   538,   538,  1132,  1882,   756,  -585,   970,   757,
    1664,    40,   159,    40,   559,   159,    40,    40,   501,    48,
     749,    40,   750,   926,   965,    40,    40,   780,   775,   779,
    -580,   823,   966,  -272,   870,  -272,    31,  1084,    65,    66,
    1314,   872,  1676,   617,   941,   834,    49,   440,   975,  1315,
     618,  1103,   751,  1104,    52,  -580,   456,  1559,   967,  1813,
    1700,  1701,   560,    50,   160,    60,  -318,  -318,  1327,  1840,
      52,   619,   465,  1008,   752,   161,   257,    36,    37,   530,
     287,   288,   289,  -818,    54,  -818,   753,    37,    39,  1086,
     531,   532,   935,   538,    55,   673,   935,  1356,    40,   673,
      67,    56,  1215,   673,   440,   620,  1802,   621,  1085,    59,
      60,   350,    62,   715,   674,   992,    40,    68,  1009,  -472,
    1019,  1216,   441,    62,   441,   823,  1357,   441,   703,   651,
      74,   441,  1030,   823,   441,  1434,    40,   668,   754,  1876,
    1762,  1358,  1889,  1829,  1136,   781,   936,  1083,   937,  1612,
     440,  -254,   533,  1474,   879,   622,    57,   757,   895,    58,
     897,   755,   898,  -254,   752,   904,  1029,  1317,    69,  -472,
     903,  -472,   142,   142,   938,  1110,    36,    37,   938,  1230,
    1537,  1295,  1475,  1232,    59,    60,   650,    36,    37,   441,
     943,  1011,  1482,   441,   756,   607,   939,  1476,   441,   441,
     939,  -472,   944,   944,  1823,   166,   958,  1164,   437,   438,
      70,  1165,   940,   438, -1014,  1687,   412,    71,   441,    39,
   -1127,   990,   296,  -472,   413,    73,  1689,  1512,   441,   525,
     526,   959,  1097,  -254,  -254,  -472,  -472,   902,   159,   912,
    1096,    75,   877,   150,   118,   441,   167,   538,  1582,   168,
     748,   126,  1513,  1336,   169,  1137,    59,    60,   650,  1337,
    1338,   441,    40,   127, -1014,   939, -1014,  1713,  1339,   414,
      40,  1340,   -34,  1583,  1533,   -34,  1341,   437,   438,   142,
     142,   142,   415,   538,  1159,  -184,   981,    59,    60,    94,
     155,   790,   170,   171,    64,   128, -1014,  -234, -1122,   791,
     749,   806,   750,   673,  1169,   173,    40,  1214,  1170,   755,
    1409,   528,  1219,   129,   803,   620,  1220,   973, -1014,  1412,
     172,  1414,   211, -1122,   -35,   174,  -184,   -35,   782,  -184,
   -1014, -1014,   751,  1405,  -184,   523,   942,   607,   524,   487,
     214,   607,  1272,   997,   792,   317,  -610,   195,   217,  -610,
     748,  1786,   650,  1381,   752,   218,   650,   793,  1188,  1716,
     650,   175,    59,    60,   525,   526,    36,    37,   686,  1189,
    -227,  -534,  -184,  -184,  -780,  -860,  1190,   525,   526,   219,
     830,   220,   831,  1148,  1478,  -534,   512,  -860,   513,  1191,
     131,  1192,  -611,   525,   526,  -611,  1000,   130,   222,   931,
     244,  1137,   223,   836,   757,    13,   620,    59,    60,  1193,
    1194,  -800,   441,   992,   245,  -245,  -245,  1433,   255,  -170,
     211,  -170,    62,  -800,   441,  -245,   246,   212,   773,  1195,
     303,  -534,  1430,   188,   189,   190,   822,   304,   214,   161,
     257,   306,  1040,  1364,   837,  1366,   217,   838,   538,   363,
     538,  1011,   839,   218,   752,   832,   526,  -860,  -860,    63,
      60,  1112,    40,   440,  -730,  1869,  1196,    37,   437,   438,
     344,    40,  -716,    40,  -716,   528,  1672,   219,   364,   220,
     935,   345,   159,   703,    40,    59,    60,   441,  1246,   440,
     840,   841,  1224,  -800,  -800,  -234,   222,   346,   904,  1247,
     223, -1076,   357,    13,   774,  -730,  1248,   358,  -730,   291,
     291,   291,   291,  -730,   512, -1076,   588,   525,   526,  1249,
     360,  1250,    52,    78,   599,    39,    79,  -780,  -791,  -791,
     368,    59,    60,   981,   858,   859,   860,  1438,  -791,  1251,
    1252,  -234,   196,   197,    36,    37,  1395,   942,   350,   373,
    1534,  -730,  -730,   160,    60,  1536,   755,    63,    60,  1253,
     650, -1076,  1273,   993,   419,   159,  1275,  1276,   425,  1672,
     292,   293,   294,  1517,   248,   249,   441,    78,   437,   438,
      79,  1001,  1887,  1004,   939,   321,   253,    59,    60,    85,
     607,   757,   757,  -310,  1010,   935,  1254,   438,  1455,    86,
      87,    36,    37,   322,  1456,  1457,   426,    78,   323,   432,
      79,   324,   433,  1458,   160,    60,  1424,  1309,   325,  1311,
     441,  1459,   434,   440,  1460,   122,   123,    36,    37,   441,
    1043,    81,    82,   441,   450,   525,   526,  1278,  1795,    83,
      84,  1148,   326,    85,   327,   936,  1328,   937,   668,   451,
    1274,   529,   526,    86,    87,    36,    37,  1149,  1363,   454,
      40,   328,  1078,  1368,  1369,   329,  -319,   457,   330,    83,
      84,   354,    52,    85,   913,   781,   512,   938,  1022,   525,
     526,  1039,  -319,    86,    87,    36,    37,   160,    60,   460,
    -319,  -861,  -142,   942,  -319,   461,    52,  -234,  1213,   939,
      36,    37,    39,  -319,    59,    60,   673,  -861,   607,   466,
    1179,   437,   438,   607,   470,  -861,  -319,  1539,   474,  -861,
      39,  1342,   529,   526,  1117,   498,     6,     7,  -861,  1074,
    1075,  1076,   634,  1146,  1078,   635,  1405,   467,   440,     8,
       9,  -861,   482,   755,   755,   535,   536,    10,   525,   526,
     538,   903,  1666,   484,  -853,   487,   497,   512,  1158,  1221,
     741,   499,    11,   620,  -319,  -319,  -319,   502,  -319,  -319,
     512,  -319,  1271,    40,   500,   731,  1577,    12,   -17,   507,
     -17,   501,   742,   509,   743,   620,   525,   526,   744,  -861,
    -861,  -861,  1300,  -861,  -861,   510,  -861,   321,   641,  1497,
     511,   745,   705,   706,   385,   868,    13,   514,   642,   643,
     437,   438,   525,   526,   538,   322,  1231,  -607,  1436,  -607,
     808,   809,  -780,   324,   515,   437,   438,  1514,  1078,  1240,
     325,   866,   867,  1673,   832,   526,  1243,    40,   441,   832,
     526,   516,  1602,  1384,  -688,  1530,   520,   437,   438,   521,
    1095,   528,   211,   551,   326,   570,   327,    52,   782,   212,
    1603,   321,  1606,  1036,  1037,  1385,   580,  1386,   385,  1667,
     214,  1387,   576,   328,   715,  1506,   582,   329,   217,   322,
     330,   869,   441,   512,  1388,   218,   587,   324,  1280,  1281,
     440,  1397,  1398,   452,   325,   577,  1039,    40,    40,   160,
      60,  -318,  -318,   610,  1864,  1767,  1768,   429,    39,   219,
     614,   220,    36,    37,   632,   942,   942,   682,   326,   684,
     327,  1774,  1775,  1609,  1604,  1608,  1673,  1668,   222,   673,
     685,   350,   223,   688,  1670,    13,   774,   328,  1886,   692,
     880,   329,   698,  1891,   330,   869,   176,   177,   178,   179,
     180,   181,   881,   882,   700,   883,   702,  1898,   709,  1405,
     728,   884,  1606,   650,   710,   885,   634,  1780,  1781,   635,
     711,   832,   526,   161,   257,   886,   723,  1539,  1803,  1804,
     713,  -780,  1706,   729,   437,   438,  1621,   714,   730,  1919,
    1912,   887,  -391,   736,   888,  1796,    40,   785,   786,  1621,
     441,  1222,   788,   739,   801,   441,   772,   797,   889,   799,
     812,   842,  1382,   890,   843,   844,   845,   891,  1392,  1393,
    1668,   892,   865,  1609,  1604,  1608,  -773,  1670,   639,   640,
     487,   828,   641,   191,   192,   193,   194,    39,   876,  1408,
     878,  1411,   642,   643,   437,   438,  1416,  1417,   894,   896,
     832,   526,  -860,  -860,   211,   251,   899,   915,   911,  1751,
     350,   212,  1691,   437,   438,   917,   918,   441,   441,   182,
     183,   929,   214,   930,   184,   185,   186,   187,    13,  1860,
     217,   330,   991,   988,   903,   994,  1003,   218,  1005,  1791,
    1018,  1024,  1447,  1026,  1032,  1041,  1792,  1027,  1033,   188,
     189,   190,  1087,  1709,  1034,  1873,  -216,  -216,  -216,  -216,
    1878,   219,  1088,   220,  1089,  1093,   471,   118,  1094,  1752,
    1755,  1750,  1754,  1746,   112,  1753,  1892,  1757,   321,  1099,
     222,  1108,  1100,  1113,   223,   385,  1728,    13,   774,  -200,
    -200,  -200,  -200,  -200,  -200,  1111,   322,  1116,   211,  1144,
     441,  1436,  1133,  1150,   324,   212,   374,   861,   862,   863,
     864,   325,    94,   213,  1147,  1155,   214,   215,   959,   958,
    1918,  1160,  1761,  1174,   217,   375,  -762,  -762,  -762,  -762,
    1176,   218,   487,  1183,  1185,   326,   650,   327,  1073,  1073,
    1073,  1073,  1187,  1010,   846,   847,   848,   849,   850,   851,
     668,  1218,  1226,  1236,   328,   219,  1227,   220,   329,  1874,
    1241,   330,   869,  1245,  1244,  1621,  1277,  1292,  1555,   221,
    1282,  1296,   321,  1297,   222,  1304,  1306,  1308,   223,   385,
     386,    13,  1310,  1621,  1854,  1312,  1317,   387,   211,  1313,
     322,   388,  1320,  1568,  1321,   212,  1749,  1329,   324,   389,
    1324,  1332,  1367,   213,  1371,   325,   214,   215,  -746,  -746,
    -746,  -746,  -746,  -746,   217,   375,  1373,  1394,  1404,  1399,
    1584,   218,   251,   273,   275,   276,   277,   278,   279,   326,
    1400,   327,   262,   264,   265,   266,   267,   268,   269,   270,
     271,   272,  1407,   390,  1415,   219,  1419,   220,   328,  1421,
    1432,  1431,   329,  1440,   321,   330,  1439,  1443,  1444,   221,
    1441,   385,  1790,  1442,   222,  1448,  1479,  1481,   223,   387,
     211,    13,   322,   388,  1451,  1480,  1482,   212,  1905,  1485,
     324,   389,  1502,  1508,  1503,   213,  1491,   325,   214,   215,
    1500,   112,  1498,   471,   118,  1510,   217,   375,  1519,  1654,
     211,  1522,  1520,   218,  1527,  1525,  1532,   212,  1541,  1535,
    1542,   326,  1544,   327,  1543,   213,  1545,  1547,   214,   215,
    1550,  1552,  1556,   216,  1558,   390,   217,   219,  1274,   220,
     328,  1654,  1560,   218,   329,  1567,   321,   330,  1564,    94,
    1563,   221,   211,   385,  1908,  1571,   222,  1569,  1573,   212,
     223,   387,  1574,    13,   322,   388,  1580,   219,  1587,   220,
     214,   215,   324,   389,  1588,   668,  1589,  1592,   217,   325,
    -124,   221,  1595,  1118,  1596,   218,   222,  1599,  1600,  1614,
     223,    78,  1617,    13,    79,  1119,  1120,    80,  1121,  1618,
    1619,  1620,  1624,   326,  1122,   327,  1625,  1719,  1123,   219,
    1628,   220,  1630,  1010,  1631,  1633,  1636,   390,  1124,  1638,
    1639,  1647,   328,   221,  1391,  1641,   329,  1644,   222,   330,
      78,  1649,   223,    79,  1125,    13,   634,  1126,   148,   635,
    1650,  1652,   636,  1657,  1660,    81,    82,  1658,  1661,  1662,
    1680,  1127,  1682,    83,    84,  1683,  1128,    85,  1681,   401,
    1129,   407,  1694,  1699,  1130,  1702,  1715,    86,    87,    36,
      37,  1710,   634,  1704,  1711,   635,  1777,  1714,  1720,  1721,
     821,  1723,  1731,  1735,    81,    82,  1738,  1740,  1741,  1763,
     637,   638,    83,    84,  1743,  1764,    85,  1770,   639,   640,
     634,  1779,   641,   635,  1783,  1771,    86,    87,    36,    37,
    1778,  1805,   642,   643,   437,   438,  1806,  1807,  1808,  1810,
      78,  1815,  1818,    79,  1816,  1821,   637,   638,  1824,  1825,
    1817,  1827,  1830,  1654,   639,   640,  1834,  1832,   641,   634,
    1654,  1835,   635,  1842,  1837,  1844,  1845,  1846,   642,   643,
     437,   438,  1848,  1849,   637,   638,   274,   274,   274,   274,
     274,   274,   639,   640,  1851,  1852,   641,   280,   282,   283,
     284,   285,   286,  1391,    81,    82,   642,   643,   437,   438,
    1856,  1858,    83,    84,  1853,  1857,    85,   281,   281,   281,
     281,   281,   281,   637,   638,  1859,    86,    87,    36,    37,
    1862,   639,   640,  -208,  -208,   641,  1861,  1863,  -208,  -208,
    -208,  -208,  1866,  1867,  1868,   642,   643,   437,   438,   852,
     853,  1871,  -933,  1872,   854,   855,   856,   857,  1885,  1880,
    1881,  -754,  -754,  -208,  -208,  -208,  -754,  -754,  -754,  -754,
    1055,  1057,  1058,  1059,  1060,  1061,  1883,  1884,  1893,   858,
     859,   860,  1056,  1056,  1056,  1056,  1056,  1056,  1894,  1895,
    1897,  -754,  -754,  -754,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,  1044,  1046,  1047,  1048,  1049,  1050,
    1051,  1052,  1053,  1054,  1045,  1045,  1045,  1045,  1045,  1045,
    1045,  1045,  1045,  1045,  1062,  1064,  1065,  1066,  1067,  1068,
    1899,  1063,  1063,  1063,  1063,  1063,  1063,  1900,  1901,  1903,
    1914,  1904,  1907,  1915,  1916,  1917,  1920,  1921,   687,  1906,
     228,   571,  1507,   740,   250,   139,   369,   365,   362,  1107,
     472,  1435,  1106,   258,  1279,   778,  1378,   699,  1350,  1748,
    1351,  1850,   600,  1352,   982,  1819,  1601,  1610,   983,  1354,
    1178,  1526,  1524,  1766,  1208,  1523,  1323,  1758,  1489,  1613,
    1909,   680,  1383,  1038,  1578,   814,  1242,  1238,  1406,   436,
    1235,  1234,  1538,  1396,  1793,   998,  1463,   873,  1794,  1843,
    1468,  1469,  1470,  1865,  1831,  1674,  1138,  1139,  1472,  1299,
    1665,  1551,  1266,  1773,  1549,  1548,  1798,  1799,  1326,  1495,
    1677
};

static const yytype_uint16 yycheck[] =
{
      13,    60,    60,   133,   197,    85,   476,   215,   137,   137,
     137,   137,   134,   302,   137,   210,   137,   206,   160,   388,
     209,   317,   210,    13,   502,   364,    85,    85,   442,    41,
      11,   962,   867,   679,   700,   961,   514,     4,   526,   696,
     253,   451,   799,   528,    57,   974,   456,    60,   971,  1326,
     322,   461,   245,   526,   976,   465,   466,   353,  1323,  1326,
     725,   601,  1145,   302,  1281,    78,  1248,    57,   526,  1349,
      60,   161,    85,   725,  1467,  1398,  1190,   206,   206,   206,
     206,    94,   209,   206,   989,   165,  1323,   521,    78,  1422,
     749,   205,   577,   749,  1082,  1374,  1564,  1522,   157,   330,
     159,   639,   640,  1529,    94,  1589,   639,   640,  1486,  1586,
     803,   330,    60,   452,  1184,   996,   594,   197,   390,  1733,
     867,  1492,   511,   936,   513,   138,   138,   516,  1305,   936,
       6,   520,     9,  1511,     6,    15,    16,    29,   197,   197,
    1547,    22,     8,     6,    42,   158,    42,    12,   138,   161,
      28,    21,    59,   641,    28,     6,    25,   388,    83,    84,
     637,   638,   620,    25,     0,   245,   246,    32,   158,    28,
      59,    83,    84,   301,    67,   255,   407,     4,  1603,    28,
     832,    57,    53,   641,   197,     0,   245,   245,     4,    33,
     249,   249,   127,   607,    57,    98,   255,   255,  1033,   588,
      13,    35,   215,   499,   637,   638,    57,     6,    28,   749,
    1581,   507,  1637,   509,    83,   118,  1299,    91,    62,   127,
     127,    83,   120,    88,   120,   215,    60,  1341,   617,    11,
     242,    42,   245,   214,   127,   127,   249,    59,   127,     6,
     221,   127,   255,  1425,    57,   723,   127,   127,   119,   127,
     127,   127,  1659,     6,   126,   127,   128,   127,    57,   249,
    1667,   127,  1376,     6,   127,   128,  1691,  1337,   127,  1082,
     195,   936,     6,  1178,     6,  1082,   127,  1459,   127,  1456,
     511,    63,   513,   195,   936,   516,  1033,   114,   115,   520,
      57,   371,   523,   373,   590,   526,    53,  1911,   114,   115,
     710,   249,  1183,    28,   523,   127,   602,   127,  1785,   368,
     368,    93,    53,  1781,    57,   115,  1304,  1010,    32,  1745,
    1804,  1728,  1700,    57,   124,    57,   127,   865,   127,   128,
      18,  1610,   865,   115,   301,  1658,   746,   996,    12,  1764,
     996,  1674,  1767,   551,  1737,   127,   128,   578,   782,   621,
     464,   582,    32,  1592,   197,   368,   587,   588,    32,   728,
     127,   128,   119,  1545,  1771,  1736,    91,  1774,   782,   121,
    1552,   123,   830,   126,   127,   128,   607,   467,    92,   867,
      68,   858,   859,   860,   127,   128,   617,    25,   401,  1503,
     679,   330,  1574,   127,   128,   127,   128,  1614,    98,   813,
       3,   116,   245,   634,    35,   120,  1520,    10,    18,   867,
     641,   401,    92,  1527,    88,   711,   605,  1082,   118,   650,
      11,  1701,   127,    81,    82,   858,   859,   860,    31,    60,
    1082,    39,   117,  1858,    34,   120,   417,    25,   451,    21,
     453,  1680,  1681,   456,   457,    83,    46,    29,   461,   388,
      58,   939,   465,   466,   932,  1862,   996,    88,    68,   601,
    1567,   451,    65,   453,    67,    65,   456,   457,   407,    53,
      61,   461,    63,    55,    21,   465,   466,   605,   605,   605,
      35,   939,    29,   121,   679,   123,   127,   876,    65,    66,
     115,   679,  1575,     3,   725,    83,    53,   728,   737,   124,
      10,   911,    93,   913,   117,    60,   119,  1430,    55,  1746,
    1617,  1618,   115,    53,   114,   115,   116,   117,  1175,  1786,
     117,    31,   119,   795,   115,   538,   538,   127,   128,   943,
     188,   189,   190,   121,   127,   123,   127,   128,   551,   878,
      65,    66,    11,   556,   127,  1033,    11,    40,   538,  1037,
     127,    42,    39,  1041,   785,    65,  1738,    67,   120,   114,
     115,   551,   124,   576,  1037,   120,   556,   127,   799,    11,
     801,    58,   511,   124,   513,  1033,    69,   516,   559,  1037,
      42,   520,   813,  1041,   523,    65,   576,   526,   601,  1854,
    1704,    84,  1869,  1775,    63,  1009,    61,   869,    63,  1504,
     831,    34,   127,    40,   684,   115,   117,   749,   688,   120,
     690,   601,   692,    46,   115,  1281,  1030,    35,   127,    61,
     700,    63,    81,    82,    93,   921,   127,   128,    93,  1018,
      65,  1116,    69,  1022,   114,   115,   867,   127,   128,   578,
    1305,  1398,    60,   582,  1184,   876,   115,    84,   587,   588,
     115,    93,  1304,  1305,  1768,     7,    35,    28,   127,   128,
     127,    32,   127,   128,    11,  1594,    23,   127,   607,   682,
      88,   751,   752,   115,    31,   127,  1598,    35,   617,   114,
     115,    60,   115,   116,   117,   127,   128,   700,    65,   702,
     903,    42,   682,   752,   752,   634,    48,   710,    35,    51,
      11,    42,    60,    14,    56,   936,   114,   115,   939,    20,
      21,   650,   702,    42,    61,   115,    63,  1640,    29,    76,
     710,    32,   117,    60,  1381,   120,    37,   127,   128,   188,
     189,   190,    89,   746,   965,     7,   749,   114,   115,   752,
     127,    23,    94,    95,   756,    42,    93,   124,    35,    31,
      61,  1023,    63,  1241,    28,    56,   746,   120,    32,   749,
    1245,   124,   116,    42,  1222,    65,   120,   734,   115,  1247,
       7,  1249,     5,    60,   117,    95,    48,   120,  1009,    51,
     127,   128,    93,  1241,    56,   117,   725,  1018,   120,   728,
      23,  1022,  1088,   774,    76,    28,   117,   113,    31,   120,
      11,  1732,  1033,  1213,   115,    38,  1037,    89,    19,  1644,
    1041,    94,   114,   115,   114,   115,   127,   128,   120,    30,
     113,    32,    94,    95,   124,    34,    37,   114,   115,    62,
     121,    64,   123,   120,  1312,    46,   117,    46,   119,    50,
      60,    52,   117,   114,   115,   120,   785,    35,    81,   120,
     116,  1082,    85,     7,   996,    88,    65,   114,   115,    70,
      71,    34,   801,   120,   117,   114,   115,  1277,   115,   121,
       5,   123,   124,    46,   813,   124,   121,    12,    13,    90,
     120,    92,  1271,   102,   103,   104,   641,   115,    23,   902,
     902,   120,   831,  1189,    48,  1191,    31,    51,   911,   120,
     913,  1658,    56,    38,   115,   114,   115,   116,   117,   114,
     115,   924,   902,  1144,     7,  1841,   127,   128,   127,   128,
     127,   911,   121,   913,   123,   124,  1572,    62,    33,    64,
      11,   127,    65,   914,   924,   114,   115,   876,    19,  1170,
      94,    95,   115,   116,   117,   124,    81,   127,  1614,    30,
      85,    32,   127,    88,    89,    48,    37,   127,    51,   191,
     192,   193,   194,    56,   117,    46,   119,   114,   115,    50,
     127,    52,   117,    49,   119,   988,    52,   124,   114,   115,
     123,   114,   115,   996,   102,   103,   104,  1283,   124,    70,
      71,   124,   116,   117,   127,   128,  1227,   936,   988,   121,
    1389,    94,    95,   114,   115,  1394,   996,   114,   115,    90,
    1241,    92,  1092,   120,    13,    65,  1096,  1097,   127,  1665,
     192,   193,   194,  1362,   116,   117,   965,    49,   127,   128,
      52,   786,  1867,   788,   115,     5,  1095,   114,   115,   115,
    1271,  1183,  1184,   120,   799,    11,   127,   128,    14,   125,
     126,   127,   128,    23,    20,    21,   127,    49,    28,   127,
      52,    31,   127,    29,   114,   115,    32,  1152,    38,  1154,
    1009,    37,   127,  1304,  1305,   127,   128,   127,   128,  1018,
     835,   103,   104,  1022,    33,   114,   115,  1100,  1734,   111,
     112,   120,    62,   115,    64,    61,  1176,    63,  1037,   119,
     122,   114,   115,   125,   126,   127,   128,   120,  1188,    42,
    1100,    81,   867,  1193,  1194,    85,    18,   119,    88,   111,
     112,   127,   117,   115,   119,  1539,   117,    93,   119,   114,
     115,  1589,    34,   125,   126,   127,   128,   114,   115,   120,
      42,    18,   115,  1082,    46,   119,   117,   124,   119,   115,
     127,   128,  1165,    55,   114,   115,  1644,    34,  1389,    42,
     120,   127,   128,  1394,   116,    42,    68,  1398,   116,    46,
    1183,  1184,   114,   115,   929,  1165,     8,     9,    55,   862,
     863,   864,    49,   938,   939,    52,  1644,    42,  1419,    21,
      22,    68,   127,  1183,  1184,   127,   128,    29,   114,   115,
    1213,  1281,  1571,   127,   120,  1144,   127,   117,   963,   119,
      17,    28,    44,    65,   116,   117,   118,    28,   120,   121,
     117,   123,   119,  1213,   127,  1456,  1457,    59,   117,    28,
     119,  1170,    39,    15,    41,    65,   114,   115,    45,   116,
     117,   118,   120,   120,   121,   120,   123,     5,   115,  1329,
     119,    58,   126,   127,    12,    13,    88,    16,   125,   126,
     127,   128,   114,   115,  1277,    23,  1021,   117,  1281,   119,
     126,   127,   124,    31,   120,   127,   128,  1357,  1033,  1034,
      38,   116,   117,  1572,   114,   115,  1041,  1277,  1227,   114,
     115,   119,  1500,    17,   115,  1375,    42,   127,   128,    42,
      65,   124,     5,   117,    62,   120,    64,   117,  1539,    12,
      13,     5,  1501,   116,   117,    39,    42,    41,    12,    13,
      23,    45,   119,    81,  1337,  1338,   119,    85,    31,    23,
      88,    89,  1271,   117,    58,    38,   119,    31,   116,   117,
    1571,   116,   117,    53,    38,    53,  1804,  1337,  1338,   114,
     115,   116,   117,   127,  1832,    26,    27,   127,  1371,    62,
     115,    64,   127,   128,   120,  1304,  1305,    42,    62,    42,
      64,    26,    27,  1501,  1501,  1501,  1665,  1572,    81,  1867,
     119,  1371,    85,   118,  1572,    88,    89,    81,  1866,    55,
       8,    85,   120,  1871,    88,    89,    96,    97,    98,    99,
     100,   101,    20,    21,   115,    23,    53,  1885,    86,  1867,
     117,    29,  1601,  1644,    71,    33,    49,   116,   117,    52,
      28,   114,   115,  1436,  1436,    43,    28,  1658,   116,   117,
     120,   124,  1625,   120,   127,   128,  1516,    88,    88,  1917,
    1910,    59,    28,   120,    62,  1734,  1436,    42,   118,  1529,
    1389,    65,    55,   120,    53,  1394,   120,   120,    76,   115,
      86,     7,  1217,    81,    56,    95,    94,    85,  1223,  1224,
    1665,    89,   113,  1601,  1601,  1601,   113,  1665,   111,   112,
    1419,   127,   115,   106,   107,   108,   109,  1500,    71,  1244,
     117,  1246,   125,   126,   127,   128,  1251,  1252,    28,   120,
     114,   115,   116,   117,     5,  1564,    42,   117,    53,  1698,
    1500,    12,    13,   127,   128,   116,   127,  1456,  1457,    72,
      73,    42,    23,   119,    77,    78,    79,    80,    88,  1825,
      31,    88,   119,   115,  1614,    98,   120,    38,    42,  1734,
      53,   117,  1297,   116,   116,   115,  1734,   127,   117,   102,
     103,   104,   120,  1633,   121,  1851,   106,   107,   108,   109,
    1856,    62,    20,    64,   120,   120,  1625,  1625,   120,  1698,
    1698,  1698,  1698,  1695,  1564,  1698,  1872,  1698,     5,   116,
      81,   120,   117,   127,    85,    12,    13,    88,    89,    96,
      97,    98,    99,   100,   101,   120,    23,   117,     5,   115,
    1539,  1614,   120,    98,    31,    12,    13,   106,   107,   108,
     109,    38,  1625,    20,   119,    28,    23,    24,    60,    35,
    1916,   127,  1702,    18,    31,    32,   106,   107,   108,   109,
      70,    38,  1571,    74,    36,    62,  1867,    64,   861,   862,
     863,   864,    28,  1398,    96,    97,    98,    99,   100,   101,
    1589,   120,   116,   120,    81,    62,   117,    64,    85,  1852,
     123,    88,    89,    28,   121,  1745,    53,    35,  1423,    76,
     120,   120,     5,    70,    81,    74,    36,   120,    85,    12,
      13,    88,   120,  1763,  1814,    20,    35,    20,     5,   120,
      23,    24,   120,  1448,    32,    12,    13,    75,    31,    32,
      32,   116,   120,    20,    54,    38,    23,    24,    96,    97,
      98,    99,   100,   101,    31,    32,   119,    53,   116,   120,
    1475,    38,  1781,   176,   177,   178,   179,   180,   181,    62,
      67,    64,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   116,    76,   120,    62,    54,    64,    81,   119,
     116,   120,    85,   101,     5,    88,    86,    47,    60,    76,
     127,    12,    13,   127,    81,    75,   127,    47,    85,    20,
       5,    88,    23,    24,   116,   127,    60,    12,    13,   120,
      31,    32,    98,   127,   115,    20,   120,    38,    23,    24,
     117,  1781,   120,  1852,  1852,    34,    31,    32,    42,  1554,
       5,    82,    91,    38,    87,   120,    46,    12,    86,   116,
     101,    62,    42,    64,   120,    20,    91,    82,    23,    24,
     120,    87,   127,    28,    46,    76,    31,    62,   122,    64,
      81,  1586,   125,    38,    85,    47,     5,    88,   115,  1852,
     116,    76,     5,    12,    13,   117,    81,   120,    98,    12,
      85,    20,   115,    88,    23,    24,    34,    62,   120,    64,
      23,    24,    31,    32,   116,  1804,   115,    47,    31,    38,
      33,    76,   120,     8,   120,    38,    81,   120,   120,    39,
      85,    49,    47,    88,    52,    20,    21,    55,    23,    47,
      40,   120,   120,    62,    29,    64,    91,  1652,    33,    62,
     120,    64,   120,  1658,   120,    32,   120,    76,    43,   120,
      18,   120,    81,    76,   122,   125,    85,    91,    81,    88,
      49,   120,    85,    52,    59,    88,    49,    62,    57,    52,
     120,    32,    55,   120,   120,   103,   104,    39,   120,   127,
      47,    76,    40,   111,   112,   120,    81,   115,    47,    32,
      85,    32,   116,   120,    89,     4,   127,   125,   126,   127,
     128,   120,    49,    91,   120,    52,  1721,   120,   120,     4,
      57,   120,   116,   120,   103,   104,    91,    28,    28,   117,
     103,   104,   111,   112,    28,   121,   115,    28,   111,   112,
      49,    28,   115,    52,    28,   121,   125,   126,   127,   128,
     117,    32,   125,   126,   127,   128,    32,    28,    61,   120,
      49,    28,    26,    52,   120,    19,   103,   104,    28,    46,
     120,    19,    28,  1778,   111,   112,    28,    46,   115,    49,
    1785,    61,    52,    28,   120,   120,   120,    26,   125,   126,
     127,   128,   120,   120,   103,   104,   176,   177,   178,   179,
     180,   181,   111,   112,    63,    91,   115,   182,   183,   184,
     185,   186,   187,   122,   103,   104,   125,   126,   127,   128,
      34,    82,   111,   112,   120,   120,   115,   182,   183,   184,
     185,   186,   187,   103,   104,    37,   125,   126,   127,   128,
      82,   111,   112,    72,    73,   115,   120,    37,    77,    78,
      79,    80,    63,    91,   120,   125,   126,   127,   128,    72,
      73,    34,    28,    63,    77,    78,    79,    80,    63,   120,
     120,    72,    73,   102,   103,   104,    77,    78,    79,    80,
     846,   847,   848,   849,   850,   851,   120,   120,   120,   102,
     103,   104,   846,   847,   848,   849,   850,   851,   117,   120,
     120,   102,   103,   104,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   836,   837,   838,   839,   840,   841,
     842,   843,   844,   845,   836,   837,   838,   839,   840,   841,
     842,   843,   844,   845,   852,   853,   854,   855,   856,   857,
     120,   852,   853,   854,   855,   856,   857,   117,   120,   120,
      28,   120,   120,    28,    14,    14,   120,   120,   548,  1896,
     137,   469,  1339,   598,   157,    78,   249,   242,   223,   915,
     368,  1279,   914,   161,  1100,   605,  1204,   556,  1184,  1697,
    1184,  1807,   506,  1184,   749,  1763,  1499,  1502,   749,  1184,
     980,  1371,  1368,  1707,   996,  1366,  1165,  1698,  1323,  1507,
    1902,   537,  1220,   830,  1458,   634,  1037,  1030,  1241,   329,
    1024,  1023,  1396,  1227,  1734,   782,  1305,   679,  1734,  1789,
    1305,  1305,  1305,  1834,  1778,  1573,   936,   936,  1305,  1136,
    1570,  1419,  1082,  1717,  1416,  1414,  1734,  1734,  1170,  1326,
    1578
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   130,   131,   139,   140,     0,     8,     9,    21,    22,
      29,    44,    59,    88,   141,   142,   143,   144,   146,   156,
     161,   165,   169,   441,   446,   450,   127,   127,   127,   127,
     127,   127,   138,    15,    16,   127,   127,   128,   145,   213,
     233,   234,   235,   238,   239,   240,   241,    53,    53,    53,
      53,    42,   117,   120,   127,   127,    42,   117,   120,   114,
     115,   207,   124,   114,   207,    65,    66,   127,   127,   127,
     127,   127,   147,   127,    42,    42,   166,   235,    49,    52,
      55,   103,   104,   111,   112,   115,   125,   126,   133,   137,
     209,   210,   211,   212,   213,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   230,
     231,   232,   233,   235,   244,   245,   246,   247,   278,   284,
       6,   126,   127,   128,   132,   237,    42,    42,    42,    42,
      35,    60,   149,   150,   151,   170,   451,   167,   213,   246,
     213,   227,   228,   233,   227,   231,   232,   231,    57,   214,
     215,   249,   250,   252,   284,   127,   208,   121,   123,    65,
     114,   213,   280,    25,    83,   288,     7,    48,    51,    56,
      94,    95,     7,    56,    95,    94,    96,    97,    98,    99,
     100,   101,    72,    73,    77,    78,    79,    80,   102,   103,
     104,   106,   107,   108,   109,   113,   116,   117,   157,   442,
     162,   447,   193,   194,   191,   192,   152,   151,   150,   171,
     452,     5,    12,    20,    23,    24,    28,    31,    38,    62,
      64,    76,    81,    85,   144,   173,   176,   181,   182,   183,
     184,   254,   275,   289,   290,   296,   297,   301,   304,   305,
     406,   207,   213,   248,   116,   117,   121,   251,   116,   117,
     212,   215,   233,   215,   287,   115,   244,   207,   279,   280,
     214,   215,   216,   221,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   222,   223,   222,   222,   222,   222,   222,
     224,   225,   224,   224,   224,   224,   224,   227,   227,   227,
     229,   230,   229,   229,   229,   231,   214,   249,   250,   159,
     444,   163,   448,   120,   115,   197,   120,   197,   148,   173,
     174,   182,   186,   290,   301,   304,   305,    28,   173,   177,
     186,     5,    23,    28,    31,    38,    62,    64,    81,    85,
      88,   435,   454,   456,   460,   461,   462,   463,   465,   532,
     552,   565,   572,   573,   127,   127,   127,   138,     6,    57,
     233,   302,   371,    59,   127,   155,   168,   127,   127,   138,
     127,   253,   253,   120,    33,   248,   249,   214,   123,   210,
     285,   288,   214,   121,    13,    32,   173,   175,   186,   290,
     301,   304,   305,   406,   417,    12,    13,    20,    24,    32,
      76,   454,   455,   465,   566,   577,   580,   581,   682,   693,
      12,    32,   144,   180,   305,   408,    12,    32,   435,   459,
     581,   684,    23,    31,    76,    89,   199,   202,   294,    13,
     153,    42,    59,   155,   172,   127,   127,   434,    59,   127,
     440,   453,   127,   127,   127,   531,   531,   127,   128,   436,
     491,   511,   512,   513,   516,   517,   518,   519,    42,   120,
      33,   119,    53,   119,    42,   366,   119,   119,   303,   155,
     120,   119,   185,   195,   196,   119,    42,    42,   255,   132,
     116,   215,   252,   214,   116,   214,   158,     6,    57,   138,
     418,   420,   127,   443,   127,     6,    57,   511,   513,   578,
     647,     6,    57,   434,   694,   696,   434,   127,   233,    28,
     127,   511,    28,   198,   138,   315,   316,    28,   187,    15,
     120,   119,   117,   119,    16,   120,   119,   464,   473,   474,
      42,    42,   533,   117,   120,   114,   115,   485,   124,   114,
     485,    65,    66,   127,   466,   127,   128,   428,   213,   276,
     277,   278,     6,    57,   132,   306,   307,   213,   407,   276,
     213,   117,   276,   197,   276,   276,     3,    10,    31,    67,
     115,   256,   257,   260,   264,   268,   270,   273,   274,   280,
     120,   185,   316,   421,   422,   423,   119,    53,   119,   592,
      42,   642,   119,   579,   697,   698,   699,   119,   119,   409,
      21,   155,   164,   685,    22,   440,   449,   116,   120,   119,
     317,   318,    29,   154,   155,   190,   155,   491,   553,   554,
     127,   553,   440,   553,   115,   475,   553,     3,    10,    31,
      65,    67,   115,   534,   535,   538,   542,   546,   547,   550,
     551,   556,   120,   513,    49,    52,    55,   103,   104,   111,
     112,   115,   125,   126,   429,   433,   487,   488,   489,   490,
     491,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   508,   509,   510,   511,   522,
     523,   524,   525,   554,   560,     6,   126,   428,   515,   468,
     464,   279,    42,   308,    42,   119,   120,   149,   118,   293,
       4,   371,    55,   298,    18,    68,   291,   295,   120,   277,
     115,   281,    53,   138,   272,   126,   127,   134,   258,    86,
      71,    28,   317,   120,    88,   213,   419,     6,    57,   428,
     582,   583,   491,    28,   593,   594,   683,   491,   117,   120,
      88,   491,   695,   553,   411,   155,   120,   687,   440,   120,
     199,    17,    39,    41,    45,    58,   201,   203,    11,    61,
      63,    93,   115,   127,   213,   233,   234,   244,   319,   320,
     321,   323,   342,   343,   345,   346,   353,   355,   363,   375,
     396,   155,   120,    13,    89,   173,   178,   186,   292,   304,
     305,   485,   491,   555,   556,    42,   118,   569,    55,   574,
      23,    31,    76,    89,   477,   480,   570,   120,   553,   115,
     557,    53,   491,   493,   511,   563,   434,   549,   126,   127,
     430,   536,    86,   491,   524,   505,   506,   505,   509,   510,
     509,    57,   492,   493,   527,   528,   530,   560,   127,   486,
     121,   123,   114,    25,    83,   564,     7,    48,    51,    56,
      94,    95,     7,    56,    95,    94,    96,    97,    98,    99,
     100,   101,    72,    73,    77,    78,    79,    80,   102,   103,
     104,   106,   107,   108,   109,   113,   116,   117,    13,    89,
     454,   457,   465,   568,   580,   581,    71,   233,   117,   214,
       8,    20,    21,    23,    29,    33,    43,    59,    62,    76,
      81,    85,    89,   309,    28,   214,   120,   214,   214,    42,
     299,   293,   213,   214,   240,   242,   265,   267,   276,   283,
     286,    53,   213,   119,   271,   117,   259,   116,   127,   262,
     276,     8,   155,   160,    21,    29,    55,   426,   584,    42,
     119,   120,     9,   440,   445,    11,    61,    63,    93,   115,
     127,   491,   511,   512,   522,   595,   596,   597,   599,   618,
     619,   621,   622,   629,   631,   639,   651,   672,    35,    60,
     437,   438,   439,     4,   647,    21,    29,    55,   702,    18,
      68,   567,   571,   144,   410,   435,   686,   276,   214,   385,
      63,   213,   346,   355,   375,   394,   395,   396,   115,   368,
     214,   119,   120,   120,    98,   372,   373,   138,   555,   556,
     511,   492,   493,   120,   492,    42,   575,   476,   434,   491,
     492,   518,   520,   543,   545,   553,   559,   562,    53,   491,
     561,   564,   119,   548,   117,   537,   116,   127,   540,   485,
     491,   526,   116,   117,   121,   529,   116,   117,   490,   493,
     511,   115,   522,   492,   494,   499,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   500,   501,   500,   500,   500,
     500,   500,   502,   503,   502,   502,   502,   502,   502,   505,
     505,   505,   507,   508,   507,   507,   507,   509,   492,   527,
     528,   648,   649,   434,   553,   120,   132,   120,    20,   120,
      39,    58,   300,   120,   120,    65,   288,   115,   243,   116,
     117,   266,   282,   276,   276,    28,   272,   258,   120,   261,
     155,   120,   213,   127,   236,   424,   117,   492,     8,    20,
      21,    23,    29,    33,    43,    59,    62,    76,    81,    85,
      89,   585,   440,   120,   492,   661,    63,   491,   622,   631,
     651,   670,   671,   672,   115,   644,   492,   119,   120,   120,
      98,   471,   472,   469,   470,    28,   439,   438,   492,   491,
     127,   514,   700,   569,    28,    32,   408,   412,   413,    28,
      32,   684,   688,   689,    18,   200,    70,   378,   368,   120,
     369,   371,   366,    74,   322,    36,   354,    28,    19,    30,
      37,    50,    52,    70,    71,    90,   127,   353,   374,   375,
     376,   379,   382,   386,   389,   390,   391,   393,   394,   397,
     399,   401,   402,   119,   120,    39,    58,   576,   120,   116,
     120,   119,    65,   564,   115,   521,   116,   117,   544,   558,
     553,   492,   553,    28,   549,   536,   120,   539,   526,   527,
     492,   123,   488,   492,   121,    28,    19,    30,    37,    50,
      52,    70,    71,    90,   127,   629,   650,   651,   652,   655,
     658,   662,   665,   666,   667,   669,   670,   673,   675,   677,
     678,   119,   155,   214,   122,   214,   214,    53,   213,   267,
     116,   117,   120,    67,   127,   269,    28,   127,   263,   115,
     124,   427,    35,   338,   339,   428,   120,    70,   654,   644,
     120,   645,   647,   642,    74,   598,    36,   630,   120,   475,
     120,   475,    20,   120,   115,   124,   703,    35,   614,   615,
     120,    32,   127,   418,    32,   127,   694,   293,   214,    75,
     377,   366,   116,   370,   364,   353,    14,    20,    21,    29,
      32,    37,   213,   310,   312,   313,   324,   325,   336,   337,
     342,   343,   345,   358,   363,   419,    40,    69,    84,   400,
      33,    62,   188,   214,   155,   385,   155,   120,   214,   214,
     398,    54,   405,   119,    98,   118,    92,   311,   313,   314,
     388,   276,   492,   477,    17,    39,    41,    45,    58,   479,
     481,   122,   492,   492,    53,   491,   545,   116,   117,   120,
      67,    28,   127,   541,   116,   493,   530,   116,   492,   428,
     467,   492,   440,   661,   440,   120,   492,   492,   674,    54,
     681,   119,    98,   118,    32,    92,   587,   589,   590,   664,
     553,   120,   116,   276,    65,   266,   213,   283,   155,    86,
     101,   127,   127,    47,    60,   340,   341,   492,    75,   653,
     642,   116,   646,   640,   629,    14,    20,    21,    29,    37,
     491,   586,   588,   589,   600,   601,   612,   613,   618,   619,
     621,   634,   639,   695,    40,    69,    84,   676,   440,   127,
     127,    47,    60,   616,   617,   120,   339,   341,   416,   422,
     425,   120,   615,   617,   692,   698,   701,   214,   120,   365,
     117,   367,    98,   115,   333,   419,   213,   236,   127,   385,
      34,   338,    35,    60,   214,   347,   348,   132,   189,    42,
      91,   392,    82,   392,   377,   120,   369,    87,   404,   400,
     214,   385,    46,   293,   553,   116,   553,    65,   544,   491,
     559,    86,   101,   120,    42,    91,   668,    82,   668,   653,
     120,   645,    87,   680,   676,   492,   127,   661,    46,   569,
     125,   135,   136,   116,   115,   204,   205,    47,   492,   120,
     641,   117,   643,    98,   115,   609,   695,   491,   514,   661,
      34,   614,    35,    60,   492,   623,   624,   120,   116,   115,
     482,   483,    47,   340,   414,   120,   120,   616,   690,   120,
     120,   367,   371,    13,   173,   179,   186,   292,   304,   305,
     354,   385,   366,   427,    39,   359,   340,    47,    47,    40,
     120,   214,   349,   351,   120,    91,   380,   385,   120,   372,
     120,   120,   385,    32,   403,   349,   120,   387,   120,    18,
     478,   125,   431,   432,    91,   656,   661,   120,   648,   120,
     120,   661,    32,   679,   492,   625,   627,   120,    39,   663,
     120,   120,   127,   209,   205,   643,   647,    13,   454,   458,
     465,   568,   580,   581,   630,   661,   642,   703,   635,   616,
      47,    47,    40,   120,   625,   487,   483,   408,   415,   684,
     691,    13,   372,   400,   116,   326,   283,   360,   361,   120,
     205,   205,     4,   352,    91,   350,   250,   381,   384,   214,
     120,   120,   372,   569,   120,   127,   528,   657,   660,   492,
     120,     4,   628,   120,   626,   559,   648,   206,    13,   648,
     676,   116,   602,   636,   637,   120,   483,   483,    91,   484,
      28,    28,   372,    28,   356,   357,   150,   332,   315,    13,
     173,   186,   290,   301,   304,   305,   362,   406,   417,   340,
     338,   214,   385,   117,   121,    28,   380,    26,    27,   383,
      28,   121,    28,   656,    26,    27,   659,   492,   117,    28,
     116,   117,   648,    28,   632,   633,   438,   608,   591,   592,
      13,   454,   465,   566,   577,   580,   581,   638,   682,   693,
     616,   614,   661,   116,   117,    32,    32,    28,    61,   344,
     120,   349,   335,   339,   327,    28,   120,   120,    26,   351,
     372,    19,   372,   385,    28,    46,   648,    19,   648,   661,
      28,   627,    46,   209,    28,    61,   620,   120,   625,   611,
     615,   603,    28,   593,   120,   120,    26,   487,   120,   120,
     344,    63,    91,   120,   151,   331,    34,   120,    82,    37,
     155,   120,    82,    37,   440,   620,    63,    91,   120,   439,
     607,    34,    63,   155,   250,   334,   341,   328,   155,   372,
     120,   120,   648,   120,   120,    63,   440,   528,   610,   617,
     604,   440,   155,   120,   117,   120,   330,   120,   440,   120,
     117,   120,   606,   120,   120,    13,   175,   120,    13,   455,
     329,   605,   316,   592,    28,    28,    14,    14,   155,   440,
     120,   120
};

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
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc)
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
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
#else
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
#else
#endif
#endif /* ! YYPARSE_PARAM */





/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
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
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

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
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 465 "bison-parser.yy"
    { YYACCEPT; }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 469 "bison-parser.yy"
    { eof = true; }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 470 "bison-parser.yy"
    { eof = false; }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 474 "bison-parser.yy"
    { (yyval.tree.IIR_TextLiteral) = (yyvsp[(1) - (1)].tree.IIR_Identifier); }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 475 "bison-parser.yy"
    { (yyval.tree.IIR_TextLiteral) = (yyvsp[(1) - (1)].tree.IIR_StringLiteral); }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 480 "bison-parser.yy"
    {
	  (yyval.tree.IIR_Expression) = build_LiteralExpression ((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].tree.IIR_AbstractLiteral));
	}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 483 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = build_Expr(mVAUL_SimpleName((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].tree.IIR_CharacterLiteral))); }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 484 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = (yyvsp[(1) - (1)].tree.IIR_PhysicalLiteral); }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 485 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = mVAUL_AmbgNullExpr((yylsp[(1) - (1)]), NULL); }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 489 "bison-parser.yy"
    { (yyval.tree.IIR_TextLiteral) = (yyvsp[(1) - (1)].tree.IIR_CharacterLiteral); }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 490 "bison-parser.yy"
    { (yyval.tree.IIR_TextLiteral) = (yyvsp[(1) - (1)].tree.IIR_Identifier); }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 495 "bison-parser.yy"
    {
	   if ((yyvsp[(1) - (2)].tree.IIR_AbstractLiteral) == NULL)
             (yyvsp[(1) - (2)].tree.IIR_AbstractLiteral) = mIIR_IntegerLiteral((yylsp[(1) - (2)]), (IR_Character *)"1", 1);
	   (yyval.tree.IIR_PhysicalLiteral) = build_PhysicalLiteral((yyvsp[(1) - (2)].tree.IIR_AbstractLiteral), (yyvsp[(2) - (2)].tree.IIR_Identifier));
        }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 503 "bison-parser.yy"
    { (yyval.tree.IIR_AbstractLiteral) = NULL; }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 509 "bison-parser.yy"
    { (yyval.tree.IIR_PhysicalLiteral) = build_PhysicalLiteral((yyvsp[(1) - (2)].tree.IIR_AbstractLiteral), (yyvsp[(2) - (2)].tree.IIR_Identifier)); }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 514 "bison-parser.yy"
    { (yyval.tree.IIR_IdentifierList) = mIIR_IdentifierList ((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].tree.IIR_Identifier), NULL); }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 516 "bison-parser.yy"
    { (yyval.tree.IIR_IdentifierList) = mIIR_IdentifierList ((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].tree.IIR_Identifier), (yyvsp[(1) - (3)].tree.IIR_IdentifierList)); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 544 "bison-parser.yy"
    { add_libs((yyvsp[(1) - (1)].tree.IIR_IdentifierList)); }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 545 "bison-parser.yy"
    { use((yyvsp[(1) - (1)].tree.VAUL_SelNameList)); }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 549 "bison-parser.yy"
    { (yyval.tree.IIR_IdentifierList) = reverse((yyvsp[(2) - (3)].tree.IIR_IdentifierList)); }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 553 "bison-parser.yy"
    { (yyval.tree.VAUL_SelNameList) = reverse((yyvsp[(2) - (3)].tree.VAUL_SelNameList)); }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 557 "bison-parser.yy"
    { (yyval.tree.VAUL_SelNameList) = mVAUL_SelNameList((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].tree.VAUL_SelName), NULL); }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 558 "bison-parser.yy"
    { (yyval.tree.VAUL_SelNameList) = mVAUL_SelNameList((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].tree.VAUL_SelName), (yyvsp[(1) - (3)].tree.VAUL_SelNameList)); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 567 "bison-parser.yy"
    {
      pIIR_EntityDeclaration e = mIIR_EntityDeclaration((yylsp[(2) - (3)]), (yyvsp[(2) - (3)].tree.IIR_Identifier));
      start (e);
      (yyval.tree.IIR_EntityDeclaration) = e;
    }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 574 "bison-parser.yy"
    {
	  pIIR_EntityDeclaration e = (yyvsp[(4) - (6)].tree.IIR_EntityDeclaration);
	  push_concurrent_stats_tail (&e->entity_statement_part);
	}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 580 "bison-parser.yy"
    {
      pIIR_EntityDeclaration e = (yyvsp[(4) - (11)].tree.IIR_EntityDeclaration);
      if ((yyvsp[(10) - (11)].tree.IIR_Identifier) && !vaul_name_eq((yyvsp[(10) - (11)].tree.IIR_Identifier), (yyvsp[(2) - (11)].tree.IIR_Identifier)))
	error ("%n does not match entity name %n", (yyvsp[(10) - (11)].tree.IIR_Identifier), (yyvsp[(2) - (11)].tree.IIR_Identifier));
      pop_concurrent_stats_tail (&e->entity_statement_part);
      pop_scope (e);
    }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 605 "bison-parser.yy"
    {
	  vaul_set_generics (cur_scope, (yyvsp[(2) - (3)].tree.IIR_InterfaceList));
	}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 620 "bison-parser.yy"
    {
	  vaul_set_ports (cur_scope, (yyvsp[(2) - (3)].tree.IIR_InterfaceList));
	}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 636 "bison-parser.yy"
    { (yyval.tree.IIR_Identifier) = (yyvsp[(2) - (2)].tree.IIR_Identifier); }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 637 "bison-parser.yy"
    { (yyval.tree.IIR_Identifier) = (yyvsp[(1) - (1)].tree.IIR_Identifier); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 641 "bison-parser.yy"
    { (yyval.tree.IIR_Identifier) = NULL; }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 642 "bison-parser.yy"
    { (yyval.tree.IIR_Identifier) = (yyvsp[(1) - (1)].tree.IIR_Identifier); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 647 "bison-parser.yy"
    {
      pIIR_EntityDeclaration entity = get_entity ((yyvsp[(4) - (5)].tree.IIR_Identifier));
      pIIR_ArchitectureDeclaration a = mIIR_ArchitectureDeclaration ((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].tree.IIR_Identifier),
                                                                     entity);
      a->continued = entity;
      start (a);
      (yyval.tree.IIR_ArchitectureDeclaration) = a;
    }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 657 "bison-parser.yy"
    {
	  pIIR_ArchitectureDeclaration a =
	    (yyvsp[(6) - (8)].tree.IIR_ArchitectureDeclaration);
	  push_concurrent_stats_tail (&a->architecture_statement_part);
	}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 664 "bison-parser.yy"
    {
      pIIR_ArchitectureDeclaration a = (yyvsp[(6) - (13)].tree.IIR_ArchitectureDeclaration);
      if ((yyvsp[(12) - (13)].tree.IIR_Identifier) && !vaul_name_eq((yyvsp[(12) - (13)].tree.IIR_Identifier), (yyvsp[(2) - (13)].tree.IIR_Identifier)))
	error ("%n does not match architecture name %n", (yyvsp[(12) - (13)].tree.IIR_Identifier), (yyvsp[(2) - (13)].tree.IIR_Identifier));
      pop_concurrent_stats_tail (&a->architecture_statement_part);
      pop_scope ((yyvsp[(6) - (13)].tree.IIR_ArchitectureDeclaration));
    }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 678 "bison-parser.yy"
    { (yyval.tree.IIR_Identifier) = (yyvsp[(2) - (2)].tree.IIR_Identifier); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 679 "bison-parser.yy"
    { (yyval.tree.IIR_Identifier) = (yyvsp[(1) - (1)].tree.IIR_Identifier); }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 685 "bison-parser.yy"
    {
      pIIR_ConfigurationDeclaration c =
	mIIR_ConfigurationDeclaration ((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].tree.IIR_Identifier), get_entity((yyvsp[(4) - (5)].tree.IIR_Identifier)));
      start (c);
      (yyval.tree.IIR_ConfigurationDeclaration) = c;
    }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 694 "bison-parser.yy"
    {
      (yyvsp[(6) - (11)].tree.IIR_ConfigurationDeclaration)->block_configuration = (yyvsp[(8) - (11)].tree.IIR_BlockConfiguration);
      if ((yyvsp[(10) - (11)].tree.IIR_Identifier) && !vaul_name_eq((yyvsp[(10) - (11)].tree.IIR_Identifier), (yyvsp[(2) - (11)].tree.IIR_Identifier)))
	error("%n does not match configuration name %n", (yyvsp[(10) - (11)].tree.IIR_Identifier), (yyvsp[(2) - (11)].tree.IIR_Identifier));
      pop_scope ((yyvsp[(6) - (11)].tree.IIR_ConfigurationDeclaration));
    }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 706 "bison-parser.yy"
    { (yyval.tree.IIR_Identifier) = (yyvsp[(2) - (2)].tree.IIR_Identifier); }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 707 "bison-parser.yy"
    { (yyval.tree.IIR_Identifier) = (yyvsp[(1) - (1)].tree.IIR_Identifier); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 713 "bison-parser.yy"
    {	if(vaul_name_eq((yyvsp[(2) - (3)].tree.IIR_Identifier), "standard"))
	    start(mVAUL_StandardPackage((yylsp[(2) - (3)]), (yyvsp[(2) - (3)].tree.IIR_Identifier)));
	else
	    start(mIIR_PackageDeclaration((yylsp[(2) - (3)]), (yyvsp[(2) - (3)].tree.IIR_Identifier)));
    }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 720 "bison-parser.yy"
    {
	if((yyvsp[(7) - (8)].tree.IIR_Identifier) && !vaul_name_eq((yyvsp[(7) - (8)].tree.IIR_Identifier), (yyvsp[(2) - (8)].tree.IIR_Identifier)))
	    error("%n does not match package name %n", (yyvsp[(7) - (8)].tree.IIR_Identifier), (yyvsp[(2) - (8)].tree.IIR_Identifier));
	pop_scope(cur_du->get_tree());
    }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 731 "bison-parser.yy"
    { (yyval.tree.IIR_Identifier) = (yyvsp[(2) - (2)].tree.IIR_Identifier); }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 732 "bison-parser.yy"
    { (yyval.tree.IIR_Identifier) = (yyvsp[(1) - (1)].tree.IIR_Identifier); }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 738 "bison-parser.yy"
    {
      pIIR_PackageDeclaration p = get_package ((yyvsp[(3) - (4)].tree.IIR_Identifier));
      pIIR_PackageBodyDeclaration pb = mIIR_PackageBodyDeclaration ((yylsp[(3) - (4)]), (yyvsp[(3) - (4)].tree.IIR_Identifier), p);
      pb->continued = p;
      start (pb);
    }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 746 "bison-parser.yy"
    {
      if ((yyvsp[(8) - (9)].tree.IIR_Identifier) && !vaul_name_eq((yyvsp[(8) - (9)].tree.IIR_Identifier), (yyvsp[(3) - (9)].tree.IIR_Identifier)))
	error ("%n does not match package name %n", (yyvsp[(8) - (9)].tree.IIR_Identifier), (yyvsp[(3) - (9)].tree.IIR_Identifier));
      pop_scope (cur_du->get_tree());
    }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 757 "bison-parser.yy"
    { (yyval.tree.IIR_Identifier) = (yyvsp[(3) - (3)].tree.IIR_Identifier); }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 758 "bison-parser.yy"
    { (yyval.tree.IIR_Identifier) = (yyvsp[(1) - (1)].tree.IIR_Identifier); }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 772 "bison-parser.yy"
    { use((yyvsp[(1) - (1)].tree.VAUL_SelNameList)); }
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 827 "bison-parser.yy"
    { use((yyvsp[(1) - (1)].tree.VAUL_SelNameList)); }
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 836 "bison-parser.yy"
    {
	  add_decl ((yyvsp[(1) - (2)].tree.IIR_SubprogramDeclaration));
	  if (consumer)
	    consumer->consume_pbody_decl ((yyvsp[(1) - (2)].tree.IIR_SubprogramDeclaration));
	  collect ();
	}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 846 "bison-parser.yy"
    {
	  for (pIIR_InterfaceList il = (yyvsp[(1) - (1)].tree.IIR_SubprogramDeclaration)->interface_declarations;
	       il; il = il->rest)
	    {
	      validate_interface ((yyvsp[(1) - (1)].tree.IIR_SubprogramDeclaration), il->first);
	      add_decl ((yyvsp[(1) - (1)].tree.IIR_SubprogramDeclaration), il->first);
	    }
	  (yyval.tree.IIR_SubprogramDeclaration) = (yyvsp[(1) - (1)].tree.IIR_SubprogramDeclaration);
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 859 "bison-parser.yy"
    {
	  (yyval.tree.IIR_SubprogramDeclaration) = mIIR_ProcedureDeclaration ((yylsp[(2) - (3)]), (yyvsp[(2) - (3)].tree.IIR_Identifier), (yyvsp[(3) - (3)].tree.IIR_InterfaceList));
	}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 864 "bison-parser.yy"
    {
	  (yyval.tree.IIR_SubprogramDeclaration) = mIIR_FunctionDeclaration ((yylsp[(3) - (6)]), (yyvsp[(3) - (6)].tree.IIR_TextLiteral), (yyvsp[(4) - (6)].tree.IIR_InterfaceList), (yyvsp[(1) - (6)].boolean), (yyvsp[(6) - (6)].tree.IIR_Type));
	}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 870 "bison-parser.yy"
    { (yyval.boolean) = true; }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 871 "bison-parser.yy"
    { (yyval.boolean) = true; }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 872 "bison-parser.yy"
    { (yyval.boolean) = false; }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 876 "bison-parser.yy"
    { (yyval.tree.IIR_InterfaceList) = NULL; }
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 882 "bison-parser.yy"
    {
	  pIIR_SubprogramDeclaration body = (yyvsp[(1) - (2)].tree.IIR_SubprogramDeclaration);
	  pIIR_SubprogramDeclaration proto =
	    pIIR_SubprogramDeclaration (add_decl (body));
	  assert (proto->is(IR_SUBPROGRAM_DECLARATION));

	  if (proto->subprogram_body != NULL)
	    {
	      error ("redefinition of %n", body);
	      info ("%: here is the previous definition", proto);
	    }

	  if (body != proto)
	    {
	      body->prototype = proto;
	      add_decl_plain (cur_scope, body);
	    }
 
	  push_scope (body);
	  (yyval.tree.IIR_SubprogramDeclaration) = body;
	}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 907 "bison-parser.yy"
    {
	  pIIR_SubprogramDeclaration body =
	    (yyvsp[(3) - (10)].tree.IIR_SubprogramDeclaration);

	  /* Check whether procedure/function is closed with "end
	     procedure/function" and not with "end
	     function/procedure" */
	  if ((yyvsp[(8) - (10)].kind) != NULL && !(yyvsp[(1) - (10)].tree.IIR_SubprogramDeclaration)->is ((yyvsp[(8) - (10)].kind)))
	    if ((yyvsp[(1) - (10)].tree.IIR_SubprogramDeclaration)->is (IR_PROCEDURE_DECLARATION))
	      error ("parse error, unexpected t_FUNCTION, expecting t_PROCEDURE");
	    else
	      error ("parse error, unexpected t_PROCEDURE, expecting t_FUNCTION");

	  if ((yyvsp[(9) - (10)].tree.IIR_TextLiteral) && !vaul_name_eq ((yyvsp[(9) - (10)].tree.IIR_TextLiteral), body->declarator))
	    error ("%n does not match subprogram designator %n",
		   (yyvsp[(9) - (10)].tree.IIR_TextLiteral), body->declarator);
	  if ((yyvsp[(6) - (10)].tree.IIR_SequentialStatementList))
	    body->subprogram_body = (yyvsp[(6) - (10)].tree.IIR_SequentialStatementList);
	  else
	    body->subprogram_body =
	      mIIR_SequentialStatementList ((yylsp[(6) - (10)]), mIIR_NullStatement ((yylsp[(6) - (10)])), NULL);

	  if (consumer)
	    consumer->consume_pbody_decl (body);
	  collect ();

	  pop_scope (body);
	}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 939 "bison-parser.yy"
    { (yyval.kind) = NULL; }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 940 "bison-parser.yy"
    { (yyval.kind) = IR_PROCEDURE_DECLARATION; }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 941 "bison-parser.yy"
    { (yyval.kind) = IR_FUNCTION_DECLARATION; }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 945 "bison-parser.yy"
    { (yyval.tree.IIR_TextLiteral) = NULL; }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 946 "bison-parser.yy"
    { (yyval.tree.IIR_TextLiteral) = (yyvsp[(1) - (1)].tree.IIR_TextLiteral); }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 960 "bison-parser.yy"
    {
	  cur_default_obj_class = VAUL_ObjClass_Signal;
	}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 964 "bison-parser.yy"
    {
	  for(pIIR_InterfaceList il = (yyvsp[(2) - (2)].tree.IIR_InterfaceList); il; il = il->rest) 
	    {
	      validate_port (il->first);
	      add_decl (il->first);
	    }
	  (yyval.tree.IIR_InterfaceList) = (yyvsp[(2) - (2)].tree.IIR_InterfaceList);
	}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 975 "bison-parser.yy"
    {
	  cur_default_obj_class = VAUL_ObjClass_Constant;
	}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 979 "bison-parser.yy"
    {
	  for(pIIR_InterfaceList il = (yyvsp[(2) - (2)].tree.IIR_InterfaceList); il; il = il->rest) 
	    {
	      validate_generic (il->first);
	      add_decl (il->first);
	    }
	  (yyval.tree.IIR_InterfaceList) = (yyvsp[(2) - (2)].tree.IIR_InterfaceList);
	}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 990 "bison-parser.yy"
    {
	  cur_default_obj_class = VAUL_ObjClass_None;
	}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 994 "bison-parser.yy"
    {
          (yyval.tree.IIR_InterfaceList) = (yyvsp[(2) - (2)].tree.IIR_InterfaceList);
	}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1001 "bison-parser.yy"
    {
	  pIIR_InterfaceList i;
	  for (i = (yyvsp[(2) - (4)].tree.IIR_InterfaceList); i && i->rest; i = i->rest)
	    ;
	  if (i)
	    {
	      i->rest = (yyvsp[(3) - (4)].tree.IIR_InterfaceList);
	      (yyval.tree.IIR_InterfaceList) = (yyvsp[(2) - (4)].tree.IIR_InterfaceList);
	    }
	  else
	    (yyval.tree.IIR_InterfaceList) = (yyvsp[(3) - (4)].tree.IIR_InterfaceList);
	}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1016 "bison-parser.yy"
    { (yyval.tree.IIR_InterfaceList) = NULL; }
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1018 "bison-parser.yy"
    {
	  pIIR_InterfaceList i;
	  for (i = (yyvsp[(1) - (3)].tree.IIR_InterfaceList); i && i->rest; i = i->rest)
	    ;
	  if (i)
	    {
	      i->rest = (yyvsp[(3) - (3)].tree.IIR_InterfaceList);
	      (yyval.tree.IIR_InterfaceList) = (yyvsp[(1) - (3)].tree.IIR_InterfaceList);
	    }
	  else
	    (yyval.tree.IIR_InterfaceList) = (yyvsp[(3) - (3)].tree.IIR_InterfaceList);
	}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1035 "bison-parser.yy"
    {
	  (yyval.tree.IIR_InterfaceList) = NULL;
	  overload_resolution ((yyvsp[(7) - (7)].tree.IIR_Expression), (yyvsp[(5) - (7)].tree.IIR_Type));
	  for (pIIR_IdentifierList idl = (yyvsp[(2) - (7)].tree.IIR_IdentifierList); idl; idl = idl->rest)
	    (yyval.tree.IIR_InterfaceList) = mIIR_InterfaceList((yylsp[(2) - (7)]), build_Interface (idl->first, (yyvsp[(5) - (7)].tree.IIR_Type), (yyvsp[(7) - (7)].tree.IIR_Expression),
							 (yyvsp[(1) - (7)].obj_class), (yyvsp[(4) - (7)].mode), (yyvsp[(6) - (7)].boolean)),
	                            (yyval.tree.IIR_InterfaceList));
	}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1046 "bison-parser.yy"
    { (yyval.boolean) = false; }
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1047 "bison-parser.yy"
    { (yyval.boolean) = true; }
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1051 "bison-parser.yy"
    { (yyval.mode) = IR_UNKNOWN_MODE; }
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1056 "bison-parser.yy"
    { (yyval.obj_class) = VAUL_ObjClass_None; }
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1061 "bison-parser.yy"
    { (yyval.mode) = IR_IN_MODE; }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1062 "bison-parser.yy"
    { (yyval.mode) = IR_OUT_MODE; }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1063 "bison-parser.yy"
    { (yyval.mode) = IR_INOUT_MODE; }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1064 "bison-parser.yy"
    { (yyval.mode) = IR_BUFFER_MODE; }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1065 "bison-parser.yy"
    { (yyval.mode) = IR_LINKAGE_MODE; }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1070 "bison-parser.yy"
    {
	    (yyval.tree.VAUL_GenAssocElem) = (yyvsp[(2) - (4)].tree.VAUL_GenAssocElem);
	    pVAUL_GenAssocElem ae = (yyvsp[(2) - (4)].tree.VAUL_GenAssocElem);
	    while (ae->next)
		ae = ae->next;
	    ae->next = reverse ((yyvsp[(3) - (4)].tree.VAUL_GenAssocElem));
        }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1081 "bison-parser.yy"
    {   
	    (yyval.tree.VAUL_NamedAssocElem) = prepare_named_assocs((yyvsp[(1) - (1)].tree.VAUL_GenAssocElem))? pVAUL_NamedAssocElem((yyvsp[(1) - (1)].tree.VAUL_GenAssocElem)) : NULL;
	}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1087 "bison-parser.yy"
    { (yyval.tree.VAUL_GenAssocElem) = NULL; }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1089 "bison-parser.yy"
    {
	    pVAUL_GenAssocElem ae = (yyvsp[(3) - (3)].tree.VAUL_GenAssocElem);
	    while (ae->next)
	        ae = ae->next;
	    ae->next = (yyvsp[(1) - (3)].tree.VAUL_GenAssocElem);
	    (yyval.tree.VAUL_GenAssocElem) = (yyvsp[(3) - (3)].tree.VAUL_GenAssocElem);
	}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1101 "bison-parser.yy"
    {
	    (yyval.tree.VAUL_GenAssocElem) = reverse((yyvsp[(3) - (4)].tree.VAUL_GenAssocElem));
	    if((yyvsp[(2) - (4)].tree.VAUL_GenAssocElem)) {
		pVAUL_GenAssocElem ae = (yyvsp[(2) - (4)].tree.VAUL_GenAssocElem);
		while (ae->next)
		    ae = ae->next;
		ae->next = (yyval.tree.VAUL_GenAssocElem);
		(yyval.tree.VAUL_GenAssocElem) = (yyvsp[(2) - (4)].tree.VAUL_GenAssocElem);
	    }
	}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1114 "bison-parser.yy"
    { (yyval.tree.VAUL_GenAssocElem) = NULL; }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1116 "bison-parser.yy"
    {
	    (yyval.tree.VAUL_GenAssocElem) = (yyvsp[(1) - (3)].tree.VAUL_GenAssocElem);
	    if((yyvsp[(3) - (3)].tree.VAUL_GenAssocElem)) {
		pVAUL_GenAssocElem ae = (yyvsp[(3) - (3)].tree.VAUL_GenAssocElem);
		while (ae->next)
		    ae = ae->next;
		ae->next = (yyval.tree.VAUL_GenAssocElem);
		(yyval.tree.VAUL_GenAssocElem) = (yyvsp[(3) - (3)].tree.VAUL_GenAssocElem);
	    }
	}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1130 "bison-parser.yy"
    {
	    pIIR_Expression a = validate_Expr ((yyvsp[(3) - (3)].tree.IIR_Root));
	    (yyval.tree.VAUL_GenAssocElem) = NULL;
	    for (pVAUL_NameList nl = (yyvsp[(1) - (3)].tree.VAUL_NameList); nl; nl = nl->link)
		(yyval.tree.VAUL_GenAssocElem) = mVAUL_NamedAssocElem((yylsp[(2) - (3)]), (yyval.tree.VAUL_GenAssocElem), nl->name, a);
	}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1137 "bison-parser.yy"
    {
	    if((yyvsp[(1) - (1)].tree.IIR_Root) && (yyvsp[(1) - (1)].tree.IIR_Root)->is(IR_RANGE))
		(yyval.tree.VAUL_GenAssocElem) = mVAUL_RangeAssocElem((yylsp[(1) - (1)]), NULL, pIIR_Range((yyvsp[(1) - (1)].tree.IIR_Root)));
	    else 
		(yyval.tree.VAUL_GenAssocElem) = mVAUL_NamedAssocElem((yylsp[(1) - (1)]), NULL, NULL, validate_Expr((yyvsp[(1) - (1)].tree.IIR_Root)));
	}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1151 "bison-parser.yy"
    { (yyval.tree.VAUL_NameList) = mVAUL_NameList ((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].tree.VAUL_Name), NULL); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1152 "bison-parser.yy"
    { (yyval.tree.VAUL_NameList) = mVAUL_NameList ((yylsp[(1) - (3)]), (yyvsp[(3) - (3)].tree.VAUL_Name), (yyvsp[(1) - (3)].tree.VAUL_NameList)); }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1157 "bison-parser.yy"
    { (yyval.tree.IIR_Root) = mIIR_OpenExpression((yylsp[(1) - (1)]), NULL); }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1165 "bison-parser.yy"
    { (yyval.tree.VAUL_Name) = mVAUL_SimpleName((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].tree.IIR_Identifier)); }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1166 "bison-parser.yy"
    { (yyval.tree.VAUL_Name) = (yyvsp[(1) - (1)].tree.VAUL_SelName); }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1171 "bison-parser.yy"
    {
	    (yyval.tree.IIR_Expression) = validate_Expr((yyvsp[(1) - (1)].tree.IIR_Root));
	}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1177 "bison-parser.yy"
    { (yyval.tree.IIR_Root) = (yyvsp[(1) - (1)].tree.IIR_Expression); }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1178 "bison-parser.yy"
    { (yyval.tree.IIR_Root) = (yyvsp[(1) - (1)].tree.IIR_Expression); }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1179 "bison-parser.yy"
    { (yyval.tree.IIR_Root) = (yyvsp[(1) - (1)].tree.IIR_Expression); }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1180 "bison-parser.yy"
    { (yyval.tree.IIR_Root) = (yyvsp[(1) - (1)].tree.IIR_Expression); }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1181 "bison-parser.yy"
    { (yyval.tree.IIR_Root) = (yyvsp[(1) - (1)].tree.IIR_Root); }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1183 "bison-parser.yy"
    { (yyval.tree.IIR_Root) = build_bcall((yyvsp[(1) - (3)].tree.IIR_Expression), "nand", (yyvsp[(3) - (3)].tree.IIR_Expression)); }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1185 "bison-parser.yy"
    { (yyval.tree.IIR_Root) = build_bcall((yyvsp[(1) - (3)].tree.IIR_Expression), "nor", (yyvsp[(3) - (3)].tree.IIR_Expression)); }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1190 "bison-parser.yy"
    {
	    (yyval.tree.IIR_Expression) = validate_Expr((yyvsp[(1) - (1)].tree.IIR_Root));
	}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1197 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = build_bcall((yyvsp[(1) - (3)].tree.IIR_Expression), "and", (yyvsp[(3) - (3)].tree.IIR_Expression)); }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1199 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = build_bcall((yyvsp[(1) - (3)].tree.IIR_Expression), "and", (yyvsp[(3) - (3)].tree.IIR_Expression)); }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1204 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = build_bcall((yyvsp[(1) - (3)].tree.IIR_Expression), "or", (yyvsp[(3) - (3)].tree.IIR_Expression)); }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1206 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = build_bcall((yyvsp[(1) - (3)].tree.IIR_Expression), "or", (yyvsp[(3) - (3)].tree.IIR_Expression)); }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1211 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = build_bcall((yyvsp[(1) - (3)].tree.IIR_Expression), "xor", (yyvsp[(3) - (3)].tree.IIR_Expression)); }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1213 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = build_bcall((yyvsp[(1) - (3)].tree.IIR_Expression), "xor", (yyvsp[(3) - (3)].tree.IIR_Expression)); }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1218 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = build_bcall((yyvsp[(1) - (3)].tree.IIR_Expression), "xnor", (yyvsp[(3) - (3)].tree.IIR_Expression)); }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1220 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = build_bcall((yyvsp[(1) - (3)].tree.IIR_Expression), "xnor", (yyvsp[(3) - (3)].tree.IIR_Expression)); }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1226 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), "=", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1230 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), "/=", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1234 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), "<", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1238 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), "<=", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1242 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), ">", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1246 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), ">=", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1253 "bison-parser.yy"
    {
	  (yyval.tree.IIR_Expression) = validate_Expr((yyvsp[(1) - (1)].tree.IIR_Root));
	}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1261 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), "sll", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1265 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), "srl", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1269 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), "sla", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1273 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), "sra", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1277 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), "rol", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1281 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), "ror", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1288 "bison-parser.yy"
    {
	  (yyval.tree.IIR_Expression) = validate_Expr((yyvsp[(1) - (1)].tree.IIR_Root));
	}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1296 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), "+", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1300 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), "-", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1304 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), "&", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1312 "bison-parser.yy"
    {
	  (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(2) - (2)].tree.IIR_Expression), "+", NULL);
	}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1316 "bison-parser.yy"
    {
	  (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(2) - (2)].tree.IIR_Expression), "-", NULL);
	}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1323 "bison-parser.yy"
    {
	  (yyval.tree.IIR_Expression) = validate_Expr((yyvsp[(1) - (1)].tree.IIR_Root));
	}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1331 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), "*", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1335 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), "/", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1339 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), "mod", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1343 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), "rem", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1350 "bison-parser.yy"
    {
	  (yyval.tree.IIR_Expression) = validate_Expr((yyvsp[(1) - (1)].tree.IIR_Root));
	}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1358 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(1) - (3)].tree.IIR_Expression), "**", (yyvsp[(3) - (3)].tree.IIR_Expression));
	}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1362 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(2) - (2)].tree.IIR_Expression), "abs", NULL);
	}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1366 "bison-parser.yy"
    {
          (yyval.tree.IIR_Root) = build_bcall ((yyvsp[(2) - (2)].tree.IIR_Expression), "not", NULL);
	}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1373 "bison-parser.yy"
    {
	    (yyval.tree.IIR_Expression) = validate_Expr((yyvsp[(1) - (1)].tree.IIR_Root));
	}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1379 "bison-parser.yy"
    { (yyval.tree.IIR_Root) = build_Expr_or_Attr((yyvsp[(1) - (1)].tree.VAUL_Name)); }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1380 "bison-parser.yy"
    { (yyval.tree.IIR_Root) = (yyvsp[(1) - (1)].tree.IIR_Expression); }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1381 "bison-parser.yy"
    { (yyval.tree.IIR_Root) = (yyvsp[(1) - (1)].tree.VAUL_AmbgAggregate); }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1382 "bison-parser.yy"
    { (yyval.tree.IIR_Root) = (yyvsp[(1) - (1)].tree.IIR_Expression); }
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1383 "bison-parser.yy"
    { (yyval.tree.IIR_Root) = (yyvsp[(1) - (1)].tree.IIR_Expression); }
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1384 "bison-parser.yy"
    { (yyval.tree.IIR_Root) = (yyvsp[(2) - (3)].tree.IIR_Expression); }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1394 "bison-parser.yy"
    { (yyval.tree.VAUL_Name) = mVAUL_SimpleName((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].tree.IIR_StringLiteral)); }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1395 "bison-parser.yy"
    { (yyval.tree.VAUL_Name) = (yyvsp[(1) - (1)].tree.VAUL_AttributeName); }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1400 "bison-parser.yy"
    { (yyval.tree.VAUL_SelName) = mVAUL_SelName((yylsp[(1) - (3)]), (yyvsp[(1) - (3)].tree.VAUL_Name), (yyvsp[(3) - (3)].tree.IIR_TextLiteral)); }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1404 "bison-parser.yy"
    { (yyval.tree.VAUL_Name) = mVAUL_SelName((yylsp[(1) - (3)]), (yyvsp[(1) - (3)].tree.VAUL_Name), (yyvsp[(3) - (3)].tree.IIR_Identifier)); }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1405 "bison-parser.yy"
    { (yyval.tree.VAUL_Name) = mVAUL_SimpleName((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].tree.IIR_Identifier)); }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1409 "bison-parser.yy"
    { (yyval.tree.IIR_TextLiteral) = (yyvsp[(1) - (1)].tree.IIR_TextLiteral); }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1410 "bison-parser.yy"
    { (yyval.tree.IIR_TextLiteral) = (yyvsp[(1) - (1)].tree.IIR_CharacterLiteral); }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1411 "bison-parser.yy"
    { (yyval.tree.IIR_TextLiteral) = make_id("all"); }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1416 "bison-parser.yy"
    {
	    pVAUL_Name n = (yyvsp[(1) - (2)].tree.VAUL_Name); // gcc bug?
	    if(n->is(VAUL_ATTRIBUTE_NAME)) {
		pVAUL_AttributeName(n)->first_actual =
		    prepare_named_assocs((yyvsp[(2) - (2)].tree.VAUL_GenAssocElem))? pVAUL_NamedAssocElem((yyvsp[(2) - (2)].tree.VAUL_GenAssocElem)) : NULL;
		(yyval.tree.VAUL_Name) = n;
	    } else {
		validate_gen_assocs((yyvsp[(2) - (2)].tree.VAUL_GenAssocElem));
		(yyval.tree.VAUL_Name) = mVAUL_IftsName((yylsp[(1) - (2)]), n, (yyvsp[(2) - (2)].tree.VAUL_GenAssocElem));
	    }
	}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1428 "bison-parser.yy"
    {
	    pVAUL_Name n = (yyvsp[(1) - (2)].tree.VAUL_Name); // gcc bug?
	    if(n->is(VAUL_ATTRIBUTE_NAME)) {
		pVAUL_AttributeName(n)->first_actual =
		    prepare_named_assocs((yyvsp[(2) - (2)].tree.VAUL_GenAssocElem))? pVAUL_NamedAssocElem((yyvsp[(2) - (2)].tree.VAUL_GenAssocElem)) : NULL;
		(yyval.tree.VAUL_Name) = n;
	    } else {
		validate_gen_assocs((yyvsp[(2) - (2)].tree.VAUL_GenAssocElem));
		(yyval.tree.VAUL_Name) = mVAUL_IftsName((yylsp[(1) - (2)]), n, (yyvsp[(2) - (2)].tree.VAUL_GenAssocElem));
	    }
	}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1443 "bison-parser.yy"
    { (yyval.tree.VAUL_Name) = (yyvsp[(1) - (2)].tree.VAUL_Name); }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1444 "bison-parser.yy"
    { (yyval.tree.VAUL_Name) = (yyvsp[(1) - (2)].tree.VAUL_Name); }
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1450 "bison-parser.yy"
    { (yyval.tree.VAUL_AttributeName) = mVAUL_AttributeName((yylsp[(1) - (2)]), (yyvsp[(1) - (2)].tree.VAUL_Name), make_id("RANGE"), NULL); }
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1452 "bison-parser.yy"
    { (yyval.tree.VAUL_AttributeName) = mVAUL_AttributeName((yylsp[(1) - (2)]), (yyvsp[(1) - (2)].tree.VAUL_Name), make_id("REVERSE_RANGE"), NULL); }
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1458 "bison-parser.yy"
    { (yyval.tree.VAUL_AttributeName) = mVAUL_AttributeName((yylsp[(1) - (2)]), (yyvsp[(1) - (2)].tree.VAUL_Name), (yyvsp[(2) - (2)].tree.IIR_Identifier), NULL); }
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1459 "bison-parser.yy"
    { (yyval.tree.VAUL_AttributeName) = (yyvsp[(1) - (1)].tree.VAUL_AttributeName); }
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1479 "bison-parser.yy"
    {
	    pVAUL_AttributeName n = (yyval.tree.VAUL_AttributeName) = (yyvsp[(1) - (2)].tree.VAUL_AttributeName);
	    if(n)
		n->first_actual = (yyvsp[(2) - (2)].tree.VAUL_NamedAssocElem);
	}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1499 "bison-parser.yy"
    { (yyval.tree.VAUL_NamedAssocElem) = NULL; }
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1501 "bison-parser.yy"
    { (yyval.tree.VAUL_NamedAssocElem) = mVAUL_NamedAssocElem((yylsp[(1) - (3)]), NULL, NULL, (yyvsp[(2) - (3)].tree.IIR_Expression)); }
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1506 "bison-parser.yy"
    {
	    (yyval.tree.VAUL_AmbgAggregate) = mVAUL_AmbgAggregate((yylsp[(1) - (2)]), NULL, reverse((yyvsp[(1) - (2)].tree.VAUL_ElemAssoc)));
	}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1510 "bison-parser.yy"
    {
	    (yyval.tree.VAUL_AmbgAggregate) = mVAUL_AmbgAggregate((yylsp[(1) - (5)]), NULL, mVAUL_ElemAssoc((yylsp[(3) - (5)]), NULL, (yyvsp[(2) - (5)].tree.IIR_ChoiceList), (yyvsp[(4) - (5)].tree.IIR_Expression)));
	}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1517 "bison-parser.yy"
    {
	    if((yyvsp[(4) - (4)].tree.VAUL_ElemAssoc)) {
		(yyvsp[(4) - (4)].tree.VAUL_ElemAssoc)->next = (yyvsp[(2) - (4)].tree.VAUL_ElemAssoc);
		(yyval.tree.VAUL_ElemAssoc) = (yyvsp[(4) - (4)].tree.VAUL_ElemAssoc);
	    } else
		(yyval.tree.VAUL_ElemAssoc) = (yyvsp[(2) - (4)].tree.VAUL_ElemAssoc);
	}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1525 "bison-parser.yy"
    {
	    if((yyvsp[(3) - (3)].tree.VAUL_ElemAssoc)) {
		(yyvsp[(3) - (3)].tree.VAUL_ElemAssoc)->next = (yyvsp[(1) - (3)].tree.VAUL_ElemAssoc);
		(yyval.tree.VAUL_ElemAssoc) = (yyvsp[(3) - (3)].tree.VAUL_ElemAssoc);
	    } else
		(yyval.tree.VAUL_ElemAssoc) = (yyvsp[(1) - (3)].tree.VAUL_ElemAssoc);
	}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1536 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = build_QualifiedExpr((yyvsp[(1) - (5)].tree.VAUL_Name), (yyvsp[(4) - (5)].tree.IIR_Expression)); }
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1538 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = build_QualifiedExpr((yyvsp[(1) - (3)].tree.VAUL_Name), (yyvsp[(3) - (3)].tree.VAUL_AmbgAggregate)); }
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1544 "bison-parser.yy"
    {
	    pIIR_Type t =
	      mIIR_AccessType((yylsp[(1) - (4)]), build_ArraySubtype ((yyvsp[(2) - (4)].tree.VAUL_Name), (yyvsp[(3) - (4)].tree.VAUL_Name), (yyvsp[(4) - (4)].tree.IIR_TypeList)));
	    (yyval.tree.IIR_Expression) = mIIR_Allocator ((yylsp[(1) - (4)]), t, t, NULL);
	}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1550 "bison-parser.yy"
    {
	    pIIR_Type t =
	      mIIR_AccessType((yylsp[(1) - (3)]), build_ArraySubtype (NULL, (yyvsp[(2) - (3)].tree.VAUL_Name), (yyvsp[(3) - (3)].tree.IIR_TypeList)));
	    pIIR_Allocator a = mIIR_Allocator ((yylsp[(1) - (3)]), t, t, NULL);
	    (yyval.tree.IIR_Expression) = a;
	}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1557 "bison-parser.yy"
    {
	    pIIR_Expression e = (yyvsp[(2) - (2)].tree.IIR_Expression);
	    overload_resolution(e, IR_TYPE);
	    if (e) 
	      {
		assert (e->is(IR_QUALIFIED_EXPRESSION));
		pIIR_QualifiedExpression qe = pIIR_QualifiedExpression(e);
		pIIR_Type t = mIIR_AccessType((yylsp[(1) - (2)]), qe->subtype);
		(yyval.tree.IIR_Expression) = mIIR_Allocator ((yylsp[(1) - (2)]), t, t, qe->expression);
	      }
	    else
	      (yyval.tree.IIR_Expression) = NULL;
	}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1573 "bison-parser.yy"
    { (yyval.tree.IIR_TypeList) = NULL; }
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1574 "bison-parser.yy"
    { (yyval.tree.IIR_TypeList) = build_PreIndexConstraint((yyvsp[(1) - (1)].tree.VAUL_GenAssocElem)); }
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1583 "bison-parser.yy"
    { (yyval.tree.VAUL_ElemAssoc) = mVAUL_ElemAssoc((yylsp[(2) - (3)]), NULL, (yyvsp[(1) - (3)].tree.IIR_ChoiceList), (yyvsp[(3) - (3)].tree.IIR_Expression)); }
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1585 "bison-parser.yy"
    { (yyval.tree.VAUL_ElemAssoc) = mVAUL_ElemAssoc((yylsp[(1) - (1)]), NULL, NULL, (yyvsp[(1) - (1)].tree.IIR_Expression)); }
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1590 "bison-parser.yy"
    {
	  if ((yyvsp[(1) - (2)].tree.IIR_Choice))
	    (yyval.tree.IIR_ChoiceList) = mIIR_ChoiceList ((yylsp[(1) - (2)]), (yyvsp[(1) - (2)].tree.IIR_Choice), (yyvsp[(2) - (2)].tree.IIR_ChoiceList));
	  else
	    (yyval.tree.IIR_ChoiceList) = (yyvsp[(2) - (2)].tree.IIR_ChoiceList);
	}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1599 "bison-parser.yy"
    { (yyval.tree.IIR_ChoiceList) = NULL; }
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1601 "bison-parser.yy"
    {
	  pIIR_ChoiceList cl = mIIR_ChoiceList ((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].tree.IIR_Choice), NULL);
	  if ((yyvsp[(1) - (3)].tree.IIR_ChoiceList))
	    {
	      pIIR_ChoiceList c;
	      for(c = (yyvsp[(1) - (3)].tree.IIR_ChoiceList); c->rest; c = c->rest)
		;
	      c->rest = cl;
	      (yyval.tree.IIR_ChoiceList) = (yyvsp[(1) - (3)].tree.IIR_ChoiceList);
	    } 
	  else
	    (yyval.tree.IIR_ChoiceList) = cl;
	}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1618 "bison-parser.yy"
    {
	  pIIR e = (yyvsp[(1) - (1)].tree.IIR_Root);
	  if (e->is(IR_ARRAY_RANGE))
	    (yyval.tree.IIR_Choice) = mIIR_ChoiceByRange ((yylsp[(1) - (1)]), pIIR_ArrayRange(e));
	  else
	    (yyval.tree.IIR_Choice) = mIIR_ChoiceByExpression ((yylsp[(1) - (1)]), validate_Expr(e));
	}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1626 "bison-parser.yy"
    {
	  (yyval.tree.IIR_Choice) = mIIR_ChoiceByRange ((yylsp[(1) - (1)]), range_from_assoc ((yyvsp[(1) - (1)].tree.VAUL_GenAssocElem)));
	}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1630 "bison-parser.yy"
    {
	  (yyval.tree.IIR_Choice) = mIIR_ChoiceByOthers ((yylsp[(1) - (1)]));
	}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1640 "bison-parser.yy"
    { start_decl((yyvsp[(1) - (1)].tree.IIR_Identifier)); (yyval.tree.IIR_Identifier) = (yyvsp[(1) - (1)].tree.IIR_Identifier); }
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1645 "bison-parser.yy"
    { 
	    pIIR_TypeDeclaration td = add_type_decl(cur_scope, (yyvsp[(3) - (4)].tree.IIR_Type), (yyvsp[(2) - (4)].tree.IIR_Identifier));
	    add_predefined_ops(td->type);
	}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1652 "bison-parser.yy"
    { (yyval.tree.IIR_Type) = mVAUL_IncompleteType(int(0)); }
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1653 "bison-parser.yy"
    { (yyval.tree.IIR_Type) = (yyvsp[(2) - (2)].tree.IIR_Type); }
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1657 "bison-parser.yy"
    { (yyval.tree.IIR_Type) = (yyvsp[(1) - (1)].tree.IIR_Type); }
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1658 "bison-parser.yy"
    { (yyval.tree.IIR_Type) = build_SubType_def((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].tree.IIR_Range)); }
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1659 "bison-parser.yy"
    { (yyval.tree.IIR_Type) = (yyvsp[(1) - (1)].tree.IIR_Type); }
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1660 "bison-parser.yy"
    { (yyval.tree.IIR_Type) = (yyvsp[(1) - (1)].tree.IIR_Type); }
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1661 "bison-parser.yy"
    { (yyval.tree.IIR_Type) = (yyvsp[(1) - (1)].tree.IIR_Type); }
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1662 "bison-parser.yy"
    { (yyval.tree.IIR_Type) = (yyvsp[(1) - (1)].tree.IIR_RecordType); }
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1663 "bison-parser.yy"
    { (yyval.tree.IIR_Type) = (yyvsp[(1) - (1)].tree.IIR_AccessType); }
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1664 "bison-parser.yy"
    { (yyval.tree.IIR_Type) = (yyvsp[(1) - (1)].tree.IIR_Type); }
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1669 "bison-parser.yy"
    {
	  (yyval.tree.IIR_Type) = build_EnumerationType ((yylsp[(1) - (3)]), (yyvsp[(2) - (3)].tree.IIR_EnumerationLiteralList));
	}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1676 "bison-parser.yy"
    {
	  pIIR_EnumerationLiteral el = pIIR_EnumerationLiteral (
		add_decl (mIIR_EnumerationLiteral((yylsp[(1) - (2)]), (yyvsp[(1) - (2)].tree.IIR_TextLiteral), NULL, 0)));
	  (yyval.tree.IIR_EnumerationLiteralList) = mIIR_EnumerationLiteralList ((yylsp[(1) - (2)]), el, (yyvsp[(2) - (2)].tree.IIR_EnumerationLiteralList));
	}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1684 "bison-parser.yy"
    { (yyval.tree.IIR_EnumerationLiteralList) = NULL; }
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1685 "bison-parser.yy"
    { (yyval.tree.IIR_EnumerationLiteralList) = (yyvsp[(2) - (2)].tree.IIR_EnumerationLiteralList); }
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1693 "bison-parser.yy"
    {
	  pIIR_PhysicalType base = mIIR_PhysicalType ((yylsp[(2) - (6)]), (yyvsp[(3) - (6)].tree.IIR_PhysicalUnit), NULL);
	  if ((yyvsp[(3) - (6)].tree.IIR_PhysicalUnit)) 
	    {
	      int unit_pos_counter = 0;
	      pIIR_UnitList ul = mIIR_UnitList ((yylsp[(3) - (6)]), (yyvsp[(3) - (6)].tree.IIR_PhysicalUnit), reverse ((yyvsp[(4) - (6)].tree.IIR_UnitList)));
	      base->units = ul;
	      while (ul)
		{
		  pIIR_PhysicalUnit pu = ul->first;
		  if (pu->unit_name &&
		      pu->unit_name->type != base)
		      error("%:value of unit %n must be from its"
			    " physical type", pu, pu);
		  pu->type = base;
		  pu->unit_pos = unit_pos_counter++;
		  ul = ul->rest;
		}
	    }
	  (yyval.tree.IIR_Type) = build_SubType_def((yylsp[(1) - (6)]), (yyvsp[(1) - (6)].tree.IIR_Range), base);
	}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1717 "bison-parser.yy"
    { (yyval.tree.IIR_UnitList) = NULL; }
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1719 "bison-parser.yy"
    {
	  (yyval.tree.IIR_UnitList) = mIIR_UnitList ((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].tree.IIR_PhysicalUnit), (yyvsp[(1) - (2)].tree.IIR_UnitList));
	}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1726 "bison-parser.yy"
    {
	  (yyval.tree.IIR_PhysicalUnit) = pIIR_PhysicalUnit(
		    add_decl(mIIR_PhysicalUnit ((yylsp[(1) - (2)]), (yyvsp[(1) - (2)].tree.IIR_Identifier), NULL, NULL, NULL, 0)));
	}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1734 "bison-parser.yy"
    {
	  if ((yyvsp[(3) - (4)].tree.IIR_PhysicalLiteral) && !(yyvsp[(3) - (4)].tree.IIR_PhysicalLiteral)->value->is (IR_INTEGER_LITERAL))
	    error ("secondary units must be integer multiples");
	  pIIR_AbstractLiteralExpression mult =
	    build_LiteralExpression ((yylsp[(3) - (4)]), (yyvsp[(3) - (4)].tree.IIR_PhysicalLiteral)->value);
	  mult->static_level = IR_LOCALLY_STATIC;
	  (yyval.tree.IIR_PhysicalUnit) = pIIR_PhysicalUnit(
		    add_decl(mIIR_PhysicalUnit((yylsp[(1) - (4)]), (yyvsp[(1) - (4)].tree.IIR_Identifier), mult, (yyvsp[(3) - (4)].tree.IIR_PhysicalLiteral)->unit, NULL, 0)));
	}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1747 "bison-parser.yy"
    {
	    (yyval.tree.IIR_Type) = mIIR_ArrayType((yylsp[(1) - (6)]), (yyvsp[(3) - (6)].tree.IIR_TypeList), (yyvsp[(6) - (6)].tree.IIR_Type));
	}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 1754 "bison-parser.yy"
    {
	  (yyval.tree.IIR_TypeList) = mIIR_TypeList ((yylsp[(1) - (2)]), (yyvsp[(1) - (2)].tree.IIR_Type), (yyvsp[(2) - (2)].tree.IIR_TypeList));
	}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1761 "bison-parser.yy"
    {
	    (yyval.tree.IIR_TypeList) = NULL;
	}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1765 "bison-parser.yy"
    {
	  (yyval.tree.IIR_TypeList) = mIIR_TypeList ((yylsp[(2) - (3)]), (yyvsp[(2) - (3)].tree.IIR_Type), (yyvsp[(3) - (3)].tree.IIR_TypeList));
	}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1772 "bison-parser.yy"
    {
	  (yyval.tree.IIR_Type) = get_type((yyvsp[(1) - (3)].tree.VAUL_Name));
	}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1779 "bison-parser.yy"
    {
	    (yyval.tree.IIR_Type) = build_constrained_array_type((yyvsp[(2) - (4)].tree.IIR_TypeList), (yyvsp[(4) - (4)].tree.IIR_Type));
	}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1786 "bison-parser.yy"
    {
	  (yyval.tree.IIR_Identifier) = NULL;
	}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1790 "bison-parser.yy"
    { 
	  (yyval.tree.IIR_Identifier) = (yyvsp[(1) - (1)].tree.IIR_Identifier);
        }
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1794 "bison-parser.yy"
    {
	  (yyval.tree.IIR_Identifier) = (yyvsp[(2) - (2)].tree.IIR_Identifier);
	}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1801 "bison-parser.yy"
    {
	  pIIR_ElementDeclarationList dl = concat ((yyvsp[(2) - (5)].tree.IIR_ElementDeclarationList), (yyvsp[(3) - (5)].tree.IIR_ElementDeclarationList));
	  int record_pos_counter = 0;
	  for (pIIR_ElementDeclarationList el = dl; el; el = el->rest)
	    el->first->declaration_pos = record_pos_counter++;

	  if ((yyvsp[(5) - (5)].tree.IIR_Identifier) != NULL
	      && !decls_in_flight(cur_scope).is_last ((yyvsp[(5) - (5)].tree.IIR_Identifier)))
	    {
	      error ("%n does not match current record type name", (yyvsp[(5) - (5)].tree.IIR_Identifier));
	    }

	  (yyval.tree.IIR_RecordType) = mIIR_RecordType((yylsp[(1) - (5)]), dl);
	}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1819 "bison-parser.yy"
    {
	    (yyval.tree.IIR_ElementDeclarationList) = NULL;
	}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1823 "bison-parser.yy"
    {
	    pIIR_ElementDeclarationList dl = concat((yyvsp[(1) - (2)].tree.IIR_ElementDeclarationList), (yyvsp[(2) - (2)].tree.IIR_ElementDeclarationList));
	    (yyval.tree.IIR_ElementDeclarationList) = dl;
	    /* edwin, vorher: $$ = concat ($1, $2); */
	}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1832 "bison-parser.yy"
    {
	    (yyval.tree.IIR_ElementDeclarationList) = NULL;
	    for(pIIR_IdentifierList idl = reverse((yyvsp[(1) - (4)].tree.IIR_IdentifierList)); idl; idl = idl->rest)
	      {
		pIIR_ElementDeclaration re =
		  mIIR_ElementDeclaration (idl->pos, idl->first, (yyvsp[(3) - (4)].tree.IIR_Type), -1);
		(yyval.tree.IIR_ElementDeclarationList) = mIIR_ElementDeclarationList (re->pos, re, (yyval.tree.IIR_ElementDeclarationList));
	      }
	    (yyval.tree.IIR_ElementDeclarationList) = reverse((yyval.tree.IIR_ElementDeclarationList));
	}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1846 "bison-parser.yy"
    {
	    if ((yyvsp[(2) - (2)].tree.IIR_Type) && (yyvsp[(2) - (2)].tree.IIR_Type)->is(IR_FILE_TYPE)) 
	      {
		error("%:can't access files", (yyvsp[(2) - (2)].tree.IIR_Type));
		(yyvsp[(2) - (2)].tree.IIR_Type) = NULL;
	      }
	    (yyval.tree.IIR_AccessType) = mIIR_AccessType((yylsp[(1) - (2)]), (yyvsp[(2) - (2)].tree.IIR_Type));
	    if ((yyvsp[(2) - (2)].tree.IIR_Type)->is(VAUL_INCOMPLETE_TYPE))
	      vaul_add_incomplete_type_use (pVAUL_IncompleteType ((yyvsp[(2) - (2)].tree.IIR_Type)),
					    (yyval.tree.IIR_AccessType)->designated_type);
	}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 1861 "bison-parser.yy"
    {
	  (yyval.tree.IIR_Type) = build_FileType ((yyvsp[(3) - (3)].tree.VAUL_Name));
	}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 1872 "bison-parser.yy"
    {
	    if ((yyvsp[(4) - (5)].tree.IIR_Type) && (yyvsp[(4) - (5)].tree.IIR_Type)->declaration)
	      {
		if ((yyvsp[(4) - (5)].tree.IIR_Type)->is(IR_SCALAR_SUBTYPE) ||
		    (yyvsp[(4) - (5)].tree.IIR_Type)->is(IR_SCALAR_TYPE))
		  {
		    add_type_decl (cur_scope,
				   mIIR_ScalarSubtype ((yylsp[(2) - (5)]), (yyvsp[(4) - (5)].tree.IIR_Type)->base,
				                       (yyvsp[(4) - (5)].tree.IIR_Type), NULL, NULL),
				   (yyvsp[(2) - (5)].tree.IIR_Identifier));
		  }
		else if ((yyvsp[(4) - (5)].tree.IIR_Type)->is(IR_ARRAY_SUBTYPE) ||
	                 (yyvsp[(4) - (5)].tree.IIR_Type)->is(IR_ARRAY_TYPE))
		  {
		    add_type_decl (cur_scope,
				   mIIR_ArraySubtype((yylsp[(2) - (5)]), (yyvsp[(4) - (5)].tree.IIR_Type)->base,
				                     (yyvsp[(4) - (5)].tree.IIR_Type), NULL, NULL),
				   (yyvsp[(2) - (5)].tree.IIR_Identifier));
		  }
		else if ((yyvsp[(4) - (5)].tree.IIR_Type)->is(IR_RECORD_SUBTYPE) ||
	                 (yyvsp[(4) - (5)].tree.IIR_Type)->is(IR_RECORD_TYPE))
		  {
		    add_type_decl (cur_scope,
				   mIIR_RecordSubtype((yylsp[(2) - (5)]), (yyvsp[(4) - (5)].tree.IIR_Type)->base,
						      (yyvsp[(4) - (5)].tree.IIR_Type), NULL),
				   (yyvsp[(2) - (5)].tree.IIR_Identifier));
		  }
		else
		  {
		    info ("xxx - plain subtype of %s", (yyvsp[(4) - (5)].tree.IIR_Type)->kind_name ());
		    add_type_decl (cur_scope,
				   mIIR_Subtype ((yylsp[(2) - (5)]), (yyvsp[(4) - (5)].tree.IIR_Type)->base, (yyvsp[(4) - (5)].tree.IIR_Type), NULL),
				   (yyvsp[(2) - (5)].tree.IIR_Identifier));
		  }
	      }
	    else
	      add_type_decl (cur_scope, (yyvsp[(4) - (5)].tree.IIR_Type), (yyvsp[(2) - (5)].tree.IIR_Identifier));
	}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1914 "bison-parser.yy"
    {
	  if ((yyvsp[(1) - (1)].tree.IIR_Type)->is(VAUL_INCOMPLETE_TYPE))
	    {
	      error ("type %n is incomplete", (yyvsp[(1) - (1)].tree.IIR_Type));
	      (yyval.tree.IIR_Type) = NULL;
	    }
	  else
	    (yyval.tree.IIR_Type) = (yyvsp[(1) - (1)].tree.IIR_Type);
	}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 1928 "bison-parser.yy"
    {
	  if ((yyvsp[(2) - (2)].tree.IIR_TypeList) == NULL)
	    {
	      // allow incomplete types here
	      pIIR_TypeDeclaration d = 
		pIIR_TypeDeclaration (find_single_decl ((yyvsp[(1) - (2)].tree.VAUL_Name),
							IR_TYPE_DECLARATION,
							"type"));
	      (yyval.tree.IIR_Type) = (d? d->type : NULL);
	    }
	  else
	    (yyval.tree.IIR_Type) = build_ArraySubtype(NULL, (yyvsp[(1) - (2)].tree.VAUL_Name), (yyvsp[(2) - (2)].tree.IIR_TypeList)); 
	}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 1946 "bison-parser.yy"
    {
	  (yyval.tree.IIR_Type) = build_ScalarSubtype((yyvsp[(1) - (3)].tree.VAUL_Name), (yyvsp[(2) - (3)].tree.VAUL_Name), (yyvsp[(3) - (3)].tree.IIR_Range)); 
	}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 1950 "bison-parser.yy"
    {
	  (yyval.tree.IIR_Type) = build_ScalarSubtype(NULL, (yyvsp[(1) - (2)].tree.VAUL_Name), (yyvsp[(2) - (2)].tree.IIR_Range)); 
	}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1954 "bison-parser.yy"
    {
	  (yyval.tree.IIR_Type) = build_Subtype ((yyvsp[(1) - (3)].tree.VAUL_Name), (yyvsp[(2) - (3)].tree.VAUL_Name), (yyvsp[(3) - (3)].tree.IIR_TypeList));
	}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 1960 "bison-parser.yy"
    { (yyval.tree.IIR_TypeList) = NULL; }
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 1961 "bison-parser.yy"
    { (yyval.tree.IIR_TypeList) = build_PreIndexConstraint((yyvsp[(1) - (1)].tree.VAUL_GenAssocElem)); }
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 1965 "bison-parser.yy"
    { (yyval.tree.IIR_Range) = (yyvsp[(2) - (2)].tree.IIR_Range); }
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 1970 "bison-parser.yy"
    {
	    if((yyvsp[(2) - (4)].tree.VAUL_GenAssocElem)) {
		(yyvsp[(2) - (4)].tree.VAUL_GenAssocElem)->next = reverse((yyvsp[(3) - (4)].tree.VAUL_GenAssocElem));
		(yyval.tree.IIR_TypeList) = build_PreIndexConstraint((yyvsp[(2) - (4)].tree.VAUL_GenAssocElem));
	    } else
		(yyval.tree.IIR_TypeList) = build_PreIndexConstraint((yyvsp[(3) - (4)].tree.VAUL_GenAssocElem));
	}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 1981 "bison-parser.yy"
    {
	    (yyval.tree.VAUL_GenAssocElem) = NULL;
	}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 1985 "bison-parser.yy"
    {
	    if((yyvsp[(3) - (3)].tree.VAUL_GenAssocElem)) {
		(yyvsp[(3) - (3)].tree.VAUL_GenAssocElem)->next = (yyvsp[(1) - (3)].tree.VAUL_GenAssocElem);
		(yyval.tree.VAUL_GenAssocElem) = (yyvsp[(3) - (3)].tree.VAUL_GenAssocElem);
	    } else
		(yyval.tree.VAUL_GenAssocElem) = (yyvsp[(1) - (3)].tree.VAUL_GenAssocElem);
	}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 1996 "bison-parser.yy"
    {
	    if(is_discrete_type((yyvsp[(1) - (1)].tree.IIR_Type)))
		(yyval.tree.VAUL_GenAssocElem) = mVAUL_SubtypeAssocElem((yylsp[(1) - (1)]), NULL, (yyvsp[(1) - (1)].tree.IIR_Type));
	    else {
		if((yyvsp[(1) - (1)].tree.IIR_Type))
		    error("%!%n is not a discrete type", lex, int((yylsp[(1) - (1)])), (yyvsp[(1) - (1)].tree.IIR_Type));
		(yyval.tree.VAUL_GenAssocElem) = NULL;
	    }
	}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 2006 "bison-parser.yy"
    {
	    (yyval.tree.VAUL_GenAssocElem) = mVAUL_RangeAssocElem((yylsp[(1) - (1)]), NULL, (yyvsp[(1) - (1)].tree.IIR_Range));
	}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 2013 "bison-parser.yy"
    {
	  if (is_discrete_type((yyvsp[(1) - (1)].tree.IIR_Type)))
	    (yyval.tree.VAUL_GenAssocElem) = mVAUL_SubtypeAssocElem ((yylsp[(1) - (1)]), NULL, (yyvsp[(1) - (1)].tree.IIR_Type));
	  else 
	    {
	      if ((yyvsp[(1) - (1)].tree.IIR_Type))
		error ("%!%n is not a discrete type", lex, int((yylsp[(1) - (1)])), (yyvsp[(1) - (1)].tree.IIR_Type));
	      (yyval.tree.VAUL_GenAssocElem) = NULL;
	    }
	}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 2024 "bison-parser.yy"
    {
	    (yyval.tree.VAUL_GenAssocElem) = mVAUL_RangeAssocElem((yylsp[(1) - (3)]), NULL,
                       mIIR_ExplicitRange((yylsp[(2) - (3)]), validate_Expr((yyvsp[(1) - (3)].tree.IIR_Root)), (yyvsp[(3) - (3)].tree.IIR_Expression), (yyvsp[(2) - (3)].dir)));
	}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 2033 "bison-parser.yy"
    {
	    (yyval.tree.IIR_ExplicitRange) = NULL;
	}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 2037 "bison-parser.yy"
    {
	  (yyval.tree.IIR_ExplicitRange) = mIIR_ExplicitRange ((yylsp[(1) - (2)]), NULL, (yyvsp[(2) - (2)].tree.IIR_Expression), (yyvsp[(1) - (2)].dir));
	}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 2053 "bison-parser.yy"
    {
	    pIIR n = build_Expr_or_Attr ((yyvsp[(1) - (1)].tree.VAUL_AttributeName));
	    if (n && n->is(IR_ARRAY_RANGE))
	      (yyval.tree.IIR_Range) = pIIR_ArrayRange (n);
	    else {
	      if (n)
 	        error ("%n not valid as range specification", n);
	      (yyval.tree.IIR_Range) = NULL;
	    }
	}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 2064 "bison-parser.yy"
    {
	  (yyval.tree.IIR_Range) = mIIR_ExplicitRange((yylsp[(2) - (3)]), (yyvsp[(1) - (3)].tree.IIR_Expression), (yyvsp[(3) - (3)].tree.IIR_Expression), (yyvsp[(2) - (3)].dir));
	}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 2071 "bison-parser.yy"
    {
	  if ((yyvsp[(2) - (2)].tree.IIR_ExplicitRange))
	    {
	      (yyvsp[(2) - (2)].tree.IIR_ExplicitRange)->left = validate_Expr ((yyvsp[(1) - (2)].tree.IIR_Root));
	      (yyval.tree.IIR_Range) = (yyvsp[(2) - (2)].tree.IIR_ExplicitRange);
	    }
	  else
	    {
	      if (!(yyvsp[(1) - (2)].tree.IIR_Root)->is(IR_RANGE))
		{
		  error ("invalid range specification %n", (yyvsp[(1) - (2)].tree.IIR_Root));
		  (yyval.tree.IIR_Range) = NULL;
		}
	      else
		(yyval.tree.IIR_Range) = pIIR_Range((yyvsp[(1) - (2)].tree.IIR_Root));
	    }
	}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 2091 "bison-parser.yy"
    { (yyval.dir) = IR_DIRECTION_UP; }
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 2092 "bison-parser.yy"
    { (yyval.dir) = IR_DIRECTION_DOWN; }
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 2101 "bison-parser.yy"
    {
	  if ((yyvsp[(5) - (6)].tree.IIR_Expression) == NULL && !cur_scope->is(IR_PACKAGE_DECLARATION))
	    error ("constants must be initialized");
	  pIIR_Type t = adapt_object_type (VAUL_ObjClass_Constant, (yyvsp[(4) - (6)].tree.IIR_Type), (yyvsp[(5) - (6)].tree.IIR_Expression));
	  overload_resolution ((yyvsp[(5) - (6)].tree.IIR_Expression), t);
	  for (pIIR_IdentifierList idl = (yyvsp[(2) - (6)].tree.IIR_IdentifierList); idl; idl = idl->rest)
	    add_decl (mIIR_ConstantDeclaration ((yylsp[(2) - (6)]), idl->first, t, (yyvsp[(5) - (6)].tree.IIR_Expression)));
	}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 2115 "bison-parser.yy"
    {
	  pIIR_Type t = adapt_object_type (VAUL_ObjClass_Signal, (yyvsp[(4) - (7)].tree.IIR_Type), (yyvsp[(6) - (7)].tree.IIR_Expression));
	  overload_resolution ((yyvsp[(6) - (7)].tree.IIR_Expression), t);
	  for (pIIR_IdentifierList idl = (yyvsp[(2) - (7)].tree.IIR_IdentifierList); idl; idl = idl->rest)
	    add_decl (mIIR_SignalDeclaration ((yylsp[(2) - (7)]), idl->first, t, (yyvsp[(6) - (7)].tree.IIR_Expression), (yyvsp[(5) - (7)].signal_kind)));
	}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 2124 "bison-parser.yy"
    { (yyval.signal_kind) = IR_NO_SIGNAL_KIND; }
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 2130 "bison-parser.yy"
    {
	  pIIR_Type t = adapt_object_type (VAUL_ObjClass_Variable, (yyvsp[(4) - (6)].tree.IIR_Type), (yyvsp[(5) - (6)].tree.IIR_Expression));
	  overload_resolution ((yyvsp[(5) - (6)].tree.IIR_Expression), t);
	  for (pIIR_IdentifierList idl = (yyvsp[(2) - (6)].tree.IIR_IdentifierList); idl; idl = idl->rest)
	    add_decl (mIIR_VariableDeclaration ((yylsp[(2) - (6)]), idl->first, t, (yyvsp[(5) - (6)].tree.IIR_Expression)));
	}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 2139 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = NULL; }
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 2140 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = (yyvsp[(2) - (2)].tree.IIR_Expression); }
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 2144 "bison-parser.yy"
    { (yyval.obj_class) = VAUL_ObjClass_Constant; }
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 2145 "bison-parser.yy"
    { (yyval.obj_class) = VAUL_ObjClass_Signal; }
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 2146 "bison-parser.yy"
    { (yyval.obj_class) = VAUL_ObjClass_Variable; }
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 2147 "bison-parser.yy"
    { (yyval.obj_class) = VAUL_ObjClass_File; }
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 2151 "bison-parser.yy"
    { (yyval.signal_kind) = IR_BUS_KIND; }
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 2152 "bison-parser.yy"
    { (yyval.signal_kind) = IR_REGISTER_KIND; }
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 2157 "bison-parser.yy"
    {
	    add_Alias ((yyvsp[(2) - (7)].tree.IIR_Identifier), (yyvsp[(4) - (7)].tree.IIR_Type), (yyvsp[(6) - (7)].tree.VAUL_Name));
	}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 2165 "bison-parser.yy"
    {
	    add_File ((yyvsp[(2) - (7)].tree.IIR_Identifier), (yyvsp[(4) - (7)].tree.IIR_Type), (yyvsp[(5) - (7)].tree.IIR_Expression), (yyvsp[(6) - (7)].tree.VAUL_FilenameAndMode));
	}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 2172 "bison-parser.yy"
    {
	    (yyval.tree.IIR_Expression) = NULL; 
	}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 2176 "bison-parser.yy"
    {
	    pIIR_Expression e = (yyvsp[(2) - (2)].tree.IIR_Expression);
	    overload_resolution(e, std->predef_FILE_OPEN_KIND);
	    (yyval.tree.IIR_Expression) = e;
	}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 2185 "bison-parser.yy"
    {
	    (yyval.tree.VAUL_FilenameAndMode) = NULL;
	}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 2189 "bison-parser.yy"
    {
	    pIIR_Expression e = (yyvsp[(3) - (3)].tree.IIR_Expression);
	    overload_resolution(e, std->predef_STRING);
	    (yyval.tree.VAUL_FilenameAndMode) = mVAUL_FilenameAndMode (e, (yyvsp[(2) - (3)].mode));
	}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 2198 "bison-parser.yy"
    {
	  (yyval.mode) = IR_UNKNOWN_MODE;
	}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 2202 "bison-parser.yy"
    {
	  (yyval.mode) = IR_IN_MODE;
	}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 2206 "bison-parser.yy"
    {
	  (yyval.mode) = IR_OUT_MODE;
	}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 2213 "bison-parser.yy"
    {
	  add_disconnect_spec ((yyvsp[(2) - (7)].tree.IIR_ExpressionList), (yyvsp[(4) - (7)].tree.VAUL_Name), (yyvsp[(6) - (7)].tree.IIR_Expression));
	}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 2220 "bison-parser.yy"
    {
	    (yyvsp[(1) - (2)].tree.IIR_ExpressionList)->rest = (yyvsp[(2) - (2)].tree.IIR_ExpressionList);
	    (yyval.tree.IIR_ExpressionList) = (yyvsp[(1) - (2)].tree.IIR_ExpressionList);
	}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 2225 "bison-parser.yy"
    { 
	    info ("XXX - no OTHERS signals");
	    (yyval.tree.IIR_ExpressionList) = NULL;
	}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 2230 "bison-parser.yy"
    {
	    info ("XXX - no ALL signals");
	    (yyval.tree.IIR_ExpressionList) = NULL;
	}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 2237 "bison-parser.yy"
    { (yyval.tree.IIR_ExpressionList) = NULL; }
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 2239 "bison-parser.yy"
    {
	  if ((yyvsp[(1) - (3)].tree.IIR_ExpressionList))
	    {
	      pIIR_ExpressionList sl = (yyvsp[(1) - (3)].tree.IIR_ExpressionList);
	      while (sl->rest)
		sl = sl->rest;
	      sl->rest = (yyvsp[(3) - (3)].tree.IIR_ExpressionList);
	      (yyval.tree.IIR_ExpressionList) = (yyvsp[(1) - (3)].tree.IIR_ExpressionList);
	    }
	  else
	    (yyval.tree.IIR_ExpressionList) = (yyvsp[(3) - (3)].tree.IIR_ExpressionList);
	}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 2259 "bison-parser.yy"
    {
	    pIIR_Type t = get_type((yyvsp[(4) - (5)].tree.VAUL_Name));
	    if(t) {
		pIIR_Type bt = vaul_get_base (t);
		if(bt && bt->is(IR_ACCESS_TYPE))
		    error("%!attributes can't have access types",
			     lex, int((yylsp[(1) - (5)])));
		else if(bt && bt->is(IR_FILE_TYPE))
		    error("%!attributes can't have file types",
			     lex, int((yylsp[(1) - (5)])));
		else
		    add_decl (mIIR_AttributeDeclaration((yylsp[(1) - (5)]), (yyvsp[(2) - (5)].tree.IIR_Identifier), t));
	    }
	}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 2277 "bison-parser.yy"
    {
	    bind_attrspec (mVAUL_AttributeSpec((yylsp[(1) - (7)]), (yyvsp[(2) - (7)].tree.IIR_Identifier), (yyvsp[(4) - (7)].tree.VAUL_EntitySpec), (yyvsp[(6) - (7)].tree.IIR_Expression)));
	}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 2284 "bison-parser.yy"
    {
	    (yyval.tree.VAUL_EntitySpec) = mVAUL_EntitySpec((yylsp[(1) - (3)]), (yyvsp[(1) - (3)].tree.VAUL_EntityNameList), (yyvsp[(3) - (3)].kind));
	}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 2291 "bison-parser.yy"
    {
	  (yyval.tree.VAUL_EntityNameList) = mVAUL_EntityNameList_Ids ((yylsp[(1) - (2)]), mVAUL_DesigList ((yylsp[(1) - (2)]), (yyvsp[(1) - (2)].tree.IIR_TextLiteral),
	                                                      reverse((yyvsp[(2) - (2)].tree.VAUL_DesigList))));
	}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 2296 "bison-parser.yy"
    {
	  (yyval.tree.VAUL_EntityNameList) = mVAUL_EntityNameList_OTHERS ((yylsp[(1) - (1)]));
	}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 2300 "bison-parser.yy"
    {
	  (yyval.tree.VAUL_EntityNameList) = mVAUL_EntityNameList_ALL ((yylsp[(1) - (1)]));
	}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 2306 "bison-parser.yy"
    { (yyval.tree.VAUL_DesigList) = NULL; }
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 2308 "bison-parser.yy"
    {
	  (yyval.tree.VAUL_DesigList) = mVAUL_DesigList ((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].tree.IIR_TextLiteral), (yyvsp[(1) - (3)].tree.VAUL_DesigList));
	}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 2314 "bison-parser.yy"
    { (yyval.kind) = IR_ENTITY_DECLARATION; }
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 2315 "bison-parser.yy"
    { (yyval.kind) = IR_ARCHITECTURE_DECLARATION; }
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 2316 "bison-parser.yy"
    { (yyval.kind) = IR_PACKAGE_DECLARATION; }
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 2317 "bison-parser.yy"
    { (yyval.kind) = IR_CONFIGURATION_DECLARATION; }
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 2318 "bison-parser.yy"
    { (yyval.kind) = IR_COMPONENT_DECLARATION; }
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 2319 "bison-parser.yy"
    { (yyval.kind) = IR_LABEL; }
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 2320 "bison-parser.yy"
    { (yyval.kind) = IR_TYPE; }
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 2321 "bison-parser.yy"
    { (yyval.kind) = IR_SUBTYPE; }
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 2322 "bison-parser.yy"
    { (yyval.kind) = IR_PROCEDURE_DECLARATION; }
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 2323 "bison-parser.yy"
    { (yyval.kind) = IR_FUNCTION_DECLARATION; }
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 2324 "bison-parser.yy"
    { (yyval.kind) = IR_SIGNAL_DECLARATION; }
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 2325 "bison-parser.yy"
    { (yyval.kind) = IR_VARIABLE_DECLARATION; }
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 2326 "bison-parser.yy"
    { (yyval.kind) = IR_CONSTANT_DECLARATION; }
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 2334 "bison-parser.yy"
    { (yyval.tree.VAUL_IterationScheme) = (yyvsp[(1) - (1)].tree.VAUL_IterationScheme); }
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 2335 "bison-parser.yy"
    { (yyval.tree.VAUL_IterationScheme) = (yyvsp[(1) - (1)].tree.VAUL_IterationScheme); }
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 2339 "bison-parser.yy"
    { (yyval.tree.VAUL_IterationScheme) = (yyvsp[(1) - (1)].tree.VAUL_IterationScheme); }
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 2340 "bison-parser.yy"
    { (yyval.tree.VAUL_IterationScheme) = (yyvsp[(1) - (1)].tree.VAUL_IterationScheme); }
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 2344 "bison-parser.yy"
    { (yyval.tree.VAUL_IterationScheme) = mVAUL_IfScheme ((yylsp[(1) - (2)]), (yyvsp[(2) - (2)].tree.IIR_Expression)); }
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 2349 "bison-parser.yy"
    {
	  pIIR_TypeList r = build_PreIndexConstraint((yyvsp[(4) - (4)].tree.VAUL_GenAssocElem));
	  (yyval.tree.VAUL_IterationScheme) = mVAUL_ForScheme((yylsp[(1) - (4)]), (yyvsp[(2) - (4)].tree.IIR_Identifier), r? r->first:NULL);
	}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 2356 "bison-parser.yy"
    { (yyval.tree.VAUL_IterationScheme) = mVAUL_WhileScheme((yylsp[(1) - (2)]), (yyvsp[(2) - (2)].tree.IIR_Expression)); }
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 2373 "bison-parser.yy"
    {
          closing_label = NULL;
          starting_label = NULL;
        }
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 2387 "bison-parser.yy"
    {
	  if ((yyvsp[(1) - (1)].tree.IIR_ConcurrentStatement))
	    {
	      if (closing_label
		  && !vaul_name_eq (closing_label, (yyvsp[(1) - (1)].tree.IIR_ConcurrentStatement)->declarator))
		{
		  if ((yyvsp[(1) - (1)].tree.IIR_ConcurrentStatement)->declarator)
		    error ("%n does not match label %n",
			   closing_label, (yyvsp[(1) - (1)].tree.IIR_ConcurrentStatement)->declarator);
		  else if ((yyvsp[(1) - (1)].tree.IIR_ConcurrentStatement)->is (IR_PROCESS_STATEMENT))
		    error ("process has no label");
		  else
		    error ("concurrent statement has no label");
		}
	      add_to_concurrent_stats_tail ((yyvsp[(1) - (1)].tree.IIR_ConcurrentStatement));
	    }
	  collect ();
	}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 2409 "bison-parser.yy"
    {
	  starting_label = (yyvsp[(1) - (2)].tree.IIR_Identifier);

	  // $1 needs to survive any garbage collection that might
	  // happen during nested concurrent statements.
	  tree_protect ((yyvsp[(1) - (2)].tree.IIR_Identifier));
	}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 2417 "bison-parser.yy"
    {
	  if ((yyvsp[(4) - (4)].tree.IIR_ConcurrentStatement))
	    {
	      (yyvsp[(4) - (4)].tree.IIR_ConcurrentStatement)->declarator = (yyvsp[(1) - (4)].tree.IIR_Identifier);
	      invalidate_decl_cache ((yyvsp[(1) - (4)].tree.IIR_Identifier));
	      if (closing_label
		  && !vaul_name_eq (closing_label, (yyvsp[(4) - (4)].tree.IIR_ConcurrentStatement)->declarator))
		{
		  error ("%n does not match label %n",
			   closing_label, (yyvsp[(4) - (4)].tree.IIR_ConcurrentStatement)->declarator);
		}
	      add_to_concurrent_stats_tail ((yyvsp[(4) - (4)].tree.IIR_ConcurrentStatement));
	    }
	  tree_unprotect ((yyvsp[(1) - (4)].tree.IIR_Identifier));
	  collect ();
	}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 2454 "bison-parser.yy"
    {
	  pIIR_BlockStatement b = mIIR_BlockStatement ((yylsp[(1) - (3)]), NULL, (yyvsp[(2) - (3)].tree.IIR_Expression), NULL);
	  add_decl (cur_scope, b, starting_label);
	  push_scope (b);
	  if ((yyvsp[(2) - (3)].tree.IIR_Expression))
	    add_decl (mVAUL_GuardSignal((yylsp[(2) - (3)]), make_id("GUARD"),
	                                std->predef_BOOLEAN, (yyvsp[(2) - (3)].tree.IIR_Expression),
	                                IR_NO_SIGNAL_KIND));
	  (yyval.tree.IIR_BlockStatement) = b;
	}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2465 "bison-parser.yy"
    {
	      pIIR_BlockStatement b = (yyvsp[(4) - (5)].tree.IIR_BlockStatement);
	      b->generic_map_aspect = associate ((yyvsp[(5) - (5)].tree.VAUL_NamedAssocElem), b->generic_clause, false);
	    }
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 2470 "bison-parser.yy"
    {
	      pIIR_BlockStatement b = (yyvsp[(4) - (7)].tree.IIR_BlockStatement);
	      b->port_map_aspect = associate_ports ((yyvsp[(7) - (7)].tree.VAUL_NamedAssocElem), b->port_clause);
	    }
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 2476 "bison-parser.yy"
    {
	      pIIR_BlockStatement b = (yyvsp[(4) - (10)].tree.IIR_BlockStatement);
	      push_concurrent_stats_tail (&b->block_statement_part);
	    }
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 2482 "bison-parser.yy"
    {
	  pIIR_BlockStatement b = (yyvsp[(4) - (16)].tree.IIR_BlockStatement);
	  closing_label = (yyvsp[(15) - (16)].tree.IIR_Identifier);
	  pop_concurrent_stats_tail (&b->block_statement_part);
	  pop_scope (b);
	  (yyval.tree.IIR_ConcurrentStatement) = b;
	}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 2497 "bison-parser.yy"
    { (yyval.tree.VAUL_NamedAssocElem) = NULL; }
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 2498 "bison-parser.yy"
    { (yyval.tree.VAUL_NamedAssocElem) = (yyvsp[(2) - (2)].tree.VAUL_NamedAssocElem); }
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 2502 "bison-parser.yy"
    { (yyval.tree.VAUL_NamedAssocElem) = NULL; }
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 2503 "bison-parser.yy"
    { (yyval.tree.VAUL_NamedAssocElem) = (yyvsp[(2) - (2)].tree.VAUL_NamedAssocElem); }
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 2507 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = NULL; }
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 2508 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = (yyvsp[(2) - (3)].tree.IIR_Expression); }
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 2512 "bison-parser.yy"
    { (yyval.tree.VAUL_NamedAssocElem) = NULL; }
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 2513 "bison-parser.yy"
    { (yyval.tree.VAUL_NamedAssocElem) = (yyvsp[(1) - (2)].tree.VAUL_NamedAssocElem); }
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2517 "bison-parser.yy"
    { (yyval.tree.VAUL_NamedAssocElem) = NULL; }
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2518 "bison-parser.yy"
    { (yyval.tree.VAUL_NamedAssocElem) = (yyvsp[(1) - (2)].tree.VAUL_NamedAssocElem); }
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2539 "bison-parser.yy"
    {
	  (yyval.tree.IIR_ConcurrentStatement) = build_CompInst ((yylsp[(1) - (6)]), starting_label,
			       build_BindingIndic(make_posinfo ((yylsp[(1) - (6)])),
						  (yyvsp[(1) - (6)].tree.IIR_ComponentDeclaration), (yyvsp[(4) - (6)].tree.VAUL_NamedAssocElem), (yyvsp[(5) - (6)].tree.VAUL_NamedAssocElem)));
	  add_decl((yyval.tree.IIR_ConcurrentStatement));
	}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2550 "bison-parser.yy"
    {
	  (yyval.tree.IIR_ConcurrentStatement) = build_CompInst ((yylsp[(1) - (6)]), starting_label,
			       build_BindingIndic(make_posinfo ((yylsp[(1) - (6)])),
						  (yyvsp[(1) - (6)].tree.IIR_ComponentDeclaration), (yyvsp[(5) - (6)].tree.VAUL_NamedAssocElem), (yyvsp[(4) - (6)].tree.VAUL_NamedAssocElem)));
	  add_decl((yyval.tree.IIR_ConcurrentStatement));
	}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2560 "bison-parser.yy"
    {
	  (yyval.tree.IIR_ConcurrentStatement) = build_CompInst ((yylsp[(1) - (4)]), starting_label,
			       build_BindingIndic (make_posinfo ((yylsp[(1) - (4)])),
						   (yyvsp[(1) - (4)].tree.IIR_DeclarativeRegion), (yyvsp[(2) - (4)].tree.VAUL_NamedAssocElem), (yyvsp[(3) - (4)].tree.VAUL_NamedAssocElem)));
	  add_decl ((yyval.tree.IIR_ConcurrentStatement));
	}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 2570 "bison-parser.yy"
    {
	  (yyval.tree.IIR_DeclarativeRegion) = (yyvsp[(2) - (2)].tree.IIR_ComponentDeclaration); 
	}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 2574 "bison-parser.yy"
    {
	  (yyval.tree.IIR_DeclarativeRegion) = get_architecture_ref ((yylsp[(1) - (3)]), (yyvsp[(2) - (3)].tree.VAUL_Name), (yyvsp[(3) - (3)].tree.IIR_Identifier));
	}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 2578 "bison-parser.yy"
    {
	  (yyval.tree.IIR_DeclarativeRegion) = get_configuration ((yyvsp[(2) - (2)].tree.VAUL_Name));
	}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 2588 "bison-parser.yy"
    { (yyval.tree.VAUL_NamedAssocElem) = NULL; }
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 2593 "bison-parser.yy"
    { (yyval.tree.VAUL_NamedAssocElem) = (yyvsp[(3) - (3)].tree.VAUL_NamedAssocElem); }
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 2597 "bison-parser.yy"
    { (yyval.tree.VAUL_NamedAssocElem) = NULL; }
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2602 "bison-parser.yy"
    { (yyval.tree.VAUL_NamedAssocElem) = (yyvsp[(3) - (3)].tree.VAUL_NamedAssocElem); }
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 2607 "bison-parser.yy"
    {
	  (yyval.tree.IIR_ConcurrentStatement) = build_conc_AssertStat ((yylsp[(1) - (1)]), NULL, false, (yyvsp[(1) - (1)].tree.IIR_AssertionStatement));
	}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 2612 "bison-parser.yy"
    {
	  (yyval.tree.IIR_ConcurrentStatement) = build_conc_AssertStat((yylsp[(1) - (2)]), NULL, true, (yyvsp[(2) - (2)].tree.IIR_AssertionStatement));
	}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 2619 "bison-parser.yy"
    {
	  (yyval.tree.IIR_ConcurrentStatement) = build_conc_ProcedureCall_or_ComponentInst ((yylsp[(1) - (2)]), NULL, (yyvsp[(1) - (2)].tree.VAUL_Name));
	}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 2624 "bison-parser.yy"
    {
	  (yyval.tree.IIR_ConcurrentStatement) = build_conc_ProcedureCall ((yylsp[(1) - (1)]), NULL, false, (yyvsp[(1) - (1)].tree.IIR_ProcedureCallStatement));
	}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 2629 "bison-parser.yy"
    {
	  (yyval.tree.IIR_ConcurrentStatement) = build_conc_ProcedureCall ((yylsp[(1) - (2)]), NULL, true, (yyvsp[(2) - (2)].tree.IIR_ProcedureCallStatement));
	}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 2635 "bison-parser.yy"
    { (yyval.boolean) = false; }
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 2636 "bison-parser.yy"
    { (yyval.boolean) = true; }
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 2641 "bison-parser.yy"
    {
	  (yyval.tree.IIR_ConcurrentStatement) = build_condal_Process (NULL, false, (yyvsp[(1) - (1)].tree.VAUL_CondalSignalAssign));
	}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 2646 "bison-parser.yy"
    {
	  (yyval.tree.IIR_ConcurrentStatement) = build_condal_Process (NULL, true, (yyvsp[(2) - (2)].tree.VAUL_CondalSignalAssign));
	}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 2651 "bison-parser.yy"
    {
	  (yyval.tree.IIR_ConcurrentStatement) = build_sel_Process (NULL, false, (yyvsp[(1) - (1)].tree.VAUL_SelSignalAssign));
	}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 2656 "bison-parser.yy"
    {
	  (yyval.tree.IIR_ConcurrentStatement) = build_sel_Process (NULL, true, (yyvsp[(2) - (2)].tree.VAUL_SelSignalAssign));
	}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2663 "bison-parser.yy"
    {
	  (yyval.tree.VAUL_CondalSignalAssign) = mVAUL_CondalSignalAssign ((yylsp[(2) - (6)]), (yyvsp[(1) - (6)].tree.IIR_Expression), (yyvsp[(3) - (6)].boolean), (yyvsp[(4) - (6)].tree.VAUL_DelayMechanism), (yyvsp[(5) - (6)].tree.VAUL_CondalWaveform));
	}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2670 "bison-parser.yy"
    {
	  pVAUL_CondalWaveform w = mVAUL_CondalWaveform ((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].tree.IIR_WaveformList), NULL);
	  if (((yyval.tree.VAUL_CondalWaveform) = (yyvsp[(1) - (2)].tree.VAUL_CondalWaveform)) != NULL)
	    {
	      while ((yyvsp[(1) - (2)].tree.VAUL_CondalWaveform)->else_wave)
		(yyvsp[(1) - (2)].tree.VAUL_CondalWaveform) = (yyvsp[(1) - (2)].tree.VAUL_CondalWaveform)->else_wave;
	      (yyvsp[(1) - (2)].tree.VAUL_CondalWaveform)->else_wave = w;
    	    } 
	  else
	    (yyval.tree.VAUL_CondalWaveform) = w;
    	}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2684 "bison-parser.yy"
    { (yyval.tree.VAUL_CondalWaveform) = NULL; }
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2686 "bison-parser.yy"
    {
	  pVAUL_CondalWaveform w = mVAUL_CondalWaveform ((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].tree.IIR_WaveformList), (yyvsp[(4) - (5)].tree.IIR_Expression));
	  if (((yyval.tree.VAUL_CondalWaveform) = (yyvsp[(1) - (5)].tree.VAUL_CondalWaveform)) != NULL)
	    {
	      while ((yyvsp[(1) - (5)].tree.VAUL_CondalWaveform)->else_wave)
		(yyvsp[(1) - (5)].tree.VAUL_CondalWaveform) = (yyvsp[(1) - (5)].tree.VAUL_CondalWaveform)->else_wave;
	      (yyvsp[(1) - (5)].tree.VAUL_CondalWaveform)->else_wave = w;
    	    } 
	  else
	    (yyval.tree.VAUL_CondalWaveform) = w;
    	}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2701 "bison-parser.yy"
    {
	  (yyvsp[(2) - (2)].tree.IIR_WaveformList) = reverse ((yyvsp[(2) - (2)].tree.IIR_WaveformList));
	  if ((yyvsp[(1) - (2)].tree.IIR_WaveformList)) 
	    {
	      (yyvsp[(1) - (2)].tree.IIR_WaveformList)->rest = (yyvsp[(2) - (2)].tree.IIR_WaveformList);
	      (yyval.tree.IIR_WaveformList) = (yyvsp[(1) - (2)].tree.IIR_WaveformList);
	    }
	  else
	    (yyval.tree.IIR_WaveformList) = (yyvsp[(2) - (2)].tree.IIR_WaveformList);
	}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2714 "bison-parser.yy"
    { (yyval.tree.IIR_WaveformList) = NULL; }
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2716 "bison-parser.yy"
    {
	  if ((yyvsp[(3) - (3)].tree.IIR_WaveformList)) 
	    {
	      (yyvsp[(3) - (3)].tree.IIR_WaveformList)->rest = (yyvsp[(1) - (3)].tree.IIR_WaveformList);
	      (yyval.tree.IIR_WaveformList) = (yyvsp[(3) - (3)].tree.IIR_WaveformList);
	    }
	  else
	    (yyval.tree.IIR_WaveformList) = (yyvsp[(1) - (3)].tree.IIR_WaveformList);
	}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2729 "bison-parser.yy"
    {
	  (yyval.tree.IIR_WaveformList) = mIIR_WaveformList ((yylsp[(1) - (2)]), mIIR_WaveformElement ((yylsp[(1) - (2)]), (yyvsp[(1) - (2)].tree.IIR_Expression), (yyvsp[(2) - (2)].tree.IIR_Expression)), NULL);
	}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2735 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = NULL; }
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2736 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = (yyvsp[(2) - (2)].tree.IIR_Expression); overload_resolution((yyval.tree.IIR_Expression), std->predef_TIME); }
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2740 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = build_Expr((yyvsp[(1) - (1)].tree.VAUL_Name)); }
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2741 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = (yyvsp[(1) - (1)].tree.VAUL_AmbgAggregate); }
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2745 "bison-parser.yy"
    { (yyval.boolean) = false; }
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2746 "bison-parser.yy"
    { (yyval.boolean) = true; }
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2752 "bison-parser.yy"
    {
	  (yyval.tree.VAUL_SelSignalAssign) = mVAUL_SelSignalAssign ((yylsp[(1) - (9)]), (yyvsp[(2) - (9)].tree.IIR_Expression), (yyvsp[(4) - (9)].tree.IIR_Expression), (yyvsp[(6) - (9)].boolean), (yyvsp[(7) - (9)].tree.VAUL_DelayMechanism), (yyvsp[(8) - (9)].tree.VAUL_SelWaveform));
	}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2759 "bison-parser.yy"
    {
	  (yyval.tree.VAUL_SelWaveform) = mVAUL_SelWaveform ((yylsp[(3) - (4)]), (yyvsp[(2) - (4)].tree.IIR_WaveformList), (yyvsp[(4) - (4)].tree.IIR_ChoiceList), (yyvsp[(1) - (4)].tree.VAUL_SelWaveform));
	}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2766 "bison-parser.yy"
    {
	  (yyval.tree.VAUL_SelWaveform) = NULL;
	}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2770 "bison-parser.yy"
    {
          (yyval.tree.VAUL_SelWaveform) = mVAUL_SelWaveform ((yylsp[(3) - (5)]), (yyvsp[(2) - (5)].tree.IIR_WaveformList), (yyvsp[(4) - (5)].tree.IIR_ChoiceList), (yyvsp[(1) - (5)].tree.VAUL_SelWaveform));
	}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 2777 "bison-parser.yy"
    {
	  pIIR_ConcurrentGenerateStatement g = push_GenerateStat ((yylsp[(2) - (2)]), (yyvsp[(1) - (2)].tree.VAUL_IterationScheme));
	  push_concurrent_stats_tail (&g->concurrent_statement_part);
	  (yyval.tree.IIR_ConcurrentGenerateStatement) = g;
	}
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 2785 "bison-parser.yy"
    {
	  pIIR_ConcurrentGenerateStatement g =
	    (yyvsp[(3) - (9)].tree.IIR_ConcurrentGenerateStatement);
	  closing_label = (yyvsp[(8) - (9)].tree.IIR_Identifier);
	  pop_scope (g);
	  pop_concurrent_stats_tail (&g->concurrent_statement_part);
	  (yyval.tree.IIR_ConcurrentStatement) = g;
	}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 2818 "bison-parser.yy"
    {
	  pIIR_ProcessStatement p = build_Process ((yylsp[(1) - (3)]), (yyvsp[(2) - (3)].tree.IIR_ExpressionList), false);
	  add_decl (p);
	  push_scope (p);
	  (yyval.tree.IIR_ProcessStatement) = p;
	}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 2828 "bison-parser.yy"
    {
	  (yyvsp[(4) - (12)].tree.IIR_ProcessStatement)->process_statement_part = (yyvsp[(7) - (12)].tree.IIR_SequentialStatementList);
	  if ((yyvsp[(9) - (12)].boolean))
	    error ("process is not postponed");
	  closing_label = (yyvsp[(11) - (12)].tree.IIR_Identifier);
	  (yyval.tree.IIR_ConcurrentStatement) = (yyvsp[(4) - (12)].tree.IIR_ProcessStatement);
	  pop_scope((yyval.tree.IIR_ConcurrentStatement));
	}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 2838 "bison-parser.yy"
    {
	  pIIR_ProcessStatement p = build_Process ((yylsp[(2) - (4)]), (yyvsp[(3) - (4)].tree.IIR_ExpressionList), true);
	  add_decl (p);
	  push_scope (p);
	  (yyval.tree.IIR_ProcessStatement) = p;
	}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 2848 "bison-parser.yy"
    {
	  (yyvsp[(5) - (13)].tree.IIR_ProcessStatement)->process_statement_part = (yyvsp[(8) - (13)].tree.IIR_SequentialStatementList);
	  closing_label = (yyvsp[(12) - (13)].tree.IIR_Identifier);
	  (yyval.tree.IIR_ConcurrentStatement) = (yyvsp[(5) - (13)].tree.IIR_ProcessStatement);
	  pop_scope ((yyval.tree.IIR_ConcurrentStatement));
	}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 2867 "bison-parser.yy"
    { (yyval.tree.IIR_ExpressionList) = no_sens_list; }
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 2868 "bison-parser.yy"
    { (yyval.tree.IIR_ExpressionList) = (yyvsp[(2) - (3)].tree.IIR_ExpressionList); }
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 2873 "bison-parser.yy"
    {
	    (yyvsp[(1) - (2)].tree.IIR_ExpressionList)->rest = reverse ((yyvsp[(2) - (2)].tree.IIR_ExpressionList));
	    (yyval.tree.IIR_ExpressionList) = (yyvsp[(1) - (2)].tree.IIR_ExpressionList);
	}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 2880 "bison-parser.yy"
    { (yyval.tree.IIR_ExpressionList) = NULL; }
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 2882 "bison-parser.yy"
    {
	    (yyvsp[(3) - (3)].tree.IIR_ExpressionList)->rest = (yyvsp[(1) - (3)].tree.IIR_ExpressionList);
	    (yyval.tree.IIR_ExpressionList) = (yyvsp[(3) - (3)].tree.IIR_ExpressionList);
	}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 2890 "bison-parser.yy"
    {
	  pIIR_Expression e = build_Expr ((yyvsp[(1) - (1)].tree.VAUL_Name));
	  overload_resolution (e, IR_TYPE);
	  if (e && (!e->is(IR_OBJECT_REFERENCE)
		    || !is_signal (pIIR_ObjectReference(e))))
	    {
	      error ("%:%n is not a signal", (yyvsp[(1) - (1)].tree.VAUL_Name), (yyvsp[(1) - (1)].tree.VAUL_Name));
	      e = NULL;
	    }
	  (yyval.tree.IIR_ExpressionList) = mIIR_ExpressionList ((yylsp[(1) - (1)]), e, NULL);
	}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 2908 "bison-parser.yy"
    { (yyval.tree.IIR_SequentialStatementList) = reverse((yyvsp[(1) - (1)].tree.IIR_SequentialStatementList)); }
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 2912 "bison-parser.yy"
    { (yyval.tree.IIR_SequentialStatementList) = NULL; }
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 2914 "bison-parser.yy"
    {
	  if ((yyvsp[(2) - (2)].tree.IIR_SequentialStatement)) 
	    (yyval.tree.IIR_SequentialStatementList) = mIIR_SequentialStatementList ((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].tree.IIR_SequentialStatement), (yyvsp[(1) - (2)].tree.IIR_SequentialStatementList));
	  else
	    (yyval.tree.IIR_SequentialStatementList) = (yyvsp[(1) - (2)].tree.IIR_SequentialStatementList);
	  /* XX - make it safe to put a call to collect here. */
	  // collect ();
	}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 2925 "bison-parser.yy"
    { (yyval.tree.IIR_SequentialStatement) = (yyvsp[(1) - (1)].tree.IIR_AssertionStatement); }
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 2926 "bison-parser.yy"
    { (yyval.tree.IIR_SequentialStatement) = (yyvsp[(1) - (1)].tree.IIR_ReportStatement); }
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 2927 "bison-parser.yy"
    { (yyval.tree.IIR_SequentialStatement) = (yyvsp[(1) - (1)].tree.IIR_SequentialStatement); }
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 2928 "bison-parser.yy"
    { (yyval.tree.IIR_SequentialStatement) = (yyvsp[(1) - (1)].tree.IIR_SequentialStatement); }
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 2929 "bison-parser.yy"
    { (yyval.tree.IIR_SequentialStatement) = (yyvsp[(1) - (1)].tree.IIR_SequentialStatement); }
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 2930 "bison-parser.yy"
    { (yyval.tree.IIR_SequentialStatement) = (yyvsp[(1) - (1)].tree.IIR_SequentialStatement); }
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 2931 "bison-parser.yy"
    { (yyval.tree.IIR_SequentialStatement) = (yyvsp[(1) - (1)].tree.IIR_SequentialStatement); }
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 2932 "bison-parser.yy"
    { (yyval.tree.IIR_SequentialStatement) = (yyvsp[(1) - (1)].tree.IIR_SequentialStatement); }
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 2933 "bison-parser.yy"
    { (yyval.tree.IIR_SequentialStatement) = (yyvsp[(1) - (1)].tree.IIR_ProcedureCallStatement); }
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 2934 "bison-parser.yy"
    { (yyval.tree.IIR_SequentialStatement) = (yyvsp[(1) - (1)].tree.IIR_SequentialStatement); }
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 2935 "bison-parser.yy"
    { (yyval.tree.IIR_SequentialStatement) = (yyvsp[(1) - (1)].tree.IIR_SequentialStatement); }
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 2936 "bison-parser.yy"
    { (yyval.tree.IIR_SequentialStatement) = (yyvsp[(1) - (1)].tree.IIR_SequentialStatement); }
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 2937 "bison-parser.yy"
    { (yyval.tree.IIR_SequentialStatement) = (yyvsp[(1) - (1)].tree.IIR_SequentialStatement); }
    break;

  case 514:

/* Line 1455 of yacc.c  */
#line 2943 "bison-parser.yy"
    {
	  (yyval.tree.IIR_AssertionStatement) = mIIR_AssertionStatement ((yylsp[(1) - (5)]), (yyvsp[(2) - (5)].tree.IIR_Expression), (yyvsp[(3) - (5)].tree.IIR_Expression), (yyvsp[(4) - (5)].tree.IIR_Expression));
	}
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 2950 "bison-parser.yy"
    {
	  overload_resolution ((yyvsp[(2) - (4)].tree.IIR_Expression), std->predef_STRING);
	  (yyval.tree.IIR_ReportStatement) = mIIR_ReportStatement ((yylsp[(1) - (4)]), (yyvsp[(2) - (4)].tree.IIR_Expression), (yyvsp[(3) - (4)].tree.IIR_Expression));
	}
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 2958 "bison-parser.yy"
    {
	    (yyval.tree.IIR_Expression) = NULL;
	}
    break;

  case 517:

/* Line 1455 of yacc.c  */
#line 2962 "bison-parser.yy"
    {
	    (yyval.tree.IIR_Expression) = (yyvsp[(2) - (2)].tree.IIR_Expression);
	    overload_resolution((yyval.tree.IIR_Expression), std->predef_SEVERITY_LEVEL);
	}
    break;

  case 518:

/* Line 1455 of yacc.c  */
#line 2970 "bison-parser.yy"
    {
	    (yyval.tree.IIR_Expression) = NULL;
	}
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 2974 "bison-parser.yy"
    {
	    (yyval.tree.IIR_Expression) = (yyvsp[(2) - (2)].tree.IIR_Expression);
	    overload_resolution((yyval.tree.IIR_Expression), std->predef_STRING);
	}
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 2985 "bison-parser.yy"
    {
	  pIIR_CaseStatementAlternativeList ca = reverse ((yyvsp[(5) - (8)].tree.IIR_CaseStatementAlternativeList));
	  if ((yyvsp[(4) - (8)].tree.IIR_CaseStatementAlternativeList))
	    {
	      (yyvsp[(4) - (8)].tree.IIR_CaseStatementAlternativeList)->rest = ca;
	      ca = (yyvsp[(4) - (8)].tree.IIR_CaseStatementAlternativeList);
	    }
	  (yyval.tree.IIR_SequentialStatement) = build_CaseStat (make_posinfo((yylsp[(1) - (8)])), (yyvsp[(2) - (8)].tree.IIR_Expression), ca);
	}
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 2998 "bison-parser.yy"
    {
	  (yyval.tree.IIR_CaseStatementAlternativeList) = mIIR_CaseStatementAlternativeList ((yylsp[(1) - (4)]),
	     mIIR_CaseStatementAlternative ((yylsp[(1) - (4)]), (yyvsp[(4) - (4)].tree.IIR_SequentialStatementList), (yyvsp[(2) - (4)].tree.IIR_ChoiceList)), NULL);
	}
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 3006 "bison-parser.yy"
    {
	    (yyval.tree.IIR_CaseStatementAlternativeList) = NULL;
	}
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 3010 "bison-parser.yy"
    {
	    if((yyvsp[(2) - (2)].tree.IIR_CaseStatementAlternativeList)) {
		(yyvsp[(2) - (2)].tree.IIR_CaseStatementAlternativeList)->rest = (yyvsp[(1) - (2)].tree.IIR_CaseStatementAlternativeList);
		(yyval.tree.IIR_CaseStatementAlternativeList) = (yyvsp[(2) - (2)].tree.IIR_CaseStatementAlternativeList);
	    } else
		(yyval.tree.IIR_CaseStatementAlternativeList) = (yyvsp[(1) - (2)].tree.IIR_CaseStatementAlternativeList);
	}
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 3022 "bison-parser.yy"
    {
	  (yyval.tree.IIR_SequentialStatement) = mIIR_IfStatement ((yylsp[(1) - (9)]), (yyvsp[(2) - (9)].tree.IIR_Expression), (yyvsp[(4) - (9)].tree.IIR_SequentialStatementList), (yyvsp[(5) - (9)].tree.IIR_SequentialStatementList));
	  if ((yyvsp[(6) - (9)].tree.IIR_SequentialStatementList))
	    {
	      pIIR_SequentialStatementList *s;
	      for (s = &(pIIR_IfStatement((yyval.tree.IIR_SequentialStatement))->else_sequence);
		   *s && (*s)->first->is(IR_IF_STATEMENT);
		   s = &(pIIR_IfStatement((*s)->first)->else_sequence))
		;
	      assert (*s == NULL);
	      *s = (yyvsp[(6) - (9)].tree.IIR_SequentialStatementList);
	    }
	}
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 3038 "bison-parser.yy"
    { (yyval.tree.IIR_SequentialStatementList) = NULL; }
    break;

  case 526:

/* Line 1455 of yacc.c  */
#line 3039 "bison-parser.yy"
    { (yyval.tree.IIR_SequentialStatementList) = (yyvsp[(2) - (2)].tree.IIR_SequentialStatementList); }
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 3043 "bison-parser.yy"
    { (yyval.tree.IIR_SequentialStatementList) = NULL; }
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 3045 "bison-parser.yy"
    {
	  (yyval.tree.IIR_SequentialStatementList) = mIIR_SequentialStatementList ((yylsp[(2) - (5)]),
	                                     mIIR_IfStatement ((yylsp[(2) - (5)]), (yyvsp[(3) - (5)].tree.IIR_Expression), (yyvsp[(5) - (5)].tree.IIR_SequentialStatementList),
					                       NULL),
	                                     NULL);
	  if ((yyvsp[(1) - (5)].tree.IIR_SequentialStatementList))
	    {
	      assert ((yyvsp[(1) - (5)].tree.IIR_SequentialStatementList)->is(IR_SEQUENTIAL_STATEMENT_LIST));
	      pIIR_SequentialStatementList sl =
		pIIR_SequentialStatementList((yyvsp[(1) - (5)].tree.IIR_SequentialStatementList));
	      assert (sl->first && sl->rest == NULL &&
		      sl->first->is(IR_IF_STATEMENT));
	      pIIR_SequentialStatementList *s;
	      for (s = &(pIIR_IfStatement(sl->first)->else_sequence);
		   *s && (*s)->first->is(IR_IF_STATEMENT);
		   s = &(pIIR_IfStatement((*s)->first)->else_sequence))
		;
	      assert (*s == NULL);
	      *s = (yyval.tree.IIR_SequentialStatementList);
	      (yyval.tree.IIR_SequentialStatementList) = (yyvsp[(1) - (5)].tree.IIR_SequentialStatementList);
	    }
	}
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 3071 "bison-parser.yy"
    {
	  overload_resolution ((yyvsp[(1) - (1)].tree.IIR_Expression), std->predef_BOOLEAN);
	  (yyval.tree.IIR_Expression) = (yyvsp[(1) - (1)].tree.IIR_Expression); 
	}
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 3079 "bison-parser.yy"
    { 
	    pIIR_LoopStatement l = push_loop((yylsp[(3) - (3)]), (yyvsp[(1) - (3)].tree.IIR_Label), (yyvsp[(2) - (3)].tree.VAUL_IterationScheme));
	}
    break;

  case 531:

/* Line 1455 of yacc.c  */
#line 3084 "bison-parser.yy"
    {
	    (yyval.tree.IIR_SequentialStatement) = pop_loop((yyvsp[(5) - (9)].tree.IIR_SequentialStatementList), (yyvsp[(8) - (9)].tree.IIR_Identifier));
	}
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 3090 "bison-parser.yy"
    { (yyval.tree.VAUL_IterationScheme) = NULL; }
    break;

  case 533:

/* Line 1455 of yacc.c  */
#line 3091 "bison-parser.yy"
    { (yyval.tree.VAUL_IterationScheme) = (yyvsp[(1) - (1)].tree.VAUL_IterationScheme); }
    break;

  case 534:

/* Line 1455 of yacc.c  */
#line 3095 "bison-parser.yy"
    { (yyval.tree.IIR_Label) = NULL; }
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 3097 "bison-parser.yy"
    {
	  (yyval.tree.IIR_Label) = pIIR_Label (add_decl (mIIR_Label((yylsp[(1) - (2)]), (yyvsp[(1) - (2)].tree.IIR_Identifier), NULL))); 
	}
    break;

  case 536:

/* Line 1455 of yacc.c  */
#line 3104 "bison-parser.yy"
    {   
	    (yyval.tree.IIR_SequentialStatement) = build_LoopControlStat((yylsp[(1) - (4)]), IR_NEXT_STATEMENT, (yyvsp[(2) - (4)].tree.IIR_Identifier), (yyvsp[(3) - (4)].tree.IIR_Expression));
	}
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 3111 "bison-parser.yy"
    {   
	    (yyval.tree.IIR_SequentialStatement) = build_LoopControlStat((yylsp[(1) - (4)]), IR_EXIT_STATEMENT, (yyvsp[(2) - (4)].tree.IIR_Identifier), (yyvsp[(3) - (4)].tree.IIR_Expression));
	}
    break;

  case 538:

/* Line 1455 of yacc.c  */
#line 3117 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = NULL; }
    break;

  case 539:

/* Line 1455 of yacc.c  */
#line 3118 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = (yyvsp[(2) - (2)].tree.IIR_Expression); }
    break;

  case 540:

/* Line 1455 of yacc.c  */
#line 3122 "bison-parser.yy"
    { (yyval.tree.IIR_SequentialStatement) = mIIR_NullStatement((yylsp[(1) - (2)])); }
    break;

  case 541:

/* Line 1455 of yacc.c  */
#line 3126 "bison-parser.yy"
    { (yyval.tree.IIR_ProcedureCallStatement) = (yyvsp[(1) - (1)].tree.IIR_ProcedureCallStatement); }
    break;

  case 542:

/* Line 1455 of yacc.c  */
#line 3127 "bison-parser.yy"
    { (yyval.tree.IIR_ProcedureCallStatement) = (yyvsp[(1) - (1)].tree.IIR_ProcedureCallStatement); }
    break;

  case 543:

/* Line 1455 of yacc.c  */
#line 3132 "bison-parser.yy"
    {
	    (yyval.tree.IIR_ProcedureCallStatement) = build_ProcedureCallStat ((yylsp[(1) - (2)]), (yyvsp[(1) - (2)].tree.VAUL_Name));
	}
    break;

  case 544:

/* Line 1455 of yacc.c  */
#line 3139 "bison-parser.yy"
    {
	    (yyval.tree.IIR_ProcedureCallStatement) = build_ProcedureCallStat ((yylsp[(1) - (2)]), (yyvsp[(1) - (2)].tree.VAUL_Name));
	}
    break;

  case 545:

/* Line 1455 of yacc.c  */
#line 3146 "bison-parser.yy"
    {
	  if (cur_body == NULL || (yyvsp[(2) - (3)].tree.IIR_Expression) == NULL)
	    (yyval.tree.IIR_SequentialStatement) = NULL;
	  else if (cur_body->is(IR_FUNCTION_DECLARATION))
	    {
	      if ((yyvsp[(2) - (3)].tree.IIR_Expression)->is(IR_OPEN_EXPRESSION))
		{
		  error ("return without a value");
		  (yyval.tree.IIR_SequentialStatement) = NULL;
		}
	      else 
		{
		  overload_resolution((yyvsp[(2) - (3)].tree.IIR_Expression),
			   pIIR_FunctionDeclaration(cur_body)->return_type);
		  (yyval.tree.IIR_SequentialStatement) = mIIR_ReturnStatement ((yylsp[(1) - (3)]), cur_body, (yyvsp[(2) - (3)].tree.IIR_Expression));
		}
	    } 
	  else if (cur_body->is(IR_PROCEDURE_DECLARATION))
	    {
	      if (!(yyvsp[(2) - (3)].tree.IIR_Expression)->is(IR_OPEN_EXPRESSION))
		{
		  error ("return with a value");
		  (yyval.tree.IIR_SequentialStatement) = NULL;
		}
	      else
		(yyval.tree.IIR_SequentialStatement) = mIIR_ReturnStatement ((yylsp[(1) - (3)]), cur_body, NULL);
	    }
	  else
	    {
	      error ("can only return from subprograms");
	      (yyval.tree.IIR_SequentialStatement) = NULL;
	    }
	}
    break;

  case 546:

/* Line 1455 of yacc.c  */
#line 3182 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = mIIR_OpenExpression(-1, NULL); }
    break;

  case 548:

/* Line 1455 of yacc.c  */
#line 3188 "bison-parser.yy"
    {
	    (yyval.tree.IIR_SequentialStatement) = build_SignalAssignment(make_posinfo((yylsp[(2) - (5)])), (yyvsp[(1) - (5)].tree.IIR_Expression), (yyvsp[(3) - (5)].tree.VAUL_DelayMechanism), (yyvsp[(4) - (5)].tree.IIR_WaveformList));
	}
    break;

  case 549:

/* Line 1455 of yacc.c  */
#line 3194 "bison-parser.yy"
    { (yyval.tree.VAUL_DelayMechanism) = mVAUL_DelayInertial ((IIR_PosInfo *)NULL, NULL); }
    break;

  case 550:

/* Line 1455 of yacc.c  */
#line 3195 "bison-parser.yy"
    { (yyval.tree.VAUL_DelayMechanism) = mVAUL_DelayTransport ((yylsp[(1) - (1)])); }
    break;

  case 551:

/* Line 1455 of yacc.c  */
#line 3196 "bison-parser.yy"
    { (yyval.tree.VAUL_DelayMechanism) = mVAUL_DelayInertial ((yylsp[(1) - (1)]), NULL); }
    break;

  case 552:

/* Line 1455 of yacc.c  */
#line 3198 "bison-parser.yy"
    {
	    pIIR_Expression rtime = (yyvsp[(2) - (3)].tree.IIR_Expression);
	    overload_resolution (rtime, std->predef_TIME);
	    (yyval.tree.VAUL_DelayMechanism) = mVAUL_DelayInertial ((yylsp[(1) - (3)]), rtime);
	}
    break;

  case 553:

/* Line 1455 of yacc.c  */
#line 3207 "bison-parser.yy"
    {
	    (yyval.tree.IIR_SequentialStatement) = build_VarAssignment((yylsp[(2) - (4)]), (yyvsp[(1) - (4)].tree.IIR_Expression), (yyvsp[(3) - (4)].tree.IIR_Expression));
	}
    break;

  case 554:

/* Line 1455 of yacc.c  */
#line 3214 "bison-parser.yy"
    {
	    (yyval.tree.IIR_SequentialStatement) = mIIR_WaitStatement ((yylsp[(1) - (5)]), (yyvsp[(3) - (5)].tree.IIR_Expression), (yyvsp[(4) - (5)].tree.IIR_Expression), (yyvsp[(2) - (5)].tree.IIR_ExpressionList));
	}
    break;

  case 555:

/* Line 1455 of yacc.c  */
#line 3220 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = NULL; }
    break;

  case 556:

/* Line 1455 of yacc.c  */
#line 3221 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = (yyvsp[(2) - (2)].tree.IIR_Expression); overload_resolution((yyval.tree.IIR_Expression), std->predef_TIME); }
    break;

  case 557:

/* Line 1455 of yacc.c  */
#line 3225 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = NULL; }
    break;

  case 558:

/* Line 1455 of yacc.c  */
#line 3226 "bison-parser.yy"
    { (yyval.tree.IIR_Expression) = (yyvsp[(2) - (2)].tree.IIR_Expression); }
    break;

  case 559:

/* Line 1455 of yacc.c  */
#line 3230 "bison-parser.yy"
    { (yyval.tree.IIR_ExpressionList) = NULL; }
    break;

  case 560:

/* Line 1455 of yacc.c  */
#line 3231 "bison-parser.yy"
    { (yyval.tree.IIR_ExpressionList) = (yyvsp[(2) - (2)].tree.IIR_ExpressionList); }
    break;

  case 561:

/* Line 1455 of yacc.c  */
#line 3240 "bison-parser.yy"
    {
	  pIIR_ComponentDeclaration c = mIIR_ComponentDeclaration ((yylsp[(1) - (3)]), (yyvsp[(2) - (3)].tree.IIR_Identifier));
	  add_decl (c);
	  push_scope (c);
	  (yyval.tree.IIR_ComponentDeclaration) = c;
	}
    break;

  case 562:

/* Line 1455 of yacc.c  */
#line 3248 "bison-parser.yy"
    {
	  if ((yyvsp[(8) - (9)].tree.IIR_Identifier) && !vaul_name_eq((yyvsp[(8) - (9)].tree.IIR_Identifier), (yyvsp[(2) - (9)].tree.IIR_Identifier)))
	    error("%n does not match component name %n", (yyvsp[(8) - (9)].tree.IIR_Identifier), (yyvsp[(2) - (9)].tree.IIR_Identifier));
	  pop_scope ((yyvsp[(4) - (9)].tree.IIR_ComponentDeclaration));
	}
    break;

  case 563:

/* Line 1455 of yacc.c  */
#line 3256 "bison-parser.yy"
    { (yyval.tree.IIR_BlockConfiguration) = start_BlockConfig((yyvsp[(2) - (2)].tree.VAUL_Name)); }
    break;

  case 564:

/* Line 1455 of yacc.c  */
#line 3260 "bison-parser.yy"
    {
    	    (yyval.tree.IIR_BlockConfiguration) = (yyvsp[(3) - (8)].tree.IIR_BlockConfiguration);
    	    if((yyval.tree.IIR_BlockConfiguration)) {
    	    	check_BlockConfig((yyval.tree.IIR_BlockConfiguration));
    		pop_scope((yyval.tree.IIR_BlockConfiguration));
    	    }
    	}
    break;

  case 565:

/* Line 1455 of yacc.c  */
#line 3270 "bison-parser.yy"
    { }
    break;

  case 566:

/* Line 1455 of yacc.c  */
#line 3271 "bison-parser.yy"
    { }
    break;

  case 568:

/* Line 1455 of yacc.c  */
#line 3276 "bison-parser.yy"
    { use((yyvsp[(2) - (2)].tree.VAUL_SelNameList)); }
    break;

  case 569:

/* Line 1455 of yacc.c  */
#line 3280 "bison-parser.yy"
    { (yyval.tree.IIR_ConfigurationItem) = (yyvsp[(1) - (1)].tree.IIR_BlockConfiguration); }
    break;

  case 570:

/* Line 1455 of yacc.c  */
#line 3281 "bison-parser.yy"
    { (yyval.tree.IIR_ConfigurationItem) = (yyvsp[(1) - (1)].tree.IIR_ConfigurationItem); }
    break;

  case 571:

/* Line 1455 of yacc.c  */
#line 3286 "bison-parser.yy"
    { (yyval.tree.IIR_ComponentConfiguration) = start_CompConfig((yylsp[(1) - (3)]), (yyvsp[(2) - (3)].tree.VAUL_ComponentSpec), (yyvsp[(3) - (3)].tree.VAUL_IncrementalBindingIndic)); }
    break;

  case 572:

/* Line 1455 of yacc.c  */
#line 3289 "bison-parser.yy"
    {
    	    pIIR_ComponentConfiguration cc =
	      (yyvsp[(4) - (8)].tree.IIR_ComponentConfiguration);
    	    if(cc) {
       	    	cc->block_config = (yyvsp[(5) - (8)].tree.IIR_BlockConfiguration);
    		pop_scope(cc);
    	    }
    	}
    break;

  case 573:

/* Line 1455 of yacc.c  */
#line 3300 "bison-parser.yy"
    { (yyval.tree.IIR_BlockConfiguration) = NULL; }
    break;

  case 574:

/* Line 1455 of yacc.c  */
#line 3301 "bison-parser.yy"
    { (yyval.tree.IIR_BlockConfiguration) = (yyvsp[(1) - (1)].tree.IIR_BlockConfiguration); }
    break;

  case 575:

/* Line 1455 of yacc.c  */
#line 3305 "bison-parser.yy"
    { (yyval.tree.VAUL_IncrementalBindingIndic) = NULL; }
    break;

  case 576:

/* Line 1455 of yacc.c  */
#line 3306 "bison-parser.yy"
    { (yyval.tree.VAUL_IncrementalBindingIndic) = (yyvsp[(1) - (2)].tree.VAUL_IncrementalBindingIndic); }
    break;

  case 577:

/* Line 1455 of yacc.c  */
#line 3307 "bison-parser.yy"
    { (yyval.tree.VAUL_IncrementalBindingIndic) = (yyvsp[(1) - (2)].tree.VAUL_IncrementalBindingIndic); }
    break;

  case 578:

/* Line 1455 of yacc.c  */
#line 3312 "bison-parser.yy"
    {
	  pVAUL_ConfigSpec cs = mVAUL_ConfigSpec ((yylsp[(1) - (4)]), (yyvsp[(2) - (4)].tree.VAUL_ComponentSpec), (yyvsp[(3) - (4)].tree.IIR_BindingIndication));
	  add_spec (cur_scope, cs);
	}
    break;

  case 579:

/* Line 1455 of yacc.c  */
#line 3320 "bison-parser.yy"
    {
	  (yyval.tree.VAUL_ComponentSpec) = mVAUL_ComponentSpec ((yylsp[(1) - (3)]), (yyvsp[(1) - (3)].tree.VAUL_InstList), (yyvsp[(3) - (3)].tree.IIR_ComponentDeclaration));
	  select_scope ((yyvsp[(3) - (3)].tree.IIR_ComponentDeclaration));
	}
    break;

  case 580:

/* Line 1455 of yacc.c  */
#line 3328 "bison-parser.yy"
    {
	  (yyval.tree.IIR_ComponentDeclaration) = pIIR_ComponentDeclaration(
		 find_single_decl ((yyvsp[(1) - (1)].tree.VAUL_Name), IR_COMPONENT_DECLARATION,
				   "component"));
	}
    break;

  case 581:

/* Line 1455 of yacc.c  */
#line 3336 "bison-parser.yy"
    { (yyval.tree.VAUL_InstList) = mVAUL_InstList_Ids((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].tree.IIR_IdentifierList)); }
    break;

  case 582:

/* Line 1455 of yacc.c  */
#line 3337 "bison-parser.yy"
    { (yyval.tree.VAUL_InstList) = mVAUL_InstList_ALL((yylsp[(1) - (1)])); }
    break;

  case 583:

/* Line 1455 of yacc.c  */
#line 3338 "bison-parser.yy"
    { (yyval.tree.VAUL_InstList) = mVAUL_InstList_OTHERS((yylsp[(1) - (1)])); }
    break;

  case 584:

/* Line 1455 of yacc.c  */
#line 3346 "bison-parser.yy"
    { (yyval.tree.IIR_BindingIndication) = build_BindingIndic((yyvsp[(1) - (1)].tree.VAUL_IncrementalBindingIndic)); }
    break;

  case 585:

/* Line 1455 of yacc.c  */
#line 3350 "bison-parser.yy"
    { (yyval.tree.IIR_DeclarativeRegion) = selected_scope; unselect_scope(); }
    break;

  case 586:

/* Line 1455 of yacc.c  */
#line 3352 "bison-parser.yy"
    { select_scope((yyvsp[(1) - (3)].tree.IIR_DeclarativeRegion)); }
    break;

  case 587:

/* Line 1455 of yacc.c  */
#line 3354 "bison-parser.yy"
    {
	    (yyval.tree.VAUL_IncrementalBindingIndic) = mVAUL_IncrementalBindingIndic((yylsp[(1) - (6)]), (yyvsp[(3) - (6)].tree.IIR_DeclarativeRegion), (yyvsp[(5) - (6)].tree.VAUL_NamedAssocElem), (yyvsp[(6) - (6)].tree.VAUL_NamedAssocElem));
	    unselect_scope();
	}
    break;

  case 588:

/* Line 1455 of yacc.c  */
#line 3362 "bison-parser.yy"
    {
	    (yyval.tree.VAUL_IncrementalBindingIndic) = mVAUL_IncrementalBindingIndic((yylsp[(1) - (2)]), NULL, (yyvsp[(1) - (2)].tree.VAUL_NamedAssocElem), (yyvsp[(2) - (2)].tree.VAUL_NamedAssocElem));
	    unselect_scope();
	}
    break;

  case 589:

/* Line 1455 of yacc.c  */
#line 3367 "bison-parser.yy"
    {
    	    (yyval.tree.VAUL_IncrementalBindingIndic) = mVAUL_IncrementalBindingIndic((yylsp[(1) - (1)]), NULL, NULL, (yyvsp[(1) - (1)].tree.VAUL_NamedAssocElem));
    	    unselect_scope();
    	}
    break;

  case 590:

/* Line 1455 of yacc.c  */
#line 3375 "bison-parser.yy"
    {
	  (yyval.tree.IIR_DeclarativeRegion) = get_architecture_ref ((yylsp[(1) - (3)]), (yyvsp[(2) - (3)].tree.VAUL_Name), (yyvsp[(3) - (3)].tree.IIR_Identifier)); 
	}
    break;

  case 591:

/* Line 1455 of yacc.c  */
#line 3379 "bison-parser.yy"
    {
	  (yyval.tree.IIR_DeclarativeRegion) = get_configuration((yyvsp[(2) - (2)].tree.VAUL_Name)); 
	}
    break;

  case 592:

/* Line 1455 of yacc.c  */
#line 3383 "bison-parser.yy"
    {
	  (yyval.tree.IIR_DeclarativeRegion) = NULL; 
	}
    break;

  case 593:

/* Line 1455 of yacc.c  */
#line 3389 "bison-parser.yy"
    { (yyval.tree.IIR_Identifier) = NULL; }
    break;

  case 594:

/* Line 1455 of yacc.c  */
#line 3390 "bison-parser.yy"
    { (yyval.tree.IIR_Identifier) = (yyvsp[(2) - (3)].tree.IIR_Identifier); }
    break;

  case 595:

/* Line 1455 of yacc.c  */
#line 3397 "bison-parser.yy"
    {}
    break;

  case 596:

/* Line 1455 of yacc.c  */
#line 3398 "bison-parser.yy"
    {}
    break;

  case 597:

/* Line 1455 of yacc.c  */
#line 3403 "bison-parser.yy"
    {}
    break;

  case 598:

/* Line 1455 of yacc.c  */
#line 3404 "bison-parser.yy"
    {}
    break;

  case 599:

/* Line 1455 of yacc.c  */
#line 3405 "bison-parser.yy"
    {}
    break;

  case 600:

/* Line 1455 of yacc.c  */
#line 3406 "bison-parser.yy"
    {}
    break;

  case 601:

/* Line 1455 of yacc.c  */
#line 3410 "bison-parser.yy"
    {}
    break;

  case 602:

/* Line 1455 of yacc.c  */
#line 3411 "bison-parser.yy"
    {}
    break;

  case 603:

/* Line 1455 of yacc.c  */
#line 3416 "bison-parser.yy"
    {}
    break;

  case 604:

/* Line 1455 of yacc.c  */
#line 3420 "bison-parser.yy"
    {}
    break;

  case 605:

/* Line 1455 of yacc.c  */
#line 3421 "bison-parser.yy"
    {}
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 3426 "bison-parser.yy"
    {}
    break;

  case 607:

/* Line 1455 of yacc.c  */
#line 3430 "bison-parser.yy"
    {}
    break;

  case 608:

/* Line 1455 of yacc.c  */
#line 3431 "bison-parser.yy"
    {}
    break;

  case 609:

/* Line 1455 of yacc.c  */
#line 3446 "bison-parser.yy"
    {}
    break;

  case 610:

/* Line 1455 of yacc.c  */
#line 3451 "bison-parser.yy"
    {}
    break;

  case 611:

/* Line 1455 of yacc.c  */
#line 3452 "bison-parser.yy"
    {}
    break;

  case 617:

/* Line 1455 of yacc.c  */
#line 3492 "bison-parser.yy"
    {}
    break;

  case 618:

/* Line 1455 of yacc.c  */
#line 3506 "bison-parser.yy"
    {}
    break;

  case 619:

/* Line 1455 of yacc.c  */
#line 3532 "bison-parser.yy"
    {}
    break;

  case 620:

/* Line 1455 of yacc.c  */
#line 3533 "bison-parser.yy"
    {}
    break;

  case 621:

/* Line 1455 of yacc.c  */
#line 3538 "bison-parser.yy"
    {
      // info ("skipping %n", $4);
    }
    break;

  case 622:

/* Line 1455 of yacc.c  */
#line 3543 "bison-parser.yy"
    {}
    break;

  case 623:

/* Line 1455 of yacc.c  */
#line 3546 "bison-parser.yy"
    {}
    break;

  case 626:

/* Line 1455 of yacc.c  */
#line 3553 "bison-parser.yy"
    {}
    break;

  case 627:

/* Line 1455 of yacc.c  */
#line 3554 "bison-parser.yy"
    {}
    break;

  case 628:

/* Line 1455 of yacc.c  */
#line 3560 "bison-parser.yy"
    {
      // info ("skipping %n", $4);
    }
    break;

  case 629:

/* Line 1455 of yacc.c  */
#line 3566 "bison-parser.yy"
    {}
    break;

  case 632:

/* Line 1455 of yacc.c  */
#line 3573 "bison-parser.yy"
    {}
    break;

  case 633:

/* Line 1455 of yacc.c  */
#line 3574 "bison-parser.yy"
    {}
    break;

  case 634:

/* Line 1455 of yacc.c  */
#line 3600 "bison-parser.yy"
    {
      // info ("skipping %n", $3);
    }
    break;

  case 635:

/* Line 1455 of yacc.c  */
#line 3605 "bison-parser.yy"
    {}
    break;

  case 639:

/* Line 1455 of yacc.c  */
#line 3613 "bison-parser.yy"
    {}
    break;

  case 646:

/* Line 1455 of yacc.c  */
#line 3627 "bison-parser.yy"
    {}
    break;

  case 668:

/* Line 1455 of yacc.c  */
#line 3686 "bison-parser.yy"
    {}
    break;

  case 669:

/* Line 1455 of yacc.c  */
#line 3695 "bison-parser.yy"
    {}
    break;

  case 670:

/* Line 1455 of yacc.c  */
#line 3700 "bison-parser.yy"
    {}
    break;

  case 671:

/* Line 1455 of yacc.c  */
#line 3705 "bison-parser.yy"
    {}
    break;

  case 672:

/* Line 1455 of yacc.c  */
#line 3708 "bison-parser.yy"
    {}
    break;

  case 673:

/* Line 1455 of yacc.c  */
#line 3712 "bison-parser.yy"
    {}
    break;

  case 674:

/* Line 1455 of yacc.c  */
#line 3713 "bison-parser.yy"
    {}
    break;

  case 675:

/* Line 1455 of yacc.c  */
#line 3714 "bison-parser.yy"
    {}
    break;

  case 676:

/* Line 1455 of yacc.c  */
#line 3718 "bison-parser.yy"
    {}
    break;

  case 678:

/* Line 1455 of yacc.c  */
#line 3724 "bison-parser.yy"
    {}
    break;

  case 679:

/* Line 1455 of yacc.c  */
#line 3729 "bison-parser.yy"
    {}
    break;

  case 680:

/* Line 1455 of yacc.c  */
#line 3733 "bison-parser.yy"
    {}
    break;

  case 681:

/* Line 1455 of yacc.c  */
#line 3734 "bison-parser.yy"
    {}
    break;

  case 684:

/* Line 1455 of yacc.c  */
#line 3748 "bison-parser.yy"
    {}
    break;

  case 685:

/* Line 1455 of yacc.c  */
#line 3750 "bison-parser.yy"
    {}
    break;

  case 686:

/* Line 1455 of yacc.c  */
#line 3754 "bison-parser.yy"
    {}
    break;

  case 687:

/* Line 1455 of yacc.c  */
#line 3756 "bison-parser.yy"
    {}
    break;

  case 688:

/* Line 1455 of yacc.c  */
#line 3760 "bison-parser.yy"
    {}
    break;

  case 689:

/* Line 1455 of yacc.c  */
#line 3762 "bison-parser.yy"
    {}
    break;

  case 690:

/* Line 1455 of yacc.c  */
#line 3767 "bison-parser.yy"
    {}
    break;

  case 691:

/* Line 1455 of yacc.c  */
#line 3771 "bison-parser.yy"
    {}
    break;

  case 692:

/* Line 1455 of yacc.c  */
#line 3773 "bison-parser.yy"
    {}
    break;

  case 693:

/* Line 1455 of yacc.c  */
#line 3779 "bison-parser.yy"
    {}
    break;

  case 694:

/* Line 1455 of yacc.c  */
#line 3783 "bison-parser.yy"
    {}
    break;

  case 695:

/* Line 1455 of yacc.c  */
#line 3784 "bison-parser.yy"
    {}
    break;

  case 696:

/* Line 1455 of yacc.c  */
#line 3788 "bison-parser.yy"
    {}
    break;

  case 698:

/* Line 1455 of yacc.c  */
#line 3793 "bison-parser.yy"
    {}
    break;

  case 700:

/* Line 1455 of yacc.c  */
#line 3798 "bison-parser.yy"
    {}
    break;

  case 701:

/* Line 1455 of yacc.c  */
#line 3799 "bison-parser.yy"
    {}
    break;

  case 702:

/* Line 1455 of yacc.c  */
#line 3800 "bison-parser.yy"
    {}
    break;

  case 703:

/* Line 1455 of yacc.c  */
#line 3801 "bison-parser.yy"
    {}
    break;

  case 704:

/* Line 1455 of yacc.c  */
#line 3802 "bison-parser.yy"
    {}
    break;

  case 705:

/* Line 1455 of yacc.c  */
#line 3807 "bison-parser.yy"
    {}
    break;

  case 706:

/* Line 1455 of yacc.c  */
#line 3812 "bison-parser.yy"
    {}
    break;

  case 707:

/* Line 1455 of yacc.c  */
#line 3816 "bison-parser.yy"
    {}
    break;

  case 708:

/* Line 1455 of yacc.c  */
#line 3818 "bison-parser.yy"
    {}
    break;

  case 709:

/* Line 1455 of yacc.c  */
#line 3824 "bison-parser.yy"
    {}
    break;

  case 710:

/* Line 1455 of yacc.c  */
#line 3828 "bison-parser.yy"
    {}
    break;

  case 711:

/* Line 1455 of yacc.c  */
#line 3830 "bison-parser.yy"
    {}
    break;

  case 712:

/* Line 1455 of yacc.c  */
#line 3835 "bison-parser.yy"
    {}
    break;

  case 713:

/* Line 1455 of yacc.c  */
#line 3837 "bison-parser.yy"
    {}
    break;

  case 716:

/* Line 1455 of yacc.c  */
#line 3846 "bison-parser.yy"
    {}
    break;

  case 717:

/* Line 1455 of yacc.c  */
#line 3847 "bison-parser.yy"
    {}
    break;

  case 719:

/* Line 1455 of yacc.c  */
#line 3852 "bison-parser.yy"
    {}
    break;

  case 720:

/* Line 1455 of yacc.c  */
#line 3860 "bison-parser.yy"
    {}
    break;

  case 721:

/* Line 1455 of yacc.c  */
#line 3861 "bison-parser.yy"
    {}
    break;

  case 722:

/* Line 1455 of yacc.c  */
#line 3866 "bison-parser.yy"
    {}
    break;

  case 723:

/* Line 1455 of yacc.c  */
#line 3870 "bison-parser.yy"
    {}
    break;

  case 724:

/* Line 1455 of yacc.c  */
#line 3871 "bison-parser.yy"
    {}
    break;

  case 725:

/* Line 1455 of yacc.c  */
#line 3872 "bison-parser.yy"
    {}
    break;

  case 726:

/* Line 1455 of yacc.c  */
#line 3873 "bison-parser.yy"
    {}
    break;

  case 727:

/* Line 1455 of yacc.c  */
#line 3874 "bison-parser.yy"
    {}
    break;

  case 728:

/* Line 1455 of yacc.c  */
#line 3876 "bison-parser.yy"
    {}
    break;

  case 729:

/* Line 1455 of yacc.c  */
#line 3878 "bison-parser.yy"
    {}
    break;

  case 730:

/* Line 1455 of yacc.c  */
#line 3883 "bison-parser.yy"
    {
	}
    break;

  case 731:

/* Line 1455 of yacc.c  */
#line 3889 "bison-parser.yy"
    { }
    break;

  case 732:

/* Line 1455 of yacc.c  */
#line 3891 "bison-parser.yy"
    { }
    break;

  case 733:

/* Line 1455 of yacc.c  */
#line 3896 "bison-parser.yy"
    { }
    break;

  case 734:

/* Line 1455 of yacc.c  */
#line 3898 "bison-parser.yy"
    { }
    break;

  case 735:

/* Line 1455 of yacc.c  */
#line 3903 "bison-parser.yy"
    { }
    break;

  case 736:

/* Line 1455 of yacc.c  */
#line 3905 "bison-parser.yy"
    { }
    break;

  case 737:

/* Line 1455 of yacc.c  */
#line 3910 "bison-parser.yy"
    { }
    break;

  case 738:

/* Line 1455 of yacc.c  */
#line 3912 "bison-parser.yy"
    { }
    break;

  case 740:

/* Line 1455 of yacc.c  */
#line 3918 "bison-parser.yy"
    {
	}
    break;

  case 741:

/* Line 1455 of yacc.c  */
#line 3921 "bison-parser.yy"
    {
	}
    break;

  case 742:

/* Line 1455 of yacc.c  */
#line 3924 "bison-parser.yy"
    {
	}
    break;

  case 743:

/* Line 1455 of yacc.c  */
#line 3927 "bison-parser.yy"
    {
	}
    break;

  case 744:

/* Line 1455 of yacc.c  */
#line 3930 "bison-parser.yy"
    {
	}
    break;

  case 745:

/* Line 1455 of yacc.c  */
#line 3933 "bison-parser.yy"
    {
	}
    break;

  case 746:

/* Line 1455 of yacc.c  */
#line 3939 "bison-parser.yy"
    {
	}
    break;

  case 748:

/* Line 1455 of yacc.c  */
#line 3946 "bison-parser.yy"
    {
	}
    break;

  case 749:

/* Line 1455 of yacc.c  */
#line 3949 "bison-parser.yy"
    {
	}
    break;

  case 750:

/* Line 1455 of yacc.c  */
#line 3952 "bison-parser.yy"
    {
	}
    break;

  case 751:

/* Line 1455 of yacc.c  */
#line 3955 "bison-parser.yy"
    {
	}
    break;

  case 752:

/* Line 1455 of yacc.c  */
#line 3958 "bison-parser.yy"
    {
	}
    break;

  case 753:

/* Line 1455 of yacc.c  */
#line 3961 "bison-parser.yy"
    {
	}
    break;

  case 754:

/* Line 1455 of yacc.c  */
#line 3967 "bison-parser.yy"
    {
	}
    break;

  case 756:

/* Line 1455 of yacc.c  */
#line 3974 "bison-parser.yy"
    {
	}
    break;

  case 757:

/* Line 1455 of yacc.c  */
#line 3977 "bison-parser.yy"
    {
	}
    break;

  case 758:

/* Line 1455 of yacc.c  */
#line 3980 "bison-parser.yy"
    {
	}
    break;

  case 760:

/* Line 1455 of yacc.c  */
#line 3987 "bison-parser.yy"
    {
	}
    break;

  case 761:

/* Line 1455 of yacc.c  */
#line 3990 "bison-parser.yy"
    {
	}
    break;

  case 762:

/* Line 1455 of yacc.c  */
#line 3996 "bison-parser.yy"
    {
	}
    break;

  case 764:

/* Line 1455 of yacc.c  */
#line 4003 "bison-parser.yy"
    {
	}
    break;

  case 765:

/* Line 1455 of yacc.c  */
#line 4006 "bison-parser.yy"
    {
	}
    break;

  case 766:

/* Line 1455 of yacc.c  */
#line 4009 "bison-parser.yy"
    {
	}
    break;

  case 767:

/* Line 1455 of yacc.c  */
#line 4012 "bison-parser.yy"
    {
	}
    break;

  case 768:

/* Line 1455 of yacc.c  */
#line 4018 "bison-parser.yy"
    {
	}
    break;

  case 770:

/* Line 1455 of yacc.c  */
#line 4025 "bison-parser.yy"
    {
	}
    break;

  case 771:

/* Line 1455 of yacc.c  */
#line 4028 "bison-parser.yy"
    {
	}
    break;

  case 772:

/* Line 1455 of yacc.c  */
#line 4031 "bison-parser.yy"
    {
	}
    break;

  case 773:

/* Line 1455 of yacc.c  */
#line 4037 "bison-parser.yy"
    {
	}
    break;

  case 774:

/* Line 1455 of yacc.c  */
#line 4042 "bison-parser.yy"
    {}
    break;

  case 775:

/* Line 1455 of yacc.c  */
#line 4043 "bison-parser.yy"
    {}
    break;

  case 776:

/* Line 1455 of yacc.c  */
#line 4044 "bison-parser.yy"
    {}
    break;

  case 777:

/* Line 1455 of yacc.c  */
#line 4045 "bison-parser.yy"
    {}
    break;

  case 778:

/* Line 1455 of yacc.c  */
#line 4046 "bison-parser.yy"
    {}
    break;

  case 779:

/* Line 1455 of yacc.c  */
#line 4047 "bison-parser.yy"
    {}
    break;

  case 782:

/* Line 1455 of yacc.c  */
#line 4056 "bison-parser.yy"
    {}
    break;

  case 783:

/* Line 1455 of yacc.c  */
#line 4057 "bison-parser.yy"
    {}
    break;

  case 785:

/* Line 1455 of yacc.c  */
#line 4062 "bison-parser.yy"
    {}
    break;

  case 786:

/* Line 1455 of yacc.c  */
#line 4066 "bison-parser.yy"
    {}
    break;

  case 787:

/* Line 1455 of yacc.c  */
#line 4067 "bison-parser.yy"
    {}
    break;

  case 788:

/* Line 1455 of yacc.c  */
#line 4071 "bison-parser.yy"
    {}
    break;

  case 789:

/* Line 1455 of yacc.c  */
#line 4072 "bison-parser.yy"
    {}
    break;

  case 790:

/* Line 1455 of yacc.c  */
#line 4073 "bison-parser.yy"
    {}
    break;

  case 791:

/* Line 1455 of yacc.c  */
#line 4078 "bison-parser.yy"
    {}
    break;

  case 792:

/* Line 1455 of yacc.c  */
#line 4080 "bison-parser.yy"
    {}
    break;

  case 793:

/* Line 1455 of yacc.c  */
#line 4085 "bison-parser.yy"
    { }
    break;

  case 794:

/* Line 1455 of yacc.c  */
#line 4086 "bison-parser.yy"
    { }
    break;

  case 795:

/* Line 1455 of yacc.c  */
#line 4091 "bison-parser.yy"
    { }
    break;

  case 796:

/* Line 1455 of yacc.c  */
#line 4092 "bison-parser.yy"
    { }
    break;

  case 798:

/* Line 1455 of yacc.c  */
#line 4098 "bison-parser.yy"
    { }
    break;

  case 799:

/* Line 1455 of yacc.c  */
#line 4118 "bison-parser.yy"
    {}
    break;

  case 800:

/* Line 1455 of yacc.c  */
#line 4122 "bison-parser.yy"
    {}
    break;

  case 801:

/* Line 1455 of yacc.c  */
#line 4124 "bison-parser.yy"
    {}
    break;

  case 802:

/* Line 1455 of yacc.c  */
#line 4129 "bison-parser.yy"
    {}
    break;

  case 803:

/* Line 1455 of yacc.c  */
#line 4131 "bison-parser.yy"
    {}
    break;

  case 804:

/* Line 1455 of yacc.c  */
#line 4136 "bison-parser.yy"
    {}
    break;

  case 805:

/* Line 1455 of yacc.c  */
#line 4138 "bison-parser.yy"
    {}
    break;

  case 806:

/* Line 1455 of yacc.c  */
#line 4143 "bison-parser.yy"
    {}
    break;

  case 807:

/* Line 1455 of yacc.c  */
#line 4145 "bison-parser.yy"
    {}
    break;

  case 808:

/* Line 1455 of yacc.c  */
#line 4151 "bison-parser.yy"
    {}
    break;

  case 809:

/* Line 1455 of yacc.c  */
#line 4153 "bison-parser.yy"
    {}
    break;

  case 810:

/* Line 1455 of yacc.c  */
#line 4155 "bison-parser.yy"
    {}
    break;

  case 811:

/* Line 1455 of yacc.c  */
#line 4159 "bison-parser.yy"
    {}
    break;

  case 812:

/* Line 1455 of yacc.c  */
#line 4160 "bison-parser.yy"
    {}
    break;

  case 813:

/* Line 1455 of yacc.c  */
#line 4169 "bison-parser.yy"
    {}
    break;

  case 814:

/* Line 1455 of yacc.c  */
#line 4171 "bison-parser.yy"
    {}
    break;

  case 815:

/* Line 1455 of yacc.c  */
#line 4176 "bison-parser.yy"
    {}
    break;

  case 816:

/* Line 1455 of yacc.c  */
#line 4180 "bison-parser.yy"
    {}
    break;

  case 817:

/* Line 1455 of yacc.c  */
#line 4182 "bison-parser.yy"
    {}
    break;

  case 818:

/* Line 1455 of yacc.c  */
#line 4187 "bison-parser.yy"
    {}
    break;

  case 819:

/* Line 1455 of yacc.c  */
#line 4189 "bison-parser.yy"
    {}
    break;

  case 820:

/* Line 1455 of yacc.c  */
#line 4191 "bison-parser.yy"
    {}
    break;

  case 821:

/* Line 1455 of yacc.c  */
#line 4199 "bison-parser.yy"
    {}
    break;

  case 822:

/* Line 1455 of yacc.c  */
#line 4204 "bison-parser.yy"
    {}
    break;

  case 823:

/* Line 1455 of yacc.c  */
#line 4208 "bison-parser.yy"
    {}
    break;

  case 824:

/* Line 1455 of yacc.c  */
#line 4209 "bison-parser.yy"
    {}
    break;

  case 825:

/* Line 1455 of yacc.c  */
#line 4213 "bison-parser.yy"
    {}
    break;

  case 826:

/* Line 1455 of yacc.c  */
#line 4214 "bison-parser.yy"
    {}
    break;

  case 827:

/* Line 1455 of yacc.c  */
#line 4215 "bison-parser.yy"
    {}
    break;

  case 828:

/* Line 1455 of yacc.c  */
#line 4216 "bison-parser.yy"
    {}
    break;

  case 829:

/* Line 1455 of yacc.c  */
#line 4217 "bison-parser.yy"
    {}
    break;

  case 830:

/* Line 1455 of yacc.c  */
#line 4218 "bison-parser.yy"
    {}
    break;

  case 831:

/* Line 1455 of yacc.c  */
#line 4219 "bison-parser.yy"
    {}
    break;

  case 832:

/* Line 1455 of yacc.c  */
#line 4220 "bison-parser.yy"
    {}
    break;

  case 833:

/* Line 1455 of yacc.c  */
#line 4225 "bison-parser.yy"
    {}
    break;

  case 834:

/* Line 1455 of yacc.c  */
#line 4230 "bison-parser.yy"
    {}
    break;

  case 835:

/* Line 1455 of yacc.c  */
#line 4234 "bison-parser.yy"
    {}
    break;

  case 836:

/* Line 1455 of yacc.c  */
#line 4235 "bison-parser.yy"
    {}
    break;

  case 837:

/* Line 1455 of yacc.c  */
#line 4243 "bison-parser.yy"
    {}
    break;

  case 838:

/* Line 1455 of yacc.c  */
#line 4247 "bison-parser.yy"
    {}
    break;

  case 839:

/* Line 1455 of yacc.c  */
#line 4249 "bison-parser.yy"
    {}
    break;

  case 840:

/* Line 1455 of yacc.c  */
#line 4254 "bison-parser.yy"
    {}
    break;

  case 841:

/* Line 1455 of yacc.c  */
#line 4259 "bison-parser.yy"
    {}
    break;

  case 842:

/* Line 1455 of yacc.c  */
#line 4264 "bison-parser.yy"
    {}
    break;

  case 843:

/* Line 1455 of yacc.c  */
#line 4269 "bison-parser.yy"
    {}
    break;

  case 844:

/* Line 1455 of yacc.c  */
#line 4274 "bison-parser.yy"
    {}
    break;

  case 845:

/* Line 1455 of yacc.c  */
#line 4276 "bison-parser.yy"
    {}
    break;

  case 846:

/* Line 1455 of yacc.c  */
#line 4281 "bison-parser.yy"
    {}
    break;

  case 847:

/* Line 1455 of yacc.c  */
#line 4286 "bison-parser.yy"
    {}
    break;

  case 848:

/* Line 1455 of yacc.c  */
#line 4291 "bison-parser.yy"
    {}
    break;

  case 849:

/* Line 1455 of yacc.c  */
#line 4296 "bison-parser.yy"
    {}
    break;

  case 850:

/* Line 1455 of yacc.c  */
#line 4298 "bison-parser.yy"
    {}
    break;

  case 851:

/* Line 1455 of yacc.c  */
#line 4303 "bison-parser.yy"
    {}
    break;

  case 852:

/* Line 1455 of yacc.c  */
#line 4308 "bison-parser.yy"
    {}
    break;

  case 853:

/* Line 1455 of yacc.c  */
#line 4313 "bison-parser.yy"
    {}
    break;

  case 854:

/* Line 1455 of yacc.c  */
#line 4322 "bison-parser.yy"
    {}
    break;

  case 855:

/* Line 1455 of yacc.c  */
#line 4326 "bison-parser.yy"
    {}
    break;

  case 857:

/* Line 1455 of yacc.c  */
#line 4332 "bison-parser.yy"
    {}
    break;

  case 858:

/* Line 1455 of yacc.c  */
#line 4334 "bison-parser.yy"
    {}
    break;

  case 859:

/* Line 1455 of yacc.c  */
#line 4336 "bison-parser.yy"
    {}
    break;

  case 860:

/* Line 1455 of yacc.c  */
#line 4340 "bison-parser.yy"
    {}
    break;

  case 861:

/* Line 1455 of yacc.c  */
#line 4341 "bison-parser.yy"
    {}
    break;

  case 862:

/* Line 1455 of yacc.c  */
#line 4345 "bison-parser.yy"
    {}
    break;

  case 863:

/* Line 1455 of yacc.c  */
#line 4350 "bison-parser.yy"
    {}
    break;

  case 864:

/* Line 1455 of yacc.c  */
#line 4355 "bison-parser.yy"
    {}
    break;

  case 865:

/* Line 1455 of yacc.c  */
#line 4357 "bison-parser.yy"
    {}
    break;

  case 866:

/* Line 1455 of yacc.c  */
#line 4362 "bison-parser.yy"
    {}
    break;

  case 867:

/* Line 1455 of yacc.c  */
#line 4364 "bison-parser.yy"
    {}
    break;

  case 868:

/* Line 1455 of yacc.c  */
#line 4369 "bison-parser.yy"
    {}
    break;

  case 869:

/* Line 1455 of yacc.c  */
#line 4371 "bison-parser.yy"
    {}
    break;

  case 870:

/* Line 1455 of yacc.c  */
#line 4377 "bison-parser.yy"
    {}
    break;

  case 871:

/* Line 1455 of yacc.c  */
#line 4379 "bison-parser.yy"
    {}
    break;

  case 872:

/* Line 1455 of yacc.c  */
#line 4393 "bison-parser.yy"
    {}
    break;

  case 873:

/* Line 1455 of yacc.c  */
#line 4395 "bison-parser.yy"
    {}
    break;

  case 874:

/* Line 1455 of yacc.c  */
#line 4400 "bison-parser.yy"
    {}
    break;

  case 875:

/* Line 1455 of yacc.c  */
#line 4404 "bison-parser.yy"
    {}
    break;

  case 876:

/* Line 1455 of yacc.c  */
#line 4405 "bison-parser.yy"
    {}
    break;

  case 877:

/* Line 1455 of yacc.c  */
#line 4414 "bison-parser.yy"
    {}
    break;

  case 878:

/* Line 1455 of yacc.c  */
#line 4421 "bison-parser.yy"
    {}
    break;

  case 879:

/* Line 1455 of yacc.c  */
#line 4425 "bison-parser.yy"
    {}
    break;

  case 881:

/* Line 1455 of yacc.c  */
#line 4431 "bison-parser.yy"
    {}
    break;

  case 882:

/* Line 1455 of yacc.c  */
#line 4435 "bison-parser.yy"
    {}
    break;

  case 883:

/* Line 1455 of yacc.c  */
#line 4436 "bison-parser.yy"
    {}
    break;

  case 884:

/* Line 1455 of yacc.c  */
#line 4440 "bison-parser.yy"
    {}
    break;

  case 885:

/* Line 1455 of yacc.c  */
#line 4441 "bison-parser.yy"
    {}
    break;

  case 886:

/* Line 1455 of yacc.c  */
#line 4442 "bison-parser.yy"
    {}
    break;

  case 887:

/* Line 1455 of yacc.c  */
#line 4443 "bison-parser.yy"
    {}
    break;

  case 888:

/* Line 1455 of yacc.c  */
#line 4447 "bison-parser.yy"
    {}
    break;

  case 889:

/* Line 1455 of yacc.c  */
#line 4448 "bison-parser.yy"
    {}
    break;

  case 890:

/* Line 1455 of yacc.c  */
#line 4453 "bison-parser.yy"
    {}
    break;

  case 891:

/* Line 1455 of yacc.c  */
#line 4459 "bison-parser.yy"
    {}
    break;

  case 892:

/* Line 1455 of yacc.c  */
#line 4464 "bison-parser.yy"
    {}
    break;

  case 893:

/* Line 1455 of yacc.c  */
#line 4466 "bison-parser.yy"
    {}
    break;

  case 894:

/* Line 1455 of yacc.c  */
#line 4471 "bison-parser.yy"
    {}
    break;

  case 895:

/* Line 1455 of yacc.c  */
#line 4473 "bison-parser.yy"
    {}
    break;

  case 896:

/* Line 1455 of yacc.c  */
#line 4478 "bison-parser.yy"
    {
	}
    break;

  case 897:

/* Line 1455 of yacc.c  */
#line 4481 "bison-parser.yy"
    {
	}
    break;

  case 898:

/* Line 1455 of yacc.c  */
#line 4484 "bison-parser.yy"
    {
	}
    break;

  case 899:

/* Line 1455 of yacc.c  */
#line 4490 "bison-parser.yy"
    {}
    break;

  case 900:

/* Line 1455 of yacc.c  */
#line 4495 "bison-parser.yy"
    {}
    break;

  case 901:

/* Line 1455 of yacc.c  */
#line 4497 "bison-parser.yy"
    {}
    break;

  case 902:

/* Line 1455 of yacc.c  */
#line 4499 "bison-parser.yy"
    {}
    break;

  case 903:

/* Line 1455 of yacc.c  */
#line 4503 "bison-parser.yy"
    {}
    break;

  case 904:

/* Line 1455 of yacc.c  */
#line 4505 "bison-parser.yy"
    {}
    break;

  case 905:

/* Line 1455 of yacc.c  */
#line 4514 "bison-parser.yy"
    {}
    break;

  case 906:

/* Line 1455 of yacc.c  */
#line 4519 "bison-parser.yy"
    {}
    break;

  case 907:

/* Line 1455 of yacc.c  */
#line 4524 "bison-parser.yy"
    {}
    break;

  case 908:

/* Line 1455 of yacc.c  */
#line 4529 "bison-parser.yy"
    {}
    break;

  case 909:

/* Line 1455 of yacc.c  */
#line 4531 "bison-parser.yy"
    {}
    break;

  case 910:

/* Line 1455 of yacc.c  */
#line 4533 "bison-parser.yy"
    {}
    break;

  case 911:

/* Line 1455 of yacc.c  */
#line 4537 "bison-parser.yy"
    {}
    break;

  case 912:

/* Line 1455 of yacc.c  */
#line 4539 "bison-parser.yy"
    {}
    break;

  case 913:

/* Line 1455 of yacc.c  */
#line 4543 "bison-parser.yy"
    {}
    break;

  case 914:

/* Line 1455 of yacc.c  */
#line 4544 "bison-parser.yy"
    {}
    break;

  case 915:

/* Line 1455 of yacc.c  */
#line 4545 "bison-parser.yy"
    {}
    break;

  case 916:

/* Line 1455 of yacc.c  */
#line 4546 "bison-parser.yy"
    {}
    break;

  case 917:

/* Line 1455 of yacc.c  */
#line 4547 "bison-parser.yy"
    {}
    break;

  case 918:

/* Line 1455 of yacc.c  */
#line 4548 "bison-parser.yy"
    {}
    break;

  case 919:

/* Line 1455 of yacc.c  */
#line 4549 "bison-parser.yy"
    {}
    break;

  case 920:

/* Line 1455 of yacc.c  */
#line 4550 "bison-parser.yy"
    {}
    break;

  case 921:

/* Line 1455 of yacc.c  */
#line 4551 "bison-parser.yy"
    {}
    break;

  case 922:

/* Line 1455 of yacc.c  */
#line 4552 "bison-parser.yy"
    {}
    break;

  case 923:

/* Line 1455 of yacc.c  */
#line 4553 "bison-parser.yy"
    {}
    break;

  case 924:

/* Line 1455 of yacc.c  */
#line 4554 "bison-parser.yy"
    {}
    break;

  case 925:

/* Line 1455 of yacc.c  */
#line 4555 "bison-parser.yy"
    {}
    break;

  case 926:

/* Line 1455 of yacc.c  */
#line 4563 "bison-parser.yy"
    {}
    break;

  case 927:

/* Line 1455 of yacc.c  */
#line 4564 "bison-parser.yy"
    {}
    break;

  case 928:

/* Line 1455 of yacc.c  */
#line 4568 "bison-parser.yy"
    {}
    break;

  case 929:

/* Line 1455 of yacc.c  */
#line 4569 "bison-parser.yy"
    {}
    break;

  case 930:

/* Line 1455 of yacc.c  */
#line 4573 "bison-parser.yy"
    {}
    break;

  case 931:

/* Line 1455 of yacc.c  */
#line 4578 "bison-parser.yy"
    {}
    break;

  case 932:

/* Line 1455 of yacc.c  */
#line 4582 "bison-parser.yy"
    {}
    break;

  case 936:

/* Line 1455 of yacc.c  */
#line 4599 "bison-parser.yy"
    {
        }
    break;

  case 940:

/* Line 1455 of yacc.c  */
#line 4611 "bison-parser.yy"
    {
	}
    break;

  case 941:

/* Line 1455 of yacc.c  */
#line 4617 "bison-parser.yy"
    {
	}
    break;

  case 942:

/* Line 1455 of yacc.c  */
#line 4620 "bison-parser.yy"
    {
	}
    break;

  case 954:

/* Line 1455 of yacc.c  */
#line 4643 "bison-parser.yy"
    {}
    break;

  case 955:

/* Line 1455 of yacc.c  */
#line 4645 "bison-parser.yy"
    {}
    break;

  case 956:

/* Line 1455 of yacc.c  */
#line 4647 "bison-parser.yy"
    {}
    break;

  case 957:

/* Line 1455 of yacc.c  */
#line 4650 "bison-parser.yy"
    {}
    break;

  case 958:

/* Line 1455 of yacc.c  */
#line 4653 "bison-parser.yy"
    {}
    break;

  case 961:

/* Line 1455 of yacc.c  */
#line 4662 "bison-parser.yy"
    {}
    break;

  case 962:

/* Line 1455 of yacc.c  */
#line 4663 "bison-parser.yy"
    {}
    break;

  case 963:

/* Line 1455 of yacc.c  */
#line 4667 "bison-parser.yy"
    {}
    break;

  case 964:

/* Line 1455 of yacc.c  */
#line 4668 "bison-parser.yy"
    {}
    break;

  case 965:

/* Line 1455 of yacc.c  */
#line 4672 "bison-parser.yy"
    {}
    break;

  case 966:

/* Line 1455 of yacc.c  */
#line 4673 "bison-parser.yy"
    {}
    break;

  case 967:

/* Line 1455 of yacc.c  */
#line 4677 "bison-parser.yy"
    {}
    break;

  case 968:

/* Line 1455 of yacc.c  */
#line 4678 "bison-parser.yy"
    {}
    break;

  case 969:

/* Line 1455 of yacc.c  */
#line 4682 "bison-parser.yy"
    {}
    break;

  case 970:

/* Line 1455 of yacc.c  */
#line 4683 "bison-parser.yy"
    {}
    break;

  case 971:

/* Line 1455 of yacc.c  */
#line 4701 "bison-parser.yy"
    {}
    break;

  case 972:

/* Line 1455 of yacc.c  */
#line 4707 "bison-parser.yy"
    {}
    break;

  case 973:

/* Line 1455 of yacc.c  */
#line 4712 "bison-parser.yy"
    {}
    break;

  case 974:

/* Line 1455 of yacc.c  */
#line 4717 "bison-parser.yy"
    {}
    break;

  case 975:

/* Line 1455 of yacc.c  */
#line 4719 "bison-parser.yy"
    {}
    break;

  case 976:

/* Line 1455 of yacc.c  */
#line 4721 "bison-parser.yy"
    {}
    break;

  case 977:

/* Line 1455 of yacc.c  */
#line 4729 "bison-parser.yy"
    {}
    break;

  case 979:

/* Line 1455 of yacc.c  */
#line 4734 "bison-parser.yy"
    {}
    break;

  case 980:

/* Line 1455 of yacc.c  */
#line 4738 "bison-parser.yy"
    {}
    break;

  case 982:

/* Line 1455 of yacc.c  */
#line 4743 "bison-parser.yy"
    {}
    break;

  case 983:

/* Line 1455 of yacc.c  */
#line 4748 "bison-parser.yy"
    {}
    break;

  case 984:

/* Line 1455 of yacc.c  */
#line 4751 "bison-parser.yy"
    {}
    break;

  case 985:

/* Line 1455 of yacc.c  */
#line 4756 "bison-parser.yy"
    {}
    break;

  case 986:

/* Line 1455 of yacc.c  */
#line 4759 "bison-parser.yy"
    {}
    break;

  case 987:

/* Line 1455 of yacc.c  */
#line 4762 "bison-parser.yy"
    {}
    break;

  case 988:

/* Line 1455 of yacc.c  */
#line 4766 "bison-parser.yy"
    {}
    break;

  case 989:

/* Line 1455 of yacc.c  */
#line 4767 "bison-parser.yy"
    {}
    break;

  case 990:

/* Line 1455 of yacc.c  */
#line 4772 "bison-parser.yy"
    {}
    break;

  case 991:

/* Line 1455 of yacc.c  */
#line 4775 "bison-parser.yy"
    {}
    break;

  case 992:

/* Line 1455 of yacc.c  */
#line 4778 "bison-parser.yy"
    {}
    break;

  case 993:

/* Line 1455 of yacc.c  */
#line 4781 "bison-parser.yy"
    {}
    break;

  case 994:

/* Line 1455 of yacc.c  */
#line 4786 "bison-parser.yy"
    {}
    break;

  case 995:

/* Line 1455 of yacc.c  */
#line 4791 "bison-parser.yy"
    {}
    break;

  case 996:

/* Line 1455 of yacc.c  */
#line 4795 "bison-parser.yy"
    {}
    break;

  case 997:

/* Line 1455 of yacc.c  */
#line 4797 "bison-parser.yy"
    {}
    break;

  case 998:

/* Line 1455 of yacc.c  */
#line 4802 "bison-parser.yy"
    {}
    break;

  case 999:

/* Line 1455 of yacc.c  */
#line 4806 "bison-parser.yy"
    {}
    break;

  case 1000:

/* Line 1455 of yacc.c  */
#line 4808 "bison-parser.yy"
    {}
    break;

  case 1001:

/* Line 1455 of yacc.c  */
#line 4813 "bison-parser.yy"
    {}
    break;

  case 1002:

/* Line 1455 of yacc.c  */
#line 4817 "bison-parser.yy"
    {}
    break;

  case 1003:

/* Line 1455 of yacc.c  */
#line 4818 "bison-parser.yy"
    {}
    break;

  case 1004:

/* Line 1455 of yacc.c  */
#line 4822 "bison-parser.yy"
    {}
    break;

  case 1005:

/* Line 1455 of yacc.c  */
#line 4823 "bison-parser.yy"
    {}
    break;

  case 1006:

/* Line 1455 of yacc.c  */
#line 4827 "bison-parser.yy"
    {}
    break;

  case 1007:

/* Line 1455 of yacc.c  */
#line 4828 "bison-parser.yy"
    {}
    break;

  case 1008:

/* Line 1455 of yacc.c  */
#line 4834 "bison-parser.yy"
    {}
    break;

  case 1009:

/* Line 1455 of yacc.c  */
#line 4839 "bison-parser.yy"
    {}
    break;

  case 1010:

/* Line 1455 of yacc.c  */
#line 4844 "bison-parser.yy"
    {}
    break;

  case 1011:

/* Line 1455 of yacc.c  */
#line 4846 "bison-parser.yy"
    {}
    break;

  case 1012:

/* Line 1455 of yacc.c  */
#line 4851 "bison-parser.yy"
    {
	}
    break;

  case 1013:

/* Line 1455 of yacc.c  */
#line 4856 "bison-parser.yy"
    {
	}
    break;

  case 1026:

/* Line 1455 of yacc.c  */
#line 4883 "bison-parser.yy"
    {}
    break;

  case 1027:

/* Line 1455 of yacc.c  */
#line 4888 "bison-parser.yy"
    {}
    break;

  case 1028:

/* Line 1455 of yacc.c  */
#line 4891 "bison-parser.yy"
    {}
    break;

  case 1029:

/* Line 1455 of yacc.c  */
#line 4896 "bison-parser.yy"
    {}
    break;

  case 1034:

/* Line 1455 of yacc.c  */
#line 4910 "bison-parser.yy"
    {}
    break;

  case 1035:

/* Line 1455 of yacc.c  */
#line 4911 "bison-parser.yy"
    {}
    break;

  case 1036:

/* Line 1455 of yacc.c  */
#line 4916 "bison-parser.yy"
    {}
    break;

  case 1037:

/* Line 1455 of yacc.c  */
#line 4920 "bison-parser.yy"
    {}
    break;

  case 1038:

/* Line 1455 of yacc.c  */
#line 4922 "bison-parser.yy"
    {}
    break;

  case 1039:

/* Line 1455 of yacc.c  */
#line 4927 "bison-parser.yy"
    {}
    break;

  case 1040:

/* Line 1455 of yacc.c  */
#line 4935 "bison-parser.yy"
    {}
    break;

  case 1041:

/* Line 1455 of yacc.c  */
#line 4939 "bison-parser.yy"
    {}
    break;

  case 1042:

/* Line 1455 of yacc.c  */
#line 4941 "bison-parser.yy"
    {}
    break;

  case 1043:

/* Line 1455 of yacc.c  */
#line 4945 "bison-parser.yy"
    {}
    break;

  case 1044:

/* Line 1455 of yacc.c  */
#line 4946 "bison-parser.yy"
    {}
    break;

  case 1045:

/* Line 1455 of yacc.c  */
#line 4947 "bison-parser.yy"
    {}
    break;

  case 1046:

/* Line 1455 of yacc.c  */
#line 4948 "bison-parser.yy"
    {}
    break;

  case 1047:

/* Line 1455 of yacc.c  */
#line 4949 "bison-parser.yy"
    {}
    break;

  case 1048:

/* Line 1455 of yacc.c  */
#line 4950 "bison-parser.yy"
    {}
    break;

  case 1049:

/* Line 1455 of yacc.c  */
#line 4951 "bison-parser.yy"
    {}
    break;

  case 1050:

/* Line 1455 of yacc.c  */
#line 4952 "bison-parser.yy"
    {}
    break;

  case 1051:

/* Line 1455 of yacc.c  */
#line 4953 "bison-parser.yy"
    {}
    break;

  case 1052:

/* Line 1455 of yacc.c  */
#line 4954 "bison-parser.yy"
    {}
    break;

  case 1053:

/* Line 1455 of yacc.c  */
#line 4955 "bison-parser.yy"
    {}
    break;

  case 1054:

/* Line 1455 of yacc.c  */
#line 4956 "bison-parser.yy"
    {}
    break;

  case 1055:

/* Line 1455 of yacc.c  */
#line 4957 "bison-parser.yy"
    {}
    break;

  case 1056:

/* Line 1455 of yacc.c  */
#line 4963 "bison-parser.yy"
    {}
    break;

  case 1057:

/* Line 1455 of yacc.c  */
#line 4968 "bison-parser.yy"
    {}
    break;

  case 1058:

/* Line 1455 of yacc.c  */
#line 4973 "bison-parser.yy"
    {}
    break;

  case 1059:

/* Line 1455 of yacc.c  */
#line 4975 "bison-parser.yy"
    {}
    break;

  case 1060:

/* Line 1455 of yacc.c  */
#line 4980 "bison-parser.yy"
    {}
    break;

  case 1061:

/* Line 1455 of yacc.c  */
#line 4982 "bison-parser.yy"
    {}
    break;

  case 1062:

/* Line 1455 of yacc.c  */
#line 4990 "bison-parser.yy"
    {}
    break;

  case 1063:

/* Line 1455 of yacc.c  */
#line 4995 "bison-parser.yy"
    {}
    break;

  case 1064:

/* Line 1455 of yacc.c  */
#line 5000 "bison-parser.yy"
    {}
    break;

  case 1065:

/* Line 1455 of yacc.c  */
#line 5002 "bison-parser.yy"
    {}
    break;

  case 1066:

/* Line 1455 of yacc.c  */
#line 5008 "bison-parser.yy"
    {}
    break;

  case 1067:

/* Line 1455 of yacc.c  */
#line 5012 "bison-parser.yy"
    {}
    break;

  case 1068:

/* Line 1455 of yacc.c  */
#line 5013 "bison-parser.yy"
    {}
    break;

  case 1069:

/* Line 1455 of yacc.c  */
#line 5017 "bison-parser.yy"
    {}
    break;

  case 1070:

/* Line 1455 of yacc.c  */
#line 5019 "bison-parser.yy"
    {}
    break;

  case 1071:

/* Line 1455 of yacc.c  */
#line 5023 "bison-parser.yy"
    {}
    break;

  case 1072:

/* Line 1455 of yacc.c  */
#line 5028 "bison-parser.yy"
    {}
    break;

  case 1073:

/* Line 1455 of yacc.c  */
#line 5031 "bison-parser.yy"
    {}
    break;

  case 1074:

/* Line 1455 of yacc.c  */
#line 5035 "bison-parser.yy"
    {}
    break;

  case 1075:

/* Line 1455 of yacc.c  */
#line 5036 "bison-parser.yy"
    {}
    break;

  case 1076:

/* Line 1455 of yacc.c  */
#line 5040 "bison-parser.yy"
    {}
    break;

  case 1077:

/* Line 1455 of yacc.c  */
#line 5042 "bison-parser.yy"
    {}
    break;

  case 1078:

/* Line 1455 of yacc.c  */
#line 5047 "bison-parser.yy"
    {}
    break;

  case 1079:

/* Line 1455 of yacc.c  */
#line 5052 "bison-parser.yy"
    {}
    break;

  case 1080:

/* Line 1455 of yacc.c  */
#line 5056 "bison-parser.yy"
    {}
    break;

  case 1081:

/* Line 1455 of yacc.c  */
#line 5057 "bison-parser.yy"
    {}
    break;

  case 1082:

/* Line 1455 of yacc.c  */
#line 5061 "bison-parser.yy"
    {}
    break;

  case 1083:

/* Line 1455 of yacc.c  */
#line 5065 "bison-parser.yy"
    {}
    break;

  case 1084:

/* Line 1455 of yacc.c  */
#line 5066 "bison-parser.yy"
    {}
    break;

  case 1085:

/* Line 1455 of yacc.c  */
#line 5071 "bison-parser.yy"
    {}
    break;

  case 1086:

/* Line 1455 of yacc.c  */
#line 5076 "bison-parser.yy"
    {}
    break;

  case 1087:

/* Line 1455 of yacc.c  */
#line 5081 "bison-parser.yy"
    {}
    break;

  case 1088:

/* Line 1455 of yacc.c  */
#line 5085 "bison-parser.yy"
    {}
    break;

  case 1090:

/* Line 1455 of yacc.c  */
#line 5091 "bison-parser.yy"
    {}
    break;

  case 1091:

/* Line 1455 of yacc.c  */
#line 5095 "bison-parser.yy"
    {}
    break;

  case 1092:

/* Line 1455 of yacc.c  */
#line 5096 "bison-parser.yy"
    {}
    break;

  case 1093:

/* Line 1455 of yacc.c  */
#line 5097 "bison-parser.yy"
    {}
    break;

  case 1094:

/* Line 1455 of yacc.c  */
#line 5099 "bison-parser.yy"
    {}
    break;

  case 1095:

/* Line 1455 of yacc.c  */
#line 5104 "bison-parser.yy"
    {}
    break;

  case 1096:

/* Line 1455 of yacc.c  */
#line 5109 "bison-parser.yy"
    {}
    break;

  case 1097:

/* Line 1455 of yacc.c  */
#line 5113 "bison-parser.yy"
    {}
    break;

  case 1098:

/* Line 1455 of yacc.c  */
#line 5114 "bison-parser.yy"
    {}
    break;

  case 1099:

/* Line 1455 of yacc.c  */
#line 5118 "bison-parser.yy"
    {}
    break;

  case 1100:

/* Line 1455 of yacc.c  */
#line 5119 "bison-parser.yy"
    {}
    break;

  case 1101:

/* Line 1455 of yacc.c  */
#line 5123 "bison-parser.yy"
    {}
    break;

  case 1102:

/* Line 1455 of yacc.c  */
#line 5124 "bison-parser.yy"
    {}
    break;

  case 1103:

/* Line 1455 of yacc.c  */
#line 5133 "bison-parser.yy"
    {}
    break;

  case 1104:

/* Line 1455 of yacc.c  */
#line 5136 "bison-parser.yy"
    {}
    break;

  case 1105:

/* Line 1455 of yacc.c  */
#line 5140 "bison-parser.yy"
    {}
    break;

  case 1106:

/* Line 1455 of yacc.c  */
#line 5144 "bison-parser.yy"
    {}
    break;

  case 1107:

/* Line 1455 of yacc.c  */
#line 5148 "bison-parser.yy"
    {}
    break;

  case 1108:

/* Line 1455 of yacc.c  */
#line 5149 "bison-parser.yy"
    {}
    break;

  case 1110:

/* Line 1455 of yacc.c  */
#line 5154 "bison-parser.yy"
    {}
    break;

  case 1111:

/* Line 1455 of yacc.c  */
#line 5158 "bison-parser.yy"
    {}
    break;

  case 1112:

/* Line 1455 of yacc.c  */
#line 5159 "bison-parser.yy"
    {}
    break;

  case 1113:

/* Line 1455 of yacc.c  */
#line 5164 "bison-parser.yy"
    {}
    break;

  case 1114:

/* Line 1455 of yacc.c  */
#line 5167 "bison-parser.yy"
    {}
    break;

  case 1115:

/* Line 1455 of yacc.c  */
#line 5171 "bison-parser.yy"
    {}
    break;

  case 1116:

/* Line 1455 of yacc.c  */
#line 5172 "bison-parser.yy"
    {}
    break;

  case 1117:

/* Line 1455 of yacc.c  */
#line 5176 "bison-parser.yy"
    {}
    break;

  case 1118:

/* Line 1455 of yacc.c  */
#line 5177 "bison-parser.yy"
    {}
    break;

  case 1119:

/* Line 1455 of yacc.c  */
#line 5178 "bison-parser.yy"
    {}
    break;

  case 1120:

/* Line 1455 of yacc.c  */
#line 5183 "bison-parser.yy"
    {}
    break;

  case 1121:

/* Line 1455 of yacc.c  */
#line 5188 "bison-parser.yy"
    {}
    break;

  case 1122:

/* Line 1455 of yacc.c  */
#line 5193 "bison-parser.yy"
    {}
    break;

  case 1123:

/* Line 1455 of yacc.c  */
#line 5197 "bison-parser.yy"
    {}
    break;

  case 1124:

/* Line 1455 of yacc.c  */
#line 5198 "bison-parser.yy"
    {}
    break;

  case 1125:

/* Line 1455 of yacc.c  */
#line 5199 "bison-parser.yy"
    {}
    break;

  case 1126:

/* Line 1455 of yacc.c  */
#line 5207 "bison-parser.yy"
    {}
    break;

  case 1127:

/* Line 1455 of yacc.c  */
#line 5211 "bison-parser.yy"
    {}
    break;

  case 1128:

/* Line 1455 of yacc.c  */
#line 5213 "bison-parser.yy"
    {}
    break;

  case 1129:

/* Line 1455 of yacc.c  */
#line 5215 "bison-parser.yy"
    {}
    break;

  case 1130:

/* Line 1455 of yacc.c  */
#line 5220 "bison-parser.yy"
    {}
    break;

  case 1131:

/* Line 1455 of yacc.c  */
#line 5222 "bison-parser.yy"
    {}
    break;

  case 1132:

/* Line 1455 of yacc.c  */
#line 5227 "bison-parser.yy"
    {}
    break;

  case 1133:

/* Line 1455 of yacc.c  */
#line 5229 "bison-parser.yy"
    {}
    break;

  case 1134:

/* Line 1455 of yacc.c  */
#line 5231 "bison-parser.yy"
    {}
    break;

  case 1135:

/* Line 1455 of yacc.c  */
#line 5235 "bison-parser.yy"
    {}
    break;

  case 1136:

/* Line 1455 of yacc.c  */
#line 5236 "bison-parser.yy"
    {}
    break;



/* Line 1455 of yacc.c  */
#line 11314 "bison-parser.cc"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
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
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 5240 "bison-parser.yy"


vaul_error_printer::vaul_error_printer ()
{
  log = stderr;
  n_errors = 0;
}

pIIR_ExpressionList vaul_parser::no_sens_list = NULL;

vaul_parser::vaul_parser (vaul_lexer *l)
{
  init_fire_chunk ();
  init_vaul_chunk ();
  init_vaulgens_chunk ();

  lex = l;
  lex->set_printer (this, log);
  lex->set_creator (this);
  cur_du = NULL;
  eof = false;

  if (no_sens_list == NULL)
    {
      no_sens_list = mIIR_ExpressionList (pIIR_PosInfo(NULL), NULL, NULL);
      tree_protect (no_sens_list);
    }
  consumer = NULL;

  options = default_options;

  //yydebug = 1;
}

vaul_parser::~vaul_parser ()
{
}

vaul_design_unit *vaul_current_design_unit;

vaul_parser_options::vaul_parser_options ()
{
  debug = false;
  fullnames = false;
  allow_invisible_default_bindings_from_work = false;
  nocache = false;
  skip_bodies = false;
}

vaul_parser_options vaul_parser::default_options;

vaul_design_unit *
vaul_parser::parse (vaul_pool *p)
{
  vaul_design_unit *prev_cur_du;
  pool = p;

  lex->skip_bodies (options.skip_bodies);

  // We block the garbage collector while creating the graph because
  // we have unprotected nodes floating around.  When `finish' returns,
  // all nodes that we care about have been linked into the design
  // unit, so it is safe to collect the unneeded ones.

  // Additionally, the parser is now careful to have all live nodes
  // safely plugged into the design unit between concurrent
  // statements.  This allows us to collect the garbage after each
  // concurrent statement has been parsed.
  
  // XXX - extend this to declarations and sequential statements.

  tree_block_garbage_collection ();  
  prev_cur_du = vaul_current_design_unit;
  XXX_seen = false;
  init ();
  bison_parse ();
  if (XXX_seen)
    n_errors++;
  vaul_design_unit *du = finish ();
  vaul_current_design_unit = prev_cur_du;
//    if (flags & VAUL_PARSER_VERBOSE)
//      fprintf (stderr, "after parse of %s: ", du? du->get_name () : "EOF");
  tree_collect_garbage ();
  tree_unblock_garbage_collection ();

  if (du && n_errors > 0)
    du->set_error (vhdlerr_errors_detected, "%d errors", n_errors);

  // if (flags & VAUL_PARSER_VERBOSE)
  //   hist.print ();

  return du;
}

int vaul_parser_gc_thresh = 100000;

void
vaul_parser::collect ()
{
  tree_collect_garbage ();
  tree_unblock_garbage_collection ();
  tree_block_garbage_collection ();
}

void
vaul_parser::clear_errors ()
{
  n_errors = 0;
}

