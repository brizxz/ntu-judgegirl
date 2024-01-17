# include <stdio.h>
 
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int c1000=0,c500=0,c100=0,c50=0,c10=0,c5=0,c1=0;
        c1000+= (n/1000); n%=1000;
        c500+= (n/500); n%=500;
        c100+= (n/100); n%=100;
        c50+= (n/50); n%=50;
        c10+= (n/10); n%=10;
        c5+= (n/5); n%=5;
        c1+=n; 
 
        printf("%d %d %d %d %d %d %d\n", c1000, c500, c100, c50, c10, c5, c1);
    }
}