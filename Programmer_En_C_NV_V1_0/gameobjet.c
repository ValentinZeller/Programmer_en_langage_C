#include "gameobjet.h"

void afficherGameObjet(Gameobjet objet) {
    printf("Cle : %d\n",objet.key);
    printf("Mesh : %s\n",objet.mesh);
    printf("X,Y,Z : %d, %d, %d\n",objet.pos.x,objet.pos.y,objet.pos.z);
}

void createGameObjet(Gameobjet *pObjet,int nKey,char *cMesh,int nX,int nY,int nZ) {
    pObjet->key = nKey;
    pObjet->mesh = cMesh;
    pObjet->pos.x = nX;
    pObjet->pos.y = nY;
    pObjet->pos.z = nZ;
}
