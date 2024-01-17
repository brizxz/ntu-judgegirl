#include <stdio.h>
#include <string.h>
 
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        char arr1[80]; char arr2[80];
        scanf("%s%s",arr1,arr2);
        int find1=1,find2=1,find3=1;
        int a1=strlen(arr1); int a2=strlen(arr2); 
        if (strlen(arr1)==strlen(arr2)){
            int loc1=-1;
            for (int j=0; j<a1; j++){ 
                if (arr1[j]!=arr2[j] && loc1==-1){ 
                    find1=0; loc1=j;
                }
            }
            if (find1==1){
                printf("yes\n"); continue;
            }
            char temp=arr1[loc1]; arr1[loc1]=arr1[loc1+1]; arr1[loc1+1]=temp;
            for (int j=0; j<a1; j++){ 
                if (arr1[j]!=arr2[j]) find2=0;
            }
            if (find2==1){
                printf("yes\n"); continue;
            }
        }
        else if (a1-a2>1 || a1-a2<-1){
            printf("no\n"); continue;
        }
        else{
            if (a1>a2){
                int loc2=0; int count=0;
                for (int j=0; j<a1-1; j++,loc2++){
                    if (arr1[loc2]!=arr2[j] && count==0){
                        loc2++; count=1; 
                        if (arr1[loc2]!=arr2[j]) find3=0;
                        continue;
                    }
                    if (arr1[loc2]!=arr2[j]) find3=0;
                }
            }
            else{
                int loc2=0; int count=0;
                for (int j=0; j<a2-1; j++,loc2++){
                    if (arr1[j]!=arr2[loc2] && count==0){
                        loc2++; count=1; continue;
                    }
                    if (arr1[j]!=arr2[loc2]) find3=0;
                }
            }
            if (find3==1){
                printf("yes\n"); continue;
            }
        }
        printf("no\n");
    }
}