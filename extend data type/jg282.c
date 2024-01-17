# include<stdio.h>
#define ll long long
int consecutivebit(ll int n) {
    int count=0;
    for (int i=0; i<sizeof(ll int)*8; i++){
        if (n&1!=0){
            count++;
        }
        n>>=1;
    }
    return count;
}
 
int main(){
    ll int n;
    while(scanf("%lld",&n)!=EOF){
        printf("%d\n",consecutivebit(n));
    }
}