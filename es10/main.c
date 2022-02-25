#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Scrivere un programma che permette all’utente di inizializzare un array unidimensionale
di float e facendo uso dell’aritmetica dei puntatori:
- individui gli elementi con valore ripetuti
- sommi i numeri rimasti
*/

bool ricerca(float *v, int n, float cerca){
    int presenze = 0;
    bool ok = false;

    for(int k = 0; k < n; k++){
        if(cerca == *(v+k)){
            presenze++;
        }
    }
    if(presenze >= 2){
        ok = true;
    }
    return ok;
}

int main()
{
    float *v;
    int n;

    printf("Inserisci la lunghezza del vettore: ");
    scanf("%d", &n);

    v = (float*) malloc(n * sizeof(float));

    for(int k = 0; k < n; k++){
        printf("\nInserisci il valore della cella [%d]: ", k);
        scanf("%f", v+k);
    }
    printf("\n");
    for(int k = 0; k < n; k++){
        printf("%.2f ", *(v+k));
    }

    bool ok;
    float *vTemp;
    float som = 0;
    int i = 0;

    vTemp = (float*) malloc(n * sizeof(float));

    for(int k = 0; k < n; k++){
        ok = ricerca(v, n, *(v+k));
        if(ok == true){
            *(vTemp+i) = *(v+k);
            i++;
        }else{
            som = som + *(v+k);
        }
    }

    printf("\n\nELEMENTI PRESENTI PIU' VOLTE NEL VETTORE: \n");
    for(int k = 0; k < i; k++){
        printf("%.2f ", *(vTemp+k));
    }
    printf("\nSOMMA DEGLI ELEMENTI DEL VETTORE PRESENTI UNA SOLA VOLTA: %.2f", som);
    free(v);

    printf("\n");
    return 0;
}
