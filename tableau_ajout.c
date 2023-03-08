#include <stdio.h>
#include <stdlib.h>
#include "outils.h"

int tableau_ajout(){
    int rows, cols, i, j, row_index, col_index;
    int** arr;

    printf("Entrez le nombre de lignes et de colonnes du tableau : ");
    scanf("%d""%d", &rows,&cols);

    // Alloue un tableau rectangulaire de dimensions rows x cols rempli de zéros
    arr = (int**) calloc(rows, sizeof(int*));
    for (i = 0; i < rows; i++) {
        arr[i] = (int*) calloc(cols, sizeof(int));
    }

    if (arr == NULL) {
        printf("Erreur : allocation de mémoire échouée.");
        exit(0);
    }

    printf("Entrez l'indice de la ligne et de la colonne où vous voulez mettre 1 : ");
    scanf("%d""%d", &row_index,&col_index);

    if (row_index >= rows || row_index < 0 || col_index >= cols || col_index < 0) {
        printf("Erreur : l'indice doit être compris entre (0,0) et (%d,%d).", rows-1, cols-1);
        exit(0);
    }

    arr[row_index -1][col_index - 1] = 1;

    printf("Le tableau final est : \n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Libère la mémoire allouée pour le tableau rectangulaire
    for (i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    
    return 0;
}

int tableau_ajoutpion(n,m) {
    int i, j, num_indices;
    int** arr;

    arr = (int**) calloc(n, sizeof(int*));  // alloue un tableau de n pointeurs

    if (arr == NULL) {
        printf("Erreur : allocation de mémoire échouée.");
        exit(0);
    }

    for (i = 0; i < n; i++) {
        arr[i] = (int*) calloc(m, sizeof(int));  // alloue un tableau de m entiers initialisés à 0 pour chaque pointeur
        if (arr[i] == NULL) {
            printf("Erreur : allocation de mémoire échouée.");
            exit(0);
        }
    }

    printf("Combien d'indices voulez-vous mettre à 1 ? ");
    scanf("%d", &num_indices);

    for (i = 1; i <= num_indices; i++) {
        printf("Entrez les coordonnées (ligne colonne) de l'indice n°%d où vous voulez mettre 1 : ", i);
        scanf("%d %d", &j, &i);

        if (i >= m || i < 0 || j >= n || j < 0) {
            printf("Erreur : les coordonnées doivent être comprises entre (0,0) et (%d,%d).", n-1, m-1);
            exit(0);
        }

        arr[j-1][i-1] = 1;
    }

    printf("Le tableau final est :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        free(arr[i]);  // libère la mémoire allouée pour chaque tableau de m entiers
    }
    free(arr);  // libère la mémoire allouée pour le tableau de pointeurs

    return 0;
}


int main(){
    int n,m;

    printf("Entrez le nombre de lignes du tableau : ");
    scanf("%d", &n);

    printf("Entrez le nombre de colonnes du tableau : ");
    scanf("%d", &m);

    tableau_ajoutpion(n,m);
    return(0);
}