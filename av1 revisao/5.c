#include <stdio.h>
#include <stdlib.h>

/*
QUESTÃO 05 - Um determinado programa será implementado em C e deve permitir
manipular números em uma Fila. Crie uma nova função que imprima a divisão dos valores
de duplas de nós que estão nesta fila. Se tiver uma quantidade ímpar de nós (sobrando
um nó), para o nó restante, divida o valor dele por 10. E se a fila tiver menos que 2 nós,
exiba a seguinte mensagem: “Tamanho da fila é insuficiente :(” e também não pode ocorrer
divisão por zero.
Protótipo da função: void divisão(Node *head, Node *tail);
*/

typedef struct Node{
    float n;
    struct Node *next;
}Node;

void divsao(Node *head,Node *tail);

void enqueue(Node **head,Node **tail,float num);

int main(){
    Node *head=NULL,*tail=NULL;
    enqueue(&head,&tail,1);
    enqueue(&head,&tail,2);
    enqueue(&head,&tail,10);
    enqueue(&head,&tail,40);
    enqueue(&head,&tail,1);
    divsao(head,tail);

    return 0;
}

void divsao(Node *head,Node *tail){
    int cont=0;
    Node *aux=head;
    while(aux!=NULL){
        cont++;
        aux=aux->next;
    }
    if(cont<2) printf("Tamanho da fila insuficiente\n");
    else{
        float a,b;
        for(int i=0;i<cont;i++){
            if(i%2==0) a=head->n;
            else if(i%2!=0) {
                b=head->n;
                if(b==0) printf("Nao dividares por zero!\n");
                else printf("%f\n",(a/b));
            }
            head=head->next;
        }
        if(cont%2!=0) printf("ultimo no %f",tail->n/10);
    }
}

void enqueue(Node **head,Node **tail,float num){
    Node *new=malloc(sizeof(Node));
    new->n=num;
    new->next=NULL;

    if(*head==NULL){
        *head=*tail=new;
    }
    else{
        (*tail)->next=new;
        *tail=new;
    }
}