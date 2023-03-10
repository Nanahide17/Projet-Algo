#include <stdio.h>
#include <stdlib.h>
#include "outils.h"


// LE BUT DU PROGRAMME EST DE REPERER LES CASES JOUABLES; ON METTRA UN 1 LA OU ON PEUT JOUER ET 0 AILLEURS //

int hexa(nbille){
    int lignemax =9; int ligne=0;
    int nzero =4;
    int a=4;
    int rest;

    // On décalle pour centrer l'hexagone 
    while(ligne < 4){
        while(a > 0){
            printf(" ");
            a--;
        }

        rest = lignemax -a ;
        lignemax+=2;

        // faire les 0 et 1 de toutes les lignes 
        for (int i=0; i<rest; i++){
             if(i %2 == 1){
                printf("0");
            }
            else{
                printf("1");
            }
        }

        printf("\n");
        nzero--;
        a = nzero;
        ligne++;
    }

    
    // MOITIE DE L'HEXAGONE
    rest =17;
    for (int i=0; i<rest; i++){
        if(i %2 == 1){
            printf("0");
        }
        else{
            printf("1");
        }
    }
    printf("\n");
    ligne++;

    // On espace pour centrer l'hexagone
    while(ligne < 9){
        while(a < (nzero +1)){
            printf (" ");
            a++;
        }

        //Faire les 0 et les 1 de toutes les lignes 
        lignemax-=1;
        rest = lignemax -a ;

        for (int j=0; j<rest; j++){
            if(j %2 == 1){
                printf("0");
            }
            else{
                printf("1");
            }
        }
        printf("\n");

        a = 0;
        nzero++;
        ligne++;
    }
    
    
}


int grillevide(){
    int lignemax =9; int ligne=0;
    int nzero =4;
    int a=4;
    int rest;

    // On décalle pour centrer l'hexagone 
    while(ligne < 4){
        while(a > 0){
            printf(" ");
            a--;
        }

        rest = lignemax -a ;
        lignemax+=2;

        // faire les 0 et 1 de toutes les lignes 
        for (int i=0; i<rest; i++){
             printf("0");
        }

        printf("\n");
        nzero--;
        a = nzero;
        ligne++;
    }

    
    // MOITIE DE L'HEXAGONE
    rest =17;
    for (int i=0; i<rest; i++){
        printf("0");
    }
    printf("\n");
    ligne++;

    // On espace pour centrer l'hexagone
    while(ligne < 9){
        while(a < (nzero +1)){
            printf (" ");
            a++;
        }

        //Faire les 0 et les 1 de toutes les lignes 
        lignemax-=1;
        rest = lignemax -a ;

        for (int j=0; j<rest; j++){
            printf("0");
        }
        printf("\n");

        a = 0;
        nzero++;
        ligne++;
    }
}

int grilledep(){
    int lignemax =9; int ligne=0;
    int nzero =4;
    int a=4;
    int rest;

    // On décalle pour centrer l'hexagone 
    while(ligne < 4){
        while(a > 0){
            printf(" ");
            a--;
        }

        rest = lignemax -a ;
        lignemax+=2;

        // faire les N pour les pions noirs (en haut de la grille);
        for (int i=0; i<rest; i++){
             if(i %2 == 1){
                printf("0");
            }
            else{
                if(ligne == 0 || ligne == 1){
                    printf("N");
                }
                else if(ligne == 2){
                    if(i==4 || i== 6 || i==8){
                        printf("N");
                    }
                    else{
                        printf("1");
                    }
                }
                else {
                    printf("1");
                }
            }
        }

        printf("\n");
        nzero--;
        a = nzero;
        ligne++;
    }

    
    // MOITIE DE L'HEXAGONE
    rest =17;
    for (int i=0; i<rest; i++){
        if(i%2 == 0){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    printf("\n");
    ligne++;

    // On espace pour centrer l'hexagone
    while(ligne < 9){
        while(a < (nzero +1)){
            printf (" ");
            a++;
        }

        //Faire les pions Blancs en bas de l'hexagone.
        lignemax-=1;
        rest = lignemax -a ;

        for (int j=0; j<rest; j++){
            if(j %2 == 1){
                printf("0");
            }
            else{
                if(ligne == 7 || ligne == 8){
                    printf("B");
                }
                else if(ligne == 6){
                    if(j==4 || j== 6 || j==8){
                        printf("B");
                    }
                    else{
                        printf("1");
                    }
                }
                else {
                    printf("1");
                }
            }
        }
        printf("\n");

        a = 0;
        nzero++;
        ligne++;
    }
    
    
}


int main (){
    int nbille = 9;
    printf("Je fais un hexagone qui a des '1' la où les cases sont jouables... \n");
    hexa(nbille);
    printf("\n Je fais un hexagone initialisé à zéro...\n");
    grillevide();
    printf("\n Je fais un hexagone avec les positions de départs... \n");
    grilledep();
    return(0);
}