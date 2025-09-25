#include <stdio.h>
#include <stdlib.h>

/*
QUESTÃO 01 -
Um determinado programa será implementado em C e deve
permitir manipular números em uma lista circular simplesmente encadeada, mas,
possui apenas a função que insere nós, inclua no programa as seguintes
funcionalidades:
a) (2 pontos) Remoção de elementos no início da lista circular;
Protótipo da função: void remover(Node **head, Node **tail);
b) (3 pontos) Imprima a multiplicação dos valores de duplas de nós que
estão nesta lista. Se tiver uma quantidade ímpar de nós (sobrando um nó),
para o nó restante, multiplique o valor dele por ele próprio. E se a lista tiver
menos que 2 nós, exiba a seguinte mensagem: “Tamanho da lista é
insuficiente :(”
*/

typedef struct Node{
    int n;
    struct Node *next;
}Node;


void insert(Node **head,Node **tail, int n);
void remover(Node **head, Node **tail);
void printMp(Node *head, Node *tail);
void print(Node *head);

void printMpv2(Node *head,Node *tail);

int len(Node *head,Node *tail);

int main(){
    Node *head=NULL, *tail=NULL;

    insert(&head,&tail,-100);
    insert(&head,&tail,6);
    insert(&head,&tail,5);
    insert(&head,&tail,4);
    insert(&head,&tail,3);
    insert(&head,&tail,2);
    insert(&head,&tail,1);


    print(head);

    //printMp(head,tail);
    printMpv2(head,tail);
    
    return 0;
}



void insert(Node **head,Node **tail, int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    if(*head==NULL) *head=*tail=new->next=new;
    else{
        new->next=*head;
        *head=new;
        (*tail)->next=*head;
    }
}
void remover(Node **head, Node **tail){
    if(*head!=NULL){
        Node *remove=*head;
        if(*head==*tail) *head=*tail=NULL;
        else{
            *head=(*head)->next;
            (*tail)->next=*head;
        }
        free(remove);
    }
}

void printMp(Node *head, Node *tail){
    int cont=len(head,tail);

    if(cont<2){
        printf("Tamanho insuficiente :(\n)");
        return;
    }
    int first,second;
    for(int i=0;i<cont;i++){
        if(i%2==0) first=head->n;
        else{
            second=head->n;
            printf("|first: %d\tsecond %d\t mp = %d|\n",first,second,(first*second));      
        }
        head=head->next;
    }

    if(cont%2!=0) printf("lista de tamanho impar\t last: %d\t mp = %d",tail->n,(tail->n * tail->n));
}


void print(Node *head){
    if(head!=NULL){
        Node *aux=head;
        do{
            printf("|%d|",aux->n);
            aux=aux->next;
        }while(head!=aux);
        printf("\n");
    }
}

int len(Node *head,Node *tail){
    int cont=0;
    if(head!=NULL){
        Node *aux=head;
        do{
            cont++;
            aux=aux->next;
        }while(aux!=head);
    }

    return cont;
}


void printMpv2(Node *head,Node *tail){
    int cont=0, first, second;

    if(head!=NULL){
        Node *aux=head;
        do{
            if(cont%2==0) first = aux->n;
            else{
                second = aux->n;
                printf("|first: %d\tsecond %d\t mp = %d|\n",first,second,(first*second));
            }
            cont++;
            aux=aux->next;    
        }while(head!=aux);

        if(cont<2) printf("tamanho insuficiente");

        else if(cont%2!=0) printf("lista de tamanho impar\t last: %d\t mp = %d",tail->n,(tail->n * tail->n));

    }
    else printf("tamanho insuficiente");
}