#include <stdio.h>

#define LEN 20

void merge(int ini,int fim,int *array);
void intercale(int ini,int meio,int fim,int *array);


int main(){

    int array[LEN];

    for(int i=0;i<LEN;i++){
        array[i]=LEN-i-1;
        printf("|%d|",array[i]);
    }

    merge(0,LEN-1,array);
    printf("\n");

    for(int i=0;i<LEN;i++) printf("|%d|",array[i]);

    return 0;
}


void merge(int ini,int fim,int *array){
    if(ini < fim){
        int meio=(ini+fim)/2;
        merge(ini,meio,array);
        merge(meio+1,fim,array);
        intercale(ini,meio,fim,array);
    }
}

void intercale(int ini,int meio,int fim,int *array){
    int inicioV1=ini, inicioV2=meio+1, cont=0;
    int aux[LEN];

    while(inicioV1 <= meio && inicioV2 <=fim){
        if(array[inicioV1] <= array[inicioV2]) aux[cont++]=array[inicioV1++];
        else aux[cont++]=array[inicioV2++];
    }

    while(inicioV1 <= meio) aux[cont++]=array[inicioV1++];

    while(inicioV2<= fim) aux[cont++]=array[inicioV2++];

    for(int i=0;i<cont;i++) array[ini+i]=aux[cont];
}