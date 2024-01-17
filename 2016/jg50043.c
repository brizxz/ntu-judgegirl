#include <stdio.h>
#define ll long long
int max(int a, int b, int c){
    if (a>=b && a>=c) return a;
    else if (b>=a && b>=c) return b;
    return c; 
}
int min(int a, int b, int c){
    if (a<=b && a<=c) return a;
    else if (b<=a && b<=c) return b;
    return c; 
}

int judge(int x, int y,int x1,int y1,int x2,int y2,int x3,int y3){
    ll int fx1 = x1-x; ll int fy1 = y1-y;ll int fx2 = x2-x;ll int fy2 = y2-y;ll int fx3 = x3-x;ll int fy3 = y3-y;
    ll int acrossb = fx1*fy2-fx2*fy1;ll int bcrossc = fx2*fy3-fx3*fy2;ll int ccrossa = fx3*fy1-fx1*fy3;
    if ((acrossb>=0 && bcrossc>=0 && ccrossa>=0) || (acrossb<=0 && bcrossc<=0 && ccrossa<=0)) return 1;
    return 0;
}

int main(){
    int x1,y1,x2,y2,x3,y3; int ans=0;
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    for (int i=min(x1,x2,x3); i<=max(x1,x2,x3); i++){
        for (int j=min(y1,y2,y3); j<=max(y1,y2,y3); j++){
            int a=judge(i,j,x1,y1,x2,y2,x3,y3); int b=judge(i+1,j,x1,y1,x2,y2,x3,y3);
            int c=judge(i,j+1,x1,y1,x2,y2,x3,y3); int d=judge(i+1,j+1,x1,y1,x2,y2,x3,y3);
            if (a==1 && b==1 && c==1 && d==1) ans++;
        }
    }
    printf("%d",ans);
}