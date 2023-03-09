#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO); // Initialise SDL
    SDL_Window* window = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0); // Crée une fenêtre SDL
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0); // Crée un renderer SDL pour la fenêtre

    SDL_Surface* image_surface = IMG_Load("hello.png"); // Charge l'image PNG en mémoire
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image_surface); // Crée une texture SDL à partir de la surface de l'image
    SDL_FreeSurface(image_surface); // Libère la surface de l'image, qui n'est plus nécessaire

    SDL_RenderClear(renderer); // Efface le renderer
    SDL_RenderCopy(renderer, texture, NULL, NULL); // Copie la texture de l'image sur le renderer
    SDL_RenderPresent(renderer); // Affiche le renderer

    SDL_Delay(5000); // Attends 5 secondes avant de quitter

    SDL_DestroyTexture(texture); // Détruit la texture de l'image
    SDL_DestroyRenderer(renderer); // Détruit le renderer
    SDL_DestroyWindow(window); // Détruit la fenêtre
    SDL_Quit(); // Ferme SDL

    return 0;
}
