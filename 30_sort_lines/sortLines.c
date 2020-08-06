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

int main(int argc, char ** argv) {
  
  //WRITE YOUR CODE HERE!
  char *line = NULL;
  size_t sz ;
  char **data = NULL;
  size_t len = 0;
  size_t i=0;
  if(argc == 1) {
    while((len = getline(&line, &sz, stdin)) >= 0) {

      data = realloc(data,(i+1)*sizeof(*data));
      data[i] = line;
      line = NULL;
      i++;
    }
    free(line);
    sortData(data, i);
  }
  else{
    for(int j = 1; j<argc; j++) {
      FILE * f = fopen(argv[j], "r");
      if(f == NULL){
	fprintf(stderr,"could not open file\n");
	return EXIT_FAILURE;
      }
      while((len == getline(&line, &sz,f)) >=0 ) {

	data = realloc(data, (i+1)*sizeof(*data));
	data[i] = line;
	line = NULL;
	i++;
      }
      free(line);
      if(fclose(f) != 0) {
	fprintf(stderr,"Failed to close the file\n");
	return EXIT_FAILURE;
      }
    }
    sortData(data,i);
  }
  for(int j=0; j<i; j++) {

    printf("%s\n",data[i]);
    free(data[i]);
  }
  free(data);
  return EXIT_SUCCESS;
}
