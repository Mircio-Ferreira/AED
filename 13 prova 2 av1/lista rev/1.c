#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    int n;
    struct Node *next;
    struct Node *prev;
}Node;

//Lista Duplamente encadeada

void insertBeginingNotTail(Node **head,int n);
void inserteEndNotTail(Node **head,int n);

void removeBeginingNotTail(Node **head);
void removeEndNotTail(Node **head);

void print(Node *head);
void printReverse(Node *head);

void insertSort(Node **head,int n);
void removePerValor(Node **head,int n);

int main(){
    srand(time(NULL));
    Node *head=NULL;

    for(int i=0;i<10;i++){
        int n=rand()%10;
        printf("Sorteado|%d|\n",n);
        insertSort(&head,n);
        printf("lista: ");
        print(head);

    }
    printf("\n");

    //print(head);
    //printReverse(head);

    //removeEndNotTail(&head);
    //removeEndNotTail(&head);

    //print(head);
    //printReverse(head);

    //removeBeginingNotTail(&head);
    
    //print(head);
    //printReverse(head);

    removePerValor(&head,0);
    print(head);
    removePerValor(&head,1);
    print(head);
    removePerValor(&head,2);
    print(head);
    removePerValor(&head,3);
    print(head);
    removePerValor(&head,4);
    print(head);


    return 0;
}

void insertBeginingNotTail(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    if(new==NULL) return;
    new->n=n;
    new->prev=NULL;
    new->next=*head;
    if(*head!=NULL) (*head)->prev=new;
    *head=new;
}
void inserteEndNotTail(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    if(new==NULL) return;
    new->n=n;
    new->next=NULL;
    if(*head==NULL){
        *head=new;
        new->prev=NULL;
    }
    else{
        Node *aux=*head;
        while(aux->next!=NULL) aux=aux->next;
        aux->next=new;
        new->prev=aux;
    }
    
}

void print(Node *head){
    while(head!=NULL){
        printf("|%d|",head->n);
        head=head->next;
    }
    printf("\n");
}
void printReverse(Node *head){
    if(head!=NULL){
        while(head->next!=NULL) head=head->next;
        while(head!=NULL){
            printf("|%d|",head->n);
            head=head->prev;
        }
        printf("\n");
    }
}


void removeBeginingNotTail(Node **head){
    if(*head!=NULL){
        Node *remove=*head;
        *head=(*head)->next;
        if(*head!=NULL) (*head)->prev=NULL;
        free(remove);
    }
}
//Gambiarra
// void removeEndNotTail(Node **head){
//     if(*head!=NULL){
//         if((*head)->next==NULL){
//             Node *remove=*head;
//             *head=NULL;
//             free(remove);
//         }
//         else{
//             Node *aux=*head;
//             while(aux->next!=NULL) aux=aux->next;
//             Node *remove=aux;
//             aux->prev->next=NULL;
//             free(remove);
//         }
//     }
// }
void removeEndNotTail(Node **head){
    if(*head!=NULL){
        Node *aux=*head;
        while(aux->next!=NULL) aux=aux->next;
        Node *remove=aux;
        if(*head==aux) *head=NULL;
        else aux->prev->next=NULL;
        free(remove); 
    }
}

void insertSort(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    if(*head==NULL){
        new->next=new->prev=NULL;
        *head=new;
    }
    else if(n < (*head)->n){
        new->next=*head;
        new->prev=NULL;
        (*head)->prev=new;
        *head=new;
    }
    else{ // caso generico de insercao no final ou meio
        Node *aux=*head;
        while(aux->next!=NULL && aux->next->n < n) aux=aux->next;
        if(aux->next==NULL){// insersano no final
            new->prev=aux;
            aux->next=new;
            new->next=NULL;
        }
        else{
            new->next=aux->next;
            new->prev=aux;
            aux->next->prev=new;
            aux->next=new;
        }
    } 
}

void removePerValor(Node **head,int n){
    if(*head!=NULL){
        Node *remove;
        if((*head)->n==n){
            remove=*head;
            *head=(*head)->next;
            if(*head!=NULL) (*head)->prev=NULL;
            free(remove);
        }
        else{
            Node *aux=*head;
            while(aux!=NULL && aux->n!=n) aux=aux->next;
            if(aux==NULL) printf("Valor nao encontrado!\n");
            else{
                remove=aux;
                if(aux->next==NULL) aux->prev->next=NULL;
                else{
                    aux->prev->next=aux->next;
                    aux->next->prev=aux->prev;   
                }
                free(remove);
            }
        }
    }
}