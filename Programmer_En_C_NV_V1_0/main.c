#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define VERT 2
#define JAUNE 14
#define GRISCLAIR 7
#define ROUGE 12

#define TAILLECODE 4
#define NBESSAIS 13


void initRandomCode(char cTabSecret[TAILLECODE],int taille);
void initTabColor(int nTabColor[NBESSAIS][TAILLECODE+1],int taille);
void saisieTentative(char cTabTentative[TAILLECODE],int taille);
void afficheEssais(char cTabEssais[NBESSAIS][TAILLECODE+1],int nTabColor[NBESSAIS][TAILLECODE+1],int nb,int taille);
void colorCode(char cTabSecret[TAILLECODE+1],char cTabTentative[TAILLECODE+1],int taille,int nTabColor[NBESSAIS][TAILLECODE+1],int nEssai);
int verifCode(int nTabColor[NBESSAIS][TAILLECODE+1],int nEssai);


void color(int t,int f) {
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}


int main()
{
    srand(time(NULL)); //Mise en place du generateur aleatoire de nombre

    int i = 0;
    char cTabEssais[NBESSAIS][TAILLECODE+1];//Stocke toutes les saisies avec l'affichage des couleurs
    char cTabTentative[TAILLECODE+1];//Stocke la saisie utilisateur
    char cTabSecret[TAILLECODE+1];//Stocke le code à trouver
    int nTabColor[NBESSAIS][TAILLECODE+1] = {{0}};//Stocke pour chaque code saisi si les valeurs sont bonnes et bien ou mal place
    int nEssai = 1;//Numero de l'essai en cours, inferieur à 12
    int verif = 0;//Stocke si l'utilisateur a trouve le code ou non

    initTabColor(nTabColor,TAILLECODE);
    initRandomCode(cTabSecret,TAILLECODE);

    while (nEssai<NBESSAIS && verif != TAILLECODE*VERT) {
    //Si l'utilisateur n'a pas trouve le code et qu'il a fait moins de 12 tentatives il peut retenter
        saisieTentative(cTabTentative,TAILLECODE);

        for (i=0;i<TAILLECODE;i++) {//Saisie utilisateur stocké dans la liste des codes saisis par l'utilisateur
            cTabEssais[nEssai][i] = cTabTentative[i];
        }
        //Pour la saisie faite, on determine si l'utilisateur a trouve des valeurs et si elles sont bien places
        colorCode(cTabSecret,cTabTentative,TAILLECODE,nTabColor,nEssai);

        //Affichage des precedents codes saisis par l'utilisateur
        system("cls");
        color(JAUNE,0);
        printf("\nEssais : \n");
        afficheEssais(cTabEssais,nTabColor,nEssai+1,TAILLECODE);
        printf("\n");

        nEssai++;
        verif = verifCode(nTabColor,nEssai-1);
        if (verif != TAILLECODE*VERT) {
            color(ROUGE,0);
            printf("Il reste %d essais\n",NBESSAIS-nEssai);
            color(GRISCLAIR,0);
        }
    }


    if (verif == TAILLECODE*VERT) {
        color(0,VERT);
        printf(" Gagne \n");
        color(GRISCLAIR,0);
    } else {
        color(0,ROUGE);
        printf(" Perdu \n");
        printf(" Le code etait %s \n",cTabSecret);
        color(GRISCLAIR,0);
    }
}

void initRandomCode(char cTabSecret[TAILLECODE],int taille) {
//BUT : Initialisation du taleau ayant le code secret à une valeur aléatoire
    int i=0;
    char cRandom = 0;
    for (i=0;i<taille;i++) {
        cRandom = rand()%10 + '0';
        cTabSecret[i] = cRandom;
    }
    cTabSecret[TAILLECODE] = '\0';
}

void initTabColor(int nTabColor[NBESSAIS][TAILLECODE+1],int taille) {
//BUT : Initialisation du tableau à la couleur grise (pas d'indication)
    int i=0;
    int j=0;
    for (i=0;i<NBESSAIS;i++) {
        for (j=0;j<taille;j++) {
            nTabColor[i][j] = GRISCLAIR;
        }
    }
}

void saisieTentative(char cTabTentative[TAILLECODE],int taille) {
//BUT : Saisie de l'utilisateur d'un code, verification que la saisie est valide
    int i=0;
    int nSaisieValide = 0;
    fflush(stdin);
    do {
        printf("Entrez un code de 4 chiffres (0-9)\n");
        fgets(cTabTentative,5,stdin); //L'utilisateur saisit 4 caracteres
        nSaisieValide = 0;
        for (i=0;i<taille;i++) {//Verification que chaque caractere saisie est entre 0 et 9
            if (cTabTentative[i] >= '0' && cTabTentative[i] <= '9') {
                nSaisieValide++;
            }
        }
    } while (nSaisieValide < 4);
}

int verifCode(int nTabColor[NBESSAIS][TAILLECODE+1],int nEssai) {
//BUT : Verifier si le code a ete trouve
    int i=0;
    int verif=0;
    for (i=0;i<TAILLECODE;i++) {
        verif += nTabColor[nEssai][i];
    }
    return verif;
}

void colorCode(char cTabSecret[TAILLECODE+1],char cTabTentative[TAILLECODE+1],int taille,int nTabColor[NBESSAIS][TAILLECODE+1],int nEssai) {
//BUT : Determine les couleurs du code saisie en fonction de la valeur et du placement (bien place = vert, mal place = jaune)
//ENTREE : cTabSecret : code secret
//         cTabTentative : saisie utilisateur
//          taille : taille des tableaux ici TAILLECODE
//          nTabColor : pour chaque valeur de chaque tentative, stocke la couleur (initialisée à gris)
//          nEssai : Numero de la tentative en cours,
    int pos = 0;
    int trouve = 0;
    int i=0;

    for (i=0;i<taille;i++) {
        if (cTabSecret[i] == cTabTentative[i]) {
        //Même valeur et bien placee
            trouve = 1;
            cTabTentative[i] = (int)"-1";
            nTabColor[nEssai][i] = VERT;
        } else {
            pos = 0;
            while (trouve == 0 && pos < taille) {
                if (cTabSecret[i] == cTabTentative[pos]) {
                    //Même valeur et mal placee
                    cTabTentative[pos] = (int)"-1";
                    trouve = 1;
                    nTabColor[nEssai][pos] = JAUNE;
                }
                pos++;
            }
        }
        trouve = 0;
    }
}



void afficheEssais(char cTabEssais[NBESSAIS][TAILLECODE+1],int nTabColor[NBESSAIS][TAILLECODE+1],int nb,int taille) {
//BUT : Affiche toutes les codes saisies par l'utilisateur
    int i=0;
    int j=0;
    for (i=1;i<nb;i++) {
        for (j=0;j<taille;j++) {
            color(nTabColor[i][j],0);
            printf("%c",cTabEssais[i][j]);
            color(7,0);
        }
        printf("\n");
    }
}

