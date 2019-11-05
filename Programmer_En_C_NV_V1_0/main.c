#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Exercices

void f1();
void f2(int nA);
int f3(int nA);
void fct(int p);
void appel();

int n=5;
static long lnAppel=0;

int main()
{

    f1();
    f2(3);
    f3(2);

    int n = 3;
    fct(n); //Affiche 5 n(globale) puis 3(locale)
    appel();
    appel();

    printf("%d\n",lnAppel);

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

void appel() {
    lnAppel++;
}
