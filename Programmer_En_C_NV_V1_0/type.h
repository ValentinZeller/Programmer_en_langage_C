#ifndef TYPE_H_INCLUDED
#define TYPE_H_INCLUDED

#define TAILLE_GRILLE 10
#define NB_BATEAU 5
#define NB_CELLULE 5
#define GRISCLAIR 7
#define VERT 2
#define PTS 50
#define PTSMIN 10


typedef struct tCell {
    int nLigne;
    int nColonne;
    int nTouche;
}tCell;

typedef struct tBateau {
    tCell tabCellule[NB_CELLULE];
    int nTaille;
    int nCoule;
}tBateau;

typedef struct tFlotte {
    tBateau tabBateau[NB_BATEAU];
}tFlotte;

#endif // TYPE_H_INCLUDED
