#include <string.h>
#include <stdio.h>
void findRowAndColumn(int **ptr, int *Row, int *Col, int **start, int *ansRow, int *ansCol){
    for (int i = 0; ptr[i]!=NULL; i++){
        int sum = 0;
        while (ptr[i]!=(start[i]+sum)){
            sum += 1;
        }
        
        ansCol[i] = sum%Col[i]; ansRow[i] = sum/Col[i];
    }
}