#include <stdio.h> // worng ???
void print(int arr[],int len) {
  for (int i=0; i<len; i++){
    if (i!=len-1) printf("%d ",arr[i]);
    else printf("%d\n",arr[i]);
  }
}
void merge(int left[],int leftlen,int leftindex,int right[],int rightlen,int rightindex,int arr[])
{
  if ((leftindex==leftlen) && (rightindex==rightlen)) 
    return;
  if (rightindex==rightlen || ( leftindex<leftlen && left[leftindex]<right[rightindex])){
    arr[leftindex+rightindex] = left[leftindex]; leftindex++; 
  } 
  else{
    arr[leftindex+rightindex] = right[rightindex]; rightindex++;
  } 
  merge(left,leftlen,leftindex,right,rightlen,rightindex,arr);
}
 
void mergesort(int arr[],int len){
  print(arr,len);
  if (len==1) return;
  int leftlen = len/2; 
  int rightlen = len-leftlen;
  int left[50005]; int right[50005];

  for (int i=0; i<leftlen; i++) left[i] = arr[i];
  for (int i=leftlen; i<len; i++) right[(i-leftlen)] = arr[i];

  mergesort (left,leftlen);
  mergesort (right,rightlen);
  
  merge(left,leftlen,0,right,rightlen,0,arr);

  print(arr,len);
}

int main(){
  int arr[100000]; 
  int count=0;
  while(scanf("%d",&(arr[count]))!=EOF) count++;

  mergesort(arr,count);
  return 0;
}