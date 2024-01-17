#include <stdio.h>
#include <string.h>
 
void sortfood(char ans[10][70],int n){
    char c[70];
    if (n==2){
        if (strcmp(ans[0],ans[1])>0){
            strcpy(c,ans[0]);
            strcpy(ans[0],ans[1]);
            strcpy(ans[1],c);
        }
    }
    else{
        for (int i=n-2; i>=0; i--){
            for (int j=0; j<=i; j++){
                if (strcmp(ans[j],ans[j+1])>0){
                    strcpy(c,ans[j]);
                    strcpy(ans[j],ans[j+1]);
                    strcpy(ans[j+1],c);
                }
            }
        }
    }
}
 
int main(){
    int n;
    char food[100][10][70]; char foodname[100][70];
    int foodnum[100];
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%s",foodname[i]);
        int num;
        scanf("%d",&num); 
        foodnum[i]=num;
        for (int j=0; j<num; j++){
            scanf("%s",food[i][j]);
        }
    }
    int q;
    scanf("%d",&q);
    for (int i=0; i<q; i++){
        char q1[70]; char q2[70];
        scanf("%s%s",q1,q2);
        int loc1, loc2;
        for (int j=0; j<n; j++){
            if (strcmp(foodname[j],q1)==0) loc1=j;
            if (strcmp(foodname[j],q2)==0) loc2=j;
        }
        int find=0;
        char ans[10][70];
        for (int i=0; i<foodnum[loc1]; i++){
            for (int j=0; j<foodnum[loc2]; j++){
                if (strcmp(food[loc1][i],food[loc2][j])==0){
                    strcpy(ans[find],food[loc1][i]);
                    find++;
                } 
            }
        }
        sortfood(ans,find);
        for (int i=0; i<find; i++){
            if (i==0) printf("%s",ans[i]);
            else printf(" %s",ans[i]);
        }
        if (find==0) printf("nothing\n");
        else printf("\n");
    }
}