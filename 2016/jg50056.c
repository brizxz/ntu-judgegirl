#include <string.h>
#include <stdio.h>

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    char raw[100][60]; int qandp[100][2];
    for (int i=0; i<n; i++){
        scanf("%s%d%d",raw[i],&qandp[i][0],&qandp[i][1]);
    }
    char goods[60]; char ans[60]; int max=0; int num;
    for (int i=0; i<m; i++){
        scanf("%s%d",goods,&num);
        int sell; int cost=0; int maxamount=100000; int unitprice=0; int index[100];
        for (int j=0; j<num; j++){
            char ingre[60]; int unit=0; 
            scanf("%s%d",ingre,&unit);
            for (int k=0; k<n; k++){
                if (strcmp(ingre,raw[k])==0){
                    unitprice+=(qandp[k][1]*unit);                  
                    if ((qandp[k][0]/unit)<maxamount) maxamount=(qandp[k][0]/unit);
                    break;
                }
            }
        }
        cost = unitprice;
        scanf("%d",&sell);
        int profit=(sell-cost)*maxamount;
        if (profit>max || profit==max && strcmp(goods,ans)<0){
            max = profit; strcpy(ans,goods);
        }
    }
    printf("%s %d",ans,max);
}