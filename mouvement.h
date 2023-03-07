#include <stdio.h>
#include <stdlib.h>

int numéro1, numéro2, numéro3, mvt;

int mouvement()
{
    printf("Entrez le nombre de billes que vous voulez bouger\n");
    scanf("%d", &mvt);

    if (mvt == 1)
    {
        printf("Entrez le numéro de la bille que vous voulez bouger :\n");
        scanf("%d", &numéro1);
        return;
    }

    else if (mvt == 2){
        printf("Entrez le numéro des billes que vous voulez bouger :\n");
        scanf("%d""%d",&numéro1, &numéro2);
        return;
    }

    else if (mvt == 3){
        printf("Entrez le numéro des billes que vous voulez bouger :\n");
        scanf("%d""%d""%d", &numéro1, &numéro2, &numéro3);
        return;
    }

    else{
        printf("mouvement impossible \n");
        mouvement();
    }
}