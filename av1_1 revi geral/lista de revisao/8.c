#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *array,int len);

void boubleSortV0(int *array,int len);

void boubleSortV1(int *array,int len);

void boubleSortV2(int *array,int len);

void swap(int *a,int *b);


int main(){

    int array[]={5,4,3,2,1,0};
    int len=sizeof(array)/sizeof(int);
    for(int i=0;i<len;i++) printf("|%d|",array[i]);
    printf("\n");

    insertionSort(array,len);

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
        int current=i;
        while(current!=0 && array[current]<array[current-1]){
            swap(&array[current],&array[current-1]);
            current--;
        }
    }
}

void boubleSortV0(int *array,int len);

void boubleSortV1(int *array,int len);

void boubleSortV2(int *array,int len);