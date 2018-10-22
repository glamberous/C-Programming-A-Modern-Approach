/*
Write a program that converts all letters in a file to upper case. (characters
other than letters shouldn't be changed.) The program should obtain the file
name from the command line and write it's output to stdout.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  FILE *fp;

  if ((fp = fopen(argv[1], "r")) == NULL)
  {
    printf("%s can't be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  int ch = 0;
  while ((ch = fgetc(fp)) != EOF)
  {
    fputc(toupper(ch), stdout);
  }

  fclose(fp);
  return 0;
}
