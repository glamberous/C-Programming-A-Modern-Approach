#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans

#define arraySize ((int) (sizeof(temperature_readings) / sizeof(tempurature_readings[0][0])))

int main (void)
{
	short digit_seen[10] = {0};
	unsigned int digit = 0, i = 0;
	
	while (1)
	{
		printf("Enter a number: ");
		scanf("%d", &i);
		if (i <= 0)
			break;
	
		while (i > 0)
		{
			digit = i % 10;
			digit_seen[digit]++;
			i /= 10;
		}
	}


	
	printf("Digit: \t\t");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", i);
	}
	
	printf("\nOccurances: \t");
	for(i = 0; i < 10; i++)
	{
		printf("%d ", digit_seen[i]);
	}
	
return (0);
}