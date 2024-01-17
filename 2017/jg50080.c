#include <stdio.h>
 
int main(){
    int num; int blockmax=-100000; int blockmin=100000; int status=1; int count=0;
    int prev=0;
    while(scanf("%d", &num) != EOF){
        if (status == 1){
            prev = num; status = 0;
        }
        else{
            count++;
            if (num>blockmax){
                blockmax = num;
            }
            if (num<blockmin) blockmin = num;
            if (count==prev){
                printf("%d\n", blockmax);
                prev=0; status = 1; count=0; blockmax=-100000; blockmin=100000;
            }
        }
    }
    if (count==1) printf("%d\n",blockmax);
    else if (count>0 && count<prev) printf("%d\n",blockmin);
}