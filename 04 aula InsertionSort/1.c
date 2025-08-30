#include <stdio.h>

void insertionSort(int len,int *array){
    for(int i=1;i<len;i++){
        int posi=i;
        //posi poderia ser >0
        while(posi!=0 && array[posi]<array[posi-1]){
            int temp=array[posi];
            array[posi]=array[posi-1];
            array[posi-1]=temp;
            posi--;
        }
    }
}

int main(){
    
    int len=10;
    int array[]={6,5,9,1,0,2,8,3,9,10};

    for(int i=0;i<len;i++){
        printf("|%d|",array[i]);
    }
    printf("\n");
    insertionSort(len,array);

     for(int i=0;i<len;i++){
        printf("|%d|",array[i]);
    }

    return 0;
}