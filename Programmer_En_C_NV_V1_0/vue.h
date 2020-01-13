#ifndef VUE_H_INCLUDED
#define VUE_H_INCLUDED

#include <windows.h>
#define TAILLE_GRILLE 10
#define GRISCLAIR 7
#define VERT 2
#include "flotte.h"

void Affichage(tFlotte *flotte);
void AffichageAttaque(tFlotte flotte,int tabTouche[][TAILLE_GRILLE]);
void afficherResultats();
void color(int t,int f);

#endif // VUE_H_INCLUDED
