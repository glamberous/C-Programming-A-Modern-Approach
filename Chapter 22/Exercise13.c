
#include <stdio.h>
#include <stdlib.h>

// Write the following function

int line_length(const char *filename, int n);

/*
The function should return the length of line n in the text file whose name is
filename (assuming that the first line in the file is line 1). If the line doesn't
exist, the function should return 0;
*/

int main(int argc, char *argv[])
{
  int n = 0;
  char *str = "Config1.txt";

  //fprintf(stderr, "Enter which file to use: ");
  //scanf("%s", str)
  fprintf(stderr, "Enter which line to measure: ");
  scanf("%d", &n);
  fprintf(stderr, "line length is: %d\n", line_length(str, n));

  return 0;
}

int line_length(const char *filename, int n)
{
  FILE *fp;
  int letter_count = 0, ch = 0;

  if ((fp = fopen(filename, "rb")) == NULL)
  {
    fprintf(stderr, "ERR: Can't open %s\n", filename);
    exit(EXIT_FAILURE);
  }

  if (fseek(fp, 0, SEEK_SET) != 0) // fseek returns 0 on success
  {
    fprintf(stderr, "ERR: No lines in file\n");
    return 0;
  }

  while (n > 0)
  {
    ch = fgetc(fp);

    if(ch == EOF)
    {
      fprintf(stderr, "ERR: Could not access desired line\n");
      return 0;
    }
    if(ch == '\n')
    {
      n--;
    }
  }
  ch = 0; //clear the lingering \n character from ch

  while(ch != '\n' && ch != EOF)
  {
    ch = fgetc(fp);
    letter_count++;
  }


  fclose(fp);

  return letter_count;
}
