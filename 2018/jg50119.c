#include <stdio.h>

int main(){
    int x0,a,b,c; // (a*x0+b) modc
    scanf("%d%d%d%d",&x0,&a,&b,&c);
    int y0,d,e,f; 
    scanf("%d%d%d%d", &y0,&d,&e,&f);
    int r;
    scanf("%d",&r); // 0 paper 1 scissor 2 stone
    for (int i=0; i<r; i++){
        int win=2; int count=0;
        while (win==2){ 
            int xs = x0%3; int ys = y0%3;
            x0 = (a*x0 + b)%c;  y0 = (d*y0 + e)%f;
            if ((xs==2 && ys==1) || (xs==1 && ys==0) || (xs==0 && ys==2)) win=0;
            else if  ((xs==1 && ys==2) || (xs==0 && ys==1) || (xs==2 && ys==0)) win=1;
            count++;
        }
        printf("%d %d\n",win,count);
    }
}