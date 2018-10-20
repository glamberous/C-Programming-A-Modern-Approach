
#include <stdio.h>
#include <stdlib.h>

/*
Write your own version of the fgets function. Make it behave as much like the
real fgets function as possible; in particular, make sure that it has the proper
return value. To avoid conflicts with the standard library, don't name your
function fgets.
*/

char *custom_fgets(char *str, int max_char, FILE *stream);

/*
Write your own version of fputs. Following the same rules as mentioned in the
previous comment.
*/

int custom_fputs(const char * restrict str, FILE * restrict stream);

int main(int argc, char *argv[])
{
  char str[30] = "\0";
  FILE *fp;

  fp = fopen("Config1.txt", "r");

  custom_fputs(custom_fgets(str, 30, fp), stderr);

  return 0;
}

char *custom_fgets(char *str, int max_char, FILE *stream)
{
  int i = 0;

  if(stream == NULL)
  {
    fprintf(stderr, "ERR: Unnable to read stream");
    return NULL;
  }

  if ((str[i] = fgetc(stream)) == EOF)
  {
    fprintf(stderr, "ERR: Reached end of file before storing");
    return NULL;
  }

  while(str[i] != '\n' && str[i] != EOF && i < max_char - 1)
  {
    i++;
    str[i] = fgetc(stream);
  }
  str[++i] = '\0';

  //fprintf(stderr, str);   // For debugging
  //putchar('\n');          // For debugging

  return str;
}

int custom_fputs(const char * restrict str, FILE * restrict stream)
{
  int i = 0;

  if(stream == NULL)
  {
    fprintf(stderr, "ERR: fputs stream is null");
    return EOF;
  }

  fputc(str[0], stream);
  while(str[i] != '\0')
  {
    fputc(str[++i], stream);
  }

  return i;
}
