#ifndef METHOD_H_INCLUDED
#define METHOD_H_INCLUDED

#define TAILLE_GRILLE 10
#define PTS 50
#define PTSMIN 10

#include <stdio.h>
#include "flotte.h"
#include "vue.h"

int nVerifBateau(tCell cellule, tFlotte flotte);
int nAttaque(tFlotte *flotte,int tabTouche[][TAILLE_GRILLE],int nJoueur);
void Bataille();
int nMenu();
void saveResultats(int nResultJ1,int nResultJ2);
void initTabTouche(int tabTouche[TAILLE_GRILLE][TAILLE_GRILLE]);
void saisirFlotte(tFlotte *flotte,int nJoueur);



#endif // METHOD_H_INCLUDED
