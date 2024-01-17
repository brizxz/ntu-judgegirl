void snake(const int *ptr_array[100][100], int m){
    int buf[10000];
    for (int i=0; i<m; i++){
        for (int j=0; j<m; j++){
            buf[i*m+j] = *(ptr_array[i][j]);
        }
    }
    for (int i=m*m-2; i>=0; i--){
        for (int j=0; j<=i; j++){
            if (buf[j]>buf[j+1]){
                int temp=buf[j]; buf[j]=buf[j+1]; buf[j+1]=temp;
                int *tmp=ptr_array[j/m][j%m];
                ptr_array[j/m][j%m]=ptr_array[(j+1)/m][(j+1)%m];
                ptr_array[(j+1)/m][(j+1)%m]=tmp;
            }
        }
    }
    for (int i=0; i<m; i++){
        for (int j=0; j<m/2; j++){
          if (i%2==1){
                int *tmpp=ptr_array[i][j];
                ptr_array[i][j]=ptr_array[i][m-j-1]; ptr_array[i][m-j-1]=tmpp;
            }
        }
    }
}