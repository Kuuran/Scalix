#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "scalix.h"
#include "scalix_y.h"

extern int yyparse();
extern int yylineno;

/* Niveau de 'verbosite'.
 * Par defaut, n'imprime que le resultat et les messages d'erreur
 */
bool verbose = FALSE;

/* Evaluation ou pas. Par defaut, on evalue les expressions */
bool noEval = FALSE;

/* code d'erreur a retourner: liste dans tp.h */
int errorCode = NO_ERROR;

/* yyerror:  fonction importee par Bison et a fournir explicitement.
 * Elle est appelee quand Bison detecte une erreur syntaxique.
 * Ici on se contente d'un message minimal.
 */
void yyerror(char *ignore) {
    fprintf(stderr, "Syntax error on line: %d\n", yylineno);
}


/* mémorise le code d'erreur et s'arrange pour bloquer l'évaluation */
void setError(int code) {
    errorCode = code;
    if (code != NO_ERROR) { noEval = TRUE; }
}
//ekflzjfoe

/* Appel:
 *   tp [-option]* programme.txt
 * Les options doivent apparaitre avant le nom du fichier du programme.
 * Options: -[eE] -[vV] -[hH?]
 */
int main(int argc, char **argv) {
    int fi;
    int i, res;

    for(i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case 'v': case 'V':
                    verbose = TRUE; continue;
                case 'e': case 'E':
                    noEval = TRUE; continue;
                case '?': case 'h': case 'H':
                    fprintf(stderr, "Syntax: tp -e -v program.txt\n");
                    exit(USAGE_ERROR);
                default:
                    fprintf(stderr, "Error: Unknown Option: %c\n", argv[i][1]);
                    exit(USAGE_ERROR);
            }
        } else break;
    }

    if (i == argc) {
        fprintf(stderr, "Error: Program file is missing\n");
        exit(USAGE_ERROR);
    }

    if ((fi = open(argv[i++], O_RDONLY)) == -1) {
        fprintf(stderr, "Error: Cannot open %s\n", argv[i-1]);
        exit(USAGE_ERROR);
    }

    /* redirige l'entree standard sur le fichier... */
    close(0); dup(fi); close(fi);

    if (i < argc) { /* fichier dans lequel lire les valeurs pour get() */
        fprintf(stderr, "Error: extra argument: %s\n", argv[i]);
        exit(USAGE_ERROR);
    }

    /* Lance l'analyse syntaxique de tout le source, qui appelle yylex au fur
     * et a mesure. Execute les actions semantiques en parallele avec les
     * reductions.
     * yyparse renvoie 0 si le source est syntaxiquement correct, une valeur
     * differente de 0 en cas d'erreur syntaxique (eventuellement dues a des
     * erreurs lexicales).
     * Comme l'interpretation globale est automatiquement lancee par les actions
     * associees aux reductions, une fois que yyparse a termine il n'y
     * a plus rien a faire (sauf fermer les fichiers)
     * Si le code du programme contient une erreur, on bloque l'evaluation.
     * S'il n'y a que des erreurs contextuelles on essaye de ne pas s'arreter
     * a la premiere mais de continuer l'analyse pour en trovuer d'autres, quand
     * c'est possible.
     */
    res = yyparse();
    if (res == 0 && errorCode == NO_ERROR) return 0;
    else {
        return res ? SYNTAX_ERROR : errorCode;
    }
}


/* Fonction AUXILIAIRE pour la construction d'arbre : renvoie un squelette
 * d'arbre pour 'nbChildren' fils et d'etiquette 'op' donnee. L'appelant
 * doit lui-même stocker ses fils dans la strucutre que MakeNode renvoie
 *
 * la macro NEW est decrite dans tp.h
 */
TreeP makeNode(int nbChildren, short op) {
    TreeP tree = NEW(1, Tree);
    tree->op = op; tree->nbChildren = (short) nbChildren;
    tree->u.children = nbChildren > 0 ? NEW(nbChildren, TreeP) : NIL(TreeP);
    return(tree);
}


