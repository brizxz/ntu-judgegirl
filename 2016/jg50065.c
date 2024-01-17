#ifndef _CAR_H
#define _CAR_H
 
#define MAXN 100
 
typedef struct{
    int x, y;
    int g;
} CarStatus;
 
typedef struct{
    int t, v;
} Command;
 
typedef struct{
    int num;
    CarStatus status[MAXN];
} CarStatusList;
 
CarStatusList carSimulation(CarStatus car, Command commands[]){
    CarStatusList ans; ans.num=0; 
    for (int i = 0; commands[i].t!=0 ; i++){
        if (commands[i].t==1) car.g+=commands[i].v;
        else{
            if (car.g < commands[i].v || commands[i].t>5 || commands[i].t<0) break;
            int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
            car.x+=commands[i].v*dir[commands[i].t-2][0];
            car.y+=commands[i].v*dir[commands[i].t-2][1];
            car.g-=commands[i].v;
            ans.status[ans.num].x = car.x;
            ans.status[ans.num].y = car.y;
            ans.status[ans.num].g = car.g;
            ans.num++;
        }
    }
    return ans;
}
 
#endif