#include <stdio.h>
 
int abs(int x) {
    if (x < 0) return -x;
    return x;
}
 
int judge(int c, int d,int num,int denum){
    if (denum*c>d*num) return 1;
    return 0;
}
 
int main(){
    int a,b,v,w,x,y,z;
    scanf("%d%d%d%d%d%d%d",&a,&b,&v,&w,&x,&y,&z);
    int choice=1;
    int maxnum = 1; int maxdenum = 100000; 
    for (int i=a; i<100; i++) {
        if (i<b && i>=a){
            if (i%2==1){
                int c=v;
                if (judge(c,i,maxnum,maxdenum)==1){
                    maxnum=c; maxdenum=i; choice=i;
                }
            }
            else{
                int c=w;
                if (judge(c,i,maxnum,maxdenum)==1){
                    maxnum=c; maxdenum=i; choice=i;
                }
            }
        }
        else{
            if (i%3==0){
                int c=x;
                if (judge(c,i,maxnum,maxdenum)==1){
                    maxnum=c; maxdenum=i; choice=i;
                }
            }
            else if (i%3==1){
                int c=y;
                if (judge(c,i,maxnum,maxdenum)==1){
                    maxnum=c; maxdenum=i; choice=i;
                }
            }
            else{
                int c=z;
                if (judge(c,i,maxnum,maxdenum)==1){
                    maxnum=c; maxdenum=i; choice=i;
                }
            }
        }
    }
    printf("%d\n",choice);
}