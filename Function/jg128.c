#include "intersection.h"
 
void intersection(int map[100][100], int result[4]){
    result[0]=0; result[1]=0; result[2]=0; result[3]=0;
    int newarray[102][102]= {0};
    for (int i=0; i<100; i++){
        for (int j=0; j<100; j++) newarray[i+1][j+1] = map[i][j];
    }
    for (int i=1; i<=100; i++){
        for (int j=1; j<=100; j++){
            if (newarray[i][j]==1){
                int cal = newarray[i-1][j]+newarray[i+1][j]+newarray[i][j-1]+newarray[i][j+1];
                if (cal==4) result[0]++;
                else if (cal==3) result[1]++;
                else if (cal==1) result[3]++;
                else if (cal==2){
                    if (newarray[i+1][j]!=newarray[i-1][j] && newarray[i][j+1]!=newarray[i][j-1]) result[2]++;
                }
            }
        } 
    }
}