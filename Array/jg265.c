#include <stdio.h>
 
int main(){
    int x,y;
    int lx=10001,ly=10001,rx=-10001,ry=-10001;
    while(scanf("%d%d",&x,&y)!=EOF){
        if (x<lx) lx=x;
        if (y<ly) ly=y;
        if (x>rx) rx=x;
        if (y>ry) ry=y;
    }
    printf("%d\n",(rx-lx)*(ry-ly));
}