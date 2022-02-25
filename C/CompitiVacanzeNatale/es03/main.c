#include <stdio.h>
#include <stdlib.h>
#define DIM 30

/*Per descrivere i pazienti di una clinica disponi del seguente tipo di dato:
Paziente
typedef struct{
    char nome[256] ;
    char cognome[256] ;
    int matricola;
    int pressione[2]; // minima e massima
    int temperature[3]; // temperature della mattina e pomeriggio e sera
    float parcella; // in euro quello che deve al dottore
} Paziente; // Iniziale maiuscola

Scrivi i Prototipi,le chiamate e il codice delle seguenti specifiche:
    1. definisci una variabile rossi di tipo paziente;
    2. definisci un array di 20 pazienti di nome clinica e di tipo paziente;
    3. imposta una procedura (prototipo) con il corretto passaggio dei parametri che permetta ad
    un utente di inserire tutti dati di un paziente che è stato passato alla procedura;
    4. imposta una procedura (prototipo) che stampa la pressione e la temperatura di un
    paziente;
    5. imposta una procedura (prototipo) che dato l&#39;indirizzo dell&#39;array clinica ed il numero di
    pazienti che vi sono sulla lista, calcola il saldo totale della clinica;
    6. imposta tutte le chiamate nel main che realizzino in sequenza i punti precedenti;
    7. facoltativo: ora completa l&#39;esercizio scrivendo il codice di tutte le procedure.*/


typedef struct{
    char nome[256];
    char cognome[256] ;
    int matricola;
    int pressione[2];
    int temperature[3];
    float parcella;
} Paziente;

void aggiungiPaziente(Paziente v[], int k){

    if(k < DIM){
        printf("Inserisci il nome del paziente: ");
        scanf("%s", v[k].nome);
        printf("Inserisci il cognome del paziente: ");
        scanf("%s", v[k].cognome);
        printf("Inserisci la matricola del paziente: ");
        scanf("%d", &v[k].matricola);
        printf("Inserisci la prima pressione: ");
        scanf("%d", &v[k].pressione[0]);
        printf("Inserisci la seconda pressione: ");
        scanf("%d", &v[k].pressione[1]);
        printf("Inserisci la prima temperatura: ");
        scanf("%d", &v[k].temperature[0]);
        printf("Inserisci la seconda temperatura: ");
        scanf("%d", &v[k].temperature[1]);
        printf("Inserisci la terza temperatura: ");
        scanf("%d", &v[k].temperature[2]);
        printf("Inserisci la parcella del paziente: ");
        scanf("%f", &v[k].parcella);
    }else{
        printf("La clinica è al completo\n");
    }
}

void stampaDati(Paziente p){
    printf("\nPRESSIONI: \n");
    for(int k = 0; k < 2; k++){
        printf("%d) %d \n", k, p.pressione[k]);
    }
    printf("\nTEMPERATURE: \n");
    for(int k = 0; k < 3; k++){
        printf("%d) %d \n", k, p.temperature[k]);
    }
    return;
}

float getSomma(Paziente v[], int nPazienti){
    float som = 0;

    for(int k=0; k < nPazienti; k++){
        som += v[k].parcella;
    }
    return som;
}

int main()
{
    Paziente Rossi;
    Paziente clinica1[DIM];
    int numPazienti = 0, nPaziente;

    char risp = 's';
    while(risp == 's'){
        aggiungiPaziente(clinica1, numPazienti);
        numPazienti++;
        printf("Vuoi aggiungere altri pazienti? ('s' per continuare) \n");
        fflush(stdin);
        scanf("%c", &risp);
    }

    do{
        printf("Di quale paziente si vuole conoscere lo stato? \n");
        scanf("%d", &nPaziente);
    }while(nPaziente < 0 || nPaziente > numPazienti);

    stampaDati(clinica1[nPaziente]);

    printf("Il saldo totale della clinica vale: %.2f", getSomma(clinica1, numPazienti));

    return 0;
}
