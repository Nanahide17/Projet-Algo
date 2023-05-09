#include <stdio.h>
#include "abalone.h"
#include"donneesSDL.h"

int trouveCASE(int X, int Y){
    //Parcours de l'ensembles des cases
    for(int i=0; i<61; i++){
        if(isInsideCASE(X,Y,structcase[i])){
            return i;
        }
    }
    //Si le point n'est dans aucune case, on retourne NULL
    return -1;
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
    return true;
}

DIRECTION trouveDirection(CASE* emplacement_bille, CASE* destination){
    float x_bille = emplacement_bille->posX, y_bille= emplacement_bille->posY;
    float x_destination = destination->posX, y_destination = destination->posY;
    float x,y;

    x=(x_bille/x_destination);
    y=(y_bille/y_destination);

    if(x>1){
    //Si l'utilisateur veut aller vers O
        if(y>1){
        //Si l'utilisateur veut aller vers NO
            return NO;
        }

        else if(y==1){
        //Si l'utilisateur veut aller pleine O
            return O;
        }
        else if(y<1){
        //Si l'utilisateur veut aller vers SO
            return SO;
        }
    }
    if(x<1){
    //Si l'utilisateur veut aller vers E
        if(y>1){
        //Si l'utilisateur veut aller vers NE
            return NE;
        }

        else if(y==1){
        //Si l'utilisateur veut aller pleine E
            return E;
        }
        else if(y<1){
        //Si l'utilisateur veut aller vers SE
            return SE;
        }
    }
    return EXIT_FAILURE;
}


///Tri la liste liste_bille_selectionne pour faciliter le traitement
void triCASE(int nb_bille){
    int temp;

    switch(nb_bille){
        case 1 : ;
        break;

        case 2 : ;
            int bille1=liste_bille_selectionne[0];
            int bille2=liste_bille_selectionne[1];

            if(bille1>bille2){
                temp=liste_bille_selectionne[0];
                liste_bille_selectionne[0]=liste_bille_selectionne[1];
                liste_bille_selectionne[1]=temp;
            }
        break;

        case 3 : ;
            int bille1bis=liste_bille_selectionne[0];
            int bille2bis=liste_bille_selectionne[1];
            int bille3=liste_bille_selectionne[2];

            if(bille1bis>bille2bis){
                temp=liste_bille_selectionne[0];
                liste_bille_selectionne[0]=liste_bille_selectionne[1];
                liste_bille_selectionne[1]=temp;
            }
            if(bille1bis>bille3){
                temp=liste_bille_selectionne[0];
                liste_bille_selectionne[0]=liste_bille_selectionne[2];
                liste_bille_selectionne[2]=temp;
            }
            if(bille2bis>bille3){
                temp=liste_bille_selectionne[1];
                liste_bille_selectionne[1]=liste_bille_selectionne[2];
                liste_bille_selectionne[2]=temp;
            }

        break;
    }


}
