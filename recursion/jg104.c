#include <stdio.h>
 
int cal(int da,int db,int dc,int ea,int eb,int ec,int fa,int fb,int fc,int a,int b,int c){
    if (a<0 || b<0 || c<0) return 0;
 
    if (a==0 && b==0 && c==0) return 1;
    return cal(da,db,dc,ea,eb,ec,fa,fb,fc,a-da,b-db,c-dc) || cal(da,db,dc,ea,eb,ec,fa,fb,fc,a-ea,b-eb,c-ec)
     || cal(da,db,dc,ea,eb,ec,fa,fb,fc,a-fa,b-fb,c-fc);
}
void judge(int da,int db,int dc,int ea,int eb,int ec,int fa,int fb,int fc,int n){
    if (n<=0) return;
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if (cal(da,db,dc,ea,eb,ec,fa,fb,fc,a,b,c)) printf("yes\n");
    else printf("no\n");   
    return judge(da,db,dc,ea,eb,ec,fa,fb,fc,n-1);
}
 
int main(){
    int da,db,dc;
    int ea,eb,ec;
    int fa,fb,fc;
    scanf("%d%d%d",&da,&db,&dc);
    scanf("%d%d%d",&ea,&eb,&ec);
    scanf("%d%d%d",&fa,&fb,&fc);
    int n;
    scanf("%d",&n);
    judge(da,db,dc,ea,eb,ec,fa,fb,fc,n);
}