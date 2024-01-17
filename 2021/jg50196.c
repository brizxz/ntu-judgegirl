#include <stdio.h>
 
int main(){
    int digit; int number=0;
    int ans = 0; int product=1;
 
    while(scanf("%d",&digit)!=0){
        if (digit==0) break;
        if (digit<=7 && digit>=1){
            number=number*10+digit;
        }
        else{
            number*=product;
            product=number;
            if (digit==8){
                ans+=number;
                product=1;
                number=0;
            }
            number=0;
        }
    }
    number*=product;
    ans+=number;
    printf("%d",ans);
}