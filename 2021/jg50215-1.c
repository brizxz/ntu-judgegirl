#include <stdio.h>
#include <string.h>
#include <stdint.h>
int cal(char c){
    return c-'a'+1;
}
int min(int a, int b){
    if (a < b) return a;
    return b;
}
int res(char str[20][55],int loc,int judge,int n){
    if (judge==(1<<26)-1 ) return 0;
    if (loc==n) return 1000000;
    int len = strlen(str[loc]); int sum=0; int newjudge=judge;
    for (int i=0;i<len;i++){
        sum += cal(str[loc][i]);
        newjudge |= (1<<(cal(str[loc][i])-1));
    }
    return min(res(str,loc+1,judge,n),sum+res(str,loc+1,newjudge,n));
}

int main(){
    char str[20][55]; int n;
    while (scanf("%d",&n)!=EOF){
        for (int i=0; i<n; i++){
            scanf("%s",str[i]);
        }
        printf("%d\n",res(str,0, 0,n));
    }
}