/* Construction d'un arbre a nbChildren branches, passees en parametres
 * 'op' est une etiquette symbolique qui permet de memoriser la construction
 * dans le programme source qui est representee par cet arbre.
 * Une liste preliminaire d'etiquettes est dans tp.h; il faut l'enrichir selon
 * vos besoins.
 * Cette fonction prend un nombre variable d'arguments: au moins deux.
 * Les eventuels arguments supplementaires doivent etre de type TreeP
 * (defini dans tp.h)
 */
TreeP makeTree(short op, int nbChildren, ...) {
    va_list args;
    int i;
    TreeP tree = makeNode(nbChildren, op);
    va_start(args, nbChildren);
    for (i = 0; i < nbChildren; i++) {
        tree->u.children[i] = va_arg(args, TreeP);
    }
    va_end(args);
    return(tree);
}


/* Retourne le i-ieme fils d'un arbre (de 0 a n-1) */
TreeP getChild(TreeP tree, int i) {
    return tree->u.children[i];
}


/* Constructeur de feuille dont la valeur est un entier */
TreeP makeLeafInt(short op, int val) {
    TreeP tree = makeNode(0, op);
    tree->u.val = val;
    return(tree);
}


/* Constructeur de feuille dont la valeur est une chaine de caracteres.
 * Construit un doublet pour la future variable et stocke son nom dedans.
 */
TreeP makeLeafStr(short op, char *str) {
    TreeP tree = makeNode(0, op);
    tree->u.str = str;
    return(tree);
}


/* Verifie que nouv n'apparait pas deja dans list. l'ajoute en tete et
 * renvoie la nouvelle liste
 */

bool contient(VarDeclP list, VarDeclP nouv)
{
    while(list != nouv)
    {
        if(list->next == NULL) return FALSE;
        else list = list->next;
    }
    return TRUE;
}

VarDeclP addToScope(VarDeclP list, VarDeclP nouv) {
    VarDeclP pt = list;
    if(contient(pt, nouv)) return list;
    else
    {
        nouv->next = list;
        return nouv;
    }
}


/**
 * 	A partir d'ici les fonctions ont besoin d'etre modifiees/completees
 **/

void printOpBinaire(char op) {
    switch(op) {
        case EQ:    printf("="); break;
        case NE:    printf("<>"); break;
        case GT:    printf("<"); break;
        case GE:    printf(">="); break;
        case LT:    printf("<"); break;
        case LE:    printf("<="); break;
        case Eadd:  printf("+"); break;
        case Eminus:printf("-"); break;
        case Emult: printf("*"); break;
        case Ediv:  printf("/"); break;
        default:
            fprintf(stderr, "Unexpected binary operator of code: %d\n", op);
            exit(UNEXPECTED);
    }
}

