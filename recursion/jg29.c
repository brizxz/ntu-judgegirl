#include <stdio.h>
int cal(int r,int c){
    if (r==1 || c==1) return 1;
    return cal(r,c-1)+cal(r-1,c);
}
 
int main(){
    int r,c;
    scanf("%d%d",&r,&c);
    printf("%d\n",cal(r,c));
}