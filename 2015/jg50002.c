#include <stdio.h>
 
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int a[102][102]={0}; int prev[102][102]={0}; int count[102][102]={0};
    for (int i=1;i<n+1;i++){
        for (int j=1;j<n+1;j++){
            scanf("%d",&a[i][j]);
            prev[i][j] = a[i][j];
            if (a[i][j]==1) count[i][j]++;
        }
    }
    if (k!=0){
        for (int i=0;i<k;i++){
            for (int j=1;j<n+1;j++){
                for (int k=1;k<n+1;k++){
                    int live_neigh=prev[j-1][k-1]+prev[j-1][k]+prev[j-1][k+1]+prev[j][k-1]
                    +prev[j][k+1]+prev[j+1][k-1]+prev[j+1][k]+prev[j+1][k+1];
                    if (prev[j][k]==0){
                        if (live_neigh==3) a[j][k] = 1;
                    }
                    else if (prev[j][k]==1){
                        if (live_neigh==2 || live_neigh==3);
                        else a[j][k]=0;
                    }
                }
            }
 
            for (int j=1;j<n+1;j++){
                for (int k=1;k<n+1;k++){
                    prev[j][k]=a[j][k];
                    if (a[j][k]==1) count[j][k]++;
                }
            }
        }
    }
 
    for (int i =1;i<n+1;i++){
        for (int j=1;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("%d",a[i][n]);
        printf("\n");
    }
    int x=0,y=0,max=0;
    for (int i =1;i<n+1;i++){
        for (int j=1;j<n+1;j++){
            if (count[i][j]>=max){
                x=i; y=j; max=count[i][j];
            }
        }
    }
    printf("%d %d",x,y);
}