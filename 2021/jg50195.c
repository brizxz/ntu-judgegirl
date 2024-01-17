#include <stdio.h>
int main(){
    int num; int count=1; int max[4][3]={0}; int sec[4][3]={0}; int prev[4]={0}; 
    while(scanf("%d", &num) != EOF){ 
        int d = count-prev[num];
        if (prev[num]!=0){ 
            if (d>max[num][0]){
                sec[num][0] = max[num][0]; sec[num][1] = max[num][1]; sec[num][2] = max[num][2];
                max[num][0]= d ; max[num][1]=prev[num]; max[num][2]=count;
            }
            else if (d==max[num][0]){
                max[num][1] = prev[num]; max[num][2] = count;
            }
            else  if (d>=sec[num][0]){
                sec[num][0] = d; sec[num][1]=prev[num]; sec[num][2]= count;
            }
        }
        prev[num]=count; count++;
    }
    for (int i=1; i<=3; i++) printf("%d %d %d\n",sec[i][0],sec[i][1]-1,sec[i][2]-1);
}