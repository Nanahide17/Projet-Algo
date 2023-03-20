#include <stdio.h>
#include <stdlib.h>
//  -lSDL2 -lSDL2_image 

typedef enum COULEUR{
    Noir =1,
    Blanc =0,
}couleur;

typedef struct piece{
    int posx,posy;
    int numéro;
    couleur joueur;
    struct piece *suiv;
    struct dir *alentours;
}pion;

typedef struct dir{
    pion *NE;
    pion *NO;
}direction;

int init(pion* elm){
    elm->posx =1;
    return(0);
}

void verif(pion premier){
    if(premier.posx != NULL){
        printf("Il y a un voisin \n");
    }
    else{
        printf("Case Libre \n");
    }
}

pion premier; pion deuxième;

int main(){
    init(&premier); init(&deuxième);
    verif(premier);
    return(0);
}