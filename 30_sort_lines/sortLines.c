#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

char ** sortFile(FILE *f, size_t* n){
  char *line = NULL;
  size_t sz ;
  char **data = NULL;
  size_t i=0;
  while(getline(&line, &sz, f) >= 0) {
    i++;
    data = realloc(data,i*sizeof(*data));
    data[i-1] = line;
    line = NULL;
  }
  free(line);
  sortData(data, i);
  *n = i;
  return data;
}

void printsortedFile(FILE * f)
{
  size_t n = 0;
  char ** data = sortFile(f,&n);
    for(int i=0; i<n; i++) {
      printf("%s",data[i]);
      free(data[i]);
    }
  free(data);
}
    
int main(int argc, char ** argv) {
  
  //WRITE YOUR CODE HERE!
  if(argc == 1) {
    printsortedFile(stdin);
  }
  else if (argc > 1){
    for(int j = 1; j<argc; j++) {
      FILE * f = fopen(argv[j], "r");
      if(f == NULL){
	fprintf(stderr,"could not open file\n");
	return EXIT_FAILURE;
      }
      printsortedFile(f);
      if(fclose(f) != 0) {
	fprintf(stderr,"Failed to close the file\n");
	return EXIT_FAILURE;
      }
    }   
  }
  return EXIT_SUCCESS;
}
