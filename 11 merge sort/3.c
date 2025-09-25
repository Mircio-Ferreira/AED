#include <stdio.h>

#define LEN 10

void merge(int star,int end,int *array);
void intercale(int star,int middle,int end,int *array);

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

void merge(int star,int end,int *array){
    if(star < end){
        int middle=(star+end)/2;
        merge(star,middle,array);
        merge(middle+1,end,array);
        intercale(star,middle,end,array);
    }
}

void intercale(int star,int middle,int end,int *array){
    int currentV0=star , currentV1=middle+1, cont=0;
    int aux[LEN];

    while(currentV0<=middle && currentV1<=end){
        if(array[currentV0] <= array[currentV1]) aux[cont++]=array[currentV0++];
        else aux[cont++]=array[currentV1++]; 
    }

    while(currentV0 <= middle) aux[cont++]=array[currentV0++];

    while(currentV1 <= end) aux[cont++]=array[currentV1++];

    for(int i=0;i<cont;i++) array[star+i]=aux[i];

}