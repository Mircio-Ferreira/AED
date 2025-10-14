#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int time;
    int minutes;
    int critialMinutes;
    struct Node *next;
    struct Node *prev;
}Node;

void insertEnd(Node **head,Node **tail,int time,int minutes,int critialMinutes);
int checkCritical(Node *head,Node *tail);
void freeList(Node **head,Node **tail);

int main(){
    Node *head=NULL,*tail=NULL;
    int contPatient;
    int time,minutos,criticalMinutes;

    while(1){
        if (scanf("%d", &contPatient) != 1) break;
        //scanf("%d", &contPatient);
        for(int i=0;i<contPatient;i++){
            scanf("%d %d %d",&time,&minutos,&criticalMinutes);
            insertEnd(&head,&tail,time,minutos,criticalMinutes);
        }
        int critical=checkCritical(head,tail);
        printf("%d\n",critical);
        freeList(&head,&tail);
    }
}

void insertEnd(Node **head,Node **tail,int time,int minutes,int critialMinutes){
    Node *new=malloc(sizeof(Node));
    new->time=time;
    new->minutes=minutes;
    new->critialMinutes=critialMinutes;
    new->next=NULL;
    if(*head==NULL){
        *head=*tail=new;
        new->prev=NULL;
    }
    else{
        (*tail)->next=new;
        new->prev=*tail;
        *tail=new;
    }
}


void freeList(Node **head,Node **tail){
    if(*head!=NULL){
        Node *aux=*head, *delete;
        while(aux!=NULL){
            delete=aux;
            aux=aux->next;
            free(delete);
        }
        *head=*tail=NULL;
    }
}

int checkCritical(Node *head,Node *tail){

    int cont = 0;
    int lastStartedAttendiment= 7*60;
    Node *aux=head;

    while(aux!=NULL){
        
        while(lastStartedAttendiment <  ((aux->time*60)+aux->minutes) ) lastStartedAttendiment+=30;

        if(lastStartedAttendiment-((aux->time*60)+aux->minutes) > aux->critialMinutes) cont++;

        lastStartedAttendiment+=30;

        aux=aux->next;
    }
    return cont;
}
