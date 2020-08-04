#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "rotate.c"

void rotate(char matrix[10][10]);

int main(int argc, char** argv){

  if(argc != 2){
    fprintf(stderr,"Invalid argc\n");
    return EXIT_FAILURE;
  }
  
  FILE * f = fopen(argv[1],"r");

  if (f == NULL){
    fprintf(stderr,"Could not open file\n");
    return EXIT_FAILURE;
  }

  int row = 0;
  char buff[12];
  char matrix[10][10];
  while(fgets(buff,12,f) != NULL){
    
    if(strchr(buff, '\n') == NULL){
      fprintf(stderr,"Input matrix line %d's width is more than 10 characters\n",row);
      return EXIT_FAILURE;
    }

    for(int i=0; i<12 ; i++){
      if(buff[i] == '\n') {
	if(i < 10) {
	  fprintf(stderr,"Input matrix line %d's width is  %d which is less than 10 characters\n",row,i);
	  return EXIT_FAILURE;
	}
      }
    }
    for(int i=0; i<10; i++){
      matrix[row][i] = buff[i];
    }
    row++;
  }
  if(row < 10) {
    fprintf(stderr,"Number of rows is %d, which is less than 10",row);
      return EXIT_FAILURE;
  }

  if(row > 10){
    fprintf(stderr,"Number of rows is %d, which is more than 10",row);
    return EXIT_FAILURE;
  }

  if(fclose(f)!=0){
    fprintf(stderr,"Failed to close the input file\n");
    return EXIT_FAILURE;
  }

  rotate(matrix);

  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      printf("%c",matrix[i][j]);
    }
    printf("\n");
  }
  return EXIT_SUCCESS;
}
