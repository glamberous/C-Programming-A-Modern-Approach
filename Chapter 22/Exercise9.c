
/*
Which one of the following calls is not a valid way of reading one character from
the standard input stream?
*/

#include <stdio.h>
#include <string.h>

int main()
{
  char ch = '\0';

  //a) not valid, doesn't exist - CORRECT
  //ch = getch();

  //b) valid - CORRECT
  //ch = getchar();

  //c) not valid, no argument - WRONG, was valid
  //ch = getc(stdin);

  //d) valid - CORRECT
  ch = fgetc(stdin);

  printf("%c\n", ch);
}
