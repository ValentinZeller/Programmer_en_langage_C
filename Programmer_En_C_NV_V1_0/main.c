#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAILLE 100
//Les Typedef

typedef struct tPoint{//Signature du typdef

    int nX;
    int nY;

}tPoint,*ptPoint;//Declaration du nouveau type



typedef struct tDroite{

    tPoint tabPoint[TAILLE];

}tDroite;


//Les enumerations
typedef  enum couleur{jaune,rouge,bleu,vert} couleur;
//Commence a index 0
// Si typedef  enum couleur{jaune=1,rouge=2,bleu,vert} couleur;
//Alors index commence a 1


typedef struct tInfoDroite{

    char cNomDroite[100];
    tDroite dr;
    couleur coul;

}tInfoDroite;




int main()
{
    //renvoie a la declaration de l'alias de la structure tPoint
    ptPoint pPoint=NULL;//Cette declaration correspond à un pointeur.


    //Creation d'une varialbe de type tPoint

    tPoint pts={0,0}; //Initialisation des membres de la structure

    pPoint=&pts;

    printf("x:%d\n",pPoint->nX);
    printf("y:%d\n",pPoint->nY);


    int i=0;
    tDroite dr;

    for(i=0;i<TAILLE;i++){

        dr.tabPoint[i]=pts;

    }

    tInfoDroite iDroite={"segment",{0,0,1,2},jaune};//Peut generer un warning car nous n'initialisons pas les 100 valeurs.
    //Initilisation d'un membre de type tInfoDroite


    for(i=0;i<TAILLE;i++){

        printf("Nom de la droite : %s", iDroite.cNomDroite);
        printf("x: %d", iDroite.dr.tabPoint[i].nX);
        printf("y: %d", iDroite.dr.tabPoint[i].nY);
        printf("y: %d", iDroite.coul);//Cela donne id(int) de la couleur

    }






   return 0;
}
