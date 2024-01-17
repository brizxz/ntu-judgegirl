#include <stdio.h>
 
int main(){
    int k;
    scanf("%d",&k);
    int num;  int prev = 0; int start = 0; int ans=0;
    while(scanf("%d",&num)!=EOF){ 
        prev = prev*10+num;
        if (prev/k==0 && start==0) continue;
        start = 1;
        printf("%d\n",prev/k);
        prev = prev%k;
    }
    if (start==0) printf("%d\n",0);
}