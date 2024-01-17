#include <stdio.h>
#include <stdlib.h>
 
typedef struct day{
    int year;
    int month;
    int day;
}date;
int hasEOF = 0;
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;   
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}
 
date arr[1000000];
int compare(const void *a, const void *b){
    date *num1 = (date*)a;
    date *num2 = (date*)b;
    if (num1->year > num2->year || num1->year == num2->year && num1->month > num2->month ||
    num1->year == num2->year && num1->month == num2->month && num1->day > num2->day) return 1;
    return -1;
}
 
int main(){
    int n; 
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        ReadInt(&arr[i].year);
        ReadInt(&arr[i].month);
        ReadInt(&arr[i].day);
    }
    qsort (arr,n, sizeof(date),compare);
    for (int i = 0; i <n; i++) printf("%d %d %d\n",arr[i].year,arr[i].month,arr[i].day);
}