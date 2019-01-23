#ifndef PROJET_SCALIX_H
#define PROJET_SCALIX_H

#include <stdlib.h>

/* deux macros pratiques, utilisees dans les allocations de structure
 * Pour NEW on donne le nombre et le type de la stucture a allouer (pas le type
 * du pointeur) et on recupere un pointeur sur cette structure.
 * Pour NIL: on donne de meme le type de la structure (pas le type du pointeur)
 */
#define NEW(howmany, type) (type *) calloc((unsigned) howmany, sizeof(type))
#define NIL(type) (type *) 0

#define TRUE 1
#define FALSE 0
typedef int bool;


/* Codes d'erreurs */
#define NO_ERROR	0
#define USAGE_ERROR	1
#define LEXICAL_ERROR	2
#define SYNTAX_ERROR    3
#define CONTEXT_ERROR	4
#define EVAL_ERROR	5
#define UNEXPECTED	10


/* Etiquettes pour les arbres de syntaxe abstraite */
#define Eadd	1
#define Eminus	2
#define Emult	3
#define Ediv	4
#define ITE	5
#define CONST	6
#define IDVAR	7
#define NE 	8
#define EQ 	9
#define LT 	10
#define LE 	11
#define GT 	12
#define GE 	13
#define LIST	14
#define DECL	15
#define Eclass	16
#define Eext	17
#define Eis	18
#define Eobj	19
#define Enew	20
#define Eovr	21
#define Edef	22
#define Ereturn	23
#define Epoint	24
#define Evar	25
#define Ecol	26
#define Estrg	27
#define SELEC   28
#define Ebrac   29
#define Eenvoi  30
#define Ebloc   31
#define Ecoma   32

typedef struct _Class *ClassP;

/* Definition d'un arbre de syntaxe abstraite */

/* la structure d'un arbre (noeud ou feuille) */
typedef struct _Tree {
    short op;         /* etiquette de l'operateur courant */
    short nbChildren; /* nombre de sous-arbres */
    union {
        char *str;      /* valeur de la feuille si op = ID */
        int val;        /* valeur de la feuille si op = CST */
        struct _Tree **children; /* tableau des sous-arbres d'un noeud interne */
    } u;
} Tree, *TreeP;

typedef union {
	char *S;
	int I;
	ClassP Classe;
	ObjP Object;
} TypeVar;

/* la structure ci-dessous permet de cosntruire des listes de paires
 * (variable, valeur entiere).
 * On va construire des listes de la forme { (x 5), (y, 27) } au fur
 * et a mesure qu'on interprete les declarations dans un programme source.
 */
typedef struct _Decl
{ char *name;
    TypeVar value;
    struct _Decl *next;
} VarDecl, *VarDeclP;

/* Type pour la valeur de retour de Flex et les actions de Bison
 * le premier champ est necessaire pour Flex.
 * les autres correspondent aux variantes utilisees dans les actions
 * associees aux productions de la grammaire.
*/
typedef union
{ char C;	/* caractere isole */
    char *S;	/* chaine de caractere */
    int I;	/* valeur entiere */
    VarDeclP D;	/* liste de paires (variable, valeur) */
    TreeP T;	/* AST */
} YYSTYPE;

typedef struct _Champs {
	TypeVar* champ;
	struct _Champs *next;
} Champs, *ChampsP;

typedef struct _Param {
	char *name;
    TypeVar* value;
    struct _Param *next;
} Param, *ParamP;

typedef struct _Methodes {
	char* nom;
	ParamP sesParam;
	struct _Methodes *next;
} Methodes, *MethodesP;

typedef struct _Class
{
	char* nom;
	ChampsP sesChamps;
	MethodesP sesMethodes;
	struct _Class *sc;
} Class, *ClassP;

typedef struct _Obj
{
	char* nom;
	ChampsP sesChamps;
	MethodesP sesMethodes
} Obj, *ObjP;



/* necessaire sinon par defaut Bison definit YYSTYPE comme int ! */
#define YYSTYPE YYSTYPE


/* Prototypes des fonctions (partiellement) mises a disposition */

/* construction pour les AST */
TreeP makeLeafStr(short op, char *str); 	    /* feuille (string) */
TreeP makeLeafInt(short op, int val);	            /* feuille (int) */
TreeP makeTree(short op, int nbChildren, ...);	    /* noeud interne */

/* Impression des AST */
void printAST(TreeP decls, TreeP main);

/* gestion des declarations et traitement de la portee */
VarDeclP addToScope(VarDeclP list, VarDeclP nouv);
VarDeclP declVar(char *name, TreeP tree, VarDeclP decls);

/* evaluateur pour les parties declarations */
VarDeclP evalDecls (TreeP tree);
int eval(TreeP tree, VarDeclP decls);

/* evaluateur pour l'expression principale. Elle prend aussi en parametre
 * la liste des couples (variable, valeur) deduite des declarations
 */
int evalMain(TreeP tree, VarDeclP decls);

/* Transformation de l'arbre en code prêt pour l'interprète
*/

void codeMain(TreeP tree);
void Code(TreeP tree);

ClassP makeClass(char* nom, ChampsP donneesMembres, MethodesP methodes, char* sc);
ObjP makeObj(char* nom, ChampsP champs, MethodesP methodes);

VarDeclP listeSC = NIL(VarDecl);

#endif //PROJET_SCALIX_H
