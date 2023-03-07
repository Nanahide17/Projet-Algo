#include <stdio.h>
#include <stdlib.h>

typedef enum COULEUR{
    Noir =1,
    Blanc =0,
}couleur;

typedef struct piece{
    int pos;
    couleur joueur;
    struct piece *suiv;
}pion;

int main(){
    return(0);
}