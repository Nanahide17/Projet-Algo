#include "abalone.h"

void defJoueurinit(CASE* casse){
    int x=casse->posX,y=casse->posY;

    if(y==120 || y==225 || y==330){
        if(x>=655 && x<=1260){
            if(y==330 && (x<=720 || x>=1200)){
                casse->couleur=0;
                return;
            }
            casse->couleur=1;
            return;
        }
    }
    else if(y==745 || y==850 || y==955){
        if(x>=655 && x<=1260){
            if(y==745 && (x<=720 || x>=1200)){
                casse->couleur=0;
                return;
            }
            casse->couleur=2;
            return;
        }
    }
    else {
        casse->couleur=0;
        return;
    }
}
