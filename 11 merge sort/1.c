#include <stdio.h>
#include <stdlib.h>

#define LEN 10

void merge(int ini,int fim,int *array);

void intercale(int ini, int meio, int fim, int *array);

int main(){
    
    int array[10]={9,8,7,6,5,4,3,2,1,0};

    for(int i=0;i<10;i++) printf("|%d|",array[i]);


    merge(0,9,array);

    printf("\n");

    for(int i=0;i<10;i++) printf("|%d|",array[i]);

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

void intercale(int ini, int meio, int fim, int *array){
    int ini_array01 = ini, ini_array02=meio+1;
    int cont=0;
    int aux[LEN];

    while( ini_array01 <= meio && ini_array02 <= fim){
        if(array[ini_array01] <= array[ini_array02]) aux[cont++]=array[ini_array01++];

        else aux[cont++] = array[ini_array02++];
    }

    while(ini_array01 <= meio){
        aux[cont++]=array[ini_array01++];
    }

    while(ini_array02 <= fim){
        aux[cont++]=array[ini_array02++];
    }

    for(int i=0 ; i<cont ;i++) array[i+ini]=aux[i];
}