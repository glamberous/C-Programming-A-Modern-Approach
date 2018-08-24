/* create a program that will convert total seconds into hour, min, second format */
// 26400 = 7:20am

#include <stdio.h>

struct time
{
	int hours;
	int minutes;
	int seconds;
};

struct time split_time(long total_seconds);

int main(void)
{
	long total_seconds = 0;
	struct time convert_this;

	printf("Please input a time in seconds to convert: ");
	scanf("%ld", &total_seconds);

	convert_this = split_time(total_seconds);
	printf("Converted time: %d:%d:%d\n", convert_this.hours, convert_this.minutes, convert_this.seconds);
}

struct time split_time(long total_seconds)
{
	struct time x;

	x.seconds = (total_seconds % 60);
	x.minutes = (total_seconds / 60) % 60;
	x.hours = (total_seconds / 60) / 60;

	return x;
}
