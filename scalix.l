Digit [0-9]
LetterMaj [A-Z]
LetterMin [a-z]
Letter ({LetterMaj}|{LetterMin})
LD  ({Letter}|{Digit})
Delim [ \n\t\r]
TSG [^{GUIL}]*
GUIL ["]

TSE [^*]
ETOILE "*"
TSES [^*/]
CommentInterieur ({TSE}|({ETOILE}+{TSES}))*{ETOILE}*
CommentLigne "//"[^\n]*



%{
#include "scalix.h"
#include "scalix_y.h"	/* produit par Bison */
#include <string.h>	/* pour strdup */

extern char *strdup(const char *s);
extern void setError(int code);

extern YYSTYPE yylval;
extern int errorCode;


void lexError(char c) {
  fprintf(stderr, "Error: Skipping invalid character '%c' on line %d\n",
          c, yylineno);
  setError(LEXICAL_ERROR);
}


/* les codes symboliques pour les unites lexicales (CST, ID, ADD, ...) sont
 * definis dans tp_y.h et corespondent aux tokens dans tp.y
 * Des etiquettes symboliques qui ne correspondent pas a des tokens sont aussi
 * definies dans tp.h
 *
 * Les "return" qui apparaissent dans les actions associees aux expressions
 * reguleres peuvent renvoyer:
 * - soit le code symbolique d'une U.L.
 * - soit un simple caractere
 * L'eventuelle partie "valeur" de l'U.L. doit etre stockee dans une des
 * variantes de la variable yylval (definie comme etant de type YYSTYPE)
 * afin que les outils compagnons de l'analyseur lexical puisse l'y recuperer.
 * Attention: le contenu de yylval va etre ecrase a chaque appel a l'analyseur
 * lexical et doit donc etre sauvegarde si besoin.
 */
%}

%%
"/*"{CommentInterieur}"*/"	{/*do nothing*/}
{CommentLigne}			{/*do nothing*/}
{GUIL}{TSG}{GUIL}		{yylval.S = strdup(yytext); return STRG;}

"+"		{yylval.C = '+'; return ADD;}
"-"		{yylval.C = '-'; return SUB;}
"*"		{yylval.C = '*'; return MUL;}
"/"		{yylval.C = '/'; return DIV;}

":="		{yylval.S = strdup(yytext); return AFFECT;}
";"		{yylval.C = ';'; return SCOL;}
"&"		{yylval.C = '&'; return AND;}
"("		{yylval.C = '('; return BRACO;}
")"		{yylval.C = ')'; return BRACC;}
","		{yylval.C = ','; return COMA;}
"{"		{yylval.C = '{'; return CBRACO;}
"}"		{yylval.C = '}'; return CBRACC;}

"="		{yylval.C = EQ; return RELOP;}
"<>"		{yylval.C = NE; return RELOP;}
"<"		{yylval.C = LT; return RELOP;}
"<="		{yylval.C = LE; return RELOP;}
">"		{yylval.C = GT; return RELOP;}
">="		{yylval.C = GE; return RELOP;}

"if"		{yylval.S = strdup(yytext); return IF;}
"then"		{yylval.S = strdup(yytext); return THEN;}
"else"		{yylval.S = strdup(yytext); return ELSE;}

"class"		{yylval.S = strdup(yytext); return CLASS;}
"extends"	{yylval.S = strdup(yytext); return EXT;}
"is"		{yylval.S = strdup(yytext); return IS;}
"object"	{yylval.S = strdup(yytext); return OBJ;}
"new"		{yylval.S = strdup(yytext); return NEW;}

"override"	{yylval.S = strdup(yytext); return OVR;}
"def"		{yylval.S = strdup(yytext); return DEF;}
"return"	{yylval.S = strdup(yytext); return RETURN;}
"."		{yylval.C = '.'; return POINT;}

"var"		{yylval.S = strdup(yytext); return VAR;}
":"		{yylval.C = ':'; return COL;}

{Delim}+        { /* espaces : rien ! on passe au token suivant */ }
{Digit}+        { yylval.I = strtol(yytext, NULL, 0); return(CST); }
{LetterMin}{LD}*   { yylval.S = strdup(yytext); return ID; }
{LetterMaj}{LD}*   {yylval.S = strdup(yytext); return IDCLASS; }


.		{ lexError(yytext[0]);}
%%
