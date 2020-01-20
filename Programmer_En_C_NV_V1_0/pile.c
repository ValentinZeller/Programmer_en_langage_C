#include "pile.h"

tPile *initialiserPile()
{
    tPile *pPile = malloc(sizeof(*pPile));
    pPile->pPremier = NULL;
    return pPile;
}
void empiler(tPile *pPile, int nvNombre)
//BUT : Empiler une valeur sur la pile.
//ENTREE : Un entier et le pointeur de la pile sur le dernier élément en date.
//SORTIE : La pile mise à jour avec un élément supplémentaire.
{
    tElementPile *pNouveau = malloc(sizeof(*pNouveau));
    if (pPile == NULL || pNouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    pNouveau->nNombre = nvNombre;
    pNouveau->pSuivant = pPile->pPremier;
    pPile->pPremier = pNouveau;
}

int depiler(tPile *pPile)
//BUT : Désempiler une valeur sur la pile.
//ENTREE : Le pointeur de la pile sur le dernier élément en date.
//SORTIE : La valeur de la dernière valeur en date de la Pile et la pile mise à jour avec un élément en moins.
{
    if (pPile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int nDepile = 0;
    tElementPile *elementDepile = pPile->pPremier;

    if (pPile != NULL && pPile->pPremier != NULL)
    {
        nDepile = elementDepile->nNombre;
        pPile->pPremier = elementDepile->pSuivant;
        free(elementDepile);
    }

    return nDepile;
}

void afficherPile(tPile *pPile)
//BUT : Afficher les valeurs de la pile.
//ENTREE : Le pointeur de la pile sur le dernier élément en date.
//SORTIE : Les valeurs des éléments de la pile affichés du dernier entré au premier.
{
    if (pPile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    tElementPile *pActuel = pPile->pPremier;

    while (pActuel != NULL)
    {
        printf("%d\n", pActuel->nNombre);
        pActuel = pActuel->pSuivant;
    }

    printf("\n");
}

