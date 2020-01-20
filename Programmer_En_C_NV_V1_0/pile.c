#include "pile.h"

tPile *initialiserPile()
{
    tPile *pPile = malloc(sizeof(*pPile));
    pPile->pPremier = NULL;
    return pPile;
}
void empiler(tPile *pPile, int nvNombre)
//BUT : Empiler une valeur sur la pile.
//ENTREE : Un entier et le pointeur de la pile sur le dernier �l�ment en date.
//SORTIE : La pile mise � jour avec un �l�ment suppl�mentaire.
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
//BUT : D�sempiler une valeur sur la pile.
//ENTREE : Le pointeur de la pile sur le dernier �l�ment en date.
//SORTIE : La valeur de la derni�re valeur en date de la Pile et la pile mise � jour avec un �l�ment en moins.
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
//ENTREE : Le pointeur de la pile sur le dernier �l�ment en date.
//SORTIE : Les valeurs des �l�ments de la pile affich�s du dernier entr� au premier.
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

