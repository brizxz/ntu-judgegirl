#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
 
int main(){
    char instru[10]; char ans[50000]=" ";
    while(scanf("%s", instru)!=EOF){
        char loc[10]; int len=strlen(ans);
        if (strcmp(instru,"insert")==0){
            scanf("%s",loc);
            int loca;
            if (strcmp(loc,"left")==0){
              char buf[50000];
                strcpy(buf,ans+1);
                scanf("%s",ans+1);
                strcpy(ans+2,buf);
            }
            else if (strcmp(loc,"right")==0){
                char c;
                scanf("%s",ans+strlen(ans));
            }
            else{
                loca=atoi(loc);
                char buf[50000];
                strcpy(buf,ans+loca);
                scanf("%s",ans+loca);
                strcpy(ans+loca+1,buf);
            }
        }
        else{
            scanf("%s",loc);
            if (strcmp(loc,"left")==0){
                strcpy(ans+1,ans+2);
            }
            else if (strcmp(loc,"right")==0){
                ans[strlen(ans)-1]='\0';
            }
            else{
                int loca=atoi(loc);
                strcpy(ans+loca,ans+loca+1);
            }
        }
    }
    char anschar[10000]; int maxlen=0; int countans=0; char prev; int countlen=0;
    for (int i = 1; i < strlen(ans); i++) {
        if (i==1){
            maxlen=countlen= 1; 
            prev=ans[1];
            anschar[0] = ans[i];
            countans=1;
            continue;
        }
        if (ans[i]==prev){
            countlen++;
        }
        else {
            countlen=1;
        }
        if (countlen>=maxlen){
            if (countlen==maxlen && anschar[countans-1]!=ans[i]){
                anschar[countans]=ans[i]; countans++;
            }
            else{
                anschar[0] = ans[i];
                countans=1;
                maxlen=countlen;
            }
        }
        prev = ans[i];
    }
    for (int i=0; i<countans; i++) printf("%c ",anschar[i]);
    printf("%d",maxlen);
}