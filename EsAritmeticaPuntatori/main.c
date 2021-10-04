#include <stdio.h>
#include <stdlib.h>
#define DIM 5

void scambio(int *x, int *y){
    int t;

    t = *x;
    *x = *y;
    *y = t;

    return;
}

void ordinamentoBubbleSort(int v[], int n){
    int sup, k;

    for(sup = n-1; sup > 0; sup--){
        for(k = 0; k < sup; k++){
            if(*(v+k) > *(v+k+1)){
                scambio(v+k, v+k+1);
            }
        }
    }
    return;
}

void leggiVettori(int vett[], int n){
    int k;

    for(k = 0; k < n; k++){
        printf("Inserisci l'elemento [%d]: ", k);
        scanf("%d", vett+k);
    }
    return;
}

void stampaVett(int v[], int n){
    int k;

    for(k = 0; k < n; k++){
        printf("%d | ", *(v+k));
    }
    return;
}

int main()
{
    int v[DIM];
    leggiVettori(v, DIM);
    printf("\nPrima dell'ordinamento: \n");
    stampaVett(v, DIM);
    printf("\n");
    ordinamentoBubbleSort(v, DIM);
    printf("\nDopo l'ordinamento: \n");
    stampaVett(v, DIM);


    printf("\n");
    system("PAUSE");
    return 0;
}
