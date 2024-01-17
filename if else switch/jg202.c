#include <stdio.h>
 
int abs(int x) {
    if (x < 0) return -x;
    return x;
}
 
int gcd(int x, int y){
    if (x==0) return 1;
    while (x%y!=0){
        int temp = x%y;
        x=y;
        y=temp;
    }
    return y;
}
 
int main(){
    int a,b,c,d,e,f,g;
    int x,y,z;
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
    int h,i,j;
    int newb= (a < 0? a * c - b : a * c + b);
    int newf= (e < 0? e * g - f : e * g + f);
    switch (d){
        case 0:
            i= g * newb + c * newf;  j=c*g;
            h=i/j;  i=abs(i)%j;
        break;
 
        case 1:
            i= g * newb - c * newf;  j=c*g;
            h=i/j;  i=abs(i)%j;       
        break;
 
        case 2:
            i= newb * newf;  j=c*g;
            h=i/j;  i=abs(i)%j;
        break;
 
        case 3:
            i= newb * g; j=c*newf; h=i/j;
            if (i<0 && j<0){
                i=abs(i); j=abs(j);
            }
            else if (i<0 && j>0) i=abs(i);
            else if (i>0 && j<0){
                j=abs(j);
            }
            i%=j;
        break;
 
        default:
        break;
    }
 
    if (i==0) j=1;
    else{
    int factor=gcd(j,i);
    i/=factor; j/=factor;
    }
    printf("%d\n%d\n%d\n",h,i,j);
}