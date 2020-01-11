#ifndef METHOD_H_INCLUDED
#define METHOD_H_INCLUDED

#include "type.h"

struct tCell CreerCell(int row, int col);
int nCompCell(tCell cell1, tCell cell2);
struct tBateau CreerBateau(int row, int col, int taille, int vertical);
int nEstDansFlotte(tCell cellule, tFlotte flotte,int *nNumCell,int *nNumBat);
int nEstDansBateau(tCell cellule, tBateau bateau,int *nNumCell);
int nEstCoule(tBateau bateau);
int nFlotteVaincue(tFlotte flotte);
int nVerifBateau(tCell cellule, tFlotte flotte);

int nAttaque(tFlotte *flotte,int tabTouche[][TAILLE_GRILLE],int nJoueur);
void Bataille();
int nMenu();

void Affichage(tFlotte *flotte);
void AffichageAttaque(tFlotte flotte,int tabTouche[][TAILLE_GRILLE]);

void afficherResultats();
void saveResultats(int nResultJ1,int nResultJ2);

void initFlotte(tFlotte *flotte);
void initTabTouche(int tabTouche[TAILLE_GRILLE][TAILLE_GRILLE]);
void saisirFlotte(tFlotte *flotte,int nJoueur);
void color(int t,int f);


#endif // METHOD_H_INCLUDED
