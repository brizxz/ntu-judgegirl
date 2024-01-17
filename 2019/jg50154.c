#include <stdio.h>
 
int main(){
    int a,b,c,d,e,f,g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
    int edge = (a+b+c+d) + (a+b+c)*e + (c+d)*f + e*g + (f+g); 
    int path = (a+b+c)*e*g + (c+d)*f;
    printf("%d\n%d\n",edge, path); 
}