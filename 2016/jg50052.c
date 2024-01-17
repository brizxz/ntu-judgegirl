#include <stdio.h>
#include <string.h>
int abs(int x) {
    if (x < 0) return -x;
    return x;
}

int mean(char a[50][12],int count,int l){
    int sum=0;
    for (int i=0;i<count;i++) sum+=a[i][l];
    sum/=count; 
    return (char)sum;
}

int d(char a[12],char b[12],int l){
    int sum=0;
    for (int i=0;i<l; i++) sum+=(abs(a[i] - b[i]));
    return sum;
} 

int findgroup(char a[12],char b[12],char c[12],char judge[12],int l){
    int choose=1;
    if (d(b,judge,l)<d(a,judge,l) || d(b,judge,l)==d(a,judge,l) && strcmp(b,a)<0) choose=2;
    if (choose==1){
        if (d(c,judge,l)<d(a,judge,l) || d(c,judge,l)==d(a,judge,l) && strcmp(c,a)<0) choose=3;
    }
    else{
        if (d(c,judge,l)<d(b,judge,l) || d(c,judge,l)==d(b,judge,l) && strcmp(c,b)<0) choose=3;
    }
    return choose;
}

int main(){
    int n,l,r; char store[50][12];
    scanf("%d%d%d",&n,&l,&r);
    char lead1[12]; char lead2[12]; char lead3[12];
    for (int i=0;i<n; i++){
        scanf("%s",store[i]);
        if (i==0) strcpy(lead1,store[i]);
        else if (i==1) strcpy(lead2,store[i]);
        else if (i==2) strcpy(lead3,store[i]);
    }
    for (int i=0; i<r; i++){
        char group1[50][12], group2[50][12], group3[50][12];
        strcpy(group1[0],lead1); strcpy(group2[0],lead2); strcpy(group3[0],lead3);
        int c1=1,c2=1,c3=1;
        for (int j=0;j<n; j++){
            if (strcmp(store[j],lead1)==0 || strcmp(store[j],lead2)==0 || strcmp(store[j],lead3)==0) continue;
            if (findgroup(lead1,lead2,lead3,store[j],l)==1){
                strcpy(group1[c1],store[j]); c1++;
            }
            else if(findgroup(lead1,lead2,lead3,store[j],l)==2){
                strcpy(group2[c2],store[j]); c2++;
            }
            else{
                strcpy(group3[c3],store[j]); c3++;
            }
        }
        char mean1[12],mean2[12],mean3[12];
        for (int j=0; j<l; j++){
            mean1[j] = mean(group1,c1,j);
            mean2[j] = mean(group2,c2,j);
            mean3[j] = mean(group3,c3,j);
        }
        int d1=1000,d2=1000,d3=1000; char new1[12],new2[12],new3[12]; 
        for (int j=0; j<c1; j++){ 
            if (d(group1[j],mean1,l)<d1 || d(group1[j],mean1,l)==d1 && strcmp(group1[j],new1)<0){
                strcpy(new1,group1[j]); d1 = d(group1[j],mean1,l);
            } 
        }
        for (int j=0; j<c2; j++){ 
            if (d(group2[j],mean2,l)<d2 || d(group2[j],mean2,l)==d2 && strcmp(group2[j],new2)<0){
                strcpy(new2,group2[j]); d2 = d(group2[j],mean2,l);
            } 
        }
        for (int j=0; j<c3; j++){ 
            if (d(group3[j],mean3,l)<d3 || d(group3[j],mean3,l)==d3 && strcmp(group3[j],new3)<0){
                strcpy(new3,group3[j]); d3 = d(group3[j],mean3,l);
            }
        }
       // printf("leader: %s %s %s\n",lead1,lead2,lead3);
      //  printf("%d %d %d\n",c1,c2,c3);
        strcpy(lead1,new1); strcpy(lead2,new2); strcpy(lead3,new3);
    }
    char ans[3][12];
    strcpy(ans[0],lead1); strcpy(ans[1],lead2); strcpy(ans[2],lead3);
    for (int i=1; i>=0; i--){
        for (int j=0; j<=i; j++){
            if (strcmp(ans[j],ans[j+1])>0){
                char k[12];
                strcpy(k,ans[j]);
                strcpy(ans[j],ans[j+1]);
                strcpy(ans[j+1],k);
            }
        }
    }
    printf("%s\n%s\n%s\n",ans[0],ans[1],ans[2]);
}