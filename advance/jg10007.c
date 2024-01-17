# include <stdio.h>
 
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int num; int prev; int sum = 0;
        for (int i=0; i<n; i++){
            scanf("%d",&num);
            if (i==0){
                prev = num; sum ++;
                continue;
            }
            if (num!=prev) sum ++;
            prev = num;
        }
        printf("%d\n",sum);
    }
}