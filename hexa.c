#include <stdio.h>
#include <stdlib.h>
#include "outils.h"


/*
int hexacasse(nbille){
    int max =17;
    for(int j=0; j<nbille; j++){
        for(int i=0; i<max; i++){
            if(i %2 == 1){
                printf("0");
            }
            else{
                printf("1");
            }
        }
    printf("\n");
    }
}
*/

int hexa(nbille){
    int lignemax =9; int ligne=0;
    int nzero =4;
    int a=4;

    while(ligne < 4){
        while(a > 0){
            printf("-");
            a--;
        }
        printf("\n");
        nzero--;
        a = nzero;
        ligne++;
    }
}

int main (){
    int nbille = 9;
    printf("Je fais un hexagone \n");
    hex(nbille);
    return(0);
}