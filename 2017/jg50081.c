#include <stdio.h>
 
int main(){
    int n,m;
    scanf("%d%d", &n, &m); // 0-9 0-19
    int struc; int x=0; int y=0;
    printf("%d\n%d\n",x,y);
    while(scanf("%d", &struc)!=EOF){
        int direc = struc%5;
        if (direc==0) continue;
        else if (direc==1 && x+struc<=n-1){
            x+=struc; printf("%d\n%d\n",x,y);
        } 
        else if (direc==2 && x-struc>=0){
            x-=struc; printf("%d\n%d\n",x,y);
        } 
        else if (direc==3  && y+struc<=m-1){
            y+=struc; printf("%d\n%d\n",x,y);
        }
        else if (direc==4 && y-struc>=0){
            y-=struc; printf("%d\n%d\n",x,y);
        }
    }
}