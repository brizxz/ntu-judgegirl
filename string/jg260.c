#include <stdio.h>
#include <string.h>
 
int cploc(char a[128],char b[128],int a1,int b1){
    int j=0; int val=0;
    for (int i=b1-1;i>=0;i--){
        int k=i;
        if (i>=a1) continue;
        for (int j=a1-1; j>=0 && k>=0; j--,k--){
            if (b[k]==a[j]){
                val++;
            }
            else{
                val=0; k=i; break;
            }
        }
        if (val>0) break;
    }
    return val;
}
 
int main(){
    char res[128]=""; char buf[128];
    while(scanf("%s", buf)!=EOF){
        int s2=strlen(buf); int s1=strlen(res);
        if (s1==0) strcpy(res,buf);
        else{
            int count = cploc(res, buf,s1,s2);
            strcat(res,buf+count);
        }
    }
    printf("%s\n",res);
}