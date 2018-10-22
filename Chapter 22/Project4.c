/*
a) Write a program that counts the number of characters in a text file.
b) Write a program that counts the number of words in a text file. (A "word" is
any sequence of non-white space characters.)
c) Write a program that counts the number of lines in a text file.
Have each program obtain the file name from the command line.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int fletter_count(FILE *fp);
int fword_count(FILE *fp);
int fline_count(FILE *fp);

int main(int argc, char *argv[])
{
  FILE *fp;

  if ((fp = fopen(argv[1], "r")) == NULL)
  {
    printf("%s can't be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  fprintf(stdout, "Letter count: %d\nWord count: %d\nLine count: %d\n", fletter_count(fp),
    fword_count(fp), fline_count(fp));

  return 0;
}

int fletter_count(FILE *fp)
{
  fseek(fp, 0, SEEK_SET);
  int char_count = 0;
  while (fgetc(fp) != EOF)
    char_count++;

  return char_count++;
}

int fword_count(FILE *fp)
{
  fseek(fp, 0, SEEK_SET);
  int ch = 0, word_count = 0;
  while (ch != EOF)
  {
    while(isspace(ch) != 0)
      ch = fgetc(fp);
    while(isspace(ch) == 0 && ch != EOF)
      ch = fgetc(fp);

    word_count++;
  }

  return word_count++;
}

int fline_count(FILE *fp)
{
  fseek(fp, 0, SEEK_SET);
  int ch = 0, line_count = 0;
  while ((ch = fgetc(fp)) != EOF)
    if (ch == '\n')
      line_count++;

  return line_count++;
}
