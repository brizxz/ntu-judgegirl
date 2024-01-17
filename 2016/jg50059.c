#include <stdio.h>
#include <string.h>
#include <stdint.h>
char decode(int c[5],char mode[35]){
    int k = c[0]*16+c[1]*8+c[2]*4+c[3]*2+c[4];
    return mode[k];
}
int main(){
    char mode[35]; int num; int total = 0; int count = 0;
    scanf("%s", mode); int c[5];
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d",&num);
        for (int j=0; j<32; j++){
            int k = num>>(31-j)&1;
            c[total]=k;
            if ((total+1)%5 ==0){
                total=0;
                printf("%c",decode(c, mode)); 
                count++;
            }
            else total++;
        }
    }
    printf("\n");
}
