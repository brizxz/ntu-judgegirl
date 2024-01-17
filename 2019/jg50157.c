#include <stdio.h>
 
int main(){
    int sum=0; int k; int max=0; int sec=0;
    scanf("%d", &k);
    int pokemon; int wind=0; int fire=0; int water=0; int count=0;
    while(scanf("%d", &pokemon)!=EOF){
        if (pokemon%3==0) wind++;
        else if (pokemon%3==1) fire++;
        else water++;
 
        if (count==0){
            max=pokemon; count=1;
        }
        else{
            if (pokemon>max){
                sec=max; max=pokemon;
            }
            else if (pokemon<=max && pokemon>sec) sec=pokemon;
        }
        if (wind>=k && fire>=k && water>=k){
            wind=0; fire=0; water=0;
            sum+=sec; max=0; sec=0; count=0;
        }
    }
    if ((wind!=0 || fire!=0 || water!=0) && sec==0) sum+=max;
    else if (wind!=0 || fire!=0 || water!=0 ) sum+=sec;
    printf("%d\n",sum);
}