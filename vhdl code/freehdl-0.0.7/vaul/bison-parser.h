
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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



