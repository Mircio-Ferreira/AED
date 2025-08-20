/*
02 - Crie um programa em C para uma clínica médica que precisa  automatizar o
 controle da ordem de atendimento de seus pacientes que deve possuir um menu com as seguintes funcionalidades:

Clínica Médica

=============

(1) Incluir paciente

(2) Realizar atendimento do paciente (remoção do paciente)

(3) Consultar a posição atual do paciente pelo nome

(4) Exibir a quantidade de pacientes já atendidos

(5) Sair

O critério de atendimento é a ordem de chegada. 
O paciente deve fornecer seu nome. Após isso, o paciente é adicionado ao sistema e deve aguardar sua vez. 


**Para a estrutura da fila considere o seguinte struct: 

typedef struct { char nome[30];  

                           struct Node *prox; } Node;*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int patientCared = 0; //obs variavel global

typedef struct Node{
    char name[30];
    struct Node *next;
}Node;

void enqueue(Node **head, Node **tail, char *name);

void dequeue(Node **head, Node **tail);

void printQueue(Node *head,char *consultName);

void countPaint();


int main(){

    int comand=-1;
    char name[30];
    Node *head=NULL,*tail=NULL;

    while(1){
        printf("\n1-Incluir Paciente\n2-Realiza atendimento do paciente(remover da fila)\n3-consulta a posicao atual do paciente pelo nome\n4-Exibir a quantidade de pacientes ja atendidos\n5-sair");
        printf("\nDigite comando: ");
        scanf(" %d",&comand);
        if(comand==1){
            printf("\nDigite nome: ");
            scanf(" %s",name);
            enqueue(&head,&tail,name);
        }
        else if(comand==2){
            dequeue(&head,&tail);
        }
        else if(comand==3){
            printf("\nDigite nome a ser consultado: ");
            scanf(" %s",name);
            printQueue(head,name);
        }
        else if(comand==4){
            printf("\nquantidade de pacientes atendidos: %d\n",patientCared);
        }
        else if(comand==5) break;
        else printf("\ncomando invalido\n");  
    }

    return 0;
}

void enqueue(Node **head, Node **tail, char *name){
    Node *new=(Node *)malloc(sizeof(Node));
    strcpy(new->name,name);
    new->next=NULL;

    if(*head==NULL) *head=*tail=new;
    else{
        (*tail)->next=new;
        *tail=new;
    }
}

void dequeue(Node **head, Node **tail){
    if(*head!=NULL){
        Node *temp=*head;
        *head=(*head)->next;
        free(temp);
        countPaint(); // funcao para fazer o incremento da variavel global de pacientes atendidos.
        if(*head==NULL) *tail=NULL;
    }
    else printf("\nfila fazia, nao a quem ser atendido!\n");
}

void printQueue(Node *head,char *consultName){
    if(head==NULL) printf("'\nLista Vazia\n");
    else{
        int cont=0;
        while(head!=NULL){
            if(strcmp(head->name,consultName)==0){
                printf("paciente %s na posicao: %d\n",consultName,cont);
                return;
            }
            cont++;
            head=head->next;
        }
        printf("\nPessoa não encontrada!\n");
    }
}

void countPaint(){
    patientCared++;
}