/* Learning how to initialize structures again! */

#define D_RANGE_ERR printf("Invalid input, Date out of bounds.")

#include <stdio.h>

struct date
{
	int month;
	int day;
	int year;
};

int day_of_year(struct date);
int compare_dates(struct date, struct date);

int main(void)
{
	struct date	christmas = {12, 25, 2018},
							halloween = {10, 31, 2018},
							birthday 	= {7, 28, 1989};

	printf("Birthday is on %d/%d/%d.\n", birthday.month, birthday.day, birthday.year);
	printf("Day of the year is: %d\n", day_of_year(birthday));

	printf("halloween is ");
	if(compare_dates(halloween, birthday) < 0)
		printf("before ");
	else if(compare_dates(halloween, birthday) > 0)
		printf("after ");
	else
		printf("the same day as ");

	printf("my birthday.\n");

	return 0;
}

int day_of_year(struct date x)
{
	int day_of_year = 0;

	switch(x.month)
	{
		case 12:	day_of_year += 30;
		case 11: 	day_of_year += 31;
		case 10:	day_of_year += 30;
		case 9:	day_of_year += 31;
		case 8:	day_of_year += 31;
		case 7:	day_of_year += 30;
		case 6:	day_of_year += 31;
		case 5:	day_of_year += 30;
		case 4:	day_of_year += 31;
		case 3: day_of_year += 28;
		if(((x.year % 4) == 0 && (x.year % 100) != 0) || (x.year % 400 == 0))
			day_of_year += 1;
		case 2: day_of_year += 31;
		case 1: break;
		default: D_RANGE_ERR; return 0;
	}
	day_of_year += x.day;

	return day_of_year;
}

int compare_dates(struct date x, struct date y)
{

	if (day_of_year(x) < day_of_year(y))
		return -1;
	else if (day_of_year(x) > day_of_year(y))
		return 1;
	else
		return 0;
}
