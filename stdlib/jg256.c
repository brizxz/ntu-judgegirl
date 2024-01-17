#include <stdio.h>
#include <stdlib.h>
#define ll long long  
ll int countbit(ll int a){
    int sum=0; ll int k=1;
    for (int i=0; i<64; i++){
        if ((a&(k<<i)) !=0) sum++;
    }
    return sum;
}
 
int compare(const void *a, const void *b){
    ll int *num1 = (ll int*)a;
    ll int *num2 = (ll int*)b;
    if (countbit(*num1)>countbit(*num2) || countbit(*num1)==countbit(*num2) && *num1>*num2) return 1;
    else if (*num1==*num2) return 0;
    else return -1;
}
 
 
int main(){
    ll int arr[1000];
    int sum=0;
    while (scanf("%lld",&arr[sum])!=EOF) sum++;
    qsort (arr, sum , sizeof(ll int), compare);
    for (int i=0; i <sum; i++){
        printf("%lld\n",arr[i]);
    }
}