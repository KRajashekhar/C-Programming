#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  char *adder = ".counts";
  char *OutputFileName = malloc((strlen(inputName)+strlen(adder)+1)*sizeof(*OutputFileName));

strcpy(OutputFileName, inputName);
strcat(OutputFileName, ".counts");

 return OutputFileName;
}
