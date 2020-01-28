#ifndef LISTE_DB_CHAINE_H_INCLUDED
#define LISTE_DB_CHAINE_H_INCLUDED
#include "gameobjet.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Element {
    struct Element *suivant;
    struct Element *precedent;
    Gameobjet objet;
}Element;

typedef struct ListeDChaine {
    Element *debut;
    Element *fin;
    int taille;
}ListeDChaine;

extern void initialiserListeD(ListeDChaine *liste);

extern int ajoutDansListeDVide (ListeDChaine * liste, Gameobjet gameobjet);
extern int ajoutDebutListeD (ListeDChaine * liste, Gameobjet gameobjet);
extern int ajoutFinListeD (ListeDChaine * liste, Gameobjet gameobjet);
extern int ajoutAvantPosListeD(ListeDChaine * liste, Gameobjet gameobjet, int pos);
extern int ajoutApresPosListeD (ListeDChaine * liste,Gameobjet gameobjet, int pos);

extern int suppPosListeD(ListeDChaine *liste, int pos);
extern void suppListeD(ListeDChaine *liste);

extern void afficheListeD(ListeDChaine *liste);

#endif // LISTE_DB_CHAINE_H_INCLUDED
