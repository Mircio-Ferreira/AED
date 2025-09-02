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
    for(int i=1;i<len;i++){
        for(int j=1;j<len;j++){
            if(array[j]<array[j-1]) swap(&array[j],&array[j-1]);
        }
    }
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
