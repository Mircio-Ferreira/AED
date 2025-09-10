#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *array,int len);

void boubleSortV0(int *array,int len);

void boubleSortV1(int *array,int len);

void boubleSortV2(int *array,int len);

void swap(int *a,int *b);

int GLOBALCONT=0;

int main(){

    int array[]={5,4,3,2,1,0};
    int len=sizeof(array)/sizeof(array[0]); 
    for(int i=0;i<len;i++) printf("|%d|",array[i]);
    printf("\n");

    //insertionSort(array,len);
    //boubleSortV0(array,len);
    //boubleSortV1(array,len);
    boubleSortV2(array,len);

    printf("Global cont: %d\n",GLOBALCONT);

    for(int i=0;i<len;i++) printf("|%d|",array[i]);

    return 0;
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void insertionSort(int *array,int len){
    for(int i=1;i<=len-1;i++){
        GLOBALCONT++;
        int current=i;
        while(current!=0 && array[current] < array[current-1]){
            swap(&array[current],&array[current-1]);
            current--;
        }
    }
}

void boubleSortV0(int *array,int len){
    for(int i=1;i<=len;i++){
        for(int j=0;j<len-1;j++){
            if(array[j]>array[j+1]) swap(&array[j],&array[j+1]);
        }
    }
}

void boubleSortV1(int *array,int len){
    for(int i=1;i<=len-1;i++){
        for(int j=len-1;j>=i;j--){
            if(array[j] < array[j-1]) swap(&array[j],&array[j-1]);
        }
    }
}

void boubleSortV2(int *array,int len){
    int troca = 1, cont =1;    
    while(troca==1 && cont<=len){
        GLOBALCONT++;
        troca=0;
        for(int i=0;i<len-1;i++){
            if(array[i] > array[i+1]){
                swap(&array[i],&array[i+1]);
                troca=1;
            }
        }
        cont++;
    }
}