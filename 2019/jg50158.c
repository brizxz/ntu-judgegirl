#include <stdio.h>
 
int max(int a, int b,int c){
    if (a > b && a>c) return a;
    else if (b > c && b>a) return b;
    else if (c > a && c>b) return c;
    return -3;
}
int min(int a, int b,int c){
    if (a < b && a<c) return a;
    else if (b < c && b<a) return b;
    else if (c < a && c<b) return c;
    return -3;
}
 
void move(int a[],int num){
    int temp = a[2];
    a[2] = num; a[0] = a[1]; a[1] = temp;
}
 
int main(){
    int a,b,c,d,e; 
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    int num;int judgeif=0;  int counts=0; int persist[3]; int cor[3];
    while(scanf("%d", &num) != EOF){
        int cal=0; int number=num;
        while(number>e || number<d){
            number=(a*number+b)%c; cal++;
        }
        if (counts<3){
            persist[counts] = cal; cor[counts] = num;
        }
        else{
            move(persist,cal); move(cor,num);
        }
        if (counts>=2){
            int k= min(persist[0],persist[1],persist[2]); int j=max(persist[0],persist[1],persist[2]);
            if (j-k==2 && (persist[0]==k+1 || persist[1]==k+1 || persist[2]==k+1)){
                judgeif =1;  break;
            }
        }
        counts++;
    }
    if (judgeif==0) printf("Not found\n");
    else printf("%d %d %d\n",cor[0],cor[1],cor[2]);
}