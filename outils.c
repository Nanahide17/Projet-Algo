#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "abalone.h"
#include "outils.h"

///Récupère les coordonnées du clic de l'utilisateur et renvoie la CASE présente au coordonnées données
///Si le clic ne correspond à aucune case, alors on ne renvoie pas de CASE
CASE* trouveCASE(int X, int Y){
    //Parcours de l'ensembles des cases
    for(int i=0; i<61; i++){
        if(isInsideCASE(X,Y,structcase[i])){
            return structcase[i];
        }
    }
    //Si le point n'est dans aucune case, on retourne NULL
    return NULL;
}

///Fonction qui détermine si le point est à l'intérieur de la case
///Source : http://www.playchilla.com/how-to-check-if-a-point-is-inside-a-hexagon => on utilise la logique de ce site
bool isInsideCASE(int X, int Y, CASE* casse){
    double q2x = abs(X-casse->posX);
    double q2y = abs(Y-casse->posY);

    int largeur_cadran = 60;
    double hauteur_cadran = 34.64; //largeur_cadran/(2*cos(M_PI/6));

    if(q2x>largeur_cadran || q2y>hauteur_cadran*2){//On teste si le point est dans le carré "circoncrit" de l'hexagone
        return false;
    }
    return (2*hauteur_cadran*largeur_cadran-hauteur_cadran*q2x-largeur_cadran*q2y >= 0);
}
