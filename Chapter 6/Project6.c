/* lists all the even squares below the inputted number */
#include <stdio.h>

int main(void)
{
	int input, evenSq;
	
	/*Collects the information from the user */
	printf("Enter a number: ");
	scanf("%d", &input);
	
	
	for (evenSq = 2;(evenSq * evenSq) <= input; evenSq += 2)
	{
		printf ("%d\n", (evenSq * evenSq));
	}
	
	return 0;
}