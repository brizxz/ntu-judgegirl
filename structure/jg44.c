#include "book.h"
#include "date.h"
#include <stdio.h>
int judge(unsigned int a){
    if ((a%4==0 && a%100!=0) || a%400==0 ) return 1;
    return 0;
}
 
int count(unsigned int ay,unsigned int am,unsigned int ad,unsigned int by,unsigned int bm,unsigned int bd){
    int days=0;
    int oddyear[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int evenyear[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for (unsigned int i=ay+1; i<by; i++){
        days+=365+(judge(i)==1);
    }
    if (ay==by){
        if (am!=bm){
            if (judge(ay)==1){
                for (unsigned int i=am+1; i<bm; i++) days+=oddyear[i-1];
                days+= (oddyear[am-1]-ad);
            }
            else{
                for (unsigned int i=am+1; i<bm; i++) days+=evenyear[i-1];
                days+= (evenyear[am-1]-ad);
            }
            days+=bd;
        }
        else days+= (bd-ad);
    }
    else{
        if (judge(by)==1){
            for (unsigned int i=1; i<bm; i++){
                days+= oddyear[i-1];
            }
            days+=bd;
        }
        else{
            for (unsigned int i=1; i<bm; i++){
                days+= evenyear[i-1];
            }
            days+=bd;            
        } 
        if (judge(ay)==1){
            for (unsigned int i=am+1; i<13; i++){
                days+= oddyear[i-1];
            }
            days+= (evenyear[am-1]-ad);
        }
        else{
            for (unsigned int i=am+1; i<13; i++){
                days+= evenyear[i-1];
            }
            days+= (evenyear[am-1]-ad);            
        }
    } 
    return days+1;
}
 
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned){
    unsigned int ans = 0;
    int k=book.importance;
    int loc1, loc2; int find=0;
    for( int i=0; i<sizeof(unsigned int)*8; i++ ){
        if (k&1!=0 && find==0){
            loc1=i; find=1;
        } 
        else if (k&1!=0 && find!=0) loc2=i;
        k>>=1;
    }
    int cl[4]={90,10,100,5};
    int imp = loc2-loc1-1; int day=count(date_borrowed.year,date_borrowed.month,date_borrowed.day,
    date_returned.year,date_returned.month,date_returned.day);
    day-= cl[book.type];
    if (day<0) day=0;
    ans=imp*day;
    return ans;
}