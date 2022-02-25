#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM  10
#define LUNG  20

/*
Si scriva una funzione malloc2d, in grado di allocare una matrice rettangolare di numeri reali,
le cui dimensioni sono ricevute come parametri.
La matrice viene inizializzata azzerando tutte le caselle.
*/

void stampaMat(float **mat, int nr, int nc){
    int k, i;

    printf("\n");

    for(k = 0; k < nr; k++){
        for(i = 0; i < nc; i++){
            printf("%5.1f ", mat[k][i]);
        }
        printf("\n");
    }
    return;
}

void inserisciNum(float **mat, int nr, int nc){
    int x, y;
    float num;


    do{
        printf("\nInserisci l'ascissa della posizione: ");
        scanf("%d", &x);
    }while(x < 0 || x > nc);

    do{
        printf("\nInserisci l'ordinata della posizione: ");
        scanf("%d", &y);
    }while(y < 0 || y > nr);

    printf("\nInserisci il numero da inserire: ");
    scanf("%f", &num);

    mat[x][y] = num;

    return;
}

void malloc2d(int nr, int nc){
    char s[LUNG];

    float **mat;
    mat = (float **) calloc(nr, sizeof(float*));
    for(int k = 0; k < nr; k++){
        mat[k] = (float *)calloc(nc, sizeof(float));
    }
    printf("\nMATRICE INIZIALIZZATA A 0\n");
    stampaMat(mat, nr, nc);

    do{
        inserisciNum(mat, nr, nc);
        printf("\nVuoi inserire altri numeri nella matrice? ('no' per uscire)\n");
        scanf("%s", s);
    }while(strcmp(s, "no") != 0);

    printf("\nMATRICE CON NUMERI REALI\n");
    stampaMat(mat, nr, nc);

    free(mat);
    return;
}

int main()
{
    int r, c;

    printf("Inserisci il numero di righe della matrice: ");
    scanf("%d", &r);
    printf("\nInserisci il numero di colonne della matrice: ");
    scanf("%d", &c);

    malloc2d(r, c);

    printf("\n");
    return 0;
}
