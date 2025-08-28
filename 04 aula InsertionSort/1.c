#include <stdio.h>

void insertionSort(int *array,int len){
    for(int i=1;i<len;i++){
        int j=i;
        while(array[j]<array[j-1] && j>0){
            int aux = array[j];
            array[j]=array[j-1];
            array[j-1]=aux;
            j--;
        }
    }
};

int main(){

    int len=5;
    int array[5]={5,4,3,2,1};
    insertionSort(array,len);
    for(int i=0;i<5;i++){
        printf("|%d|",array[i]);
    }

    return 0;
}

