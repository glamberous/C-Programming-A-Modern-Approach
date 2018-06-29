/* User inputs a time in 12-hour format and the program will list a 
known flight departure time closest to the time the user entered  */
#include <stdio.h>
#include <ctype.h>
#define AM 1																				//To be used with the AM_PM Char
#define PM 0

int main(void)
{	
	char ch = 0, AM_PM = 2;																	// Used for determining AM or PM
	int hours = 0, hours12 = 0, minutes = 0, minSinceMidnight = 0,							// flight ints will be listed in minutes since midnight
	dFlight1, dFlight2, dFlight3, dFlight4, dFlight5, dFlight6, dFlight7, dFlight8,			// "d" stands for departure
	aFlight1, aFlight2, aFlight3, aFlight4, aFlight5, aFlight6, aFlight7, aFlight8;			// "a" stands for arrival
	
	dFlight1 = 480; aFlight1 = 616;															//Flight Arrival and Departure database in minutes since midnight
	dFlight2 = 583; aFlight2 = 712;
	dFlight3 = 679; aFlight3 = 811;
	dFlight4 = 767; aFlight4 = 900;
	dFlight5 = 840; aFlight5 = 968;
	dFlight6 = 945; aFlight6 = 1075;
	dFlight7 = 1140; aFlight7 = 1280;
	dFlight8 = 1305; aFlight8 = 1438;
	
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
	
	
	if (minSinceMidnight <= dFlight1)
	{
		hours = dFlight1 / 60;
		minutes = dFlight1 % 60;
		hours12 = hours > 12 ? (hours - 12) : hours;
		
		//Departure
		printf("Closest departure time is %d:%.2d ", hours12, minutes);
		if (hours <= 12 && hours != 0)
			printf("AM");
		else
			printf("PM");
		
		//Arrival
		hours = aFlight1 / 60;
		minutes = aFlight1 % 60;
		hours12 = hours > 12 ? (hours - 12) : hours;
		
		printf(", arriving at %d:%.2d ", hours12, minutes);
		if (hours <= 12 && hours != 0)
			printf("AM");
		else
			printf("PM");
	}
	else if (minSinceMidnight <= dFlight2)
	{
		hours = dFlight2 / 60;
		minutes = dFlight2 % 60;
		hours12 = hours > 12 ? (hours - 12) : hours;
		
		//Departure
		printf("Closest departure time is %d:%.2d ", hours12, minutes);
		if (hours <= 12 && hours != 0)
			printf("AM");
		else
			printf("PM");
		
		//Arrival
		hours = aFlight2 / 60;
		minutes = aFlight2 % 60;
		hours12 = hours > 12 ? (hours - 12) : hours;
		
		printf(", arriving at %d:%.2d ", hours12, minutes);
		if (hours <= 12 && hours != 0)
			printf("AM");
		else
			printf("PM");
	}
	else if (minSinceMidnight <= dFlight3)
	{
		hours = dFlight3 / 60;
		minutes = dFlight3 % 60;
		hours12 = hours > 12 ? (hours - 12) : hours;
		
		//Departure
		printf("Closest departure time is %d:%.2d ", hours12, minutes);
		if (hours <= 12 && hours != 0)
			printf("AM");
		else
			printf("PM");
		
		//Arrival
		hours = aFlight3 / 60;
		minutes = aFlight3 % 60;
		hours12 = hours > 12 ? (hours - 12) : hours;
		
		printf(", arriving at %d:%.2d ", hours12, minutes);
		if (hours <= 12 && hours != 0)
			printf("AM");
		else
			printf("PM");
	}
	else if (minSinceMidnight <= dFlight4)
	{
		hours = dFlight4 / 60;
		minutes = dFlight4 % 60;
		hours12 = hours > 12 ? (hours - 12) : hours;
		
		//Departure
		printf("Closest departure time is %d:%.2d ", hours12, minutes);
		if (hours <= 12 && hours != 0)
			printf("AM");
		else
			printf("PM");
		
		//Arrival
		hours = aFlight4 / 60;
		minutes = aFlight4 % 60;
		hours12 = hours > 12 ? (hours - 12) : hours;
		
		printf(", arriving at %d:%.2d ", hours12, minutes);
		if (hours <= 12 && hours != 0)
			printf("AM");
		else
			printf("PM");
	}
	else if (minSinceMidnight <= dFlight5)
	{
		hours = dFlight5 / 60;
		minutes = dFlight5 % 60;
		hours12 = hours > 12 ? (hours - 12) : hours;
		
		//Departure
		printf("Closest departure time is %d:%.2d ", hours12, minutes);
		if (hours <= 12 && hours != 0)
			printf("AM");
		else
			printf("PM");
		
		//Arrival
		hours = aFlight5 / 60;
		minutes = aFlight5 % 60;
		hours12 = hours > 12 ? (hours - 12) : hours;
		
		printf(", arriving at %d:%.2d ", hours12, minutes);
		if (hours <= 12 && hours != 0)
			printf("AM");
		else
			printf("PM");
	}
	else if (minSinceMidnight <= dFlight6)
	{
		hours = dFlight6 / 60;
		minutes = dFlight6 % 60;
		hours12 = hours > 12 ? (hours - 12) : hours;
		
		//Departure
		printf("Closest departure time is %d:%.2d ", hours12, minutes);
		if (hours <= 12 && hours != 0)
			printf("AM");
		else
			printf("PM");
		
		//Arrival
		hours = aFlight6 / 60;
		minutes = aFlight6 % 60;
		hours12 = hours > 12 ? (hours - 12) : hours;
		
		printf(", arriving at %d:%.2d ", hours12, minutes);
		if (hours <= 12 && hours != 0)
			printf("AM");
		else
			printf("PM");
	}
	else if (minSinceMidnight <= dFlight7)
	{
		hours = dFlight7 / 60;
		minutes = dFlight7 % 60;
		hours12 = hours > 12 ? (hours - 12) : hours;
		
		//Departure
		printf("Closest departure time is %d:%.2d ", hours12, minutes);
		if (hours <= 12 && hours != 0)
			printf("AM");
		else
			printf("PM");
		
		//Arrival
		hours = aFlight7 / 60;
		minutes = aFlight7 % 60;
		hours12 = hours > 12 ? (hours - 12) : hours;
		
		printf(", arriving at %d:%.2d ", hours12, minutes);
		if (hours <= 12 && hours != 0)
			printf("AM");
		else
			printf("PM");
	}
	else if (minSinceMidnight <= dFlight8)
	{
		hours = dFlight8 / 60;
		minutes = dFlight8 % 60;
		hours12 = hours > 12 ? (hours - 12) : hours;
		
		//Departure
		printf("Closest departure time is %d:%.2d ", hours12, minutes);
		if (hours <= 12 && hours != 0)
			printf("AM");
		else
			printf("PM");
		
		//Arrival
		hours = aFlight8 / 60;
		minutes = aFlight8 % 60;
		hours12 = hours > 12 ? (hours - 12) : hours;
		
		printf(", arriving at %d:%.2d ", hours12, minutes);
		if (hours <= 12 && hours != 0)
			printf("AM");
		else
			printf("PM");
	}
	else
	{
		printf("There are no more flights for the rest of the day.");
	}
	
	return (0);
}