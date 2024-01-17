#include <stdint.h>
#include <stdio.h>
void BubbleSort(uint64_t input, uint64_t output[63]){
    uint64_t k=1;
    for (int i = 62; i >=0; i--){
            for (int j = 62; j >=0; j--){
            if ((((k<<(j+1))&input)!=0) && (((k<<j)&input))==0){
                input ^= (k<<(j+k)); input ^= (k<<(j));
            }
        }
        output[62-i] = input;
    }
}