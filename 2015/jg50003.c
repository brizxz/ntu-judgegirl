#include <stdio.h>
#include <math.h>

int min(int a,int b){
  if (a<b) return a;
  return b;
}

int main(){
    int l,x,y;
    scanf("%d%d%d",&l,&x,&y);
    int ans[100][100]={0};
    for (int i=0;i<l;i++){
        int n; int testx, testy; int prevx,prevy; int count=1;
        scanf("%d",&n); scanf("%d%d",&prevx,&prevy);
        if (prevx<0 || prevy<0 || prevx>=y ||prevy>=x){
            printf("ERROR %d %d",i+1,1); return 0;
        }
        for (int j=0; j<n-1; j++){
            scanf("%d%d",&testx,&testy); int oops=0;
            if (testx<0 || testy<0 || testx>=y || testy>=x || (abs(testx-prevx)!=abs(testy-prevy)&& testx!=prevx && testy!=prevy )){
                printf("ERROR %d %d",i+1,j+2); return 0;
            }
            if (testx==prevx){
                for (int k=(prevy>testy)?testy:prevy; k<=min(prevy,testy)+abs(prevy-testy); k++) ans[k][testx]=1;
            }
            else if (testy==prevy){
                for (int k=(prevx>testx)?testx:prevx; k<=min(prevx,testx)+abs(prevx-testx); k++){
                  ans[testy][k]=1; 
                } 
            }
            else if (abs(testx-prevx)==abs(testy-prevy)){
                if (testx-prevx!=testy-prevy){
                    for (int k=(prevy>testy)?testy:prevy; k<=min(prevy,testy)+abs(prevy-testy); k++){
                        ans[k][min(prevx,testx)+abs(prevx-testx)-oops]=1; oops++;
                    }
                }
                else{
                    for (int k=(prevy>testy)?testy:prevy; k<=min(prevy,testy)+abs(prevy-testy); k++){
                        ans[k][min(prevx,testx)+oops]=1; oops++;
                    } 
                }
            }
            prevx=testx; prevy=testy;
        }
        
    }
    for (int i=x-1; i>=0; i--){
        for (int j=0; j<y; j++){
            printf("%d",ans[i][j]);
        }
        printf("\n");
    }
}