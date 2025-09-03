#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b);

void insertionSort(int *array,int len);

void boubleSortVo(int *array,int len);

void bouleSortv1(int *array,int len);

void boubleSortv2(int *array,int len);

int main(){

    int array[]={-3,2,9,-8,0,1,999,-1};
    int len=sizeof(array)/sizeof(int);
    
    for(int i=0;i<len;i++){
        printf("|%d|",array[i]);
    }

    printf("\n");
    //insertionSort(array,len);
    //boubleSortVo(array,len);
    //bouleSortv1(array,len);
    boubleSortv2(array,len);


    for(int i=0;i<len;i++){
        printf("|%d|",array[i]);
    }

    return 0;
}

void swap(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}


