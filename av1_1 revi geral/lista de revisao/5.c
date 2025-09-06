/*
QUESTÃO 05 - Um determinado programa será implementado em C e deve permitir
manipular números em uma Fila. Crie uma nova função que imprima a divisao dos valores
de duplas de nós que estão nesta fila. Se tiver uma quantidade ímpar de nós (sobrando
um nó), para o nó restante, divida o valor dele por 10. E se a fila tiver menos que 2 nós,
exiba a seguinte mensagem: “Tamanho da fila é insuficiente :(” e também não pode ocorrer
divisao por zero.
Protótipo da função: void divisao(Node *head, Node *tail);
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void enqueue(Node **head,Node **tail,int n);

void printQueue(Node *head);

int lenQueue(Node *head);

void divisao(Node *head, Node *tail);

int main(){

    Node *head1=NULL, *tail1=NULL;
    Node *head2=NULL, *tail2=NULL;
    Node *head3=NULL, *tail3=NULL;

    // Caso 1: fila com 1 nó (deve mostrar msg de insuficiente)
    enqueue(&head1, &tail1, 5);
    printf("Fila 1:\n");
    printQueue(head1);
    divisao(head1, tail1);
    printf("\n");

    // Caso 2: fila com 2 nós (par)
    enqueue(&head2, &tail2, 20);
    enqueue(&head2, &tail2, 4);
    printf("Fila 2:\n");
    printQueue(head2);
    divisao(head2, tail2);
    printf("\n");

    // Caso 3: fila com 3 nós (ímpar)
    enqueue(&head3, &tail3, 30);
    enqueue(&head3, &tail3, 2);
    enqueue(&head3, &tail3, 0);
    enqueue(&head3, &tail3, 2);
    enqueue(&head3, &tail3, 100);
    enqueue(&head3, &tail3, 0);
    enqueue(&head3, &tail3, 20);
    printf("Fila 3:\n");
    printQueue(head3);
    divisao(head3, tail3);
    printf("\n");

    return 0;
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

int lenQueue(Node *head){
    int cont=0;
    while(head!=NULL){
        cont++;
        head=head->next;
    }
    return cont;
}

void divisao(Node *head, Node *tail){
    int len=lenQueue(head);
    if(len < 2) printf("Tamanho da fila é insuficiente :(\n");
    else{
        int par=len%2,a,b;
        for(int i=0;i<len;i++){
            if(i%2==0) a=head->n;
            else{
                b=head->n;
                if(b==0) printf("Nao dividiras por zero!\n");
                else{
                    printf("%d\n",a/b);
                }
            }
            head=head->next;
        }
        if(par) printf("last print div por 10: %d\n",a/10);
    }
}