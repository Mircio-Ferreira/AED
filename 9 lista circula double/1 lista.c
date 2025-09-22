#include <stdio.h>
#include <stdlib.h>
/*
01 - Crie uma função que realize a INSERÇÃO de nós em uma Lista Circular Duplamente Encadeada em uma determinada posição.

Considere:

               Que a posição inicia em 1;

               Se não houver a posição na lista, o nó deve ser inserido no final.

               Também trate demais erros que possam ocorrer.
*/

typedef struct Node{
    int n;
    struct Node *next;
    struct Node *prev;
}Node;

void insertPosition(Node **head,Node **tail,int posi,int n);

int len(Node *head,Node *tail);

void print(Node *head,Node *tail);


int main(){

    Node *head=NULL,*tail=NULL;

    insertPosition(&head,&tail,0,-1);   // NÃO insere (posição inválida < 1)

    insertPosition(&head,&tail,1,10);   // insere 10 na posição 1 -> lista: 10

    insertPosition(&head,&tail,2,11);   // insere 11 na posição 2 -> lista: 10 11

    insertPosition(&head,&tail,3,3);    // insere 3 na posição 3 -> lista: 10 11 3

    insertPosition(&head,&tail,2,2);    // insere 2 na posição 2 -> lista: 10 2 11 3

    insertPosition(&head,&tail,2,-100); // insere -100 na posição 2 -> lista: 10 -100 2 11 3

    print(head,tail);
    
    return 0;
}

void insertPosition(Node **head,Node **tail,int posi,int n){
    if(posi<1){
        printf("So e valido indicies maiores que 0\n");
        return;
    }
    Node *new=malloc(sizeof(Node));
    new->n=n;
    //insersao de lista vazia em caso que o usuario digite 1 para cima (como se fosse insersao no comeco)
    if(*head==NULL){
        *head=*tail=new;
        new->next=new->prev=new;
    }
    else{
        int tam=len(*head,*tail);
        //insersao no comeco
        if(posi==1){
            new->next=*head;
            new->prev=*tail;
            (*tail)->next=new;
            (*head)->prev=new;
            *head=new;
        }
        // insersao no fim
        else if(posi>tam){
            new->prev=*tail;
            new->next=*head;
            (*head)->prev=new;
            (*tail)->next=new;
            *tail=new;
        }
        //Insersao de meio
        else{
            Node *aux=*head;
            int cont=1;
            //Paro um antes da posicao
            while(cont+1!=posi){
                cont++;
                aux=aux->next;
            }
            new->next=aux->next;
            new->prev=aux;

            aux->next->prev=new;

            aux->next=new;
        }
        
    }

}

int len(Node *head,Node *tail){
    int cont=0;
    if(head!=NULL){
        Node *aux=head;
        do{
            cont++;
            aux=aux->next;
        } while(aux!=head);
    }
    return cont;
}

void print(Node *head,Node *tail){
    if(head!=NULL){
        Node *aux=head;
        do{
            printf("|%d|",aux->n);
            aux=aux->next;
        }while(aux!=head);
        printf("\n");
    }
}