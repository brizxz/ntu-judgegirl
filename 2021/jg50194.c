# include <stdio.h>
 
int count(int x ){
    int counts=0;
    while(x!=0){
        x/=10;
        counts++;
    }
    return counts;
}
 
int main(){
    int k; int L;
    scanf("%d%d", &k, &L);
    int n; int rest=0;
    while(scanf("%d", &n)!=EOF){
        if (n==0) break;
        int times= n%k;
        if (times*count(n)>L) continue;
 
        if ((rest+times*count(n))>L){
            printf("\n"); rest=0;
        }
        for (int i=0; i<times; i++) printf("%d",n);
        rest+=times*count(n);
    }
    printf("\n");
}