#include <stdio.h>
#include <stdlib.h>
#include "abalone.h"
#include<stdbool.h>


///On ne s'intéresse pas à la couleur du joueur
///Effectue le déplacement et modifie la couleur de la struct
///Gére le cas où la case de destination est VIDE
///Cas où on arrive sur le bord (détecter si la case de destination est NULL)(pas encore fait)
///Et le cas où il y a une bille sur la case de destination
bool DeplacePion(DIRECTION direction, CASE* case_a_deplacer, TYPE_CASE couleur_joueur, int nb_meme_bille_derriere, int nb_bille_ennemi)
{
    //TODO : stocker couleur du joueur, faire fonction qui prend direction et case à deplacer qui va initialiser nb meme bille et nb bille ennemi
    CASE* case_de_destination;
    bool deplacement_possible;

    if(nb_meme_bille_derriere>=3){
        //Vérifie si on ne déplace pas trop de bille (à partir de 4 billes)
        return false;
    }

    //Détermination de la direction de la case de destination
    switch (direction)
    {
    case SO:
         case_de_destination=case_a_deplacer->alentours->SO;
        break;
    case SE:
        case_de_destination=case_a_deplacer->alentours->SE;
        break;
    case NE:
        case_de_destination=case_a_deplacer->alentours->NE;
        break;
    case NO:
        case_de_destination=case_a_deplacer->alentours->NO;
        break;
    case E:
        case_de_destination=case_a_deplacer->alentours->E;
        break;
    case O:
        case_de_destination=case_a_deplacer->alentours->O;
        break;
    }

    switch(case_de_destination->couleur)
    {
    //TODO : Gérer cas EJECTE return true
    case VIDE:
        //La case de destination prend la couleur de la case à déplacer et on vide la case à déplacer
        case_de_destination->couleur=case_a_deplacer->couleur;
        case_a_deplacer->couleur=VIDE;
        return true;
        break;

    //On a une bille en face
    default :
        //Si ami dans la case de destination, incrémentation compteur bille ami
        if((case_a_deplacer->couleur==case_de_destination->couleur)==couleur_joueur){
            nb_meme_bille_derriere++;
            deplacement_possible=DeplacePion(direction,case_de_destination,couleur_joueur,nb_meme_bille_derriere,nb_bille_ennemi);
            if(deplacement_possible){
                case_de_destination->couleur=case_a_deplacer->couleur;
                case_a_deplacer->couleur=VIDE;
            }
            return deplacement_possible;
        }

        //Cas où bille d'en face est une bille ennemi, incrémentation compteur bille ennemi
        else if(case_a_deplacer->couleur!=case_de_destination->couleur){
            nb_bille_ennemi++;
            deplacement_possible=DeplacePion(direction,case_de_destination,couleur_joueur,nb_meme_bille_derriere,nb_bille_ennemi);
            if(deplacement_possible){
                case_de_destination->couleur=case_a_deplacer->couleur;
                case_a_deplacer->couleur=VIDE;
            }
            return deplacement_possible;
        }

        //Si plusieur bille ennemi à la suite, incrémentation compteur bille ennmi
        else if((case_a_deplacer->couleur==case_de_destination->couleur)!=couleur_joueur){
            nb_bille_ennemi++;
            deplacement_possible=DeplacePion(direction,case_de_destination,couleur_joueur,nb_meme_bille_derriere,nb_bille_ennemi);
            if(deplacement_possible){
                case_de_destination->couleur=case_a_deplacer->couleur;
                case_a_deplacer->couleur=VIDE;
            }
            return deplacement_possible;
        }

        //Cas où il y a une bille du jouer derrière celle de l'ennemi (ex: noir, noir, blanc, blanc, noir)(donc non jouable)
        else if((case_a_deplacer->couleur!=case_de_destination->couleur)&&(case_a_deplacer->couleur!=couleur_joueur)){
            return false;
        }

        //TODO : Gerer le cas où pas assez de bille pour pousser l'ennemi (car pour l'instant si la case derrière l'ennemi est vide, on peut jouer)
        break;
    }
}