#include <stdio.h>
int min(int a, int b){
    if (a <= b) return a;
    return b;
}
int max(int a, int b){
    if (a > b) return a;
    return b;
}
int main(){
    int acap,bcap,r;
    scanf("%d%d%d",&acap,&bcap,&r);
    int ball;
    while(scanf("%d",&ball)!=EOF){
        if (r==0){
            if (acap-ball>=0) acap-=ball;
            else if (bcap-ball>=0) bcap-=ball;
        }
        else{
            if (min(acap,bcap)-ball>=0){
                if (acap==min(acap,bcap)) acap-=ball;
                else bcap-=ball;
            }
            else{
                if (max(acap,bcap)-ball>=0){
                    if (acap==max(acap,bcap)) acap-=ball;
                    else bcap-=ball;
                }
            }
        }
        printf("%d %d\n",acap,bcap);
    } 
}