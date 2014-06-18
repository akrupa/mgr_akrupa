
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
     EXIT = 258,
     SAVE_DIR = 259,
     TABLE_NAME = 260,
     BASE_NAME = 261,
     USER_NAME = 262,
     MAKE = 263,
     NUMBER = 264,
     IDENTIFIER = 265,
     CREATE = 266,
     KEY = 267,
     FACT = 268,
     DIMENSION = 269,
     SITE_WEB = 270,
     SITE_WEB_ADDRESS = 271,
     LEFTPARENTHESIS = 272,
     RIGHTPARENTHESIS = 273,
     SEMICOLON = 274,
     COMMA = 275,
     LEX_ERROR = 276
   };
#endif
/* Tokens.  */
#define EXIT 258
#define SAVE_DIR 259
#define TABLE_NAME 260
#define BASE_NAME 261
#define USER_NAME 262
#define MAKE 263
#define NUMBER 264
#define IDENTIFIER 265
#define CREATE 266
#define KEY 267
#define FACT 268
#define DIMENSION 269
#define SITE_WEB 270
#define SITE_WEB_ADDRESS 271
#define LEFTPARENTHESIS 272
#define RIGHTPARENTHESIS 273
#define SEMICOLON 274
#define COMMA 275
#define LEX_ERROR 276




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


