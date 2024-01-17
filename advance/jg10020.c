#include <stdio.h>
#include <math.h>
 
int main(){
    double a,b,c;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF){
        double small = (-b-sqrt(b*b-4*a*c))/(2*a);
        double large = (-b+sqrt(b*b-4*a*c))/(2*a);
        printf("%.20f %.20f\n",small,large);
    }
}