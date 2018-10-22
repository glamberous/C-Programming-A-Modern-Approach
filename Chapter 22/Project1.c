/*
Checks whether a file can be opened for reading.  aka canopen.c

Extend the canopen.c program of Section 22.2 so that the user may put any number
of file names on the command line:

canopen foo bar baz

The program should print a separate can be opened or can't be opened message for
each file. Have the program terminate with status EXIT_FAILURE if one or more of
the files can't be opened.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int i;

  for(i = 1; i < argc; i++)
  {
    if ((fp = fopen(argv[i], "r")) == NULL)
    {
      printf("%s can't be opened\n", argv[i]);
      exit(EXIT_FAILURE);
    }
    printf("%s can be opened\n", argv[i]);
    fclose(fp);
  }

  return 0;
}
