#include <stdio.h>
#include <assert.h>
 
#define MAXL 100000
 
void printKeys(int arr[],int len) {
  for (int i=0; i<len; i++){
    if (i!=len-1) printf("%d ",arr[i]);
    else printf("%d\n",arr[i]);
  }
}
 
void merge(int left[], int leftIndex, int leftLength,
       int right[], int rightIndex, int rightLength,
       int keys[])
{
  if ((leftIndex == leftLength) && (rightIndex == rightLength))
    return;
  if (rightIndex == rightLength ||
      (leftIndex < leftLength && left[leftIndex] < right[rightIndex])){
    keys[leftIndex+rightIndex] = left[leftIndex]; leftIndex++;
      }
  else{
    keys[leftIndex+rightIndex] = right[rightIndex]; rightIndex++;
  }
 
  merge(left, leftIndex, leftLength, right, rightIndex, rightLength, keys);
}
void mergeSort(int keys[], int n)
{
  printKeys(keys, n);
  if (n == 1)
    return;
  int leftLength = n / 2;
  int rightLength = n - leftLength;
  int left[leftLength];
  int right[rightLength];
  for (int i = 0; i < leftLength; i++)
    left[i] = keys[i];
  for (int i = leftLength; i < n; i++)
    right[i-leftLength] = keys[i];
 
  mergeSort(left, leftLength);
  mergeSort(right, rightLength);
 
  merge(left, 0, leftLength, right, 0, rightLength, keys);
  printKeys(keys, n);
} 
 
int main()
{
  int index = 0;
  int keys[100000];
 
  while (scanf("%d", &(keys[index])) != EOF) index++;

  mergeSort(keys, index);
  return 0;
}