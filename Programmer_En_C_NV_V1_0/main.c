#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TAILLE 100
#define TAILLENOM 100
#define TAILLEPRENOM 100
#define TAILLEADRESSE 255
#define TAILLECP 10
#define TAILLEVILLE 40

int main()
{
    //Tout ce qui est déclaré est déclaré dans la pile
    /*int nTabInteger[TAILLE];
    float fltTabFloat[TAILLE];
    double dblTabDouble[TAILLE];

    char cTabCar[TAILLE];

    int nI = 0;
    for(nI=0;nI<TAILLE;nI++) {
        nTabInteger[nI]=0;
        fltTabFloat[nI]=0.0;
        dblTabDouble[nI]=0.0;
        cTabCar[nI]='\0'; // '\0' caractere de fin de chaine
    }*/
    //Creation de carte d'identite
    //Saisir numero d'identifiant, nom, prenom, ddn, adresse postale : numero, nom de la rue, code postal, ville
    static int nId = 0; //Persistance : donnée conservée à la même adresse mémoire peu importe la fonction
    char cNom[TAILLENOM];
    char cPrenom[TAILLEPRENOM];
    char cDDN[10];
    char cAdresse[TAILLEADRESSE];
    char cCP[TAILLECP];
    char cVille[TAILLEVILLE];

    const char FinDeSaisie = 'n';
    char cContinue[TAILLE];

    do {
        printf("Carte d'identite \n");
        printf("Saisir Nom ? \n");
        fgets(cNom,TAILLENOM,stdin);

        fflush(stdin);
        printf("Saisir Prenom ? \n");
        fgets(cPrenom,TAILLEPRENOM,stdin);

        fflush(stdin);
        printf("Saisir Date de naissance ? \n");
        gets(cDDN);

        fflush(stdin);
        printf("Saisir Adresse ? \n");
        fgets(cAdresse,TAILLEADRESSE,stdin);

        fflush(stdin);
        printf("Saisir Code postal ? \n");
        scanf("%5s",cCP);

        fflush(stdin);
        printf("Saiisir Ville ? \n");
        fgets(cVille, TAILLEVILLE,stdin);

        ++nId;

        //affichage
        printf("Identite :\n");
        printf("%d ",nId);
        printf("%s %s",cNom,cPrenom);
        printf("Ne.e le %s \n",cDDN);
        printf("Adresse : %s %s %s\n",cAdresse,cCP,cVille);
        do {
        printf("Nouvelle saisie ? (o/n)\n");
        scanf("%s",cContinue);
        fflush(stdin);
        } while (strcmp(cContinue,"o") && strcmp(cContinue,"n"));

    } while (cContinue[0]!=FinDeSaisie);

    return 0;
}
