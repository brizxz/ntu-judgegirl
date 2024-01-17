#include <stdio.h>
void sumOfIntegers(const int *ptrArray[], int answer[], int *numberOfBlocks){
    int start = 0; int blocksum=0; int k=*numberOfBlocks; int cal=0;
    while (!(ptrArray[cal]==NULL && ptrArray[cal+1]==NULL)){
        if (ptrArray[cal]==NULL){
            answer[k]=blocksum; 
        //    printf("%d %d\n",k,cal);
            k++; blocksum=0; cal++; start=cal;
            continue;
        } 
        else{
            int find=0;
            for (int i=start; i<cal; i++){
                if (ptrArray[i]==ptrArray[cal]) find=1;
            }
            if (find==0) blocksum+=(*ptrArray[cal]);
        }
        cal++;
    }
    answer[k]=blocksum;
    *numberOfBlocks=k+1;
   // printf("%dkk",*numberOfBlocks);
}