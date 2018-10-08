#include <stdio.h>

//Write the following function
int count_ones1(unsigned char ch);
int count_ones2(unsigned char ch);
//count_ones should return the numbers of 1 bits in ch.

int main (void)
{
  unsigned char input = '\0';
  printf("Enter in a char to see how many one's it has: ");
  input = getchar();
  while(getchar() != '\n') ;
  printf("Number of ones is: %d\n", count_ones2(input));
}

int count_ones1(unsigned char ch)
{
  unsigned char temp = 1;
  int count = 0, real_count = 0;
  while(count < (sizeof(unsigned char) * 8))
  {
    temp <<= 1;
    count++;
    if(ch & temp)
      real_count++;
  }
  return real_count;
}

int count_ones2(unsigned char ch)
{
  return ((ch>>7 & 1)+(ch>>6 & 1)+(ch>>5 & 1)+(ch>>4 & 1)+(ch>>3 & 1)+(ch>>2 & 1)+(ch>>1 & 1)+(ch & 1));
}
