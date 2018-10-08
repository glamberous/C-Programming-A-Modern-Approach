#include <stdio.h>

//Write the following function:
unsigned int reverse_bits(unsigned int n);
//reverse_bits should return an unsigned integer whose bits are the same as
//those in n but in reverse order.

int main (void)
{
  unsigned int num = 0;

  printf("Enter a hexadecimal number (eight digits): ");
  scanf("%X", &num);

  printf("bits reveresed: %X\n", reverse_bits(num));

}

unsigned int reverse_bits(unsigned int n)
{
  unsigned int mask1 = 0x00000001, mask2 = 0x80000000, reversed_int = 0;
  int i;
  for(i = 0; i < 32; i++, mask1 <<= 1, mask2 >>= 1)
  {
    if(n & mask1)
    {
      reversed_int |= mask2;
    }
  }
  return reversed_int;
}
