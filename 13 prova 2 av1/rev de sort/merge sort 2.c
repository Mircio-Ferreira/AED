#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10

void merge(int *arry,int ini,int fim);
void intercale(int *array,int ini,int meio,int fim);

int main(){

    srand(time(NULL));
    
    int array[LEN];

    for(int i=0;i<LEN;i++){
        array[i]=rand()%100;
        printf("|%d|",array[i]);
    }
    printf("\n");

    merge(array,0,LEN-1);

    for(int i=0;i<LEN;i++) printf("|%d|",array[i]);

    return 0;
}

void merge(int *arry,int ini,int fim){
    if(ini<fim){
        int meio=(ini+fim)/2;
        merge(arry,ini,meio);
        merge(arry,meio+1,fim);
        intercale(arry,ini,meio,fim);
    }
}
void intercale(int *array,int ini,int meio,int fim){
    int aux[LEN], cont=0;
    int atualV1=ini,atualV2=meio+1;

    while(atualV1<=meio && atualV2<=fim){
        if(array[atualV1] <= array[atualV2]) aux[cont++]=array[atualV1++];
        else aux[cont++]=array[atualV2++];
    }

    while(atualV1<=meio) aux[cont++]=array[atualV1++];

    while(atualV2<=fim) aux[cont++]=array[atualV2++];

    for(int i=0;i<cont;i++) array[ini+i]=aux[i];
}