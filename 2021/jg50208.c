#include <stdio.h>
#include <string.h>

int judge(char str[10000]){
    char test[7][7]={"","","if","for","case","while"};
    for (int i=2; i<=5; i++){
        if (strncmp(str,test[i],i)==0) return i;
    }
    return -1;
}

int main(){
    char str[10000]; int cc=0; char buf[1024]="";
    while( scanf("%s", str)!=EOF){
        int k=judge(str); int cal=1;
        if (k!=-1){
            while (str[k]!='(' && str[k]!='\0'){
                if (str[k]!=' ') cal=0;
                k++; 
            }
            cc+=(cal==1);
        }
        for (int i=0; i<strlen(str); i++){
            if (str[i]=='?') cc++;
            if (str[i]==')'){
                if (strncmp(str+1+i,"for",3)==0) cc++;
            }
        }
    }
    printf("%d\n", cc);
}