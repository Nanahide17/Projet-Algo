#include <stdio.h>
#include <stdlib.h>
#include "abalone.h"

void initialisationPlateau(){
        //Initialisation des cases de jeu
    for(int i=0; i<61; i++){
        CASE *casse = (CASE *)malloc(sizeof(CASE));
        creationCase(casse,i);
        printf("Case n°%d :\n",60-i);
        testByPrint(i);
    }
}
