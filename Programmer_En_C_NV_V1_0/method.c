#include "method.h"
#include <stdio.h>
#include <windows.h>

void Bataille() {
    //Bataille navale

    tFlotte Tflotte1,Tflotte2; //Flottes des joueurs
    int gagne =0; //Si égal à 1, la partie se termine
    int nAttReussite=0; //Compte si la dernière attaque a été réussi
    int nScoreJ1 = 0; //Score du joueur 1
    int nScoreJ2 = 0; //Score du joueur 2
    int nCoupRateJ1 = 0; //Nombre de coups ratés entre deux attaques réussis du joueur 1
    int nCoupRateJ2 = 0; //Nombre de coups ratés entre deux attaques réussis du joueur 2
    int tabToucheJ1[TAILLE_GRILLE][TAILLE_GRILLE]; //Tableau stockant les cellules de la grille du joueur 2 attaqués par le joueur 1
    int tabToucheJ2[TAILLE_GRILLE][TAILLE_GRILLE]; //Tableau stockant les cellules de la grille du joueur 1 attaqués par le joueur 2

    //Initilisation des flottes;
    initFlotte(&Tflotte1);
    initFlotte(&Tflotte2);

    //Saisie utilisateur des flottes
    saisirFlotte(&Tflotte1,1);
    saisirFlotte(&Tflotte2,2);

    //Initilisation des tableaux
    initTabTouche(tabToucheJ1);
    initTabTouche(tabToucheJ2);

    while (!gagne) {
    //Tant qu'autant joueur n'a gagné, la partie continue
        do {
        //Attaque du joueur 1 sur le joueur 2 tant qu'il touche des cellules de la flotte du joueur 2
            nAttReussite = nAttaque(&Tflotte2,tabToucheJ1,1);
            if (nAttReussite == 1) {
            //Si l'attaque a réussi, le joueur 1 gagne des points en fonction du nombre de coups ratés
                nScoreJ1 += PTSMIN;
                if (nCoupRateJ1 <= PTSMIN) {
                    nScoreJ1 += PTS - (PTS * nCoupRateJ1/PTSMIN);
                }
                nCoupRateJ1 = 0;
            }
            gagne = nFlotteVaincue(Tflotte2);
        } while ((nAttReussite == 1)&&(gagne==0));
        nCoupRateJ1++;


        if (!gagne) {
        //Si le joueur 1 n'a pas gagné, le joueur 2 peut attaqué
          do {
          //Attaque du joueur 2 sur le joueur 1 tant qu'il touche des cellules de la flotte du joueur 1
            nAttReussite = nAttaque(&Tflotte1,tabToucheJ2,2);
            if (nAttReussite == 1) {
            //Si l'attaque a réussi, le joueur 2 gagne des points en fonction du nombre de coups ratés
                nScoreJ2 += PTSMIN;
                if (nCoupRateJ2 <= PTSMIN) {
                    nScoreJ2 += PTS - (PTS * nCoupRateJ2/PTSMIN);
                }
                nCoupRateJ2 = 0;
            }
            gagne = nFlotteVaincue(Tflotte1);
          } while ((nAttReussite == 1)&&(gagne==0));
          nCoupRateJ2++;
        }
    }

    //Fin de la partie
    if (nFlotteVaincue(Tflotte2)) {
    //Si la flotte du joueur 2 est vaincu, victoire du joueur 1, sinon victoire du joueur 2
        printf("Victoire du joueur 1");
    } else {
        printf("Victoire du joueur 2 ");
    }
    //Sauvegarde des score
    saveResultats(nScoreJ1,nScoreJ2);

}

void initTabTouche(int tabTouche[TAILLE_GRILLE][TAILLE_GRILLE]) {
    //Initialisation du tableau indiquant où le joueur a déjà attaqué
    int i=0;
    int j=0;
    for (i=0;i<TAILLE_GRILLE;i++) {
        for (j=0;j<TAILLE_GRILLE;j++) {
            tabTouche[i][j] = 0;
        }
    }
}

void initFlotte(tFlotte *flotte) {
    //Initialisation d'une flotte
    int i=0;
    int j=0;
    for (i=0;i<NB_BATEAU;i++) {
        for(j=0;j<1;j++) {
            flotte->tabBateau[i].tabCellule[j].nColonne = -1;
            flotte->tabBateau[i].tabCellule[j].nLigne = -1;
            flotte->tabBateau[i].nCoule = 0;
            flotte->tabBateau[i].nTaille = 0;
        }
    }
}

