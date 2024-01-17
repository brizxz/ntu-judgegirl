#include <stdio.h>
int max(int a, int b){
    return  (a > b)*a + (b>a)*b + (a==b)*a;
}
 
int cal(int wei[20],int val[20],int n,int w,int loc,int ans){
    if (loc==n){
        if (w<0) return 0;
        return ans;
    }
    return max(cal(wei,val,n,w,loc+1,ans),cal(wei,val,n,w-wei[loc],loc+1,ans+val[loc]));
}
 
int main(){
    int n,w;
    scanf("%d%d",&n,&w);
    int wei[20];int val[20];
    for (int i=0; i<n; i++){
        scanf("%d%d",&wei[i],&val[i]);
    }
    printf("%d\n",cal(wei,val,n,w,0,0));
}