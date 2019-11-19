#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TAILLE 10


void Exercice1a();
void Exercice1b();
void Exercice2(int nEntier[],int taille,int *nMax, int *nMin);
void Exercice3(int nEntier[]);
void Exercice4(double dblTab[][10],double dblTab2[][10],double resultTab[][10],int taille, int taille2);

int main() {
    int i,j;
    const int taille = 10;
    const int taille2 = 2;
    int nEntier[10] = {1,2,3,40,-5,6,7,8,9,2}; //Tableau pour les exercices 2 et 3
    double dblMat[2][10] = {{1,2,3,40,-5,6,7,8,9,2},{1,2,3,40,-2,6,7,8,9,2}}; //Matrice 1 pour exercice 4
    double dblMat2[2][10] = {{1,2,3,80,-5,6,7,8,18,2},{1,2,3,80,-5,6,7,12,9,2}}; //Matrice 12pour exercice 4
    double dblResult[2][10] = {{0}}; //Matrice resultat pour exercice 4
    /* Exercice 1
    Exercice1a();
    Exercice1b();
    */


    /* Exercice 2
    int nMax = nEntier[0];
    int nMin = nEntier[0];
    Exercice2(nEntier,taille,&nMax,&nMin);
    printf("Max : %d Min : %d\n",nMax,nMin);
    */

    /* Exercice 3
    Exercice3(nEntier);
    for (i=0;i<TAILLE;i++) {
        printf("%d ",nEntier[i]);
    }
    */

    /* Exercice 4
    Exercice4(dblMat,dblMat2,dblResult,taille,taille2);

    //Affichage matrice résultat
    for (i=0;i<taille2;i++) {
        for (j=0;j<taille;j++) {
            printf("%1.1f ",dblResult[i][j]);
        }
        printf("\n");
    }
    */

    return 0;
}

void Exercice1a() {
    /* Exercice 1 formalisme tableau*/
    int ntabInt[TAILLE];
    int i =0;
    for (i=0;i<TAILLE;i++) {
        printf("Entrez le nombre %d\n",i);
        scanf("%d",&ntabInt[i]);
    }
    int nMax = ntabInt[0];
    int nMin = ntabInt[0];

    for (i=0;i<TAILLE;i++) {
        if (ntabInt[i] > nMax) {
            nMax = ntabInt[i];
        } else if (ntabInt[i] < nMin) {
            nMin = ntabInt[i];
        }
    }
    printf("Le nombre le plus grand : %d \n",nMax);
    printf("Le nombre le plus petit : %d \n",nMin);
}

void Exercice1b() {
    /* Exercice 1 formalisme pointeur*/
    int ntabInt[TAILLE] = {0};
    int i =0;
    for (i=0;i<TAILLE;i++) {
        printf("Entrez le nombre %d\n",i);
        scanf("%d",&*(ntabInt+i));
    }
    int nMax = *(ntabInt);
    int nMin = *(ntabInt);

    for (i=0;i<TAILLE;i++) {
        if (*(ntabInt+i) > nMax) {
            nMax = *(ntabInt+i);
        } else if (*(ntabInt+i) < nMin) {
            nMin = *(ntabInt+i);
        }
    }
    printf("Le nombre le plus grand : %d\n",nMax);
    printf("Le nombre le plus petit : %d\n",nMin);
}

void Exercice2(int nEntier[],int taille,int *nMax, int *nMin) {
//Trouver le min et max
    int i=0;
    for (i=0;i<taille;i++) {
        if (nEntier[i] > *nMax) {
            *nMax = nEntier[i];
        }
        if (nEntier[i] < *nMin) {
            *nMin = nEntier[i];
        }
    }
}

void Exercice3(int nEntier[]) {
//Tri croissant
    int i=0;
    int j=0;
    int taille = 10;
    int nMin;
    int nMinI;
    int nA;
    for (i=0;i<5;i++) {
        nMin = nEntier[i];
        nMinI = i;
        for (j=i;j<10;j++) {
            if (nEntier[j] < nMin) {
                nMin = nEntier[j];
                nMinI = j;
            }
        }
        nA = nEntier[i];
        nEntier[i] = nMin;
        nEntier[nMinI] = nA;
    }
}

void Exercice4(double dblTab[][10],double dblTab2[][10],double resultTab[][10],int taille, int taille2) {
//Somme de deux matrices
    int i=0;
    int j=0;
    for (i=0;i<taille2;i++) {
        for (j=0;j<taille;j++) {
            resultTab[i][j] = dblTab[i][j] + dblTab2[i][j];
        }
    }
}
