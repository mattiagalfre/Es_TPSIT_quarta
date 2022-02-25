#include <stdio.h>
#include <stdlib.h>

#define DIM  20

/*Galfre' Mattia*/

/*Scrivere un programma che legga da file verifica.dat:
- Numero di elementi dell’array di float (prima riga)
- Riempie un array con i valori float contenuti dalla seconda riga in poi*/

void leggiDaFile(char nomeFile[], float *v, int n, int *nValori){
    FILE *fp;
    int k = 0;

    fp = fopen(nomeFile, "r");      //apro il file in lettura

    if(fp == NULL){         //controllo che il file ci sia
        printf("Errore nel file");
    }else{
        while(k < n && fscanf(fp, "%d", &*nValori) != EOF){     //leggo ogni elemento del file fino a che i dati saranno terminati
            for(int i = 0; i < *nValori; i++){
                fscanf(fp, "%f", (v+i));
            }
            k++;
        }
    }
    fclose(fp);
    return;
}

int main()
{
    float *v;                   //dichiaro il vettore come un puntatore a float
    int nValori = 0;            //dichiaro e inizializzo a zero la variabile che conterrà il valore della prima riga del file, il numero di elementi

    v = (float*) malloc(DIM * sizeof(float));     //alloco dinamicamente il vettore

    leggiDaFile("verifica.dat", v, DIM, &nValori);  //uso la funzione leggiDaFile per leggere i dati presenti in "verifica.dat" e inserirli nelle variabili corrette

    printf("Dal file si sono letti %d elementi float", nValori);    //stampo il numero di elementi e il vettore appena costruito
    printf("\nARRAY: \n");
    for(int k = 0; k < nValori; k++){
        printf("%.2f | ", *(v+k));
    }

    free(v);        //disalloco il vettore
    printf("\n");
    return 0;
}
