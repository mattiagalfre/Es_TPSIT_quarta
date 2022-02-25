#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_queue_node {
    int elemento;
    struct s_queue_node *next;

} Queue_node;

int is_empty(Wueue_node *head);
void enqueue(Queue_node *head, Queue_node * tail, Queue_node *element);
Queue_node *dequeue(Queue_node **head, Queue_node **tail);

int main() {

    Queue_node *head = NULL;
    Queue_node *tail = NULL;
    Queue_node *struct_return = NULL;
    Queue_node *element;
    bool condizione = true;
    int scelta,dato;

    while(condizione) {
        int scelta;

        printf("MENU\n\n -scegli '1' per inserire elementi nella coda\n scegli '2' per svuotare la coda\n scegli '3' per uscire dal programma\n Inserire numero: ");
        scanf("%d",&scelta);

        switch(scelta) {
            case 1:
                printf("inserisci un elemento: ");
                scanf("%d",&dato);
                element = (Queue_node*)malloc(sizeof(Queue_node));
                element->elemento = dato;
                enqueue(&head, &tail, element);
                break;
            case 2:
                printf("Gli elementi inseriti fino ad ora sono: /t");
                while((struct_return = dequeue(&head, &tail)) != NULL){
                    printf("%d\t", struct_return->elemento);
                    free(struct_return);
                }
                break;
            case 3:
                printf("EXIT..");
                condizione = false;

                break;
            default:
                printf("Carattere inserito non valido \n");
                break;
        }

    }
    return 0;
}

int is_empty(Queue_node* head){
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(Queue_node *head, Queue_node **tail, Queue_node *element){
    if(is_empty(*head)){
        *head = element;
    }else{
        *tail->next = element;
    }
}

