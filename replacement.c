#include <stdio.h>
#include <stdlib.h>
//  -lSDL2 -lSDL2_image 

typedef enum COULEUR{
    Noir =1,
    Blanc =0,
}couleur;

typedef struct piece{
    int posx,posy;
    int numéro;
    couleur joueur;
    struct piece *suiv;
    struct dir *alentours;
}pion;

typedef struct dir{
    pion *NE;
    pion *NO;
}direction;

int init(pion* elm){
    elm->posx =1;
    return(0);
}

void verif(pion premier){
    if(premier.posx != NULL){
        printf("Il y a un voisin \n");
    }
    else{
        printf("Case Libre \n");
    }
}

pion premier; pion deuxième;

void initblanc(){
    int tabterm[2][14] = {
    {4,6,8,10,12,
    3,5,7,9,11,13,
    6,8,10},
    {8,8,8,8,8,
    7,7,7,7,7,7,
    6,6,6
    }};
}

void initnoir(){
    int tabnterm[2][14] = {
    {12,10,8,6,4,
    13,11,9,7,5,3,
    10,8,6},
    {0,0,0,0,0,
    1,1,1,1,1,1,
    2,2,2
    }};
}


//Les variables tableaux doivent êtres définies en dehors de la fonction pour permettre l'existance en sortie de fct.
void initgrilleblanc(int caseb, int *x, int *y){
    // Les coordonnées sont données en pixels
    // On stocke les valeurs recues dans les pointeurs x et y pour pouvoir les utiliser après
    // Ici les blancs sont en haut du plateau étant donné qu'on suppose que le joueur joue les noirs
    int Gtabx[2][14] = {{
    1200,1080,960,840,720,
    1260,1140,1020,900,780,660,
    1080,1080,1080,
    },{
    120,120,120,120,120,
    225,225,225,225,225,225,
    330,330,330
    }};

    *x = Gtabx[0][caseb];
    *y = Gtabx[1][caseb];
}

int initgrillenoir(int casen,int *x, int *y){
    // Ici les pions sont en bas cas on suppose que le joueur joue les pions noirs
    // Les coordonnées sont données en pixels
    int Gtabn[2][14] ={{
    715,835,960,1080,1200,
    660,780,900,1020,1140,1260,
    835,960,1080
    },{
    955,955,955,955,955,
    850,850,850,850,850,850,
    745,745,745
    }};

    *x = Gtabn[0][casen];
    *y = Gtabn[1][casen];
}

int cases(int recup, int *x, int *y){
    //ligne 1 les X et ligne 2 les Y
    int test[2][61] ={{ 720,840,960,1080,1200,
                        1260,1140,1020,900,780,660,
                        600,720,840,960,1080,1200,1320,
                        1380,1260,1140,1020,900,780,660,535,
                        475,600,720,840,960,1080,1200,1320,1440,
                        1380,1260,1140,1020,900,780,660,535,
                        600,720,840,960,1080,1200,1320,
                        1260,1140,1020,900,780,655,
                        720,840,960,1080,1200},
                    {
                        955,955,955,955,955,
                        850,850,850,850,850,850,
                        745,745,745,745,745,745,745,
                        640,640,640,640,640,640,640,640,
                        540,540,540,540,540,540,540,540,540,
                        435,435,435,435,435,435,435,435,
                        330,330,330,330,330,330,330,
                        225,225,225,225,225,255,
                        120,120,120,120,120
                    }};

    *x = test[0][recup];
    *y = test[1][recup];
    return(0);
}


// Les fonctions pos_pixels prennent en arguments les entiers qui représentent la case dont nous voulons afficher les co. 
int pospixel_init_blanc(){
    int varx; int vary;int pos;

    printf("Entrez la position des pions blanc \n");
    scanf("%d",&pos);

    initgrilleblanc(pos,&varx,&vary);

    if((pos>14)||(pos<0)){
        printf("La case n'existe pas\n");
        pospixel_init_blanc();
    }
    else{
        printf("Voila x %d\n", varx);
        printf("Voila y %d\n", vary);
    }
    return(0);
}

int pospixel_init_noir(){
    int varx; int vary; int pos;
    printf("Entrez la position des pions noirs \n");
    scanf("%d",&pos);

    initgrillenoir(pos,&varx,&vary);

    if((pos>14)||(pos<0)){
        printf("La case n'existe pas\n");
        pospixel_init_noir();
    }
    else{
        printf("Voila x %d\n", varx);
        printf("Voila y %d\n", vary);
    }
    return(0);
}


int getco(){
    int recupx; int recupy;
    int x,y,num;

    printf("Entrez la case dont vous voulez les co \n");
    scanf("%d",&num);
    cases(num,&x,&y);

    recupx =x;
    recupy =y;

    if((num>61)||(num<0)){
        printf("La case n'existe pas \n");
        getco();
    }
    else{
        printf("%d,%d\n", recupx, recupy);
    }
    return(0);
}

int main(){
    getco();
    return(0);
}