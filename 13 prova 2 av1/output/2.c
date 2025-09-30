#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
    struct Node *prev;
}Node;

void excluirIntervalo(Node **head, Node **tail, int delimitador01, int delimitador02){
    if(*head==NULL || (*head)->next==NULL || (*head)->next->next==NULL){
        printf("Tamanho da lista insuficiente\n");
        return;
    }
    int flag1=0,flag2=0;
    Node *aux=*head,*no1,*no2;
    while(aux!=NULL){
        if(flag1==0 && aux->n==delimitador01){
            no1=aux;
            flag1=1;
        }
        else if(flag1!=0 && aux->n==delimitador02 && no1->next!=aux){
            flag2=1;
            no2=aux;
        }
        aux=aux->next;
    }
    if(flag1!=1 || flag2!=1){
        printf("nao existe numero delimitador ou nao existe numero entre os delimitadores\n");
        return;
    }
    aux=no1->next;
    no1->next=no2;
    no2->prev=no1;
    while(1){
        Node *remove=aux;
        aux=aux->next;
        free(remove);
        if(aux==no2) break;
    }

}

void inserirFim(Node **head, Node **tail, int valor) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->n = valor;
    novo->next = NULL;
    novo->prev = NULL;

    if (*head == NULL) { // lista vazia
        *head = novo;
        *tail = novo;
    } else {
        (*tail)->next = novo;
        novo->prev = *tail;
        *tail = novo;
    }
}

void imprimirLista(Node *head) {
    Node *aux = head;
    printf("Lista: ");
    while (aux != NULL) {
        printf("%d ", aux->n);
        aux = aux->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL, *tail = NULL;

    // Inserindo alguns valores
    inserirFim(&head, &tail, 10);
    inserirFim(&head, &tail, 20);
    inserirFim(&head, &tail, 30);
    inserirFim(&head, &tail, 40);
    inserirFim(&head, &tail, 50);

    imprimirLista(head);

    excluirIntervalo(&head, &tail, 10,50); // remove tudo entre 20 e 50
    imprimirLista(head);

    return 0;
}