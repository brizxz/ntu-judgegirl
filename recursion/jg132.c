#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void cal(int pair[100][2],int country[20],int n,int c,int p,int loc,int kk){
    if (loc==n){
        int find = 0;
        for (int i=0; i<n; i++){
            find=1;
            printf("%d\n",country[i]);
        } 
        kk=1;
        exit(0);
    } 
    for (int i=1;i<=c; i++){
        bool k=false;
        country[loc]=i;
        for (int j=0; j<p && !k; j++){
            if (pair[j][0]>loc || pair[j][1]>loc) continue;
            if (country[pair[j][0]]==country[pair[j][1]] && country[pair[j][1]]!=0){
                k=true; 
            } 
        }
        if (!k){
            cal(pair,country,n,c,p,loc+1,kk);
        }
    }
}
 
int main(){
    int n,c,p; int pair[100][2]; int color[10]; int country[20]={0}; 
    scanf("%d%d%d",&n,&c,&p);
    for (int i=0; i<p; i++){
        scanf("%d%d",&pair[i][0],&pair[i][1]);
    }
    int kk=0;
    cal(pair,country,n,c,p,0,kk);
    if (kk==0) printf("no solution.\n");
 
}