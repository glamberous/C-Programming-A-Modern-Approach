/* Prints a calendar */
#include <stdio.h>

int main(void)
{
	int totalDay, startDay, i;
	
	printf("Enter number of days in month: ");
	scanf("%d", &totalDay);
	printf("Enter starting day of the week (1=sun, 7=sat):");
	scanf("%d", &startDay);
	
	for (i = 1; i < startDay; i++)
	{
		printf("\t");
	}
	
	for (i = 1; i <= totalDay; i++, startDay++)
	{
		printf("%d\t", i);
		if ((startDay % 7) == 0)
		{
			printf("\n");
		}
	}
	
	return 0;
}