#include <stdlib.h>
#include <stdio.h>
#include "liste_db_chaine.h"

void initialiserListe(ListeDChaine *liste) {
    liste = malloc(sizeof(liste));
    liste->debut = NULL;
    liste->fin = NULL;
    liste->taille =0;
}

int insDansListeDVide (ListeDChaine * liste, Gameobjet gameobjet){

    Element *nouveau_element;

    if ((nouveau_element =  (Element*) malloc(sizeof(Element))) == NULL) return -1;

    nouveau_element->objet=gameobjet;

    nouveau_element->precedent = liste->debut;
    nouveau_element->suivant = liste->fin;

    liste->debut = nouveau_element;
    liste->fin = nouveau_element;

    liste->taille++;

return 0;

}

int insDebutListeD (ListeDChaine * liste, Gameobjet gameobjet){

    Element *nouveau_element;

    if ((nouveau_element =  (Element*) malloc(sizeof(Element))) == NULL)
    return -1;

    nouveau_element->objet=gameobjet;

    nouveau_element->precedent = NULL;
    nouveau_element->suivant = liste->debut;

    liste->debut->precedent = nouveau_element;
    liste->debut = nouveau_element;

    liste->taille++;

    return 0;

}


int insFinListeD (ListeDChaine * liste, Gameobjet gameobjet){

    Element *nouveau_element;

     if ((nouveau_element =  (Element*) malloc(sizeof(Element))) == NULL)
        return -1;

    nouveau_element->objet=gameobjet;

    nouveau_element->suivant = NULL;
    nouveau_element->precedent = liste->fin;
    liste->fin->suivant = nouveau_element;

    liste->fin = nouveau_element;
    liste->taille++;


return 0;

}

int insAvantD (ListeDChaine * liste, Gameobjet gameobjet, int pos){
    int i;
    Element *nouveau_element, *courant;

   if ((nouveau_element =  (Element*) malloc(sizeof(Element))) == NULL)
        return -1;


    nouveau_element->objet=gameobjet;

    courant = liste->debut;

    for (i = 1; i < pos; ++i)
        courant = courant->suivant;

        nouveau_element->suivant = courant;
        nouveau_element-> precedent = courant->precedent;

        if(courant->precedent == NULL)
            liste->debut = nouveau_element;
        else courant->precedent->suivant = nouveau_element;
            courant->precedent = nouveau_element;

        liste->taille++;

return 0;

}

int insApresD (ListeDChaine * liste,Gameobjet gameobjet, int pos){

    int i;
    Element *nouveau_element, *courant;

      if ((nouveau_element =  (Element*) malloc(sizeof(Element))) == NULL)
        return -1;

    nouveau_element->objet=gameobjet;

    courant = liste->debut;

    for (i = 1; i < pos; ++i)
        courant = courant->suivant;

    nouveau_element->suivant = courant->suivant;
    nouveau_element->precedent = courant;

    if(courant->suivant == NULL)
        liste->fin = nouveau_element;
    else
        courant->suivant->precedent = nouveau_element;

    courant->suivant = nouveau_element;
    liste->taille++;

    return 0;
}

int suppD(ListeDChaine *liste, int pos){

        int i;
        Element *supp_element,*courant;

        if(liste->taille == 0) return -1;

            if(pos == 1){ /* suppresion de 1er élément */

                supp_element = liste->debut;

                liste->debut = liste->debut->suivant;

                if(liste->debut == NULL)
                    liste->fin = NULL;
                else
                    liste->debut->precedent = NULL;


           }else if(pos == liste->taille){ /* suppression du dernier élément */

               supp_element = liste->fin;
               liste->fin->precedent->suivant = NULL;
               liste->fin = liste->fin->precedent;

            }else { /* suppression ailleurs */
                    courant = liste->debut;

                    for(i=1;i<pos;++i)
                        courant = courant->suivant;

                    supp_element = courant;
                    courant->precedent->suivant = courant->suivant;
                    courant->suivant->precedent = courant->precedent;
            }


            free(supp_element);
            liste->taille--;
return 0;
}


void detruire(ListeDChaine *liste){

        while(liste->taille > 0)
            suppD(liste,1);
}

void afficheListeD(ListeDChaine *liste){
    Element *courant;
    courant = liste->debut;
    printf("[ ");
        while(courant != NULL){
                afficherGameObjet(courant->objet);
                courant = courant->suivant;
        }
    printf("]\n");
}


void affiche_invListeD(ListeDChaine *liste){

    Element *courant;
    courant = liste->fin;
    while(courant != NULL){
            printf("%d : ",courant->objet.key);
            courant = courant->precedent;
    }
    printf("\n");

}
