#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* argv[]) {

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Déplacement d'image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Chargement de l'image
    SDL_Surface* image = IMG_Load("billeblanche.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);

    // Position de départ de l'image
    SDL_Rect imageRect = {0, 0, image->w, image->h};

    // Boucle principale
    SDL_bool done = SDL_FALSE;
    SDL_bool imageClicked = SDL_FALSE; // Variable pour savoir si l'image a été cliquée

    while (!done) {

        // Gestion des événements
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    done = SDL_TRUE;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if (SDL_PointInRect(&(SDL_Point){event.button.x, event.button.y}, &imageRect)) {
                        imageClicked = SDL_TRUE;
                    }
                    printf("Clicked at x=%d, y=%d\n", event.button.x, event.button.y); // afficher les coordonnées du clic
                    break;

                case SDL_MOUSEBUTTONUP:
                    if (imageClicked) {
                        imageRect.x = event.button.x - imageRect.w / 2;
                        imageRect.y = event.button.y - imageRect.h / 2;
                        imageClicked = SDL_FALSE;
                    }
                    break;
            }
        }

        // Affichage de l'image
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, &imageRect);
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

