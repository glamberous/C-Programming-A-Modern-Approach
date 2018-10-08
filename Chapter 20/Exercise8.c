#include <stdio.h>

unsigned int f(unsigned int i, int m, int n);

int main (void)
{

}

unsigned int f(unsigned int i, int m, int n)
{
  return (i >> (m + 1 - n)) & ~(~0 << n);
}

/*
a) What is the value of ~(~0 << n)?
1x2^n + 1x2^n-1 till n = 0

b) What does this function do?
Returns n number of bits starting at bit m out of unsigned int i

*/
