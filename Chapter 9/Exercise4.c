/* Exercises that do things */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper




short day_of_year(short month, short day, short year)
{	
	short sum = 0;
	
	switch (month-1) 
	{
		case 11: sum += 30;
		case 10: sum += 31;
		case 9: sum += 30;
		case 8: sum += 31;
		case 7: sum += 31;
		case 6: sum += 30;
		case 5: sum += 31;
		case 4: sum += 30;
		case 3: sum += 31;
		case 2: sum += 28;
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
				sum += 1;
		case 1: sum += 31;
		case 0: break;
		default: printf("Invalid input.\n"); return(0);
	}
	
	return (sum + day);
}


int main(void)
{	
	short month = 0, day = 0, year = 0;
	
	printf("Enter in a month, day, and a year (mm/dd/yyyy format): ");
	scanf("%hd/%hd/%hd", &month, &day, &year);
	printf("The day count for that day is: %hd", day_of_year(month, day, year));
	
	return (0);
}