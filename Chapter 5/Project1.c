/*Buns not hot*/
#include <stdio.h>

int main(void)
{
	int input, digits;
	printf ("Enter a number with 1-4 digits: ");
	scanf ("%d", &input);
	
	if (input < 0 || input > 9999) 
		printf ("Number input is invalid, try again with a 1-4 digit number.\n");
	else
	{
		{
			if (input >= 0 && input <= 9)
				digits = 1;
			else if (input >= 10 && input <= 99) 
				digits = 2;
			else if (input >= 100 && input <= 999)
				digits = 3;
			else
				digits = 4;
		}
		printf ("The number is %d and has %d digits.\n", input, digits);
	}
	
	
	return 0;
}