#include <stdio.h>
#include <stdlib.h>
#include "./zColor.h"

#include <time.h>

#define X 17
#define Y 9

typedef enum
{
    PAS_JOUABLE,
    EJECTEE,
    NOIR,
    BLANC,
    LIBRE
} TYPE_CASE;

typedef enum
{
    A, // pas de direction
    NE,
    NO,
    SE,
    SO,
    E,
    O
} DIRECTION;

typedef struct
{
    int posX;
    int posY;
    TYPE_CASE type;

} CASE;

void iniPlateau(CASE monPlateau[Y][X]);
// void afficheNb(CASE monPlateau[Y][X]);
void affichePlateau(CASE monPlateau[Y][X]);
void DeplacePion(CASE plateau[Y][X], TYPE_CASE joueur, DIRECTION direction, int posX, int posY);
void Deplace2pion(CASE plateau[Y][X], TYPE_CASE joueur, DIRECTION direction, int posX, int posY);
void Deplace3pion(CASE plateau[Y][X], TYPE_CASE joueur, DIRECTION direction, int posX, int posY);

int main()
{
    CASE plateau[Y][X];
    iniPlateau(plateau);
    TYPE_CASE j1 = BLANC;
    TYPE_CASE j2 = NOIR;

    DIRECTION direction;
    int posX;
    int posY;

    affichePlateau(plateau);

    printf("quels pion voulez vous deplacer");
    printf("Votre X: ");
    scanf("%d", &posX);
    printf("Votre Y: ");
    scanf("%d", &posY);
    printf("Entrez la direction de mouvement : NE=1,NO=2,SE=3,SO=4,E=5,O=6 \n");
    scanf("%d", &direction);
    // DeplacePion(plateau, j2, direction, posX, posY);
    Deplace2pion(plateau, j2, direction, posX, posY);
    // Deplace3pion(plateau, j2, direction, posX, posY);

    sleep(2);

    affichePlateau(plateau);

    return 0;
}

void iniPlateau(CASE monPlateau[Y][X])
{

    for (int line = 0; line < Y; line++)
    {
        for (int col = 0; col < X; col++)
        {
            monPlateau[line][col].posX = col;
            monPlateau[line][col].posY = line;

            if ((line % 2) == 0)
            {
                if ((col % 2) == 0)
                    monPlateau[line][col].type = LIBRE;
                else
                    monPlateau[line][col].type = PAS_JOUABLE;
            }
            else
            {
                if ((col % 2) != 0)
                    monPlateau[line][col].type = LIBRE;
                else
                    monPlateau[line][col].type = PAS_JOUABLE;
            }
        }
    }

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < (4 - j); i++)
        {
            monPlateau[0 + j][i].type = EJECTEE;
            monPlateau[8 - j][i].type = EJECTEE;

            monPlateau[0 + j][13 + i + j].type = EJECTEE;
            monPlateau[8 - j][13 + i + j].type = EJECTEE;
        }
    }

    for (int line = 0; line < Y; line++)
    {
        for (int col = 0; col < X; col++)
        {
            if (monPlateau[line][col].type == LIBRE)
            {
                if (line < 2)
                    monPlateau[line][col].type = NOIR;
                if (line > 6)
                    monPlateau[line][col].type = BLANC;
                if (line == 2 && col > 5 && col < 11)
                    monPlateau[line][col].type = NOIR;
                if (line == 6 && col > 5 && col < 11)
                    monPlateau[line][col].type = BLANC;
            }
        }
    }
}

void affichePlateau(CASE monPlateau[Y][X])
{
    printf("\e[1;1H\e[2J"); // clear screen
    for (int line = 0; line < Y + 1; line++)
    {
        if (line != 0)
            printf(reset "%d", line - 1);
        else
            printf("0");
        for (int col = 0; col < X; col++)
        {
            if (line == 0)
                printf(reset "%-2.d", col);
            else
            {
                switch (monPlateau[line - 1][col].type)
                {
                case PAS_JOUABLE:
                    printf(BLUHB "  ");
                    break;
                case EJECTEE:
                    printf(REDHB "  ");
                    break;
                case NOIR:
                    printf(BLKHB "  ");
                    break;
                case BLANC:
                    printf(WHTHB "  ");
                    break;
                case LIBRE:
                    printf(reset "  ");
                    break;

                default:
                    printf(YELHB "  ");
                    break;
                }
            }
        }
        printf(reset "\n");
    }
    printf("\n");
}

