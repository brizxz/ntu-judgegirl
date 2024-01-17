#include <stdio.h>
int cal(int arr[20],int sum,int q,int p,int n){
    if (sum==q) return 1;
    if (sum>q || p>=n) return 0;
    return cal(arr,sum+arr[p],q,p+1,n) + cal(arr,sum,q,p+1,n);
}
 
int main(){
    int n;
    scanf("%d", &n);
    int arr[20];
    for (int i=0; i< n; i++) scanf("%d", &arr[i]);
    int sum=0; int p=0;
    int q;
    while (scanf("%d", &q)!=EOF){
        sum=0;
        printf("%d\n",cal(arr,sum,q,p,n));
    }
}