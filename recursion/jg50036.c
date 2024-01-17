#include <stdio.h>
int cal(int arr[],int loc,int n,int k,int m,int picknum,int sum){
    if (loc==n) return picknum>=k && sum<=m; 
    return cal(arr,loc+1,n,k,m,picknum,sum) + cal(arr,loc+1,n,k,m,picknum+1,sum+arr[loc]);
}
 
 
int main(){
    int k,n,m;
    scanf("%d%d%d",&k,&n,&m);
    int arr[20];
    for (int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("%d\n",cal(arr,0,n,k,m,0,0));
}