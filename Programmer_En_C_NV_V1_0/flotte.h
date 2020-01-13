#ifndef FLOTTE_H_INCLUDED
#define FLOTTE_H_INCLUDED
#include "bateau.h"
#include <stdio.h>
#define NB_BATEAU 5

typedef struct tFlotte {
    tBateau tabBateau[NB_BATEAU];
}tFlotte;

int nEstDansFlotte(tCell cellule, tFlotte flotte,int *nNumCell,int *nNumBat);
int nFlotteVaincue(tFlotte flotte);
void initFlotte(tFlotte *flotte);


#endif // FLOTTE_H_INCLUDED
