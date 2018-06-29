/* Search through an array for a specific temperature */

#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator
#include <time.h> 			//includes time

void fill_temp_array(int temperature[][24]);
void display_temps(int temperature[][24]);
int search_temp(int temperature[][24], int key);

int main (void)
{
	int temperature[7][24];
	int search = 0;
	

	fill_temp_array(temperature);
	display_temps(temperature);
	
	printf("What temperature would you like to search for? ");
	scanf("%d", &search);
	
	printf("There are %d of that number throughout the week.", search_temp(temperature, search));
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

void display_temps(int temperature[][24])
{
	int *p, count = 0;
	
	for(p = &temperature[0][0]; p <= &temperature[7-1][24-1]; p++)
	{
		printf("%d\t", *p);
		count++;
		if (count == 7)
		{
			printf("\n");
			count = 0;
		}
	}
	printf("\n");
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