void DeplacePion(CASE plateau[Y][X], TYPE_CASE joueur, DIRECTION direction, int posX, int posY)
{

    if (plateau[posY][posX].type != joueur)
    {
        printf("Mauvaise couleur !");
        return;
    }

    switch (direction)
    {
    case SO:
        if (plateau[posY + 1][posX - 1].type == LIBRE)
        {
            plateau[posY + 1][posX - 1].type = plateau[posY][posX].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }

        break;
    case SE:
        if (plateau[posY + 1][posX + 1].type == LIBRE)
        {
            plateau[posY + 1][posX + 1].type = plateau[posY][posX].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }

        break;

    case NE:
        if (plateau[posY - 1][posX + 1].type == LIBRE)
        {
            plateau[posY - 1][posX + 1].type = plateau[posY][posX].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }
        break;

    case NO:
        if (plateau[posY - 1][posX - 1].type == LIBRE)
        {
            plateau[posY - 1][posX - 1].type = plateau[posY][posX].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }
        break;

    case E:
        if (plateau[posY][posX + 1].type == LIBRE)
        {
            plateau[posY][posX + 1].type = plateau[posY][posX].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }
        break;
    case O:
        if (plateau[posY][posX - 1].type == LIBRE)
        {
            plateau[posY][posX - 1].type = plateau[posY][posX].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }
        break;
    case A:
    default:
        printf("Mauvaise direction");
        break;
    }
}

void Deplace2pion(CASE plateau[Y][X], TYPE_CASE joueur, DIRECTION direction, int posX, int posY)
{
    if (plateau[posY][posX].type != joueur)
    {
        printf("Mauvaise couleur !");
        return;
    }
    switch (direction)
    {
    case SO:
        if (plateau[posY + 2][posX - 2].type == LIBRE)
        {
            plateau[posY + 1][posX - 1].type = plateau[posY][posX].type;
            plateau[posY + 2][posX - 2].type = plateau[posY + 1][posX - 1].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }
        break;
    case SE:
        
        if (plateau[posY + 2][posX + 2].type == LIBRE)
        {
            plateau[posY + 1][posX + 1].type = plateau[posY][posX].type;
            plateau[posY + 2][posX + 2].type = plateau[posY + 1][posX + 1].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }
        break;
    case NE:
        if (plateau[posY - 2][posX + 2].type == LIBRE)
        {
            plateau[posY + 1][posX + 1].type = plateau[posY][posX].type;
            plateau[posY + 2][posX + 2].type = plateau[posY + 1][posX + 1].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }
        break;
    case NO:
        if (plateau[posY - 2][posX - 2].type == LIBRE)
        {
            plateau[posY - 1][posX - 1].type = plateau[posY][posX].type;
            plateau[posY - 2][posX - 2].type = plateau[posY - 1][posX - 1].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }
        break;
    case E:
       if (plateau[posY][posX + 2].type == LIBRE)
        {
            plateau[posY][posX+1].type = plateau[posY][posX+1].type;
            plateau[posY][posX - 2].type = plateau[posY][posX - 1].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }
            break;
    
    case O:
     if (plateau[posY][posX - 2].type == LIBRE)
        {
            plateau[posY][posX-2].type = plateau[posY][posX-1].type;
            plateau[posY][posX - 1].type = plateau[posY][posX].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }
        
    case A:
    default:
        break;
   
        printf("Mouvement invalide \n"); // REFAIRE LE MOUVEMENT
        break;
    }
}

