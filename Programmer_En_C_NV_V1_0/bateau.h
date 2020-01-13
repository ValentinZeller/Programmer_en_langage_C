#ifndef BATEAU_H_INCLUDED
#define BATEAU_H_INCLUDED
#include "cellule.h"
#define NB_CELLULE 5

typedef struct tBateau {
    tCell tabCellule[NB_CELLULE];
    int nTaille;
    int nCoule;
}tBateau;

struct tBateau CreerBateau(int row, int col, int taille, int vertical);
int nEstDansBateau(tCell cellule, tBateau bateau,int *nNumCell);
int nEstCoule(tBateau bateau);


#endif // BATEAU_H_INCLUDED
