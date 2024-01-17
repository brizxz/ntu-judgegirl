#include <stdio.h>

int cal(int m[202][202],int i,int j,int k){
    int sum=0; int count=1; int countdir=0;
    int dx[4]={1,1,-1,-1}; int dy[4]={1,-1,-1,1};
    while(count<=(k-1)*4){
        sum+=m[i][j-k+1]; i+=dy[countdir]; j+=dx[countdir];
        if (count%(k-1)==0 && count!=0) countdir++; 
        count++;
    }
    return sum;
}

int main(){
    int h,w,k; int m[202][202]={0}; int max=0;
    scanf("%d%d%d",&h,&w,&k);
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++) scanf("%d",&m[i][j]);
    }

    for (int i=k-1; i<=h-k; i++){
        for (int j=k-1; j<=w-k; j++) if (cal(m,i,j,k)>max) max=cal(m,i,j,k);
    }
    printf("%d",max);
}