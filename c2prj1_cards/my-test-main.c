#include "cards.h"
#include<stdlib.h>
#include<stdio.h>
int main(void) {
  for(int i=0;i<52;i++)
    {
      card_t c=card_from_num(i);
      printf("%c%c\n",c.value,c.suit);
    }
  return 0;
}
