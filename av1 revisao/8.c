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
    int temp=*a;
    *a=*b;
    *b=temp;
}

void insertionSort(int *array,int len){
    for(int i=1;i<len;i++){
        int posi=i;
        while(posi!=0 && array[posi]<array[posi-1]){
            swap(&array[posi],&array[posi-1]);
            posi--;
        }
    }
}

void boubleSortVo(int *array,int len){
    //i=1 pra ter um loop a menos, j começa no 0 e tem que controlar até ir no len-1 pra n acessar algo valido
    for(int i=1;i<len;i++){
        for(int j=0;j<len-1;j++){
            swap(&array[j],&array[j+1]);
        }
    }
}

void bouleSortv1(int *array,int len){
    for(int i=1;i<len;i++){
        for(int j=len-1;j>=i;j--){
            if(array[j]<array[j-1]) swap(&array[j],&array[j-1]); 
        }
    }
}

void boubleSortv2(int *array,int len){
    int troca=0;
    int cont=1;
    while(troca==0 && cont<len){
        troca=1;
        for(int i=0;i<len-1;i++){
            if(array[i]>array[i+1]){
                swap(&array[i],&array[i+1]);
                troca=0;
            }
        }
        cont++;
    }
}