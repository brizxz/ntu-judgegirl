#include <stdio.h>

int main(){
    int arr[2048]; int n; int find=0; int swapplace=0;
    scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d",&arr[i]);
    while (find==0){
        for (int i=1; i<n-1; i++){ // from left2 to right2
            int left=0; int right=0; int countleft=1; int countright=1;
            for (int j=i-1; j>=0; j--){
                left+=(countleft*arr[j]); countleft++;
            }
            for (int j=i+1; j<n; j++){
                right+=(countright*arr[j]); countright++;
            }
            if (left==right){
                find=1; arr[i]=0;  break; 
            } 
        }
        if (find==1) break; 
        int temp=arr[swapplace]; arr[swapplace]=arr[n-swapplace-1]; arr[n-swapplace-1]=temp;
        swapplace++;
    }

    for (int i=0; i<n; i++){
        if (i==0) printf("%d",arr[i]);
        else{
            if (arr[i]==0) printf(" v");
            else printf(" %d",arr[i]);
        }
    }
}