/*Figure out which calendar date is sooner*/
#include <stdio.h>

int main(void)
{
	int number;
	char *tens[] = {"", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy",
								"Eighty", "Ninety"},
	*ones[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"},
	*teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
							"Seventeen", "Eighteen", "Nineteen"};

	printf ("Enter a two-digit number: ");
	scanf("%d", &number);
	printf("You entered the number ");

	if (number >= 20)
	{
		printf("%s", tens[(number / 10) - 1]);
		if (number % 10 != 0)
		{
			printf(" %s\n", ones[(number % 10) - 1]);
		}
	}
	else if (number >= 10)
	{
		printf("%s\n", teens[(number - 10)]);
	}
	else if (number > 0)
	{
		printf("%s\n", ones[number - 1]);
	}
	else if (number == 0)
	{
		printf("Zero\n");
	}

	return 0;
}
