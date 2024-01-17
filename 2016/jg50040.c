#include <stdio.h>
 
int main(){
    int m;
    scanf("%d",&m);
    int n=0;
    if (m>0 && m%2==0 && (m>10000 || m<1000)) n=1;
    printf("%d\n",n);
}