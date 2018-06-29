

#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <ctype.h>			//toupper

#define arraySize ((int) (sizeof(array) / sizeof(array[0][0])))

int array[5][5] = {0}, row[5] = {0}, column[5] = {0}, i, j;

int main (void)
{
	
	
	for(i = 0; i < 5; i++)
	{
		printf("Enter row %d: ", (i + 1));
		for(j = 0; j < 5; j++)
		{
		scanf("%d", &array[i][j]);
		row[i] += array[i][j];
		}
	}
	
	printf("Row totals: ");
	for(i = 0; i < 5; i++)
		printf("%d ", row[i]);
	
	printf("\nColumn totals: ");
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			column[i] += array[j][i];
		}
	printf("%d ", column[i]);
	}
	
	
return (0);
}