/*Figure out which calendar date is sooner*/
#include <stdio.h>

int main(void)
{
int month, day, year, earlyMonth, earlyDay, earlyYear;
	
earlyMonth = 99;
earlyDay = 99;
earlyYear = 99;
month = 99;
day = 99;
year = 99;
	
do 
{
	if (year < earlyYear)
	{
		earlyYear = year;
		earlyMonth = month;
		earlyDay = day;
	}
	else if (year == earlyYear)
	{
		if (month < earlyMonth)
		{
			earlyYear = year;
			earlyMonth = month;
			earlyDay = day;
		}
		else if (month == earlyMonth)
		{
			if (day < earlyDay)
			{
				earlyYear = year;
				earlyMonth = month;
				earlyDay = day;
			}
		}
	}
	printf ("Enter a date (mm/dd/yy): ");
	scanf("%d/%d/%d", &month, &day, &year);

} while (month != 0 && day != 0 && year != 0);
	
	printf ("%.2d/%.2d/%.2d is the earliest date", earlyMonth, earlyDay, earlyYear);

return 0;
}