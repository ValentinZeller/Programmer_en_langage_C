#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAILLE 10
//Structures Conditions et boucles

int main()
{
    //Condition
    int a=0,b=0,c=0,d=0;
    if(a==b) {
        printf("Ils sont egaux\n");
    } else {
        printf("Ils sont diff\n");
    }
    //Condition avec operateurs logiques
    if ((a==b) && (a==c)) {
        printf("Ils sont tous egaux\n");
    } else {
        printf("Ils sont tous differents\n");
    }

    if((a==b) || (a==c)) {
        printf("Ils sont egaux\n");
    } else {
        printf("Ils sont diff\n");
    }

    if((a==b) || (a==c)) {
        printf("Ils sont egaux\n");
    } else if((a==c)&& (a!=d)){
        printf("blabla...\n");
    }

    //Boucle
    int i=0;

    for(i=0;i<TAILLE;i++) {
        printf("Hello world\n");
    }

    //TQ
    i=0;
    while(i<TAILLE){
        printf("Hello world\n");
        i++;
    }

    //Faire TQ
    i=0;
    do {
        printf("Hello world\n");
        i++;
    } while(i<TAILLE);

    //Cas alternative de la condition
    int choix=-1;
    printf("Veuillez entrez votre choix\n");
    scanf("%d",&choix);
    switch (choix) {
        case 0:printf("Quitter\n");break;
        case 1:printf("Calculer\n");break;
        case 2:printf("Jouer\n");break;
        default:printf("Default\n");
    }

    //test ? instruction1 : instruction 2
    b = a==b? printf("egaux\n"):printf("diff\n");

    //Instruction break;
    for(i=0;i<TAILLE;i++) {
        printf("Hello world\n");
        if (i==3){
            break;
        }
    }

    //Instruction continue
        for(i=0;i<TAILLE;i++) {
        printf("Hello world\n");
        if (i<3){
            printf("continue\n");
            continue;
        }
    }



    /*
    //Exemple d'une condition inclus sinon
    int nCond;
    printf("Entrez un nombre");
    scanf("%d",&nCond);
    if (nCond > 1 && nCond < 10000000) {
        printf("Le nombre est plus grand que 1\n");
    } else {
        printf("Le nombre est plus petit ou egal a 1\n");
    }
    //Exemple d'une condition sans operateur logique
    if (nCond) {
        printf("Existe\n");
    }
    //Exemple de boucle pour
    for (int i = 0;i<=10;i++) {
        printf("%d\n",i);
    }
    //Exemple de boucle tantque
    while (nCond <= 10) {
        printf("Le nombre augmente jusqu'a 10 : %d\n",nCond);
        nCond++;
    }
    //Exemple de boucle faire tantque
    do {
        printf("Le nombre est trop grand : %d\n",nCond);
        nCond--;
    } while (nCond > 0);
    //Exemple avec l'opérateur ternaire
    int nAge;
    nAge = (nCond = 0) ? 18 : 17;
    printf("%d\n",nAge);*/
    return 0;
}
