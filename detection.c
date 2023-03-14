#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>


int truc(){
    // Boucle principale pour afficher l'image et récupérer les clics de souris
    SDL_Event evenement;
    int clicX, clicY;
    while (1) {
        SDL_WaitEvent(&evenement);
        if (evenement.type == SDL_QUIT) {
            break;
        }
        if (evenement.type == SDL_MOUSEBUTTONDOWN) {
            clicX = evenement.button.x;
            clicY = evenement.button.y;
            printf("Clic en (%d,%d)\n", clicX, clicY);
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    return 0;
}

