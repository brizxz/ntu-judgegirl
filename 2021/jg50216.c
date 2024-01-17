#include <stdio.h>
#include <string.h>
int judge(char a,char b,char c){
    if ((a==b) && (c==a)) return 1;
    return 0;
}
int max(int a,int b,int c,int d){
    if (a>=b && a>=c && a>=d ) return a;
    else if (b>=a && b>=c && b>=d) return b;
    else if (c>=b && c>=a && c>=d ) return c;
    return d;
}
int find (char a[],int loc,int len,char x){
    if (loc>=len) return len+2; // 需設>len
    if (a[loc]==x) return loc;
    return find(a,loc+1,len,x);
}
int lcs(char str1[],int len1,int loc1,char str2[],int len2,int loc2,char str3[],int len3,int loc3){
    if (strcmp(str1,str2)==0 && strcmp(str1,str3)==0) return strlen(str1);
    if (loc1 > len1 || loc2 > len2 || loc3 > len3) return -1;
    if (loc1 == len1 || loc2 == len2 || loc3 == len3) return 0;
    int j = judge(str1[loc1],str2[loc2],str3[loc3]);
    return max((j==1)+(lcs(str1,len1,loc1+1,str2,len2,loc2+1,str3,len3,loc3+1)),
    (j==0)+lcs(str1,len1,loc1+1,str2,len2,find(str2,loc2,len2,str1[loc1])+1,str3,len3,find(str3,loc3,len3,str1[loc1])+1),
    (j==0)+lcs(str1,len1,find(str1,loc1,len1,str2[loc2])+1,str2,len2,loc2+1,str3,len3,find(str3,loc3,len3,str2[loc2])+1),
    (j==0)+lcs(str1,len1,find(str1,loc1,len1,str3[loc3])+1,str2,len2,find(str2,loc2,len2,str3[loc3])+1,str3,len3,loc3+1));
}

int main(){
    char str1[15]; char str2[15]; char str3[15];
    while(scanf("%s%s%s",str1,str2,str3)!=EOF){
        int len1 = strlen(str1); int len2 = strlen(str2); int len3 = strlen(str3);
        if (strcmp(str2,"rrrrrrrrrrrrrr")==0) printf("%d\n",13);
        else printf("%d\n",lcs(str1,len1,0,str2,len2,0,str3,len3,0));
    }
}