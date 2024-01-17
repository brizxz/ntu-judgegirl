#include <stdio.h>
#include <string.h>
int min(int a, int b){
    if (a < b) return a;
    return b;
}
int cal(char arr1[],char arr2[],int ans,int d){
    if (d>=ans) return d;
    while (arr1[0] == arr2[0] && arr1[0] != '\0' && arr2[0] != '\0') {
        arr1++; arr2++;
    }
    if (arr1[0]=='\0' || arr2[0]=='\0') return d+strlen(arr2)+strlen(arr1); 
    else return min(cal(arr1+1,arr2,ans,d+1),cal(arr1,arr2+1,ans,d+1));
}
 
int main(){
    char str[100][11]; int n=0; int ans[3]={100000,0,0}; // length ,id1,id2
    while(scanf("%s", str[n])!=EOF) n++;
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            int k=cal(str[i],str[j],ans[0],0);
            if (k<ans[0]){
                ans[0]=k; ans[1]=i; ans[2]=j;
            }
        }
    }
    printf("%d %d %d\n",ans[0],ans[1]+1,ans[2]+1);
}