#include <math.h>
#include "pile.h"
#include "file.h"
#include "liste_db_chaine.h"


int main()
//Stock des game objets, pour l'affichage dans la vue, sous un modèle de données abstraits : liste doublement chainée
{
    Gameobjet Obj,Obj2,Obj3;
    ListeDChaine ListeObj;
    initialiserListe(&ListeObj);

    Obj.key = 1;
    Obj.mesh = "Mesh1";
    Obj.pos.x = 0;
    Obj.pos.y = 0;
    Obj.pos.z = 0;

    Obj2 = Obj;
    Obj2.key = 2;
    Obj3 = Obj;
    Obj3.key = 3;

    insDansListeDVide(&ListeObj,Obj);
    insDebutListeD(&ListeObj,Obj2);
    insApresD(&ListeObj,Obj3,1);
    afficheListeD(&ListeObj);
    suppD(&ListeObj,1);
    afficheListeD(&ListeObj);

    return 0;
}

