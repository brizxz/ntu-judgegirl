#include <stdio.h>
#include <string.h>
 
int main(){
    char str[128];
    while(scanf("%s", str) !=EOF){
        if (strlen(str)==2){
            if ((str[0]=='o' && str[1]=='f') || (str[0]=='a' && str[1]=='t')) continue;
        }
        if (strlen(str)==3){
            if ((str[0]=='t' && str[1]=='h' && str[2]=='e') || (str[0]=='a' && str[1]=='n' && str[2]=='d'))
            continue;
            else if ((str[0]=='o' && str[1]=='f' && str[2]=='.') || (str[0]=='a' && str[1]=='t' && str[2]=='.')){
                printf("\n");
                continue;
            }
        }
        if (strlen(str)==4){
            if ((str[0]=='t' && str[1]=='h' && str[2]=='e' && str[3]=='.') || 
            (str[0]=='a' && str[1]=='n' && str[2]=='d' && str[3]=='.')){
                printf("\n");
                continue;
            }
        }
        if (str[0]>=97 && str[0]<=122) printf("%c", str[0]-32);
        if (str[strlen(str) - 1]=='.') printf("\n");
    }    
}