#include<stdio.h>
int main(void) {
    int T;
    scanf("%d", &T);
    while(T--) {
        long long a, b, c, A, B, C, D;
        scanf("%lld%lld%lld%lld%lld%lld%lld", &D, &a, &b, &c, &A, &B, &C);
        for (int i=0; i<=a; i++){
            for (int j=0; j<=b; j++){
                for (int k=0; k<=c; k++){
                    if (D-i*A-j*B-k*C==0) {
                        D=0;
                        break;
                    }
                }
                if(!D) break;   
            }
            if(!D) break;
        }
        printf(D?"no\n":"yes\n");           
 
    }
}