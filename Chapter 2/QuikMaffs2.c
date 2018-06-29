/*Mans not hot*/
#include <stdio.h>

int main(void)
{
	int x, y;
	printf("Enter a number for some quik maffs (x): ");
	scanf("%d", &x);
	printf("BAM, SKrrrr-POP POP: %d\n", (3 * (x * x * x * x * x)) + (2 * (x * x * x* x)) - (5 * (x * x * x)) - (x * x) + (7 * x) - 6);
	printf("\nEnter a number for some quik maffs (y): ");
	scanf("%d", &y);
	printf("BAM, SKrrrr-POP POP: %d\n", (((((3*y) + 2)*y - 5)*y - 1)*y + 7)*y - 6);
	
	return 0;
}

