# include <stdio.h>
 
int gcd(int x, int y){
    while(x%y!=0){
        int temp = x%y;
        x=y; y=temp;
    }
    return y;
}
 
int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF){
        int factor = gcd(m,n);
        m/=factor; n/=factor;
        printf("%d / %d\n",m,n);
    }
}