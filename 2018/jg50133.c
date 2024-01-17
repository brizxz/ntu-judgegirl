#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// strlen strcpy strcmp
int key(char a[7],int s){
    int sum=0;
    for (int i=0; a[i]!='\0'; i++){
        int cal=a[i]-'a'+1;
        sum+=cal; sum*=29;
    }
    return sum%s;
}
 
int insert(char loc[110][110][110][7],char hash[10000][10][7],int place[10000][10][4],char str[7],int i,int j,int k,int n){
    if (i>n*n) return -1;
    int s=n*n;
    int ka = key(str,s);
    for (int i=0; i<10; i++){
        if (strcmp(str,hash[ka][i])==0 && place[ka][i][0]!=0) return i;
    }
    int loca=0;
    while ((place[ka][loca][0])!=0) loca++;
 
    strcpy (hash[ka][loca],str);
    place[ka][loca][0]=i; place[ka][loca][1]=j; place[ka][loca][2]=k;
    return -1;
}
void find(char loc[110][110][110][7],char hash[10000][10][7],int place[10000][10][4],char str[7],int i,int j,int k,int n){
    if (i>n) return;
    int s=n*n;
    int ka = key(str,s);
    int judge=insert(loc,hash,place,str,i,j,k,n);
    if (judge!=-1){
        printf("%s\n",str);
        int x=place[ka][judge][0]+1; int y=place[ka][judge][1]; int z=place[ka][judge][2];
        place[ka][judge][0]=0; place[ka][judge][1]=0; place[ka][judge][2]=0;
        find (loc,hash,place,loc[x][y][z],x,y,z,n);
        find (loc,hash,place,loc[i+1][j][z],i,j,k,n);
    }
}
 
int main(){
    int n; int s;
    scanf("%d",&n);
    s=n*n;
    char hash[10000][10][7]={{"\0"}}; char loc[110][110][110][7]={{{"\0"}}}; int place[10000][10][4]={{{0}}};
    for (int i=0; i<s; i++){
        for (int j=0; j<10; j++){
            hash[i][j][0]='\0';
            place[i][j][0]=place[i][j][1]=place[i][j][2]=place[i][j][3];
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            for (int k=1; k<=i; k++){
                scanf("%s",loc[i][j][k]);
                if (j>=i || k>=i){
                    int kkkkk=key(loc[i][j][k],s);
                    int loca=0;
                    while (place[kkkkk][loca][0]!=0){
                        loca++;
                    }
                    strcpy(hash[kkkkk][loca],loc[i][j][k]);
                    place[kkkkk][loca][0]=i; place[kkkkk][loca][1]=j; place[kkkkk][loca][2]=k;
                }
            }
        }
    }
    for (int i=0; i<s; i++){
        for (int j=0; j<10; j++){
            for (int k=j+1; k<10; k++){
                if ((place[i][k][0])==0 || place[i][j][0]==0) continue;
                if (strcmp(hash[i][j],hash[i][k])==0 ){
                    printf("%s\n",hash[i][j]);
                    char c[7]="\0";
                    strcpy(hash[i][j],c); strcpy(hash[i][k],c); 
                    int x1=place[i][j][0]+1; int y1=place[i][j][1]; int z1=place[i][j][2];
                    int x2=place[i][k][0]+1; int y2=place[i][k][1]; int z2=place[i][k][2];
                    place[i][j][0]=place[i][j][1]=place[i][j][2]=0;
                    place[i][k][0]=place[i][k][1]=place[i][k][2]=0;
                    find (loc,hash,place,loc[x1][y1][z1],x1,y1,z1,n);
                    find (loc,hash,place,loc[x2][y2][z2],x2,y2,z2,n);
                    return 0;
                }
            }
        }
    }
}