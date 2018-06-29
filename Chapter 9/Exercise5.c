/* Exercises that do things */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper




short num_digits(unsigned int n)
{	
	short i;
	for(i = 0; n != 0; i++)
		n /= 10;
	
	return (i);
}


int main(void)
{	
	unsigned int num;
	
	printf("Enter in a positive number you want the digits counted for: ");
	scanf("%ud", &num);
	printf("Number of digits in your number was: %hd", num_digits(num));
	
	return (0);
}