#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "abalone.h"
#include "Donnees.h"
#include "init.c"

// On initialise les pions blancs et noirs sur le plateau.
int clic = 0;

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Images", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, 1, 0);

    SDL_Surface *imageG = IMG_Load("Grille_jeu2.png");
    SDL_Texture *textureG = SDL_CreateTextureFromSurface(renderer, imageG);
    SDL_FreeSurface(imageG);

    // SDL_Surface *image = IMG_Load("billeblanche.png");
    SDL_Surface *pim[14];
    SDL_Surface *pimb[14];
    SDL_Surface *pimbleu[14];

    for (int i = 0; i < 14; i++)
    {
        SDL_Surface *image = IMG_Load("billenoire.png");
        pim[i] = image;
        SDL_Surface *imageb = IMG_Load("billeblanche.png");
        pimb[i] = imageb;
        SDL_Surface *imagebleu = IMG_Load("billebleu.png");
        pimbleu[i] = imagebleu;
    }

    // SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_Texture *ptex[14];
    SDL_Texture *ptexb[14];
    SDL_Texture *ptexbleu[14];
    for (int i = 0; i<14; i++)
    {
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, pim[i]);
        ptex[i] = texture;
        SDL_Texture *textureb = SDL_CreateTextureFromSurface(renderer, pimb[i]);
        ptexb[i] = textureb;
        SDL_Texture *texturebleu = SDL_CreateTextureFromSurface(renderer, pimbleu[i]);
        ptexbleu[i] = texturebleu;
    }

    for (int i = 0; i < 14; i++)
    {
        //SDL_FreeSurface(image);
        SDL_FreeSurface(pim[i]);
        SDL_FreeSurface(pimb[i]);
        SDL_FreeSurface(pimbleu[i]);
    }

    SDL_Rect pimrect[2][14];
    SDL_Rect pimrectb[2][14];
    for (int i = 0; i < 14; i++)
    {
        SDL_Rect imageRect = {(conoire[0][i]) - 50, (conoire[1][i]) - 50, 100, 100};
        pimrect[1][i] = imageRect;
        // printf("test %d \n", pimrect[1][i]);

        SDL_Rect imageRectb = {(coblanc[0][i]) - 50, (coblanc[1][i]) - 50, 100, 100};
        pimrectb[1][i] = imageRectb;
        // printf("test %d \n", pimrectb[1][i]);
    }

    SDL_Color color = {255, 255, 255, 255};

    SDL_Texture *pcurim[14];
    SDL_Texture *pcurimb[14];
    SDL_Texture *pcurimbleu[14];
    for (int i = 0; i < 14; i++)
    {
        SDL_Texture *currentImage = ptex[i];
        pcurim[i] = ptex[i];
        SDL_Texture *currentImageb = ptexb[i];
        pcurimb[i] = ptexb[i];
        SDL_Texture *currentImagebleu = ptexbleu[i];
        pcurimbleu[i] = ptexbleu[i];
    }

    SDL_bool done = SDL_FALSE;
    SDL_bool imageClicked1 = SDL_FALSE;

    while (!done)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT: //On ferme la fenètre
                    done = SDL_TRUE;
                    break;

                case SDL_MOUSEBUTTONDOWN: // Il y a un clic de la souris
                    /*
                    if (SDL_PointInRect(&(SDL_Point){event.button.x, event.button.y}, &pimrect[2][i]))
                    {
                        printf("Clicked %d at x=%d, y=%d\n", i, event.button.x, event.button.y); // afficher les coordonnées du clic
                        imageClicked1 = SDL_TRUE;
                    }
                    break;
                    */
                    
                    for(int i=0;i<14;i++){
                        //printf("Clique %d,%d \n",&(SDL_Point){event.button.x}, &(SDL_Point){event.button.y});
                        if((&pimrect[1][i]) < (&(SDL_Point){event.button.x})){
                            printf("Clicked %d at x=%d\n", i, event.button.x); // afficher les coordonnées du clic
                            imageClicked1 = SDL_TRUE;
                        }
                        break;
                    }
                    
                    
        }
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, textureG, NULL, NULL); // Afficher l'image blanche en arrière-plan

    for (int i = 0; i < 14; i++)
    {
        SDL_RenderCopy(renderer, pcurim[i], NULL, &pimrect[1][i]);
        SDL_RenderCopy(renderer, pcurimb[i], NULL, &pimrectb[1][i]);
        
    }
    SDL_RenderPresent(renderer);
}

for (int i = 0; i < 14; i++)
{
    SDL_DestroyTexture(ptex[i]);
    SDL_DestroyTexture(ptexb[i]);
    SDL_DestroyTexture(ptexbleu[i]);
}

SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();

return 0;
}
