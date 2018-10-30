
/*
User inputs a time in 12-hour format and the program will list a
known flight departure time closest to the time the user entered
*/

/*
Modify Programming Project 8 from Chapter 5 so that the program obtains departure
and arrival times from a file named flights.dat. Each line of the file will contain
a departure time followed by an arrival time, with one or more spaces separating
the two. Times will be expressed using the 24-hour clock. For example, here's what
flights.dat might look like if it contained the flight information listed in the
original project:
8:00 10:16
9:43 11:52
11:19 13:31
12:47 15:00
14:00 16:08
15:45 17:55
19:00 21:20
21:45 23:58
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define LINE_LEN 50

char calculate_AM_PM(int *hours);

int main(int argc, char *arg[])
{
  char AM_PM = 0;
  int stdin_midnight = 0, file_midnight = 0, hours = 0, minutes = 0;
	//User inputs 12-hour time
	printf("\nEnter a 12-hour time (Example: 3:46pm): ");
	scanf("%d:%2d%c", &hours, &minutes, &AM_PM);

	//Converts the user's input to minSinceMidnight
	stdin_midnight = (hours * 60) + minutes;
  AM_PM = toupper(AM_PM);
  if (AM_PM == 'P' && hours != 12)
		stdin_midnight += 720;
  else if(AM_PM == 'A' && hours == 12)
    stdin_midnight -= 720;

  FILE *flight_list = NULL;
  if ((flight_list = fopen(arg[1], "rb")) == NULL) {
    printf("%s can't be opened\n", arg[1]);
    exit(EXIT_FAILURE);
  }

  char line[LINE_LEN + 1] = "";
  while(stdin_midnight > file_midnight)
  {
    fgets(line, LINE_LEN, flight_list);
    sscanf(line, "%d:%d", &hours, &minutes);
    file_midnight = (hours * 60) + minutes;
  }
  AM_PM = calculate_AM_PM(&hours);
  printf("Closest departure time is %d:%.2d%cM", hours, minutes, AM_PM);
  sscanf(line, "%*d:%*d %d:%d", &hours, &minutes);
  AM_PM = calculate_AM_PM(&hours);
  printf(", arriving at %d:%.2d%cM\n", hours, minutes, AM_PM);

  fclose(flight_list);
  return 0;
}

char calculate_AM_PM(int *hours)
{
  if(*hours < 12 || *hours == 24) {
    if(*hours == 24)
      *hours = 0;
    return 'A';
  }
  else {
    if (*hours != 12)
      *hours -= 12;
    return 'P';
  }
}
