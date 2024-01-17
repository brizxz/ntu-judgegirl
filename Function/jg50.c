#include <stdio.h>
 
int abs(int x) {
    if (x < 0) return -x;
    return x;
}
 
int area(int a,int b,int c,int d){
    return (abs((c-a)*(d-b)));
}
 
int min(int x,int y){
    if (x < y) return x;
    return y;
}
int max(int x,int y){
    if (x < y) return y;
    return x;
}
 
int judge(int lx1,int ly1,int rx1,int ry1, int lx2,int ly2,int rx2,int ry2){
    if (lx1>=rx2 || ly1>=ry2 || rx1<=lx2 || ry1<=ly2) return 0;
    return 1;
}
 
int main(){
    int lx1,ly1,rx1,ry1;
    scanf("%d%d%d%d",&lx1,&ly1,&rx1,&ry1);
    int lx2,ly2,rx2,ry2;
    scanf("%d%d%d%d",&lx2,&ly2,&rx2,&ry2);
    int lx3,ly3,rx3,ry3;
    scanf("%d%d%d%d",&lx3,&ly3,&rx3,&ry3);
    int result=0;
    result= area(lx1,ly1,rx1,ry1)+area(lx2,ly2,rx2,ry2)+area(lx3,ly3,rx3,ry3);
    int overlap12=judge(lx1,ly1,rx1,ry1,lx2,ly2,rx2,ry2);
    int overlap13=judge(lx1,ly1,rx1,ry1,lx3,ly3,rx3,ry3);
    int overlap23=judge(lx2,ly2,rx2,ry2,lx3,ly3,rx3,ry3); 
    if (overlap12==1) result-= (area(max(lx1,lx2),max(ly1,ly2),min(rx2,rx1),min(ry2,ry1)));
    if (overlap13==1) result-= (area(max(lx1,lx3),max(ly1,ly3),min(rx3,rx1),min(ry3,ry1)));
    if (overlap23==1) result-= (area(max(lx3,lx2),max(ly3,ly2),min(rx2,rx3),min(ry2,ry3)));
 
    if (overlap13==1 && overlap23==1 && overlap12==1){
        result+= (area(max(max(lx1,lx2),lx3),max(max(ly1,ly2),ly3),min(min(rx2,rx1),rx3),min(min(ry2,ry1),ry3)));
    }
    printf("%d\n",result);
 
}