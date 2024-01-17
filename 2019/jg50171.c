#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int find(int count[400000],int total){
    int min=1000000; int loc;
    for (int i=0;i<total;i++){
        if (count[i]<min){
            min=count[i]; loc=i;
        } 
    }
    return loc;
}

void splitAndMap(char*** ptr, char* str){
    int len=0; int total=0; int count[400000]; int loca[400000];
    for (int i=0; ptr[i]!=NULL; i++){
        count[i]=0; loca[i]=0; total++; 
    } 
    str = strtok(str, "*");
    while(str!=NULL){
        int goal = find(count,total);
        ptr[goal][loca[goal]] = str;
        count[goal]+=strlen(str);
        loca[goal]++;
        str = strtok(NULL, "*");
    }
}