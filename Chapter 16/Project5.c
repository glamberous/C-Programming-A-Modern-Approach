/* User inputs a time in 12-hour format and the program will list a
known flight departure time closest to the time the user entered  */
#include <stdio.h>
#include <ctype.h>

#define NUM_FLIGHTS 8

struct flight_times {
	int departure;
	int arrival;
};

int get_time(void);
void print_flight(int usertime, struct flight_times[NUM_FLIGHTS]);

int main(void)
{
	struct flight_times flights[NUM_FLIGHTS] = {
		{480, 616}, {583, 712}, {679, 811}, {767, 900}, {840, 968},
		{945, 1075}, {1140, 1280}, {1305, 1438}};
	int usertime = 0;

	usertime = get_time();
	print_flight(usertime, flights);
	return 0;
}

void print_flight(int usertime, struct flight_times flights[NUM_FLIGHTS])
{
	int temp_hour = 0, i = 0;
	char ch = '0';

	for(i = 0; i < NUM_FLIGHTS; i++)
	{
		if (usertime <= flights[i].departure)
		{
			//Departure
			temp_hour = flights[i].departure / 60;
			ch = (temp_hour <= 12 && temp_hour != 0) != 0 ? 'A' : 'P';
			temp_hour = temp_hour > 12 ? temp_hour - 12 : temp_hour;
			printf("Closest departure time is %d:%.2d %cM\n", temp_hour, (flights[i].departure % 60), ch);

			//Arrival
			temp_hour = flights[i].arrival / 60;
			ch = (temp_hour <= 12 && temp_hour != 0) ? 'A' : 'P';
			temp_hour = temp_hour > 12 ? temp_hour - 12 : temp_hour;
			printf("With an arrival time of %d:%.2d %cM\n", temp_hour, (flights[i].arrival % 60), ch);

			return;
		}
	}
	printf("There are no more flights for the rest of the day.");
	return;
}

int get_time(void)
{
	char ch = '0';
	int hours = 0, minutes = 0, minSinceMidnight = 0;
	enum morning_evening {NDEF, AM, PM} AM_PM = NDEF;

	//User inputs 12-hour time
	printf("\nEnter a 12-hour time (Example: 3:46pm): ");
	scanf("%d:%d", &hours, &minutes);

	while (AM_PM == NDEF)									//Determines whether AM or PM was inputted
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
			default: break;
		}
	}

	//Converts the user's input to minSinceMidnight
	minSinceMidnight = (hours * 60) + minutes;

	if (AM_PM == PM)
	{
		minSinceMidnight += 720;
	}
	return minSinceMidnight;
}
