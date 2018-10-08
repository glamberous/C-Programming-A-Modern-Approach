
#include <stdio.h>

void bit_toggle(unsigned short *);
void bit_toggle2(unsigned short *);

int main (void)
{
  unsigned short i;

  i = 0;
  printf("Enter a number to bit toggle: ");
  scanf("%hu", &i);
  printf("pre bit toggle i = %hu\n", i);
  bit_toggle2(&i);
  printf("post bit toggle i = %hu\n", i);
}

void bit_toggle(unsigned short *i)
{
  if(*i & 0x0010)
    *i &= ~0x0010;
  else
    *i |= 0x0010;
}

void bit_toggle2(unsigned short *i)
{
  *i = *i ^ 0x0010;
}
