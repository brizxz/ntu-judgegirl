void fill_rectangle_neg(int *upper_left, int *bottom_right, int n_row, int n_col, int fill){
    int diff = bottom_right-upper_left;
    int dif_r = diff/n_col; int dif_c = diff%n_col;
    for (int i = 0; i <=dif_r; i++){
        for (int j = 0; j <=dif_c; j++){
            *(upper_left+i*n_col+j) = fill;
        }
    }
}
void fill_rectangle_pos(int *upper_right, int *bottom_left, int n_row, int n_col, int fill){
    int dif_r=0;
    while (bottom_left>upper_right){
        bottom_left-=n_col;
        dif_r++;
    }
    int dif_c = upper_right-bottom_left; 
    for (int i = 0; i <=dif_r; i++){
        for (int j = 0; j <=dif_c; j++){
            *(bottom_left+i*n_col+j) = fill;
        }
    }    
}