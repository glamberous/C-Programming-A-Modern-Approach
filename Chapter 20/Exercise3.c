

#include <stdio.h>

#define M(x,y) ((x)^=(y), (y)^=(x), (x)^=(y)) //this trades the values of two variables

int main (void)
{
  unsigned short i, j;

  i = 4, j = 6;

  printf("x = %hu\ny = %hu\n", i, j);
  M(i,j);
  printf("x = %hu\ny = %hu\n", i, j);
}
