#include <stdio.h>
#include "setmatrix.h"
 
void processSetMatrix(int ***ptr) {
    // add your code
    int find=0;
    for (int i = 0; ptr[i] != NULL; i++){
        for (int j = 0; ptr[i][j] != NULL; j++){
            for (int k = 0; ptr[i][j][k] != 0; k++){
                if (find==0) printf("%d",ptr[i][j][k]);
                else printf(" %d",ptr[i][j][k]);
                find=1;
            }
        }
    }
}