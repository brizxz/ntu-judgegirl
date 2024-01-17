#include <stdio.h>
#include <string.h>
// use strtok 
int main(){
    char input[128];
 
    int total = 0;
    while(scanf("%s", input) != EOF){
        char *token = strtok(input, "()");
        while(token != NULL){
 
            if(strcmp(token, "if") == 0 || strcmp(token, "case") == 0 || strcmp(token, "while") == 0
            || strcmp(token, "for") == 0 || strstr(token, "?") != NULL) {total++;}
            token = strtok(NULL, "()");
        }
    }
    printf("%d", total);
}