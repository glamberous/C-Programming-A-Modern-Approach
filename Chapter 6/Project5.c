/* Reverses numbers of an int */
#include <stdio.h>

int main(void)
{
	int input;
	
	/*Collects the information from the user */
	printf("Enter a number: ");
	scanf("%d", &input);

	printf ("The reversal is: ");
	do
	{		
		printf ("%d", (input % 10));
		input /= 10;
	} while (input != 0);
	
	return 0;
}