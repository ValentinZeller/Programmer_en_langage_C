#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAILLE 3
#define NBSYMBOL 2
#define MAXTURN 8

//Prototypes
void initMorpion(char cMorpion[TAILLE][TAILLE]);
void afficheMorpion(char cMorpion[TAILLE][TAILLE]);
int isWon(char cMorpion[TAILLE][TAILLE],char cSymbol,int nLigne,int nColonne);

//Morpion

int main()
{
    //Gestion des
    char cSymbol[NBSYMBOL];
    cSymbol[0] = 'x';
    cSymbol[1] = 'o';

    char cMorpion[TAILLE][TAILLE];
    int nLigne = 0;
    int nColonne = 0;
    int Turn = 0;

    int nSelectPlayer = 0;

    initMorpion(cMorpion);

    do {
        Turn++;
        nSelectPlayer = (nSelectPlayer + 1)%2; //Changement de joueur
        do { //Saisie des coordonnées
            printf("Entrez les coordonnes x y (entre 1 et 3)\n");
            printf("Quelle ligne ?\n");
            scanf("%d",&nLigne);
            fflush(stdin);
            printf("Quelle colonne ?\n");
            scanf("%d",&nColonne);
        } while (cMorpion[nLigne-1][nColonne-1] != '_'); //Si la cellule est déjà remplie ou hors du tableau, le joueur doit ressaisir des coordonnées

        cMorpion[nLigne-1][nColonne-1] = cSymbol[nSelectPlayer]; //Symbole posé sur la case
        afficheMorpion(cMorpion);
    } while(Turn <= MAXTURN && isWon(cMorpion,cSymbol[nSelectPlayer],nLigne,nColonne) == 0);
    //Fin de la boucle si un joueur gagne ou s'il y a égalité

    if (Turn > MAXTURN) {
        printf("Egalite");
    }

    return 0;
}
//Initialisation
void initMorpion(char cMorpion[TAILLE][TAILLE]) {
//BUT : Initialisation du morpion
    int i,j;
    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++) {
            cMorpion[i][j] = '_';
        }
    }
}

int isWon(char cMorpion[TAILLE][TAILLE],char cSymbol,int nLigne,int nColonne) {
//BUT : Vérifie si le joueur qui joue a gagné
    int i;
    int nWon = 0;
    int nCountL = 0;
    int nCountC = 0;
    int nCountD1 = 0;
    int nCountD2 = 0;

    for (i=0;i<TAILLE;i++) {
        if (cMorpion[i][nColonne-1] == cSymbol) {
            nCountC++;
        }
        if (cMorpion[nLigne-1][i] == cSymbol) {
            nCountL++;
        }
        if (cMorpion[i][i] == cSymbol) {
            nCountD1++;
        }
        if (cMorpion[i][2-i] == cSymbol) {
            nCountD2++;
        }
    }
    if (nCountC == 3 || nCountL == 3 || nCountD1 == 3 || nCountD2 == 3) {
        nWon = 1;
        printf("Victoire des %c\n",cSymbol);
    }
   return nWon;
}

//Affichage
void afficheMorpion(char cMorpion[TAILLE][TAILLE]) {
//BUT : Affiche
    int i,j;
    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++) {
            printf("%c ",cMorpion[i][j]);
        }
        printf("\n");
    }
}
