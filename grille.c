#include <stdio.h>
#include "abalone.h"
#include "donneesSDL.h"

int demande(){
//Demande à l'utilisateur combien de bille il souhaite déplacé
    int demande=0;
    do{
        printf("Combien de billes souhaitez vous déplacer ?\n");
        scanf("%d",&demande);
        if((demande>3) || (demande<=0)){
            printf("Saisie invalide : le nombre de bille doit être compris entre 1 et 3, merci de réessayer\n");
        }
    }while((demande>3) || (demande<=0));
    return demande;
}

///Affichage
void affichage_SDL(){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, imageG, NULL, NULL);
    for(int i=0; i<61; i++){
        if((current_state_bille_noir[i]==NULL) && (current_state_bille_blanc[i]==NULL)){
            continue;
        }
        else if((current_state_bille_noir[i]!=NULL) && (current_state_bille_blanc[i]==NULL)){
            SDL_RenderCopy(renderer, current_state_bille_noir[i], NULL, &casse[i]);
        }
        else if((current_state_bille_noir[i]==NULL) && (current_state_bille_blanc[i]!=NULL)){
            SDL_RenderCopy(renderer, current_state_bille_blanc[i], NULL, &casse[i]);
        }
    }

    SDL_RenderPresent(renderer);
}

///Sélection des billes
void selection_bille(int *liste_bille_selectionne, int nb_bille_a_bouger,SDL_Texture *current_state[61], SDL_Texture *image_bille, TYPE_CASE couleur){

    SDL_Event event1;
    SDL_bool done1= SDL_FALSE;

    int conf=0;
    int nb_bille_selectionne=0;
    DIRECTION direction=0;

    while(!done1){
        while(SDL_PollEvent(&event1)){
            switch(event1.type){
                case SDL_QUIT : ;
                    done1 = SDL_TRUE;
                break;

                case SDL_MOUSEBUTTONDOWN : ;
                    int x1 = event1.button.x;
                    int y1 = event1.button.y;

                    int bille_selectionne=trouveCASE(x1,y1);
                    conf=1;

                    if(current_state[bille_selectionne]==image_bille_bleu){
                        current_state[bille_selectionne]=image_bille;
                        if(nb_bille_selectionne==2){
                            direction=0;
                        }
                        nb_bille_selectionne--;
                        liste_bille_selectionne[nb_bille_selectionne]=-1;

                        printf("Vous avez sélectionnez %d bille(s)\n", nb_bille_selectionne);
                    }
                    else{
                        if(nb_bille_selectionne==nb_bille_a_bouger){
                            printf("Coup impossible\n");
                            printf("Appuyer sur 'ENTRER' une fois la séléction faite\n");
                        }
                        else if(current_state[bille_selectionne]==NULL){
                            printf("Veuillez séléctionner des billes\n");
                        }
                        else{
                            if(nb_bille_selectionne==0){
                                current_state[bille_selectionne]=image_bille_bleu;
                                liste_bille_selectionne[nb_bille_selectionne]=bille_selectionne;
                                nb_bille_selectionne++;
                                printf("Vous avez sélectionnez %d bille(s)\n", nb_bille_selectionne);
                            }
                            else{
                                if(direction==0){
                                    CASE* verif_case=structcase[liste_bille_selectionne[0]];
                                    CASE* verif_case2=structcase[bille_selectionne];

                                    if(verif_case->alentours->NE == verif_case2){
                                        direction=trouveDirection(verif_case, verif_case2);
                                        current_state[bille_selectionne]=image_bille_bleu;
                                        liste_bille_selectionne[nb_bille_selectionne]=bille_selectionne;
                                        nb_bille_selectionne++;
                                        printf("Vous avez sélectionnez %d bille(s)\n", nb_bille_selectionne);
                                    }
                                    else if(verif_case->alentours->E == verif_case2){
                                        direction=trouveDirection(verif_case, verif_case2);
                                        current_state[bille_selectionne]=image_bille_bleu;
                                        liste_bille_selectionne[nb_bille_selectionne]=bille_selectionne;
                                        nb_bille_selectionne++;
                                        printf("Vous avez sélectionnez %d bille(s)\n", nb_bille_selectionne);
                                    }
                                    else if(verif_case->alentours->SE == verif_case2){
                                        direction=trouveDirection(verif_case, verif_case2);
                                        current_state[bille_selectionne]=image_bille_bleu;
                                        liste_bille_selectionne[nb_bille_selectionne]=bille_selectionne;
                                        nb_bille_selectionne++;
                                        printf("Vous avez sélectionnez %d bille(s)\n", nb_bille_selectionne);
                                    }
                                    else if(verif_case->alentours->NO == verif_case2){
                                        direction=trouveDirection(verif_case, verif_case2);
                                        current_state[bille_selectionne]=image_bille_bleu;
                                        liste_bille_selectionne[nb_bille_selectionne]=bille_selectionne;
                                        nb_bille_selectionne++;
                                        printf("Vous avez sélectionnez %d bille(s)\n", nb_bille_selectionne);
                                    }
                                    else if(verif_case->alentours->O == verif_case2){
                                        direction=trouveDirection(verif_case, verif_case2);
                                        current_state[bille_selectionne]=image_bille_bleu;
                                        liste_bille_selectionne[nb_bille_selectionne]=bille_selectionne;
                                        nb_bille_selectionne++;
                                        printf("Vous avez sélectionnez %d bille(s)\n", nb_bille_selectionne);
                                    }
                                    else if(verif_case->alentours->SO == verif_case2){
                                        direction=trouveDirection(verif_case, verif_case2);
                                        current_state[bille_selectionne]=image_bille_bleu;
                                        liste_bille_selectionne[nb_bille_selectionne]=bille_selectionne;
                                        nb_bille_selectionne++;
                                        printf("Vous avez sélectionnez %d bille(s)\n", nb_bille_selectionne);
                                    }
                                    else{
                                        printf("Veuillez séléctionner une bille aux alentours de la première\n");
                                    }
                                }
                                else{
                                    CASE* case2=structcase[liste_bille_selectionne[1]];
                                    CASE* case2bis=structcase[liste_bille_selectionne[0]];
                                    CASE* verif_case;
                                    CASE* verif_case2;
                                    switch(direction){
                                        case NE :
                                            verif_case = case2->alentours->NE;
                                            verif_case2= case2bis->alentours->SO;
                                        break;

                                        case E :
                                            verif_case = case2->alentours->E;
                                            verif_case2= case2bis->alentours->O;
                                        break;

                                        case SE :
                                            verif_case = case2->alentours->SE;
                                            verif_case2= case2bis->alentours->NO;
                                        break;

                                        case NO :
                                            verif_case = case2->alentours->NO;
                                            verif_case2= case2bis->alentours->SE;
                                        break;

                                        case O :
                                            verif_case = case2->alentours->O;
                                            verif_case2= case2bis->alentours->E;
                                        break;

                                        case SO :
                                            verif_case = case2->alentours->SO;
                                            verif_case2= case2bis->alentours->NE;
                                        break;
                                    }
                                    CASE* bille_prise=structcase[bille_selectionne];
                                    if((verif_case!=bille_prise)&&(verif_case2!=bille_prise)){
                                        printf("Veuillez séléctionner un bille dans la continuité de la direction\n");
                                    }
                                    else{
                                        current_state[bille_selectionne]=image_bille_bleu;
                                        liste_bille_selectionne[nb_bille_selectionne]=bille_selectionne;
                                        nb_bille_selectionne++;
                                        printf("Vous avez sélectionnez %d bille(s)\n", nb_bille_selectionne);
                                    }
                                }
                            }
                        }
                    }
                    affichage_SDL(renderer, imageG, current_state_bille_noir,current_state_bille_blanc,casse);
                break;

                case SDL_KEYDOWN : ;
                    if((conf==1) && (nb_bille_selectionne==nb_bille_a_bouger)){
                        printf("Veuillez maintenant cliquez vers la où vous souhaitez vous déplacer\n");
                        deplacement(nb_bille_a_bouger,direction,current_state,couleur);
                        done1=SDL_TRUE;
                    }
                    else{
                        break;
                    }

            }
        }
    }
}

int grille(){

///Déclaration variable
    int nb_bille_a_bouger;
    tour=0;

    printf("\nLes noirs commencent la partie\n");

    while((ejection_blanc!=6)||(ejection_noir!=6)){
        nb_bille_a_bouger=demande(); //On demande à l'utilisateur combien de bille il veut bouger
        selection_bille(&liste_bille_selectionne, nb_bille_a_bouger, current_state_bille_noir,image_bille_noire, NOIR);
        tour=1;
        printf("Aux tours des blancs\n");
        nb_bille_a_bouger=demande();
        selection_bille(&liste_bille_selectionne,nb_bille_a_bouger, current_state_bille_blanc, image_bille_blanc, BLANC);
        printf("Aux tours des noires");
        tour=0;
    }








///Libération mémoire
    SDL_DestroyTexture(imageG);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
