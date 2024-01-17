#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int cmp(const void *a,const void *b){
    char *c1 = (char *)a;
    char *c2 = (char *)b;
    return strcmp(c1,c2);
}
 
 
int main(){
    char arr[64][60];
    int count = 0;
    while(fgets(arr[count],60,stdin) != NULL) count++;
    qsort(arr,count,60,cmp);
    for(int i=0;i<count;i++) printf("%s",arr[i]);
}