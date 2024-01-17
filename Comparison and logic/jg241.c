# include <stdio.h>
 
int main(){
    int ax,ay,bx,by,cx,cy,dx,dy;
    scanf("%d%d%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
    int acrossb = ax*by-ay*bx;
    int bcrossc = bx*cy-by*cx;
    int ccrossd = cx*dy-cy*dx;
    int dcrossa = dx*ay-dy*ax;
    if (acrossb>0 && bcrossc>0 && ccrossd>0 && dcrossa>0) printf("%d\n",1);
    else printf("%d\n",0);
}
