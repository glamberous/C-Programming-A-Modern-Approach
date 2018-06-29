#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans

#define arraySize ((int) (sizeof(temperature_readings) / sizeof(tempurature_readings[0][0])))

int main (void)
{
	char i, j;
	double dayAverage = 0, monthAverage = 0, temperature_readings[30][24] = {0};
	
	for (i = 0; i < arraySize; i++)
	{
		for (j = 0; j < arraySize / 30; j++)
			dayAverage += temperature_readings[i][j];
		dayAverage /= 24;
		monthAverage += dayAverage;
	}
	monthAverage /= 30;
	
	printf("%f", monthAverage);
	
return (0);
}