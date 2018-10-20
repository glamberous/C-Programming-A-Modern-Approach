
/*
Find the error in the following function and show how to fix it.
*/

#include <stdio.h>
#include <stdlib.h>

int count_periods(const char *);

int main(int argc, char *argv[])
{

}

int count_periods(const char *filename)
{
  FILE *fp;
  int n = 0, ch = 0;

  if ((fp = fopen(filename, "r")) != NULL)
  {
    while((ch = fgetc(fp)) != EOF)
    {
      if(ch == '.')
        n++;
    }
    fclose(fp);
  }

  return n;
}

//Had to add int ch so the character could be saved and checked twice properly.
