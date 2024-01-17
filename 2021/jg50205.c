#include <stdio.h>

int find(char c,char op[10]){
    for (int i= 0; i <10; i++){
        if (c == op[i]) return i;
    }
    return -1;
}

int main(){
    char operator[12] = ")!@#$%^&*(";
    char ans; int product=1; int sum=0;
    int answer=0;
    while (scanf("%c",&ans) != EOF){
        int num=find(ans,operator);
        if (num!=-1 && num!=8){
            sum=sum*10+num;
        }
        else{
            product*=sum;
            if (ans=='+'){
                answer+=product;
                sum=0; product=1;
            }
            sum=0;
        }
    }
    product*=sum;
    answer+=product;
    printf("%d",answer);
}