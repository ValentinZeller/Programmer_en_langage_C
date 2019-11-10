#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Exercices

void f1();
void f2(int nA);
int f3(int nA);
void fct(int p);
void appel(long *plnAppel,double *pfltPower);


int n=5; //déclaration de l'Exerice 2


int main()
{
    int i=0;
    static long lnAppel=0;
    double fltPower=0;

    f1(); //Exercice 1 bonjour 1 fois
    f2(3); //Exercice 1 bonjour autant de fois que le paramètre
    f3(2); //Exercice 1  bonjour autant de fois que le paramètre et return 0

    int n = 3;
    fct(n); //Affiche 5 (n globale) puis 3(n locale)

    for (i=0;i<1000000;i++) {
        appel(&lnAppel,&fltPower);
    }


    return 0;
}

void f1() {
    printf("Bonjour\n");
}

void f2(int nA) {
    int i = 0;
    for(i=0;i<nA;i++) {
        printf("Bonjour\n");
    }
}

int f3(int nA) {
    int i = 0;
    for(i=0;i<nA;i++) {
        printf("Bonjour\n");
    }
    return 0;
}

void fct(int p) {
    printf("%d %d\n",n,p);
}

void appel(long *plnAppel,double *pfltPower) { //Exercice 3
    *plnAppel = *plnAppel + 1;
    if (*plnAppel%(long)pow(10.0,*pfltPower) == 0) {
        printf("*** appel %d fois ***\n",(int)*plnAppel);
        *pfltPower = *pfltPower + 1;
    }
}
