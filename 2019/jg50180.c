#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
int main(){
    int n;
    scanf("%d",&n);
    char filenameA[20],filenameB[20],filenameC[20];
    scanf("%s%s%s",filenameA,filenameB,filenameC);
    int32_t matrixA[30][30]; int32_t matrixB[30][30]; int64_t matrixC[30][30];
    memset (matrixC,0,sizeof(matrixC));
    for (int i=1; i<=n; i++){
        char fileApre[20]; char fileBpre[20];
        strcpy(fileBpre,filenameB); strcpy(fileApre,filenameA);
        int len1 = strlen(filenameA); int len2 = strlen(filenameB);
        sprintf(fileApre+len1,"%d",i); sprintf(fileBpre+len2,"%d",i);
        // printf("%s %s\n",fileApre,fileBpre);
        FILE *fa = fopen(fileApre,"rb"); FILE *fb = fopen(fileBpre,"rb");
        fread(&matrixA[i-1],sizeof(int32_t),n,fa); fread(&matrixB[i-1],sizeof(int32_t),n,fb);
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            for (int k=0; k<n; k++){
                matrixC[i][j] += (int64_t)matrixA[i][k]*(int64_t)matrixB[k][j];
            }
        }
    }
    for (int i=1; i<=n; i++){
        char fileCpre[20];
        strcpy(fileCpre,filenameC); 
        int len1 = strlen(filenameC);
        sprintf(fileCpre+len1,"%d",i);
        // printf("%s %s\n",fileApre,fileBpre);
        FILE *fc = fopen(fileCpre,"wb"); 
        fwrite(&matrixC[i-1],sizeof(int64_t),n,fc);     
    }
}