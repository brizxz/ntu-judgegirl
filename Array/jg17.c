#include <stdio.h>
 
int main(){
    int m,n;
    int matrix[101][101];
    scanf("%d%d",&m,&n);
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++) scanf("%d",&matrix[i][j]);
    }
    for (int i=0; i<n; i++){
        int sum=0;
        for (int j=0; j<m; j++) sum+=matrix[j][i];
        printf("%d\n",sum/m);
    }
 
}