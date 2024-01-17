#include <stdio.h>
 
int abs(int x){
    if (x < 0) return -x;
    return x;
}
 
int second(int x){
    int a= 3600*(x/10000)+(x%100);
    x%=10000;
    a+= 60*(x/100);
    return a;
}
 
int main(){
    int time; int min=100000; int status=0;
    scanf("%d", &time);
    int prev=time;
    while (scanf("%d", &time)!=EOF){
        if (abs(second(time)-second(prev))<min) min = abs(second(time)-second(prev)); 
        prev=time;
    }
 
    printf("%d\n",min);
}