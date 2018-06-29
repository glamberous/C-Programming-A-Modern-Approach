/* User inputs a time in 12-hour format and the program will list a 
known flight departure time closest to the time the user entered  */
#include <stdio.h>
#include <stdbool.h>		//booleans
#include <ctype.h>		// for toupper
#include <stdlib.h>

int get_input(void);
void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);
void print_result(int departure_time, int arrival_time);

int 		flightArrival[8] = {616, 712, 811, 900, 968, 1075, 1280, 1438}, 
			flightDeparture[8] = {480, 583, 679, 767, 840, 945, 1140, 1305};

int main(void)
{		
	int arrival = 0, departure = 0, temp = 0; 
	
	temp = get_input();
	find_closest_flight(temp, &departure, &arrival);
	print_result(departure, arrival);

}

int get_input(void)
{
	char ch = 0;
	int hours = 0, minutes = 0, minSinceMidnight = 0;
	
	//User inputs 12-hour time
	printf("\nEnter a 12-hour time (Example: 3:46pm): ");
	scanf("%d:%d", &hours, &minutes);
	
	while (ch != '\n')
	{
		ch = getchar();
		ch = toupper(ch);
		if(ch == 'A' || ch == 'P')
			break;
	}
	
	minSinceMidnight = (hours * 60) + minutes;
	
	if (ch == 'P')
	{
		minSinceMidnight += 720;
	}
	else if (ch == '\n')
	{
		printf("Entry invalid.");
		exit(EXIT_SUCCESS);
	}
	
	return minSinceMidnight;
}
	
void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
	int i;
	
	for(i = 0; desired_time > flightDeparture[i]; i++)
		/* intentionally null */;

	*departure_time = flightDeparture[i];
	*arrival_time = flightArrival[i];
}

void print_result(int departure_time, int arrival_time)
{
	int hours = 0, minutes = 0;
	
	hours = departure_time / 60;
	minutes = departure_time % 60;
	
	printf("Closest departure time is %d:%.2d ", ((hours > 12) ? (hours - 12) : hours), minutes);
	printf("%c.m.", ((hours <= 12 && hours != 0) ? 'a' : 'p'));
	
	hours = arrival_time / 60;
	minutes = arrival_time % 60;
	
	printf(" with the arrival time of %d:%.2d ", ((hours > 12) ? (hours - 12) : hours), minutes);
	printf("%c.m.", ((hours <= 12 && hours != 0) ? 'a' : 'p'));
	
}
	
/*	else if (minSinceMidnight <= dFlight8)
	{
		hours = dFlight8 / 60;
		minutes = dFlight8 % 60;
		if (hours > 12)
		{
			hours12 = hours - 12;
		}
		else
		{
			hours12 = hours;
		}
		
		//Departure
		printf("Closest departure time is %d:%.2d ", hours12, minutes);
		if (hours <= 12 && hours != 0)
		{
			printf("a.m.");
		}
		else
		{
			printf("p.m.");
		}
		
		//Arrival
		hours = aFlight8 / 60;
		minutes = aFlight8 % 60;
		if (hours > 12)
		{
			hours12 = hours - 12;
		}
		else
		{
			hours12 = hours;
		}
		
		printf(", arriving at %d:%.2d ", hours12, minutes);
		if (hours <= 12 && hours != 0)
		{
			printf("a.m.");
		}
		else
		{
			printf("p.m.");
		}
	}
	else
	{
		printf("There are no more flights for the rest of the day.");
	}
	
	return 0;
}*/