#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NFOIS 5 //Constante

//Exemple de programme en C

int main()
{
    int i;
    float x;
    float racx;

    printf("Bonjour\n");

    racx=sqrt(x);
    printf("Calcul de %d racine carr� \n",NFOIS);
    for (i=0; i<NFOIS; i++)
    {
        printf("Donnez un nombre : ");
        scanf("%f",&x); //fonction servent � r�cup�rer la saisie de donn�e d'un certain type
        if (x<0.0) //.0 important car c'est un r�el
            printf("Le nombre %f ne possede pas de racine carree\n",x);
        else
        {
            racx = sqrt(x);
            printf("Le nombre %f a pour racine carree : %f\n",x,racx);
        }
    }
    printf("Travail termine - Au revoir"); //Pas d'accent console

    return 0;
}
