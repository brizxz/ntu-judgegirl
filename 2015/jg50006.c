#include "eval.h"
#include <stdio.h> 
int eval(int exp[]) {
    /* add your code */
    int res=0; int product=1; int number=0;
    for (int i = 1; i <= exp[0]; i++){
        if (i%2==0){
            if ((exp[i]==1 || exp[i]==2 || exp[i]==3 || exp[i]==4)){
                number*=product; product=number; 
                if (exp[i]==1 || exp[i]==2){
                    res+=number; product=1;
                }
                number=0;
            }
            else return -2147483646;
        }
        else{
            number=number*10+exp[i];
            if (exp[i-1]==2) number*=-1;
            if (exp[i-1]==4){
                if (exp[i]==0) return -2147483647;
                product/=exp[i]; number=1;
            } 
        }
    }
    number*=product;
    res+=number;
    return res;
}