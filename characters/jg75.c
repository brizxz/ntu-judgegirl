# include <stdio.h>
# include <string.h>
 
int main(){
    char str[120]; int alpha[30]={0};
    scanf("%s",str);
    for (int i=0; i<strlen(str); i++){
        if (str[i]<='Z' && str[i]>='A') alpha[str[i]-65]++;
        else if (str[i]>='a' && str[i]<='z') alpha[str[i]-97]++;
    }
    for (int i=0; i<26; i++){
        printf("%d\n",alpha[i]);
    }
}