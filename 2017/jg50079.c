#include <stdio.h>
 
int main(){
    int a,b;
    scanf("%d%d", &a,&b);
    int sum=0;
    for (int i=a; i<=b; i++) sum+=i;
    int side= a+b+(b-a-1)*2;
    printf("%d\n%d\n",sum,side);
}