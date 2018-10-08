#include <stdio.h>

/*
Design a union that makes it possible to view a 32-bit value as either a float
or the described in Exercise 14. Write a program that stores 1 in the structures
sign field, 128 in the exponent field, and 0 in the fraction field, then prints
the float value stored in the union. (The answer should be -2.0 if you've set up
the bit-fields correctly.)
*/

int main (void)
{
  union
  {
    float i;
    struct {
      unsigned int fraction: 23, exponent: 8, sign: 1;
    } custom;
  } u;

  u.custom.fraction = 0;
  u.custom.exponent = 128;
  u.custom.sign = 1;

  printf("%f\n", u.i);
}
