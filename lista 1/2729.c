#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char palavra[21];
    struct Node *next;
}Node;

void insert(Node **head,char *input);

void print(Node *head);

void boubleSortv2(Node **head);

int lenLista(Node *head);

void swapNo(Node *a,Node *b);

int main(){

    Node *head=NULL;
    char frase[25000],palavra[21];
    int casos,cont=0;
    scanf("%d ",&casos);

    for(int i=0;i<casos;i++){
        //scanf("%s",frase);
        scanf(" %[^\n]", frase);
        int lenFrase=strlen(frase);
        for(int j=0;j<=lenFrase;j++){
            if(frase[j]!=' ' && frase[j]!='\0') palavra[cont++]=frase[j];
            else{
                palavra[cont]='\0';
                cont=0;
                //printf("%s\n",palavra);
                insert(&head,palavra);
            }
        }
        boubleSortv2(&head);
        print(head);
        printf("\n"); // ve se precisa dps
        head=NULL;
    }


    return 0;
}

void insert(Node **head,char *input){
    Node *new=malloc(sizeof(Node));
    strcpy(new->palavra,input);
    new->next=NULL;
    if(*head==NULL) *head=new;
    else{
        Node *aux=*head;
        while(aux->next!=NULL){
            if(strcmp(input,aux->palavra) == 0) {
                free(new);
                return;
            }
            aux=aux->next;
        }
        if(strcmp(input,aux->palavra) == 0) {
            free(new);
            return;
        }
        aux->next=new;
    }
}

void print(Node *head){
    while(head!=NULL){
        if(head->next==NULL){
            printf("%s",head->palavra);
            return;
        }
        printf("%s ",head->palavra);
        head=head->next;
    }
}

int lenLista(Node *head){
    int cont=0;
    while(head!=NULL){
        cont++;
        head=head->next;
    }
    return cont;
}

void swapNo(Node *a,Node *b){
    char temp[21];
    strcpy(temp,a->palavra);
    strcpy(a->palavra,b->palavra);
    strcpy(b->palavra,temp);
}

void boubleSortv2(Node **head){
    if(*head==NULL) return;
    int len=lenLista(*head);
    int cont=1;
    int troca=1;
    while(troca==1 && cont<=len){
        troca=0;
        Node *aux=*head;
        for(int i=0;i<len-1;i++){
            if(strcmp(aux->palavra,aux->next->palavra) > 0){
                swapNo(aux,aux->next);
                troca=1;
            }
            aux=aux->next;
        }
        cont++;
    }
}