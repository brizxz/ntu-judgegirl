#include <stdio.h>
void printmatrix(int dim,int matrix[9][9]){
    for (int i=0; i<dim; i++){
        for (int j=0; j<dim; j++){
            if (j==0) printf("%d",matrix[i][j]);
            else printf(" %d",matrix[i][j]);
        }
        printf("\n");
    }
}
void swap(int arr[9][9],int new[9][9],int skip,int dim){
    int k=0;
    for (int i=1; i<dim; i++){
        k=0;
        for (int j=0; j<dim; j++){
            if (j==skip) continue;
            new[i-1][k] = arr[i][j];
            k++;
        }
    }
}

int deter(int dim,int matrix[9][9]){
    int newmatrix[9][9]; 
    printmatrix(dim,matrix);
    if (dim==1) return matrix[0][0];
    int val = 0;
    for (int i=0; i<dim; i++){
        swap (matrix,newmatrix,i,dim);
       
        // printmatrix(dim-1,newmatrix);
        if (i%2==0) val+=(matrix[0][i]*deter(dim-1,newmatrix));
        else val -= (matrix[0][i]*deter(dim-1,newmatrix));
        
    }
    if (dim>=2) printf("determinant=%d\n",val);
    return val;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[9][9];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    deter(n,arr);
}