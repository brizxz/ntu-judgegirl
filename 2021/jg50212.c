#include <stdio.h>
#include <string.h>
int countbit(unsigned int a, int bit,int loc){
    int sum=0; unsigned int b=a;
    for (int i=0; i<32; i++){
        if (b&1!=0 && i>=loc && i<loc+bit) sum+=1;
        b>>=(1);
    }
    return sum;
}

unsigned int x(unsigned int a,int bit,int loc){
    // printbit(a);
    if (bit==1) return a;
    int bits= countbit(a,bit,loc);
    unsigned int x1 = (a>>(bit/2+loc)); unsigned int x2 = (a<<(32-bit/2-loc)) ;
    if (bits%2==0){  
        x1<<=(bit/2+loc);  x2>>=((32-bit/2-loc)); 
        return x(x1,bit/2,bit/2+loc) | x(x2,bit/2,loc);
    } 
    else{        
        x1<<=(loc);  x2>>=((32-bit-loc)); 
        return x(x2,bit/2,bit/2+loc) | x(x1,bit/2,loc);
    } 
}


int main(){
    unsigned int a; int num=32;
    scanf("%u",&a);
    a = x(a,32,0);
    printf("%u\n",a);
}