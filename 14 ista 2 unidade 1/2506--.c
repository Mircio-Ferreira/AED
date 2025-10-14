#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int time;
    int minutes;
    int critialMinutes;
    struct Node *next;
    struct Node *prev;
} Node;

void insertEnd(Node **head, Node **tail, int time, int minutes, int critialMinutes);
int checkCritical(Node *head, Node *tail);
void freeList(Node **head, Node **tail);

int main() {
    Node *head = NULL, *tail = NULL;
    int contPatient;
    int time, minutos, criticalMinutes;

    while (1) {
        if (scanf("%d", &contPatient) != 1) break;
        for (int i = 0; i < contPatient; i++) {
            scanf("%d %d %d", &time, &minutos, &criticalMinutes);
            insertEnd(&head, &tail, time, minutos, criticalMinutes);
        }

        int critical = checkCritical(head, tail);
        printf("%d\n", critical);

        freeList(&head, &tail);
    }
    return 0;
}

void insertEnd(Node **head, Node **tail, int time, int minutes, int critialMinutes) {
    Node *newNode = malloc(sizeof(Node));
    newNode->time = time;
    newNode->minutes = minutes;
    newNode->critialMinutes = critialMinutes;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = *tail = newNode;
        newNode->prev = NULL;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void freeList(Node **head, Node **tail) {
    Node *aux = *head;
    while (aux != NULL) {
        Node *del = aux;
        aux = aux->next;
        free(del);
    }
    *head = *tail = NULL;
}

int checkCritical(Node *head, Node *tail) {
    int cont = 0;
    int current_slot_start_minutes = 7 * 60; // 7:00 em minutos
    Node *p = head;

    while (p != NULL) {
        // calcula chegada em minutos
        int chegada = p->time * 60 + p->minutes;

        // avança o horário do atendimento em blocos de 30 minutos até o paciente chegar
        while (current_slot_start_minutes < chegada) {
            current_slot_start_minutes += 30;
        }

        // calcula tempo de espera
        int waiting_time = current_slot_start_minutes - chegada;

        if (waiting_time > p->critialMinutes) {
            cont++;
        }

        // atendimento leva 30 minutos
        current_slot_start_minutes += 30;

        p = p->next;
    }

    return cont;
}
