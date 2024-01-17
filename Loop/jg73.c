# include <stdio.h>
 
int main(){
    int n;
    scanf("%d",&n);
    int r0=0,r1=0,r2=0;
    int num;
    for (int i=0; i<n; i++){
        scanf("%d",&num);
        if (num%3==0) r0++;
        else if (num%3==1) r1++;
        else r2++;
    }
    printf("%d %d %d\n",r0,r1,r2);
}