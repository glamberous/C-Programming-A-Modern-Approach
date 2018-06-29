#include <stdio.h>

/* This program takes a user inputted string and reverses it */

// \r is important for this

typedef short int Int8;
typedef int Int16;
typedef long int Int32;

Int8 i = 0;
Int16 j = 0;
Int32 k = 0;


int main() 
{

printf("Int8 = %hd, Int16  %d, Int32 = %ld", i + 32768, j + 2147483648, k + 9223372036854775807);


   return(0);
}