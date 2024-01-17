#include <stdio.h>

int judge(int arr[6][6]){
    int sum=1;
    for (int i=1; i<5; i++){
        for (int j=1; j<5; j++){
            if (i==4 && j==4){
                if (arr[i][j]!=0) return 0;
            }
            else if (arr[i][j]!=sum) return 0;
            sum++;
        }
    }
    return 1;
}

int main(){
    int x,y;
    int move[6][6]={0};
    for (int i=1; i<5; i++){
        for (int j=1; j<5; j++){
            scanf("%d",&move[i][j]);
            if (move[i][j]==0){
                x=i; y=j;
            } 
        } 
    }
    int status=0; int step;
    while (scanf("%d",&step)!=EOF){
        if (step==0) break;
        if (move[x+1][y]!=step && move[x-1][y]!=step && move[x][y-1]!=step && move[x][y+1]!=step) continue;
        if (move[x+1][y]==step){
            move[x+1][y]=0; move[x][y]=step; x+=1;   
        }
        else if (move[x-1][y]==step){
            move[x-1][y]=0; move[x][y]=step; x-=1;   
        }
        else if (move[x][y+1]==step){
            move[x][y+1]=0; move[x][y]=step; y+=1;   
        }
        else if (move[x][y-1]==step){
            move[x][y-1]=0; move[x][y]=step; y-=1;   
        }

        if (judge(move)==1){
            status = 1; break;
        }
    }  

    for (int i=1; i<5; i++){
        for (int j=1; j<5; j++){
            if (j==1) printf("%d",move[i][j]);
            else printf(" %d",move[i][j]);
        }
        printf("\n");
    }    
    if (status==0) printf("%d",0);
    else printf("%d %d",1,step);
}