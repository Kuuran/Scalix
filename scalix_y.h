/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_SCALIX_Y_H_INCLUDED
# define YY_YY_SCALIX_Y_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    THEN = 259,
    ELSE = 260,
    ADD = 261,
    SUB = 262,
    MUL = 263,
    DIV = 264,
    AFFECT = 265,
    SCOL = 266,
    AND = 267,
    BRACO = 268,
    BRACC = 269,
    COMA = 270,
    CBRACO = 271,
    CBRACC = 272,
    CLASS = 273,
    EXT = 274,
    IS = 275,
    OBJ = 276,
    NEW = 277,
    OVR = 278,
    DEF = 279,
    STRG = 280,
    RETURN = 281,
    POINT = 282,
    VAR = 283,
    COL = 284,
    ID = 285,
    IDCLASS = 286,
    CST = 287,
    RELOP = 288,
    unary = 289
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SCALIX_Y_H_INCLUDED  */
