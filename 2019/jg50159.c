#include <stdio.h>
void swap(int arr[3],int n){
    arr[0]=arr[1]; arr[1]=n-1; arr[2]=n;
}
 
int main(){
    int ans[3]={0,0,0};int count[3]={0,0,0}; int index=1; int prev; int prev_d=-2;int find=0;
    int price;
    while(scanf("%d",&price) != EOF){
        if (index==1){
            ans[0] = count[0] = 1; prev=price; index++; continue;
        }
 
        if (prev_d!=-2 && (price>prev)!=prev_d && find==0){ 
            count[1]=ans[1]=(index-1); find=2; count[2]=ans[2]=(index);
        }
        else if (prev_d!=-2 && (price>prev)!=prev_d && find==2) swap(count,index);
        else if ((price>prev)==prev_d && prev_d!=-2 && find==2) count[2]=index;
        if (count[2]-count[0]>ans[2]-ans[0] || (count[2]-count[0]==ans[2]-ans[0]
        && count[1]-count[0]>ans[1]-ans[0])) for (int i=0; i<3; i++) ans[i]=count[i];
        index++; prev_d=(price>prev);  prev=price; // + up - down
    };
    if (ans[2]==0) printf("%d",0);
    else printf("%d %d",ans[2]-ans[0]+1,ans[0]);
}