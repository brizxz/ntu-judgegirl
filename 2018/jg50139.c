#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GPA_calculation.h"
 
typedef struct result{
    int rank;
    char name[20];
    double gpa;
    int credits;
} res;
 
double calnum(char score[3]) {
    char state[10][3]={"A+","A","A-","B+","B","B-","C+","C","C-","F"};
    double real[10] = {4.3,4,3.7,3.3,3.0,2.7,2.3,2.0,1.7,0};
    for (int i=0; i<10; i++){
        if (strcmp(score,state[i])==0) return real[i];
    }
}
 
int calcredit(struct Student a){
    int credits = 0;
    for (int i=0; i<a.N_class; i++){
        credits += a.all_class[i].academic_credit;
        // printf("%f\n",calnum(a.all_class[i].score));
    }
    return credits;
}

double calgpa(struct Student a){
    double weight = 0;
    int credits = 0;
    for (int i=0; i<a.N_class; i++){
        weight+= (a.all_class[i].academic_credit*calnum(a.all_class[i].score));
        credits += a.all_class[i].academic_credit;
        // printf("%f\n",calnum(a.all_class[i].score));
    }
    a.N_credit = credits;
    // printf("%d\n",a.N_credit);
    return weight/(double)credits;
}
 
int compare(const void *a, const void *b){
    res *c1 = (res *)a;
    res *c2 = (res *)b;
    if (c1->gpa> c2->gpa) return -1;
    else return 1;
}
 
void GPA_calculation(struct Student all_student[], int N){
    int award; res result[10000]; res buf[10000];
    if (N%20==0) award = N/20;
    else award = N/20 + 1;
    for (int i=0; i<N; i++){
        result[i].rank = i+1;
        strcpy(buf[i].name,all_student[i].name);
        // printf("%s\n",buf[i].name);
        result[i].gpa = calgpa(all_student[i]);
        buf[i].gpa = result[i].gpa;
        buf[i].credits = calcredit(all_student[i]);
    }
 
    qsort(result, N, sizeof(res),compare);

    for (int i=0; i<award; i++){
        for (int j=0; j<N; j++){
            if (result[i].gpa == buf[j].gpa ) {
                strcpy(result[i].name,buf[j].name);
                result[i].credits = buf[j].credits;
                break;
            }
        }
    }
    for (int i=0; i<award; i++){
        if (result[i].gpa<3.38 || result[i].credits<15) continue;
        printf("%d %s %f\n",i+1,result[i].name,result[i].gpa);
    }
}