/* Prints a table of squares using an odd method */
#include <stdio.h>

int main(void)
{
	int totalDay, startDay, i;
	printf("Enter number of days in month: ");
	scanf("%d", &totalDay);
	printf("Enter starting day of the week (1=sun, 7=sat):");
	scanf("%d", &startDay);
	
	for (i = 1; i <= startDay; i++)
	{
		printf("\t");
	}
	
	for (i = 1; i <= totalDay; i++)
	{
		printf("%d\t", i);
		if (i = 7 || i = 14 || i = 21 || i = 28)
		{
			printf("\n");
		}
	}
	
	return 0;
}