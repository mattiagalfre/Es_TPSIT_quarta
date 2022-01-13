#include <stdio.h>
#include <stdlib.h>

/*Scrivere un programma che legga una sequenza di caratteri e li stampi in ordine inverso. Usa una
pila.*/

typedef struct nodo
{
    char car;
    struct nodo * next;
} Nodo;



Nodo* formattaLista(){
    int n;
    printf("Quanti caratteri vuoi inserire? ");
    scanf("%d", &n);
    Nodo* head;
    if(n > 0){
        head = (Nodo*)malloc(sizeof(Nodo));
    }else{
        head = NULL;
    }
    Nodo* r = head;
    Nodo* c;
    for(int k = 0; k< n; k++){
        printf("Inserisci il carattere %d: ", k+1);
        fflush(stdin);
        scanf("%c", &r->car);
        c = NULL;
        if(k < n-1){
            c = (Nodo*)malloc(sizeof(Nodo));
        }
        r->next = c;
        r = c;
    }
    return head;
}

void stampaLista(Nodo* l){
    if(l != NULL){
        printf("%c\n", l->car);
        stampaLista(l->next);
    }
    return;
}

void stampaListaInvertita(Nodo* l){
    if(l!=NULL){
        stampaListaInvertita(l->next);
        printf("%c\n", l->car);
    }
    return;
}

int main()
{
    Nodo * head = formattaLista();
    printf("Sequenza originale: \n");
    stampaLista(head);
    printf("Sequenza invertita: \n");
    stampaListaInvertita(head);
    return 0;
}
