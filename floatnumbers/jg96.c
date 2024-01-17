#include <stdio.h>
 
double min(double a, double b){
    if (a < b) return a;
    return b;
}
 
double max(double a, double b){
    if (a < b) return b;
    return a;
}
 
int main(){
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    double pi=3.1415926;
    double area;
    if (c<=min(a,b)) area = c*c*3*pi/4;
    else if (c>min(a,b)){
        if (c>=max(a,b)) area =c*c*3*pi/4 + (c-a)*(c-a)*pi/4 + (c-b)*(c-b)*pi/4;
        else area =c*c*3*pi/4 + (c-min(a,b))*(c-min(a,b))*pi/4;
    }
    printf("%lf\n",area);
}