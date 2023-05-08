#include <stdio.h>
#include <stdlib.h>
#include "abalone.h"
#include "Donnees.h"
#include "donneesSDL.h"

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
    initialisationGrille();
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
    if(y==115 || y==220 || y==325){
        if(x>=655 && x<=1260){
            if(y==325 && (x<=720 || x>=1200)){
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
    reliageHaut(LIGNE4,LIGNE5);
    reliageHaut(LIGNE5,LIGNE6);
    reliageHaut(LIGNE6,LIGNE7);
    reliageHaut(LIGNE7,LIGNE8);
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
}

void initialisationGrille(){
    ejection_blanc=0;
    ejection_noir=0;
///Initialisation SDL
    SDL_Init(SDL_INIT_VIDEO);
    //Gestion d'erreur
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        SDL_Log("ERREUR > %s\n", SDL_GetError());
        SDL_Quit();
    }

///Initialisation fênetre
    window=SDL_CreateWindow("Abalone", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);
    //Gestion d'erreur
	if(window == NULL){
		SDL_Log("ERREUR > %s\n", SDL_GetError());
		SDL_Quit();
	}

///Initialisation renderer
    renderer = SDL_CreateRenderer(window, -1, 0);
    //Gestion fênetre
    if(renderer == NULL){
        SDL_Log("ERREUR > %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

///Initialisation grille
    //Initialisation surface
    SDL_Surface* surfaceG = IMG_Load("Grille_jeu2.png");
    //Gestion mémoire
    if(surfaceG == NULL){
        SDL_Log("ERREUR > %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    //Initialisation texture
    imageG = SDL_CreateTextureFromSurface(renderer, surfaceG);
    //Gestion d'erreur
    if(imageG == NULL){
        SDL_Log("ERREUR > %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    //Libération de la mémoire pour la surface car plus utile
    SDL_FreeSurface(surfaceG);

///Initialisation bille
    //Initialisation surfaces
	SDL_Surface *surface_noire;
	SDL_Surface *surface_blanc;
	SDL_Surface *surface_bleu;

    //Bille noire
    SDL_Surface *image = IMG_Load("billenoire.png");
    //Gestion d'erreur
 	if(image == NULL){
 	//Gestion d'erreur
		SDL_Log("ERREUR > %s\n", SDL_GetError());
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
 	surface_noire = image;

 	//Bille blanche
    SDL_Surface *imageb = IMG_Load("billeblanche.png");
    //Gestion d'erreur
    if(imageb == NULL){
        SDL_Log("ERREUR > %s\n", SDL_GetError());
		SDL_FreeSurface(surface_noire);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
    }
    surface_blanc = imageb;

    //Bille bleue
    SDL_Surface *imagebleu = IMG_Load("billebleu.png");
    //Gestion d'erreur
    if(imagebleu == NULL){
        SDL_Log("ERREUR > %s\n", SDL_GetError());
        SDL_FreeSurface(surface_blanc);
        SDL_FreeSurface(surface_noire);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    surface_bleu = imagebleu;

    //Initialisation texture
    //Bille noire
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface_noire);
 	//Gestion d'erreur
 	if(texture == NULL){
		SDL_Log("ERREUR > %s\n", SDL_GetError());
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	image_bille_noire = texture;

    //Bille blanche
	SDL_Texture *textureb = SDL_CreateTextureFromSurface(renderer, surface_blanc);
	//Gestion d'erreur
	if(textureb == NULL){
		SDL_Log("ERREUR > %s\n", SDL_GetError());
		SDL_DestroyTexture(image_bille_noire);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
 	image_bille_blanc = textureb;

 	//Bille bleue
 	SDL_Texture *texturebleu = SDL_CreateTextureFromSurface(renderer, surface_bleu);
 	//Gestion d'erreur
 	if(texturebleu == NULL){
		SDL_Log("ERREUR > %s\n", SDL_GetError());
		SDL_DestroyTexture(image_bille_blanc);
		SDL_DestroyTexture(image_bille_noire);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	image_bille_bleu = texturebleu;

    //Libération de la mémoire pour les surfaces car plus utile
    SDL_FreeSurface(surface_noire);
    SDL_FreeSurface(surface_blanc);
    SDL_FreeSurface(surface_bleu);

///Initialisation rectangle (un rectangle = une case)
    for(int i=0; i<61; i++){
        CASE* verif_casse = structcase[i];
        SDL_Rect rect_case = {((verif_casse->posX)-50),((verif_casse->posY)-50),100,100};
		casse[i]=rect_case;
    }

///Initialisation état courant
    for(int i=0; i<61; i++){
        CASE* verif_case=structcase[i];
        if(verif_case->couleur==0){
            current_state_bille_noir[i]=NULL;
            current_state_bille_blanc[i]=NULL;
        }
        if(verif_case->couleur==1){
            current_state_bille_noir[i]=image_bille_noire;
            current_state_bille_blanc[i]=NULL;
        }
        if(verif_case->couleur==2){
            current_state_bille_blanc[i]=image_bille_blanc;
            current_state_bille_noir[i]=NULL;
        }
    }

///Liste (utilisez pour se souvenir pos des cases dans liste structcase)
    int compteur_noire=0, compteur_blanc=0;
    for(int i=0; i<61; i++){
        CASE* verif_case=structcase[i];
        if(verif_case->couleur==1){
            conoire[compteur_noire]=i;
            compteur_noire++;
        }
        else if(verif_case->couleur==2){
            coblanc[compteur_blanc]=i;
            compteur_blanc++;
        }
    }

    affichage_SDL(renderer,imageG,current_state_bille_noir,current_state_bille_blanc,casse);

}
