#include <stdio.h>
 
int main(){
    int max=0; int count=0;int arr[100]; int num; int judge=0; int place;
    while(scanf("%d",&num)!=EOF){
        arr[count]=num; count++;
    }
 
    for(int i=0; i<count-1; i++){
        for (int j=count-1; j>i; j--){
            for (int k=i+1; k<=j; k++){
                judge=0;
                for (int l=i; l<=(i+k-1)/2; l++){
                    if (arr[l]!=arr[k+i-l-1]) judge=1;
                }
                for (int l=k; l<=(k+j)/2; l++){
                    if (arr[l]!=arr[j+k-l]) judge=1;
                }
                if (judge==1) continue;
                else{
                    if (j-i+1>=max){
                        max=(j-i+1);
                      place=i;
                    }
                }
            }
        }
    }
    for (int i=0; i<max; i++){
        if (i!=max-1) printf("%d ",arr[place+i]);
        else printf("%d\n",arr[place+i]);
    }
}