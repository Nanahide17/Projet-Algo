#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

#include "abalone.h"
#include "Donnees.h"
#include "init.c"

typedef struct // On fait une structure pour les états du bouton, utilisée par la suite.
{
    SDL_Rect rect;
    bool clicked;
} Button;

void demande(int *pointeur) // demande combien de boules l'utilisateur veut déplacer
{
    int element;
    printf("Combien de billes souhaitez vous déplacer ?\n");
    scanf("%d", &element);

    if ((element > 3) || (element <= 0)) // Si le chiffre dépasse 3 on redemande en expliquant les règles
    {
        printf("Saisie invalide : le nombre de billes doit être compris entre 1 et 3, merci de réessayer\n");
        demande(pointeur);
    }
    else //Sinon on affecte la valeur au pointeur d'entrée
    {
        *pointeur = element;
    }
}

void placement() // demande à l'utilisateur où il veut placer les boules.
{
    printf("Cliquer où vous souhaiter poser la/les boules\n");
}

int confirmation() // Demande si l'utilisateur à bien choisi ces billes
{
    int essai = 0;
    printf("Souhaiter vous confirmer la selection des billes ? 1 = oui, 0 = non.\n");
    scanf("%d\n", &essai);
    if (essai == 1) // Si il dit oui on continue et on demande ou est-ce qu'il les poses.
    {
        printf("C'est OOOOKKKKKKK \n");
        placement();
    }
    else // Sinon il doit rechoisir  PAS FAIT ENCORE.
    {
        printf("c'est nulllll \n");
    }
    return (0);
}

