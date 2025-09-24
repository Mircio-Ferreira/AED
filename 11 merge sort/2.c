#include <stdio.h>
#include <stdlib.h>

#define LEN 10

void merge(int ini, int fim, int *array);
void intercale(int ini,int meio, int fim , int *array);


int main(){

    //int array[10]={9,8,7,6,5,4,3,2,1,0};
    int array[10]={0,1,2,3,4,5,6,7,8,9};

    for(int i=0;i<10;i++) printf("|%d|",array[i]);


    merge(0,9,array);

    printf("\n");

    for(int i=0;i<10;i++) printf("|%d|",array[i]);

    return 0;
}

void merge(int ini, int fim, int *array){
    if(ini < fim){
        int meio=(ini+fim)/2;
        merge(ini,meio,array);
        merge(meio+1,fim,array);
        intercale(ini,meio,fim,array);
    }
}
void intercale(int ini,int meio, int fim , int *array){
    int ini_1=ini, ini_2=meio+1, cont =0;
    int aux[LEN];

    while(ini_1<=meio && ini_2 <=fim){
        if(array[ini_1] >= array[ini_2]) aux[cont++]= array[ini_1++];
        else aux[cont++] = array[ini_2++];
    }

    while( ini_1 <= meio) aux[cont++]=array[ini_1++];

    while( ini_2 <= fim) aux[cont++]=array[ini_2++];

    for(int i=0 ; i<cont;i++) array[ini+i]=aux[i];
}