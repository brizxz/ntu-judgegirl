int max(int *iptr[], int n){
    int k=-100000;
    for (int i=0; i<n; i++) if (*iptr[i]>k) k=*iptr[i];
    return k;
}