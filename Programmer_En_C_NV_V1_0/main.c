#include <stdio.h>

int main()
{
    /*Exercice 1
    int nI, nN, nSom;
    nSom = 0;
    while (nI<4) {
        printf("Donnez un entier\n");
        scanf("%d",&nN);
        nSom += nN;
        nI++;
    }
    printf("Somme : %d\n",nSom);

    nI = 0;
    nSom = 0;
    do {
        printf("Donnez un entier\n");
        scanf("%d",&nN);
        nSom += nN;
        nI++;
    } while (nI<4);
    printf("Somme : %d\n",nSom);
    */

    /*Exercice 2 Moyenne
    float fltNote,fltMoy,fltI;
    fltI = 0;
    fltMoy = 0;
    fltNote = 0;
    do {
        printf("note %1.0f : ",fltI);
        scanf("%f",&fltNote);
        if (fltNote >= 0) {
            fltMoy += fltNote;
            fltI++;
        }
    } while (fltNote >= 0);
    fltMoy =  fltMoy/fltI;
    printf("moyenne de ces %1.0f notes : %2.2f\n",fltI,fltMoy);
    */

    /* Exercice 3 Triangle d'étoiles
    int nNb = 0;
    int nI =0;
    int nJ =0;
    printf("Entrez un nombre\n");
    scanf("%d",&nNb);
    for (nI=0;nI<nNb;nI++) {
        for (nJ=0;nJ<=nI;nJ++) {
            printf("*");
        }
        printf("\n");
    }
    */

    /* Exercice 4 Nombre Premier
    int nPremier = 0;
    int nI = 2;
    int nDiv = 0;
    printf("Entrez un nombre\n");
    scanf("%d",&nPremier);
    while (nI<=(nPremier/2) && nDiv<2) {
        if (nPremier%i == 0) {
            nDiv++;
        }
        nI++;
    }
    if (nDiv<2) {
        printf("%d est un nombre premier\n",nPremier);
    } else {
        printf("%d n'est pas un nombre premier\n",nPremier);
    } */

    /* Exercice 5 Suite de Fibonacci
    int nNbsuite = 0;
    int nSuite = 1;
    int nSuite2 = 1;
    int nSuiteold = 0;
    int nI = 0;
    printf("Entrez un nombre\n");
    scanf("%d",&nNbsuite);
    for (nI =2;nI<=nNbsuite;nI++) {
        nSuiteold = nSuite;
        nSuite += nSuite2;
        nSuite2 = nSuiteold;
    }
    printf("Le nombre est : %d\n",nSuite); */

    /* Exercice 6 Table de multiplication
    int nI,nJ;
    int nResult = 0;
    for (nI=1;nI<=10;nI++) {
        for (nJ=1;nJ<=10;nJ++) {
            nResult = nI*nJ;
            printf("4%d ",nResult);
        }
        printf("\n");
    }
    */

    return 0;
}
