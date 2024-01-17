#include <stdio.h>
#include <ctype.h>
#include <string.h>
 
int main(){
    char arr[101]; int k=0; char dk; int seg[100]; int c_s=1; seg[0]=0;
    while( scanf("%c", &dk)!=EOF){
        arr[k] = dk;
        if (arr[k]=='\n'){
            seg[c_s]=k; c_s++; 
        } 
        k++; 
    }
    seg[c_s]=k-1;
    for (int i=0; i<c_s; i++){
      int c1=seg[i]; int c2=seg[i+1];
        while(isspace(arr[c1])) c1++;
        while(isspace(arr[c2])) c2--;
        for (int j=c1; j<=c2; j++){
            printf("%c",arr[j]);
        }
    }
}