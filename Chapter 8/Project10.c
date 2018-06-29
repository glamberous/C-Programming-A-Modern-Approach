/* User inputs a time in 12-hour format and the program will list a 
known flight departure time closest to the time the user entered  */
#include <stdio.h>
#include <stdbool.h>		//booleans
#include <ctype.h>	
#define AM 1																				//To be used with the AM_PM Char
#define PM 0

int main(void)
{	
	char ch = 0, AM_PM = 2;																	// Used for determining AM or PM
	int hours = 0, hours12 = 0, minutes = 0, minSinceMidnight = 0, x = 0, 					// flight ints will be listed in minutes since midnight
	dFlight[8] = {480, 583, 679, 767, 840, 945, 1140, 1305},								// "d" stands for departure
	aFlight[8] = {616, 712, 811, 900, 968, 1075, 1280, 1438};								// "a" stands for arrival
	bool flag = true;
	
	//User inputs 12-hour time
	printf("\nEnter a 12-hour time (Example: 3:46pm): ");
	scanf("%d:%d", &hours, &minutes);
	
	while (AM_PM == 2)																		//Determines whether AM or PM was inputted
	{
		ch = getchar();
		ch = toupper(ch);
		switch(ch)
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
			/* intentionally null */;
		}
	}
	
	//Converts the user's input to minSinceMidnight
	minSinceMidnight = (hours * 60) + minutes;
	
	if (AM_PM == PM && hours != 12)
	{
		minSinceMidnight += 720;
	}
	else if (AM_PM == AM && hours == 12)
	{
		minSinceMidnight -= 720;
	}
	
	for(x = 0; x < 8; x++)
	{
		if (minSinceMidnight <= dFlight[x])
		{
			hours = dFlight[x] / 60;
			minutes = dFlight[x] % 60;
			hours12 = hours > 12 ? (hours - 12) : hours;
		
			//Departure
			printf("Closest departure time is %d:%.2d ", hours12, minutes);
			if (hours < 12)
			{
				printf("a.m.");
			}
			else
			{
				printf("p.m.");
			}
		
			//Arrival
			hours = aFlight[x] / 60;
			minutes = aFlight[x] % 60;
			hours12 = hours > 12 ? (hours - 12) : hours;
			
			printf(", arriving at %d:%.2d ", hours12, minutes);
			if (hours < 12)
			{
				printf("a.m.");
			}
			else
			{
				printf("p.m.");
			}
			flag = false;
			break;
		}
	}
	
	if (flag)
	{
		printf("There are no more flights for the rest of the day.");
	}
	
	return 0;
}