#include <stdio.h>
int min(int a, int b){
    if (a < b) return a;
    return b;
}
int max(int a, int b){
    if (a > b) return a;
    return b;
}
int main(){
    int n,m; int dx[4]={1,-1,0,0}; int dy[4]={0,0,1,-1}; int taildir[1000000];
    scanf("%d%d", &n, &m); 
    int sx,sy,ex,ey; int arr[1000][1000]={0}; int count=0;
    scanf("%d%d%d%d", &sx,&sy,&ex,&ey); // head and tail
    if (sx==ex){
        count=max(sy,ey)-min(sy,ey);
        for (int i=min(sy,ey); i<=max(sy,ey); i++) arr[sx][i]=1;
        if (sy>ey) for (int i=0; i<sy-ey; i++) taildir[i]=2;
        else for (int i=0; i<ey-sy; i++) taildir[i]=3;
    }
    else{
        count=max(sx,ex)-min(sx,ex);
        for (int i=min(sx,ex); i<=max(sx,ex); i++) arr[i][sy]=1;
        if (sx>ex) for (int i=0; i<sx-ex; i++) taildir[i]=0;
        else for (int i=0; i<ex-sx; i++) taildir[i]=1;
    } 
    int q; int dir;
    scanf("%d",&q); 
    for (int i=0; i<q; i++){
        scanf("%d",&dir); taildir[count]=dir; count++;
        if ((arr[sx+dx[dir]][sy+dy[dir]]==1 && !(sx+dx[dir]==ex && sy+dy[dir]==ey)) || sx+dx[dir]<0 ||
         sx+dx[dir]>=n || sy+dy[dir]<0 || sy+dy[dir]>=m) break;
        arr[ex][ey]=0; sx+=dx[dir]; sy+=dy[dir]; arr[sx][sy]=1; ex+=dx[taildir[i]]; ey+=dy[taildir[i]];
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
}