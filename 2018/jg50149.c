#include <stdio.h>
#include <stdlib.h>

typedef struct te{
    int id;
    int chinese;
    int english;
    int math;
    int science;
    int social;
} test;

int compare(const void *a, const void *b){
    test *c1 = (test *)a;
    test *c2 = (test *)b;
    int scorea = c1->chinese+c1->english+c1->math+c1->science+c1->social;
    int scoreb = c2->chinese+c2->english+c2->math+c2->science+c2->social;
    if (scorea < scoreb || scorea == scoreb && c1->math < c2->math || scorea == scoreb && c1->math == c2->math && c1->english < c2->english
    || scorea == scoreb && c1->math == c2->math && c1->english == c2->english && c1->science < c2->science
    || scorea == scoreb && c1->math == c2->math && c1->english == c2->english && c1->science == c2->science && c1->chinese < c2->chinese
    || scorea == scoreb && c1->math == c2->math && c1->english == c2->english && c1->science == c2->science && c1->chinese == c2->chinese && c1->social < c2->social) return 1;
    return -1;
}

int judge(test a, test b){
    if (a.chinese==b.chinese && a.math==b.math && a.english==b.english && a.science==b.science && a.social==b.social)
        return 1;
    return 0;
}

int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    test stu[20000];
    for (int i=0; i< n; i++) scanf("%d%d%d%d%d%d",&stu[i].id,&stu[i].chinese,&stu[i].english,&stu[i].math,&stu[i].science,&stu[i].social);
    qsort(stu,n,sizeof(test),compare);
    for (int i=0; i< m; i++){
        printf("%d\n",stu[i].id);
    }
    while (judge(stu[m-1],stu[m]) && m<n) {
        printf("%d\n",stu[m].id);
        m++;
    }
}