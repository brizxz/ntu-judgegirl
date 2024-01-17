#include <stdio.h>
 
int main(){
    int n,m; int count=1; int row_index_max=0; int row_index_sec=0;
    scanf("%d%d",&n,&m);
    int row_high=-1; int row_sec=-1; int highest=-1; int highest_index_row=0; int highest_index_col=0;
    int num; int rowcount=1; int colcount=1; 
    while(scanf("%d",&num) != EOF){
        if (num>=highest){
            highest = num; highest_index_row=rowcount; highest_index_col=colcount;
        } 
 
        if (num>=row_high){
            row_sec=row_high;  row_high = num; row_index_sec=row_index_max; row_index_max=colcount;
        }
        else if (num>=row_sec){
            row_sec = num; row_index_sec=colcount;
        }
        if (colcount==m){
            printf("%d %d\n",row_index_max,row_index_sec);
            colcount = 0; row_index_max=0; row_index_sec=0; rowcount++;
            row_high=0; row_sec=0;
        }
        colcount++;
    }
    printf("%d %d",highest_index_row,highest_index_col);
}