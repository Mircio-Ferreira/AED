#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
    struct Node *prev;
}Node;

void sequencia(Node *head, Node *tail);

int len(Node *head,Node *tail);

int main(){
    Node *head=NULL,*tail=NULL;
    
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

void sequencia(Node *head, Node *tail){
    int cont=len(head,tail);
    if(cont<4) printf("Tamanho da lista é insuficiente :(");
    else{
        
    }
}