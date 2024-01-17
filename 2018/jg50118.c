#include <stdio.h>
#include <math.h>
 
int count(int i){
    int count = 0;
    while (i!=0){
        count++;
        i/=10;
    }
    return count;
}
 
int main(){
    int num; int prev; int ans = 0; int now = 0;
    while(scanf("%d",&num)!=EOF){
        int a=count(num); int b=num;
        while (num/10!=0) num/=10;
        if (prev%10 == num){
            now+=a;
        }
        else{
            now=a;
        }
        if (now>ans) ans=now;
        prev=b;
    }
    printf("%d\n",ans);
}