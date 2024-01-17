#include <stdio.h>
int cal(int arr[12][12], int r,int c,int row,int col){
    if (arr[r][c]==0 || r<0 || c>=col) return 0;
    if (r==0 && c==col-1) return 1;
    return cal(arr,r,c+1,row,col) + cal(arr,r-1,c,row,col);
}
 
int main(){
    int r,c; int arr[12][12];
    scanf("%d%d",&r,&c);
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++) scanf("%d",&arr[i][j]);
    }
    printf("%d\n",cal(arr,r-1,0,r,c));
}