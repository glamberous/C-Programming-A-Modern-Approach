/*Mans not hot*/
#include <stdio.h>

int main(void)
{
	int input, change20, change10, change5, change1;

	printf("\nEnter a number for some change: ");
	scanf("%d", &input);
	
	change20 = input/20;
	change10 = (input-(change20 * 20))/10;
	change5  = (input-((change20 * 20) + (change10 * 10)))/5;
	change1  = (input-((change20 * 20) + (change10 * 10) + (change5 * 5)))/1;
	
	printf("$20 bills: %d\n", change20 );
	printf("$10 bills: %d\n", change10 );
	printf("$5 bills: %d\n",  change5  );
	printf("$1 bills: %d\n",  change1  );
	
	return 0;
}