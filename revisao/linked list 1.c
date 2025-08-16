#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    struct Node *next;
}Node;

void insertAtBegginer (int num,Node **head);

void printList(Node *head);

void insertAtEnd (int num, Node **head);

void remover(int num, Node **head);

int main(){

    Node *head=NULL;
    int entrada;
    
    for(int i=0;i<5;i++){
        scanf(" %d",&entrada);
        //insertAtBegginer(entrada,&head);
        insertAtEnd(entrada,&head);
    }
    //remover(1,&head);
    printList(head);

    

    return 0;
}

void insertAtBegginer (int input ,Node **head){
    Node *new=malloc(sizeof(Node));
    new->num=input;
    new->next=*head;
    *head = new;
}

void printList(Node *head){
    if(head==NULL){
        printf("Lista Vazia");
        return;
    }
    while(head!=NULL){
        printf("Number: %d\n",head->num);
        head=head->next;
    }
}

void insertAtEnd (int num, Node **head){
    Node *new= malloc(sizeof(Node));
    new->num=num;
    new->next=NULL;

    if(*head==NULL) *head=new;

    else{
        Node *aux=*head;
        while(aux->next!=NULL){
            aux=aux->next;
        }
        aux->next=new;
    }

}

void remover(int num, Node **head){

    if(*head==NULL) {
        printf("Não ha o que remover, lista vazia\n");
        return;
    }
    // Remocao no começo
    if( (*head)->num == num){
        (*head)=(*head)->next;
        return;
    }
    //remocao no meio ou no final
    else{
        Node *aux=*head;
        Node *delete;
        while(aux->next!=NULL){
            if(aux->next->num == num){
                delete=aux->next;
                aux->next=aux->next->next;
                free(delete);
                return;
            }
            aux=aux->next;
        }
    }
}
