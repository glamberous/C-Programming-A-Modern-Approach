#include <stdio.h>

/*
When store according to the IEEE floating-point standard, a float value consists
of a 1-bit sign (the leftmost--or most significant--bit), an 8-bit exponent, and
a 23-bit fraction, in that order.

Design a structure type that occupies 32 bits,
with bit-fields members corresponding to the sign, exponent, and fraction. Declare
the bit-fields to have type unsigned int. Check manual for your compiler to
determine the order of the bit-fields.
*/

int main (void)
{

struct custom {
  unsigned int fraction: 23, exponent: 8, sign: 1;
  };
}
