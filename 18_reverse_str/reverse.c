#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void reverse(char * str) {
  //WRITE ME!
  /*  int size=0;
  int front=0,back;
  while(str[size]!='\0')
    {
      size++;
    }
  if(size != 0)
    {
      back = size-1;
  while(back > front)
    {
      char temp = str[back];
      str[back] = str[front];
      str[front] = temp;
      back--;
      front++;
    }
    }*/
  void reverse(char *str)
  {
    int length, c;
    char *begin, *end, temp;

    length = 0;
    begin  = str;
    end    = str;

    while( *(str + length) != '\0' )
      length++;
    
    for (c = 0; c < length - 1; c++)
      end++;

    for (c = 0; c < length/2; c++)
      {
	temp   = *end;
	*end   = *begin;
	*begin = temp;

	begin++;
	end--;
      }
  }

 


int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
