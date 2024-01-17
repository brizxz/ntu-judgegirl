#include <stdio.h>
int abs(int a){
  if (a<0) return -a;
  return a;
}
int main(){
    int n,k,m,d; int tester[10][10]; int testee[10][10]; int sumb=0;
    scanf("%d%d%d%d",&n,&k,&m,&d);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) scanf("%d",&tester[i][j]);
    }
    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            scanf("%d",&testee[i][j]); sumb+=testee[i][j];
        } 
    }   
    int suma=0; int nrow=0; int ncol=0; int diff=0;
    int ansrow=-1; int anscol=-1;
    for (int i=0; i<=n-k; i++){
        for (int j=0; j<=n-k; j++){
            for (int h=i; h<i+k; h++){
                for (int l=j; l<j+k; l++){
                    suma+=tester[h][l];
                    if (tester[h][l]!=testee[nrow][ncol]) diff++;
                    ncol++;
                }
                ncol=0; nrow++;
            }
            if (abs(suma-sumb)<=d && diff<=m){
                ansrow=i; anscol=j;
            }
            suma=nrow=ncol=diff=0;
        }
    }
    printf("%d %d",ansrow,anscol);
}