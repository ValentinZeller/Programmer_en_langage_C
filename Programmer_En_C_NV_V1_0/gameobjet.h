#ifndef GAMEOBJET_H_INCLUDED
#define GAMEOBJET_H_INCLUDED
#include <stdio.h>

//Game Objet
typedef struct Vect3 {
    int x,y,z;
}Vect3;

typedef struct Gameobjet {
    int key;
    char *mesh;
    Vect3 pos;
}Gameobjet;

extern void afficherGameObjet(Gameobjet objet);
extern void createGameObjet(Gameobjet *pObjet,int nKey,char *cMesh,int nX,int nY,int nZ);

#endif // GAMEOBJET_H_INCLUDED
