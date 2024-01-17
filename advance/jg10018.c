#include <stdio.h>
 
int main(){
    int N[50005]={0};
    int n;
    scanf("%d",&n);
    int num;
    for (int i=0; i<n; i++){
        scanf("%d",&num);
        N[num]++;
    }
    for (int i=0; i<n; i++) if (N[i]>1){
        printf("%d",i); break;
    }
}