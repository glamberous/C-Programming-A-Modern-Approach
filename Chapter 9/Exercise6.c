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

short digit(unsigned int n, short k)
{
	short i;
	for (i = 1; i < k; i++)
		n /= 10;
		
	return (n % 10);
}


int main(void)
{	
	unsigned int num;
	short fromRight;
	
	printf("Enter in a positive number you want a digit returned for: ");
	scanf("%ud", &num);
	printf("Which digit (counted from the right) would you like to return? ");
	scanf("%hd", &fromRight);
	printf("Number of digits in your number was: %hd", digit(num, fromRight));
	
	return (0);
}