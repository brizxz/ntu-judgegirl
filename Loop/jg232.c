#include <stdio.h>
 
int judgeyear(int year){
    if ((year%4==0 && year%100!=0) || year%400==0) return 1;
    return 0;
}
 
int main(){
    int the_year,the_day; // 0:sunday
    int dayofodd[15]={31,29,31,30,31,30,31,31,30,31,30,31};
    int dayofeven[15]={31,28,31,30,31,30,31,31,30,31,30,31};
    scanf("%d%d",&the_year,&the_day);
    int n;
    scanf("%d",&n);
    int this_month,this_day;
    for (int i=0; i<n; i++){
        scanf("%d%d",&this_month,&this_day);
        if (this_month>12||this_month<1){
            printf("%d\n",-1); continue;
        }
        if (this_month==1 || this_month==3 || this_month==5 ||this_month==7
        || this_month==8 || this_month==10 || this_month==12){
            if (this_day<1|| this_day>31){
                printf("%d\n",-2); continue;
            }
        }
        else if (this_month==4 || this_month==6 || this_month==9 || this_month==11){
            if (this_day<1|| this_day>30){
                printf("%d\n",-2); continue;
            }          
        }
        else if (this_month==2){
            if ( judgeyear(the_year)==1 && (this_day<1 || this_day>29)){
                printf("%d\n",-2); continue;
            }          
            else if ( judgeyear(the_year)==0 && (this_day<1 || this_day>28)){
                printf("%d\n",-2); continue;
            }
        }
        int totaldays=the_day;
        if (judgeyear(the_year)==1){
            for (int i=0; i<this_month-1; i++ ) totaldays+=dayofodd[i];
            totaldays+= this_day;
        }
        else if (judgeyear(the_year)==0){
            for (int i=0; i<this_month-1; i++ ) totaldays+=dayofeven[i];
            totaldays+= this_day;
        }
        printf("%d\n",(totaldays-1)%7);
    }
}