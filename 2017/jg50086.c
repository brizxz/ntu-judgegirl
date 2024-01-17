#include <stdio.h>
#define MAX_STUDENT 32768
#define MAX_FRIEND 256
// 當array使用的記憶體太大時，建在外面才對 不然會RE why??
int stu[MAX_STUDENT][MAX_FRIEND]={ {0} }; 
int stustatus[MAX_STUDENT]={0}; 
int stucount[MAX_STUDENT]={0};

int main(){
    int n,e; // point and line
    scanf("%d%d",&n,&e);
    for (int i=0; i<e; i++) {
        int rela,relb;
        scanf("%d%d",&rela,&relb);
        stu[rela][stucount[rela]] = relb; stucount[rela]++;
        stu[relb][stucount[relb]] = rela; stucount[relb]++;
    }

    int sender;
    while(scanf("%d",&sender) != EOF){
        stustatus[sender]=1;
        for (int i=0; i<=stucount[sender]; i++){
            stustatus[stu[sender][i]]=1;
        }
    }
    for (int i=0; i<n; i++){
        if (stustatus[i]==0) printf("%d\n",i);
    }
}