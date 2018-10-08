#include <stdio.h>

unsigned int rotate_right(unsigned int i, int n);
unsigned int rotate_left(unsigned int i, int n);

//1 int = 4 bytes = 32 bit = 8 hex

int main (void)
{
  unsigned int num = 0x12345678;
  int shift = 0;

  //printf("Enter a hexadecimal number (eight digits): ");
  //scanf("%x", &num);
  printf("Enter a number for byte shift: ");
  scanf("%d", &shift);
  shift *= 4;
  printf("Number with bytes moved right: %x\n", rotate_right(num, shift));
  printf("Number with bytes moved left: %x\n", rotate_left(num, shift));
}

unsigned int rotate_right(unsigned int i, int n)
{
  return (i << (32 - n)) | (i >> n);
}

unsigned int rotate_left(unsigned int i, int n)
{
  return i >> (32 - n) | (i << n);
}