int grille() // On défini notre grille 
{
    Button button = {{0, 0, 100, 50}, false}; // on défini un bouton avec la structure (voir début)

    // On crée une fenetre 'image' centrée, et on charge la grille dans une texture
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Abalone", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);// On crée la fenetre
    SDL_Renderer *renderer = SDL_CreateRenderer(window, 1, 0); // Avec un rendu sinon c'est tout noir

    SDL_Surface *imageG = IMG_Load("Grille_jeu2.png"); // On charge dans ce rendu l'image de la grille de jeu 
    SDL_Texture *textureG = SDL_CreateTextureFromSurface(renderer, imageG); // On crée une texture pour cette image.
    SDL_FreeSurface(imageG); // On suprime l'image puisqu'elle vient d'être chargée dans sa texture

    SDL_Surface *pim[1]; // pim = Pointeur Image Noir
    SDL_Surface *pimb[1]; // pimb = Pointeur Image Blanc
    SDL_Surface *pimbleu[1]; // pimbleu = Pointeur Image Bleu

    SDL_Surface *image = IMG_Load("billenoire.png");
    pim[0] = image; // On stocke les images dans des tableaux 1 case pour économiser la mémoire
    SDL_Surface *imageb = IMG_Load("billeblanche.png");
    pimb[0] = imageb;
    SDL_Surface *imagebleu = IMG_Load("billebleu.png");
    pimbleu[0] = imagebleu;

    SDL_Texture *ptex[61]; //Pointeur texture bille noir
    SDL_Texture *ptexb[61]; //Pointeur texture bille blanche
    SDL_Texture *ptexbleu[61]; //Pointeur texture bille bleu
    for (int i = 0; i < 61; i++)
    {
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, pim[0]); //On crée des textures pour chaque type de boules sinon elle peuvent pas s'afficher
        ptex[i] = texture;
        SDL_Texture *textureb = SDL_CreateTextureFromSurface(renderer, pimb[0]);
        ptexb[i] = textureb;
        SDL_Texture *texturebleu = SDL_CreateTextureFromSurface(renderer, pimbleu[0]);
        ptexbleu[i] = texturebleu;
    }

    SDL_Rect pimrect[2][61];
    SDL_Rect pimrectb[2][61]; //On crée des rectangles qui vont nous servir à définir si les images des billes sont cliquées ou non 
    for (int i = 0; i < 61; i++)
    {
        SDL_Rect imageRect = {(coplateau[0][i]) - 50, (coplateau[1][i]) - 50, 100, 100}; // Les rectangles sont décaler de 50 px pour etre bien centrée avec les boules sur les cases du plateau
        pimrect[1][i] = imageRect; // On fait ça pour les billes blanches et noires mais pas les bleues car bleu = blanche/noire modifiée.
        SDL_Rect imageRectb = {(coplateau[0][i]) - 50, (coplateau[1][i]) - 50, 100, 100};
        pimrectb[1][i] = imageRectb;
    }

    SDL_Texture *pcurim[61]; //Pointeur Image courante noire
    SDL_Texture *pcurimb[61]; //pointeur Image courante blanche 
    for (int i = 0; i < 61; i++)
    {
        pcurim[i] = ptex[i]; // On stocke nos images dans un pointeur sur SDL_texture (utile pour sauvegarder les parties).
        pcurimb[i] = ptexb[i]; //De cette manière, si on modifie une bille, seule l'image courante est modifiée et on peux reset la grille à n'importe quelle étape.
    }

    SDL_bool done = SDL_FALSE; // On défini un évènement réglé à FAUX qui va nous servir 'tant que le jeu n'est pas fini'.

    int i = 0;
    int compteur = 0;
    int *pointeurcompteur = 0; // Je fais un poiteur sur le compteur ( au cas ou )

    int *x = 0;
    int *y = 0;

    int valeur=0;
    
    int tour = 0;
    int fini = 0;
    int conf = 0;
    
    demande(&x); // Vu au dessus

    while (fini == 0) // Tant que la partie n'est pas finie
    {   
        while (!done)
        {   
            SDL_Event event;

            while (SDL_PollEvent(&event))
            {   
                if (conf == 1) // Variable de confirmation (état confirmé pour le changement de tour)
                {   
                    if (tour == 0) //Si les noirs viennent de jouer on reset les pions et on passe au tour des blancs.
                    {   
                        
                        for (int i = 0; i < 61; i++) // On remet toutes les billes dans leur couleur d'origine (on efface la selection bleue).
                        {
                            pcurimb[i] = ptexb[0];
                            pcurim[i] = ptex[0];
                        }
                        demande(&x); // On demande aux blancs de choisirs un nombre de billesà bouger 
                        tour = 1; //
                        fini = 1;
                    }

                    else if (tour == 1) //Si les blancs viennent de jouer on reset les pions et on passe au tour des noirs.
                    {   
                        demande(&y);
                        for (int i = 0; i < 61; i++) // On remet toutes les billes dans leur couleur d'origine (on efface la selection bleue).
                        {
                            pcurimb[i] = ptexb[0];
                            pcurim[i] = ptex[0];
                        }
                        tour = 0;
                    }
                    conf = 0; //On fait le tour jusqu'à ce que le placement des nouvelles billes soit confirmé.
                }

                switch (event.type) // 
                {
                
                case SDL_QUIT: // Si l'utilisateur ferme la fenetre notre évènement passe à TRUE et on sort de la boucle.
                    done = SDL_TRUE;
                    break;

                case SDL_MOUSEBUTTONDOWN: // Quand il y a un clic de la souris 
                    int x1;
                    int y1;
                    x1 = event.button.x; // On récupère les coordonnées x et y de ce clic
                    y1 = event.button.y;

                    for (int k = 0; k < 61; k++) // On dit que le clic peut avoir lieu sur tout le plateau et on met le numéro de la bille dans 'i' sinon on colorie les boules selectionnée jusqu'à i.
                    {
                        if ((((coplateau[0][k])) > (x1 - 35)) && (((coplateau[0][k])) <= (x1 + 35)))
                        {
                            if ((((coplateau[1][k]) - 35) > (y1 - 35)) && (((coplateau[1][k]) - 35) <= (y1 + 35)))
                            {
                                i = k;
                            }
                        }
                    }

                    // On compare la boule et le clic et si c'est dedans...
                    // On change la couleur de la bille correspondante
                    if ((coplateau[0][i] > (x1 - 35)) && (coplateau[0][i] <= (x1 + 35)) && (coplateau[1][i] > (y1 - 35)) && (coplateau[1][i] <= (y1 + 35)))
                    {   
                        valeur =x; // Ici on récupère le nombre rentré par l'utilisateur dans 'demande()'.
                        if (tour == 0) // Quand tour vaut 0 les noirs jouent
                        {   
                            if ((pcurim[i]) == (ptexbleu[i]))// Si la bille est bleue
                            {
                                pcurim[i] = ptex[i]; // Elle redevient noire et le compteur diminue (le coup n'a pas été joué).
                                compteur--;
                                pointeurcompteur = compteur;
                            }
                            else
                            {   
                                if ((compteur > valeur) || (compteur < 0))  // On vérifie que le nombre de billes qui changent de couleur ne dépasse pas le nombre de billes à bougers
                                {
                                    printf("Coup impossible\n"); // Si l'utilisateur à dit qu'il voulait bouger 2 boules, il ne peut pas en bouger 3
                                    printf("Appuyer sur 'ENTRER' une fois la sélection faite.\n");
                                }
                                else
                                {
                                    pcurim[i] = ptexbleu[i]; // La bille cliquée devient bleu si elle était noire/
                                    compteur++; //Le coup à été joué et on incrémente le compteur ( plus que x boules à placer avant fin du tour).
                                    pointeurcompteur = compteur;
                                }
                            }
                        }

                        else if (tour == 1) // Quand tour vaut 1 les blancs jouent
                        {
                            if ((pcurimb[i]) == (ptexbleu[i])) // Si la bille est bleue
                            {
                                pcurimb[i] = ptexb[i]; // Elle redevient blanche et le compteur diminue (le coup n'a pas été joué).
                                compteur--;
                                pointeurcompteur = compteur;
                            }
                            else
                            {
                                if ((compteur > valeur) || (compteur < 0)) // On vérifie que le nombre de billes qui changent de couleur ne dépasse pas le nombre de billes à bougers
                                {
                                    printf("Coup impossible\n"); // Si l'utilisateur à dit qu'il voulait bouger 2 boules, il ne peut pas en bouger 3
                                    printf("Appuyer sur 'ENTRER' une fois la sélection faite.\n");
                                }
                                else 
                                {
                                    pcurimb[i] = ptexbleu[i]; // La bille cliquée devient bleu si elle était blanche.
                                    compteur++; //Le coup à été joué et on incrémente le compteur (plus que x boules à placer avant fin du tour).
                                    pointeurcompteur = compteur;
                                }
                            }
                        }
                    }

                case SDL_KEYDOWN: // Si une touche du clavier est appuyée 
                    if (event.button.button == SDL_SCANCODE_RETURN) // Si cette touche est 'ENTREE'
                    {
                        button.clicked = true; // l'état du bouton dans la stucture passe à TRUE
                        int valeur = x;
                        int valeurcompteur = pointeurcompteur;

                        if (valeurcompteur != valeur) // On compare la valeur du compteur et le nombre de billes que l'utilisateur voulait bouger
                        {
                            printf("Impossible de valider\n"); // Si c'est différent (la selection n'est pas finie)
                        }
                        else 
                        {
                            confirmation(); // Si la sélection est finie on demande la confirmation des billes 
                            conf = 1; // L'état est confirmé, on va pouvoir nettoyer la grille et passer au tour d'après.
                        }
                    }
                }
            }

            SDL_RenderClear(renderer); // On actualise le rendu 
            //SDL_RenderCopy(renderer, textureG, NULL, NULL); // Afficher l'image blanche en arrière-plan

            for (int i = 0; i < 61; i++) // Pour chaque case
            {
                if ((i < 11) || ((i >= 13) && (i < 16))) // Sur les emplacement des billes noires, on affiche les billes noires
                {
                    SDL_RenderCopy(renderer, pcurim[i], NULL, &pimrect[1][i]);
                }
                else if (((i > 44) && (i < 48)) || (i > 49)) // Sur les emplacement des billes blanches, on affiche les billes blanches
                {
                    SDL_RenderCopy(renderer, pcurimb[i], NULL, &pimrectb[1][i]);
                }
            }
            SDL_RenderPresent(renderer); // On affiche le nouveau rendu
        }
    }

    SDL_FreeSurface(pim[0]); // On libere toutes les surfaces de la mémoire
    SDL_FreeSurface(pimb[0]);
    SDL_FreeSurface(pimbleu[0]);

    for (int i = 0; i < 61; i++)
    {
        SDL_DestroyTexture(ptex[i]); // On détruit toutes les textures du plateau.
        SDL_DestroyTexture(ptexb[i]);
        SDL_DestroyTexture(ptexbleu[i]);
    }

    SDL_DestroyRenderer(renderer); // On détruit le rendu et la fenetre et on quitte
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

int main()
{
    grille();
    return (0);
}