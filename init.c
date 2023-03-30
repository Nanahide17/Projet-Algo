#include <stdio.h>
#include <stdlib.h>
#include "abalone.h"
#include "Donnees.h"

void initialisationPlateau(){
        //Initialisation des cases de jeu
    for(int i=0; i<61; i++){
        //Création des cases
        CASE *casse = (CASE *)malloc(sizeof(CASE));
        creationCase(casse,i);
        POS *alentours = (POS*)malloc(sizeof(POS));
        casse->alentours=alentours;
    }
    alentour();
}

void creationCase(CASE* casse, int i){
    //Insertion des coordonnées des cases et du type de case qu'il sera
    int x=coplateau[0][i],y=coplateau[1][i];
    casse->posX=x;
    casse->posY=y;
    defJoueurinit(casse);
    structcase[i] = casse;
}

void defJoueurinit(CASE* casse){
    //En fonction de la position de la case, on attribut le type de case qu'il sera
    int x=casse->posX,y=casse->posY;
    //Vérification si case avec pion blanc ou non
    if(y==120 || y==225 || y==330){
        if(x>=655 && x<=1260){
            if(y==330 && (x<=720 || x>=1200)){
                casse->couleur=0;
                return;
            }
            casse->couleur=2;
            return;
        }
    }
    //Vérification si case avec pion noir ou non
    else if(y==745 || y==850 || y==955){
        if(x>=655 && x<=1260){
            if(y==745 && (x<=720 || x>=1200)){
                casse->couleur=0;
                return;
            }
            casse->couleur=1;
            return;
        }
    }
    //Sinon on le recense en case vide
    else {
        casse->couleur=0;
        return;
    }
}

void alentour(){
    //Pour lier nos différentes cases il nous a fallu passer par des pile pour pouvoir créer un plan
    //Création des piles pour chaque ligne de jeu
    PILE *LIGNE0=(PILE*)malloc(sizeof(PILE)),
    *LIGNE1=(PILE*)malloc(sizeof(PILE)),
    *LIGNE2=(PILE*)malloc(sizeof(PILE)),
    *LIGNE3=(PILE*)malloc(sizeof(PILE)),
    *LIGNE4=(PILE*)malloc(sizeof(PILE)),
    *LIGNE5=(PILE*)malloc(sizeof(PILE)),
    *LIGNE6=(PILE*)malloc(sizeof(PILE)),
    *LIGNE7=(PILE*)malloc(sizeof(PILE)),
    *LIGNE8=(PILE*)malloc(sizeof(PILE));
    //Initialisation de chaque pile en fonction de la ligne de jeu
    for(int i=0;i<5;i++){
        initialisationPile(LIGNE0,structcase[i]);
    }
    for(int i=5;i<11;i++){
        initialisationPile(LIGNE1,structcase[i]);
    }
    for(int i=11;i<18;i++){
        initialisationPile(LIGNE2,structcase[i]);
    }
    for(int i=18;i<26;i++){
        initialisationPile(LIGNE3,structcase[i]);
    }
    for(int i=26;i<35;i++){
        initialisationPile(LIGNE4,structcase[i]);
    }
    for(int i=35;i<43;i++){
        initialisationPile(LIGNE5,structcase[i]);
    }
    for(int i=43;i<50;i++){
        initialisationPile(LIGNE6,structcase[i]);
    }
    for(int i=50;i<56;i++){
        initialisationPile(LIGNE7,structcase[i]);
    }
    for(int i=56;i<61;i++){
        initialisationPile(LIGNE8,structcase[i]);
    }
    //Liaisons entre les différentes lignes
    reliageBas(LIGNE0,LIGNE1);
    reliageBas(LIGNE1,LIGNE2);
    reliageBas(LIGNE2,LIGNE3);
    reliageBas(LIGNE3,LIGNE4);

}

void initialisationPile(PILE *pil,CASE *casse){
    //Initialisation des piles
    CASE *parent=pil->premier;

    if(pil->premier == NULL){
        pil->premier = casse;
    }
    else {
        while(parent->alentours->E != NULL){
            parent = parent->alentours->E;
        }
        parent->alentours->E = casse;
        casse->alentours->O = parent;
    }

}

void reliageBas(PILE *pile1,PILE *pile2){
    //Reliage entre deux piles
    //Ici nous nous chargeons que de la partie bas
    CASE *case_pile1 = pile1->premier, *case_pile2 = pile2->premier;

    case_pile1->alentours->O = NULL;
    case_pile2->alentours->O = NULL;
    case_pile1->alentours->SO = NULL;
    case_pile2->alentours->SO = NULL;

    while(case_pile1!= NULL){
        case_pile1->alentours->NO = case_pile2;
        case_pile1->alentours->NE = case_pile2->alentours->E;

        case_pile2->alentours->SE =case_pile1;
        case_pile2 = case_pile2->alentours->E;
        case_pile2->alentours->SO =case_pile1;

        case_pile1 = case_pile1->alentours->E;
    }
    case_pile1->alentours->E = NULL;
    case_pile2->alentours->E = NULL;
    case_pile1->alentours->SE = NULL;
    case_pile2->alentours->SE = NULL;
}

void reliageHaut(PILE* pile1, PILE* pile2){
    //Reliage entre deux piles
    //Ici nous nous chargeons que de la partie bas
    CASE *case_pile1 = pile1->premier, *case_pile2 = pile2->premier;

    case_pile1->alentours->O = NULL;
    case_pile2->alentours->O = NULL;
    case_pile1->alentours->NO = NULL;
    case_pile2->alentours->NO = NULL;

    while(case_pile2!= NULL){
        case_pile2->alentours->SO = case_pile1;
        case_pile2->alentours->SE = case_pile1->alentours->E;

        case_pile1->alentours->NE=case_pile2;
        case_pile1 = case_pile1->alentours->E;
        case_pile1->alentours->NO=case_pile2;

        case_pile2=case_pile2->alentours->E;
    }
    case_pile1->alentours->E = NULL;
    case_pile2->alentours->E = NULL;
    case_pile1->alentours->NE = NULL;
    case_pile2->alentours->NE = NULL;
}
