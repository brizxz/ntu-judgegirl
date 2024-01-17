#include <stdio.h>
 
int main(){
    int time,x,y; int prex=0,prey=0;
    while(scanf("%d%d%d",&time,&x,&y) != EOF){
        if (prex<time) prex=time; 
        prex+=x; 
        prey = (prey>prex) ?prey+y:prex+y;
        printf("%d\n",prey); 
    }
}