void printExpr(TreeP tree) {
     switch (tree->op) {
        case IDVAR :
            printf("%s", tree->u.str); break;
        case CONST:
            printf("%d", tree->u.val); break;
        case ITE:
            printf("[ITE "); printExpr(getChild(tree, 0)); /* la condition */
            printf(", "); printExpr(getChild(tree, 1)); /* la partie 'then' */
            printf(", "); printExpr(getChild(tree, 2)); /* la partie 'else' */
            printf("]");
            break;
            
        case EQ:
        assert(tree->nbChildren == 2);
    	printf("(");
    	printExpr(getChild(tree, 0));
    	printOpBinaire(EQ);
    	printExpr(getChild(tree, 1));
    	printf(")");
    	break;
       
       
        case NE:
        assert(tree->nbChildren == 2);
    	printf("(");
    	printExpr(getChild(tree, 0));
    	printOpBinaire(NE);
    	printExpr(getChild(tree, 1));
    	printf(")");
    	break;
    	
        case GT:
        assert(tree->nbChildren == 2);
    	printf("(");
    	printExpr(getChild(tree, 0));
    	printOpBinaire(GT);
    	printExpr(getChild(tree, 1));
    	printf(")");
            
        
        case GE:
        assert(tree->nbChildren == 2);
    	printf("(");
    	printExpr(getChild(tree, 0));
    	printOpBinaire(GE);
    	printExpr(getChild(tree, 1));
    	printf(")");
        
        case LT:
        assert(tree->nbChildren == 2);
    	printf("(");
    	printExpr(getChild(tree, 0));
    	printOpBinaire(LT);
    	printExpr(getChild(tree, 1));
    	printf(")");
        
        case LE:
        assert(tree->nbChildren == 2);
    	printf("(");
    	printExpr(getChild(tree, 0));
    	printOpBinaire(LE);
    	printExpr(getChild(tree, 1));
    	printf(")");
        
       
        case Eadd: 
        
        assert(tree->nbChildren == 2);
    	printf("(");
    	printExpr(getChild(tree, 0));
    	printOpBinaire(Eadd);
    	printExpr(getChild(tree, 1));
    	printf(")"); break;
        
        case Eminus:
        
        assert(tree->nbChildren == 2);
        printf("(");
    	printExpr(getChild(tree, 0));
    	printOpBinaire(Emult);
    	printExpr(getChild(tree, 1));
    	printf(")"); break;
    	    	
    	
    	case Emult:
    	
    	assert(tree->nbChildren == 2);
        printf("(");
    	printExpr(getChild(tree, 0));
    	printOpBinaire(Emult);
    	printExpr(getChild(tree, 1));
    	printf(")"); break;
    	    

        case Ediv:
            
        assert(tree->nbChildren == 2);
        printf("("); 
        printExpr(getChild(tree, 0));
        printOpBinaire(Ediv); 
        printExpr(getChild(tree, 1));
        printf(")"); break;
                   
       
        default:
            fprintf(stderr, "Erreur! etiquette indefinie: %d\n", tree->op);
            exit(UNEXPECTED);
    }
}

void printDecls(TreeP decls) {
    TreeP gauche, droite;
    if (decls == NIL(Tree)) { return; }
    if (decls->op != LIST) {
        fprintf(stderr, "Mauvais format dans les declarations\n");
        exit(UNEXPECTED);
    }
    gauche = getChild(decls, 0); droite = getChild(decls, 1);
    printDecls(gauche);
    printf("%s := ", getChild(droite, 0)->u.str);
    printExpr(getChild(droite, 1));
    printf("\n");
}


void printAST(TreeP decls, TreeP main) {
    printDecls(decls);
    printf("Expression finale: ");
    printExpr(main);
    printf("\n");
}


/* Avant evaluation, verifie si tout identificateur qui apparait dans tree a
 * bien ete declare (dans ce cas il doit apparaitre dans lvar).
 */
bool checkScope(TreeP tree, VarDeclP lvar) {
    VarDeclP decls = evalDecls(tree);

    printf("checkscope debut\n");
    addToScope(lvar, decls);
    printf("checkscope finie\n");

    return TRUE;
}

/* Associe une variable a l'expression qui definit sa valeur, et procede a
 * l'evaluation de cette expression, sauf si on est en mode noEval
 */
VarDeclP declVar(char *name, TreeP tree, VarDeclP decls) {
    if(!noEval) {
        decls->value.u.I = tree->u.val;
        printf(" nom de la variable = %s valeur = %d\n", name, decls->value.u.I);
    }
    return decls;
}


/* Traite une declaration representee par l'AST 'tree'.
 * 'decls' represente la liste des couples (variable, valeur) definis par les
 * declarations qui precedaient la declaration courante dans le programme,
 * donc les variables qui peuvent apparaitre aux feuilles de 'tree'
*/
VarDeclP evalAff (TreeP tree, VarDeclP decls) {

    decls->name = getChild(tree, 0)->u.str;
    declVar(decls->name, getChild(tree, 1), decls);
    return decls;
}

/* Ici 'tree' correspond a l'AST pour une liste de declarations. */
VarDeclP evalDecls (TreeP tree) {
    VarDeclP dec = NEW(1, VarDecl);

    if(tree == NULL)
        return NIL(VarDecl);

    dec->next = evalDecls(getChild(tree, 0)); // Récupérationde la suite des liste opt Decl

// Gestion de Decl

    TreeP child = getChild(tree, 1);
    dec = evalAff(child, dec);
    printf("fct evalDecls finie\n");

    return dec;
}


