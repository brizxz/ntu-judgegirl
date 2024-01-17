#include <stdio.h>
 
int main(){
    int m,n;
    int matrix[101][101]={0};
    scanf("%d%d",&m,&n);
    for (int i=1; i<m+1; i++){
        for (int j=1; j<n+1; j++) scanf("%d",&matrix[i][j]);
    }
 
    for (int i=1; i<m+1; i++){
        for (int j=1; j<n+1; j++){
            if (matrix[i][j]>matrix[i+1][j] && matrix[i][j]>matrix[i-1][j] && matrix[i][j]>matrix[i][j+1] && matrix[i][j]>matrix[i][j-1] )
            printf("%d\n",matrix[i][j]);
        }
    }
}