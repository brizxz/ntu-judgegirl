#ifndef MWTIME
#define MWTIME
#include <stdio.h>
typedef struct Time {
    int hour;
    int minute;
    int second;
} Time;
 
void initTime(Time *time){
    time->hour = time->minute = time->second = 0;
}
void setTime(Time *time, int hour, int minute, int second){
    time->hour = hour; time -> minute = minute; time -> second = second;
}
void addTime(Time *time, int hour, int minute, int second){
    time->second += second; time -> hour += hour; time -> minute += minute;
    time -> minute += time->second/60; time->second%=60;
    time -> hour += time->minute/60;  time->minute%=60;
    if (time -> hour >=24) time -> hour -= 24;
}
#ifdef H24
void printTime(Time *time){
    int h[2]={0,0}; int m[2]={0,0}; int s[2]={0,0};
    h[0]=time->hour/10; h[1]=time->hour%10;
    m[0]=time->minute/10; m[1]=time->minute%10;
    s[0]=time->second/10; s[1]=time->second%10;
    printf("%d%d:%d%d:%d%d\n", h[0],h[1],m[0],m[1],s[0],s[1]);
}
#endif
#ifndef H24
void printTime(Time *time){
    int h[2]={0,0}; int m[2]={0,0}; int s[2]={0,0};
    h[0]=time->hour/10; h[1]=time->hour%10;
    m[0]=time->minute/10; m[1]=time->minute%10;
    s[0]=time->second/10; s[1]=time->second%10;
    if (time->hour==12 ) printf("12pm:%d%d:%d%d\n",m[0],m[1],s[0],s[1]);
    else if (time->hour==0 || time->hour==24) printf("12am:%d%d:%d%d\n",m[0],m[1],s[0],s[1]);
    else if (time->hour<12) printf("%d%dam:%d%d:%d%d\n", time->hour/10,time->hour%10,m[0],m[1],s[0],s[1]);
    else printf("%d%dpm:%d%d:%d%d\n", (time->hour-12)/10,(time->hour-12)%10,m[0],m[1],s[0],s[1]);
}
#endif
#endif