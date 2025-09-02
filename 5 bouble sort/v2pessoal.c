#include <stdio.h>

void boubleSort(int *array,int len);

void swap(int *a,int *b);

int main(){

    int array[]={9,5,4,7,3,2,0,-1,999};
    int len=sizeof(array)/sizeof(int);

    for(int i=0;i<len;i++){
        printf("|%d|",array[i]);
    }
    boubleSort(array,len);
    printf("\n");
    for(int i=0;i<len;i++){
        printf("|%d|",array[i]);
    }
    return 0;
}

void boubleSort(int *array,int len){
    int troca=0,cont=0;
    while(troca==0 && cont<len){
        troca=1;
        for(int i=1;i<len;i++){ 
            if(array[i]<array[i-1]){
                swap(&array[i],&array[i-1]);
                troca=0;
            }
        }
        cont++;
    }
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
