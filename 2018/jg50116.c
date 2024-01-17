#include <stdio.h>
 
int abs(int x){
    if (x < 0) return -x;
    return x;
}
 
int main(){
    int digits; int count=0; int sumeven=0; int sumodd=0; 
    int count0=0; int prev;
    while(scanf("%d", &digits)!=EOF){
        if (count%2==0) sumeven+=digits;
        else sumodd += digits;
        if (digits==0) count0++;
 
        prev = digits;
        count++;
    }
    printf("%d\n%d\n%d\n%d\n",count,(prev%2==0)?1:0,count0,((abs(sumodd-sumeven)%11)==0)?1:0);
}