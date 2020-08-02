/*#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
  void Decrypt(char * arr , size_t n){
  char alpha[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'} ;
  int index = 0;
  int frequency = 0;
  for(int i = 0; i < 26 ;i++)
    {
      int freq_i=0;
     
	  for( int j = 0; j<n ; j++)
	    {
	      if(arr[j] == alpha[i])
		{
		  freq_i ++ ;
	        }
	    }
	
      if(freq_i > frequency)
	{
	  frequency = freq_i;
	   index = i;
	}
    }
  printf("%d\n", (index+22)%26);
  
}



size_t  number_of_letters(FILE * f) {
  int c;
  size_t size = 0;
  while((c = fgetc(f)) != EOF) {
    if(isalpha(c)) {
      size++;
    }
  }
 return size;
  }

 
int main(int argc, char ** argv)
{
  if(argc != 2 )
    {
      fprintf(stderr,"Usage: encrypt key inputFilename\n");
      return EXIT_FAILURE;
    }

  FILE *f = fopen(argv[1], "r");

  if(f == NULL)
    {
      perror("Could not open file");
      return EXIT_FAILURE;
    }
  size_t n_letters  = number_of_letters(f);
  n_letters++;
  char  arr[n_letters];
  int c=0;
  int i = 0;
   rewind(f);
   if(f == NULL)
     {
       perror("Could not open file");
       return EXIT_FAILURE;
     }
  while((c = fgetc(f)) != EOF   && i < n_letters)
    {
      if(isalpha(c))
	{
          c = tolower(c);
	  arr[i] = c;
	  i++;
	}
    }
   Decrypt(arr, n_letters);

   if(fclose(f) != 0){
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


size_t largestindx(int * array, size_t n){

  size_t indx=0;

  for (int i=1;i<n;i++){
    if (array[indx] < array[i]){
      indx = i;
    }
  }
  return indx;
}


int main(int argc, char ** argv) {


  if (argc != 2) {
    fprintf(stderr,"Invalid argc\n");
    return EXIT_FAILURE;
  }

  FILE * f = fopen(argv[1], "r");

  if (f == NULL) {
    fprintf(stderr,"Could not open file\n");
    return EXIT_FAILURE;
  }

  int freq[26]={0};
  int c;
  //xint n = 0;

  while (((c = fgetc(f)) != EOF)){

    if (isalpha(c)){
      freq[c-97] = freq[c-97] + 1;
    }
  }

  size_t i = largestindx(freq, 26);

  int key = (i+22)%26;


  printf("%d\n",key);


  if (fclose(f) != 0) {
    fprintf(stderr,"Failed to close the input file!\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
