#include <stdio.h>
 
int minmulti(int x, int y){
    int prevx=x; int prevy=y;
    if (x<y){
        int temp = x;
        x=y; y=temp;
    }
    while(x%y!=0){
        int temp = x%y;
        x=y;
        y=temp;
    }
    return prevx*prevy/y;
}
 
int main(){
    int num; int result=1;
    while(scanf("%d", &num)!=EOF){
        result=minmulti(result, num);
    }
    printf("%d\n", result);
}