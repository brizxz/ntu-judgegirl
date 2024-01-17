# include <stdio.h>
 
int main(){
    int s,f,t;
    scanf("%d%d%d",&s,&f,&t);
    int y= (f-8*s+6*t)/2;
    int z= s-t;
    int x= t-y;
    printf("%d\n%d\n%d\n",x,y,z);
}