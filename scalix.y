%token IF THEN ELSE ADD SUB MUL DIV AFFECT SCOL AND BRACO BRACC COMA CBRACO CBRACC CLASS EXT IS OBJ NEW OVR DEF STRG RETURN POINT VAR COL
%token <S> ID IDCLASS
%token <I> CST
%token <C> RELOP

/* On realise la version simple dans laquelle les declarations sont
 * stockees dans l'AST comme le reste du programme
 */
 

%type <T>  defConstObj defObj aff decl listDecl listInst bloc inst instanciation ELight listE selection envoi E typeMethode nomClasseOpt overrideOpt methode listOptDef listDef defClasse listParam param heritOpt defConst superClasseOpt listChamps champ listMeth expOpt listOptInst listEOpt appel listOptMeth listOptChamps listOptParam Def 


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


/* 
decl: ID AFFECT expr ';'
    { $$ = makeTree(DECL, 2, makeLeafStr(ID, $1), $3); }
;

expr : If bexpr Then expr Else expr
                        { $$ = makeTree(ITE, 3, $2, $4, $6); }
| expr ADD expr 	{ $$ = makeTree(Eadd, 2, $1, $3); }
| expr SUB expr 	{ $$ = makeTree(Eminus, 2, $1, $3); }
| expr MUL expr         { $$ = makeTree(Emult, 2, $1, $3); }
| expr DIV expr	        { $$ = makeTree(Ediv, 2, $1, $3); }
| ADD expr %prec unary  { $$ = $2; }

*/



programme	: listOptDef bloc 

{ /* $1 represente le sous-arbre avec toutes les declarations,
   * S3 represente l'arbre pour l'expression finale.
   * lvar va etre la liste des couples (variable, valeur) resultant de
   * l'evaluation des declarations.
   */
  printAST($1, $2);
  VarDeclP lvar = evalDecls($1);
  evalMain($2, lvar);
}
;

listOptDef	: listDef  { $$ = $1; }
| { $$ = NIL(Tree); }
;

listDef	:Def { $$ = $1;/*$$ = makeTree(LIST, 1, $1);*/ }
	| Def listDef { $$ = makeTree(LIST, 2, $1, $2); }
	;
	
Def	:defClasse { $$ = $1; }
	| defObj { $$ = $1; }
	;

defClasse : CLASS IDCLASS BRACO listOptParam BRACC heritOpt IS CBRACO listOptChamps defConst listOptMeth CBRACC
	 { $$ = makeClass($2, $4,$6, $9,$10,$11); }
	 ;

listOptParam	: listParam { $$ = $1; }
		|{ $$ = NIL(Champs); }
		;

listParam	:param { $$ = $1; }
		|param COMA listParam { $$ = makeTree(Ecoma, 2, $1, $3); }  //JSP
		;

param	:ID COL IDCLASS { $$ = makeParam(false, $1, $3); }
	| VAR ID COL IDCLASS { $$ = makeParam(true, $2, $4); }
	;
	
heritOpt	:EXT ID { $$ = makeTree(Eext, 1, makeLeafStr(IDVAR,$2)); }
		|{ $$ = NIL(Tree); }
		;

defConst	:DEF IDCLASS BRACO listOptParam BRACC superClasseOpt IS CBRACO listOptInst CBRACC
{ $$ = makeTree(Edef, 4,makeLeafStr(IDVAR,$2), $4, $6, $9); }
;


superClasseOpt	: IDCLASS BRACO listEOpt BRACC { $$ = makeTree(Eclass, 2,makeLeafStr(IDVAR,$1), $3); }
		|{ $$ = NIL(Tree); }
		;

listOptChamps	: listChamps { $$ = $1; }
|{ $$ = NIL(Tree); }
;
listChamps	: champ { $$ = $1; }
		| champ listChamps { $$ = makeTree(LIST, 2, $1, $2); }
		;

champ	: VAR ID COL IDCLASS SCOL { $$ = makeParam(true, $2, $4); } //on sait pas
;

listOptMeth	: listMeth { $$ = $1; }
	|{ $$ = NIL(Methodes); }
	;

listMeth	: methode { $$ = $1; }
	| methode listMeth { $$ = makeTree(LIST, 2, $1, $2); }
	;
		 
/*methode: overrideOpt DEF typeMethode { $$ = makeTree(Eovr, 2, $1, $3); } 
;*/

overrideOpt	:OVR { $$ = true; }
		| { $$ = false; }
;

