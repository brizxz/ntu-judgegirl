#include <stdio.h>
#include <stdlib.h>
 
typedef struct distance{
    int x;
    int y;
} d;
 
int qudra(int a, int b){
    return (a-b)*(a-b);
}
 
int compare (const void *a, const void *b){
    d *num1 = (d*)a;
    d *num2 = (d*)b;
    int dis1 = qudra(num1->x,0)+qudra(num1->y,0);
    int dis2 = qudra(num2->x,0)+qudra(num2->y,0);
    if (dis1 >dis2 || dis1 == dis2 && num1->x > num2->x || 
    dis1 == dis2 && num1->x == num2->x && num1->y > num2->y) return 1;
    return -1;
}
 
int main(){
    int count =0 ; d arr[100000];
    while(scanf("%d%d",&arr[count].x,&arr[count].y)!=EOF) count++;
    qsort (arr,count, sizeof(d),compare);
 
    int ans=qudra(arr[0].x,0)+qudra(arr[0].y,0);
    for (int i = 0; i <count-1; i++){
        ans+= (qudra(arr[i+1].x,arr[i].x)+qudra(arr[i+1].y,arr[i].y));
    }  
    printf("%d\n",ans);
}