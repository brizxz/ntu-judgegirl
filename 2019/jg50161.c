#include <stdio.h>
int main(){
    int n; int arr[100000]; int prev[101];
    for (int i=1; i<101; i++) prev[i]=-1;
    scanf("%d",&n);
    for (int i = 0; i <n; i++){
        int num; int find=0;
        scanf("%d", &num); 
        if (prev[num]==-1) prev[num]=i;
        else{
            printf("%d %d %d\n",i,prev[num],num); find=1; prev[num]=-1;
        } 
        if (find==0) printf("%d\n",i);
    }
}