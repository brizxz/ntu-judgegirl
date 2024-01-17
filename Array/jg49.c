#include <stdio.h>
 
int main(){
    int N; int m;
    scanf("%d%d",&N,&m);
    int num; int sum[1001]={0}; int max[1001]={0}; int min[1001]={0}; int count[1001]={0};
    for (int i=0; i<N; i++){
        scanf("%d",&num);
        int remainder = num%m;
        sum[remainder]+=num;
        if (num>max[remainder]) max[remainder] = num;
        if (num<min[remainder] || (min[remainder]==0 && count[remainder]==0)) min[remainder] = num;
        count[remainder]++;
    }
    for (int i=0; i<m; i++){
        printf("%d %d %d\n",sum[i],max[i],min[i]);
    }
}