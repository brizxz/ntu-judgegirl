#include <stdio.h>
#include <math.h>
int main(){
    int a[100][100][100]={0}; int store[100][100][100];
    int n,m,type,index; int count=0;
    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            for (int k=0; k<n; k++){
                a[i][j][k]=count; store[i][j][k]=a[i][j][k];
                count++;
            }
        }
    }
    for (int i=0; i<m; i++){
        scanf("%d%d",&type,&index);
        if (type==0){
            for (int j=0; j<n; j++){
                for (int k=0; k<n; k++){
                    store[index][j][k]=a[index][abs(n-1-k)][j]; 
                }
            }
        }
        else{
            for (int j=0; j<n; j++){
                for (int k=0; k<n; k++){
                    store[j][k][index]=a[abs(n-1-k)][j][index];
                }
            }            
        }
        for (int j=0; j<n; j++){
            for (int k=0; k<n; k++){
                for (int k2=0; k2<n; k2++) a[j][k][k2] = store[j][k][k2];
            }
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            for (int k=0; k<n; k++){
                if (k==0) printf("%d",a[i][j][k]);
                else printf(" %d",a[i][j][k]);
            }
            printf("\n");
        }
    }
}