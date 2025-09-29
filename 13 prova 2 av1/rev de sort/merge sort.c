#include <stdio.h>

#define LEN 10

void merge(int *array,int ini,int fim);
void intercale(int *array,int ini,int meio,int fim);

int main(){

    int array[LEN];

    for(int i=0;i<LEN;i++){
        array[i]=LEN-i;
        printf("|%d|",array[i]);
    }
    printf("\n");

    merge(array,0,LEN-1);

    for(int i=0;i<LEN;i++) printf("|%d|",array[i]);

    return 0;
}


void merge(int *array,int ini,int fim){
    if(ini<fim){
        int meio=(ini+fim)/2;

        merge(array,ini,meio);
        merge(array,meio+1,fim);
        intercale(array,ini,meio,fim);
    }
}
void intercale(int *array,int ini,int meio,int fim){
    int aux[LEN], cont=0;
    int atualv1=ini,atualv2=meio+1;

    while(atualv1 <= meio && atualv2 <= fim){
        if(array[atualv1] <= array[atualv2]) aux[cont++]=array[atualv1++];
        else aux[cont++]=array[atualv2++];
    }

    while(atualv1 <= meio) aux[cont++]=array[atualv1++];

    while(atualv2 <= fim) aux[cont++]=array[atualv2++];

    for(int i=0;i<cont;i++) array[ini+i]=aux[i];
}