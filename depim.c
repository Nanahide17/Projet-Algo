#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* argv[]) {

    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Création de la fenêtre
    SDL_Window* window = SDL_CreateWindow("Déplacement d'image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fprintf(stderr, "Erreur de création de la fenêtre : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Création du renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        fprintf(stderr, "Erreur de création du renderer : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Chargement de l'image à déplacer
    SDL_Surface* image = IMG_Load("play1.png");
    if (image == NULL) {
        fprintf(stderr, "Erreur de chargement de l'image : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Création de la texture à partir de l'image
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    if (texture == NULL) {
        fprintf(stderr, "Erreur de création de la texture : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Position initiale de l'image
    SDL_Rect imageRect = {100, 100, 200, 200};

    // Booléen pour la boucle principale
    SDL_bool done = SDL_FALSE;

    while (!done) {
        SDL_Event event;

        // Gestion des événements
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    done = SDL_TRUE;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    // Si l'utilisateur a cliqué sur l'image
                    if (event.button.x >= imageRect.x && event.button.x < imageRect.x + imageRect.w &&
                        event.button.y >= imageRect.y && event.button.y < imageRect.y + imageRect.h) {
                        printf("Image cliquée !\n");
                    }
                    break;
                case SDL_MOUSEMOTION:
                    // Si l'utilisateur maintient le clic sur l'image, déplace l'image en fonction de la position de la souris
                    if (event.motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) {
                        int newX = event.motion.x - imageRect.w / 2;
                        int newY = event.motion.y - imageRect.h / 2;
                        imageRect.x = newX;
                        imageRect.y = newY;
                    }
                    break;
                default:
                    break;
            }
        }

        // Efface le contenu du renderer
        SDL_RenderClear(renderer);

        // Affiche l'image
        SDL_RenderCopy(renderer, texture, NULL, &imageRect);

        // Met à jour l'affichage
        SDL_RenderPresent(renderer);
    }

    // Libération de la texture et du renderer
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);

    // Libération de la surface de l'image
    SDL_FreeSurface(image);

    // Libération de la fenêtre
    SDL_DestroyWindow(window);

    // Quitter SDL
    SDL_Quit();

    return 0;
}


