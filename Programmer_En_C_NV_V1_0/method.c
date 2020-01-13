#include "method.h"

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

void saveResultats(int nResultJ1,int nResultJ2) {
    //Sauvegarde les scores à la fin de la partie
    FILE *fResult = NULL;

    fResult = fopen("result.bin","ab");
    fwrite(&nResultJ1,sizeof(int),1,fResult);
    fwrite(&nResultJ2,sizeof(int),1,fResult);
    fclose(fResult);
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
