#include <stdio.h>
#include <stdlib.h>
#include "method.h"

int main ()
{
    int nMenuInput =0;
    do {
    //Menu d'accueil tant qu'on ne quitte pas
        nMenuInput = nMenu();
        switch (nMenuInput) {
            case 1 :
            //Nouvelle partie
                Bataille();
                break;

            case 2 :
            //Afficher le score
                afficherResultats();
                break;

            case 3 :
            //Quitter
                return 1;
      }
    } while (nMenuInput != 3);
  return 0;
}

