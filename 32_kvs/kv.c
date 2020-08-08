#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"


kvpair_t *splitPair(char *line) {
  kvpair_t * ans = malloc(sizeof(*ans));
  char *p = NULL;
  if((p = strchr(line,'=')) != NULL) {
    *p = '\0';
  }
  else {
    perror("Invalid key value pair\n");
    return NULL;
  }
  p++;
  char * stripNline;
  if((stripNline = strchr(p,'\n')) != NULL) {
    *stripNline = '\0';
   }
  else {
    perror("Invalid key value pair\n");
    return NULL;
  }
  ans->key = line;
  ans->value = p;
  return ans;
}
kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE * f = fopen(fname, "r");
  if(f==NULL){
    perror("Could not open file\n");
    return NULL;
  }
  kvarray_t * ans;
  ans = malloc(sizeof(*ans));
  ans->pairs = NULL;
  ans->numPairs = 0;
  kvpair_t * pair = NULL;

  char *line = NULL;
  size_t  sz =0;
  
  while(getline(&line, &sz, f)>=0) {
    pair  = splitPair(line);
    ans->numPairs++;
    ans->pairs = realloc(ans->pairs, ans->numPairs*sizeof(*ans->pairs));
    ans->pairs[ans->numPairs -1] = pair;
    line = NULL;
  }
  free(NULL);

  if(fclose(f) !=0){
    perror("could not close the file\n");
    return NULL;
  }
  return ans;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i=0; i< pairs->numPairs; i++) {
    free(pairs->pairs[i]->key);
    free(pairs->pairs[i]);
  }
  free(pairs->pairs);
  free(pairs);
 }

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i=0; i<pairs->numPairs; i++) {
    printf("key = '%s' value = '%s'\n",pairs->pairs[i]->key, pairs->pairs[i]->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  for (int i=0; i<pairs->numPairs; i++) {

    if(!strcmp(pairs->pairs[i]->key,key)) {
      return pairs->pairs[i]->value;
    }
  }
  return NULL;
}
