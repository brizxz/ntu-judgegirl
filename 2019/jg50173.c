#include<stdint.h>
#include <stdio.h>
void printMatrix(uint64_t *matrix){
    printf("%lu\n",*matrix);
    uint64_t k=1;
    for (uint64_t i=0; i<64; i++){
        printf("%lu",(k)&((*matrix)>>(i)));
        if (i%8==7 && i!=0) printf("\n");
    }
}
void rotateMatrix(uint64_t *matrix){
    int arr[8][8];
    uint64_t k=1;
    for (uint64_t i=0; i<64; i++){
        arr[i/8][i%8]=(k)&((*matrix)>>(i));
    }
    uint64_t rota[8][8];
    for (int i=0; i<8; i++){
        for (int j=7; j>=0; j--){
            rota[i][7-j]=arr[j][i];
        }
    }
    uint64_t res = 0;
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            res |= ((rota[i][j])<<(i*8+j));
        }
    }
    *matrix = res;
}
void transposeMatrix(uint64_t *matrix){
    int arr[8][8];
    uint64_t k=1;
    for (uint64_t i=0; i<64; i++){
        arr[i/8][i%8]=(k)&((*matrix)>>(i));
    }
    uint64_t trans[8][8];
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            trans[j][i]=arr[i][j];
        }
    }
    uint64_t res = 0;
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            res |= ((trans[i][j])<<(i*8+j));
        }
    }
    *matrix = res;
}