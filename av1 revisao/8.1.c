#include <stdio.h>
#include <stdlib.h>

int globalcont=0;

void swap(int *a,int *b);

void insertionSort(int *array,int len);

void boubleSortVo(int *array,int len);

void bouleSortv1(int *array,int len);

void boubleSortv2(int *array,int len);

int main(){

    int array[]={5,4,3,2,1,0};
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

    printf("\nglobal: %d",globalcont);

    return 0;
}

void swap(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}


void boubleSortVo(int *array,int len){
    for(int i=0;i<len;i++){ // deve rodar a mesma quantidade do tamanho do vetor( len )
        for(int j=0;j<len-1;j++){ // roda len-1 quantidade
            if(array[j]>array[j+1]) swap(&array[j],&array[j+1]);
        }
    }
}

void bouleSortv1(int *array,int len){
    for(int i=1;i<len;i++) { // total de interações deve ser len-1
        for(int j=len-1;j>=i;j++){
            if(array[j]<array[j-1]) swap(&array[j],&array[j-1]);
        }
    }
}
