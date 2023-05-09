#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#include "abalone.h"

#define NUM_CHOICE 3

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const char *MENU_CHOICES[NUM_CHOICE] = {
    "Jouer",
    "Options",
    "Quitter"};

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *backgroundTexture = NULL;
TTF_Font *font = NULL;
int currentChoice = 0;

void renderMenu(){
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    SDL_Color textColor={255,255,255,255};
    SDL_Rect textRect;
    textRect.w = 200;
    textRect.h = 50;
    textRect.x = WINDOW_WIDTH/2 - textRect.w/2;
    textRect.y = WINDOW_HEIGHT/2 - NUM_CHOICE * textRect.h/2;

    for(int i=0; i<NUM_CHOICE; i++){
        if(i==currentChoice){
            SDL_SetRenderDrawColor(renderer, 255,0,0,255);
        }
        else{
            SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        }
        SDL_RenderFillRect(renderer, &textRect);

        SDL_Surface *textSurface = TTF_RenderText_Solid(font, MENU_CHOICES[i], textColor);
        SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_Rect textRenderRect;
        SDL_QueryTexture(textTexture, NULL, NULL, &textRenderRect.w, &textRenderRect.h);
        textRenderRect.x = textRect.x + textRect.w/2 - textRenderRect.w/2;
        textRenderRect.y = textRect.y + textRect.h/2 - textRenderRect.h/2;
        SDL_RenderCopy(renderer,textTexture,NULL, &textRenderRect);

        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);

        textRect.y += textRect.h;
    }
    SDL_RenderPresent(renderer);
}

void handleKeyboardEvent(SDL_Event *event){
    switch(event->key.keysym.sym){
        case SDLK_UP: ;
            currentChoice=(currentChoice-1 + NUM_CHOICE)%NUM_CHOICE;
        break;

        case SDLK_DOWN :;
            currentChoice=(currentChoice+1)%NUM_CHOICE;
        break;

        case SDLK_RETURN:;
            printf("Choix sélectionné: %s\n", MENU_CHOICES[currentChoice]);
            switch(currentChoice){
                case 0:
                    SDL_DestroyTexture(backgroundTexture);
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    TTF_CloseFont(font);
                    TTF_Quit();
                    IMG_Quit();
                    SDL_Quit();

                    initialisationPlateau();
                    grille();

                case 1:
                    printf("Cette page n'est pas accesible pour le moment\n");
                break;

                case 2 :
                    printf("Merci d'avoir joué\n");
                    SDL_DestroyTexture(backgroundTexture);
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    TTF_CloseFont(font);
                    TTF_Quit();
                    SDL_Quit();
                break;
            }
    }
}

void menu(){
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        printf("Erreur lors du chargement de l'initialisation de SDL : %s\n", SDL_GetError());
    }

    window=SDL_CreateWindow("Menu Abalone", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if(!window){
        printf("Erreur lors de la création de la fênetre : %s\n",SDL_GetError());
        SDL_Quit();
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
        printf("Erreur lors de la création du renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    if(!(IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG)){
        printf("Erreur lors de l'initialisation de SDL_IMage : %s_n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    if(TTF_Init()<0){
        printf("Erreur lors de l'initialisation de SDL_ttf : %s\n", TTF_GetError());
        IMG_Quit();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    font=TTF_OpenFont("arial-bold.ttf",24);
    if(!font){
        printf("Erreur lors du chargement de la police de caractères : %s\n", TTF_GetError());
        TTF_Quit();
        IMG_Quit();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }


    SDL_Surface *surface = IMG_Load("fond.jpg");
    if(!surface){
        printf("Erreur lors du chargement de l'image : %s\n", SDL_GetError());
        return NULL;
    }

    backgroundTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);



    if(!backgroundTexture){
        printf("Erreur lors du chargement de l'image : %s\n", SDL_GetError());
        TTF_CloseFont(font);
        TTF_Quit();
        IMG_Quit();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    bool quit=false;
    SDL_Event event;

    while(!quit){
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT){
                quit = true;
            }
            else if(event.type == SDL_KEYDOWN){
                handleKeyboardEvent(&event);
            }
        }
        renderMenu();
    }
    TTF_CloseFont(font);
    TTF_Quit();
    IMG_Quit();
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
