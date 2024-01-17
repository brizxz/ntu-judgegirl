#include <stdio.h>
int cal(int d,int a,int b,int c,int al,int bl,int cl,int o){
    if ( a<0 || b<0 || c<0 || o<0 || o>d) return 0;
    if (o == d){
        return 1;
    } 
    // or 才不會TLE
    return (cal(d,a-1,b,c,al,bl,cl,o+al)) || (cal(d,a,b-1,c,al,bl,cl,o+bl))  || (cal(d,a,b,c-1,al,bl,cl,o+cl));
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int d,a,b,c,al,bl,cl; 
        scanf("%d%d%d%d%d%d%d",&d,&a,&b,&c,&al,&bl,&cl);
        int k=cal(d,a,b,c,al,bl,cl,0);
        if (k==0){
            printf("no\n");
        }
        else   printf("yes\n");
    }
}