#include <stdio.h>
 
int main(){
    int m,n; int a[101]; int b[101]; int result[202]={0};
    scanf("%d", &m);
    for (int i = 1; i < m+1; i++) scanf("%d", &a[i]);
    scanf("%d", &n);
    for (int i = 1; i < n+1; i++) scanf("%d", &b[i]);
    for (int i = 1; i <m+1; i++){
        for (int j = 1; j < n+1; j++){
            result[i+j-1] += a[i]*b[j];
        }
    }
    for (int i = 1; i <n+m-1; i++) printf("%d ", result[i]);
    printf("%d\n", result[n+m-1]);
 
}