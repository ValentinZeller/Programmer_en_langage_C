#include <math.h>
#include "pile.h"
#include "file.h"

//Les Types Abstraits de Données

int main()
//BUT : Utiliser les méthodes de gestion de la pile et de la file
{
    //Les Piles (LIFO)
    tPile *pMaPile = initialiserPile();

    empiler(pMaPile, 13);
    empiler(pMaPile, 12);
    empiler(pMaPile, 56);
    empiler(pMaPile, 42);

    printf("\nEtat de la pile :\n");
    afficherPile(pMaPile);

    printf("Je depile %d\n", depiler(pMaPile));
    printf("Je depile %d\n", depiler(pMaPile));

    printf("\nEtat de la pile :\n");
    afficherPile(pMaPile);

    //Les Files (FIFO)

    tFile *pMaFile = initialiserFile();
    enfiler(pMaFile,2);
    enfiler(pMaFile,3);
    enfiler(pMaFile,4);
    enfiler(pMaFile,5);

    printf("\nEtat de la file : \n");
    afficherFile(pMaFile);

    printf("Je defile %d\n", defiler(pMaFile));
    printf("Je defile %d\n", defiler(pMaFile));

    printf("\nEtat de la file : \n");
    afficherFile(pMaFile);

    return 0;
}

