#include<stdio.h>
#include<stdlib.h>

unsigned power (unsigned x, unsigned y);

int main() {
  if(power(0,0) != 1) { printf("0\n"); exit(EXIT_FAILURE);   }
  if(power(2,1) != 2) { printf("1\n"); exit(EXIT_FAILURE);   }
  if(power(100,2) != 10000 ) { printf("2\n");  exit(EXIT_FAILURE);  }
  if(power(10000000,1) != 10000000) { printf("3\n");  exit(EXIT_FAILURE);    }

  exit(EXIT_SUCCESS);
 
}
