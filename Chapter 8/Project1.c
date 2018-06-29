#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans

#define arraySize ((int) (sizeof(temperature_readings) / sizeof(tempurature_readings[0][0])))

int main (void)
{
	short digit_seen[10] = {0};
	int digit, i;
	long n;
	
	printf("Enter a number: ");
	scanf("%ld", &n);
	
	while (n > 0) {
		digit = n % 10;
		digit_seen[digit]++;
		n /= 10;
	}
	printf("Repeated digits: ");
	for(i = 0; i < 10; i++)
	{
		if (digit_seen[i] >= 2)
		{
			printf("%d ", i);
		}
	}

	
return (0);
}