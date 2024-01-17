#include "value.h"
 
int gcd(int x, int y){
    while(x%y!=0){
        int temp = x%y;
        x=y; y=temp;
    }
    return y;
}
 
int value(int type, int width, int height, int length){
    if (type!=79 && type!=47 && type!=29 && type!=82 && type!=26 && type!=22 ) return -1;
    // 30 10 4 5 3 9 
    if (width<=0 || height<=0 || length<=0) return -2;
    int maxblock = gcd(gcd(width,length), height); int newblock = maxblock*maxblock*maxblock; // volume
    int blockamount = width*height*length/(maxblock*maxblock*maxblock);
    if (type==79) return 30*newblock*newblock*blockamount;
    else if (type==47) return 10*newblock*newblock*blockamount;
    else if (type==29) return 4*newblock*newblock*blockamount;
    else if (type==82) return 5*newblock*newblock*blockamount;
    else if (type==26) return 3*newblock*newblock*blockamount;
    else if (type==22) return 9*newblock*newblock*blockamount;
}