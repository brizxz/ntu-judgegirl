#include <stdio.h>
int main(){
    int n,m; int dr[5]={0,0,1,0,-1}; int dc[5]={0,1,0,-1,0};
    scanf("%d%d",&n,&m);
    int arr[500][500]={{0}}; int pr,pc,pe;
    scanf("%d%d%d",&pr,&pc,&pe);
    arr[pr][pc]=pe;
    int kb; int instru;
    scanf("%d",&kb);
        int kr,kc,kw;
    for (int i=0; i<kb; i++){
        scanf("%d%d%d",&kr,&kc,&kw);
        arr[kr][kc]=kw;
    }
    while(scanf("%d",&instru)!=EOF){
        if (instru==0){
            for (int i=0; i<n; i++){
                for (int j=0; j<m; j++){
                    if (j==0) printf("%d",arr[i][j]);
                    else printf(" %d",arr[i][j]);
                }
                printf("\n");
            }
        }
        else{ //  (0,1) (1,0) (0,-1) (-1,0)
            if (pr+dr[instru]<0 || pr+dr[instru]>=n || pc+dc[instru]<0 || pc+dc[instru]>=m) continue;
            int sum=0; int nr,nc; nr=pr; nc=pc;
            if (instru==1 || instru==3){
                while(arr[pr][nc+dc[instru]]!=0 && (nc+dc[instru]>0 && nc+dc[instru]<m-1)){
                    sum+=arr[pr][nc+dc[instru]];
                    nc+=dc[instru];
                }
                if ((arr[pr][nc+dc[instru]]!=0 && (nc+dc[instru]<=0 || nc+dc[instru]>=m-1)) || arr[pr][pc]<sum) continue;
                arr[pr][pc]-=sum;

                if (nc>pc){
                    for (int i=nc+1; i>pc; i--) arr[pr][i]=arr[pr][i-1];
                    pc+=1; arr[pr][pc-1]=0;
                }
                else if (nc<pc){
                    for (int i=nc-1; i<pc; i++) arr[pr][i]=arr[pr][i+1];
                    pc-=1; arr[pr][pc+1]=0;
                }
                if (sum==0){
                    arr[pr][pc+dc[instru]]=arr[pr][pc]; arr[pr][pc]=0;
                    pc+=dc[instru];
                } 
            }
            else{
                while(arr[nr+dr[instru]][pc]!=0 && (nr+dr[instru]>0 && nr+dr[instru]<n-1)){
                    sum+=arr[nr+dr[instru]][pc];
                    nr+=dr[instru];
                }
                if ((arr[nr+dr[instru]][pc]!=0 && (nr+dr[instru]<=0 || nr+dr[instru]>=n-1)) || arr[pr][pc]<sum) continue;
                arr[pr][pc]-=sum;
                if (nr>pr){
                    for (int i=nr+1; i>pr; i--) arr[i][pc]=arr[i-1][pc];
                    pr+=1; arr[pr-1][pc]=0;
                }
                else if (nr<pr){
                    for (int i=nr-1; i<pr; i++) arr[i][pc]=arr[i+1][pc];
                    pr-=1; arr[pr+1][pc]=0;
                }
                if (sum==0){
                    arr[pr+dr[instru]][pc]=arr[pr][pc]; arr[pr][pc]=0;
                    pr+=dr[instru];
                } 
            }
        }
    }
}