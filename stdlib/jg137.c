#include <stdio.h>
#include <stdlib.h>
 
void print100(int arr[],int n){
    float sum = 0.0;
    for (int i=0; i<n; i++) {
        printf("%d ",arr[i]);
        sum += (float)arr[i];
    }
    printf("%.1f\n",sum/(float)n);
    return;
}
 
void printgpa(int arr[],int n){
    float sum = 0.0;  float rank=0.0;
    for (int i=0; i<n; i++) {
        if (arr[i]>=90 && arr[i]<=100){
            rank += 4.3; sum+= 95; printf("A+ ");
        }
        else if (arr[i]>=85 && arr[i]<=89){
            rank += 4.0; sum+= 87; printf("A ");
        }
        else if (arr[i]>=80 && arr[i]<=84){
            rank += 3.7; sum+= 82; printf("A- ");      
        }
        else if (arr[i]>=77 && arr[i]<=79){
            rank += 3.3; sum+= 78; printf("B+ ");
        }
        else if (arr[i]>=73 && arr[i]<=76){
            rank += 3.0; sum+= 75; printf("B ");        
        }
        else if (arr[i]>=70 && arr[i]<=72){
            rank += 2.7; sum+= 70;  printf("B- ");        
        }
        else if (arr[i]>=67 && arr[i]<=69){
            rank += 2.3; sum+= 68; printf("C+ ");          
        }
        else if (arr[i]>=63 && arr[i]<=66){
            rank += 2.0; sum+= 65; printf("C ");          
        }
        else if (arr[i]>=60 && arr[i]<=62){
            rank += 1.7; sum+= 60; printf("C- ");         
        }
        else{
            sum+=50; printf("F ");
        }
    }
    printf("%.1f ",rank/(float)n);
    printf("%.1f\n",sum/(float)n);
    return;
}
int main(){
    int arr[200]; int count = 0;
    while(scanf("%d",&arr[count])!=EOF) count++;
    #ifdef HUNDRED
    print100(arr,count);
    #endif
    #ifdef APLUS
    printgpa(arr,count);
    #endif
 
}