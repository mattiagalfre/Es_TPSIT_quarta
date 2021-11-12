#include <stdio.h>
#include <stdlib.h>

/*
Scrivere un programma per leggere e stampare
array bidimensionale di interi. Il programma richiede all’utente il numero
di righe e di colonne dopo di che richiede ad uno ad uno gli elementi da inserire
nell'array. Il programma inoltre deve gestire dinamicamente l'allocazione
e la deallocazione della memoria.
*/

int main()
{
    int **mat;
    int nr, nc;

    printf("Inserisci il numero di righe della matrice: ");
    scanf("%d", &nr);
    printf("Inserisci il numero di colonne della matrice: ");
    scanf("%d", &nc);


    mat = (int **) malloc(nr * sizeof(int*));
    for(int k = 0; k < nr; k++){
        mat[k] = (int *)malloc(nc * sizeof(int));
    }

    for(int r = 0; r < nr; r++){
        for(int c = 0; c < nc; c++){
            printf("\nInserisci l'elemento [%d][%d] della matrice: ", r, c);
            scanf("%d", &mat[r][c]);
        }
    }

    for(int r = 0; r < nr; r++){
        for(int c = 0; c < nc; c++){
            printf("%d ", mat[r][c] );
        }
        printf("\n");
    }

    free(mat);

    printf("\n");
    return 0;
}
