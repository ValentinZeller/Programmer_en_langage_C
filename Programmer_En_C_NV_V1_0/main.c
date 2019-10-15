#include <stdio.h>
#include <stdlib.h>
#include <math.h>//macro pour appeler le fichier header math avec des prototypes de méthodes

#define NFOIS 5 //constante
#define PI 3.14
#define NOM "Zeller"
#define CAR 'x'
//# : macro utilisé dans la compilation par le pré processeur

//Exemple de programme en C

int main()
{
    //Integer
    short int nA;//short sn
    int nB;
    long int nC;//long ln

    const int cntT=10;

    volatile int nVolB;

    static int nStatB;

    printf("Taille de a : %d\n",sizeof(nA));
    printf("Taille de b : %d\n",sizeof(nB));
    printf("Taille de c : %d\n",sizeof(nC));

    //Real
    float fltReelSimple;
    double dblReelDouble;
    //long double
    printf("Taille de reel simple : %d\n",sizeof(fltReelSimple));
    printf("Taille de reel double : %d\n",sizeof(dblReelDouble));

    //Character
    char cCaractere;
    printf("Taille de caractere : %d\n",sizeof(cCaractere));

    //Tester Define
    printf("NFOIS : %d\n",NFOIS);
    printf("PI : %f\n",PI);
    printf("NOM : %s\n",NOM);
    printf("CAR : %c\n",CAR);

    //Opérateurs
    int nI=0;
    ++nI; //pré-incrémentation
    nI++; //post-incrémentation
    // % modulo
    // / division

    //Cast
    long double ldblLongDouble=105.89522;
    printf("Val de long double : %lf", (double)ldblLongDouble);

    //Opérateurs relationnels
    // < > <= >= == !=

    //Opérateurs logiques
    // & ET && ET sans forcément tout vérifier
    // | ET || OU sans forcément tout vérifier
    // ! NON

    //Factorisation opérateurs
    // += -= *= /= %= ...

    //Exemple d'une condition avec operateur logique inclus sinon
    //Exemple d'une condition sans operateur logique
    //Exemple de boucle pour
    //Exemple de boucle tantque
    //Exemple de boucle faire tantque
    //Exemple avec l'opérateur ternaire

    return 0;
}

/*void main()
{
        int i;
    float x;
    float racx;

    printf("Bonjour\n");

    racx=sqrt(x);
    printf("Calcul de %d racine carré \n",NFOIS);
    for (i=0; i<NFOIS; i++)
    {
        printf("Donnez un nombre : ");
        scanf("%f",&x); //fonction servent à récupérer la saisie de donnée d'un certain type
        if (x<0.0) //.0 important car c'est un réel
            printf("Le nombre %f ne possede pas de racine carree\n",x);
        else
        {
            racx = sqrt(x);
            printf("Le nombre %f a pour racine carree : %f\n",x,racx);
        }
    }
    printf("Travail termine - Au revoir"); //Pas d'accent console
}*/
