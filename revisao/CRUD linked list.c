#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int id;
    char name[50];
    char telephone[15];
    struct Node *next;
}Node;

void insertSort(Node **head,int newId, char *newName, char *newTelephone);

void delete(Node **head, int idDelete);

void search(Node *head, int idSearch);

void printAll(Node *head);

void freeMemore(Node **head);

int main(){

    Node *head=NULL;
    int comand=-1;
    int contId=0;

    while(1){

        printf("\n1- inserir\n2-delete\n3- busca\n4- mostra toda lista\n5-Deletar tudo\n6- sair");
        printf("\ndigite comando: \n");
        scanf("%d",&comand);
        if(comand == 1){
            char name[50];
            char telefone[15];
            printf("digite nome: ");
            scanf(" %s",name);
            printf("digite telefone: ");
            scanf(" %s",telefone);
            insertSort(&head,contId,name,telefone);
            contId++;
        }
        else if(comand == 2){
            printf("digite Id da pessoa que desenha remover: ");
            int idRemove;
            scanf(" %d",&idRemove);
            delete(&head,idRemove);
        }
        else if(comand == 3){
            printf("digite Id da pessoa que deseja buscar: ");
            int idSearch;
            scanf(" %d",&idSearch);
            search(head,idSearch);
        }
        else if(comand == 4){
            printAll(head);
        }
        else if(comand == 5){
            contId=0;
            freeMemore(&head);
        }
        else if(comand == 6) break;
        else{
            printf("Comando invalido tente novamente\n");
        }
    }


    return 0;
}

void insertSort(Node **head,int newId, char *newName, char *newTelephone){
    Node *new=malloc(sizeof(Node));
    new->id=newId;
    strcpy(new->name,newName);
    strcpy(new->telephone,newTelephone);
    new->next=NULL;

    if(*head==NULL){
        *head=new;    
    }
    else if(strcmp(new->name,(*head)->name) < 0){
        new->next=*head;
        *head=new;
    }
    else{
        Node *aux = *head;
        while(aux->next!=NULL){
            if(strcmp(new->name,aux->next->name) < 0){
                new->next=aux->next;
                aux->next=new;
                return;
            }
            aux=aux->next;
        }
        //insersao no final
        aux->next=new;
    }
}

void delete(Node **head, int idDelete){
    
    Node *temp, *aux=*head;

    if(*head == NULL){
        printf("Lista Vazia nao ah o que remover\n");
        return;
    }
    //removendo antes do comeco
    if((*head)->id == idDelete){
        temp=*head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    //caso geral
    while(aux->next!=NULL){
        if(idDelete == aux->next->id){
            temp=aux->next;
            aux->next=aux->next->next;
            free(temp);
            return;
        }
        aux=aux->next;
    }
}

void search(Node *head, int idSearch){
    if(head==NULL){
        printf("Lista Vazia");
        return;
    }
    while(head!=NULL){
        if(idSearch == head->id){
            printf("[id: %d\nname: %s\ntelefone: %s\n ]\n",head->id,head->name,head->telephone);
            return;
        } 
        head=head->next;
    }
    printf("!!!!!!!Id não encontrado!\n");
}

void printAll(Node *head){
    if(head == NULL){
        printf("Lista Vazia\n");
    }
    while(head!=NULL){
        printf("[id: %d name: %s telefone: %s ]\n",head->id,head->name,head->telephone);
        head=head->next;
    }
}

void freeMemore(Node **head){
    Node *temp, *aux=*head;

    while(aux!=NULL){
        temp=aux;
        aux=aux->next;
        free(temp);
    }
    *head=NULL;
}
