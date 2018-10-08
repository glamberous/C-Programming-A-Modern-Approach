

#include <stdio.h>

#define MK_COLOR(red,green,blue) ((long)(blue) << 16|(green) << 8|(red))

unsigned short focus_red(unsigned long color);
unsigned short focus_green(unsigned long color);
unsigned short focus_blue(unsigned long color);

int main (void)
{
  unsigned long color = 0;
  unsigned short red = 0, green = 0, blue = 0;

  printf("Enter red: ");
  scanf("%hu", &red);
  printf("Enter green: ");
  scanf("%hu", &green);
  printf("Enter blue: ");
  scanf("%hu", &blue);
  color = MK_COLOR(red,green,blue);

  printf("x = %lu\n", color);
  printf("red = %hu\n", focus_red(color));
  printf("green = %hu\n", focus_green(color));
  printf("blue = %hu\n", focus_blue(color));
}

unsigned short focus_red(unsigned long color)
{
  unsigned short temp = 0x0000;
  temp = color & 0x00ff;
  return temp;
}

unsigned short focus_green(unsigned long color)
{
  unsigned short temp = 0x0000;
  temp = (color >> 8) & 0x00ff;
  return temp;
}

unsigned short focus_blue(unsigned long color)
{
  unsigned short temp = 0x0000;
  temp = (color >> 16) & 0x00ff;
  return temp;
}
