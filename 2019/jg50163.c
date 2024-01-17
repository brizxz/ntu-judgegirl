#include <stdio.h>
int main(){
    int car; // 123 45
    scanf("%d",&car);
    int hr[car][20][5]={{{0}}};
    int req; int req1[3]={0,0,0}; int req2[3]={0,0,0}; // car,row,col;
    while(scanf("%d",&req)!=EOF){
        int find=0;
        if (req==1){
            for (int i=req1[0]; i<car; i++){
                if (find==1) break;
                for (int j=0; j<20; j++){
                    if (find==1) break;
                    for (int k=0; k<5; k++){
                        if (hr[i][j][k]==0){
                            printf("%d %d %d\n", i+1, j+1, k+1); find=1;
                            hr[i][j][k]=1; req1[0]=i; req1[1]=j; req1[2]=k; break;
                        }
                    }
                }
            }
        }
        else{
            for (int i=req2[0]; i<car; i++){
                if (find==1) break;
                for (int j=0; j<20; j++){
                    if ((hr[i][j][0]==0 && hr[i][j][1]==0)){
                        printf("%d %d %d %d %d %d\n", i+1, j+1,1,i+1,j+1,2);
                        hr[i][j][0]=1; hr[i][j][1]=1; find=1;
                        req2[0]=i; req2[1]=j; req2[2]=1; break;
                    }
                    else if ((hr[i][j][1]==0 && hr[i][j][2]==0)){
                        printf("%d %d %d %d %d %d\n", i+1, j+1,2,i+1,j+1,3);
                        hr[i][j][1]=1; hr[i][j][2]=1; find=1;
                        req2[0]=i; req2[1]=j; req2[2]=2; break;
                    }
                    else if ((hr[i][j][3]==0 && hr[i][j][4]==0)){
                        printf("%d %d %d %d %d %d\n", i+1, j+1,4,i+1,j+1,5);
                        hr[i][j][3]=1; hr[i][j][4]=1; find=1;
                        req2[0]=i; req2[1]=j; req2[2]=4; break;
                    }
                }
            }
            if (find==0){
                int count=0;
                for (int i=req1[0]; i<car; i++){
                    if (count==2) break;
                    for (int j=0; j<20; j++){
                        if (count==2) break;
                        for (int k=0; k<5; k++){
                            if (count==2) break;
                            if (hr[i][j][k]==0 && count==0){
                                printf("%d %d %d",i+1, j+1, k+1);
                                hr[i][j][k]=1; req1[0]=i; req1[1]=j; req1[2]=k; count++;
                            }
                            else if (hr[i][j][k]==0 && count==1){
                                printf(" %d %d %d\n",i+1, j+1, k+1);
                                hr[i][j][k]=1; req1[0]=i; req1[1]=j; req1[2]=k; count++;                               
                            }
                        }
                    }
                }
            }           
        }
      //  printf("k %d %d %d\n",req1[0],req1[1],req1[2]);
    }
}