#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TAILLE 100

//Les Typedef
typedef struct tPoint{//Signature du typedef
    int nX;
    int nY;
}tPoint;//Declaration du nouveau type

typedef struct tDroite{ //Composition : composé d'un tableau de point/tableau de point composant
    tPoint tabPoint[TAILLE];
}tDroite;


void setX(tPoint *pt,int nNewX);
void setY(tPoint *pt,int nNewY);
int getX(tPoint pt);
int getY(tPoint pt);
void creaDroite(tDroite * dt, tPoint pt,int nIndex);
tPoint depPoint(tPoint pt,int nNewX,int nNewY);

int main() {
	tPoint newPoint = {0,0};
    setX(&newPoint,5);
    setY(&newPoint,8);

    tDroite dt;
    int i;
    for(i=0;i<TAILLE;i++) {
        creaDroite(&dt,newPoint,i);
    }

    newPoint = depPoint(newPoint,2,3);
    printf("%d\n",newPoint.nX);
    printf("%d\n",newPoint.nY);

	return 0;
}

void setX(tPoint *pt,int nNewX) {
    pt->nX = nNewX;
}

void setY(tPoint *pt,int nNewY) {
    pt->nY = nNewY;
}

int getX(tPoint pt) {
    return pt.nX;
}

int getY(tPoint pt) {
    return pt.nY;
}

void creaDroite(tDroite * dt, tPoint pt,int nIndex) {
    dt->tabPoint[nIndex].nX = pt.nX+nIndex;
    dt->tabPoint[nIndex].nY = pt.nY+nIndex;
    //dt->tabPoint[nIndex] = pt;
}

tPoint depPoint(tPoint pt,int nNewX,int nNewY) {
    pt.nX += nNewX;
    pt.nY += nNewY;
    return pt;
}
