#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char c;
    struct Node *next;
}Node;

void push(Node **head,char c);

void pop(Node **head);

char check(Node *head);

int main(){
    Node *head=NULL;
    int vagao=-1;
    while(1){
        head=NULL;
        scanf("%d",&vagao);
        if(vagao==0)break;

        int contEntradas=0,contSaidas=0;
        char entrada[vagao],saida[vagao];
        int possible=1;

        for(int i=0;i<vagao;i++) scanf(" %c",&entrada[i]);
        for(int i=0;i<vagao;i++) scanf(" %c",&saida[i]);

        while(contSaidas<vagao){
            if(head!=NULL && check(head)==saida[contSaidas]){
                pop(&head);
                printf("R");
                contSaidas++;
            }
            else if(contEntradas<vagao){
                push(&head,entrada[contEntradas]);
                contEntradas++;
                printf("I");
            }
            else{
                possible=0;
                break;
            }
        }
        if(!possible) printf(" Impossible");
        printf("\n");
           
    }
    return 0;
}

void push(Node **head,char c){
    Node *new=malloc(sizeof(Node));
    new->c=c;
    new->next=*head;
    *head=new;
}

void pop(Node **head){
    if(*head!=NULL){
        Node *delete=*head;
        *head=(*head)->next;
        free(delete);
    }
}

char check(Node *head){
    if(head==NULL) return '0';
    return head->c;
}