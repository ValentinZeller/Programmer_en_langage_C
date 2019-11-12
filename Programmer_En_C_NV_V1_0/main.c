#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Exercices

void f1();
void f2(int nA);
int f3(int nA);
void fct(int p);
void appel();


int n=5; //Exercice 2 : variable globale

int main()
{
    int i=0;

    f1(); //Exercice 1 bonjour 1 fois
    f2(3); //Exercice 1 bonjour autant de fois que le paramètre
    f3(2); //Exercice 1  bonjour autant de fois que le paramètre et return 0

    int n = 3; //Exercice 2 :  variable locale
    fct(n); //Exercice 2 : Affiche 5 (n globale) puis 3(n locale)

    for (i=0;i<1000;i++) {//Exercice 3
        appel();
    }


    return 0;
}

void f1() {// Exercice 1 : bonjour une fois
    printf("Bonjour\n");
}

void f2(int nA) {// Exercice 1 : bonjour nA fois
    int i = 0;
    for(i=0;i<nA;i++) {
        printf("Bonjour\n");
    }
}

int f3(int nA) { // Exercice 1 : bonjour nA fois et return 0
    int i = 0;
    for(i=0;i<nA;i++) {
        printf("Bonjour\n");
    }
    return 0;
}

void fct(int p) { //Affiche 5 (n globale) puis 3(n locale)
    printf("%d %d\n",n,p);
}

void appel() { //Exercice 3
    static long lnAppel=0;
    static double fltPower=0;
    lnAppel++;
    if (lnAppel%(long)pow(10.0,fltPower) == 0) {
        printf("*** appel %d fois ***\n",(int)lnAppel);
        fltPower++;
    }
}
