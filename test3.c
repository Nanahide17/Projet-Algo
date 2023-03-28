#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
int clic = 0;

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Images", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 1);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, 1, 0);

    SDL_Surface *image1 = IMG_Load("billeblanche.png");
    SDL_Texture *texture1 = SDL_CreateTextureFromSurface(renderer, image1);
    SDL_FreeSurface(image1);

    SDL_Surface *image2 = IMG_Load("billenoire.png");
    SDL_Texture *texture2 = SDL_CreateTextureFromSurface(renderer, image2);
    SDL_FreeSurface(image2);

    SDL_Surface *image3 = IMG_Load("Grille_jeu2.png");
    SDL_Texture *texture3 = SDL_CreateTextureFromSurface(renderer, image3);
    SDL_FreeSurface(image3);

    SDL_Surface *image4 = IMG_Load("billebleu.png");
    SDL_Texture *texture4 = SDL_CreateTextureFromSurface(renderer, image4);
    SDL_FreeSurface(image4);


    SDL_Rect imageRect1 = {720 - 50, 955 - 50, 100, 100};
    SDL_Color color1 = {255, 255, 255, 255};
    SDL_Texture *currentImage = texture1;

    SDL_Rect imageRect2 = {840 - 50, 115 - 50, 100, 100};
    SDL_Color color2 = {255, 255, 255, 255};
    SDL_Texture *currentImage2 = texture2;

    SDL_Rect imageRect3 = {1920, 1080, 100, 100};
    SDL_Color color3 = {255, 255, 255, 255};
    SDL_Texture *currentImage3 = texture3;

    SDL_Rect imageRect4 = {0, 0, 0, 0};
    SDL_Color color4 = {255, 255, 255, 255};
    SDL_Texture *currentImage4 = texture4;

    SDL_bool done = SDL_FALSE;
    SDL_bool imageClicked1 = SDL_FALSE;
    SDL_bool imageClicked2 = SDL_FALSE;
    SDL_bool imageClicked3 = SDL_FALSE; // Variable pour savoir si l'image a été cliquée

    while (!done)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                done = SDL_TRUE;
                break;
            case SDL_MOUSEBUTTONDOWN:

                if (SDL_PointInRect(&(SDL_Point){event.button.x, event.button.y}, &imageRect1))
                {
                    printf("Clicked 1 at x=%d, y=%d\n", event.button.x, event.button.y); // afficher les coordonnées du clic
                    imageClicked1 = SDL_TRUE;
                    if (clic % 2 == 0)
                    {
                        currentImage2 = texture4;
                        clic++;
                    }
                    else if (clic % 2 == 1)
                    {
                        currentImage2 = texture2;
                        clic++;
                    }
                }

                if (SDL_PointInRect(&(SDL_Point){event.button.x, event.button.y}, &imageRect2))
                {
                    printf("Clicked 2 at x=%d, y=%d\n", event.button.x, event.button.y); // afficher les coordonnées du clic
                    imageClicked2 = SDL_TRUE;
                    if (clic % 2 == 0)
                    {
                        currentImage = texture4;
                        clic++;
                    }
                    else if (clic % 2 == 1)
                    {
                        currentImage = texture1;
                        clic++;
                    }
                }

                if (SDL_PointInRect(&(SDL_Point){event.button.x, event.button.y}, &imageRect3))
                {
                    printf("Clicked Grille at x=%d, y=%d\n", event.button.x, event.button.y); // afficher les coordonnées du clic
                    imageClicked3 = SDL_TRUE;
                }
                break;

            case SDL_MOUSEBUTTONUP:
                if (imageClicked1)
                {
                    imageRect1.x = event.button.x - imageRect1.w / 2;
                    imageRect1.y = event.button.y - imageRect1.h / 2;
                    imageClicked1 = SDL_FALSE;
                }
                else if (imageClicked2)
                {
                    imageRect2.x = event.button.x - imageRect2.w / 2;
                    imageRect2.y = event.button.y - imageRect2.h / 2;
                    imageClicked2 = SDL_FALSE;
                }
                else //(imageClicked3)
                {
                    imageRect3.x = event.button.x - imageRect3.w / 2;
                    imageRect3.y = event.button.y - imageRect3.h / 2;
                    imageClicked3 = SDL_FALSE;
                }

                break;

                /* case SDL_MOUSEMOTION:
                     if (SDL_PointInRect(&(SDL_Point){event.motion.x, event.motion.y}, &imageRect1)) {
                         currentImage = texture2;
                     } else {
                         currentImage = texture1;
                     }
                     if (SDL_PointInRect(&(SDL_Point){event.motion.x, event.motion.y}, &imageRect2)) {
                         currentImage2 = texture2;
                     } else {
                         currentImage2 = texture1;
                     }
                     break;*/
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture3, NULL, NULL); // Afficher l'image blanche en arrière-plan
        SDL_RenderCopy(renderer, currentImage4, NULL, &imageRect4);
        SDL_RenderCopy(renderer, currentImage2, NULL, &imageRect1);
        SDL_RenderCopy(renderer, currentImage, NULL, &imageRect2);

        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(texture2);
    SDL_DestroyTexture(texture3);
    SDL_DestroyTexture(texture4);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
