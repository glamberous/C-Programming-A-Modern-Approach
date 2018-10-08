
#include <stdio.h>

int main (void)
{
  unsigned short i, j, k;
  //A
  i = 8; j = 9;
  printf("%d\n", i >> 1 + j >> 1);
  printf("My answer: 0\n");

  //B
  i = 1;
  printf("%d\n", i & ~i);
  printf("My answer: 0\n");

  //C
  i = 2; j = 1; k = 0;
  printf("%d\n", ~i & j ^ k);
  printf("My answer: 1\n");

  //D
  i = 7; j = 8; k = 9;
  printf("%d\n", i ^ j & k);
  printf("My answer: 9\n"); // it was 15, & has a higher priority over ^
}
