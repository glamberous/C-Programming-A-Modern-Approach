/* Improve the remind.c program */

#include <stdio.h>		// for typef & scanf

#include <string.h>   // for strcpy and strcat


#define MAX_REMIND 50 /* maximum number of reminders */
#define MSG_LEN 60 /* max length of reminder message */

int read_line(char str[], int n);

int main (void)
{
	char reminders[MAX_REMIND][MSG_LEN+2];
	int i, num_remind = 0;

	for(; ;)
	{
		char date_time_str[12] = {""}, msg_str[MSG_LEN+1];
		int month = 0, day = 0, hours = 0, minutes = 0, j;

		if (num_remind == MAX_REMIND)
		{
			printf("-- No space left --\n");
			break;
		}

		printf("Enter day and reminder (mm/dd 00:00 format): ");
		scanf("%2d/%2d %2d:%2d", &month, &day, &hours, &minutes);

		if (month == 0 || day == 0)
		{
			break;
		}
		else if(month < 0 || month > 12 || day < 0 || day > 31 || hours > 24 ||
			hours < 0 || minutes > 59 || minutes < 0)
		{
			printf("-- Invalid date or time --\n");
			while((getchar()) != '\n');
			continue;
		}

		sprintf(date_time_str, "%2d/%.2d %2d:%.2d", month, day, hours, minutes);
		read_line(msg_str, MSG_LEN);

		for(i = 0; i < num_remind; i++)
		{
			if (strcmp(date_time_str, reminders[i]) < 0)
				break;
		}
		for(j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j-1]);

		strcpy(reminders[i], date_time_str);
		strcat(reminders[i], msg_str);

		num_remind++;
	}

	printf("\n mm/dd  Time Reminder\n");
	for (i = 0; i < num_remind; i++)
		printf(" %s\n", reminders[i]);

	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n')
	{
		if (i < n)
		{
			str[i++] = ch;
		}
	}
	str[i] = '\0';
	return i;
}
