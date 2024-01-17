#include <stdio.h>

double pow1(double x, double y){
    double sum=1;
    if (y==0) return 1;
    else{
        for (int i=1; i<=y; i++) sum*=x;
    }
    return sum;
}

double calfx(double arr[12],int d,double x){
    double sum=0;
    for (int i=0;i<=d;i++){
        sum+=(arr[i]*pow1(x,d-i));
    }
    return sum;
}
double calfplunx(double arr[11],int d,double x){
    double sum=0;
    for (int i=0;i<=d-1;i++){
        sum+=(arr[i]*pow1(x,d-i-1));
    }
    return sum;
}

int main(){
    int kk; double arr[12];
    scanf("%d",&kk); 
    int count=kk;
    for (int i=0; i<=kk; i++) scanf("%lf",&arr[i]);
    double fplun[11];
    for (int i=0; i<=kk-1; i++){
        fplun[i] = (arr[i]*count); count--;
    } 
    int iter; double x; double prex,prey,prefpluny;
    scanf("%d%lf",&iter,&x);
    for (int i=0; i<iter; i++){
        double nx,ny;
        double fpluny;
        if (i==0){
            nx=x;
            ny = calfx(arr,kk,x);
            fpluny = calfplunx(fplun,kk,x);
        }
        else{
            nx = prex-(prey/prefpluny);
            ny = calfx(arr,kk,nx);
            fpluny = calfplunx(fplun,kk,nx);
        }
        printf("%.4f %.4f\n",nx,ny);
        prex = nx; prey = ny; prefpluny=fpluny;
    }
}