#include "abalone.h"
#include "Donnees.h"

void creationCase(CASE* casse, int i){
    int x=coplateau[0][i],y=coplateau[1][i];
    casse->posX=x;
    casse->posY=y;
    defJoueurinit(casse);
    structcase[i] = casse;
}
