#include <stdio.h>
int main(){
    int r,c;
    scanf("%d%d",&r,&c);
    int a[r][c];
    for(int i=0; i<r; i++) 
        for (int j=0; j<c; j++) scanf("%d",&a[i][j]);
    int type,size; int nowr=0; int nowc=c;
    while(scanf("%d%d",&type,&size)!=EOF){
        if (type==1){
            int k = nowr;
            for(int i=nowr+2*size-1; i>=nowr+size; i--){
                for(int j=0; j<nowc; j++) a[i][j]+=a[k][j];
                k++;
            }
            nowr+=size;
        }  // down
        else if (type==2){
            int k = nowc-1;
            for(int i=nowc-2*size; i<nowc-size; i++){ //
                for(int j=nowr; j<r; j++) a[j][i]+=a[j][k];
                k--;
            }
            nowc-=size;
        }
        else if (type==3){
            int k = nowc-size; ; int lx=nowc-size+1;
            for (int i=nowr+1; i<nowr+size; i++){  // 1-3
            int ly=nowr; // key
                for (int j=nowc-size; j<=k && j<nowc-1; j++){ // 2-2 2-3 2-4
                    a[i][j]+=a[ly][lx]; a[ly][lx]=0; ly++;
                }
                k++; lx++;
            }
        }
    }
    for (int i=nowr; i<r; i++){
        for (int j=0; j<nowc; j++){
            if (j==0) printf("%d",a[i][j]);
            else printf(" %d",a[i][j]);
        }
        printf("\n");
    }
}