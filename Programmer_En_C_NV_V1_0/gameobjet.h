#ifndef GAMEOBJET_H_INCLUDED
#define GAMEOBJET_H_INCLUDED

//Game Objet
typedef struct Vect3 {
    int x,y,z;
}Vect3;

typedef struct Gameobjet {
    int key;
    char *mesh;
    Vect3 pos;
}Gameobjet;

void afficherGameObjet(Gameobjet objet);

#endif // GAMEOBJET_H_INCLUDED
