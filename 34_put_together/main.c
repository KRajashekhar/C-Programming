#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  FILE *f = fopen(filename, "r");
  if(f==NULL){
    perror("Unable to open file\n");
    return NULL;
  }
  counts_t * ans = createCounts();
  char * line = NULL;
  size_t sz=0;
  while(getline(&line, &sz, f) >=0) {
    char *p = strchr(line,'\n');
    if(p!=NULL) {
      *p = '\0';
    }
    addCount(ans, lookupValue(kvPairs, line));
  }
  free(line);
  if(fclose(f) != 0) {
    perror("Unable to close the file\n");
    return NULL;
  }
  return ans;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
  if(argc < 3) {
    perror("Less arguments\n");
    return EXIT_FAILURE;
  }

  char *suffix = ".counts";
 //read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t * kv = readKVs(argv[1]);  
 //count from 2 to argc (call the number you count i)
  for(int i=2; i<argc; i++){
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    counts_t *c = countFile(argv[i], kv);
    //   (call this result c)
    //compute the output file name from argv[i] (call this outName)
    char * outName = malloc((strlen(argv[i])+strlen(suffix)+1) * sizeof(*outName));
    strcpy(outName,argv[i]);
    strcat(outName,suffix);

    //open the file named by outName (call that f)
    FILE * f = fopen(outName, "w");
    if(f==NULL) {
      perror("Unable to opent the file\n");
      return EXIT_FAILURE;
    }
    //print the counts from c into the FILE f
    printCounts(c,f);  
    //close f
    if(fclose(f) != 0) {
      perror("Unable to close the file\n");
      return EXIT_FAILURE;
    }
    //free the memory for outName and c
    free(outName);
    freeCounts(c);
  }

 //free the memory for kv
  freeKVs(kv);
  return EXIT_SUCCESS;
}
