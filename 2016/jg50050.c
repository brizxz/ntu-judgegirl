#include <stdio.h>
#ifndef SPIRALSNAKE_H_INCLUDED
#define SPIRALSNAKE_H_INCLUDED
void SpiralSnake(int N, int *snake, int *result){
    int arr[N][N];
    int drow[4]={0,-1,0,1};
    int dcol[4]={-1,0,1,0};
    int ncol=N/2,nrow=N/2; int change=2; int count=1; int c=0; int dir=0;
    int cr=0;
    while(1){
        
        if (ncol<0 || ncol>=N || nrow<0 || nrow>=N) break;
        arr[nrow][ncol]=*(snake+cr);
        nrow+=drow[dir]; ncol+=dcol[dir]; 
        count++;
        if (count==change){
            c++; count=1;
            if (dir==3) dir=0;
            else dir++;
        }
        if (c==2){
            
            c=0; change++;
        }
        cr++;
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++) result[i*N+j]=arr[i][j];
    }
}
#endif