# include <stdio.h>
int main(){
    int a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e) ;
    int surface = (2*a*b+2*b*c+2*a*c) + (a+b+c-6*e)*d*8 ;
    int volume = a*b*c - 2*d*((a-2*e)*(b-2*e)+(a-2*e)*(c-2*e)+(c-2*e)*(b-2*e)) ;
    printf("%d\n", surface);
    printf("%d\n", volume);
 
}