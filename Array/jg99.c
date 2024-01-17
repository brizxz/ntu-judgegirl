#include <stdio.h>,
 
int judgex(int x,int m,int play[m][m]){
    for (int i=0;i<m; i++) if (play[x][i]!=0 ) return 0;
    return 1;
}
int judgey(int y,int m,int play[m][m]){
    for (int i=0;i<m; i++) if ( play[i][y] !=0) return 0;
    return 1;
}
int judgediag1(int m,int play[m][m]){
    for (int i=0;i<m;i++) if (play[i][i]!=0 ) return 0;
    return 1;
}
int judgediag2(int m,int play[m][m]){
    for (int i=0;i<m;i++) if ( play[i][m-i-1] !=0) return 0;
    return 1;
}
 
int main(){
    int n,m; char player[10][70];
    scanf("%d%d",&n,&m);
    int play[n][m][m]; int place[n][m*m];
    for (int i=0;i<n;i++){
        scanf("%s",player[i]);
        for (int j=0;j<m;j++){
            for (int k=0;k<m;k++){
                scanf("%d",&play[i][j][k]);
                place[i][play[i][j][k]] = j*m+k;
            }
        }
    }
    int count1=0; int digit; int status=1;  int win[10]; int count2=0;
    while (scanf("%d",&digit)!=EOF){
        count1++;
        for (int i=0;i<n;i++){
            int x=place[i][digit]/m; int y=place[i][digit]%m;
            play[i][x][y] = 0;
        }
        if (count1>=m-1){
            for (int i=0;i<n;i++){
                int x=place[i][digit]/m; int y=place[i][digit]%m;
                if (judgex(x,m,play[i])+judgey(y,m,play[i])+judgediag1(m,play[i])+judgediag2(m,play[i])!=0){
                    status=0; win[count2]=i; count2++;
                }
            }
        }
 
        if (status==0) break;
    }
    printf("%d",digit);
    for (int i=0;i<count2;i++){
        printf(" %s",player[win[i]]);
    }
}