#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Bouton", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 200, 100, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    
    SDL_Rect button = {50, 25, 100, 50};
    SDL_Color color = {255, 255, 255, 255};
    
    SDL_bool done = SDL_FALSE;
    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    done = SDL_TRUE;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    {
                        SDL_Point mouse_position = {event.button.x, event.button.y};
                        if (SDL_PointInRect(&mouse_position, &button)) {
                            printf("Bonjour\n");
                            color.r = 0;
                            color.g = 255;
                            color.b = 0;
                        }
                    }
                    break;
                case SDL_MOUSEMOTION:
                    {
                        SDL_Point mouse_position = {event.motion.x, event.motion.y};
                        if (SDL_PointInRect(&mouse_position, &button)) {
                            color.r = 255;
                            color.g = 0;
                            color.b = 0;
                        } 
                        else {
                            color.r = 255;
                            color.g = 255;
                            color.b = 255;
                        }
                    }
                    break;
            }
        }
        
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(renderer, &button);
        SDL_RenderPresent(renderer);
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
