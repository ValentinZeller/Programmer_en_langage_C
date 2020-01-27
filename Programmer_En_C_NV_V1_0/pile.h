#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct tElementPile tElementPile;
struct tElementPile
//Type structuré récursif (ou autoréférentiel), appele un élément de même type/genre
//Type structuré pour un élément de la pile
//Stock une valeur entière et le pointeur vers l'élément suivant (inséré juste avant)
{
    int nNombre;
    tElementPile *pSuivant;
};

typedef struct tPile tPile;
struct tPile
//Type structuré pour une pile
//Stock le dernier élément inséré
{
    tElementPile *pPremier;
};

extern tPile *initialiserPile();
extern void empiler(tPile *pPile, int nvNombre);
extern int depiler(tPile *pPile);
extern void afficherPile(tPile *pPile);

#endif // PILE_H_INCLUDED
