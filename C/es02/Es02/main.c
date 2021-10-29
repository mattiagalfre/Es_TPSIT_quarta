#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR  20
#define N_STUD  5

/*
Definire una struttura per memorizzare i dati degli
studenti di una classe e dei voti nelle varie discipline:
Italiano, Matematica e Informatica.
Si scriva una funzione in C che, a partire da un vettore di studenti fornito come argomento,
determini la disciplina che ha la media più alta.
*/

typedef struct{
    int matricola;
    char nome[MAX_CHAR];
    char cognome[MAX_CHAR];
    float italiano;
    float matematica;
    float informatica;
}Studente;

int main()
{
    Studente classe[N_STUD];
    int k;

    for(k = 0; k < N_STUD; k++){
        printf("Inserisci i dati dello studente [%d]", k+1);
        printf("\nNome: ");
        scanf("%s", classe[k].nome);
        fflush(stdin);
        printf("\nCognome: ");
        scanf("%s", classe[k].cognome);
        fflush(stdin);
        printf("\nMatricola: ");
        scanf("%d", &classe[k].matricola);
        fflush(stdin);
        printf("\nVoto Italiano: ");
        scanf("%f", &classe[k].italiano);
        fflush(stdin);
        printf("\nVoto Matematica: ");
        scanf("%f", &classe[k].matematica);
        fflush(stdin);
        printf("\nVoto Informatica: ");
        scanf("%f", &classe[k].informatica);
        fflush(stdin);
        printf("\n");
    }
    printf("\n\nDati acquisiti.\n\n");

    float mediaIta;
    float mediaMate;
    float mediaInfo;
    float somma = 0;

    for(k = 0; k < N_STUD; k++){
        somma = somma + classe[k].italiano;
    }
    mediaIta = somma / N_STUD;
    somma = 0;

    for(k = 0; k < N_STUD; k++){
        somma = somma + classe[k].matematica;
    }
    mediaMate = somma / N_STUD;
    somma = 0;

    for(k = 0; k < N_STUD; k++){
        somma = somma + classe[k].informatica;
    }
    mediaInfo = somma / N_STUD;

    if(mediaIta > mediaMate && mediaIta > mediaInfo){
        printf("Italiano e' la disciplina con la media piu' alta \n");
    }

    if(mediaMate > mediaIta && mediaMate > mediaInfo){
        printf("Matematica e' la disciplina con la media piu' alta \n");
    }

    if(mediaInfo > mediaMate && mediaInfo > mediaIta){
        printf("Informatica e' la disciplina con la media piu' alta \n");
    }

    printf("\n");
    system("PAUSE");
    return 0;
}
