#include <stdio.h>
#include <stdbool.h>
 
 
void tiles(int i, int j, int facing, int size){
    #ifdef DEBUG
    printf("%d,%d %d %d\n", i, j, facing, size);
    #endif
    if(size==2)
        printf("%d %d %d\n", facing, i, j);
    else if(facing==1){
        tiles(i, j, 1, size/2);
        tiles(i-size/4, j-size/4, 1, size/2);
        tiles(i+size/4, j-size/4, 2, size/2);
        tiles(i-size/4, j+size/4, 4, size/2);
    }else if(facing==2){
        tiles(i, j, 2, size/2);
        tiles(i-size/4, j-size/4, 1, size/2);
        tiles(i+size/4, j-size/4, 2, size/2);
        tiles(i+size/4, j+size/4, 3, size/2);
    }else if(facing==3){
        tiles(i, j, 3, size/2);
        tiles(i+size/4, j-size/4, 2, size/2);
        tiles(i+size/4, j+size/4, 3, size/2);
        tiles(i-size/4, j+size/4, 4, size/2);
    }else if(facing==4){
        tiles(i, j, 4, size/2);
        tiles(i-size/4, j-size/4, 1, size/2);
        tiles(i+size/4, j+size/4, 3, size/2);
        tiles(i-size/4, j+size/4, 4, size/2);
    }
}
 
int main(){
    int l, m;
    scanf("%d%d", &l, &m);
    int i=l/2, j=i;
 
    while(l>m){
        tiles(i, j, 1, l);
        l/=2;
        i+=l/2;
        j+=l/2;
    }
 
}