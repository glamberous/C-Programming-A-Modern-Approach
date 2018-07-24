/*
Write a program that accepts a date from the user in the form mm/dd/yyyy and
then displays it in the form month dd, yyyy. where month is the name of the month:
Enter a date (mm/dd/yyyy): 2/17/2011
You entered the date February 17, 2011
Store the month names in an array that contains pointers to strings.
*/

#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator
#include <time.h> 			//includes time
#include <ctype.h>			//toupper

#define NUM_MONTHS 12
#define STR_MAX 17

void convert_format(char *);

int main (void)
{
	char str[STR_MAX + 1] = {'\0'};

	printf("Enter a date (mm/dd/yyyy): ");
	fgets(str, STR_MAX, stdin);
	convert_format(str);
	printf("You entered the date %s\n", str);

	return 0;
}

void convert_format(char *message)
{
	const char *months[NUM_MONTHS] = {"January", "February", "March", "April",
	"May", "June", "July", "August", "September", "October", "November", "December"};
	int month = 0, day = 0, year = 0;

	sscanf(message, "%2d/%2d/%4d", &month, &day, &year);
	sprintf(message, "%2s %2d, %4d", months[month - 1], day, year);
}
