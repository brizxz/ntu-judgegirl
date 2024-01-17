#include <stdio.h>
#include <string.h>
 
int abs(int x) { 
    if (x < 0) return -x;
    return x;
}
 
int main(){
    char str[1024];
    while(scanf("%s", str)!=EOF){
        if (strlen(str)==2 && str[0]=='-' && str[1]=='1') break;
        int judge3=0;int oddsum=0; int evensum=0;
        for (int i=0; i<strlen(str); i++){
            judge3+=(str[i]-48);
            if (i%2==0) evensum+=(str[i]-48);
            else if (i%2==1) oddsum+=(str[i]-48);
        }
        if ((str[strlen(str)-1]-48)%2==0) printf("yes ");
        else printf("no ");
        if (judge3%3==0) printf("yes ");
        else printf("no ");
        if ((str[strlen(str)-1]-48)%5==0) printf("yes ");
        else printf("no ");       
        if ((abs(evensum-oddsum))%11==0) printf("yes\n");
        else printf("no\n"); 
    }
}