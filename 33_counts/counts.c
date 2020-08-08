#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t *ans = malloc(sizeof(*ans));
  ans->ncounts = 0;
  ans->unknown = 0;
  ans->countArr = NULL;
  return ans;
}
one_count_t * createCount(const char * name){
  one_count_t * ans = malloc(sizeof(*ans));
  ans->name =  malloc((strlen(name)+1)*sizeof(*ans->name));
  ans->name = strcpy(ans->name, name);
  ans->ns = 1;
  return ans;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  if(name == NULL) {
    c->unknown ++;
    return;
  }
  for(int i=0; i<c->ncounts; i++) {
    if(!( strcmp(c->countArr[i]->name,name) )) {
      c->countArr[i]->ns++;
      return ;
    }
  }
  c->ncounts++;
  c->countArr = realloc(c->countArr,c->ncounts*sizeof(*c->countArr));
  c->countArr[c->ncounts - 1] = createCount(name);
  return ;
}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for(size_t i =0; i<c->ncounts; i++) {
    fprintf(outFile,"%s: %zd\n",c->countArr[i]->name,c->countArr[i]->ns);
  }
  if(c->unknown != 0) {
    fprintf(outFile,"<unknown> : %zd\n",c->unknown);
  }
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for(int i=0; i<c->ncounts; i++) {
    free(c->countArr[i]->name);
    free(c->countArr[i]);
  }
  free(c->countArr);
  free(c);
}
