#include <stdio.h>
#include <stdlib.h>

/*Galfre' Mattia*/

/*Scrivere un programma per leggere e stampare array bidimensionale di float. Il
programma richiede all’utente il numero di righe e di colonne dopo di che richiede ad
uno ad uno gli elementi da inserire nell'array.  Il programma inserisce in un secondo
array unidimensionale i numeri più grandi di ogni riga. Allocare e deallocare l’array
restituito.*/

int main()
{
    float **mat;        //dichiaro la matrice come un puntatore a puntatori a float
    int nr, nc;     //dichiaro le variabili numero di righe e colonne

    printf("Inserisci il numero di righe della matrice: ");     //input righe e colonne
    scanf("%d", &nr);

    printf("Inserisci il numero di colonne della matrice: ");
    scanf("%d", &nc);

    mat = (float **) malloc(nr * sizeof(float*));       //alloco dinamicamente la matrice
    for(int k = 0; k < nr; k++){
        mat[k] = (float *)malloc(nc * sizeof(float));
    }

    for(int r = 0; r < nr; r++){
        for(int c = 0; c < nc; c++){
            printf("Inserisci il valore della cella [%d][%d]: ", r, c);     //inizializzo la matrice
            scanf("%f", &mat[r][c]);
        }
    }

    printf("\nMATRICE: \n");

    for(int r = 0; r < nr; r++){        //stampo la matrice
        for(int c = 0; c < nc; c++){
            printf("%.2f | ", mat[r][c]);
        }
        printf("\n");
    }

    float *v;       //dichiaro il vettore come un puntatore a float
    int indiceVet = 0;      //dichiaro e inizializzo la variabile utile per l'indice del vettore di supporto
    v = (float*)malloc(nr * sizeof(float));

    for(int r = 0; r < nr; r++){        //costruisco il vettore del massimo per ogni riga
            float max = 0;
            max = mat[r][0];
        for(int c = 1; c < nc; c++){
            if(mat[r][c] > max){
                max = mat[r][c];
            }
        }
        *(v+indiceVet) = max;
        indiceVet++;
    }


    printf("\nVETTORE: \n");        //stampo il vettore
    for(int z = 0; z < nr; z++){
        printf("%.2f | ", *(v+z));
    }

    free(mat);      //disalloco matrice e vettore
    free(v);

    printf("\n");
    return 0;
}
