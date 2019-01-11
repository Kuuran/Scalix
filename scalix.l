Digit [0-9]
Letter  [a-zA-Z]
LD  ({Letter}|{Digit})
Delim [ \n\t\r]

%{
#include "tp.h"
#include "tp_y.h"	/* produit par Bison */
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
{Delim}+        { /* espaces : rien ! on passe au token suivant */ }
{Digit}+        { yylval.I = strtol(yytext, NULL, 0); return(CST); }
{Letter}{LD}*   { yylval.S = strdup(yytext); return ID; }
%%
