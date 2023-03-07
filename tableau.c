#include <stdio.h>
#include <stdlib.h>

int tableau(){
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Allocation du tableau avec calloc
    int **arr = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)calloc(cols, sizeof(int));
    }

    // Affichage du tableau
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Libération de la mémoire allouée
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

int main(){
    printf("voila le tableau \n");
    tableau();
    return(0);
}