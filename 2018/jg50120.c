#include <stdio.h>

int arr[1001][1001]; // change to n,n
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int ans=0;
    for (int i=0; i<n; i++){
        int countd1=0;
        if (arr[i][i]==1)  countd1++;
        else countd1=0;
        int countr=0; int countc=0; int countd2=0; int countd3=0;
        for (int j=0; j<n; j++){
            if (arr[i][j]==1) countr++;
            else countr=0;
            if (arr[j][i]==1) countc++;
            else countc=0;
            if (i+j+1<n){
                if (arr[i+j+1][j]==1 ) countd2++;
                else if (arr[i+j+1][j]!=1 ) countd2=0;
                if (arr[j][i+j+1]==1 ) countd3++;
                else if (arr[j][i+j+1]!=1 ) countd3=0;
            }
            if (countr>ans) ans = countr;
            if (countc>ans) ans = countc;
            if (countd2>ans) ans = countd2;
            if (countd3>ans) ans = countd3;
        }
        if (countd1>ans) ans = countd1;
    }
    printf("%d",ans);
}