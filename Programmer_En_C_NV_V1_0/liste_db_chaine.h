#ifndef LISTE_DB_CHAINE_H_INCLUDED
#define LISTE_DB_CHAINE_H_INCLUDED
#include "gameobjet.h"

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


#include <stdlib.h>
#include <stdio.h>
#include "liste_db_chaine.h"

void initialiserListe(ListeDChaine *liste);

int insDansListeDVide (ListeDChaine * liste, Gameobjet gameobjet);
int insDebutListeD (ListeDChaine * liste, Gameobjet gameobjet);
int insFinListeD (ListeDChaine * liste, Gameobjet gameobjet);
int insAvantD (ListeDChaine * liste, Gameobjet gameobjet, int pos);
int insApresD (ListeDChaine * liste,Gameobjet gameobjet, int pos);

int suppD(ListeDChaine *liste, int pos);
void detruire(ListeDChaine *liste);

void afficheListeD(ListeDChaine *liste);
void affiche_invListeD(ListeDChaine *liste);


#endif // LISTE_DB_CHAINE_H_INCLUDED
