#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void Decrypt(char * arr , size_t n){
  char alpha[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'} ;
  int index = 0;
  int frequency = 0;
  for(int i = 0; i < n ;i++)
    {
      int freq_i=0;
     
	  for( int j = 0; j<n ; j++)
	    {
	      if(arr[j] == alpha[i])
		{
		  freq_i++;
	        }
	    }
	
      if(freq_i >= frequency)
	{
	  frequency = freq_i;
	   index = i;
	}
    }
  // printf("%c\n", alpha[index]);
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
  // printf("%zu\n", size);
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
  //  int n_letters = 19;
  char  arr[n_letters+1];
  int c;
  int i = 0;
  rewind(f);
  while((c = fgetc(f)) != EOF)
    {
      if(isalpha(c))
	{
	  //	  printf("%c\n",c);
	  c = tolower(c);
	  arr[i] = c;
	  i++;
	}
    }
  /*  for(int i=0; i< n_letters;i++)
    {
      printf("%c\n",arr[i]);
      }*/
    Decrypt(arr, n_letters+1);
   if(fclose(f) != 0){
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
