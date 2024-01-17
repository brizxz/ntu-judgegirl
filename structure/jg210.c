#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// 使用strcmp會TLE，要判斷第一個char
int judge(char name[20]){
    if (name[0]=='l') return 0;
    if (name[0]=='f') return 1;
    if (name[0]=='I') return 2;
    if (name[0]=='s') return 3;
    if (name[0]=='a') return 4;
}
 
typedef struct DMS{
    char lastname[85];
    char firstname[85];
    char ID[85];
    int salary;
    int age;
} dms;
void printans(char find[8][10],int rem,dms da[50],int loc){
    for (int i=0;i<rem; i++){
        int k=judge(find[i]);
        if (k==0) printf("%s",da[loc].lastname);
        else if (k==1) printf("%s",da[loc].firstname);
        else if (k==2) printf("%s",da[loc].ID);
        else if (k==3) printf("%d",da[loc].salary);
        else  printf("%d",da[loc].age);        
        if (i!=rem-1) printf(" ");
        else printf("\n");
    }
}
 
void printint(int n,char find[8][10],int rem,dms da[50],char s[20],char o[5],char g[85]){
    int k=judge(s); 
    if (k==0){
        for (int i=0;i<n; i++){
            if (o[0]=='=' && strcmp(da[i].lastname,g)==0 || o[0]=='!' && strcmp(da[i].lastname,g)!=0) printans(find,rem,da,i);
        }
    }
    else if (k==1){
        for (int i=0;i<n; i++){
            if (o[0]=='=' && strcmp(da[i].firstname,g)==0 || o[0]=='!' && strcmp(da[i].firstname,g)!=0) printans(find,rem,da,i);
        }
    }
    else if (k==3){
        int c=atoi(g);
        for (int i=0;i<n; i++){
            if (o[0]=='>' && da[i].salary>c || o[0]=='<' && da[i].salary<c || o[0]=='=' && da[i].salary==c) printans(find,rem,da,i);
        }
    }
    else if (k==4){
        int c=atoi(g);
        for (int i=0;i<n; i++){
            if (o[0]=='>' && da[i].age>c || o[0]=='<' && da[i].age<c || o[0]=='=' && da[i].age==c) printans(find,rem,da,i);
        }
    }
    else{
        for (int i=0;i<n; i++){
            if (o[0]=='=' && strcmp(da[i].ID,g)==0 || o[0]=='!' && strcmp(da[i].ID,g)!=0) printans(find,rem,da,i);
        }       
    }
}
 
int main(){
    int n;
    scanf("%d",&n);
    dms data[50];
    memset(data,0, sizeof(data));
    for(int i=0; i<n; i++){
        scanf("%s%s%s%d%d",data[i].lastname,data[i].firstname,data[i].ID,&(data[i].salary),&(data[i].age));
    }
    int q;
    scanf("%d",&q);
    for (int i=0; i<q; i++){
        char instru[20];
        char find[8][10];
        int rem=0;
        scanf("%s",instru);
        while(scanf("%s", instru)!=EOF){
            if (strcmp(instru,"where")==0) break;
            strcpy(find[rem],instru); rem++;
        }
        char str[20];
        scanf("%s", str);
        char stroper[5]; char goal[85];
        scanf("%s%s", stroper,goal);
        printint(n,find,rem,data,str,stroper, goal);
    }
}