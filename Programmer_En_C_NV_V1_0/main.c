#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAILLE 10

//Prototypes
void initMatrice(int nMatriceEntier[][TAILLE],int nValInit);
void afficheMatrice(int nMatriceEntier[][TAILLE]);
void initMatrice2(int nMatriceEntier[][TAILLE],int nNVal,int nValInit);
int nSommeEltMatrice(int nMatriceEntier[][TAILLE],int nNVal);
//Les tableaux 2 dim, fonctions et prodc�dures

int main()
{
    //Tableau 2 dim entier
    int nMatriceEntier[TAILLE][TAILLE];
    int nMatriceEntier2[TAILLE][TAILLE];

    initMatrice(nMatriceEntier,0);
    afficheMatrice(nMatriceEntier);
    initMatrice2(nMatriceEntier2,5,10);

    int i,j;
    //Affichage Matrice
    for(i=0;i<5;i++) {
        for (j=0;j<TAILLE;j++) {
            printf("%d",nMatriceEntier2[i][j]);
        }
        printf("\n");
    }

    int nResSommeMatrice = nSommeEltMatrice(nMatriceEntier2,5);
    printf("Resultat de la somme de notre matrice : %d\n",nResSommeMatrice);


    return 0;
}
//Implémenation des fonctions
//Procédures

//Init
void initMatrice(int nMatriceEntier[][TAILLE],int nValInit) {
  int i,j;

  for(i=0;i<TAILLE;i++) {
      for (j=0;j<TAILLE;j++) {
          nMatriceEntier[i][j] = nValInit;
      }
  }
}
void initMatrice2(int nMatriceEntier[][TAILLE],int nNVal,int nValInit) {
  int i,j;

  for(i=0;i<nNVal;i++) {
      for (j=0;j<TAILLE;j++) {
          nMatriceEntier[i][j] = nValInit;
      }
  }
}

//Calcul
int nSommeEltMatrice(int nMatriceEntier[][TAILLE],int nNVal) {
  int i,j;
  int nResSommeMatrice = 0;

  for(i=0;i<nNVal;i++) {
      for (j=0;j<TAILLE;j++) {
          nResSommeMatrice += nMatriceEntier[i][j];
      }
  }
  return nResSommeMatrice;
}

//Layout
void afficheMatrice(int nMatriceEntier[][TAILLE]) {
    int i,j;
    //Affichage Matrice
    for(i=0;i<TAILLE;i++) {
        for (j=0;j<TAILLE;j++) {
            printf("%d",nMatriceEntier[i][j]);
        }
        printf("\n");
    }
}
