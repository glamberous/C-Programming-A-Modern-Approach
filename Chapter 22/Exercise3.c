
//Find the error in the following program fragment and show how to fix it.

#include <stdio.h>



int main()
{
  FILE *fp;

  fp = fopen("filename.dat", "r");

  if(fp)
  {
    //read characters until end-of-file
    printf("Test.\n");
  }
  fclose(fp);
  // 1) the if condition isn't properly testing to see if the pointer is NULL
  // 2) filename needed to be in quotes
}
