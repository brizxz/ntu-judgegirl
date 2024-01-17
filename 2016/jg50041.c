#include <stdio.h>
#include <math.h>
 
int main(){
    int n; int cost=0; int h; int prev_state=0;
    scanf("%d%d", &n, &h); int prev=h;
    for(int i = 0; i < n; i++){
        scanf("%d", &h);
        if (i==0){
            if (h>prev){
                cost += 3*(h-prev);
            }
            else {
                cost += 2*(prev-h);
            }
        }
        else{
            if (prev_state==1 && h>prev) cost += 4*(h-prev);
            else if ((prev_state==1 && h<prev) || (prev_state==0 && h>prev)) cost += abs(prev-h)*3;
            else cost += 2*abs(prev-h);
        }
        prev_state = (h>prev)?1:0; // 1:uphill
        prev=h;
    }
    printf("%d",cost);
}