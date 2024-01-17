#include <stdio.h>
 
int c(int x, int y){
    if (x==y || y==0) return 1;
    return c(x-1,y) + c(x-1,y-1);
}
 
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int ans = 0;
    for (int i=0; i<=b; i++) ans += c(a,i);
    printf("%d\n", ans);
}