#include <stdio.h>
 
int main(){
    int a,b,c,d,e,f,g;
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
    int result;
    if (d==0) printf("%d\n",0);
    else if (a*b==e*f){
        if (g>=c) printf("%d\n",0);
        else {
            result = d+g;
            printf("%d\n",(result>=c)?c:result);
        }
    }
    else{
        result= (g<c)? d + (e*f*g)/(a*b) : (a*b*d/(a*b-e*f));
        printf("%d\n",(result>=c)?c:result);
    }
}