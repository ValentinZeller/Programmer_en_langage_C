#ifndef CELLULE_H_INCLUDED
#define CELLULE_H_INCLUDED

typedef struct tCell {
    int nLigne;
    int nColonne;
    int nTouche;
}tCell;

struct tCell CreerCell(int row, int col);
int nCompCell(tCell cell1, tCell cell2);

#endif // CELLULE_H_INCLUDED
