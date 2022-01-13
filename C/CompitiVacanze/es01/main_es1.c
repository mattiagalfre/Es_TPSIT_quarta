#include <stdio.h>
#include <stdlib.h>

/*Considerate una sequenza di interi letti da input e definite una funzione C che li
stampa in modo tale che tutti i pari precedano i dispari, nello stesso ordine in cui vengono
letti.
Ad esempio, se la sequenza è:
1 , 20 , 35 , 40 , 62 , 51 , 66
La stampa che si vuole ottenere è;
20 , 40 , 62 , 66 , 1 , 35 , 51*/

typedef struct nodo{
    int val;
    struct nodo* next;
}Nodo;

Nodo* formattaLista(){
    int n;
    printf("Quanti numeri vuoi inserire? ");
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
        printf("Inserisci il valore %d: ", k+1);
        scanf("%d", &r->val);
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
        printf("%d\n", l->val);
        stampaLista(l->next);
    }
}

void stampaListaOrdinata(Nodo* l){
    Nodo* head = l;
    while(l != NULL)
    {
        if(l->val % 2 ==0){
            printf("%d\n", l->val);
        }
        l = l-> next;
    }
    l = head;
    while(l != NULL){
        if(l->val % 2 !=0){
            printf("%d\n", l->val);
        }
        l = l->next;
    }
}

int main()
{
    Nodo* head = formattaLista();
    printf("Stampa Normale: \n");
    stampaLista(head);
    printf("Stampa modificata: \n");
    stampaListaOrdinata(head);
    return 0;
}
