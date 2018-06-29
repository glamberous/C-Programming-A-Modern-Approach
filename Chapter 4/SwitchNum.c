/*testing commit changes again a third time*/
#include <stdio.h>

int main(void)
{
	int input, output, num1, num2, num3;
	
	/*Collects the information from the user */
	printf("Enter a three-digit number: ");
	scanf("%d", &input);

	num1 = ((input % 100) %10) * 100;
	num2 = ((input % 100) / 10) * 10;
	num3 = input / 100;
	output = num1 + num2 + num3;
	
	printf("The reversal is: %d ", output);
	
	return 0;
}
