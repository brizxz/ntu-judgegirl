#include <stdio.h>

int main(){
    int n,req;
    scanf("%d",&n);
    int a[n][20][5],C=n*100; // use total *seat* as number
    for(int i=0;i<n;i++){
        for(int j=0;j<20;j++){
            for(int k=0;k<5;k++){
                a[i][j][k]=0;
            }
        }
    }
    int cnt1=-1,cnt2=-1,spl=0;
    while(scanf("%d",&req)!=EOF){
        if(req==1){
            for(int i=cnt1+1;i<C;i++){ // by the method O(N)
                if(a[i/100][(i%100)/5][i%5]==0){
                    printf("%d %d %d\n",i/100+1,(i%100)/5+1,i%5+1);
                    a[i/100][(i%100)/5][i%5]=1; cnt1=i;
                    if(cnt1>cnt2) cnt2=cnt1; 
                    break;
                }
            }
        }
        if(req==2){
            spl=0;
            for(int i=cnt2+1;i<C;i++){
                if(i%5 == 2 || i%5 == 4) continue;
                else if(a[i/100][(i%100)/5][i%5]==0 && a[i/100][(i%100)/5][(i+1)%5]==0){
                    printf("%d %d %d %d %d %d\n",i/100+1,(i%100)/5+1,i%5+1,i/100+1,(i%100)/5+1,(i+1)%5+1);
                    a[i/100][(i%100)/5][i%5]=1; a[i/100][(i%100)/5][(i+1)%5]=1;
                    cnt2=i+1; spl=1;
                    break;
                }
            }
            if(spl==0){
                cnt2=C;
                for(int i=cnt1+1;i<C;i++){
                    if(a[i/100][(i%100)/5][i%5]==0){
                        if(req==2) printf("%d %d %d ",i/100+1,(i%100)/5+1,i%5+1);
                        else printf("%d %d %d\n",i/100+1,(i%100)/5+1,i%5+1);
                        a[i/100][(i%100)/5][i%5]=1;
                        cnt1=i; req--;
                        if(req==0) break;
                    }
                }
            }
        }
    }
    return 0;
}