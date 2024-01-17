#include <stdio.h>
#include <string.h>
int max(int a, int b,int c, int d){
    if (a>=b && a>=c && a>=d) return a;
    else if (b>=a && b>=c && b>=d) return b;
    else if (c>=b && c>=a && c>=d) return c;
    return d;
}
int find(char str[],int len,int loc,char c){
    if (loc>=len) return len+2; // 需設>len or will get segmentation fault
    if (str[loc]==c) return loc;
    return find(str,len,loc+1,c);
}

int cal (char str1[],int len1,int loc1,char str2[],int len2 ,int loc2,char str3[],int len3,int loc3){
    if (loc1>len1 || loc2>len2 || loc3>len3) return -1;
    if (loc1==len1 || loc2==len2 || loc3==len3) return 0;
    if (str1[loc1]==str2[loc2] && str1[loc1]==str3[loc3]) return 1+cal(str1,len1,loc1+1,str2,len2,loc2+1,str3,len3,loc3+1);
    else{
        return max(cal(str1,len1,loc1+1,str2,len2,loc2+1,str3,len3,loc3+1),
        1+cal(str1,len1,loc1+1,str2,len2,find(str2,len2,loc2,str1[loc1])+1,str3,len3,find(str3,len3,loc3,str1[loc1])+1),
        1+cal(str1,len1,find(str1,len1,loc1,str2[loc2])+1,str2,len2,loc2+1,str3,len3,find(str3,len3,loc3,str2[loc2])+1),
        1+cal(str1,len1,find(str1,len1,loc1,str3[loc3])+1,str2,len2,find(str2,len2,loc2,str3[loc3])+1,str3,len3,loc3+1));
    }
}

int main(){
    char str1[15]; char str2[15]; char str3[15];
    while(scanf("%s%s%s", str1, str2, str3)!=EOF){
        int len1 = strlen(str1); int len2= strlen(str2); int len3= strlen(str3);
        printf("%d\n",cal(str1,len1,0,str2,len2,0,str3,len3,0));
    }
}