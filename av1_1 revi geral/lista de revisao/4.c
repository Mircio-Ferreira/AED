/*
QUESTÃO 04 - Considere que um programa em C manipula duas Filas (Fila01 e Fila02) e
agora é necessário que seja implementada uma nova função que verifique se existem
valores repetidos entre as filas, caso tenha valor repetido, deve ser removido apenas da
Fila2;.
Protótipo da função: void excluirIguais(Node *head1,Node *tail1, Node **head2,
Node **tail2);
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void removeDuplicate(Node *head1,Node **head2,Node **tail2);

void enqueue(Node **head,Node **tail,int n);

void printQueue(Node *head);

int main(){

    Node *head1=NULL, *tail1=NULL;
    Node *head2=NULL, *tail2=NULL;

    // Preenche Fila1
    enqueue(&head1, &tail1, 1);
    enqueue(&head1, &tail1, 2);
    enqueue(&head1, &tail1, 5);
    enqueue(&head1, &tail1, 7);
    enqueue(&head1, &tail1, 10);
    enqueue(&head1, &tail1, 1);
    enqueue(&head1, &tail1, 3);

    // Preenche Fila2
    enqueue(&head2, &tail2, 1);
    enqueue(&head2, &tail2, 1);
    enqueue(&head2, &tail2, 1);
    enqueue(&head2, &tail2, 2);
    enqueue(&head2, &tail2, 6);
    enqueue(&head2, &tail2, 2);
    enqueue(&head2, &tail2, 3);
    enqueue(&head2, &tail2, 5);
    enqueue(&head2, &tail2, 1);
    enqueue(&head2, &tail2, 6);
    enqueue(&head2, &tail2, 1);
    enqueue(&head2, &tail2, 7);
    enqueue(&head2, &tail2, 6);
    enqueue(&head2, &tail2, 7);
    enqueue(&head2, &tail2, 1);



    printf("Fila 1 (referência):\n");
    printQueue(head1);

    printf("Fila 2 (antes):\n");
    printQueue(head2);

    removeDuplicate(head1, &head2, &tail2);

    printf("Fila 2 (depois de remover iguais):\n");
    printQueue(head2);

    return 0;
}


void removeDuplicate(Node *head1,Node **head2,Node **tail2){
    if(*head2!=NULL){
        while(head1!=NULL){
            int check=head1->n;
            while(*head2!=NULL && (*head2)->n==check){
                Node *remove=*head2;
                *head2=(*head2)->next;
                free(remove);
                if(*head2==NULL){
                    *tail2=NULL;
                    return;
                }
            }
            Node *remove,*aux=*head2;
            while(aux->next!=NULL){
                if(aux->next->n==check){
                    remove=aux->next;
                    if(*tail2==remove) *tail2=aux;
                    aux->next=aux->next->next;
                    free(remove);
                    continue;
                }
                aux=aux->next;
            }
            head1=head1->next;
        }
    }
}

void enqueue(Node **head,Node **tail,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    new->next=NULL;
    if(*head==NULL) *head=*tail=new;
    else{
        (*tail)->next=new;
        *tail=new;
    }
}

void printQueue(Node *head){
    printf("Fila: ");
    while(head!=NULL){
        printf("|%d|",head->n);
        head=head->next;
    }
    printf("\n");
}