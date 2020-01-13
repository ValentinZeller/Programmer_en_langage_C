#include "vue.h"

void Affichage(tFlotte *flotte) {
    //Affiche la grille de jeu lors de la saisie
    system("cls");
    int i;
    int j;
    int nNumBat = 0;
    int nNumCell = 0;

    for (i=0;i<TAILLE_GRILLE;i++) {
        for (j=0;j<TAILLE_GRILLE;j++) {
            if (nEstDansFlotte(CreerCell(i,j),*flotte,&nNumCell,&nNumBat)) {
                printf("X|");
            } else {
                printf(" |");
            }
        }
        printf("\n");
    }
}

void AffichageAttaque(tFlotte flotte,int tabTouche[][TAILLE_GRILLE]) {
    //Affiche la grille de jeu lors de l'attaque
    system("cls");
    int nNumBat = 0;
    int nNumCell = 0;
    int i;
    int j;
    for (i=0;i<TAILLE_GRILLE;i++) {
        for (j=0;j<TAILLE_GRILLE;j++) {
            if (tabTouche[i][j] == 1) {
                if (nEstDansFlotte(CreerCell(i,j),flotte,&nNumCell,&nNumBat)) {
                    color(VERT,0);
                }
                printf("X");
                color(GRISCLAIR,0);
            } else {
                printf(" ");
            }
            printf("|");
        }
        printf("\n");
    }
}

void color(int t,int f) {
    //Affichage des couleurs dans la console
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}

void afficherResultats() {
    //Affiche les résultats des parties
    int nVal =0;
    int i=0;
    int nPartie=1;

    FILE *fResult=NULL;
    fResult = fopen("result.bin","rb");

    fseek(fResult, 0L, SEEK_END);
    int sz = ftell(fResult);
    printf("%d",sz);
    rewind(fResult);

    system("cls");
    do{
            printf("\nPartie %d :\n",nPartie);
            nPartie++;

            fseek(fResult,sizeof(int)*i,SEEK_SET);
            fread(&nVal,sizeof(int),1,fResult);
            printf("Score du joueur 1 : ");
            printf("%d\n",nVal);
            i++;

            fseek(fResult,sizeof(int)*i,SEEK_SET);
            fread(&nVal,sizeof(int),1,fResult);
            printf("Score du joueur 2 : ");
            printf("%d\n",nVal);
            i++;

    } while (i<(sz/sizeof(int)));

    printf("Appuyer sur [Entree] pour continuer");
    fflush(stdin);
    getchar();
    fclose(fResult);
}
