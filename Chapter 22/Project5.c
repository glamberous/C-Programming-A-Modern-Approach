/*
Thexor.c program of Section 20.1 refuses to encrypt bytes that--in original or
encrypted form--are control characters. We can now remove this restriction.
Modify the program so that the names of the input and output files are
command-line arguments. Open both files in binary mode, and remove the test
that checks whether the original and encrypted characters are printing characters.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define KEY '&'

int main(int argc, char *argv[])
{
  FILE *fp1, *fp2;
  int read_char;

  if ((fp1 = fopen(argv[1], "rb")) == NULL)
  {
    printf("%s can't be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if ((fp2 = fopen("XorEncryption1.txt", "wb")) == NULL)
  {
    printf("%s can't be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  while ((read_char = fgetc(fp1)) != EOF)
    fputc(read_char ^ KEY, fp2);

  return 0;
}
