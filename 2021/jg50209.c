#include <stdio.h>
#include <string.h>

int main(){
    char keyboard[3][12]={"qwertyuiop","asdfghjkl","zxcvbnm"};
    int dirr[6]={0,-1,-1,0,1,1};
    int dircol[6]={1,1,0,-1,-1,0};
    char start; int dir; int nr,nc;
    scanf("%c",&start);
    for (int i=0; i<3; i++){
        for (int j=0; j<12 && keyboard[i][j]!='\0'; j++){
            if (keyboard[i][j]==start){
                nr=i; nc=j;
            }
        }
    }
    printf("%c\n", start);
    int collll[3]={10,9,7};
    while(scanf("%d",&dir)!=EOF){
        int nowdirr,nowdirc;
        nowdirr=nr+dirr[dir]; nowdirc=nc+dircol[dir];
        if (nowdirr<0 || nowdirr>2 || nowdirc<0 || nowdirc>=collll[nowdirr]) continue;
        nr=nowdirr; nc=nowdirc;
        printf("%c\n",keyboard[nr][nc]);
    }
}