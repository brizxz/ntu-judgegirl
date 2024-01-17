#include <stdio.h>
#include <stdint.h>

int cal(uint32_t a){
    uint32_t k =-1;
    for (int i=0; i<32; i++){
        if ((a>>i) & k !=0) k=i; 
    }
    return 32-k;
}

int main(){
    int n;
    scanf("%d",&n);
    uint32_t num; int now=0; uint32_t prev=-1; uint32_t k=1; uint32_t kk=-1;
    for (int i=0; i<n; i++){
        scanf("%u",&num);
        uint32_t space = cal(num);
        for (int j=31; j>=0; j--){
            uint32_t output = (num>>j)&k;
            if (output!=prev && prev!=kk){
                if (space==(32-j)) now%=40;
                printf("\n");
                for (int l=0; l<now%40; l++) printf(" ");
            }
            printf("%u", output);

            prev = output; now++;
        }
    }
    printf("\n");
}