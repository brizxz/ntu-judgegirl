#include <string.h>
#include <stdio.h>

int main(){
    char str[100]; char buf[100]=""; int count = 0; int star=0;
    while(scanf("%s",str) != EOF){
        if (count%2==0){
            if (count==0){
                printf("%s",str); star+=strlen(str)-1;
            }
            else if (str[0]==buf[strlen(buf)-1]){
                printf("%s",str+1);
                star+=strlen(str)-1;
            }
            else{
                printf("\n");
                for (int i=0; i<star; i++) printf("*");
                printf("%s",str);
                star+=strlen(str)-1;
            } 
        }
        else{
            if (str[0]==buf[strlen(buf)-1]){
                for (int i=1; i<strlen(str); i++) {
                    printf("\n");
                    for (int j=0; j<star; j++) printf("*");
                    printf("%c",str[i]);
                }
            }
            else{
                for (int i=0; i<strlen(str); i++) {
                    printf("\n");
                    for (int j=0; j<star; j++) printf("*");
                    printf("%c",str[i]);
                }
            }
        }
        count++;
        strcpy(buf,str);
    }
    printf("\n");
}