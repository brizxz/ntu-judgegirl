#include <stdio.h>
void print(int arr[9][9],int dim){
    for (int i=0;i<dim; i++){
        for (int j=0;j<dim; j++){
            if (j!=dim-1) printf("%d ",arr[i][j]);
            else printf("%d\n",arr[i][j]);
        }
    }
    return;
}
void del(int arr[9][9],int new[9][9],int dim,int skip){
    for (int i=1;i<dim;i++){
        int kk=0;
        for (int j=0;j<dim; j++){
            if (j==skip) continue;
            new[i-1][kk]=arr[i][j];
            kk++;
        }
    }
    return;
}

int deter(int arr[9][9],int dim){
    print(arr,dim);
    if (dim==1) return arr[0][0];
    int val = 0; int sign=1;
    for (int i=0;i<dim; i++){
        int new[9][9];
        del(arr,new,dim,i);
        if (i%2==0) val += (arr[0][i]*deter(new,dim-1));
        else val -= (arr[0][i]*deter(new,dim-1));
    }
    if (dim>=2) printf("determinant=%d\n",val);
    return val; // notice
}


int main(){
    int arr[9][9];
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    deter(arr,n);
}