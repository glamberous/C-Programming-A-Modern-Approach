#include <stdio.h>			//printf / scanf
#include <stdbool.h>		//booleans
#include <stdlib.h>			//Random number generator




void split_time(long total_sec, int *hr, int *min, int *sec);


int main(void)
{
	int hr, min, sec;
	long time;
	
	printf("Please enter time in seconds since midnight: ");
	scanf("%ld", &time);

	split_time(time, &hr, &min, &sec);
	
	printf("hours: %d\tminutes: %d\tseconds: %d", hr, min, sec);

}

void split_time(long total_sec, int *hr, int *min, int *sec)
{
	*sec = total_sec % 60;
	*min = (total_sec / 60) % 60;
	*hr =  (total_sec / 60) / 60;
	
}

