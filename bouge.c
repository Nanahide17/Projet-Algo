#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur lors de l'initialisation de SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Création d'une fenêtre
    
    if (fenetre == NULL) {
        printf("Erreur lors de la création de la fenêtre: %s\n", SDL_GetError());
        return 1;
    }

    // Création d'un renderer pour afficher l'image
    SDL_Renderer* renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Erreur lors de la création du renderer: %s\n", SDL_GetError());
        return 1;
    }

    // Chargement de l'image
    SDL_Surface* image = IMG_Load("billeblanche.png");
    if (image == NULL) {
        printf("Erreur lors du chargement de l'image: %s\n", SDL_GetError());
        return 1;
    }

    // Création d'une texture à partir de l'image
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    if (texture == NULL) {
        printf("Erreur lors de la création de la texture: %s\n", SDL_GetError());
        return 1;
    }

    // Libération de la surface d'image
    SDL_FreeSurface(image);

    // Boucle principale pour afficher l'image dans la position souhaitée
    
    
    int posX, posY;
    printf("Entrez la position x: ");
    scanf("%d", &posX);
    printf("Entrez la position y: ");
    scanf("%d", &posY);
    
    SDL_Rect destRect = {posX, posY, 0, 0};
    SDL_QueryTexture(texture, NULL, NULL, &(destRect.w), &(destRect.h));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, &destRect);
    SDL_RenderPresent(renderer);

    // Attente de 5 secondes avant de quitter
    SDL_Delay(5000);

    // Libération de la texture et du renderer
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);

    // Fermeture de la fenêtre et de SDL
    SDL_DestroyWindow(fenetre);
    SDL_Quit();

    return 0;
}

