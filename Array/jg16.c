#include <stdio.h>
 
int main(){
    int n;
    scanf("%d",&n);
    int odd[1000]; int even[1000];
    int count_odd=0; int count_even=0;
    int num;
    for (int i=0; i<n; i++){
        scanf("%d",&num);
        if (num%2==0){
            even[count_even]=num; count_even++;
        } 
        else{
            odd[count_odd]=num; count_odd++;
        }
    }
    for (int i=0; i<count_odd-1; i++) printf("%d ",odd[i]);
    printf("%d\n",odd[count_odd-1]);

    for (int i=0; i<count_even-1; i++) printf("%d ",even[i]);
    printf("%d\n",even[count_even-1]);
}