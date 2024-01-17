#include "employee.h"
#include <string.h> 
# include <stdio.h>
int relation(Employee *employee1, Employee *employee2) {
    char ansa[32][2][32]; char ansb[32][2][32];
    char a[2][32],b[2][32];
    strcpy(a[0],employee1->first_name);
    strcpy(a[1],employee1->last_name);
    strcpy(b[0],employee2->first_name);
    strcpy(b[1],employee2->last_name);
    int c_a=0, c_b=0;
    int find=4;
    while (employee1->boss != employee1){
        strcpy(ansa[c_a][0],(employee1->boss)->first_name);
        strcpy(ansa[c_a][1],(employee1->boss)->last_name);
        employee1 = employee1->boss; c_a++;
    }
    while (employee2->boss != employee2){
        strcpy(ansb[c_b][0],(employee2->boss)->first_name);
        strcpy(ansb[c_b][1],(employee2->boss)->last_name);
        employee2 = employee2->boss; c_b++;
    }
    for (int i=0; i <c_a; i++){
        if (strcmp(ansa[i][0],b[0])==0 && strcmp(ansa[i][1],b[1])==0) find=1;
    }
    for (int i=0; i <c_b; i++){
        if (strcmp(ansb[i][0],a[0])==0 && strcmp(ansb[i][1],a[1])==0) find=2;
    }
    if (find==4){
        for (int i = 0; i <c_a; i++){
            for (int j = 0; j <c_b; j++){
                if (strcmp(ansa[i][0],ansb[j][0])==0 && strcmp(ansa[i][1],ansb[j][1])==0) find=3;            
            }
        }
    }
    return find;
}