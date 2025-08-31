#include <stdio.h>

void insertionSort(int *array,int len);

void swap(int *a,int *b);

int main(){

    int array[]={9,7,5,3,6,8,3};
    int len=sizeof(array)/sizeof(int);

    for(int i=0;i<len;i++){
        printf("|%d|",array[i]);
    }
    insertionSort(array,len);

    printf("\n");

    for(int i=0;i<len;i++) printf("|%d|",array[i]);

    return 0;
}

void insertionSort(int *array,int len){
    for(int i=1;i<len;i++){
        int currenty=i;

        while(currenty!=0 && array[currenty]>array[currenty-1]){
            swap(&array[currenty],&array[currenty-1]);
            currenty--;
        }
    }
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}