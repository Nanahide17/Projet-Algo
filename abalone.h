#ifndef ABALONE_H_INCLUDED
#define ABALONE_H_INCLUDED

#include <stdbool.h>
//Definitions des deux joueurs
typedef enum joueur{VIDE, NOIR, BLANC, EJECTE}TYPE_CASE;

//Création d'un pion avec la couleur, le numéro du pion et ces alentours
typedef struct jeu{
    TYPE_CASE couleur;
    int posX, posY; //posX et posY sont en pixels
    struct coordonnées *alentours;
}CASE;

typedef enum direction{NO,O,SO,NE,E,SE}DIRECTION;

typedef struct coordonnées{
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

//Tableau pour recenser les cases
CASE* structcase[61];

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
bool DeplacePion(DIRECTION direction, CASE* case_a_deplacer, TYPE_CASE couleur_joueur, int nb_meme_bille_derriere, int nb_bille_ennemi);
DIRECTION trouveDirection(CASE* emplacement_bille, CASE* destination);
CASE* trouveCASE(int X, int Y);
bool isInsideCASE(int X, int Y, CASE* casse);
//Fonctions SDL



//Fonction test
//void testByPrint(int i);

#endif // ABALONE_H_INCLUDED
