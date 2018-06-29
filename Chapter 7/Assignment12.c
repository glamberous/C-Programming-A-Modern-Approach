/* Takes a first name and last name entered by the user and displays the last name, 
a comma, and the first initial, followed by a period. */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

int main(void)
{	
	char ch = 0;
	float operand = 0, total = 0;
	
	printf ("Enter an expression: ");
	scanf("%f", &operand);
	total += operand;
	ch = getchar();
	
	while (ch != '\n')
	{
		scanf("%f", &operand);
		
		if (ch == '+')
			total += operand;
		else if (ch == '-')
			total -= operand;
		else if (ch == '/')
			total /= operand;
		else if (ch == '*')
			total *= operand;
		else
			return(0);
		
		ch = getchar();
	}
	
	printf("Value of expression: %.2f", total);
	
	return (0);
}