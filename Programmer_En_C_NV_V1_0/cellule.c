#include "cellule.h"

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
