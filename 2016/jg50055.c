#include <stdio.h>

int main(){
    int n,m; // server,customer
    scanf("%d%d",&n,&m); int time[1024]; int ans=0;
    for (int i=0; i<n; i++) time[i]=0;
    for (int i=0; i<m; i++){
        int arrive,check; int small=1000000; int loc=0;
        scanf("%d%d",&arrive,&check);
        for (int j=0; j<n; j++){
            if (time[j]<small){
                small=time[j]; loc=j;
            } 
        }
        if (arrive<time[loc]){
            ans+=(time[loc]-arrive);
            time[loc]+=check;             
        } 
        else{
            time[loc]=arrive+check;
        } 
    }
    printf("%d",ans);
}