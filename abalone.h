#ifndef ABALONE_H_INCLUDED
#define ABALONE_H_INCLUDED

//Definitions des deux joueurs
enum joueur{VIDE, NOIR, BLANC,EJECTE};

//Création d'un pion avec la couleur, le numéro du pion et ces alentours
typedef struct jeu{
    enum joueur couleur;
    int posX, posY;
    struct coordonnées *alentours;
}CASE;


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
//Fonctions SDL



//Fonction test
//void testByPrint(int i);

#endif // ABALONE_H_INCLUDED
