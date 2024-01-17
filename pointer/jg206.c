#include <stdio.h>
void shuffle(int *deck[]){
    int count = 0;
    for (int i=0; deck[i]!=NULL; i++) count++;
    int arr1[5000]; int arr2[5000];
    int l,r;
    if (count%2==0) l=r=(count/2);
    else{
        l=count/2+1; r=count/2;
    }
    int k=0;
    for (int i=0; i<l; i++) arr1[i]=*deck[i];
    for (int i=l; i<count; i++,k++) arr2[k]=*deck[i];
    for (int i=0; deck[i]!=NULL; i++){
        if (i%2==0) *deck[i]=arr1[i/2];
        else *deck[i]=arr2[i/2];
    }
 
}
 
void print(int *deck[]){
    for (int i=0; deck[i]!=NULL; i++){
        if (i==0) printf("%d",*deck[i]);
        else printf(" %d",*deck[i]);
    }
}