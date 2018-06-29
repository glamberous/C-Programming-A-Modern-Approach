

#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <ctype.h>			//toupper

#define arraySize ((int) (sizeof(array) / sizeof(array[0][0])))

int array[5][5] = {0}, total[5] = {0}, i, j, lowest = 999, highest = 0, totalAverage = 0;

int main (void)
{
	for(i = 0; i < 5; i++)
	{
		printf("Enter five grades for student #%d: ", (i + 1));
		for(j = 0; j < 5; j++)
		{
			scanf("%d", &array[i][j]);
		
			total[i] += array[i][j];
			totalAverage += array[i][j];
			lowest = lowest < array[i][j]?lowest:array[i][j];
			highest = highest > array[i][j]?highest:array[i][j];
		}
	}
	
	for(i = 0; i < 5; i++)
		printf("Student %d's totals: %d\n", (i + 1), total[i]);
	
	for(i = 0; i < 5; i++)
		printf("Student %d's averages: %d\n", (i + 1), (total[i] / 5));
	
	printf("Total average of all quizzes: %d\n", (totalAverage / 25));
	printf("Lowest scored quiz was: %d\n", lowest);
	printf("Highest scored quiz was: %d\n", highest);
	
	
	
return (0);
}