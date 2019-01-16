%token IF THEN ELSE ADD SUB MUL DIV AFFECT SCOL AND BRACO BRACC COMA CBRACO CBRACC CLASS EXT IS OBJ NEW OVR DEF RETURN POINT VAR COL
%token <S> ID IDCLASS
%token <I> CST
%token <C> RELOP

/* On realise la version simple dans laquelle les declarations sont
 * stockees dans l'AST comme le reste du programme
 */
/*%type <T> expr bexpr decl declLOpt*/


/* indications de precedence (en ordre croissant) et d'associativite. Les
 * operateurs sur une meme ligne (separes par un espace) ont la meme priorite.
 */

%left RELOP
%left ADD SUB
%left MUL DIV
%left POINT 


%{
#include "scalix.h"     /* les definition des types et les etiquettes des noeuds */

extern int yylex();	/* fournie par Flex */
extern void yyerror();  /* definie dans tp.c */
%}

%%
programme	: listOptDef blocInst 
;

listOptDef	: listDef 
|
;

listDef	:Def 
	| Def listDef
	;
	
Def	:defClasse
	| defObj
;

defClasse : CLASS IDCLASS BRACO listOptParam BRACC heritOpt IS CBRACO listOptChamps defConst listOptMeth CBRACC
;

listOptParam	: listParam
		|
		;

listParam	:param
		|param COMA listParam
		;

param	:ID COL IDCLASS
	| VAR ID COL IDCLASS
	;
	
heritOpt	:EXT ID
;

defConst	:DEF IDCLASS BRACO listOptParam BRACC superClasseOpt IS CBRACO corps CBRACC
;

corps	: listAff
	|
	;
	
listAff	: aff
	| aff listAff
	;

superClasseOpt	: IDCLASS BRACO listOptParam2 BRACC
		;

listOptParam2	:listParam2
		|
		;

listParam2	: ID
		| ID COMA listParam2
		;

listOptChamps	: listChamps
|
;
listChamps	: champ
		| champ listChamps
		;

champ	: VAR ID COL ID SCOL
;

listOptMeth	: listMeth
	|
	;

listMeth	: methode
	| methode listMeth
	;
		 
methode: overrideOpt DEF typeMethode
;

overrideOpt	:OVR
		| 
;

typeMethode	: ID BRACO listOptParam BRACC COL IDCLASS AFFECT E
		| ID BRACO listOptParam BRACC COL nomClasseOpt IS bloc
		;

nomClasseOpt 	: COL IDCLASS
		|
		;

E	:E RELOP E
	|E ADD E 
	|E SUB E
	|E MUL E
	|E DIV E
	|instanciation
	|ELight
	|BRACO E BRACC
	|BRACO IDCLASS E BRACC
	;
	
appel	:envoi
	|selection
	;
envoi	:ELight POINT ID BRACO listEOpt BRACC
;
selection	:ELight POINT ID
;
listEOpt	:listE 
|
;
listE	:E
|E COMA listE
;
ELight	:ID
	|CST
	|appel
	;

//ident	: ID
/*| this
| super
| result*/
//;
//appel	: E POINT apresPoint

//apresPoint	: envMess
//;
/*

selec	:E POINT ID
;*/

instanciation	: NEW IDCLASS BRACO listOptParam2 BRACC
;


/*envMessOpt : 
|ID BRACO listOptParam2 BRACC POINT envMessOpt
;*/

blocInst 	: inst
| inst blocInst
;

inst	: E SCOL
| bloc
| RETURN SCOL
| aff
| IF E THEN inst ELSE inst 
;

bloc 	: CBRACO listOptInst CBRACC
|CBRACO listDecl IS listInst CBRACC
;

listOptInst	: listInst
|
;

listInst	: inst listInst
| inst
;

listDecl	: decl listDecl 
| decl
;

decl	: ID COL IDCLASS expOpt SCOL
;

expOpt	: AFFECT E
|
;

aff 	: ID AFFECT E SCOL 
;

defObj	: OBJ IDCLASS IS CBRACO listOptChamps defConstObj listOptMeth CBRACC
;

defConstObj	: DEF IDCLASS IS CBRACO corps CBRACC
;




/*
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
                 
E	: BRACO E BRACC
	| BRACO IDCLASS E BRACC
	| selec
	| instanciation	
	| envMess
	| expr
	;

//ident	: ID
/*| this
| super
| result*/
//;

/*selec	:E POINT ID
;

instanciation	: NEW IDCLASS BRACO listOptParam2 BRACC
;

envMess	: ID POINT ID
;

blocInst 	: inst
| inst blocInst
;

inst	: E SCOL
| bloc
| RETURN SCOL
| aff
| IF expr1 THEN inst ELSE inst 
;
       { $$ = makeTree(ITE, 3, $2, $4, $6); }
| expr ADD expr 	{ $$ = makeTree(Eadd, 2, $1, $3); }
| expr SUB expr 	{ $$ = makeTree(Eminus, 2, $1, $3); }
| expr MUL expr         { $$ = makeTree(Emult, 2, $1, $3); }
| expr DIV expr	        { $$ = makeTree(Ediv, 2, $1, $3); }
/* Ici on ne conserve pas le + unaire puisqu'il n'influe pas dans la
 * suite des traitements
 */
//| ADD expr %prec unary  { $$ = $2; }
/* Pour l'AST on represente - e  par 0 - e , comme cela on ne s'en soucie plus
 * dans la Suite. simple meme si pas optimal
 */
 /*
| SUB expr %prec unary  { $$ = makeTree(Eminus, 2, makeLeafInt(CONST, 0), $2); }
| CST		        { $$ = makeLeafInt(CONST, $1); }
| ID 			{ $$ = makeLeafStr(IDVAR, $1); }

*/
/* pas besoin de conserver les parentheses dans l'AST. Elles ne servent a
 * l'utilisateur que pour preciser la structure de son expression
 */
//| '(' expr ')'		{ $$ = $2; }
//;

/* Expression booleenne seulement presente dans un IF */
/*bexpr : expr RELOP expr { $$ = makeTree($2, 2, $1, $3); }
| '(' bexpr ')'		{ $$ = $2; }
;*/
