#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct tElementPile tElementPile;
struct tElementPile
//Type structur� r�cursif (ou autor�f�rentiel), appele un �l�ment de m�me type/genre
//Type structur� pour un �l�ment de la pile
//Stock une valeur enti�re et le pointeur vers l'�l�ment suivant (ins�r� juste avant)
{
    int nNombre;
    tElementPile *pSuivant;
};

typedef struct tPile tPile;
struct tPile
//Type structur� pour une pile
//Stock le dernier �l�ment ins�r�
{
    tElementPile *pPremier;
};

extern tPile *initialiserPile();
extern void empiler(tPile *pPile, int nvNombre);
extern int depiler(tPile *pPile);
extern void afficherPile(tPile *pPile);

#endif // PILE_H_INCLUDED
