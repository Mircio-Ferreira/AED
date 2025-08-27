#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int n_quadrado=n*n;
    int a[n_quadrado];
    for(int i=0;i<n_quadrado;i++){
        scanf("%d",&a[i]);
    }
    int b[n][n],cont=0;
    for(int i=0;i<n;i++){
        if(i==0 || i%2==0){
            for(int j=0;j<n;j++){
                b[i][j]=a[j+n*cont];
                //b[i][j]=a[(cont)];
            }
            cont++;
        }
        else if(i==1 || i%2==1){
            for(int j=n-1;j>=0;j--){
                //b[i][j]=a[(n-1-j)*cont];
                b[i][j]=a[cont*n + (n-1-j)];
                //b[i][j]=a[(cont)];
            }
            cont++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
