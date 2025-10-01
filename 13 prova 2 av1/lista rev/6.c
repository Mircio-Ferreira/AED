#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    int n;
    struct Node *next;
    struct Node *prev;
}Node;

void sequencia(Node *head, Node *tail);

int len(Node *head,Node *tail);

void print(Node *head);

void insert(Node **head,Node **tail,int n);

int main(){
    Node *head=NULL,*tail=NULL;
    srand(time(NULL));

    for(int i=0;i<10;i++) insert(&head,&tail,rand()%100);
    print(head);
    sequencia(head,tail);
}

int len(Node *head,Node *tail){
    int cont=0;
    if(head!=NULL){
        Node *aux=head;
        do{
            cont++;
            aux=aux->next;
        }while(aux!=head);
    }
    return cont;
}

// void sequencia(Node *head, Node *tail){
//     int cont=len(head,tail);
//     if(cont<4) printf("Tamanho da lista é insuficiente :(");
//     else{
//         Node *aux=head;
//         int cont=0;
//         printf("Numeros que sao de sequencia de impar: ");
//         do{
//             if(aux->n%2!=0) cont++;
//             else cont=0;
//             if(cont==2){
//                 cont=1;
//                 printf("|%d|",aux->next->n);
//             }
//             aux=aux->next;
//         }while(aux!=head);
//         if(tail->n%2!=0 && head->n%2!=0) printf("|%d|",head->next->n);
//         printf("\n");
//     }
// }

void sequencia(Node *head, Node *tail){
    int cont=len(head,tail);
    if(cont<4) printf("Tamanho da lista é insuficiente :(");
    else{
        Node *aux=head;
        printf("Numeros que sao de sequencia de impar: ");
        do{
            if(aux->prev->n%2!=0 && aux->prev->prev->n%2!=0) printf("|%d|",aux->n);
            aux=aux->next;
        }while(aux!=head);
        printf("\n");
    }
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

void insert(Node **head,Node **tail,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    if(*head==NULL) {
        *head=*tail=new;
        new->next=new->prev=new;
    }
    else{
        (*tail)->next=new;
        new->prev=*tail;
        *tail=new;
        (*tail)->next=*head;
        (*head)->prev=new;
    }
}