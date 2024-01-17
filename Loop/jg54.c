# include<stdio.h>
 
void place(int a[10],int n){
    for (int i=6; i>=0; i--){
        a[i]=n%10;
        n/=10;
    }
}
 
int main(){
    int a[10];
    int m,n; int count = 0;
    scanf("%d%d",&m,&n);
    int ten=m/10,ind=m%10;
    place(a,n);
    for (int i=0; i<6; i++){
        if (ten==a[i] && ind==a[i+1]) count++;
    }
 
    printf("%d\n",count);
}