#include <stdio.h>

/*
The following function supposedly combines two bytes to form an unsigned short integer.
Explain why the function doesn't work and show how to fix it.
*/

unsigned short create_short(unsigned char high_byte, unsigned char low_byte);

int main (void)
{

}

//replaced + with | and added some paranthesis
unsigned short create_short(unsigned char high_byte, unsigned char low_byte)
{
  return (high_byte << 8) | low_byte;
}
