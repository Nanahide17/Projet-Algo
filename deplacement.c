#include <stdio.h>
#include "abalone.h"
#include "donneesSDL.h"

void deplacement(int nb_bille_a_bouger, DIRECTION direction, SDL_Texture *current_state[61], TYPE_CASE couleur){
    cliqueSurDeplacement(nb_bille_a_bouger,current_state,couleur);
}

void cliqueSurDeplacement(int nb_bille_a_bouger, SDL_Texture *current_state[61], TYPE_CASE couleur){

    SDL_Event event;
    SDL_bool done=SDL_FALSE;

    triCASE(nb_bille_a_bouger);

    int ejecte_blanc_avant=ejection_blanc;
    int ejecte_noir_avant=ejection_noir;

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

                                if(verif_case_deplacement==case_a_deplace->alentours->NO){
                                    if(verificationDeplacement(nb_bille,NO)){
                                        if(tour==0){
                                            if(ejecte_blanc_avant!=ejection_blanc){
                                                deplacementEjecte(verif_case_deplacement, NO, image_bille_blanc, current_state_bille_blanc);
                                            }
                                            deplacementBille(1,NO,image_bille_noire,current_state_bille_noir);
                                        }
                                        if(tour==1){
                                            if(ejecte_noir_avant!=ejection_noir){
                                                deplacementEjecte(verif_case_deplacement, NO, image_bille_noire, current_state_bille_noir);
                                            }
                                            deplacementBille(1, NO,image_bille_blanc, current_state_bille_blanc);
                                        }
                                        affichage_SDL();
                                        done=SDL_TRUE;
                                    }
                                    break;
                                }
                                else if(verif_case_deplacement==case_a_deplace->alentours->O){
                                    if(verificationDeplacement(nb_bille,O)){
                                        if(tour==0){
                                            if(ejecte_blanc_avant!=ejection_blanc){
                                                deplacementEjecte(verif_case_deplacement, O, image_bille_blanc, current_state_bille_blanc);
                                            }
                                            deplacementBille(1,O,image_bille_noire,current_state_bille_noir);
                                        }
                                        if(tour==1){
                                            if(ejecte_noir_avant!=ejection_noir){
                                                deplacementEjecte(verif_case_deplacement, O, image_bille_noire, current_state_bille_noir);
                                            }
                                            deplacementBille(1, O,image_bille_blanc, current_state_bille_blanc);
                                        }
                                        affichage_SDL();
                                        done=SDL_TRUE;
                                    }
                                    break;
                                }
                                else if(verif_case_deplacement==case_a_deplace->alentours->SO){
                                    if(verificationDeplacement(nb_bille,SO)){
                                        if(tour==0){
                                            if(ejecte_blanc_avant!=ejection_blanc){
                                                deplacementEjecte(verif_case_deplacement, SO, image_bille_blanc, current_state_bille_blanc);
                                            }
                                            deplacementBille(1,SO,image_bille_noire,current_state_bille_noir);
                                        }
                                        if(tour==1){
                                            if(ejecte_noir_avant!=ejection_noir){
                                                deplacementEjecte(verif_case_deplacement, SO, image_bille_noire, current_state_bille_noir);
                                            }
                                            deplacementBille(1, SO,image_bille_blanc, current_state_bille_blanc);
                                        }
                                        affichage_SDL();
                                        done=SDL_TRUE;
                                    }
                                    break;
                                }
                                else if(verif_case_deplacement==case_a_deplace->alentours->NE){
                                    if(verificationDeplacement(nb_bille,NE)){
                                        if(tour==0){
                                            if(ejecte_blanc_avant!=ejection_blanc){
                                                deplacementEjecte(verif_case_deplacement, NE, image_bille_blanc, current_state_bille_blanc);
                                            }
                                            deplacementBille(1,NE,image_bille_noire,current_state_bille_noir);
                                        }
                                        if(tour==1){
                                            if(ejecte_noir_avant!=ejection_noir){
                                                deplacementEjecte(verif_case_deplacement, NE, image_bille_noire, current_state_bille_noir);
                                            }
                                            deplacementBille(1, NE,image_bille_blanc, current_state_bille_blanc);
                                        }
                                        affichage_SDL();
                                        done=SDL_TRUE;
                                    }
                                    break;
                                }
                                else if(verif_case_deplacement==case_a_deplace->alentours->E){
                                    if(verificationDeplacement(nb_bille,E)){
                                        if(tour==0){
                                            if(ejecte_blanc_avant!=ejection_blanc){
                                                deplacementEjecte(verif_case_deplacement, E, image_bille_blanc, current_state_bille_blanc);
                                            }
                                            deplacementBille(1,E,image_bille_noire,current_state_bille_noir);
                                        }
                                        if(tour==1){
                                            if(ejecte_noir_avant!=ejection_noir){
                                                deplacementEjecte(verif_case_deplacement, E, image_bille_noire, current_state_bille_noir);
                                            }
                                            deplacementBille(1, E,image_bille_blanc, current_state_bille_blanc);
                                        }
                                        affichage_SDL();
                                        done=SDL_TRUE;
                                    }
                                    break;
                                }
                                else if(verif_case_deplacement==case_a_deplace->alentours->SE){
                                    if(verificationDeplacement(nb_bille,SE)){
                                        if(tour==0){
                                            if(ejecte_blanc_avant!=ejection_blanc){
                                                deplacementEjecte(verif_case_deplacement, SE, image_bille_blanc, current_state_bille_blanc);
                                            }
                                            deplacementBille(1,SE,image_bille_noire,current_state_bille_noir);
                                        }
                                        if(tour==1){
                                            if(ejecte_noir_avant!=ejection_noir){
                                                deplacementEjecte(verif_case_deplacement, SE, image_bille_noire, current_state_bille_noir);
                                            }
                                            deplacementBille(1, SE,image_bille_blanc, current_state_bille_blanc);
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
                                for(int i=0; i<2; i++){
                                    int test=liste_bille_selectionne[i];
                                    CASE* case_a_deplace = structcase[test];
                                    if(verif_case_deplacement==case_a_deplace->alentours->NO){
                                        if(verificationDeplacement(nb_bille,NO)){
                                            if(tour==0){
                                                if(ejecte_blanc_avant!=ejection_blanc){
                                                    deplacementEjecte(verif_case_deplacement, NO, image_bille_blanc, current_state_bille_blanc);
                                                }
                                                deplacementBille(2,NO,image_bille_noire,current_state_bille_noir);
                                            }
                                            if(tour==1){
                                                if(ejecte_noir_avant!=ejection_noir){
                                                    deplacementEjecte(verif_case_deplacement, NO, image_bille_noire, current_state_bille_noir);
                                                }
                                                deplacementBille(2, NO,image_bille_blanc, current_state_bille_blanc);
                                            }
                                            affichage_SDL();
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->O){
                                        if(verificationDeplacement(nb_bille,O)){
                                            if(tour==0){
                                                if(ejecte_blanc_avant!=ejection_blanc){
                                                    deplacementEjecte(verif_case_deplacement, O, image_bille_blanc, current_state_bille_blanc);
                                                }
                                                deplacementBille(2,O,image_bille_noire,current_state_bille_noir);
                                            }
                                            if(tour==1){
                                                if(ejecte_noir_avant!=ejection_noir){
                                                    deplacementEjecte(verif_case_deplacement, O, image_bille_noire, current_state_bille_noir);
                                                }
                                                deplacementBille(2, O,image_bille_blanc, current_state_bille_blanc);
                                            }
                                            affichage_SDL();
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->SO){
                                        if(verificationDeplacement(nb_bille,SO)){
                                            if(tour==0){
                                                if(ejecte_blanc_avant!=ejection_blanc){
                                                    deplacementEjecte(verif_case_deplacement, SO, image_bille_blanc, current_state_bille_blanc);
                                                }
                                                deplacementBille(1,SO,image_bille_noire,current_state_bille_noir);
                                            }
                                            if(tour==1){
                                                if(ejecte_noir_avant!=ejection_noir){
                                                    deplacementEjecte(verif_case_deplacement, SO, image_bille_noire, current_state_bille_noir);
                                                }
                                                deplacementBille(1, SO,image_bille_blanc, current_state_bille_blanc);
                                            }
                                            affichage_SDL();
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->NE){
                                        if(verificationDeplacement(nb_bille,NE)){
                                            if(tour==0){
                                                if(ejecte_blanc_avant!=ejection_blanc){
                                                    deplacementEjecte(verif_case_deplacement, NE, image_bille_blanc, current_state_bille_blanc);
                                                }
                                                deplacementBille(2,NE,image_bille_noire,current_state_bille_noir);
                                            }
                                            if(tour==1){
                                                if(ejecte_noir_avant!=ejection_noir){
                                                    deplacementEjecte(verif_case_deplacement, NE, image_bille_noire, current_state_bille_noir);
                                                }
                                                deplacementBille(2, NE,image_bille_blanc, current_state_bille_blanc);
                                            }
                                            affichage_SDL();
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->E){
                                        if(verificationDeplacement(nb_bille,E)){
                                            if(tour==0){
                                                if(ejecte_blanc_avant!=ejection_blanc){
                                                    deplacementEjecte(verif_case_deplacement, E, image_bille_blanc, current_state_bille_blanc);
                                                }
                                                deplacementBille(2,E,image_bille_noire,current_state_bille_noir);
                                            }
                                            if(tour==1){
                                                if(ejecte_noir_avant!=ejection_noir){
                                                    deplacementEjecte(verif_case_deplacement, E, image_bille_noire, current_state_bille_noir);
                                                }
                                                deplacementBille(2, E,image_bille_blanc, current_state_bille_blanc);
                                            }
                                            affichage_SDL();
                                            done=SDL_TRUE;
                                            }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->SE){
                                        if(verificationDeplacement(nb_bille,SE)){
                                            if(tour==0){
                                                if(ejecte_blanc_avant!=ejection_blanc){
                                                    deplacementEjecte(verif_case_deplacement, SE, image_bille_blanc, current_state_bille_blanc);
                                                }
                                                deplacementBille(2,SE,image_bille_noire,current_state_bille_noir);
                                            }
                                            if(tour==1){
                                                if(ejecte_noir_avant!=ejection_noir){
                                                    deplacementEjecte(verif_case_deplacement, SE, image_bille_noire, current_state_bille_noir);
                                                }
                                                deplacementBille(2, SE,image_bille_blanc, current_state_bille_blanc);
                                            }
                                            affichage_SDL();
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
                                            if(tour==0){
                                                if(ejecte_blanc_avant!=ejection_blanc){
                                                    deplacementEjecte(verif_case_deplacement, NO, image_bille_blanc, current_state_bille_blanc);
                                                }
                                                deplacementBille(3,NO,image_bille_noire,current_state_bille_noir);
                                            }
                                            if(tour==1){
                                                if(ejecte_noir_avant!=ejection_noir){
                                                    deplacementEjecte(verif_case_deplacement,NO, image_bille_noire, current_state_bille_noir);
                                                }
                                                deplacementBille(3, NO,image_bille_blanc, current_state_bille_blanc);
                                            }
                                            affichage_SDL();
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->O){
                                        if(verificationDeplacement(nb_bille,O)){
                                            if(tour==0){
                                                if(ejecte_blanc_avant!=ejection_blanc){
                                                    deplacementEjecte(verif_case_deplacement, O, image_bille_blanc, current_state_bille_blanc);
                                                }
                                                deplacementBille(3,O,image_bille_noire,current_state_bille_noir);
                                            }
                                            if(tour==1){
                                                if(ejecte_noir_avant!=ejection_noir){
                                                    deplacementEjecte(verif_case_deplacement,O, image_bille_noire, current_state_bille_noir);
                                                }
                                                deplacementBille(3, O,image_bille_blanc, current_state_bille_blanc);
                                            }
                                            affichage_SDL();
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->SO){
                                        if(verificationDeplacement(nb_bille,SO)){
                                            if(tour==0){
                                                if(ejecte_blanc_avant!=ejection_blanc){
                                                    deplacementEjecte(verif_case_deplacement, SO, image_bille_blanc, current_state_bille_blanc);
                                                }
                                                deplacementBille(3,SO,image_bille_noire,current_state_bille_noir);
                                            }
                                            if(tour==1){
                                                if(ejecte_noir_avant!=ejection_noir){
                                                    deplacementEjecte(verif_case_deplacement,SO, image_bille_noire, current_state_bille_noir);
                                                }
                                                deplacementBille(3, SO,image_bille_blanc, current_state_bille_blanc);
                                            }
                                            affichage_SDL();
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->NE){
                                        if(verificationDeplacement(nb_bille,NE)){
                                            if(tour==0){
                                                if(ejecte_blanc_avant!=ejection_blanc){
                                                    deplacementEjecte(verif_case_deplacement, NE, image_bille_blanc, current_state_bille_blanc);
                                                }
                                                deplacementBille(3,NE,image_bille_noire,current_state_bille_noir);
                                            }
                                            if(tour==1){
                                                if(ejecte_noir_avant!=ejection_noir){
                                                    deplacementEjecte(verif_case_deplacement,NE, image_bille_noire, current_state_bille_noir);
                                                }
                                                deplacementBille(3, NE,image_bille_blanc, current_state_bille_blanc);
                                            }
                                            affichage_SDL();
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->E){
                                        if(verificationDeplacement(nb_bille,E)){
                                            if(tour==0){
                                                if(ejecte_blanc_avant!=ejection_blanc){
                                                    deplacementEjecte(verif_case_deplacement, E, image_bille_blanc, current_state_bille_blanc);
                                                }
                                                deplacementBille(3,E,image_bille_noire,current_state_bille_noir);
                                            }
                                            if(tour==1){
                                                if(ejecte_noir_avant!=ejection_noir){
                                                    deplacementEjecte(verif_case_deplacement,E, image_bille_noire, current_state_bille_noir);
                                                }
                                                deplacementBille(3, E,image_bille_blanc, current_state_bille_blanc);
                                            }
                                            affichage_SDL();
                                            done=SDL_TRUE;
                                        }
                                        break;
                                    }
                                    else if(verif_case_deplacement==case_a_deplace->alentours->SE){
                                        if(verificationDeplacement(nb_bille,SE)){
                                            if(tour==0){
                                                if(ejecte_blanc_avant!=ejection_blanc){
                                                    deplacementEjecte(verif_case_deplacement, SE, image_bille_blanc, current_state_bille_blanc);
                                                }
                                                deplacementBille(3,SE,image_bille_noire,current_state_bille_noir);
                                            }
                                            if(tour==1){
                                                if(ejecte_noir_avant!=ejection_noir){
                                                    deplacementEjecte(verif_case_deplacement,SE, image_bille_noire, current_state_bille_noir);
                                                }
                                                deplacementBille(3, SE,image_bille_blanc, current_state_bille_blanc);
                                            }
                                            affichage_SDL();
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

        for(int j=0; j<nb_bille_amie; j++){
            if(destination==structcase[liste_bille_selectionne[j]]){
                validation++;
                break;
            }
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
                    validation++;
                    if(tour==0){
                        ejection_noir++;
                    }
                    if(tour==1){
                        ejection_blanc++;
                    }

                }
            }
        }
    }

    if(validation==nb_bille_amie){
        return true;
    }
    return false;
}


void deplacementBille(int nb_bille, DIRECTION mouvement, SDL_Texture *image_bille, SDL_Texture *current_state[61]){

    for(int i=0; i<nb_bille; i++){

        int same_bille=0;

        CASE* bille=structcase[liste_bille_selectionne[i]];
        CASE* destination;

        switch(mouvement){
            case NO :;
                destination=bille->alentours->NO;
            break;

            case O :;
                destination=bille->alentours->O;
            break;

            case SO :;
                destination=bille->alentours->SO;
            break;

            case NE :;
                destination=bille->alentours->NE;
            break;

            case E :;
                destination=bille->alentours->E;
            break;

            case SE :;
                destination=bille->alentours->SE;
            break;
        }

        int inlist_destination=0;
        while(destination!=structcase[inlist_destination]){
            inlist_destination++;
        }

        for(int j=0; j<nb_bille; j++){
            if(inlist_destination==liste_bille_selectionne[j]){
                same_bille++;
            }
        }

        if(same_bille!=0){
            current_state[inlist_destination]=image_bille;
            current_state[liste_bille_selectionne[i]]=NULL;
        }
        else{
            if(current_state[liste_bille_selectionne[i]]==image_bille){
                current_state[inlist_destination]=image_bille;
            }
            else{
                current_state[inlist_destination]=image_bille;
                current_state[liste_bille_selectionne[i]]=NULL;
            }
        }
    }
}


void deplacementEjecte(CASE* bille_a_bouge, DIRECTION mouvement, SDL_Texture *image_bille, SDL_Texture *current_state[61]){
    CASE* case_a_changer[2];
    int i=0;
    int nb_bille=0;
    switch(mouvement){
        case NO :;
            while(bille_a_bouge->alentours->NO){
                nb_bille++;
                case_a_changer[i]=bille_a_bouge;
                bille_a_bouge=bille_a_bouge->alentours->NO;
                i++;
            }
        break;
        case O:;
            while(bille_a_bouge->alentours->O){
                nb_bille++;
                case_a_changer[i]=bille_a_bouge;
                bille_a_bouge=bille_a_bouge->alentours->NO;
                i++;
            }
        break;
        case SO :;
            while(bille_a_bouge->alentours->SO){
                nb_bille++;
                case_a_changer[i]=bille_a_bouge;
                bille_a_bouge=bille_a_bouge->alentours->NO;
                i++;
            }
        break;
        case NE :;
            while(bille_a_bouge->alentours->NE){
                nb_bille++;
                case_a_changer[i]=bille_a_bouge;
                bille_a_bouge=bille_a_bouge->alentours->NO;
                i++;
            }
        break;
        case E :;
            while(bille_a_bouge->alentours->E){
                nb_bille++;
                case_a_changer[i]=bille_a_bouge;
                bille_a_bouge=bille_a_bouge->alentours->NO;
                i++;
            }
        break;
        case SE :;
            while(bille_a_bouge->alentours->SE){
                nb_bille++;
                case_a_changer[i]=bille_a_bouge;
                bille_a_bouge=bille_a_bouge->alentours->NO;
                i++;
            }

        break;
    }

    int index_case_inlist[2];
    for(int i=0; i<nb_bille;i++){
        int inlist=0;
        while(case_a_changer[i]!=structcase[inlist]){
            inlist++;
        }
        index_case_inlist[i]=inlist;
    }

    CASE* destination_case[2];
    for (int i=0; i<nb_bille;i++){
        switch(mouvement){
            case NO :;
                destination_case[i]=case_a_changer[i]->alentours->NO;
            break;
            case O:;
                destination_case[i]=case_a_changer[i]->alentours->O;
            break;
            case SO :;
                destination_case[i]=case_a_changer[i]->alentours->SO;
            break;
            case NE :;
                destination_case[i]=case_a_changer[i]->alentours->NE;
            break;
            case E :;
                destination_case[i]=case_a_changer[i]->alentours->E;
            break;
            case SE :;
                destination_case[i]=case_a_changer[i]->alentours->SE;
            break;
        }
    }

    int index_desti_inlist[2];
    for(int i=0; i<nb_bille;i++){
        int inlist=0;
        while(destination_case[i]!=structcase[inlist]){
            inlist++;
        }
        index_desti_inlist[i]=inlist;
    }

    int same_bille=0;
    for(int j=0; j<nb_bille; j++){
        for(int k=0; k<nb_bille;k++){
            if(index_desti_inlist[k]==index_case_inlist[j]){
                same_bille++;
            }
        }
    }

    for(int i=0; i<nb_bille; i++){
        if(same_bille!=0){
            current_state[index_desti_inlist[i]]=image_bille;
            current_state[index_case_inlist[i]]=NULL;
        }
        else{
            if(current_state[index_case_inlist[i]]==image_bille){
                current_state[index_desti_inlist[i]]=image_bille;
            }
            else{
                current_state[index_desti_inlist[i]]=image_bille;
                current_state[index_case_inlist[i]]=NULL;
            }
        }
    }
}
