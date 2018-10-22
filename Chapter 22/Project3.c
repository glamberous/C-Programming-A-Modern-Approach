/*
Write a program named fcat that "concatenates" any number of files by writing
them to standard output, one after the other, with no break between files. For
example, the following command will display the files f1.c, f2.c, and f3.c on
the screen:
fcat f1.c f2.c f3.c
fcat should issue an error message if any file can't be opened. Hint: since it
has no more than one file open at a time, fcat needs only a single file pointer
variable. Once it's finished with a file, fcat can use the same variable when
it opens the next file
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

    int ch = 0;
    while ((ch = fgetc(fp)) != EOF)
      fputc(ch, stdout);

    fclose(fp);
  }

  return 0;
}
