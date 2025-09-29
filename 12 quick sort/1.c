#include <stdio.h>

void swap(int *array,int i,int indicie);
void quick(int *array,int ini,int fim);
int particao(int *array,int ini,int fim);

int main(){

    int len=10;
    int array[len];

    for(int i=0;i<len;i++) array[i]=len-i;

    for(int i=0;i<len;i++) printf("|%d|",array[i]);

    printf("\n");

    quick(array,0,len-1);

    for(int i=0;i<len;i++) printf("|%d|",array[i]);


    return 0;
}

void quick(int *array,int ini,int fim){
    if(ini<fim){
        int indicie=particao(array,ini,fim);
        quick(array,ini,indicie-1);
        quick(array,indicie+1,fim);
    }
}

int particao(int *array,int ini,int fim){
    int pivo=ini, indicie=fim;
    
    for(int i=fim;i> ini;i--){
        if(array[i]>=array[pivo]) swap(array,i,indicie--);
    }

    swap(array,pivo,indicie);
    return indicie;
}

void swap(int *array,int i,int indicie){
    int temp=array[i];
    array[i]=array[indicie];
    array[indicie]=temp;
}