# include<stdio.h>
 
int consecutivebit(int n) {
    int max=0; int count=0;
    for (int i=0; i<sizeof(int)*8; i++){
        if (n&1!=0){
            count++;
            if (count>max) max=count;
        }
        else count=0;
        n>>=1;
    }
    return max;
}
 
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",consecutivebit(n));
    }
}