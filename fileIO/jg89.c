#include<stdio.h>
#include<stdlib.h>
#define MAXN 65536
 
int main(){
    FILE *open = fopen("test","rb");
    FILE *close = fopen("test.enc","wb");
    int key; char arr[MAXN]; 
    int size; 
    scanf("%d", &key);
    while ((size = fread(arr,1,MAXN,open))!=0){
        for (int i = 0; i < size; i++){
            arr[i] ^= key;
        }
        fwrite(arr,sizeof(char),size,close);
    }
    fclose(open);
    fclose(close);
    return 0;
}