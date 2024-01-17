#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAXLENGTH 16
#define MAXCOMPONENT 64
typedef struct{
    char name[MAXLENGTH];
    int numComponent;
    int componentPartList[MAXCOMPONENT];
    int price;
}ComponentPart;
int computeprice(ComponentPart list[],ComponentPart *com){ // 使用指標速度較快
    if(com->numComponent==0||com->price!=0) return com->price;
    else{
        int tem=0;
        for(int i=0;i<com->numComponent;i++)
        tem += computeprice(list,&list[com->componentPartList[i]]);
        com->price = tem;
        return com->price;
    }
}
void findPrice(int N,ComponentPart list[]){
    for(int i=0;i<N;i++) list[i].price = computeprice(list,&list[i]);
    for(int i=N-2;i>=0;i--)
        for(int j=0;j<=i;j++){
        if(strcmp(list[j].name,list[j+1].name)>0){
            ComponentPart tem = list[j];
            list[j] = list[j+1];
            list[j+1] = tem;
        }
        }
    for(int i=0;i<N;i++) printf("%s %d\n",list[i].name,list[i].price);
}