#include <stdio.h> 
#include <stdint.h>
int dis(uint64_t a, uint64_t b){
    int sum=0; uint64_t k=1; 
    for (int i =0; i<8; i++){
        if ( (a>>i)&k-(b>>i)&k!=0 || ((b>>i)&k -(a>>i)&k!=0)){
            sum++;  
        }
    }
    return sum;
}

int main(){
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    uint64_t k[4];
    uint64_t valid[24];
    for (int i=0; i<m; i++) scanf("%lu",&k[i]);
    for (int i=0; i<n; i++){
        int r = i/8; int col = i%8;
        valid[i] = (k[r]>>(56-8*col))&(0x00000000000000ff);
    }
    unsigned char uc;
    uint64_t ans[256];
    for (int i=0; i<p; i++){
        scanf("%hhu", &uc);
        uint64_t judge = (uint64_t)uc;
        ans[i]= judge;
    }
    for (int i=0; i<p; i++){
        for (int j=0; j<n; j++){
            int d = dis(ans[i],valid[j]);
            if (d==0 || d==1) printf("%lu\n",valid[j]);
        }
    }
}