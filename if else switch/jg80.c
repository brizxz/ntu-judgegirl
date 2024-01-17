# include <stdio.h>
 
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        int x1,y1,x2,y2,x3,y3; int max;
        scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
        int a=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
        int b=(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
        int c=(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);
        if (a>=b && a>=c) max=a;
        else if (b>=a && b>=c) max=b;
        else max=c;
        if (a==b || c==b || a==c) printf("isosceles\n");
        else {
            if (max==a){
                if (b+c>a) printf("acute\n");
                else if (b+c==a) printf ("right\n");
                else printf("obtuse\n");
            }
            else if (max==b){
                if (a+c>b) printf("acute\n");
                else if (a+c==b) printf ("right\n");
                else printf("obtuse\n");
            }
            else {
                if (a+b>c) printf("acute\n");
                else if (b+a==c) printf ("right\n");
                else printf("obtuse\n");
            }
        }
    }
}