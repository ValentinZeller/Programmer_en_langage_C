#include <stdio.h>
#include <stdlib.h>
#include <math.h>




//Pointeurs

int sommeEntiers(int nA, int nB);
void somEntiers(int nA, int nB, int *pnRes);

int main()
{
    //Déclaration Pointeur
    //Un pointeur pointe vers une référence mémoire
    //Un pointeur lors de son initialisation doit avoir une référence NULL
    int *pnPointeurEntier=NULL;
    int nEntier=10;


    //Pointeur pointe sur référence nEntier
    pnPointeurEntier = &nEntier;
    *pnPointeurEntier =88;
    nEntier = 500;

    //int **ppnEntier=&pnPointeurEntier;

    int nEntier2 = 200;

    nEntier = sommeEntiers(10,88);

    printf("%d\n",nEntier);

    int nResSomme = 0;

    somEntiers(56,12,&nResSomme);
    printf("%d\n",nResSomme);

    return 0;
}

int sommeEntiers(int nA, int nB) {
    return nA+nB;
}

void somEntiers(int nA, int nB, int *pnRes){ //* = Passage d'argument par adresse
    *pnRes = nA+nB;
}
