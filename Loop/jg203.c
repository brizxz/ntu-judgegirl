#include <stdio.h>
 
int main(){
    int X,Y,x1,y1,x2,y2,dx1,dy1,dx2,dy2,time;
    scanf("%d%d",&X,&Y);
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    scanf("%d%d%d%d%d",&dx1,&dy1,&dx2,&dy2,&time);
    while(time>0){
        x1+=dx1; y1+=dy1; x2+=dx2; y2+=dy2;
        if (x1==1 || x1==X) dx1=-dx1;
        if (x2==1 || x2==X) dx2=-dx2;
        if (y1==1 || y1==Y) dy1=-dy1;
        if (y2==1 || y2==Y) dy2=-dy2;
 
        if (x1==x2 && y1==y2){
            int temp = dx1; dx1=dx2; dx2=temp;
            temp = dy1; dy1=dy2; dy2=temp;
        }
        time--;
    }
 
    printf("%d\n%d\n%d\n%d\n",x1,y1,x2,y2);
}