#include <stdio.h>
#include <stdlib.h>

/*
Sia data una struttura dati dinamica di tipo lista semplicemente concatenata.
Ogni nodo della lista contiene un numero intero come valore.  Si scriva la funzione che, dato un vettore di
N numeri interi, restituisce la lista contenente gli N elementi del vettore;
l’elemento di indice 0 va in testa alla lista, ecc.
*/

typedef struct nodo{
    int val;
    struct nodo *next;
}Nodo;


Nodo *createNode(int val, Nodo *nodo){
    Nodo *succ = (Nodo*)malloc(sizeof(Nodo));

    if(nodo!= NULL){
        nodo->next = succ;
    }
    succ->val = val;
    succ->next = NULL;
    return succ;
}


int main()
{
    Nodo *head = NULL;
    int *vet;
    int n;

    printf("Inserisci il numero di elementi: ");
    scanf("%d", &n);

    vet = (int*)malloc(n * sizeof(int));

    for(int k = 0; k < n; k++){
        printf("Inserisci l'elemento [%d] del vettore: ", k);
        scanf("%d", vet+k);
    }

    printf("\nVETTORE VALORI: \n\n");
    for(int k = 0; k < n; k++){
        printf("%d | ", *(vet+k));
    }
    printf("\n");

    Nodo *curr = NULL;

    for(int i = 0; i < n; i ++){
        curr = createNode(*(vet+i), curr);
        if(head == NULL){
            head = curr;
        }
    }
    printf("\nLISTA: \n\n");

    curr = head;
    while(curr != NULL){
        printf("%d | ", curr->val);
        curr = curr->next;
    }

    printf("\n");
    return 0;
}
