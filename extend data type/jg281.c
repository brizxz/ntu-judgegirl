# include <stdio.h>
 
int numberbit(int n){
    int sum=0;
    for (int i=0; i<sizeof(int)*8 ; i++){
        if ((n&1)!=0) sum+=1;
        n>>=1;
    }
 
    return sum;
}
 
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%d\n", numberbit(n));
    }
}