#include <stdio.h>
 
int main(){
    int special[5];
    scanf("%d%d%d",&special[0],&special[1],&special[2]);
    int first[5];
    scanf("%d%d%d",&first[0],&first[1],&first[2]);
    int my_lottery; int sum=0;
    while(scanf("%d",&my_lottery)!=EOF){
        for (int i=0; i<3; i++){
            if (my_lottery==special[i]) sum+=2000000;
            if (my_lottery==first[i]) sum+=200000;
            else if (my_lottery%10000000==first[i]%10000000) sum+=40000;
            else if (my_lottery%1000000==first[i]%1000000) sum+=10000;
            else if (my_lottery%100000==first[i]%100000) sum+=4000;
            else if (my_lottery%10000==first[i]%10000) sum+=1000;
            else if (my_lottery%1000==first[i]%1000) sum+=200;
        }
    }
    printf("%d\n",sum);
}