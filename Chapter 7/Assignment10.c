/* Program counts the number of vowels in a user's input */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

int main(void)
{	
	char ch = 0;															
	int vowels = 0;
	
	
	printf ("This program will count the number of vowels that are in your input");
	printf ("Enter a sentence: ");
	
	while (ch != '\n')
	{
		ch = getchar();
		ch = toupper(ch);
		
		if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
			vowels++;
	}
	
	printf ("Your sentence contains %d vowels.\n", vowels);
	
	return (0);
}