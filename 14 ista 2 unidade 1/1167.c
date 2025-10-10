#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int key;
    char nome[50];
    struct Node *next;
    struct Node *prev;
}Node;

void insertEnd(Node **head,Node **tail,int key,char *nome);
void removeNode(Node **head,Node **tail,Node *deleteNode);
void search(Node **head,Node **tail);

int main(){
    int qtdCriancas,key;
    char nome[50];
    while(1){
        Node *head=NULL,*tail=NULL;
        scanf("%d",&qtdCriancas);
        if(qtdCriancas==0) break;

        for(int i=0;i<qtdCriancas;i++){
            scanf("%s %d",nome,&key);
            insertEnd(&head,&tail,key,nome);
        }
        search(&head,&tail);
    }

    return 0;
}

void insertEnd(Node **head,Node **tail,int key,char *nome){
    Node *new=malloc(sizeof(Node));
    new->key=key;
    strcpy(new->nome,nome);

    if(*head==NULL) *head=*tail=new->next=new->prev=new;
    else{
        (*tail)->next=new;
        new->prev=*tail;
        new->next=*head;
        *tail=new;
        (*head)->prev=*tail;
    }

}


void removeNode(Node **head,Node **tail,Node *deleteNode){
    if(*head!=NULL){
        Node *removeNode=deleteNode;
        if(deleteNode->next==deleteNode) *head=*tail=NULL;
        else{
            if(*head==deleteNode){
                *head=(*head)->next;
                (*head)->prev=*tail;
                (*tail)->next=*head;
            }
            else if(*tail==deleteNode){
                *tail=(*tail)->prev;
                (*tail)->next=*head;
                (*head)->prev=*tail;
            }
            else{
            deleteNode->prev->next = deleteNode->next;
            deleteNode->next->prev = deleteNode->prev;
            }
        }
        free(removeNode);
    }
}

void search(Node **head,Node **tail){
    int keyInit=(*head)->key;
    Node *delete=*head;

    while(*head!=*tail){
        //if(keyInit%2==0) for(int i=0;i<keyInit;i++) delete=delete->next; //hahaha isso da certo
        
        //else for(int i=0;i<keyInit;i++) delete=delete->prev;

        if(keyInit%2==0) for(int i=0;i<keyInit;i++) delete=delete->prev; //hahaha isso da certo

        else for(int i=0;i<keyInit;i++) delete=delete->next;

        keyInit=delete->key;

        Node *temp=delete->next; //suponho que é par
        if(keyInit%2!=0) temp=delete->prev; //caso impar

        removeNode(head,tail,delete);
        delete=temp;
    }

    printf("Vencedor(a): %s\n",(*head)->nome);
    free(*head);
    *head=*tail=NULL;
}
