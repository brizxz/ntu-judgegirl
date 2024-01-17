#include <stdio.h>
 
int h(int n){
    if (n<2) return -1;
    return 2+h(n-1)-h(n-2);
}
int g(int z){
    if (z<=2) return z*z-1;
    return 2;
}
int f(int x){
    if (x>h(x)) return f(x-1)-h(x);
    else if (x<h(x)) return f(g(x))-g(x);
    return 1;
}
 
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",f(n));
}