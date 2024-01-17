# include <stdio.h>
 
int main(){
    int width, height;
    scanf("%d%d",&width,&height);
    int  a[100][100]; // a[5][4]
    for (int i=height-1; i>=0; i--){
        for (int j=0; j<width; j++){
            scanf("%d",&a[j][i]);
 
        }
    }
    int dx[4]={0,-1,0,1}; // 對應上左下右
    int dy[4]={1,0,-1,0};
    int newdir[4]={3,2,1,0}; // 重要 3:right 2:down 1:left 0:up
    int x,y,dir;
    for (int i=0; i<2*height+2*width; i++){
        if (i<width){
            x=i; y=0; dir=0;
        }
        else if (i<width+height){
            x=width-1; y= i-width; dir=1;
        }
        else if (i<2*width+height){
            y=height-1; dir=2; x=2*width+height-1-i;
        }
        else{
            x=0; y=2*width+2*height-i-1; dir=3;
        }
 
        while(x>=0 && x<width && y>=0 && y<height){
            if (a[x][y]) dir=newdir[dir];
            x+=dx[dir];
            y+=dy[dir];
        }
 
        if (y<0) printf("%d\n",x);
        else if (x>=width) printf("%d\n",width+y);
        else if (y>=height) printf("%d\n",height+width*2-x-1);
        else printf("%d\n", 2*(width+height)-y-1);
    }
}