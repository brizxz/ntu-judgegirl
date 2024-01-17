#include <stdio.h>
void fill_array(int *ptr[], int n){
    for (int i =0; i<n; i++) *ptr[i] = i;
    for (int i = n-3; i>=1; i--){
        for (int j = 1; j <=i; j++){
            if (ptr[j]-ptr[j+1]>0){
                int *temp = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = temp;
            }
        }
    }
    for (int i =0; i<n-1; i++){
        for (int *j =ptr[i]+1; j<ptr[i+1]; j++){
            *j = *ptr[i]+*ptr[i+1];
        }
    }
}