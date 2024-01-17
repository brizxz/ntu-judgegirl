int judge(int a){
    if ((a%4==0 && a%100!=0) || a%400==0) return 1;
    return 0;
}
// day: 1/1 
void count_day(int year, int day, int month, int results[7]){
    int nien = judge(year); int days=day;
    int oddmonth[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int evenmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (nien==1){
        for (int i =0; i<month-1; i++) days += oddmonth[i]; 
        days%=7;
        for (int i=1; i<=oddmonth[month-1]; i++){
            results[days%7]++;
            days++;
        }
    }
    else{
        for (int i =0; i<month-1; i++) days += evenmonth[i];  
        days%=7;
        for (int i=1; i<=evenmonth[month-1]; i++){
            results[days%7]++;
            days++;
        }
    }
}