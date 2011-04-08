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
     WORD = 258,
     STRING = 259,
     _FLOAT = 260,
     INTEGER = 261,
     ABORT = 262,
     APROPOS = 263,
     BREAK = 264,
     CHDIR = 265,
     DEFINE = 266,
     DELETE = 267,
     DO = 268,
     EDIT = 269,
     ELSE = 270,
     FOREACH = 271,
     HELP = 272,
     HISTORY = 273,
     IF = 274,
     KEY = 275,
     LIST = 276,
     LOCAL = 277,
     MACRO = 278,
     OVERLOAD = 279,
     PRINT = 280,
     PROMPT = 281,
     QUIT = 282,
     READ = 283,
     RESTORE = 284,
     SAVE = 285,
     SET = 286,
     SNARK = 287,
     STANDARD = 288,
     TERMTYPE = 289,
     VERBOSE = 290,
     WHILE = 291,
     WRITE = 292,
     ANGLE = 293,
     ASPECT = 294,
     AXIS = 295,
     BOX = 296,
     CONNECT = 297,
     CONTOUR = 298,
     CTYPE = 299,
     CURSOR = 300,
     DATA = 301,
     DEVICE = 302,
     DOT = 303,
     DRAW = 304,
     DITHER = 305,
     ERASE = 306,
     ERRORBAR = 307,
     EXPAND = 308,
     FORMAT = 309,
     GRID = 310,
     HISTOGRAM = 311,
     IMAGE = 312,
     LABEL = 313,
     LEVELS = 314,
     LIMITS = 315,
     LINES = 316,
     LOCATION = 317,
     LTYPE = 318,
     LWEIGHT = 319,
     MINMAX = 320,
     NOTATION = 321,
     PAGE = 322,
     POINTS = 323,
     PTYPE = 324,
     PUTLABEL = 325,
     RANGE = 326,
     RELOCATE = 327,
     RETURN = 328,
     SHADE = 329,
     SORT = 330,
     SPLINE = 331,
     SURFACE = 332,
     TABLE = 333,
     TICKSIZE = 334,
     USER = 335,
     VIEWPOINT = 336,
     WHATIS = 337,
     WINDOW = 338,
     XLABEL = 339,
     YLABEL = 340,
     FLOAT = 341,
     META = 342,
     OLD = 343,
     ROW = 344,
     ABS = 345,
     ACOS = 346,
     ASIN = 347,
     ATAN = 348,
     ATAN2 = 349,
     CONCAT = 350,
     COS = 351,
     DIMEN = 352,
     EXP = 353,
     FFT = 354,
     GAMMA = 355,
     INT = 356,
     LG = 357,
     LN = 358,
     PI = 359,
     RANDOM = 360,
     SIN = 361,
     SQRT = 362,
     SUM = 363,
     TAN = 364,
     LEFT_SHIFT_SYMBOL = 365,
     RIGHT_SHIFT_SYMBOL = 366,
     POWER_SYMBOL = 367,
     ATOF = 368,
     INDEX = 369,
     LENGTH = 370,
     SPRINTF = 371,
     STRLEN = 372,
     SUBSTR = 373,
     OR = 374,
     AND = 375,
     UNARY = 376
   };
#endif
#define WORD 258
#define STRING 259
#define _FLOAT 260
#define INTEGER 261
#define ABORT 262
#define APROPOS 263
#define BREAK 264
#define CHDIR 265
#define DEFINE 266
#define DELETE 267
#define DO 268
#define EDIT 269
#define ELSE 270
#define FOREACH 271
#define HELP 272
#define HISTORY 273
#define IF 274
#define KEY 275
#define LIST 276
#define LOCAL 277
#define MACRO 278
#define OVERLOAD 279
#define PRINT 280
#define PROMPT 281
#define QUIT 282
#define READ 283
#define RESTORE 284
#define SAVE 285
#define SET 286
#define SNARK 287
#define STANDARD 288
#define TERMTYPE 289
#define VERBOSE 290
#define WHILE 291
#define WRITE 292
#define ANGLE 293
#define ASPECT 294
#define AXIS 295
#define BOX 296
#define CONNECT 297
#define CONTOUR 298
#define CTYPE 299
#define CURSOR 300
#define DATA 301
#define DEVICE 302
#define DOT 303
#define DRAW 304
#define DITHER 305
#define ERASE 306
#define ERRORBAR 307
#define EXPAND 308
#define FORMAT 309
#define GRID 310
#define HISTOGRAM 311
#define IMAGE 312
#define LABEL 313
#define LEVELS 314
#define LIMITS 315
#define LINES 316
#define LOCATION 317
#define LTYPE 318
#define LWEIGHT 319
#define MINMAX 320
#define NOTATION 321
#define PAGE 322
#define POINTS 323
#define PTYPE 324
#define PUTLABEL 325
#define RANGE 326
#define RELOCATE 327
#define RETURN 328
#define SHADE 329
#define SORT 330
#define SPLINE 331
#define SURFACE 332
#define TABLE 333
#define TICKSIZE 334
#define USER 335
#define VIEWPOINT 336
#define WHATIS 337
#define WINDOW 338
#define XLABEL 339
#define YLABEL 340
#define FLOAT 341
#define META 342
#define OLD 343
#define ROW 344
#define ABS 345
#define ACOS 346
#define ASIN 347
#define ATAN 348
#define ATAN2 349
#define CONCAT 350
#define COS 351
#define DIMEN 352
#define EXP 353
#define FFT 354
#define GAMMA 355
#define INT 356
#define LG 357
#define LN 358
#define PI 359
#define RANDOM 360
#define SIN 361
#define SQRT 362
#define SUM 363
#define TAN 364
#define LEFT_SHIFT_SYMBOL 365
#define RIGHT_SHIFT_SYMBOL 366
#define POWER_SYMBOL 367
#define ATOF 368
#define INDEX 369
#define LENGTH 370
#define SPRINTF 371
#define STRLEN 372
#define SUBSTR 373
#define OR 374
#define AND 375
#define UNARY 376




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif





