#include <stdio.h>
 
int gcd(int x, int y){
    if (x==0) return y;
    if (y==0) return x;
    while (x%y!=0){
        int temp=x%y;
        x=y; y=temp;
    }
    return y;
}
 
int main(){
    int ans[20][20][2]; int node[20][20][3]; // num,denum
    ans[0][0][1]=ans[0][0][0]=node[0][0][1]=node[0][0][0]=1;
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++){
        for (int j=0; j<i; j++){
            scanf("%d%d",&node[i][j][0],&node[i][j][1]);
            int pu=gcd(node[i][j][0],node[i][j][1]);
            node[i][j][0]/=pu; node[i][j][1]/=pu; // if not will overflow
        }
    }
    for (int i = 1; i <=n; i++){
        for (int j=0; j<=i; j++){
            if (j==0){
                ans[i][j][1]=(node[i][j][0]+node[i][j][1])*(ans[i-1][j][1]);
                ans[i][j][0]=(node[i][j][0])*(ans[i-1][j][0]);
                int k=gcd(ans[i][j][0],ans[i][j][1]);
                ans[i][j][0]/=k; ans[i][j][1]/=k;
            }
            else if (j==i){
                ans[i][j][1]=(node[i][j-1][0]+node[i][j-1][1])*(ans[i-1][j-1][1]);
                ans[i][j][0]=(node[i][j-1][1])*(ans[i-1][j-1][0]);
                int k=gcd(ans[i][j][0],ans[i][j][1]);
                ans[i][j][0]/=k; ans[i][j][1]/=k;          
            }
            else{
                int a=(node[i][j-1][0]+node[i][j-1][1])*(ans[i-1][j-1][1]);
                int b=(node[i][j-1][1])*(ans[i-1][j-1][0]);
                int c=(node[i][j][0]+node[i][j][1])*(ans[i-1][j][1]);
                int d=(node[i][j][0])*(ans[i-1][j][0]);
                // b/a + d/c
                int f1=gcd(a,b); int f2=gcd(c,d);
                a/=f1; b/=f1; c/=f2; d/=f2;
                int nnum=b*c+a*d; int ndenum=a*c;
                ans[i][j][0]=nnum; ans[i][j][1] = ndenum;
                int k=gcd(ans[i][j][0],ans[i][j][1]);
                ans[i][j][0]/=k; ans[i][j][1]/=k;
            }
        }
    }
 
    for (int i = 0; i <n+1; i++){
       printf("%d/%d\n",ans[n][i][0],ans[n][i][1]);
    }
}