void saisirFlotte(tFlotte *flotte,int nJoueur) {
    //Saisie utilisateur de sa flotte
    int i=0;
    int j=0;

    int vertical=0; //Bateau à la vertical ou horizontal
    int verif =0; //Verifie si le bateau est plaçable
    int taille = 3; //Taille du bateau à la saisie

    int row=0;
    int col=0;
    char vert; //Choisir si le bateau est à la vertical ou horizontal

    for(i=0;i<NB_BATEAU;i++){
      Affichage(flotte);
      if (i >= 1) {
        taille = i+1;
      }
      do {
        verif = 0;
        printf("Joueur %d :\n",nJoueur);
        printf("Saisir les coordonnees haut-gauche du bateau %d de taille %d\n",(i+1),taille);
        scanf("%d",&row);
        fflush(stdin);
        scanf("%d",&col);
        fflush(stdin);
        do {
            printf("Vertical ou Horizontal ? (V | H)\n" );
            scanf("%c",&vert);
            fflush(stdin);
        } while ((vert != 'V')&&(vert != 'H'));
        vertical = 0;
        if (vert == 'V') {
            vertical = 1;
        }
        j = 0;
        while ((verif == 0)&&(j < taille)) {
            if (vertical) {
              verif = nVerifBateau(CreerCell(row+j,col),*flotte);
            } else {
              verif = nVerifBateau(CreerCell(row,col+j),*flotte);
            }
            j++;
        }
        if (verif == 1) {
            printf("Mauvaise saisie \n");
        }
      } while (verif == 1);
      flotte->tabBateau[i] = CreerBateau(row,col,taille,vertical);
  }
}

struct tCell CreerCell(int row, int col){
    //Création d'une cellule de bateau d'une flotte
    tCell cellule;
    cellule.nColonne = col;
    cellule.nLigne = row;
    cellule.nTouche = 0;
    return cellule;
}

int nCompCell(tCell cell1, tCell cell2) {
    //Renvoite 1 si les deux cellules sont égales, sinon 0
    return ((cell1.nLigne == cell2.nLigne)&&(cell1.nColonne == cell2.nColonne));
}

struct tBateau CreerBateau(int row, int col, int taille, int vertical) {
    //Création d'un bateau
    tBateau bateau;
    int i=0;

    bateau.nTaille = taille;
    bateau.nCoule = 0;
    for (i=0;i<taille;i++) {
        bateau.tabCellule[i] = CreerCell(row,col);
        if (vertical) {
            row++;
        } else {
            col++;
        }
    }
    return bateau;
}

int nEstDansBateau(tCell cellule, tBateau bateau,int *nNumCell) {
    //Renvoie 1 si la cellule est dans un bateau et stock le numero de la cellule correspondant, sinon 0
    int i=0;
    int verif = 0;
    while ((verif == 0)&&(i < bateau.nTaille)) {
        verif = nCompCell(cellule,bateau.tabCellule[i]);
        if (verif) {
          *nNumCell = i;
        }
        i++;
    }
    return verif;
}

int nEstDansFlotte(tCell cellule, tFlotte flotte,int *nNumCell,int *nNumBat) {
    //Renvoie 1 si la cellule est dans une flotte et stock le numéro du bateau correspondant, sinon 0
    int i=0;
    int verif=0;

    while ((verif == 0)&&(i < NB_BATEAU)) {
        verif = nEstDansBateau(cellule,flotte.tabBateau[i],nNumCell);
        if (verif) {
          *nNumBat = i;
        }
        i++;
    }
    return verif;
}

