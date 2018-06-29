/* program computes the factorial of a positive integer */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

int main(void)
{																
	unsigned int countTo = 0, i = 0;
	long factorial = 1;
	
	
	printf("Enter a positive integer: ");
	scanf("%d", &countTo);
	
	for (i = 1; i <= countTo; i++)
		factorial *= i;

	printf("Factorial of %d: %30ld", countTo, factorial);
	
	return (0);
}