#include <stdio.h>
 
int abs(int x){
    if (x < 0) return -x;
    return x;
}
 
int main(){
    int ax,ay,bx,by,cx,cy,dx,dy;
    scanf("%d%d%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
    int peri= 2*(cx-ax)+2*(cy-ay); 
    int area= (cx-ax)*(cy-ay) - (dx-ax)*(cy-dy) - (by-ay)*(cx-bx);
    printf("%d\n%d\n",peri,area);
}