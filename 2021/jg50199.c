#include <stdio.h>

void change(int m,int n,int a[502][502]){
    for (int i=1; i<m+1; i++){
        for (int j=1; j<n+1; j++){
            if (a[i][j]==0) continue;
            if (a[i][j]==a[i+1][j] && a[i][j]==a[i-1][j]) a[i][j] = a[i+1][j] = a[i-1][j] =0; 
            else if (a[i][j]==a[i][j-1] && a[i][j]==a[i][j+1]) a[i][j] = a[i][j+1] = a[i][j-1] =0;               
            else if (a[i][j]==a[i-1][j-1] && a[i][j]==a[i-1][j]) a[i][j] = a[i-1][j-1] = a[i-1][j] =0; 
            else if (a[i][j]==a[i-1][j-1] && a[i][j]==a[i][j-1]) a[i][j] = a[i-1][j-1] = a[i][j-1] =0;
            else if (a[i][j]==a[i+1][j-1] && a[i][j]==a[i+1][j]) a[i][j] = a[i+1][j-1] = a[i+1][j] =0; 
            else if (a[i][j]==a[i+1][j-1] && a[i][j]==a[i][j-1]) a[i][j] = a[i+1][j-1] = a[i][j-1] =0; 
            else if (a[i][j]==a[i-1][j+1] && a[i][j]==a[i][j+1]) a[i][j] = a[i-1][j+1] =a[i][j+1] =0; 
            else if (a[i][j]==a[i-1][j+1] && a[i][j]==a[i-1][j]) a[i][j] = a[i-1][j+1] = a[i-1][j] =0; 
            else if (a[i][j]==a[i+1][j+1] && a[i][j]==a[i][j+1]) a[i][j] = a[i+1][j+1] = a[i][j+1] =0; 
            else if (a[i][j]==a[i+1][j+1] && a[i][j]==a[i+1][j]) a[i][j] = a[i+1][j+1] = a[i+1][j] =0; 
        }
    }
}

int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int a[502][502]={0};
    for (int i=1; i<m+1; i++){
        for (int j=1; j<n+1; j++) scanf("%d",&a[i][j]);
    }
    change(m,n,a);
    for (int i=1; i<m+1; i++){
        for (int j=1; j<n+1; j++){
            if (j==1) printf("%d",a[i][1]);
            else printf(" %d",a[i][j]);
        }
        printf("\n");
    }
}