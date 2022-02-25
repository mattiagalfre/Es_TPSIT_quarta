#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR  20
#define N_STUD  2

/*
Inserimento ordinato

Si scriva un programma che:

-definisca un tipo di dato Studente.Ogni studente è caratterizzato da un nome, cognome, matricola.

-acquisisca i dati di 10 studenti e, per ogni nuovo studente inserito, proceda ad un inserimento ordinato (lo scopo dell'esercizio è
ordinare gli studenti durante il processo di inserimento degli stessi e non dopo averli inseriti tutti con un algoritmo di ordinamento):

-stampi i dati degli student.

*/

typedef struct{
    int matricola;
    char nome[MAX_CHAR];
    char cognome[MAX_CHAR];
}Studente;

int main()
{
    Studente classe[N_STUD];
    int k;

    for(k = 0; k < N_STUD; k++){
        printf("Inserisci i dati dello studente [%d]", k+1);
        printf("\nNome: ");
        //gets(classe[k].nome);
        scanf("%s", classe[k].nome);
        fflush(stdin);
        printf("\nCognome: ");
        //gets(classe[k].cognome);
        scanf("%s", classe[k].nome);
        fflush(stdin);
        printf("\nMatricola: ");
        scanf("%d", &classe[k].matricola);
        printf("\n");
    }
    printf("\n\nDati acquisiti.");

    for(k = 0; k < N_STUD; k++){
        printf("Studente [%d]", k+1);
        printf("\nNOME: %s", classe[k].nome);
        printf("\nCOGNOME: %s", classe[k].cognome);
        printf("\nMATRICOLA: %d", classe[k].matricola);
        printf("\n\n");
    }


    printf("\n");
    system("PAUSE");
    return 0;
}
