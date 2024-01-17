#include <stdio.h>

int arr[1001][1001]={{0}};

int main(){
    int n,k,x,y;
    scanf("%d%d%d%d",&n,&k,&x,&y);
    if (k==1){
        arr[x][y]=k;
        while (k<=n*n){
            k++;
            if (arr[x-1][y+1]==0 && x-1>=0 && y+1<n){
                x-=1; y+=1; arr[x][y]=k;
            } 
            else{
                if (x-1<0 && y+1>=n && arr[n-1][0]==0){
                    x=n-1; y=0; arr[x][y]=k;
                } 
                else if (x-1<0 && y+1<n && arr[n-1][y+1]==0){
                    x=n-1; y+=1; arr[x][y]=k;
                } 
                else if (y+1>=n && x-1>=0 && arr[x-1][0]==0){
                    x-=1; y=0; arr[x][y]=k;
                }
                else if (arr[x+1][y]==0 && x+1<n){
                    x+=1; arr[x][y]=k;
                }
                else if (arr[0][y]==0 && x+1>=n){
                    x=0; arr[x][y]=k;
                }
            }
        }
    }
    else{
        arr[x][y]=k; int nvalue=k,nx=x,ny=y;
        while (nvalue>=2){ // reverse replace x=nx,y=ny,k=nvalue 
            nvalue--;
            if (arr[nx+1][ny-1]==0 && nx+1<n && ny-1>=0){
                nx+=1; ny-=1; arr[nx][ny]=nvalue;
            } 
            else{
                if (nx+1>=n && ny-1<0 && arr[0][n-1]==0){
                    nx=0; ny=n-1; arr[nx][ny]=nvalue;
                } 
                else if (nx+1>=n && arr[0][ny-1]==0){
                    nx=0; ny-=1; arr[nx][ny]=nvalue;
                } 
                else if (ny-1<0 && arr[nx+1][n-1]==0){
                    nx+=1; ny=n-1; arr[nx][ny]=nvalue;
                }
                else if (arr[nx-1][y]==0 && nx-1>=0){
                    nx-=1; arr[nx][ny]=nvalue;
                }
                else if (arr[n-1][ny]==0 && nx-1<0){
                    nx=n-1; arr[nx][ny]=nvalue;
                }
            }
        }    
        while (k<=n*n){
            k++;
            if (arr[x-1][y+1]==0 && x-1>=0 && y+1<n){
                x-=1; y+=1; arr[x][y]=k;
            } 
            else{
                if (x-1<0 && y+1>=n && arr[n-1][0]==0){
                    x=n-1; y=0; arr[x][y]=k;
                } 
                else if (x-1<0 && arr[n-1][y+1]==0){
                    x=n-1; y+=1; arr[x][y]=k;
                } 
                else if (y+1>=n && arr[x-1][0]==0){
                    x-=1; y=0; arr[x][y]=k;
                }
                else if (arr[x+1][y]==0 && x+1<n){
                    x+=1; arr[x][y]=k;
                }
                else if (arr[0][y]==0 && x+1>=n){
                    x=0; arr[x][y]=k;
                }
            }
        }         
    }


    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (j==0) printf("%d",arr[i][j]);
            else printf(" %d",arr[i][j]);
        }
        printf("\n");
    }
}