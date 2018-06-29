#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator

#define ARRAY_SIZE 10


void split_date(int day_of_year, int year, int *month, int *day);


bool leapYear = false;


int main(void)
{
	int month, day, year, day_of_year;
	
	printf("Please enter in a day of the year: ");
	scanf("%d", &day_of_year);
	printf("What year is it? ");
	scanf("%d", &year);
	
	
	split_date(day_of_year, year, &month, &day);
	
	printf("Day of the year you entered was: %d\n", day_of_year);
	printf("%2d/%2d/%d\n", month, day, year);
	if (leapYear)
		printf("LeapYear");

}

void split_date(int day_of_year, int year, int *month, int *day)
{
	
	int months[11] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
	int i = 0;
	
	*month = 1;
	
	if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		months[1]++;

	while(day_of_year > months[i] && i < 11)
	{
		day_of_year -= months[i];
		(*month)++;
		i++;
	}
	
	*day = day_of_year;
	
}

