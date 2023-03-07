#include <stdio.h>
#include <stdlib.h>
#include "tableau.h"
#include "outils.h"

int eq,billes,n;
char direction;


//la fonction doit prendre en compte l'équipe
// SI EQ = 1   lES BILLES SONT NOIRES

void deplacement(eq,billes,direction){
    
    char direction;

    printf("Entrez votre équipe :\n");
    scanf("%d",eq);

    //appeler la fonction mouvement 

   
   

    if ((eq == 1) && (numéro <15)){
// CREER UNE FONCTION EJECTEE 
        //if (BILLE N° == EJECT) {
            printf("la boule est déjà ejectée");
            //rappeler la fonction 
        }
        else{
            printf("Entrez la direction de mouvement : NE,NO,SE,SO,E,O \n");
            scanf("%c",direction);

            /*CHOIX DE LA DIRECTION
            switch(direction){
                case NE : MOUVEMENTS
                case NO : 
                case SE : 
                case SO :
                case E :
                case O : 
                default :
                    printf("Mouvement invalide \n"); REFAIRE LE MOUVEMENT

            }
            */
        }
    }
    

}









int main(){
    printf("test\n");
    tableau();
    return(0);
}