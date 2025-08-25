#include <stdio.h>

int main(){

    int len, contPrimo=0,control=0;

    scanf("%d",&len);
    int array[len];

    for(int i=0;i<len;i++){
        scanf(" %d",&array[i]);
        control=0;
        if(array[i]<2) control=1;
        
        else{
            for(int j=2;j <array[i]-1;j++){ //existem maneiras mais otimizadas como for(int j=2; j*j<=array[i];j++)
                if(array[i]%j==0){
                    control = 1;
                    break;
                }
            }
        }
        if(control==0) contPrimo++;
    }

    int arrayPrimo[contPrimo];
    int cont=0;

    for(int i=0;i<len;i++){
        control=0;
        if(array[i] < 2) control=1;
        
        else{
            for(int j=2;j<array[i]-1;j++){
                if(array[i]%j == 0){
                    control =1;
                     break;
                }
            }
        }

        if(control==0){
            arrayPrimo[cont]=array[i];
            cont++;
        }
    }

    for(int i=0;i<contPrimo;i++){
        printf("|%d|",arrayPrimo[i]);
    }
    
}