#include <stdio.h>
#include "abalone.h"
#include "donneesSDL.h"

void deplacement(int nb_bille_a_bouger, DIRECTION direction, SDL_Texture *current_state[61], TYPE_CASE couleur){
    cliqueSurDeplacement(nb_bille_a_bouger,current_state,couleur);
}

void cliqueSurDeplacement(int nb_bille_a_bouger, SDL_Texture *current_state[61], TYPE_CASE couleur){

    SDL_Event event;
    SDL_bool done=SDL_FALSE;

    while(!done){
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT : ;
                    done = SDL_TRUE;
                break;

                case SDL_MOUSEBUTTONDOWN : ;
                    int x = event.button.x;
                    int y = event.button.y;

                    int case_selectionne=trouveCASE(x,y);

                    if(current_state[case_selectionne]!=0){
                        printf("Veuillez séléctionner une case sans bille de votre couleur\n");
                    }
                    else{
                        int nb_bille=nb_bille_a_bouger;

                        //Vérification si case séléctionné est bien au alentours de la case
                        CASE* verif_case_deplacement=structcase[case_selectionne];

                        switch(nb_bille){
                            case 1 : ;
                                CASE* case_a_deplace = structcase[liste_bille_selectionne[0]];
                                CASE* caseNO =case_a_deplace->alentours->NO;
                                CASE* caseO =case_a_deplace->alentours->O;
                                CASE* caseSO =case_a_deplace->alentours->SO;
                                CASE* caseNE =case_a_deplace->alentours->NE;
                                CASE* caseE =case_a_deplace->alentours->E;
                                CASE* caseSE =case_a_deplace->alentours->SE;


                                if(verif_case_deplacement==caseNO){
                                    if(verificationDeplacement(nb_bille,NO)){
                                        if(couleur==NOIR){
                                            current_state[case_selectionne]=image_bille_noire;
                                            current_state[liste_bille_selectionne[0]]=NULL;
                                        }
                                        else{
                                            current_state[case_selectionne]=image_bille_blanc;
                                            current_state[liste_bille_selectionne[0]]=NULL;
                                        }
                                        affichage_SDL();
                                        done=SDL_TRUE;
                                    }
                                    break;
                                }
                                else if(verif_case_deplacement==case_a_deplace->alentours->O){
                                    if(verificationDeplacement(nb_bille,O)){
                                        if(couleur==NOIR){
                                            current_state[case_selectionne]=image_bille_noire;
                                            current_state[liste_bille_selectionne[0]]=NULL;
                                        }
                                        else{
                                            current_state[case_selectionne]=image_bille_blanc;
                                            current_state[liste_bille_selectionne[0]]=NULL;
                                        }
                                        affichage_SDL();
                                        done=SDL_TRUE;
                                    }
                                    break;
                                }
                                else if(verif_case_deplacement==case_a_deplace->alentours->SO){
                                    if(verificationDeplacement(nb_bille,SO)){
                                        if(couleur==NOIR){
                                            current_state[case_selectionne]=image_bille_noire;
                                            current_state[liste_bille_selectionne[0]]=NULL;
                                        }
                                        else{
                                            current_state[case_selectionne]=image_bille_blanc;
                                            current_state[liste_bille_selectionne[0]]=NULL;
                                        }
                                        affichage_SDL();
                                        done=SDL_TRUE;
                                    }
                                    break;
                                }
                                else if(verif_case_deplacement==case_a_deplace->alentours->NE){
                                    if(verificationDeplacement(nb_bille,NE)){
                                        if(couleur==NOIR){
                                            current_state[case_selectionne]=image_bille_noire;
                                            current_state[liste_bille_selectionne[0]]=NULL;
                                        }
                                        else{
                                            current_state[case_selectionne]=image_bille_blanc;
                                            current_state[liste_bille_selectionne[0]]=NULL;
                                        }
                                        affichage_SDL();
                                        done=SDL_TRUE;
                                    }
                                    break;
                                }
                                else if(verif_case_deplacement==case_a_deplace->alentours->E){
                                    if(verificationDeplacement(nb_bille,E)){
                                        if(couleur==NOIR){
                                            current_state[case_selectionne]=image_bille_noire;
                                            current_state[liste_bille_selectionne[0]]=NULL;
                                        }
                                        else{
                                            current_state[case_selectionne]=image_bille_blanc;
                                            current_state[liste_bille_selectionne[0]]=NULL;
                                        }
                                        affichage_SDL();
                                        done=SDL_TRUE;
                                    }
                                    break;
                                }
                                else if(verif_case_deplacement==case_a_deplace->alentours->SE){
                                    if(verificationDeplacement(nb_bille,SE)){
                                        if(couleur==NOIR){
                                            current_state[case_selectionne]=image_bille_noire;
                                            current_state[liste_bille_selectionne[0]]=NULL;
                                        }
                                        else{
                                            current_state[case_selectionne]=image_bille_blanc;
                                            current_state[liste_bille_selectionne[0]]=NULL;
                                        }
                                        affichage_SDL();
                                        done=SDL_TRUE;
                                    }
                                    break;
                                }
                                else{
                                    printf("Veuillez séléctionné une case aux alentours de votre séléction\n");
                                }
                            break;

                            case 2 : ;
                                DIRECTION mouvement=0;
                                for(int i=0; i<2; i++){
                                    CASE* case_a_deplace = structcase[liste_bille_selectionne[i]];
                                    if(verif_case_deplacement==case_a_deplace->alentours->NO){
                                        mouvement=NO;
                                        if(verificationDeplacement(nb_bille,NO)){
                                            printf("Désolé mais nous ne pouvons pas gérer ce genre de mouvement pour l'instant\n");
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->O){
                                        if(verificationDeplacement(nb_bille,O)){
                                            printf("Désolé mais nous ne pouvons pas gérer ce genre de mouvement pour l'instant\n");
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->SO){
                                        if(verificationDeplacement(nb_bille,SO)){
                                            printf("Désolé mais nous ne pouvons pas gérer ce genre de mouvement pour l'instant\n");
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->NE){
                                        if(verificationDeplacement(nb_bille,NE)){
                                            printf("Désolé mais nous ne pouvons pas gérer ce genre de mouvement pour l'instant\n");
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->E){
                                        if(verificationDeplacement(nb_bille,E)){
                                            printf("Désolé mais nous ne pouvons pas gérer ce genre de mouvement pour l'instant\n");
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->SE){
                                        if(verificationDeplacement(nb_bille,SE)){
                                            printf("Désolé mais nous ne pouvons pas gérer ce genre de mouvement pour l'instant\n");
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                }
                                printf("Veuillez séléctionné une case aux alentours de votre séléction\n");
                            break;

                            case 3 : ;
                                for(int i=0; i<3; i++){
                                    CASE* case_a_deplace = structcase[liste_bille_selectionne[i]];
                                    if(verif_case_deplacement==case_a_deplace->alentours->NO){
                                        if(verificationDeplacement(nb_bille,NO)){
                                            printf("Désolé mais nous ne pouvons pas gérer ce genre de mouvement pour l'instant\n");
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->O){
                                        if(verificationDeplacement(nb_bille,O)){
                                            printf("Désolé mais nous ne pouvons pas gérer ce genre de mouvement pour l'instant\n");
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->SO){
                                        if(verificationDeplacement(nb_bille,SO)){
                                            printf("Désolé mais nous ne pouvons pas gérer ce genre de mouvement pour l'instant\n");
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->NE){
                                        if(verificationDeplacement(nb_bille,NE)){
                                            printf("Désolé mais nous ne pouvons pas gérer ce genre de mouvement pour l'instant\n");
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->E){
                                        if(verificationDeplacement(nb_bille,E)){
                                            printf("Désolé mais nous ne pouvons pas gérer ce genre de mouvement pour l'instant\n");
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->SE){
                                        if(verificationDeplacement(nb_bille,SE)){
                                            printf("Désolé mais nous ne pouvons pas gérer ce genre de mouvement pour l'instant\n");
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                }
                                printf("Veuillez séléctionné une case aux alentours de votre séléction\n");
                            break;
                break;
                        }
                    }
            }
        }
    }
}

bool verificationDeplacement(int nb_bille_amie, DIRECTION mouvement){
    CASE* destination;
    DIRECTION ami;
    int nb_bille_ennemi;
    int validation=0;

    triCASE(nb_bille_amie);

    for(int i=0; i<nb_bille_amie; i++){
        CASE* bille=structcase[liste_bille_selectionne[i]];
        switch(mouvement){
            case NO :;
                destination = bille->alentours->NO;
            break;
            case O :;
                destination = bille->alentours->O;
            break;
            case SO :;
                destination = bille->alentours->SO;
            break;
            case NE :;
                destination = bille->alentours->NE;
            break;
            case E :;
                destination = bille->alentours->E;
            break;
            case SE :;
                destination = bille->alentours->SE;
            break;
        }

        if(nb_bille_amie>1){
            ami=trouveDirection(structcase[liste_bille_selectionne[0]],structcase[liste_bille_selectionne[1]]);
        }

        if(destination->couleur==0){
            validation++;
        }
        else {
            while(((bille->couleur!=destination->couleur)&&(destination->couleur!=0)) && (nb_bille_amie>nb_bille_ennemi)){
                nb_bille_ennemi++;
                if((nb_bille_amie>nb_bille_ennemi)&&(ami==mouvement)){
                    validation++;
                    switch(mouvement){
                    case NO :;
                        destination = destination->alentours->NO;
                    break;
                    case O :;
                        destination = destination->alentours->O;
                    break;
                    case SO :;
                        destination = destination->alentours->SO;
                    break;
                    case NE :;
                        destination = destination->alentours->NE;
                    break;
                    case E :;
                        destination = destination->alentours->E;
                    break;
                    case SE :;
                        destination = destination->alentours->SE;
                    break;
                    }
                }
                if(destination==NULL){
                    if(tour==0){
                        ejection_noir++;
                    }
                    else{
                        ejection_blanc++;
                    }
                    break;
                }
            }
        }
    }

    if(validation==nb_bille_amie){
        return true;
    }
    return false;
}
