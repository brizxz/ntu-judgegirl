#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct buffer{
    char name[17];
    int value;
} buf;

int compare(const void *a, const void *b){
    buf *c1 = (buf *)a;
    buf *c2 = (buf *)b;
    if (strcmp(c1->name, c2->name)>0 || strcmp(c1->name, c2->name)==0 && c1->value<c2->value) return 1;
    else return -1;
}

int main(){
    buf paper[20000];
    int count = 0;
    while(scanf("%s%d",paper[count].name,&paper[count].value)!=EOF){
        count++;
    }
    qsort(paper,count,sizeof(buf),compare);

    int k=0; int hindex=0; char prev[17]; int index=1;
    strcpy(prev,paper[0].name); 
    while (k<count){
        int find = 1;
        while (strcmp(paper[k].name,prev)==0 && k< count){
            if (paper[k].value>=index && find==1){
                hindex++; index++;
            }
            else find = 0;
            strcmp(prev,paper[k].name);
            k++;
        }
        printf("%s %d\n",prev,hindex);
        strcpy(prev,paper[k].name);
        hindex = 0 ; index = 1;
    }
}