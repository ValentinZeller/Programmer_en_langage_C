#include "liste_db_chaine.h"

int main()
//Stock des game objets, pour l'affichage dans la vue, sous un modèle de données abstraits : liste doublement chainée
{
    Gameobjet Obj,Obj2,Obj3; //Création des gameobjets
    ListeDChaine ListeObj; // Création de la liste doublement chainee
    initialiserListeD(&ListeObj); //Initialisation de la liste dchaine

    //Initialiation des game objets
    createGameObjet(&Obj,1,"Mesh1",0,0,0);
    createGameObjet(&Obj2,2,"Mesh2",2,0,2);
    createGameObjet(&Obj3,3,"Mesh3",0,3,1);

    ajoutDansListeDVide(&ListeObj,Obj); // Ajout d'un gameobjet dans la liste

    printf("Etat de la Liste Doublement Chainee : \n");
    afficheListeD(&ListeObj);

    ajoutDebutListeD(&ListeObj,Obj2); //Ajout d'un gameobjet au debut de la liste
    ajoutApresPosListeD(&ListeObj,Obj3,1); //Ajout d'un gameobjet après la position 1 (position 2)

    printf("Etat de la Liste Doublement Chainee : \n");
    afficheListeD(&ListeObj);

    suppPosListeD(&ListeObj,2); //Gameobjet à la position 1 supprimé

    printf("Etat de la Liste Doublement Chainee : \n");
    afficheListeD(&ListeObj);

    ajoutAvantPosListeD(&ListeObj,Obj3,2);

    printf("Etat de la Liste Doublement Chainee : \n");
    afficheListeD(&ListeObj);

    suppListeD(&ListeObj);

    return 0;
}

