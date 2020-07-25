#include<stdlib.h>
#include<stdio.h>

size_t maxSeq(int * array, size_t n);

int main(void)
{
  int array1[] = {};
  int array2[] = {1};
  int array3[] = {1,2,3,4};
  int array4[] = {1000,11000,1,5,6,7,8};
  int array5[] = {2,3,6,-10};
  int array6[] = {-10,5,6,9,11,-12};
  int array7[] = {5,-11,15};
  int array8[] = {10,-4,-7,-9};
  int array15[] = {12, 10};
  int array9[] =  { 1, 3, 5, 7, 2, 4, 6, 9};
  int arr10[]={1};

  if(maxSeq(arr10,1)!=1) {printf("array10\n"); exit(EXIT_FAILURE);  }
  if(maxSeq(array8,4)!=1){printf("array8\n"); exit(EXIT_FAILURE);}//10,11
  if(maxSeq(array6,6)!=5){printf("array6\n"); exit(EXIT_FAILURE);}//1,2
  if (maxSeq(array15,2)!=1){printf("array15\n"); exit(EXIT_FAILURE);}//3,4 
  if(maxSeq(array9,10)!=4) {printf("array9\n"); exit(EXIT_FAILURE);} 
  if(maxSeq(array1,0)!=0){printf("array1\n"); exit( EXIT_FAILURE);} 
  // if(maxSeq(array2,1)!=1){printf("some error\n"); retur0n EXIT_FAILURE;} 
  if(maxSeq(array3,4)!=4){printf("some error\n"); exit(EXIT_FAILURE);} 
  if(maxSeq(array4,7)!=5){printf("some error\n"); exit(EXIT_FAILURE);}
   //if(maxSeq(array5,4)!=3){printf("some error\n"); return EXIT_FAILURE;}
   //if(maxSeq(array6,6)!=5){printf("some error\n"); return EXIT_FAILURE;}
   //if(maxSeq(array7,3)!=2){printf("some error\n"); return EXIT_FAILURE;}

   //if(maxSeq(array1,0)!=0){printf("some error\n"); return EXIT_FAILURE;}
    //if(maxSeq(array5,4)!=3){printf("some error\n"); return EXIT_FAILURE;}
   // if(maxSeq(array5,4)!=3){printf("some error\n"); return EXIT_FAILURE;}
 
   //  if(maxSeq(array6,7)!=5){printf("some error\n"); return EXIT_FAILURE;}
  
  return EXIT_SUCCESS;
}
