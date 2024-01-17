#include <stdio.h>
#define ll long long
 
int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    int x1,y1,e1,n1,f1;
    scanf("%d%d%d%d%d", &x1, &y1, &e1, &n1, &f1);
    ll int x2,y2,e2,n2,f2;
    scanf("%lld%lld%lld%lld%lld", &x2, &y2, &e2, &n2, &f2);  
    int time=0; int count1=0; ll int count2=0;
    while(f1>0 || f2>0){
        time++; count1++; count2++;
        if (f1>0){
            if (count1<=n1) y1++;
            else if (count1<=n1+e1){
                x1++;
                if (count1 == n1+e1) count1=0;
            }
            f1--;
        }
        if (f2>0){ // testdata2 will overflow
            if (count2<=e2) x2++;
            else if (count2<=n2+e2){
                y2++;
                if (count2 == n2+e2) count2=0;
            }
            f2--;
        }
 
        if (x1==m) x1=0;
        else if (y1==n) y1=0;
        if (x2==m) x2=0;
        else if (y2==n) y2=0;
        if (x1==x2 && y1==y2) break;
    }
    if (x1==x2 && y1==y2) printf("robots explode at time %d\n",time);
    else printf("robots will not explode\n");
}