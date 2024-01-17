#include <stdio.h>

int main(){
    int h,w;
    scanf("%d%d",&h,&w);
    int board[500][500]= {0};
    int type,col,row;
    while(scanf("%d%d%d",&type,&col,&row)!= EOF){
        int x=row; int y=col; int r1=1,r2=1,c1=1,c2=1;
        if (type==0) board[row][col] = 1;
        else if (type==1){
            board[row][col] = 1;
            while (board[row+r1][col+c1]!=1 && row+r1<h && col+c1<w){
                board[row+r1][col+c1] = 1; r1++; c1++; 
            }
            r1=1; c1=1;
            while (board[row-r1][col-c1]!=1 && row-r1>=0 && col-c1>=0){
                board[row-r1][col-c1] = 1; r1++; c1 ++;
            }
            r1=1; c1=1;
            while (board[row-r1][col+c1]!=1 && col+c1<w && row-r1>=0){
                board[row-r1][col+c1] = 1; c1++; r1++;
            }
            r1 = 1; c1 =1;
            while (board[row+r1][col-c1] !=1 && col-c1>=0 && row+r1<h){
                board[row+r1][col-c1] = 1; c1++; r1++;
            }             
            r1=1; c1=1; 
            while (board[row+r1][col]!=1 && row+r1<h){
                board[row+r1][col] = 1; r1++;
            } 
            while (board[row-r2][col]!=1 && row-r2>=0){
                board[row-r2][col] = 1; r2++;
            }
            while (board[row][col+c1]!=1 && col+c1<w){
                board[row][col+c1] = 1; c1++;
            }
            while (board[row][col-c2] !=1 && col-c2>=0){
                board[row][col-c2] = 1; c2++;
            }
        }
        else if (type==2){
            board[row][col] = 1;
            while (board[row+r1][col+c1]!=1 && row+r1<h && col+c1<w){
                board[row+r1][col+c1] = 1; r1++; c1++; 
            }
            r1=1; c1=1;
            while (board[row-r1][col-c1]!=1 && row-r1>=0 && col-c1>=0){
                board[row-r1][col-c1] = 1; r1++; c1 ++;
            }
            r1=1; c1=1;
            while (board[row-r1][col+c1]!=1 && col+c1<w && row-r1>=0){
                board[row-r1][col+c1] = 1; c1++; r1++;
            }
            r1 = 1; c1 =1;
            while (board[row+r1][col-c1] !=1 && col-c1>=0 && row+r1<h){
                board[row+r1][col-c1] = 1; c1++; r1++;
            }            
        }
        else if (type==3){
            board[row][col] = 1;
            while (board[row+r1][col]!=1 && row+r1<h){
                board[row+r1][col] = 1; r1++;
            } 
            while (board[row-r2][col]!=1 && row-r2>=0){
                board[row-r2][col] = 1; r2++;
            }
            while (board[row][col+c1]!=1 && col+c1<w){
                board[row][col+c1] = 1; c1++;
            }
            while (board[row][col-c2] !=1 && col-c2>=0){
                board[row][col-c2] = 1; c2++;
            }
        }
    }

    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            if (j==0) printf("%d",board[i][j]);
            else printf(" %d",board[i][j]);
        }
        printf("\n");
    }
}