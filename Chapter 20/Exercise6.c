#include <stdio.h>

unsigned short swap_bytes(unsigned short i);

int main (void)
{
  unsigned short num = 0;

  printf("Enter a hexadecimal number (up to four digits): ");
  scanf("%hx", &num);
  printf("Number with bytes swapped: %hx\n", swap_bytes(num));

}

unsigned short swap_bytes(unsigned short i)
{
  /*unsigned short temp = 0;

  temp = (i & 0x00ff) << 8;
  i = (i & 0xff00) >> 8;
  temp |= i;
  return temp;*/

  return (i << 8) | (i >> 8);
}
