#include <stdio.h>
 
int judge_year(int year){
    if ((year%4==0 && year%100!=0) || year%400==0) return 1;
    return 0;
}
 
int main(){
    int year, month, day;
    int dayofodd[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    int dayofeven[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    scanf("%d%d%d", &year, &month, &day);
    if (month<1 || month>12 || day<0 || day>6) printf("invalid\n");
    else{
        printf(" Su Mo Tu We Th Fr Sa\n");
        printf("=====================\n");
        for (int i=0; i<day; i++) printf("   ");
        for (int i=1; i<=((judge_year(year)==1)?dayofodd[month]:dayofeven[month]); i++){
            printf("%3d",i);
            if ((i+day)%7==0) printf("\n");
        }
        int aaa=((judge_year(year)==1)?dayofodd[month]:dayofeven[month])+day;
        if (aaa%7!=0) printf("\n");
        printf("=====================\n");
    }
}