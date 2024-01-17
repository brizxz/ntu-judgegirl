#include <stdio.h>
 
int main(){
    int n;
    int matrix[102][102]={0};
    scanf("%d",&n);
    for (int i=1; i<n+1; i++){
        for (int j=1; j<n+1; j++) scanf("%d",&matrix[i][j]);
    }
 
    int inter=0,T=0,turn=0,dead=0;
    for (int i=1; i<n+1; i++){
        for (int j=1; j<n+1; j++){
            if (matrix[i][j]==1){
                int total= 4-matrix[i+1][j]-matrix[i-1][j]-matrix[i][j+1]-matrix[i][j-1];
                if (total==0) inter++;
                else if (total==1) T++;
                else if (total==3) dead++;
                else if (total==2){
                    if (matrix[i][j+1]!=matrix[i][j-1] && matrix[i+1][j]!=matrix[i-1][j]) turn++;
                }
            }
        }
    }
    printf("%d\n%d\n%d\n%d\n",inter,T,turn,dead);
}