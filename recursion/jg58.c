#include <stdio.h>
#include <string.h>
void bubble(int arr[],int n){
    for (int i=n-2; i>=0; i--){
        for (int j=0; j<=i; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return;
}

int cal(int arr[402][402],int n,int m,int i,int j){
    if (arr[i][j]==-1 || arr[i][j]==0 ) return 0;
    arr[i][j] = -1;
    return 1+cal(arr,n,m,i,j)+cal(arr,n,m,i-1,j)+cal(arr,n,m,i+1,j)+cal(arr,n,m,i,j-1)+cal(arr,n,m,i,j+1);
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int arr[402][402]; int ans[80001]; int count = 0;
    memset(arr,-1,sizeof(arr));
    memset(ans,0,sizeof(ans));
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++) scanf("%d",&arr[i][j]);
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (arr[i][j]==1){
                int k=cal(arr,n,m,i,j);
                ans[count]=k;
                count++;
            }
        }
    }
    bubble(ans,count);
    for (int i = count-1; i>=0; i--) printf("%d\n",ans[i]);
}