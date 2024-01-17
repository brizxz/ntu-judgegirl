#include <stdio.h>

int main(){
    int dps[5000]; int healer[5000]; int tank[5000];
    int cd=0,ch=0,ct=0; int people; int d=0,h=0,t=0;
    while(scanf("%d",&people)!=EOF){
        if (people%3==0){
            dps[cd%5000]=people; cd++;
        }
        else if (people%3==1){
            healer[ch%5000]=people; ch++;
        }
        else{
            tank[ct%5000]=people; ct++;
        }
        if (cd-d>=3 && ch-h>=1 && ct-t>=1){
            printf("%d %d %d %d %d\n",dps[d%5000],dps[(d+1)%5000],dps[(d+2)%5000],healer[h%5000],tank[t%5000]);
            d+=3; h++; t++;
        }
    }
}