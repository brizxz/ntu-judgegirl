#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
 
void init_storage(Employee **storage, int n)
{
    // allocate memory space to store employee data
    // no need to understand this function now.
 
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
 
void free_storage(Employee **storage)
{
    free(*storage);
    *storage = 0;
}
 
Employee* find_employee_by_id( Employee *set, int n, int id ){
    for (int i = 0; i < n; i++){
        if (set[i].id == id) return &set[i];
    }
}
Employee* find_employee_by_name( Employee *set, int n, const char *first_name, const char *last_name ){
    for (int i = 0; i < n; i++){
        if (strcmp(set[i].first_name,first_name)==0 && strcmp(set[i].last_name,last_name)==0) return &set[i];
    }
}
Employee* find_root_boss( Employee *set, int n, Employee *employee ){
    Employee *ptr = employee;
    while (ptr->id != ptr->boss_id){
        for (int i = 0; i < n; i++){
            if (ptr->boss_id == set[i].id) ptr = &set[i];
        }
    }
    return ptr;
}
int check_abrelation( Employee *set, int n, Employee *a, Employee *b ){
    Employee *ptra = a;     Employee *ptrb = b;
    while (ptra->id != ptra->boss_id){
        for (int i = 0; i < n; i++){
            if (ptra->boss_id == b->id) return 1;
            if (ptra->boss_id == set[i].id) ptra = &set[i];
        }
    }
    ptra = a; ptrb = b;
    while (ptrb->id != ptrb->boss_id){
        for (int i = 0; i < n; i++){
            if (ptrb->boss_id == a->id) return -1;
            if (ptrb->boss_id == set[i].id) ptrb = &set[i];
        }
    }
    return 0;
}
 
int check_relationship(Employee *set, int n, Employee *A, Employee *B){
    char fname1[32]; char fname2[32];
    char lname1[32]; char lname2[32];
    strcpy(fname1,find_root_boss(set,n,A)->first_name);
    strcpy(lname1,find_root_boss(set,n,A)->last_name);
    strcpy(fname2,find_root_boss(set,n,B)->first_name);
    strcpy(lname2,find_root_boss(set,n,B)->last_name);
    if (check_abrelation(set,n,A,B)==1) return 1;
    else if (check_abrelation(set,n,A,B)==-1) return 2;
    else if (strcmp(fname1,fname2)==0 && strcmp(lname1,lname2)==0) return 3;
    else return 4;
}