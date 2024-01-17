# include <stdio.h>
 
int main(){
    int s;
    scanf("%d",&s);
    if (s%3==0 && s%5==0 && s%7!=0) printf("%d\n",0);
    else printf("%d\n",1);
}