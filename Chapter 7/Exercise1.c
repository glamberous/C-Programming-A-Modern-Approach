#include <stdio.h>

int main() 
{
	int decimal1 = 077, decimal2 = 0x77, decimal3 = 0XABC;

   printf("077 in decimal: %i\n", decimal1);
   scanf("%i", &decimal1);
   printf("user input was: %i\n", decimal1);
   printf("My guess was 77\n\n");
   
   printf("0x77 in decimal: %i\n", decimal2);
   printf("My guess was 119\n\n");
   
   printf("0XABC in decimal: %i\n", decimal3);
   printf("My guess was 2748\n\n");

//2560 + 176 + 12
   return(0);
}