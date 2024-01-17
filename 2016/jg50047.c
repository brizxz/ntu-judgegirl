#include "game_of_cell.h"
// 0 dead, 1 dying, 2 living
void game_of_cell(int grid[50][50],int outcome[50][50],int N){
    int new[52][52]={0};
    for (int i=1; i<51; i++){
        for (int j=1; j<51; j++) new[i][j]=grid[i-1][j-1];
    }
    while (N>0){
        N--;
        for (int j=1; j<51; j++){
            for (int k=1; k<51; k++){
                int healsum=((new[j+1][k+1]==2)+(new[j+1][k]==2)+(new[j+1][k-1]==2)+(new[j][k+1]==2)
                +(new[j][k-1]==2)+(new[j-1][k-1]==2)+(new[j-1][k]==2)+(new[j-1][k+1]==2));
                if (new[j][k]==0){
                    if (healsum==3) grid[j-1][k-1] = 2;
                } 
                else if (new[j][k]==1){
                    if (healsum==2) grid[j-1][k-1] = 2;
                } 
                else{
                    if (healsum<2) grid[j-1][k-1] = 0;
                    else if (healsum>3) grid[j-1][k-1] = 1;
                }
            }
        }
        for (int i=1; i<51; i++){
            for (int j=1; j<51; j++) new[i][j]=grid[i-1][j-1];
        }  
    }
    for (int i=1; i<51; i++){
        for (int j=1; j<51; j++) outcome[i-1][j-1]=new[i][j];
    }    
    return;
}