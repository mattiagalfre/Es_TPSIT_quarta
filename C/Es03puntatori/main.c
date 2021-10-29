#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM  30
#define MAX  50


typedef struct {
    int numero;
    char titoloFilm[MAX];
    char genere[MAX];
    int anno;
    char dispo[MAX];
} Libreria;

void caricaVettore(Libreria v[], int n, char nomeFile[]) {
    FILE *fp;
    int i = 0;
    char line[100];
    char *pezzo;

    fp = fopen(nomeFile, "r");

    while(fgets(line, 100, fp)){
        pezzo = strtok(line, ",");
        (v + i)->numero = atoi(pezzo);

        pezzo = strtok(NULL, ",");
        strcpy((v + i)->titoloFilm, pezzo);

        pezzo = strtok(NULL, ",");
        strcpy((v + i)->genere, pezzo);

        pezzo = strtok(NULL, ",");
        (v + i)->anno = atoi(pezzo);

        pezzo = strtok(NULL, ",");
        strcpy((v + i)->dispo, pezzo);
        i++;
    }
    fclose(fp);

}

void stampaVettore(Libreria v[], int n){
    for(int k=0;k<n;k++){
        printf("%5d %40s %15s %5d %15s", (v + k)->numero, (v + k)->titoloFilm, (v + k)->genere, (v + k)->anno, (v + k)->dispo);
        printf("\n");
    }
}

int contaRighe(char nFile[]){
    char line[100];
    FILE *fp;
    int n = 0;

    fp = fopen(nFile, "r");

    while(fscanf(fp, "%s", line) != EOF){
        n++;
    }
    return n;
}

int main() {

    int n;

    Libreria *film;
    n = contaRighe("lista.txt");
    film = (Libreria*) malloc(n * sizeof(Libreria));

    caricaVettore(film, DIM, "lista.txt");
    stampaVettore(film, DIM);

    free(film);
    return 0;
}
