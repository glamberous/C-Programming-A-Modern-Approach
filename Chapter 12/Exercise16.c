/* Search through an array for a specific temperature */

#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator
#include <time.h> 			//includes time

void fill_temp_array(int temperature[][24]);
void display_temps(int temperature[][24], int input);
int find_largest(int temperature[][24], int input);
int search_temp(int temperature[][24], int key);

int main (void)
{
	int temperature[7][24];
	int input = 0;
	

	fill_temp_array(temperature);
	

	while(1)
	{
		printf("What row would you like to view? ");
		scanf("%d", &input);
		if(input < 1 || input > 7)
			break;
		display_temps(temperature, input);
	}
	

	while(1)
	{
		printf("Which row do you want to know the highest temp of? ");
		scanf("%d", &input);
		if(input < 1 || input > 7)
			break;
		printf("The largest in row %d is %d.\n", input, find_largest(temperature, input));
	}
	
	printf("What temperature would you like to search for? ");
	scanf("%d", &input);
	
	printf("There are %d of that number throughout the week.", search_temp(temperature, input));
}

void fill_temp_array(int temperature[][24])
{
	int *p;
	srand (time(NULL));
	
	for(p = &temperature[0][0]; p <= &temperature[7-1][24-1]; p++)
	{
		*p = (rand()%130)-30;
	}
}

void display_temps(int temperature[][24], int input)
{
	int *p, count = 0;
	
	for(p = temperature[input-1]; p < temperature[input-1] + 24; p++)
	{
		printf("%d ", *p);
		count++;
	}
	printf("\n\n");
}

int find_largest(int temperature[][24], int input)
{
	int *p, large_temp = -30;
	
	for(p = temperature[input-1]; p < temperature[input-1]+24; p++)
	{
		if(*p > large_temp)
		{
			large_temp = *p;
		}
	}
	printf("\n\n");
	return large_temp;
}

int search_temp(int temperature[][24], int key)
{
	int *p, count = 0;
	
	for(p = &temperature[0][0]; p <= &temperature[7-1][24-1]; p++)
	{
		if(*p == key)
		{
			count++;
		}
	}
	return count;
}

