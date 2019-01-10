%token If Then Else Begin End ADD SUB MUL DIV AFFECT
%token <S> ID
%token <I> CST
%token <C> RELOP

/* On realise la version simple dans laquelle les declarations sont
 * stockees dans l'AST comme le reste du programme
 */
%type <T> expr bexpr decl declLOpt

/* indications de precedence (en ordre croissant) et d'associativite. Les
 * operateurs sur une meme ligne (separes par un espace) ont la meme priorite.
 */
%right Else
%left ADD SUB
%left MUL DIV
%nonassoc unary

%{
#include "tp.h"     /* les definition des types et les etiquettes des noeuds */

extern int yylex();	/* fournie par Flex */
extern void yyerror();  /* definie dans tp.c */
%}

%%
programme : declLOpt Begin expr End
               { printAST($1, $3); evalMain($3, evalDecls($1)); }
;

declLOpt :	  { $$ = NIL(Tree); }
|  declLOpt decl  { $$ = makeTree(LIST, 2, $1, $2); }
;


decl: ID AFFECT expr ';'
    { $$ = makeTree(DECL, 2, makeLeafStr(ID, $1), $3); }
;

expr : If bexpr Then expr Else expr
                        { $$ = makeTree(ITE, 3, $2, $4, $6); }
| expr ADD expr 	{ $$ = makeTree(Eadd, 2, $1, $3); }
| expr SUB expr 	{ $$ = makeTree(Eminus, 2, $1, $3); }
| expr MUL expr         { $$ = makeTree(Emult, 2, $1, $3); }
| expr DIV expr	        { $$ = makeTree(Ediv, 2, $1, $3); }
/* Ici on ne conserve pas le + unaire puisqu'il n'influe pas dans la
 * suite des traitements
 */
| ADD expr %prec unary  { $$ = $2; }
/* Pour l'AST on represente - e  par 0 - e , comme cela on ne s'en soucie plus
 * dans la Suite. simple meme si pas optimal
 */
| SUB expr %prec unary  { $$ = makeTree(Eminus, 2, makeLeafInt(CONST, 0), $2); }
| CST		        { $$ = makeLeafInt(CONST, $1); }
| ID 			{ $$ = makeLeafStr(IDVAR, $1); }
/* pas besoin de conserver les parentheses dans l'AST. Elles ne servent a
 * l'utilisateur que pour preciser la structure de son expression
 */
| '(' expr ')'		{ $$ = $2; }
;

/* Expression booleenne seulement presente dans un IF */
bexpr : expr RELOP expr { $$ = makeTree($2, 2, $1, $3); }
| '(' bexpr ')'		{ $$ = $2; }
;
