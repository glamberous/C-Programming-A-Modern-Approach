#include <stdio.h>

/*
If n is an unsigned int variable, what effect does the following statement have
on the bits in n?
*/


int main (void)
{
  unsigned int n = 0xffff;

  while (n != 0)
  {
    n &= n - 1; //This causes the farthest 1 (left side) to be removed
    printf("%x\n", n);
  }

}
