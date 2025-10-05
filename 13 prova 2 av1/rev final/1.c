#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
    struct Node *prev;
}Node;

void print(Node *head);
void printReverse(Node *head);

void insertPerValue(Node **head,int n,int posi);

void removePerValue(Node **head,int posi);

int main(){
    Node *head=NULL;

    insertPerValue(&head,10,1);
    insertPerValue(&head,20,2);
    insertPerValue(&head,30,3);
    insertPerValue(&head,40,4);
    insertPerValue(&head,50,5);

    print(head);
    printReverse(head);

    removePerValue(&head,-1);
    removePerValue(&head,1);

    removePerValue(&head,3);
    removePerValue(&head,5);


    print(head);
    printReverse(head);

}

void print(Node *head){
    while(head!=NULL){
        printf("|%d|",head->n);
        head=head->next;
    }
    printf("\n");
}
void printReverse(Node *head){

    while(head->next!=NULL) head=head->next;
    
    Node *aux=head; // aux=tail;

    while(aux!=NULL){
        printf("|%d|",aux->n);
        aux=aux->prev;
    }
    printf("\n");

}
// Posi incial =1
// se valor maior do que len de lista, insersao no final
void insertPerValue(Node **head,int n,int posi){
    if(posi<1){
        printf("ala valor menor do que 1\n");
        return;
    }
    Node *new=malloc(sizeof(Node));
    new->n=n;
    if(*head==NULL){
        *head=new;
        new->next=NULL;
        new->prev=NULL;
    }
    else if(posi==1){
        new->next=*head;
        new->prev=NULL;
        (*head)->prev=new;
        *head=new;
    }
    //Caos geral , meio ou fim
    else{
        Node *aux=*head;
        int cont=1;
        while(aux->next!=NULL && cont+1!=posi){
            aux=aux->next;
            cont++;
        }
        if(aux->next==NULL){ // Insersao no final
            new->next=NULL;
            new->prev=aux;
            aux->next=new;
        }
        else{ //caso do meio
            new->next=aux->next;
            new->prev=aux;
            aux->next->prev=new;
            aux->next=new;
        }
    }
}

void removePerValue(Node **head,int posi){
    if(posi < 0 || *head==NULL){
        printf("ala valor menor do que 1 ou lista vazia\n");
        return;
    }
    Node *remove;
    if((*head)->next==NULL){
        remove=*head;
        *head=NULL;
        free(remove);
    }
    else if(posi==1){
        remove=*head;
        *head=(*head)->next;
        (*head)->prev=NULL;
        free(remove);
    }
    else{ // caso geral
        Node *aux=*head;
        int cont=1;
        while(aux->next!=NULL && cont!=posi){
            aux=aux->next;
            cont++;
        }
        remove=aux;
        if(aux->next==NULL){ // remocao no final
            aux->prev->next=NULL;
        }
        else{
            aux->prev->next=aux->next;
            aux->next->prev=aux->prev;
        }
        free(remove);
    }
    
}
