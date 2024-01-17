#include <stdio.h>
 
int main(){
    int a,b;
    int c[5]; int d[5];
    scanf("%d%d",&a,&b);
    c[0]= a/1000; d[0]= b/1000;
    a%=1000; b%=1000;
    c[1]= a/100; d[1]= b/100;
    a%=100; b%=100;
    c[2]= a/10; d[2]= b/10;
    a%=10; b%=10;
    c[3]= a; d[3]= b;
 
    int count_A = 0; int count_B = 0;
    for (int i=0; i<4; i++){
        for (int j=0;j<4; j++){
            if (c[i]==d[j]){
                if (i==j) count_A++;
                else count_B++;
            }
        }
    }
    printf("%dA%dB\n",count_A,count_B);
}