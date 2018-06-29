/*Buns not hot*/
#include <stdio.h>

int main(void)
{
	int AreaC, ExchangeC, LineNum;
	
	/*Collects the information from the user */
	printf("Enter phone number [(xxx) xxx-xxxx]: ");
	scanf("(%d) %d- %d", &AreaC, &ExchangeC, &LineNum);
	
	/*Prints out the inputted data into a special format*/
	printf("You entered: %d.%d.%d\n", AreaC, ExchangeC, LineNum);


	return 0;
}