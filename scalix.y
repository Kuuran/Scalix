%token IF THEN ELSE ADD SUB MUL DIV AFFECT SCOL AND BRACO BRACC COMA CBRACO CBRACC CLASS EXT IS OBJ NEW OVR DEF STRG RETURN POINT VAR COL
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
%nonassoc unary
%left POINT 



%{
#include "scalix.h"     /* les definition des types et les etiquettes des noeuds */

extern int yylex();	/* fournie par Flex */
extern void yyerror();  /* definie dans tp.c */
%}

%%
programme	: listOptDef bloc 
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
		|
		;

defConst	:DEF IDCLASS BRACO listOptParam BRACC superClasseOpt IS CBRACO listOptInst CBRACC
;


superClasseOpt	: IDCLASS BRACO listEOpt BRACC
		|
		;

listOptChamps	: listChamps
|
;
listChamps	: champ
		| champ listChamps
		;

champ	: VAR ID COL IDCLASS SCOL
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
		| ID BRACO listOptParam BRACC nomClasseOpt IS bloc
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
	
	|BRACO IDCLASS E BRACC
	|ADD E %prec unary 
	|SUB E %prec unary 
	;
	
appel	:envoi
	|selection
	;
envoi	:ELight POINT ID BRACO listEOpt BRACC
|IDCLASS POINT ID BRACO listEOpt BRACC
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
	|STRG
	|BRACO E BRACC
	
	;

instanciation	: NEW IDCLASS BRACO listEOpt BRACC
;

/*
blocInst 	: inst
| inst blocInst
;
*/
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

aff 	: selection AFFECT E SCOL 
| ID AFFECT E SCOL 
;

defObj	: OBJ IDCLASS IS CBRACO listOptChamps defConstObj listOptMeth CBRACC
;

defConstObj	: DEF IDCLASS IS CBRACO listOptInst CBRACC
;
