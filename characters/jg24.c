#include <stdio.h>
#include <string.h>
 
int abs(int x) { 
    if (x < 0) return -x;
    return x;
}
 
int main(){
    char str[108];
    scanf("%s", str);
    int digits=0; int alpha=0; int vowel=0; int consonant=0;
    for (int i=0; i<strlen(str); i++) {
        if (str[i]<='9' && str[i]>='0') digits++;
        if ((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            alpha++;
            if (str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' ||
             str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' ) vowel++;
            else consonant++; 
        }
    }
    printf("%d %d %d %d\n",digits,alpha, vowel, consonant);
 
}