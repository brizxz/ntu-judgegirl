#include <stdio.h>

int judge(int c,int a,int b,int status[100][100]){
    if (a<0 || a>=c || b<0 || b>=c || status[a][b]==1) return 0;
    return 1;
}
int judge1(int find[10001],int m){
    for (int i=1;i<=m; i++){
        if (find[i]==0) return 1;
    }
    return 0;
}

int main(void){
    int n,m; int arr[100][100]={{0}}; int status[100][100]={{0}};int find[10001]={{0}};  
    scanf("%d%d",&n,&m); 
    int place[10001][2]; int step[10001]={0}; int row,col;
    for (int i=1; i<=m; i++){
        scanf("%d%d",&row,&col); 
        place[i][0]=row; place[i][1]=col;
        status[row][col]=1; arr[row][col]=i*10000; 
        step[i]=1; find[i]=0;
    }
    int da=1;
    int dir[9][2]={{0,0},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}}; 

    while (judge1(find,m)==1 ){
        if (find[da]==1){
            da++; continue;
        } 
        int key=(da%m==0)?m:da%m;
        int count[9]={0,0,0,0,0,0,0,0,0}; int st[9]={0,0,0,0,0,0,0,0,0};
        int max=100; int maxindex=-1;
        for (int j=1; j<=8; j++){
            if (judge(n,place[key][0]+dir[j][0],place[key][1]+dir[j][1],status)==0) continue;
            st[j]=1; // status[place[key][0]+dir[j][0]][place[key][1]+dir[j][1]]=1;
            for (int k=1; k<=8; k++){
                if (judge(n,place[key][0]+dir[j][0]+dir[k][0],place[key][1]+dir[j][1]+dir[k][1],status)==0) continue;
                else count[j]+=1;
            }
  //          status[place[key][0]+dir[j][0]][place[key][1]+dir[j][1]]=0;
        }
        for (int l=1; l<=8; l++){
            if (count[l]<max && st[l]!=0){
                max=count[l]; maxindex=l;
            } 
        }
    //    printf("k %d %d  %d k",count[5],count[6],step[key]);
        if (maxindex==-1){
            find[key]=1; da++; continue;
        }
        place[key][0]+=dir[maxindex][0]; place[key][1]+=dir[maxindex][1];
        arr[place[key][0]][place[key][1]]=key*10000+step[key]; step[key]++;
        status[place[key][0]][place[key][1]]=1;
        da++;
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (j==0) printf("%d", arr[i][j]); 
            else printf(" %d",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}