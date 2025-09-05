#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

//questao 1
int checkValue(Node *head,int check);

//questao 2
void insertBeging(Node **head,int n);
void insertFinish(Node **head,int n);

//questao 3
void removeEnd(Node **head);

//questao 4
void insertRelativePosition(Node **head,int posi,int n);

//questao 5
void removeRelativePosition(Node **head,int posi);

//pra testar
void printList(Node *head);

int main(){

    Node *head = NULL;

    printf("Inserindo 10, 20 e 30 no final\n");
    insertFinish(&head, 10);
    insertFinish(&head, 20);
    insertFinish(&head, 30);
    printList(head);

    printf("Inserindo 5 no começo\n");
    insertBeging(&head, 5);
    printList(head);

    printf("Inserindo 15 na posição 2\n");
    insertRelativePosition(&head, 2, 15);
    printList(head);

    printf("Removendo elemento na posição 0\n");
    removeRelativePosition(&head, 0);
    printList(head);

    printf("Removendo elemento na posição 2 (limite ou último)\n");
    removeRelativePosition(&head, 2);
    printList(head);

    printf("Removendo o último elemento\n");
    removeEnd(&head);
    printList(head);

    printf("Verificando se 20 está na lista: %s\n", checkValue(head, 10) ? "Sim" : "Não");
    printf("Verificando se 100 está na lista: %s\n", checkValue(head, 100) ? "Sim" : "Não");

    return 0;
}

int checkValue(Node *head,int check){
    while(head!=NULL){
        if(head->n==check) return 1;
        head=head->next;
    }
    return 0;
}

void insertBeging(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    new->next=*head;
    *head=new;
}

void insertFinish(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    new->next=NULL;
    if(*head==NULL) *head=new;
    else{
        Node *aux=*head;
        while(aux->next!=NULL) aux=aux->next;
        aux->next=new;
    }
}
void removeEnd(Node **head){
    Node *aux;
    if(*head==NULL) return;
    else if((*head)->next==NULL){
        free(*head);
        *head=NULL;
    }
    else{
        aux=*head;
        while(aux->next!=NULL){
            if(aux->next->next==NULL){
                free(aux->next);
                aux->next=NULL;
                return;
            }
            aux=aux->next;
        }
    }
}

void insertRelativePosition(Node **head,int posi, int n){//considerando posi incial como 0
    if(posi<0) return;
    Node *aux=*head;
    int cont=0;
    while(aux!=NULL){
        cont++;
        aux=aux->next;
    }
    if(posi<=cont){
        Node *new=malloc(sizeof(Node));
        new->n=n;
        new->next=NULL;
        if(posi==0){
            new->next=*head;
            *head=new;
        }
        else{
            aux=*head;
            for(int i=0;i<posi-1;i++){
                aux=aux->next;
            }
            new->next=aux->next;
            aux->next=new;
        }
    }
}

void removeRelativePosition(Node **head,int posi){
    if(*head==NULL) return;
    Node *aux,*remove;
    if(posi==0){
        remove=*head;
        *head=(*head)->next;
        free(remove);
    }
    else{
        int cont=0;
        aux=*head;
        while(aux->next!=NULL && cont<posi-1){
            aux=aux->next;
            cont++;
        }
        remove=aux->next;
        aux->next=aux->next->next;
        free(remove);
    }
}

void printList(Node *head){
    while(head!=NULL){
        printf("%d\n",head->n);
        head=head->next;
    }
}