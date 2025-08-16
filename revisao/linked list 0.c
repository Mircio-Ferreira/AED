#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    struct Node *next;
}Node;

void insertAtBeging(Node **head, int num);

void printList(Node *head);

int main(){
    Node *head = NULL;
    int entrada;
    for(int i=0;i<3;i++){
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &entrada);
        insertAtBeging(&head,entrada);
    }
    printList(head);
    return 0;
}

void insertAtBeging(Node **head, int num){
    Node *newNode=malloc(sizeof(Node));
    
    newNode->num=num;
    newNode->next=*head;
    *head=newNode;
}

void printList(Node *head){
    if(head==NULL){
        printf("Lista vazia\n");
    }
    while(head!=NULL){
        printf("\n%d",head->num);
        head=head->next;
    }
}
