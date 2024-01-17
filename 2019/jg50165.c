#include <stdio.h>
#include <math.h>

int main(){
    int n; double equa[3][251]; double ans[2][251];
    scanf("%d",&n);
    double a,b,c; double peri=0;
    for (int i=0; i<n; i++) scanf("%lf%lf%lf",&equa[0][i],&equa[1][i],&equa[2][i]);
    for (int i=0; i<n-1; i++){
        double tri = (equa[0][i]*equa[1][i+1]-equa[0][i+1]*equa[1][i]);
        double trix = (equa[2][i+1]*equa[1][i]-equa[2][i]*equa[1][i+1]); 
        double triy = (equa[2][i]*equa[0][i+1]-equa[2][i+1]*equa[0][i]);
        ans[0][i] = trix/tri; ans[1][i] = triy/tri;
    }
    double last = equa[0][0]*equa[1][n-1]-equa[1][0]*equa[0][n-1];
    double lastx = equa[1][0]*equa[2][n-1]-equa[2][0]*equa[1][n-1];
    double lasty = equa[2][0]*equa[0][n-1]-equa[2][n-1]*equa[0][0];
    ans[0][n-1] = lastx/last; ans[1][n-1] = lasty/last; 
    ans[0][n] = (equa[2][1]*equa[1][0]-equa[2][0]*equa[1][1])/(equa[0][0]*equa[1][1]-equa[1][0]*equa[0][1]);
    ans[1][n] = (equa[2][0]*equa[0][1]-equa[2][1]*equa[0][0])/(equa[0][0]*equa[1][1]-equa[1][0]*equa[0][1]);
    for (int i=0; i<n; i++){
        peri += sqrt((ans[0][i+1]-ans[0][i])*(ans[0][i+1]-ans[0][i])+(ans[1][i+1]-ans[1][i])*(ans[1][i+1]-ans[1][i]));
    }
    printf("%.3lf",peri);

}