#include <stdio.h>

int main(){
    int r,c; int ans=0;
    scanf("%d%d",&r,&c);
    int arr[r][c]; // change to r,c 
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++) scanf("%d",&arr[i][j]);
    }

    for (int i=1; i<r-1; i++){
        for (int j=3; j<=c-1; j++){ 
            if (arr[i][j]+arr[i][j-2]!=7 || arr[i][j-1]+arr[i][j-3]!=7) continue;
            int judge[7]={0,0,0,0,0,0,0};
            judge[arr[i][j]]++; judge[arr[i][j-1]]++; judge[arr[i][j-2]]++; judge[arr[i][j-3]]++;
            for (int k=0; k<4; k++){
                for (int l=0; l<4; l++){
                    if (arr[i-1][j-k]+arr[i+1][j-l]!=7) continue;
                    judge[arr[i-1][j-k]]++; judge[arr[i+1][j-l]]++;
                    if (judge[1]==1 && judge[2]==1 && judge[3]==1 && judge[4]==1 && judge[5]==1 && judge[6]==1) ans++;
                    judge[arr[i-1][j-k]]--; judge[arr[i+1][j-l]]--;
                }
            }
        }
    }
    printf("%d",ans);
}