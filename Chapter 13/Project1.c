/* Write a program that finds the "smallest" and "largest" in a series of words. */


#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper
#include <string.h>   // for strcpy and strcat
#include <stdbool.h> // for booleans

#define STR_LENGTH 20


int main (void)
{
	char input[STR_LENGTH+1] = "", smallest[STR_LENGTH+1] = "zzzzzzzzzzzzzzzzzzzz", largest[STR_LENGTH+1] = "";

	while(strlen(input) != 5)
	{
		printf("Enter word: ");
		fgets(input, STR_LENGTH, stdin);

		if(strlen(input) < strlen(smallest))
		{
			strcpy(smallest, input);
		}
		else if(strlen(input) == strlen(smallest))
		{
			if(strcmp(input, smallest) <= 0)
				strcpy(smallest, input);
		}

		if(strlen(input) > strlen(largest))
		{
			strcpy(largest, input);
		}
		else if(strlen(input) == strlen(largest))
		{
			if(strcmp(input, largest) <= 0)
				strcpy(largest, input);
		}
	}

	printf("Largest: ");
	puts(largest);

	printf("Smallest: ");
	puts(smallest);

	return 0;
}
