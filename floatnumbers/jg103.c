# include <stdio.h>
 
int main(){
    double result[18][18];
    int n;
    double y[18]; double x[18];
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) {
            scanf("%lf", &result[i][j]);
        }
    }
    for (int i=0; i<n; i++) scanf("%lf", &y[i]);
    // x3 = y3/A3,3
    int count = n-1;
    for (int i=n-1; i>=0; i--){
        for (int j=n-1; j>=count; j--){
            if (j==count){
                x[i] = (y[i]/result[i][j]);
            }
            else{
                y[i]-= (result[i][j]*x[j]);
            }
        }
        count--;
    }
    for (int i=0; i<n; i++) printf("%f\n",x[i]);
}