/* Evaluation d'un if then else
 * le premier fils represente la condition,
 * les deux autres fils correspondent respectivement aux parties then et else.
 * Attention a n'evaluer qu'un seul de ces deux sous-arbres !
 */
int evalIf(TreeP tree, VarDeclP decls) {

    TreeP condChild = getChild(tree, 0);
    TreeP lchild = getChild(tree, 1), rchild = getChild(tree, 2);

    switch(condChild->op) {
        case EQ:
            if(eval(getChild(condChild, 0), decls) == eval(getChild(condChild, 1), decls))
                return eval(lchild, decls);
            else return eval(rchild, decls);

        case GT:
            if(eval(getChild(condChild, 0), decls) > eval(getChild(condChild, 1), decls))
                return eval(lchild, decls);
            else return eval(rchild, decls);

        case LT:
            if(eval(getChild(condChild, 0), decls) < eval(getChild(condChild, 1), decls))
                return eval(lchild, decls);
            else return eval(rchild, decls);

        case NE:
            if(eval(getChild(condChild, 0), decls) != eval(getChild(condChild, 1), decls))
                return eval(lchild, decls);
            else return eval(rchild, decls);

        case GE:
            if(eval(getChild(condChild, 0), decls) >= eval(getChild(condChild, 1), decls))
                return eval(lchild, decls);
            else return eval(rchild, decls);

        case LE:
            if(eval(getChild(condChild, 0), decls) <= eval(getChild(condChild, 1), decls))
                return eval(lchild, decls);
            else return eval(rchild, decls);

        default :
            return -1;
    }
}


/* retourne la valeur d'une variable: 'tree' correspond a une feuille qui
 * represente un identificateur. decls est la liste courante des couples
 * (variable, valeur). On est suppose avoir deja verifie que l'identificateur
 * etait bien declare, donc on doit trouver sa valeur.
 */
int getValue(TreeP tree, VarDeclP decls) {
    if(strcmp(tree->u.str, decls->name) == 0) return decls->value.u.I;
    else return getValue(tree, decls->next);
}


/* eval: parcours recursif de l'AST d'une expression en cherchant dans
 * l'environnement la valeur des variables referencee
 * tree: l'AST d'une expression
 * decls: la liste des variables deja declarées avec leur valeur.
 */
int eval(TreeP tree, VarDeclP decls) {
    if (tree == NIL(Tree)) { exit(UNEXPECTED); }

    if(tree->op == CONST) return tree->u.val;
    else if(tree->op == IDVAR) return -1;
    else
    {
        TreeP lchild = getChild(tree, 0), rchild = getChild(tree, 1);

        switch (tree->op) {
            case ITE:
                return evalIf(tree, decls);

            case Eadd:
                return eval(lchild, decls) + eval(rchild, decls);

            case Eminus:
                return eval(lchild, decls) - eval(rchild, decls);

            case Emult:
                return eval(lchild, decls) * eval(rchild, decls);

            case Ediv:
                return eval(lchild, decls) / eval(rchild, decls);

            default :
                return -1;
        }
    }
}

/* evalMain: evaluation de l'expression finale.
 * tree: AST de l'expression comprise entre le BEGIN et le END
 * decls: l'environnement forme par les variables declarees
 */
int evalMain(TreeP tree, VarDeclP decls) {
    int res;
    /* verifie les ident utilises dans l'expression finale */
    checkScope(tree, decls);
    printf("decls %s\n", decls->name);
    if (noEval) {
        fprintf(stderr, "Skipping evaluation step.\n");
    } else {
        if (errorCode == NO_ERROR) {
            res = eval(tree, decls);
            printf("\nResultat global: %d\n", res);
        } else {
            return errorCode;
        }
    }
    return errorCode;
}

void codeMain(TreeP tree)
{
    //checkScope(tree, decls);
    if (noEval) {
        fprintf(stderr, "Skipping evaluation step.\n");
    } else {
        if (errorCode == NO_ERROR) {
            Code(tree);
            printf("\nResultat global: \n");
        } else {
        }
    }
}

void Code(TreeP tree)
{

}

