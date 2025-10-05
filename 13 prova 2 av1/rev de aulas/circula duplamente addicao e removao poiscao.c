#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
    struct Node *prev;
}Node;

void print(Node *head);
void printReverse(Node *tail);

void insertPosi(Node **head,Node **tail,int n,int posi);

void removePosi(Node **head,Node **tail,int posi);

int main(){
    Node *head=NULL,*tail=NULL;

    insertPosi(&head,&tail,0,1);
    insertPosi(&head,&tail,2,2);
    insertPosi(&head,&tail,4,3);
    insertPosi(&head,&tail,5,4);
    insertPosi(&head,&tail,3,3);
    insertPosi(&head,&tail,1,2);
    insertPosi(&head,&tail,-1,1);
    print(head);
    printReverse(tail);

    removePosi(&head, &tail, 1);   // remove do início (-1)
    removePosi(&head, &tail, 3);   // remove o 3º elemento (2)
    removePosi(&head, &tail, 10);  // posição inexistente → remove do final (5)
    removePosi(&head, &tail, 2);   // remove o 2º elemento (1)
    removePosi(&head, &tail, 1);   // remove o primeiro (0)

    printf("\n\n");

    print(head);
    printReverse(tail);

}

void print(Node *head){
    if(head!=NULL){
        Node *aux=head;
        do{
            printf("|%d|",aux->n);
            aux=aux->next;
        }while(aux!=head);
        printf("\n");
    }
}
void printReverse(Node *tail){
    if(tail!=NULL){
        Node *aux=tail;
        do{
            printf("|%d|",aux->n);
            aux=aux->prev;
        }while(aux!=tail);
        printf("\n");
    }
}

void insertPosi(Node **head,Node **tail,int n,int posi){
    if(posi < 1) {
        printf("posi elada!\n");
        return;
    }
    Node *new=malloc(sizeof(Node));
    if(new==NULL) return;
    new->n=n;
    if(*head==NULL){
        *head=*tail=new;
        new->next=new->prev=new;
    }
    else if(posi==1){
        new->next=*head;
        new->prev=*tail;
        (*head)->prev=new;
        *head=new;
        (*tail)->next=*head;
    }
    else{//caso geral
        Node *aux=*head;
        int cont=1;
        while(aux->next!=*head && cont+1!=posi){
            aux=aux->next;
            cont++;
        }
        if(aux->next==*head){ // insersao de tail
            (*tail)->next=new;
            new->next=*head;
            new->prev=*tail;
            *tail=new;
            (*head)->prev=*tail;
        }
        else{//insersao de meio
            new->prev=aux;
            new->next=aux->next;
            aux->next->prev=new;
            aux->next=new;
        }
    }
}

void removePosi(Node **head,Node **tail,int posi){
    if(*head==NULL || posi < 1){
        printf("lista vazia ou posi errada\n");
        return;
    }
    Node *remove;
    if(*head==*tail){
        remove=*head;
        *head=*tail=NULL;
    }
    else if(posi==1){
        remove=*head;
        *head=(*head)->next;
        (*head)->prev=*tail;
        (*tail)->next=*head;
    }
    else{
        Node *aux=*head;
        int cont=1;
        while(aux->next!=*head && cont!=posi){
            aux=aux->next;
            cont++;
        }
        if(*tail==aux){ //remocao na tail
            remove=*tail;
            *tail=(*tail)->prev;
            (*tail)->next=*head;
            (*head)->prev=*tail;
        }
        else{// remocao de meio
            remove=aux;
            aux->next->prev=aux->prev;
            aux->prev->next=aux->next;
        }
    }

    free(remove);

}