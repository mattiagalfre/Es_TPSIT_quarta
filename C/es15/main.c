#include <stdio.h>
#include <stdlib.h>

/*Implementare
le pile dei metodi pop() e push() utilizzando una coda con i suoi metodi
enqueue() e dequeue().*/


typedef struct nodo
{
    int num;
    struct nodo * next;
} Nodo;

void enqueue(Nodo ** t, int num)
{
    Nodo*tail=*t;
    if(tail==NULL)
    {
        tail=(Nodo*)malloc(sizeof(Nodo));
        tail->num=num;
        tail->next=NULL;
    }
    else
    {
        Nodo * n=(Nodo*)malloc(sizeof(Nodo));
        n->next=tail;
        n->num=num;
        tail=n;
    }
    *t=tail;
}

int denqueue(Nodo ** head)
{
    int num=0;
    if(*head==NULL)
    {
        printf("Coda Vuota!!!\n");
    }
    else
    {
        Nodo* t= *head;
        num=t->num;
        *head=t->next;
    }
    return num;
}

Nodo * formattaLista()
{
    int n;
    printf("Quanti numeri vuole inserire: ");
    scanf("%d", &n);
    int num;
    Nodo * head=NULL;
    for(int k=0; k< n; k++)
    {
        printf("Dammi un numero: ");
        scanf("%d", &num);
        if(head==NULL){
            head=(Nodo*)malloc(sizeof(Nodo));
            head->num=num;
            head->next=NULL;
        }else{
        Nodo*next=head;
        head=(Nodo*)malloc(sizeof(Nodo));
        head->num=num;
        head->next=next;
        }
    }
    return head;
}


void stampaLista(Nodo*l)
{
    printf("%d ",l-> num);
    if(l->next!=NULL)stampaLista(l->next);

}

void main(){
Nodo* head=formattaLista();
enqueue(&head, 12);
enqueue(&head, 13);
denqueue(&head);
stampaLista(head);
}
