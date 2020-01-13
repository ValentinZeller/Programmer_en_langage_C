#include "bateau.h"

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

int nEstCoule(tBateau bateau) {
    //Renvoie 1 si toutes les cellules d'un bateau ont été touché, sinon 0
    int i=0;
    int verif=1;
    for (i=0;i<bateau.nTaille;i++) {
        verif = verif && bateau.tabCellule[i].nTouche;
    }
    return verif;
}
