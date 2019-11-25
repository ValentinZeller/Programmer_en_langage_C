#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAILLE 2

//Exercices sur les types
typedef struct point {
    int num;
    float x;
    float y;
}point;

void Exercice1();
void Exercice2();
void saisieTabPoint(point *tabPoint,int taille);
void affichageTabPoint(point *tabPoint,int taille);

int main()
{
    Exercice1();
    Exercice2();
    return 0;
}

void Exercice1() {
    point tabPoint[TAILLE] = {0};
    int i=0;
    for (i=0;i<TAILLE;i++) {
        tabPoint[i].num = i;

        printf("Veuillez entrez la coord x du point %d \n",tabPoint[i].num);
        scanf("%f",&tabPoint[i].x);

        printf("Veuillez entrez la coord y du point %d \n",tabPoint[i].num);
        scanf("%f",&tabPoint[i].y);
        printf("\n");
    }

    for (i=0;i<TAILLE;i++) {
        printf("Point : %d\n",tabPoint[i].num);
        printf("Coord x : %1.1f\n",tabPoint[i].x);
        printf("Coord y : %1.1f\n",tabPoint[i].y);
        printf("\n");
    }
}

void Exercice2() {
    point tabPoint[] = {0};
    saisieTabPoint(tabPoint,TAILLE);
    affichageTabPoint(tabPoint,TAILLE);
}

void saisieTabPoint(point *tabPoint,int taille) {
    int i=0;
    for (i=0;i<taille;i++) {
        tabPoint[i].num = i;

        printf("Veuillez entrez la coord x du point %d \n",tabPoint[i].num);
        scanf("%f",&tabPoint[i].x);

        printf("Veuillez entrez la coord y du point %d \n",tabPoint[i].num);
        scanf("%f",&tabPoint[i].y);
        printf("\n");
    }
}

void affichageTabPoint(point *tabPoint,int taille) {
    int i=0;
    for (i=0;i<taille;i++) {
        printf("Point : %d\n",tabPoint[i].num);
        printf("Coord x : %1.1f\n",tabPoint[i].x);
        printf("Coord y : %1.1f\n",tabPoint[i].y);
        printf("\n");
    }
}
