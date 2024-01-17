# include <stdio.h>
 
int sum(int a,int result){
    if (a==0) return result;
    result+=a*a;
    return sum(a-1,result);
}
 
int main(){
    int n; int result=0;
    scanf("%d",&n);
    printf("%d",sum(n,result));
}