int nVerifBateau(tCell cellule, tFlotte flotte) {
    //Renvoie 0 si la cellule est bien dans la grille et si ni elle, ni ses voisins ne sont déjà occupées
    int verif = 1;
    int nNumCell=0;
    int nNumBat=0;

    if ((cellule.nLigne > 0)||(cellule.nLigne < TAILLE_GRILLE)) {
        if ((cellule.nColonne > 0)||(cellule.nColonne < TAILLE_GRILLE)) {
            if (nEstDansFlotte(cellule,flotte,&nNumCell,&nNumBat) == 0) {
                verif = 0;

                if (cellule.nLigne > 0) {
                    verif += nEstDansFlotte(CreerCell(cellule.nLigne-1,cellule.nColonne),flotte,&nNumCell,&nNumBat);
                    if (cellule.nColonne > 0) {
                        verif += nEstDansFlotte(CreerCell(cellule.nLigne,cellule.nColonne-1),flotte,&nNumCell,&nNumBat);
                        verif += nEstDansFlotte(CreerCell(cellule.nLigne-1,cellule.nColonne-1),flotte,&nNumCell,&nNumBat);
                    }
                    if (cellule.nColonne < TAILLE_GRILLE-1) {
                        verif += nEstDansFlotte(CreerCell(cellule.nLigne,cellule.nColonne+1),flotte,&nNumCell,&nNumBat);
                        verif += nEstDansFlotte(CreerCell(cellule.nLigne-1,cellule.nColonne+1),flotte,&nNumCell,&nNumBat);
                    }
                }

                if (cellule.nLigne < TAILLE_GRILLE - 1) {
                    verif += nEstDansFlotte(CreerCell(cellule.nLigne+1,cellule.nColonne),flotte,&nNumCell,&nNumBat);
                    if (cellule.nColonne > 0) {
                        verif += nEstDansFlotte(CreerCell(cellule.nLigne,cellule.nColonne-1),flotte,&nNumCell,&nNumBat);
                        verif += nEstDansFlotte(CreerCell(cellule.nLigne+1,cellule.nColonne-1),flotte,&nNumCell,&nNumBat);
                    }
                    if (cellule.nColonne < TAILLE_GRILLE-1) {
                        verif += nEstDansFlotte(CreerCell(cellule.nLigne,cellule.nColonne+1),flotte,&nNumCell,&nNumBat);
                        verif += nEstDansFlotte(CreerCell(cellule.nLigne+1,cellule.nColonne+1),flotte,&nNumCell,&nNumBat);
                    }
                }

                if (verif) {
                    verif = 1;
                }
            }
        }
    }
    return verif;
}

int nFlotteVaincue(tFlotte flotte) {
    //Renvoie 1 si tous les bateaux de la flotte ont coulé, sinon 0
    int verif=1;
    int i=0;
    for (i=0;i<NB_BATEAU;i++) {
        if (flotte.tabBateau[i].nCoule == 0)
        verif = 0;
    }
    return verif;
}

int nEstCoule(tBateau bateau) {
    //Renvoie 1 si toutes les cellules d'un bateau ont été touché, sinon 0
    int i=0;
    int verif=1;
    for (i=0;i<bateau.nTaille;i++) {
        verif = verif && bateau.tabCellule[i].nTouche;
    }
    return verif;
}

int nAttaque(tFlotte *flotte,int tabTouche[][TAILLE_GRILLE],int nJoueur) {
        //Attaque d'un joueur, renvoie 1 si l'attaque a réussi, sinon 0
        int nReussite=0;
        int verif=0;
        int row;
        int col;
        int nNumBat=0;
        int nNumCell=0;

        AffichageAttaque(*flotte,tabTouche);

        printf("Au tour du Joueur %d d'attaquer \n",nJoueur);
        printf("Saisir les coordonnees de la cellule a attaquer (ligne puis colonne)\n");
        scanf("%d",&row);
        scanf("%d",&col);
        verif = nEstDansFlotte(CreerCell(row,col),*flotte,&nNumCell,&nNumBat);
        while (tabTouche[row][col] == 1) {
            printf("Deja attaque, saisissez d'autre coordonnes\n");
            scanf("%d",&row);
            scanf("%d",&col);
            verif = nEstDansFlotte(CreerCell(row,col),*flotte,&nNumCell,&nNumBat);
        }
        tabTouche[row][col] = 1;
        if (verif) {
            printf("Touche\n");
            flotte->tabBateau[nNumBat].tabCellule[nNumCell].nTouche = 1;
            if (nEstCoule(flotte->tabBateau[nNumBat])) {
                printf("Bateau %d coule !\n",nNumBat+1);
                flotte->tabBateau[nNumBat].nCoule = 1;
            }
            nReussite = 1;
            printf("Le joueur %d reattaque ! \n",nJoueur);
        } else {
            printf("Rate\n");
        }
        printf("Appuyer sur [Entree] pour continuer");

        fflush(stdin);
        getchar();
        return nReussite;

}

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

int nMenu() {
    //Menu d'accueil
    int nMenuInput;
    system("cls");
    printf("Bataille Navale\n");
    printf("Nouvelle Partie (1)\n");
    printf("Charger les resultats des parties (2)\n");
    printf("Quitter (3)\n");
    scanf("%d",&nMenuInput);
    return nMenuInput;
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

void saveResultats(int nResultJ1,int nResultJ2) {
    //Sauvegarde les scores à la fin de la partie
    FILE *fResult = NULL;

    fResult = fopen("result.bin","ab");
    fwrite(&nResultJ1,sizeof(int),1,fResult);
    fwrite(&nResultJ2,sizeof(int),1,fResult);
    fclose(fResult);
}

void color(int t,int f) {
    //Affichage des couleurs dans la console
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}
