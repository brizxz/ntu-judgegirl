#include <stdio.h>
int judge(int x){
    int num[11]={0};
    int count=0;
    while(x!=0){
        num[x%10]++;
        x/=10;
    }
    for (int i=0; i<10; i++){
        if (num[i]>0) count++;
    }
    if (count>2) return 0;
    return 1;
}
 
int main(){
    int a,b,x;
    while(scanf("%d%d%d", &a, &b, &x)!=EOF){
        while (judge(x)==0) x=((a%b)*(x%b)%b);
        printf("%d\n",x);
    }
}