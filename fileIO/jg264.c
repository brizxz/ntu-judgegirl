#include <stdio.h>
#include <string.h>
int main(){
    char filename[202];
    scanf("%s", filename);
    FILE *open = fopen(filename, "rb");
    int num;
    fread(&num, sizeof(int), 1,open);
    int maxtime=-1 ,maxnum=-1; short int ans[65536];
    memset(ans, 0, sizeof(ans));
    for (int i=0; i<num; i++) {
        short signed int scan;
        fread(&scan, 2, 1, open);
        ans[scan+32768]++;
        if (ans[scan+32768]>maxtime || ans[scan+32768]==maxtime && scan+32768>maxnum){
            maxtime = ans[scan+32768]; maxnum = scan+32768;
        } 
    }
    printf("%d\n%d\n", maxnum-32768,maxtime);
}