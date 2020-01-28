#include <stdlib.h>
#include <stdio.h>
#include "liste_db_chaine.h"

void initialiserListeD(ListeDChaine *liste) {
    //Initialisation de la liste doublement chaine
    liste = malloc(sizeof(liste));
    liste->debut = NULL;
    liste->fin = NULL;
    liste->taille =0;
}

int ajoutDansListeDVide (ListeDChaine * liste, Gameobjet gameobjet){

    Element *pNouveauElement;

    if ((pNouveauElement =  (Element*) malloc(sizeof(Element))) == NULL) {
        return 1;
    }

    pNouveauElement->objet=gameobjet;

    pNouveauElement->precedent = liste->debut;
    pNouveauElement->suivant = liste->fin;

    liste->debut = pNouveauElement;
    liste->fin = pNouveauElement;

    liste->taille++;

return 0;

}

int ajoutDebutListeD (ListeDChaine * liste, Gameobjet gameobjet){

    Element *pNouveauElement;

    if ((pNouveauElement =  (Element*) malloc(sizeof(Element))) == NULL) {
        return 1;
    }

    pNouveauElement->objet=gameobjet;

    pNouveauElement->precedent = NULL;
    pNouveauElement->suivant = liste->debut;

    liste->debut->precedent = pNouveauElement;
    liste->debut = pNouveauElement;

    liste->taille++;

    return 0;

}


int ajoutFinListeD (ListeDChaine * liste, Gameobjet gameobjet){

    Element *pNouveauElement;

    if ((pNouveauElement =  (Element*) malloc(sizeof(Element))) == NULL) {
        return 1;
    }

    pNouveauElement->objet=gameobjet;

    pNouveauElement->suivant = NULL;
    pNouveauElement->precedent = liste->fin;
    liste->fin->suivant = pNouveauElement;

    liste->fin = pNouveauElement;
    liste->taille++;


return 0;

}

int ajoutAvantPosListeD (ListeDChaine * liste, Gameobjet gameobjet, int nPos){
    int i;
    Element *pNouveauElement, *pCourant;

    if ((pNouveauElement =  (Element*) malloc(sizeof(Element))) == NULL) {
        return 1;
    }


    pNouveauElement->objet=gameobjet;

    pCourant = liste->debut;

    for (i = 1; i < nPos; ++i) {
        pCourant = pCourant->suivant;

        pNouveauElement->suivant = pCourant;
        pNouveauElement-> precedent = pCourant->precedent;

        if(pCourant->precedent == NULL)
            liste->debut = pNouveauElement;
        else pCourant->precedent->suivant = pNouveauElement;
            pCourant->precedent = pNouveauElement;

        liste->taille++;
    }

return 0;

}

int ajoutApresPosListeD (ListeDChaine * liste,Gameobjet gameobjet, int nPos){

    int i;
    Element *pNouveauElement, *pCourant;

    if ((pNouveauElement =  (Element*) malloc(sizeof(Element))) == NULL) {
        return -1;
    }

    pNouveauElement->objet=gameobjet;

    pCourant = liste->debut;

    for (i = 1; i < nPos; ++i) {
        pCourant = pCourant->suivant;
    }

    pNouveauElement->suivant = pCourant->suivant;
    pNouveauElement->precedent = pCourant;

    if(pCourant->suivant == NULL) {
        liste->fin = pNouveauElement;
    } else {
        pCourant->suivant->precedent = pNouveauElement;
    }

    pCourant->suivant = pNouveauElement;
    liste->taille++;

    return 0;
}

int suppPosListeD(ListeDChaine *liste, int nPos){
    int i;
    Element *pElementSupprime,*pCourant;

    if(liste->taille == 0) {
        return 1;
    }

    if(nPos == 1){
    //Cas où on enlève le premier element de la liste
        pElementSupprime = liste->debut;
        liste->debut = liste->debut->suivant;

        if(liste->debut == NULL) {
            liste->fin = NULL;
        }else{
            liste->debut->precedent = NULL;
        }


    }else if(nPos == liste->taille){
    //Cas où on enlève le dernier element de la liste
        pElementSupprime = liste->fin;
        liste->fin->precedent->suivant = NULL;
        liste->fin = liste->fin->precedent;

    }else {
        pCourant = liste->debut;

        for(i=1;i<nPos;++i) {
            pCourant = pCourant->suivant;
            pElementSupprime = pCourant;
            pCourant->precedent->suivant = pCourant->suivant;
            pCourant->suivant->precedent = pCourant->precedent;
        }
    }
    free(pElementSupprime);
    liste->taille--;

return 0;
}


void suppListeD(ListeDChaine *liste){
    while(liste->taille > 0) {
        suppPosListeD(liste,1);
    }
}

void afficheListeD(ListeDChaine *liste){
    Element *pCourant;
    pCourant = liste->debut;

    while(pCourant != NULL){
        afficherGameObjet(pCourant->objet);
        printf("\n");
        pCourant = pCourant->suivant;
    }

}
