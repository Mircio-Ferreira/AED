#include <stdio.h>

void insertionSort(int *array,int len);

int main(){

    int array[]={9,5,4,7,3,2,0,-1,999};
    int len=sizeof(array)/sizeof(int);

    for(int i=0;i<len;i++){
        printf("|%d|",array[i]);
    }
    insertionSort(array,len);
    printf("\n");
    for(int i=0;i<len;i++){
        printf("|%d|",array[i]);
    }
    return 0;
}

void insertionSort(int *array,int len){
    for(int i=1;i<len;i++){
        int current=i;
        while(current!=0 && array[current]<array[current-1]){
            int temp=array[current];
            array[current]=array[current-1];
            array[current-1]=temp;
            current--;
        }
    }
}