methode	: overrideOpt DEF ID BRACO listOptParam BRACC COL IDCLASS AFFECT E { $$ = makeMehodes($1, $3,$5, $8,  $10); }
		| overrideOpt DEF ID BRACO listOptParam BRACC nomClasseOpt IS bloc { $$ = makeTree(Edef, 4,makeLeafStr(IDVAR,$1), $3, $5, $7); }
		;

nomClasseOpt 	: COL IDCLASS { $$ = makeTree(Ecol, 1,makeLeafStr(IDVAR,$2)); }
		|{ $$ = NIL(Tree); }
		;

/*case GT:    printf("<"); break;
        case GE:    printf(">="); break;
        case LT:    printf("<"); break;
        case LE:    printf("<="); break;
        case Eadd:  printf("+"); break;

*/








E	:E RELOP E { $$ = makeTree($2, 2, $1, $3); }
	|E ADD E { $$ = makeTree(Eadd, 2, $1, $3); }
	|E SUB E { $$ = makeTree(Eminus, 2, $1, $3); }
	|E MUL E { $$ = makeTree(Emult, 2, $1, $3); }
	|E DIV E { $$ = makeTree(Ediv, 2, $1, $3); }
	|instanciation { $$ = $1; }
	|ELight{ $$ = $1; }
	
	|BRACO IDCLASS E BRACC { $$ = makeTree(Ebrac, 2, makeLeafStr(IDVAR,$2), $3); }
	|ADD E %prec unary { $$ = $2; }
	|SUB E %prec unary { $$ = $2; } //A VOIR
	;
	
appel	:envoi { $$ = $1; }
	|selection { $$ = $1; }
	;
envoi	:ELight POINT ID BRACO listEOpt BRACC { $$ = makeTree(Eenvoi, 3,$1,makeLeafStr(IDVAR,$3), $5); }
|IDCLASS POINT ID BRACO listEOpt BRACC { $$ = makeTree(Eenvoi, 3,makeLeafStr(IDVAR,$1),makeLeafStr(IDVAR,$3), $5); }
;
selection	:ELight POINT ID { $$ = makeTree(SELEC, 2,$1,makeLeafStr(IDVAR,$3)); }
;
listEOpt	:listE { $$ = $1; }
|{ $$ = NIL(Tree); }
;
listE	:E { $$ = $1; }
|E COMA listE  { $$ = makeTree(Ecoma, 2,$1,$3); }
;
ELight	:ID { $$ = makeLeafStr(IDVAR, $1); }
	|CST { $$ = makeLeafInt(CONST, $1); }
	|appel { $$ = $1; }
	|STRG { $$ = makeLeafStr(Estrg, "strg"); }
	|BRACO E BRACC { $$ = $2; }
	
	;

instanciation	: NEW IDCLASS BRACO listEOpt BRACC { $$ = makeTree(Enew, 2,makeLeafStr(IDVAR,$2), $4); }
;

/*blocInst 	: inst
| inst blocInst
;
*/
inst	: E SCOL  { $$ = $1; }
| bloc  { $$ = $1; }
| RETURN SCOL { $$ = makeLeafStr(Ereturn, "Return"); }
| aff  { $$ = $1; }
| IF E THEN inst ELSE inst  { $$ = makeTree(ITE, 3, $2, $4, $6); }
;

bloc 	: CBRACO listOptInst CBRACC { $$ = $2; }
|CBRACO listDecl IS listInst CBRACC { $$ = makeTree(Ebloc, 2,$2,$4); }
;

listOptInst	: listInst { $$ = $1; } 
|{ $$ = NIL(Tree); }
;

listInst	: inst listInst { $$ = makeTree(LIST, 2,$1,$2); }
| inst { $$ = $1; }
;

listDecl	: decl listDecl { $$ = makeTree(LIST, 2,$1,$2); }
| decl { $$ = $1; }
;

decl	: ID COL IDCLASS expOpt SCOL { $$ = makeTree(DECL, 2,makeLeafStr(IDVAR,$1),makeLeafStr(IDVAR,$3)); }
; 

expOpt	: AFFECT E { $$ = $2; }
| { $$ = NIL(Tree); }
;

aff 	: selection AFFECT E SCOL { $$ = makeTree(DECL, 2, $1, $3); }
| ID AFFECT E SCOL { $$ = makeTree(DECL, 2, makeLeafStr(IDVAR, $1), $3); }
;

defObj	: OBJ IDCLASS IS CBRACO listOptChamps defConstObj listOptMeth CBRACC { $$ = makeObj($2, $5,$6,$7); }
;

defConstObj	: DEF IDCLASS IS CBRACO listOptInst CBRACC { $$ = makeMethodes($2, 2,makeLeafStr(IDVAR,$2),$5); }
;
