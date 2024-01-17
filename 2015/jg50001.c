#include <stdio.h>

int main(){
    int k; int seg=0;
    scanf("%d",&k);
    int num; int goal=1; int max=0; int count=0;
    while(scanf("%d",&num)!=EOF){
        if (num==0) break;
        if (num>0 && goal==1){
            count++; seg++;
            if (seg==k){
                if (count>max && count>=3*k) max=count;;
                seg=0; goal=-1;
            }
        }
        else if (num>0 && goal==-1){
            count=k; seg=0;
        }
        else if (num<0 && goal==1){
            count=0; seg=0; 
        }
        else{
            count++; seg++;
            if (seg==k){
                goal=1; seg=0;
            }
        }
    }
    printf("%d",max);
}