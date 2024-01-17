#include <stdio.h>
#define MAXN 100005
int A[MAXN]={0};
int main() {
    int n; int num; int count0=0;
    while (scanf("%d", &n) == 1) {
        int count = n-1;
        for (int i = 0; i < n; i++){
            scanf("%d", &num);
            if (num == 0){ 
                A[count] = num; count--;
            }
            else{
                A[count0] = num; count0++;
            }
        }
        for (int i = 0; i < n-1; i++)
            printf("%d ", A[i]);
        printf("%d",A[n-1]);
    }
}