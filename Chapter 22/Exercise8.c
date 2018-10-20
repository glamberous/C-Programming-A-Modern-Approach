
/*
In previous chapters, we've used the scanf format string " %c" when we wanted to
skip white-space characters and read a nonblank character. Some programmers use "%1s"
instead. Are the two techniques equivalent? if not, what are the differences?
*/

#include <stdio.h>
#include <string.h>

int main()
{
  char ch = '\0';
  char str[2] = "\0";

  scanf(" %c", &ch); // stores only a character
  while(getchar() != '\n');
  scanf("%1s", str); // stores a character + null character
  while(getchar() != '\n');

  printf("Char = %c\n", ch);
  printf("String = %s\n", str);
}
