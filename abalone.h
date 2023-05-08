#ifndef ABALONE_H_INCLUDED
#define ABALONE_H_INCLUDED

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//Definitions des deux joueurs
typedef enum joueur{VIDE, NOIR, BLANC, EJECTE}TYPE_CASE;

//Création d'un pion avec la couleur, le numéro du pion et ces alentours
typedef struct jeu{
    TYPE_CASE couleur;
    int posX, posY; //posX et posY sont en pixels
    struct coordonnees *alentours;
}CASE;

typedef enum direction{NO=1,O=2,SO=3,NE=4,E=5,SE=6}DIRECTION;

typedef struct coordonnees{
    CASE *NO;
    CASE *O;
    CASE *SO;
    CASE *NE;
    CASE *E;
    CASE *SE;
}POS;

typedef struct pile{
    CASE* premier;
}PILE;

typedef struct // On fait une structure pour les états du bouton, utilisée par la suite.
{
    SDL_Rect rect;
    bool clicked;
} Button;

//Tableau pour recenser les cases
CASE* structcase[61];
//Tableau pour recenser position bille dans structcase
int conoire[14], coblanc[14];

//Fonction principale
int main();

//Fonctions d'initialisation
void initialisationPlateau();
void creationCase(CASE* casse, int i);
void defJoueurinit(CASE* casse);
void alentour();
void initialisationPile(PILE* pil, CASE* casse);
void reliageBas(PILE* pile1, PILE* pile2);
void reliageHaut(PILE* pile1, PILE* pile2);

//Fonctions déplacement
void deplacement(int nb_bille_a_bouger, DIRECTION direction, SDL_Texture *current_state[61], TYPE_CASE couleur);
bool verificationDeplacement(int nb_bille_amie, DIRECTION mouvement);
void cliqueSurDeplacement(int nb_bille_a_bouger, SDL_Texture *current_state[61], TYPE_CASE couleur);

//Fonction outils
DIRECTION trouveDirection(CASE* emplacement_bille, CASE* destination);
int trouveCASE(int X, int Y);
bool isInsideCASE(int X, int Y, CASE* casse);
void triCASE(int nb_bille);

//Fonctions SDL
void initialisationGrille();
int grille();
int demande();
void affichage_SDL();
void selection_bille(int *liste_bille_selectionne, int nb_bille_a_bouger,SDL_Texture *current_state[61], SDL_Texture *image_bille, TYPE_CASE couleur);

//Fonction test
//void testByPrint(int i);


#endif // ABALONE_H_INCLUDED
