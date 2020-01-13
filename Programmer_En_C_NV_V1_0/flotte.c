#include "flotte.h"

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
