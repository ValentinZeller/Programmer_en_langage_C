#include "gameobjet.h"
#include <stdio.h>

void afficherGameObjet(Gameobjet objet) {
    printf("Cle : %d\n",objet.key);
    printf("Mesh : %s\n",objet.mesh);
    printf("X,Y,Z : %d, %d, %d\n",objet.pos.x,objet.pos.y,objet.pos.z);
}
