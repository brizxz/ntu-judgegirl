#include <stdio.h>
 
int main(){
    int n;
    int a[1000];
    scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    for (int i=n-1; i>=1; i--) printf("%d ",a[i]); 
    printf("%d\n",a[0]);
}