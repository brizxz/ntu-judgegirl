#include <stdio.h>
#include <string.h>

int main(){
    char list[100][2][60]; char name[100]; int ans=0;
    int n; int count[100];
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%s%s",list[i][0],list[i][1]);
    }
    for (int i=0; i<n; i++){
        int sell; char book[60]; int find=0;
        scanf("%s%d",book,&sell);
        for (int j=0; j<n; j++){
            if (find == 1) break;
            if (strcmp(book,list[j][1])==0){
                find=1;
                for (int k=0; k<=j; k++){
                    if (strcmp(list[j][0],list[k][0])==0){
                        count[k]+=sell; break;
                    } 
                }
                break;
            }
        }
    }

    for (int i=0; i<n; i++){
        if (count[i]>ans || (count[i]==ans && strcmp(list[i][0],name)<0)){
            ans = count[i]; strcpy(name,list[i][0]);
        }
    }
    printf("%s %d",name,ans);
}