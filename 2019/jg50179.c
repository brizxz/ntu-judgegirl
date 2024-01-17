#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(int count[10],int n){
    int c = 10000000; int loc=-1;
    for (int i=0; i<n; i++){
        if (count[i]<c){
            c = count[i]; loc = i;
        } 
    }
    return loc;
}

int main(){
    int n; char input[50]; char prefix[50];
    scanf("%s%d%s",input,&n,prefix);
    char refile[10][50]; int count[10] = {0};
    FILE *resfile[10];
    int prefixlen = strlen(prefix);
    for (int i=0; i<n; i++){
        strcpy(refile[i],prefix);
        sprintf(refile[i]+prefixlen,"%d",i+1);
        printf("%s\n",refile[i]);
        resfile[i] = fopen(refile[i],"wb");
    }
    printf("%d",find(count,n));
    FILE *fin = fopen(input,"rb"); 

    // use fgetc and fputc to get unsigned char
   while (!feof(fin)){
        int cur= find(count,n);
        int byte = fgetc(fin);
        while (!feof(fin) && (byte!=255)){
            fputc(byte,resfile[cur]);
            count[cur]++;
            byte = fgetc(fin);
        }
    } 
    fclose(fin);
    for (int i=0; i<n; i++) fclose(resfile[i]);
}