#include "fraction.h"
#define ll long long
 
ll int gcd(ll int x,ll int y){
 
    if (y>x){
       ll int temp1 = x;
       x=y;
       y=temp1;
    }
    while(x%y!=0){
        ll int temp=x%y;
        x=y;
        y=temp;
    }
    return y;
}
 
ll int maxmulti(ll int x, ll int y){
    ll int result = x*y/gcd(x,y);
    return result;
}
 
Frac normal(long long a, long long b) {
    /* add your code */
    Frac c;
    if (a==0){
        c.a=a;
        c.b=b;
    }
    else{
        c.a = (a/gcd(a,b));
        c.b = (b/gcd(a,b));
    }
 
    return c;
}
Frac add(Frac x, Frac y) {
    /* add your code */
    Frac z;
    if (x.a==0){
        z.a= y.a; z.b=y.b;
    }
    else if (y.a==0){
        z.a= x.a; z.b=x.b;
    }
    else{
        z.b = maxmulti(x.b,y.b);
        z.a = (x.a*z.b/x.b+y.a*z.b/y.b);
        z= normal(z.a,z.b);
    }
    return z;
}
Frac subtract(Frac x, Frac y) {
    /* add your code */
    Frac z;
    if (x.a==0){
        z.a= y.a; z.b=y.b;
    }
    else if (y.a==0){
        z.a= x.a; z.b=x.b;
    }
    else{
        z.b = maxmulti(x.b,y.b);
        z.a = (x.a*z.b/x.b-y.a*z.b/y.b);
        z= normal(z.a,z.b);
    }
    return z;
}
Frac multipy(Frac x, Frac y) {
    /* add your code */
    Frac z;
    if (x.a==0){
        z.a= 0; z.b=1;
    }
    else if (y.a==0){
        z.a=0; z.b=1;
    }
    else{
        z.b = x.b*y.b;
        z.a = x.a*y.a;
        z= normal(z.a,z.b);
    }
    return z;
}
Frac divide(Frac x, Frac y) {
    /* add your code */
    Frac z;
    if (x.a==0){
        z.a= 0; z.b=1;
    }
    else if (y.a==0){
        z.a=0; z.b=1;
    }
    else{
        z.b = x.b*y.a;
        z.a = x.a*y.b;
        z= normal(z.a,z.b);
    }
    return z;
}