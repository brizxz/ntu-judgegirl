#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char hash[1000][10000][110];
int val(char str[110],int s){
    int sum=0;
    for (int i=0; i<strlen(str); i++){
        if ((str[i])<='9' && str[i]>='0') sum+=(str[i]-'0');
        else sum+=(str[i]);
    }
    return sum%s;
}
 
int insert(char hash[1000][10000][110],char str[110],int s){
    int key = val(str,s);
    int loc=0;
    while (strlen(hash[key][loc])!=0) loc++;
    strcpy(hash[key][loc],str);
    return key;
}
 
int search(char hash[1000][10000][110],char str[110],int s,int count[1000]){
    int key = val(str,s);
    for (int i=0; i<count[key]; i++){
        if (strcmp(hash[key][i],str)==0) return key;
    }
    return -1;
}
 
int main(){
    int s,n,q; int count[10000]={0};
    for (int i=0; i<s; i++) count[i]=0;
    scanf("%d%d%d",&s,&n,&q);
 char str[110]; char query[110];
    for (int i=0; i<n; i++){
        scanf("%s", str);
        count[insert(hash,str,s)]++;
    }
 
    for (int i=0; i<q; i++){
        scanf("%s",query);
        int ans=search(hash,query,s,count);
        if (ans!=-1) printf("%d\n",ans);
        else printf("%d\n",-1);
    }
}