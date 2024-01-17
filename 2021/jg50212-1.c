#include <stdio.h>
#include <stdint.h>
int countbit(uint32_t a){
    uint32_t k=1; int sum=0;
    for (int i=0;i<32; i++){
        if ((a>>i)&k!=0) sum++;
    }
    return sum;
}

int cal(uint32_t u,int bit){
    if (bit==1) return u;
    if (countbit(u)%2==0){
        return cal(u>>bit/2,bit/2)<<bit/2 | cal((u<<(32-bit/2))>>(32-bit/2),bit/2);
    }
    else{
        return cal(u>>bit/2,bit/2) | cal((u<<(32-bit/2))>>(32-bit/2),bit/2)<<(bit/2);
    }
}

int main(){
    uint32_t num;
    scanf("%u",&num);
    printf("%u\n",cal(num,32));
}