/*Buns not hot*/
#include <stdio.h>

int main(void)
{
	int month, day, year;
	printf("Enter a date in mm/dd/yyyy format: ");
	scanf("%d/%d/%d", &month, &day, &year);
	printf("Your entered date now in yyyymmdd format: %d%.2d%.2d\n", year, month, day);
	
	return 0;
}