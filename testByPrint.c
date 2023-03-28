#include <stdio.h>
#include "abalone.h"

void testByPrint(int i){
    CASE* casse=structcase[i];
    int x=casse->posX, y=casse->posY;
    int couleur=casse->couleur;

    printf("Coordonnées en x : %d\n",x);
    printf("Coordonnées en y : %d\n",y);
    printf("Couleur de la case : %d\n\n",couleur);
}
