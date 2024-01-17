int evaluate_f(int *iptr[], int n, int *index){
    int max=-100000;
    for (int i=0; i<n; i++){
        if (iptr[i][0]*4-iptr[i][1]*6>max){
            max=iptr[i][0]*4-iptr[i][1]*6;
            *index=i;
        }
    }
    return max;
}