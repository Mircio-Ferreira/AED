#include <stdio.h>
#include <time.h>

void quick(int *array,int ini,int fim);
int particionar(int *array,int ini,int fim);
void swap(int *array,int a,int b);


int main(){

    srand(time(NULL));
    
    int len=20;
    int array[len];

    for(int i=0;i<len;i++) array[i]=rand()%100;

    for(int i=0;i<len;i++) printf("|%d|",array[i]);

    printf("\n");

    quick(array,0,len-1);

    for(int i=0;i<len;i++) printf("|%d|",array[i]);

    return 0;
}

void swap(int *array,int a,int b){
    int temp=array[a];
    array[a]=array[b];
    array[b]=temp;
}

void quick(int *array,int ini,int fim){
    if(ini < fim){
        int indicie=particionar(array,ini,fim);
        quick(array,ini,indicie-1);
        quick(array,indicie+1,fim);
    }
}

int particionar(int *array,int ini,int fim){
    int pivo=ini, indicie=fim;

    for(int i=fim;i > ini;i--){
        if(array[i]>=array[pivo]) swap(array,i,indicie--);
    }

    swap(array,indicie,pivo);
    return indicie;
}
