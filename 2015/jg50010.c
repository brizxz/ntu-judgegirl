#include <stdio.h>
#include <string.h>

int main(){
    char str[100010]; int k=0;
    scanf("%s",str);
    char command[100010];
    while(scanf("%s",command)!=EOF){
        int len=strlen(str); char a[2]; char b[2]; char buf[100010];
        if (strcmp(command,"end")==0) break;
        if (strcmp(command,"replace")==0){
            scanf("%s%s",a,b);
            for (int i=0; i<len; i++){
                if (str[i]==a[0]) str[i] = b[0];
            }
        }
        else if (strcmp(command,"remove")==0){
            int c=0;
            scanf("%s",a);
            for (int i=0; i<len; i++){
                if (str[i]==a[0]) continue;
                buf[c]=str[i]; c++;
            }
            buf[c]='\0';
            strcpy(str,buf);
        }
        else if (strcmp(command,"addhead")==0){
            scanf("%s",a);
            strcpy(buf,str); str[0]=a[0];
            strcpy(str+1,buf);
        }
        else if (strcmp(command,"addtail")==0){
            scanf("%s",a);
            str[len]=a[0]; str[len+1]='\0';
        }
        else {
            printf("invalid command %s",command); 
            k=1; break;
        }
    }
    if (k==0) printf("%s",str);
}