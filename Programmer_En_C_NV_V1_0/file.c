#include "file.h"

tFile *initialiserFile()
{
    tFile *pFile = malloc(sizeof(*pFile));
    pFile->pPremier = NULL;
    return pFile;
}

void enfiler(tFile *pFile, int nvNombre)
{
    tElementFile *pNouveau = malloc(sizeof(*pNouveau));
    if (pFile == NULL || pNouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    pNouveau->nNombre = nvNombre;
    pNouveau->pSuivant = NULL;

    if (pFile->pPremier != NULL) /* La file n'est pas vide */
    {
        /* On se positionne � la fin de la file */
        tElementFile *pActuel = pFile->pPremier;
        while (pActuel->pSuivant != NULL)
        {
            pActuel = pActuel->pSuivant;
        }
        pActuel->pSuivant = pNouveau;
    }
    else /* La file est vide, notre �l�ment est le pPremier */
    {
        pFile->pPremier = pNouveau;
    }
}

int defiler(tFile *pFile)
{
    if (pFile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    int nDefile = 0;

    /* On v�rifie s'il y a quelque chose � d�filer */
    if (pFile->pPremier != NULL)
    {
        tElementFile *pDefile = pFile->pPremier;

        nDefile = pDefile->nNombre;
        pFile->pPremier = pDefile->pSuivant;
        free(pDefile);
    }
    return nDefile;
}

void afficherFile(tFile *pFile)
//BUT : Afficher les valeurs de la file.
{
    if (pFile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    tElementFile *pActuel = pFile->pPremier;
    while (pActuel != NULL)
    {
        printf("%d ", pActuel->nNombre);
        pActuel = pActuel->pSuivant;
    }
    printf("\n");
}

