#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void push(int entrada,Node **head);

void pop(Node **head);

void peek(Node *head);

void printStack(Node *head);

int isEmpty(Node *head);

int isFull(Node *head);


int main(){
     Node *stack = NULL;  // pilha começa vazia

    // inserindo elementos
    push(10, &stack);
    push(20, &stack);
    push(30, &stack);
    push(40, &stack);
    push(50, &stack);
    push(60, &stack); // ta full n é pra adicionar

    printf("Pilha atual:\n");
    printStack(stack);

    printf("\nTopo da pilha (peek): ");
    peek(stack);

    printf("\nRemovendo dois elementos...\n");
    pop(&stack);
    pop(&stack);

    printf("\nPilha apos os pops:\n");
    printStack(stack);

    printf("\nTopo da pilha agora: ");
    peek(stack);
    return 0;
}

int isEmpty(Node *head){
    return (head==NULL) ? 1 : 0;
}

int isFull(Node *head){
    int cont=0;
    while(head!=NULL){
        cont++;
        head=head->next;
    }
    return (cont==5) ? 1 : 0;
}

void push(int entrada,Node **head){
    if(!isFull(*head)){
        Node *new=malloc(sizeof(Node));
        new->n=entrada;
        new->next=*head;
        *head=new;
    }
}
void peek(Node *head){
    if(!isEmpty(head)){
        printf("%d\n",head->n);
    }
}

void pop(Node **head){
    if(!isEmpty(*head)){
        Node *remove=*head;
        *head=(*head)->next;
        free(remove);
    }
}

void printStack(Node *head){
    while(head!=NULL){
        printf("%d\n",head->n);
        head=head->next;
    }
}
