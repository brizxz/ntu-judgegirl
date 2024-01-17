#include <stdio.h>
 
int abs(int x) {
    if (x < 0) return -x;
    return x;
}
 
int main(){
    int m; // parkinglot
    scanf("%d",&m);
    int caramount[10]={0},capcity[10]={0};
    int parkinglot_x[10];  int parkinglot_y[10];
    for (int i=0; i<m; i++) scanf("%d%d%d",&parkinglot_x[i],&parkinglot_y[i],&capcity[i]);
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        int distance[10];
        int car_x,car_y;
        scanf("%d%d",&car_x,&car_y);
        int min=100000, x=10001,y=10001; //先x後y
        int choice;
        for (int j=0; j<m; j++) distance[j] = abs(car_x-parkinglot_x[j])+abs(car_y-parkinglot_y[j]);
        
        for (int j=0; j<m; j++){
            if (capcity[j]==0) continue;
            if (distance[j]<min || distance[j]==min && parkinglot_x[j]<x || 
            distance[j]==min && parkinglot_x[j]==x && parkinglot_y[j]<y){
                min=distance[j]; choice=j; x=parkinglot_x[j]; y=parkinglot_y[j];
            }
        }
        capcity[choice]--;
        caramount[choice]++;
    }
 
    for (int i=0; i<m; i++) printf("%d\n",caramount[i]);
}