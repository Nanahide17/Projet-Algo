#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* argv[]) {

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Images", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface* image1 = IMG_Load("billeblanche.png");
    SDL_Texture* texture1 = SDL_CreateTextureFromSurface(renderer, image1);
    SDL_FreeSurface(image1);

    SDL_Surface* image2 = IMG_Load("billenoire.png");
    SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer, image2);
    SDL_FreeSurface(image2);

    SDL_Surface* image3 = SDL_LoadBMP("play3.bmp");
    SDL_Texture* texture3 = SDL_CreateTextureFromSurface(renderer, image3);
    SDL_FreeSurface(image3);

    SDL_Surface* image4 = IMG_Load("Grille_jeu2.png");
    SDL_Texture* texture4 = SDL_CreateTextureFromSurface(renderer, image4);
    SDL_FreeSurface(image4);

    SDL_Rect imageRect1 = {100, 100, 100, 100};
    SDL_Color color1 = {255, 255, 255, 255};

    SDL_Texture* currentImage = texture1;

    SDL_bool done = SDL_FALSE;

    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    done = SDL_TRUE;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (SDL_PointInRect(&(SDL_Point){event.button.x, event.button.y}, &imageRect1)) {
                        printf("Image 1 cliquée\n");
                        currentImage = texture4;
                    }
                    break;
                case SDL_MOUSEMOTION:
                    if (SDL_PointInRect(&(SDL_Point){event.motion.x, event.motion.y}, &imageRect1)) {
                        currentImage = texture2;
                    } else {
                        currentImage = texture1;
                    }
                    break;
            }
        }
            
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture4, NULL, NULL); // Afficher l'image blanche en arrière-plan
        SDL_RenderCopy(renderer, currentImage, NULL, &imageRect1);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(texture2);
    SDL_DestroyTexture(texture3);
    SDL_DestroyTexture(texture4);  // Libérer la texture de l'image verte
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
