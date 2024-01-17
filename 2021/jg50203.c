#include <stdio.h>
 
int find0(int a, int b, int c){
    if (a>b && a>c) return a;
    else if (b>=c && b>=a) return b;
    return c;
}
int find1(int a, int b, int c){
    if (c>a && c>b) return c;
    else if (b>=c && b>=a) return b;
    return a;
}
int find2(int a, int b, int c){
    if (a>=b && a>=c) return a;
    else if (b>=c && b>=a) return b;
    return c;
}
int find3(int a, int b, int c){
    if (a>b && a>=c) return a;
    else if (c>b && c>=a) return c;
    return b;
}
 
int main(){
    int ans[100000]={0};
    int n; int lcol,type;
    scanf("%d",&n);
    while(scanf("%d%d",&lcol,&type)!=EOF){
        if (type==0){
            int max = find0(ans[lcol],ans[lcol+1],ans[lcol+2]);
            if (max==ans[lcol+1] || max==ans[lcol+2]){
                ans[lcol] = ans[lcol+1] =max+2; ans[lcol+2] =max+1;
            }
            else{
                ans[lcol]=max+1; ans[lcol+1] =max+1; ans[lcol+2] = max;          
            }
        }
        else if (type==1){
            int max = find1(ans[lcol],ans[lcol+1],ans[lcol+2]);
            if (max==ans[lcol+1] || max==ans[lcol] ){
                ans[lcol+2] = ans[lcol+1] =max+2; ans[lcol] =max+1;
            }
            else{
                ans[lcol] =max; ans[lcol+1] = ans[lcol+2] = max+1;          
            }
        }
        else if (type==2){
            int max = find2(ans[lcol],ans[lcol+1],ans[lcol+2]);
            ans[lcol]=max+1; ans[lcol+1]=max+2; ans[lcol+2]=max+1;
        }
        else{
            int max = find3(ans[lcol],ans[lcol+1],ans[lcol+2]);
            if (max==ans[lcol+1] ) ans[lcol] = ans[lcol+1] = ans[lcol+2] = max+2;
            else  ans[lcol] = ans[lcol+1] = ans[lcol+2] = max+1;
        }
    }
    for (int i=0; i<n-1; i++) printf("%d ",ans[i]);
    printf("%d",ans[n-1]);
}