ClassP rechercheClasse(char* nom){
    VarDeclP tmp = listeSC;
    while(tmp != NIL(VarDecl)){
        if(tmp->value.t == CLASS && tmp->value.u.Classe->nom == nom){
            return tmp->value.u.Classe;
        }
        tmp = tmp->next;
    }
    return NIL(Class);
}

ObjP rechercheObjet(char* nom){
    VarDeclP tmp = listeObjet;
    while(tmp != NIL(VarDecl)){
        if(tmp->value.t == OBJECT && tmp->value.u.Object->nom == nom){
            return tmp->value.u.Object;
        }
        tmp = tmp->next;
    }
    return NIL(Obj);
}

MethodesP rechercheMethode(char* nomC, char* nomM){
    ClassP cp = rechercheClasse(nomC);

    if(cp == NIL(Class)){
        printf("Erreur : La classe %s n'existe pas.\n", nomC);
        exit(EXIT_FAILURE);
    }

    MethodesP tmp = cp->sesMethodes;
    while(tmp != NIL(Methodes)){
        if(tmp->nom == nomM){
            return tmp;
        }
        tmp = tmp->next;
    }
    return NIL(Methodes);
}

VarDeclP rechercheChamps(char* nomC, const char* nomChamp){
    ClassP cp = rechercheClasse(nomC);

    if(cp == NIL(Class)){
        printf("Erreur : La classe %s n'existe pas.\n", nomC);
        exit(EXIT_FAILURE);
    }

    VarDeclP tmp = cp->sesChamps;
    while(tmp != NIL(VarDecl)){
        if(tmp->name == nomChamp){
            return tmp;
        }
        tmp = tmp->next;
    }
    return NIL(VarDecl);
}


