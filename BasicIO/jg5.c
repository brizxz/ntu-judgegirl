# include <stdio.h>
 
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int volume= a*b*c;
    int surface= 2*a*b+2*c*b+2*a*c;
    printf("%d\n%d\n",surface,volume);
}