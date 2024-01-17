#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    char name[64];
    int height;
    int weight;
    float bmi;
} stu;

int compare(const void *a, const void *b){
    stu *c1 = (stu *)a;
    stu *c2 = (stu *)b;
    if (c1->bmi> c2->bmi || c1->bmi == c2->bmi && c1->weight>c2->weight || 
    c1->bmi == c2->bmi && c1->weight==c2->weight && c1->height > c2->height || 
    c1->bmi == c2->bmi && c1->weight==c2->weight && c1->height == c2->height && strcmp(c1->name, c2->name)>0) return 1;
    else return -1;
}

int main(){
    int n; stu a[100001];
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%s%d%d",a[i].name,&a[i].height,&a[i].weight);
        float w = (float)a[i].weight; float h = (float)a[i].height;
        a[i].bmi  = w/((h/100)*(h/100));
    } 
    qsort(a,n,sizeof(stu),compare);

    for (int i=0; i<n; i++) printf("%s %d %d\n",a[i].name,a[i].height,a[i].weight);
}