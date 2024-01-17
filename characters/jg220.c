#include <stdio.h>
 
int main(){
    int sent=0,issent=0,status=0;
    char pre1=' ',pre2=' ',c=' ';
    while(scanf("%c",&c) != EOF){
        if(c == '.') status = 0;
        if(c != ' ' || c != '\n' || c != '.') status = 1;
        if(pre1 == '.' && pre2 == ' ' && c == ' ') sent++;
        if(pre2 == '.' && c == '\n') sent++;
        pre1 = pre2; pre2 = c;
    }
    if(c == '.') sent++;
    printf("%d",sent);
}