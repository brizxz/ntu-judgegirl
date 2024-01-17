#include <stdio.h>
 
int main(){
    int n;
    scanf("%d",&n);
    int num[100000]; int remainder[200000]={0};
    
    for (int i=0; i<n; i++) scanf("%d",&num[i]);
    
    int m; 
    scanf("%d",&m);
    for (int i=0; i<n; i++){
        remainder[num[i]%m]++;
    }
    for (int i=0; i<m; i++) printf("%d\n",remainder[i]);
}