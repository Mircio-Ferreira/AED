#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void print(Node *head){
    if(head!=NULL){
        Node *aux=head;
        do{
            printf("|%d|",aux->n);
            aux=aux->next;
        }while(aux!=head);
        printf("\n");
    }
}

void insertFinish(Node **head,Node **tail,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    if(*head==NULL){
        *head=*tail=new;
        (*tail)->next=*head;
    }
    else{
        (*tail)->next=new;
        *tail=new;
        (*tail)->next=*head;
    }
}

void multiplicacao(Node *head,Node *tail);

int main(){
    
    Node *head=NULL,*tail=NULL;

    insertFinish(&head,&tail,0);
    insertFinish(&head,&tail,1);
    insertFinish(&head,&tail,2);
    insertFinish(&head,&tail,3);
    insertFinish(&head,&tail,4);
    insertFinish(&head,&tail,5);
    insertFinish(&head,&tail,6);
    insertFinish(&head,&tail,7);
    insertFinish(&head,&tail,8);

    print(head);

    multiplicacao(head,tail);


    return 0;
}

void multiplicacao(Node *head,Node *tail){
    if(head==NULL || head==tail) printf("tamanho insuficiente\n");
    else{
        int cont=0,nPar,nImpar;
        do{
            if(cont%2==0) nPar=head->n;
            else{
                nImpar=head->n;
                printf("posi par: %d\tposi impar: %d\t %dx%d = %d\n",nPar,nImpar,nPar,nImpar,(nPar*nImpar));
            }
            cont++;
            head=head->next;
        }while(head!=tail->next);
        if(cont%2!=0) printf("umltima posi %d\t %dx%d = %d",nPar,nPar,nPar,(nPar*nPar));
    }
}

