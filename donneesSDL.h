#ifndef DONNEESSDL_H_INCLUDED
#define DONNEESSDL_H_INCLUDED

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *imageG;
SDL_Texture *image_bille_noire;
SDL_Texture *image_bille_blanc;
SDL_Texture *image_bille_bleu;
SDL_Rect casse[61];
SDL_Texture *current_state_bille_noir[61];
SDL_Texture *current_state_bille_blanc[61];

int liste_bille_selectionne[3];
int ejection_blanc, ejection_noir;
int tour;


#endif // DONNEESSDL_H_INCLUDED
