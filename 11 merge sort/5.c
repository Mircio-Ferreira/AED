#include <stdio.h>
#include <stdlib.h>

#define LEN 10

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

void aa(int low, int high, int mid, int arr[]) {
    int aux[high - low + 1];
    int i = low, j = mid + 1, k = 0;

    while(i <= mid && j <= high) 
        aux[k++] = arr[i] > arr[j] ? arr[j++] : arr[i++];

    while (i <= mid) aux[k++] = arr[i++];
    while (j <= high) aux[k++] = arr[j++];

    for (int i = 0;i < k; i++) arr[low + i] = aux[i];
}

void intercale(int ini,int meio,int fim,int *array){
    int atual1=ini, atual2=meio+1,cont=0;
    int aux[LEN];

    while(atual1 <= meio && atual2 <=fim){
        if(array[atual1] <= array[atual2]) aux[cont++]=array[atual1++];
        else aux[cont++] = array[atual2++];
    }

    while(atual1 <=meio) aux[cont++]=array[atual1++];

    while(atual2 <= fim) aux[cont++]=array[atual2++];

    for(int i=0;i<cont;i++) array[ini+i]=aux[cont];
}