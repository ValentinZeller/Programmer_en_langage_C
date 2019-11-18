#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TAILLE 100

char *ctabCar(char cChaine[TAILLE]);
int *ntabInt(int nEntier[TAILLE]);
int *ntabInt2D(int nEntier[10][10]);

// Pointeurs

int main() {
    /* char cSaisie[TAILLE]={"Votre Nom"};

    char *cNom;
    //&cNom[1] : décalage d'1 octet, 4 si c'était entier

    cNom=ctabCar(cSaisie);
    printf("Votre nom %s\n",cNom); */

    int nEntier[100] = {0}; //= faire la boucle d'initialisation
    ntabInt(nEntier);

    //int nTabEntier[][] = { {0,1,2,...},{0,1,2,...} }
    int nEntier2[10][10] = {{0}};
    int *pInt = ntabInt2D(nEntier2);

    int i;
    int *p;
    for (i=0;i<TAILLE;i++) {
        printf("%d ",*(pInt)++);
        p=pInt;
    }

    return 0;
}


//Tableau = Pointeur
char * ctabCar(char cChaine[TAILLE]) {
    printf("Entrez votre nom\n");
    scanf("%s",cChaine);
    return cChaine;
}

int * ntabInt(int nEntier[TAILLE]) {
    int i;

    for (i=0;i<TAILLE;i++) {
        *(nEntier+1)=0;//nEntier[i]=0
    }

    return nEntier;
}


int * ntabInt2D(int nEntier[10][10]) {
    int i,j;
    for (i=0;i<10;i++) {
        for (j=0;j<10;j++) {
            *(*(nEntier+i)+j)=10;//nEntier[i][j]=10;
        }
    }

    return (int*)nEntier;//Tableau 2D != Pointeur donc cast
}
