#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char name[50];
    int age;
    float nota;
}Student;

void getStudant(Student *student,int posi);

void outStudent(Student *studen,int len);

int main(){

    int quant;
    scanf("%d",&quant);

    Student *student= malloc(sizeof(Student)*quant);

    for(int i=0 ;i<quant;i++){
        getStudant(student,i);
    }

    outStudent(student,quant);


    printf("\nEnd Of programin!\n");

    free(student);
    return 0;
}

void getStudant(Student *student,int posi){
    printf("\n%d.Digite o nome do aluno: ",posi);
    scanf(" %s",student[posi].name);
    printf("\nDigite a idade do aluno: ");
    scanf(" %d",&student[posi].age);
    printf("\nDigite a nota do aluno: ");
    scanf(" %f",&student[posi].nota);
    printf("\n");
}

void outStudent(Student *studen,int len){
    for(int i=0;i<len;i++){
    printf("\n[%d] Nome:%s, idade: %d, nota: %.2f",i,studen[i].name,studen[i].age,studen[i].nota);
    }
}