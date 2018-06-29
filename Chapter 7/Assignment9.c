/* Converts 12-hour time into 24-hour time. */
#include <stdio.h>
#include <ctype.h>
#define AM 1																				//To be used with the AM_PM Char
#define PM 0

int main(void)
{	
	char ch = 0, AM_PM = 2;																	// Used for determining AM or PM
	int hours = 0, minutes = 0, minSinceMidnight = 0;							// flight ints will be listed in minutes since midnight

	
	//User inputs 12-hour time
	printf("\nEnter a 12-hour time (Example: 3:46pm): ");
	scanf("%d:%d", &hours, &minutes);
	
	while (AM_PM == 2)																		//Determines whether AM or PM was inputted
	{
		ch = getchar();
		ch = toupper(ch);
		switch (ch)
		{
			case 'A':
				AM_PM = AM;
				break;
			case 'P':
				AM_PM = PM;
				break;
			case '\n':
				printf("Invalid input.");
				return (0);
			default:
				break;
		}
	}
	
	minSinceMidnight = (hours * 60) + minutes;												//Converts the user's input to minSinceMidnight
	
	if (AM_PM == PM && hours != 12)
	{
		minSinceMidnight += 720;
	}
	else if (AM_PM == PM && hours == 12)
	{
		minSinceMidnight -= 720;
	}
	
	hours = minSinceMidnight / 60;
	minutes = minSinceMidnight % 60;
		
	printf("24-hour time is %d:%.2d ", hours, minutes);

	
	return (0);
}