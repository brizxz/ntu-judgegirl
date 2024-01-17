#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct daliy_expense{
    int year;
    int month;
    int day;
    char category[35];
    int expense;
}expense;
 
int compare(const void *a, const void *b){
    expense *num1 = (expense *)a;
    expense *num2 = (expense *)b;
    if (num1->year > num2->year || num1->year == num2->year && num1->month > num2->month || 
    num1->year == num2->year && num1->month == num2->month && num1->day > num2->day || 
    num1->year == num2->year && num1->month == num2->month && num1->day == num2->day &&
    strcmp(num1->category, num2->category)>0) return 1;
    return -1;
} 
 
int fast_judge(expense a,expense b){
    return (a.year==b.year && a.month==b.month && a.day==b.day && strcmp(a.category,b.category)==0);
}
 
int main(){
    expense arr[10000]; int count=0; expense buf;
    while(scanf("%d%d%d%s%d",&buf.year,&buf.month,&buf.day,buf.category,&buf.expense)!=EOF){
        int find=0;
        for (int i=0; i<count; i++){
            if (fast_judge(arr[i],buf)==1){
                arr[i].expense += buf.expense; find=1;
                break;
            } 
        }
        if (find==1) continue;
        arr[count].year = buf.year; arr[count].month = buf.month; arr[count].day = buf.day; 
        arr[count].expense = buf.expense; strcpy(arr[count].category,buf.category);
        count++;
    }
    qsort (arr,count,sizeof(expense),compare);
    for (int i = 0; i <count; i++) printf("%d %d %d %s %d\n",
    arr[i].year,arr[i].month,arr[i].day,arr[i].category,arr[i].expense);
}