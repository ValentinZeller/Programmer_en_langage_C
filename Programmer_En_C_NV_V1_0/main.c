#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAILLE 10
#define MOT "HELLO"

//Les entrées sorties conversationnelles

int main()
{
    //Affichage
    printf("%d\n",TAILLE);
    printf("%s\n",MOT);

    //Saisie
    /*int val;
    scanf("%d",&val);
    fflush(stdin); //vide le buffer de la saisie
    char car;
    scanf("%c",&car);
    fflush(stdin);*/
    /*char tabCar[TAILLE]; //de 0 à TAILLE-1
    gets(tabCar); //récupére string
    printf("%s",tabCar);*/

    char c;
    printf("Entrez un caractere\n");
    scanf("%c",&c);
    while (((c>='a')&&(c<='z'))||((c>='A')&&(c<='Z') ) ) {
        printf("Le caractere saisi est : %c\n",c);
        fflush(stdin);
        scanf("%c",&c);
    }
/*
    c = getchar();
        while (((c>='a')&&(c<='z'))||((c>='A')&&(c<='Z') ) ) {
        printf("Le caractere saisi est : %c\n",c);
        fflush(stdin);
        c = getchar();
    } */
    return 0;
}
