#include <stdio.h>
#include <string.h>
int cal(char a){
    return a-'a';
}
int min(int a, int b){
    if (a < b) return a;
    return b;
}
int judgeans(int a){
    for (int i=0; i<26; i++){
        if ((a>>i) &1 ==0) return 0;
    }
    return 1;
}

int calans(char arr[20][55],int loc,int judge,int minnum,int n){
    if (((judge))==67108863 && judge!=0 &&minnum!=0) return minnum;
    if (loc==n) return 1000000;
    int len = strlen(arr[loc]); int sum=0; int newjudge=judge;
    for (int i=0; i<len; i++){
        newjudge |= (1<<(cal(arr[loc][i])));
        sum +=(cal(arr[loc][i])+1);
    }
   // printf("%d\n",len);
    return min(calans(arr,loc+1,judge,minnum,n),calans(arr,loc+1,newjudge,minnum+sum,n)); 
}

int main(){
    int n; char arr[20][55]; 
    while(scanf("%d",&n)!=EOF) {
        for (int i=0; i<n; i++){
            scanf("%s",arr[i]);
        } 
        printf("%d\n",calans(arr,0,0,0,n));    
    }
}