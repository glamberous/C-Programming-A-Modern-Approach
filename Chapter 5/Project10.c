/*Figure out which calendar date is sooner*/
#include <stdio.h>

int main(void)
{
	int number;
	
	printf ("Enter a two-digit number: ");
	scanf("%d", &number);
	printf("You entered the number ");
	
	if ((number >= 10 && number < 20) || number == 0)
	{
		switch (number)
		{
			case 0: printf("Zero"); break;
			case 10: printf("Ten"); break;
			case 11: printf("Eleven"); break;
			case 12: printf("Twelve"); break;
			case 13: printf("Thirteen"); break;
			case 14: printf("Fourteen"); break;
			case 15: printf("Fifteen"); break;
			case 16: printf("Sixteen"); break;
			case 17: printf("Seventeen"); break;
			case 18: printf("Eighteen"); break;
			case 19: printf("Nineteen"); break;
		}
	}
	else
	{
		switch (number / 10)
		{
			case 9: printf("Ninety"); break;
			case 8: printf("Eighty"); break;
			case 7: printf("Seventy"); break;
			case 6: printf("Sixty"); break;
			case 5: printf("Fifty"); break;
			case 4: printf("Fourty"); break;
			case 3: printf("Thirty"); break;
			case 2: printf("Twenty"); break;
			case 1:
			case 0: break;
		}
		
		if ((number % 10 != 0) && number > 10)
		{
			printf("-");
		}
		
		switch (number % 10)
		{
			case 9: printf("Nine"); break;
			case 8: printf("Eight"); break;
			case 7: printf("Seven"); break;
			case 6: printf("Six"); break;
			case 5: printf("Five"); break;
			case 4: printf("Four"); break;
			case 3: printf("Three"); break;
			case 2: printf("Two"); break;
			case 1: printf("One"); break;
			case 0: break;
		}
	}
		

	
	return 0;
}