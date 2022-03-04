#include <stdio.h>
#include <stdlib.h>

/*Scrivere una
funzione che inverta una coda, ovvero
produca degli elementi  della coda
di partenza. Suggerimento: utilizzare una pila
*/

typedef struct nodo {
    int num;
    struct nodo * next;
} Nodo;

Nodo * formattaLista(Nodo** tail) {
    int n;
    printf("Quanti numeri vuole inserire: ");
    scanf("%d", &n);
    int num;
    Nodo * head=NULL;
    Nodo *r = (Nodo*)malloc(sizeof(Nodo));
    Nodo * cur=head;
    for(int k=0; k< n; k++) {
        printf("Dammi un numero: ");
        scanf("%d", &num);
        if(r==NULL)r=(Nodo*)malloc(sizeof(Nodo));
        r->num=num;
        if(head==NULL) {
            head= r;
            cur=r;
        }
        cur->next=r;
        cur=r;
        cur->next=NULL;
        r=NULL;
    }
    *tail=cur;
    return head;
}

void enqueue(Nodo ** t, int num) {
    Nodo*tail=*t;
    if(tail==NULL) {
        tail=(Nodo*)malloc(sizeof(Nodo));
        tail->num=num;
        tail->next=NULL;
    } else {
        tail->next=(Nodo*)malloc(sizeof(Nodo));
        tail=tail->next;
        tail->num=num;
        tail->next=NULL;
    }
    *t=tail;
}

int denqueue(Nodo ** head) {
    int num=0;
    if(*head==NULL) {
        printf("Coda Vuota!!!\n");
    } else {
        Nodo* t= *head;
        num=t->num;
        *head=t->next;
    }
    return num;
}

void stampaLista(Nodo*l) {
    if(l->next!=NULL)stampaLista(l->next);
    printf("%d ",l-> num);
}

Nodo* push(Nodo * l, int c) {
    Nodo * n= (Nodo*)malloc(sizeof(Nodo));
    n->num=c;
    n->next=NULL;
    if(l!=NULL) {
        n->next=l;
    }
    return n;
}

int pop(Nodo ** l) {
    Nodo * n= (Nodo*)malloc(sizeof(Nodo));
    n=*l;
    int num=0;
    if(*l==NULL) {
        printf("Non ci sono nodi nella lista!!\n");
    } else {
        num=n->num;
        n=n->next;
        *l=n;
    }
    return num;
}

Nodo* invertiCoda(Nodo ** head) {
    Nodo * pila=NULL;
    Nodo*t=*head;
    while(t!=NULL) {
        pila=push(pila,denqueue(&t));
    }
    while(pila!=NULL) {
        if(t==NULL) {
            enqueue(&t,pop(&pila));
            *head=t;
        }
        enqueue(&t,pop(&pila));
    }
    return t;

}

int main() {
    Nodo* tail=NULL;
    Nodo * head=formattaLista(&tail);
    printf("\nCoda iniziale: ");
    stampaLista(head);
    printf("\nCoda invertita: ");
    tail = invertiCoda(&head);
    stampaLista(head);
    denqueue(&head);
    printf("\n");
}
