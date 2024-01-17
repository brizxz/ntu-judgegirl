#include <stdio.h>
#define ll long long
 
void bubble_sort(int a[],int n){
    for (int i=n-2; i>=0; i--){
        for (int j=0; j<=i; j++){
            if (a[j] > a[j+1]){
                ll int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
 
int main(){
    ll int a,b,c; int sol[5];
    scanf("%lld%lld%lld",&a,&b,&c);
    int count_sol = 0;
    for (ll int i=-100000; i<=100000; i++){
        if (i*i*i+a*i*i+b*i+c==0){
            sol[count_sol]=-i;
            count_sol++;
        }
        if (count_sol==3) break;
    }
 
    if (count_sol==1) printf("%d %d %d",sol[0],sol[0],sol[0]);
    else if (count_sol==2){
        if (sol[0]*2+sol[1]==a){
            if (sol[0]>sol[1]) printf("%d %d %d",sol[1],sol[0],sol[0]);
            else printf("%d %d %d",sol[0],sol[0],sol[1]);
        }
        else if (sol[0]+sol[1]*2==a){
            if (sol[0]>sol[1]) printf("%d %d %d",sol[1],sol[1],sol[0]);
            else printf("%d %d %d",sol[0],sol[1],sol[1]);
        }
    }
    else if (count_sol==3){
        bubble_sort(sol,count_sol);
        printf("%d %d %d",sol[0],sol[1],sol[2]);       
    }
}