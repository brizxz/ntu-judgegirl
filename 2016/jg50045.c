#include <stdio.h>
#include <math.h>
int d(int x1,int y1,int z1,int x2,int y2,int z2){
    return (abs(x1-x2)+abs(y1-y2)+abs(z1-z2));
}
 
int main(){
    int x0,y0,z0; int status=1;
    int dx[7]={1,-1,0,0,0,0}; int dy[7]={0,0,1,-1,0,0}; int dz[7]={0,0,0,0,1,-1};
    scanf("%d%d%d",&x0,&y0,&z0);
    int xm,ym,zm; int xb,yb,zb; // mine and black hole
    scanf("%d%d%d%d%d%d",&xm,&ym,&zm,&xb,&yb,&zb);
    int q; int instruction; int count=0;
    scanf("%d",&q);
    for (int i=0; i<q; i++){
        scanf("%d",&instruction); count++; 
        // 先進行位置的移動再判斷距離 remember qq
        x0+=dx[instruction-1]; y0+=dy[instruction-1]; z0+=dz[instruction-1];
        if (d(x0,y0,z0,xm,ym,zm)<10) break;
        else if (d(x0,y0,z0,xb,yb,zb)<10 && status==1){
            status=0; x0=xb; y0=yb; z0=zb;
        }
        if (count%5==0) printf("%d %d %d\n",x0,y0,z0);
    }
}