void Deplace3pion(CASE plateau[Y][X], TYPE_CASE joueur, DIRECTION direction, int posX, int posY)
{

    if (plateau[posY][posX].type != joueur)
    {
        printf("Mauvaise couleur !");
        return;
    }

    switch (direction)
    {
    case SO:
        if (plateau[posY + 3][posX - 3].type == LIBRE)
        {
            plateau[posY + 1][posX - 1].type = plateau[posY][posX].type;
            plateau[posY + 2][posX - 2].type = plateau[posY + 1][posX - 1].type;
            plateau[posY + 3][posX - 3].type = plateau[posY + 2][posX - 2].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }

        break;
        case SE:
        if (plateau[posY + 3][posX + 3].type == LIBRE)
        {
            plateau[posY + 1][posX + 1].type = plateau[posY][posX].type;
            plateau[posY + 2][posX + 2].type = plateau[posY + 1][posX + 1].type;
            plateau[posY + 3][posX + 3].type = plateau[posY + 2][posX + 2].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }
        break;
    case NO :
    if (plateau[posY + 3][posX - 3].type == LIBRE)
        {
            plateau[posY + 1][posX - 1].type = plateau[posY][posX].type;
            plateau[posY + 2][posX - 2].type = plateau[posY + 1][posX - 1].type;
            plateau[posY + 3][posX - 3].type = plateau[posY + 2][posX - 2].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }
        
    break;
    case NE:
    if (plateau[posY - 3][posX + 3].type == LIBRE)
        {
            plateau[posY - 1][posX + 1].type = plateau[posY][posX].type;
            plateau[posY - 2][posX + 2].type = plateau[posY - 1][posX + 1].type;
            plateau[posY - 3][posX + 3].type = plateau[posY - 2][posX + 2].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }
    break;
    case E:
    if (plateau[posY][posX + 3].type == LIBRE)
        {
            plateau[posY][posX + 1].type = plateau[posY][posX].type;
            plateau[posY][posX + 2].type = plateau[posY][posX + 1].type;
            plateau[posY][posX + 3].type = plateau[posY][posX + 2].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }

    break;
    case O:
    if (plateau[posY][posX - 3].type == LIBRE)
        {
            plateau[posY][posX - 1].type = plateau[posY][posX].type;
            plateau[posY][posX - 2].type = plateau[posY][posX - 1].type;
            plateau[posY][posX - 3].type = plateau[posY][posX - 2].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }

    case A:
    default:
        printf("Mauvaise direction");
        break;
    }
}

/*
void Deplace2vs1(CASE plateau[Y][X], TYPE_CASE joueur, DIRECTION direction, int posX, int posY)
{

    if (plateau[posY][posX].type != joueur && [posY + 1][posX - 1].type != joueur )
    {
        printf("Mauvaise couleur !");
        
        return;
    }

    switch (direction)
    {
    case SO:
        if {
            plateau[posY + 1][posX - 1].type = plateau[posY][posX].type;
            plateau[posY][posX].type = LIBRE;
            }
        else
        {
            printf("la case n'est pas libre");
        }

        break;
    case SE:
        if (plateau[posY + 1][posX + 1].type == LIBRE)
        {
            plateau[posY + 1][posX + 1].type = plateau[posY][posX].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }

        break;

    case NE:
        if (plateau[posY - 1][posX + 1].type == LIBRE)
        {
            plateau[posY - 1][posX + 1].type = plateau[posY][posX].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }
        break;

    case NO:
        if (plateau[posY - 1][posX - 1].type == LIBRE)
        {
            plateau[posY - 1][posX - 1].type = plateau[posY][posX].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }
        break;

    case E:
        if (plateau[posY][posX + 1].type == LIBRE)
        {
            plateau[posY][posX + 1].type = plateau[posY][posX].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }
        break;
    case O:
        if (plateau[posY][posX - 1].type == LIBRE)
        {
            plateau[posY][posX - 1].type = plateau[posY][posX].type;
            plateau[posY][posX].type = LIBRE;
        }
        else
        {
            printf("la case n'est pas libre");
        }
        break;
    case A:
    default:
        printf("Mauvaise direction");
        break;
    }
}*/