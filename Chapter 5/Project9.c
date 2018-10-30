/*Figure out which calendar date is sooner*/
#include <stdio.h>

int main(void)
{
	int month1, day1, year1,
	month2, day2, year2;
	
	printf ("Enter first date (mm/dd/yy): ");
	scanf("%d/%d/%d", &month1, &day1, &year1);
	printf ("Enter second date (mm/dd/yy): ");
	scanf("%d/%d/%d", &month2, &day2, &year2);
	
	if (year1 == year2)
	{
		if (month1 == month2)
		{
			if(day1 == day2)
			{
				printf("These are the same day!");
			}
			else if (day1 < day2)
			{
				printf("%d/%.2d/%.2d is earlier than %d/%.2d/%.2d", month1, day1, year1, month2, day2, year2);
			}
			else
			{
				printf("%d/%.2d/%.2d is earlier than %d/%.2d/%.2d", month2, day2, year2, month1, day1, year1);
			}
		}
		else if (month1 < month2)
		{
			printf("%d/%.2d/%.2d is earlier than %d/%.2d/%.2d", month1, day1, year1, month2, day2, year2);
		}
		else
		{
			printf("%d/%.2d/%.2d is earlier than %d/%.2d/%.2d", month2, day2, year2, month1, day1, year1);
		}
	}
	else if(year1 < year2)
	{
		printf("%d/%.2d/%.2d is earlier than %d/%.2d/%.2d", month1, day1, year1, month2, day2, year2);
	}
	else
	{
		printf("%d/%.2d/%.2d is earlier than %d/%.2d/%.2d", month2, day2, year2, month1, day1, year1);
	}
	
	return 0;
}