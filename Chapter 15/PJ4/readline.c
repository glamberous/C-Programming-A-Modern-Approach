/*  Modify the remind.c program of Section 13.5 so that  the
read_line  function is in a separate file named  readline.c.
Create  a  header  file  named readline.h  that  contains  a
prototype  for  the  function  and have  both  remind.c  and
readline.c include this file. */

#include "readline.h"

int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
