
# include <stdio.h>
 
int main(){
    int score;
    int sum=0;
    scanf("%d",&score);
    if (score<=0) printf("%d\n",-100);
    else{
        if (score%3==0) sum+=3;
        if (score%5==0) sum+=5;
        if (score<=200 && score>=100) sum+=50;
        else sum-=50;
        printf("%d\n",sum);
    }
}