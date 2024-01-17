#include <stdio.h>

int main(){
    int n,m; // n:image 
    scanf("%d%d",&n,&m);
    int threshold = 2*m*m; int weight[20][20]; 
    for (int i=0; i<m; i++){
        for (int j=0; j<m; j++) weight[i][j]=1;
    }
    // step 1
    for (int i=0; i<n; i++){
        int ans; int sum=0; int test[20][20];
        scanf("%d",&ans);
        for (int k=0; k<m; k++){
            for (int j=0; j<m; j++){
                scanf("%d",&test[k][j]);
                sum+= (weight[k][j]*test[k][j]);
            }
        }
        int result = (sum>=threshold);
        if (result==ans) continue;
        else{
            for (int k=0; k<m; k++){
                for (int j=0; j<m; j++){
                    if (result==1 && test[k][j]!=0) weight[k][j]= ((weight[k][j]/2)+((weight[k][j]/2)==0));
                    else{
                        if(test[k][j]!=0) weight[k][j]*=2;
                    }
                }
            }
        }
    }
    // step2
    int q; int judge[20][20];
    scanf("%d",&q);
    for (int i=0; i<q; i++){
        int sum=0;
        for (int j=0; j<m; j++){
            for (int k=0; k<m; k++){
                scanf("%d",&judge[j][k]);
                sum+= (weight[j][k]*judge[j][k]);
            }
        }
        printf("%d\n",(sum>=threshold));
    }
}