#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int *array, size_t n){

  if(n==0){
    return 0;
  }
  if(n==1){
    return 1;
  }
  int length = 1;
  int large_length = length;

  for(int i = 1; i < n; i++}
  {
    if(array[i] > array[i-1]){
      length++;
    }
    else{
      if(length > large_length){
	large_length = length;
      }
      length = 1;
    }
  }
  return large_length;
}
