#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //Création de la variable pour la fenetre
    SDL_Window *window = NULL;
    int statut = EXIT_FAILURE;

    //Initialisation
    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
	  //Gestion d'erreur
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }

    //Création de la fênetre
    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              640, 480, SDL_WINDOW_SHOWN);
    if(NULL == window)
    {
	  //Gestion d'erreur
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        goto Quit;
    }
    statut = EXIT_SUCCESS;

    //Affichage de la fênetre pendant 3000ms
    SDL_Delay(3000);

    //Destruction de la fênetre
    SDL_DestroyWindow(window);

    //Sortie de SDL
Quit:
    SDL_Quit();
    return statut;
}