ClassP makeClass(char* nom, VarDeclP lparamConst, VarDeclP donneesMembres, MethodesP constructeur, MethodesP methodes, char* sc){

    ClassP result = malloc(sizeof(ClassP));

    //si une superclasse est fournie on teste si elle a déja été définie
    VarDeclP tmp = listeSC;
    if (sc != NIL(Class)) {
        if (tmp != NIL(VarDecl)) {
            do{
                if(tmp->name == sc){
                    result->sc = listeSC->value.u.Classe;
                    break;
                }
                tmp = tmp->next;
            }while (tmp != NIL(VarDecl));

            if (result->sc == NIL(Class)){ //si on ne trouve pas la superclasse dans la liste on a une erreur
                printf("Erreur : la superclasse %s n'est pas definie.\n", sc);
                exit(EXIT_FAILURE);
            }
        }else{ //si la liste de superclasses est vide on a une erreur
            printf("Erreur : la superclasse %s n'est pas definie.\n", sc);
            exit(EXIT_FAILURE);
        }
    }

    //on teste la validité du constructeur pr rapport aux parametres de la classe

    if (lparamConst != NIL(VarDecl)){
        if(constructeur->sesParam == NIL(VarDecl)){
            printf("Erreur : les arguments passes en parametre de la classe %s sont errones.\n", nom);
            exit(EXIT_FAILURE);
        }
        VarDeclP tmp1 = lparamConst, tmp2 = constructeur->sesParam;
        while(tmp1 != NIL(VarDecl) && tmp2 != NIL(VarDecl)){
            if(tmp1->value.t == tmp2->value.t){
                switch (tmp1->value.t){
                    CLASSE :
                        if(tmp1->value.u.Classe->nom != tmp2->value.u.Classe->nom){
                            printf("Erreur : les arguments passes en parametre de la classe %s sont errones.\n", nom);
                            exit(EXIT_FAILURE);
                        }
                        break;
                    OBJECT :
                        if(tmp1->value.u.Object->nom != tmp2->value.u.Object->nom){
                            printf("Erreur : les arguments passes en parametre de la classe %s sont errones.\n", nom);
                            exit(EXIT_FAILURE);
                        break;
                    default:
                        break;
                    }
                }
            }
            else{
                printf("Erreur : les arguments passes en parametre de la classe %s sont errones.\n", nom);
                exit(EXIT_FAILURE);
            }
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        if(tmp1 != NIL(VarDecl) || tmp2 != NIL(VarDecl)){
            printf("Erreur : les arguments passes en parametre de la classe %s sont errones.\n", nom);
            exit(EXIT_FAILURE);
        }

    }

    result->sesChamps = donneesMembres;
    result->sesMethodes = methodes;
    result->nom = nom;
    if(listeSC != NIL(VarDecl)) {
        //rajout de ma classe dans la liste des super classes potentielles, on réutilise tmp car il a déja avancé dans la liste ou est déja à la fin
        while (tmp->next != NIL(VarDecl)) {
            tmp = tmp->next;
        }
        tmp->next = malloc(sizeof(VarDeclP));
        tmp->next->next = NIL(VarDecl);
        tmp->next->value.u.Classe = result;
        tmp->next->name = nom;
        tmp->next->element = INCONNU;
        tmp->next->value.t = CLASSE;
    }else{
        listeSC = malloc(sizeof(VarDeclP));
        listeSC->next = NIL(VarDecl);
        listeSC->value.u.Classe = result;
        listeSC->name = nom;
        listeSC->element = INCONNU;
        listeSC->value.t = CLASSE;
    }

    return result;
}

ObjP makeObj(char* nom, VarDeclP champs, MethodesP constructeur, MethodesP methodes)
{
	ObjP result = malloc(sizeof(ObjP));
	result->sesChamps = champs;
	result->sesMethodes = methodes;
	result->nom = nom;

	if(listeObjet == NIL(VarDecl)){
	    listeObjet = malloc(sizeof(VarDeclP));
	    listeObjet->element = INCONNU;
	    listeObjet->value.t = OBJECT;
	    listeObjet->value.u.Object = result;
	    listeObjet->next = NIL(VarDecl);
	} else{
	    VarDeclP tmp = listeObjet;
	    while (tmp->next == NIL(VarDecl)){
	        tmp = tmp->next;
	    }
        tmp->next = malloc(sizeof(VarDeclP));
        tmp->next->element = INCONNU;
        tmp->next->value.t = OBJECT;
        tmp->next->value.u.Object = result;
        tmp->next->next = NIL(VarDecl);
	}

	return result;
}

//todo remplacement d'un truc mais on sait plus ce que c'est mais c'est pas grave Philippe s'en souviendra en lisant ce todo (le typevar est remplacé par un string)
//todo gerer exit classe existe pas
MethodesP makeMethodes(bool ovr, char* nom, VarDeclP params, char* typeRetour, TreeP bloc)
{
	MethodesP result = malloc(sizeof(MethodesP));
	ClassP classP = rechercheClasse(typeRetour);
	result->ovr = ovr;
	result->nom = nom;
	result->sesParam = params;
	ObjP obj = rechercheObjet(typeRetour);

	if(typeRetour == "Integer")
		result->typeRetour.t = INTEGER;
	else if(typeRetour == "String")
		result->typeRetour.t = STRING;
	else if(classP != NIL(Class))
		result->typeRetour.t = CLASSE;
	else if(obj != NIL(Obj))
		result->typeRetour.t = OBJECT;
	else
		exit(EXIT_FAILURE);

	//todo type de Retour à faire avec l'env listeClasse + Integer + String
	return result;

}

VarDeclP makeVarDecl(char* name, char* type, enum elmt element, bool var)
{
	VarDeclP res = malloc(sizeof(VarDeclP));
	ClassP classP = rechercheClasse(type);
	ObjP obj = rechercheObjet(type);

	res->name = name;
	res->element = element;
	if(type == "Integer")
		res->value.t = INTEGER;
	else if(type == "String")
		res->value.t = STRING;
	else if(classP != NIL(Class))
		res->value.t = CLASSE;
	else if(obj != NIL(Obj))
		res->value.t = OBJECT;
	else
		exit(EXIT_FAILURE);

	return res;
}

VarDeclP makeList(VarDeclP element, VarDeclP next)
{
	element->next = next;
	return element;
}

MethodesP makeListMeth(MethodesP element, MethodesP next)
{
	element->next = next;
	return element;
}
