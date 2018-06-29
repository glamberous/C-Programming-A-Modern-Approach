/* calculates the average word length for a sentence */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

int main(void)
{	
	char ch = 0;
	int letterCount = 0, wordCount = 0;
	float average = 0;
	
	printf ("Enter a sentence: ");
	
	while (ch != '\n')
	{
	ch = getchar();
		while (ch != ' ' && ch != '\n')
		{
			letterCount++;
			ch = getchar();
		}
	wordCount++;
	}
	
	average = (float) letterCount / wordCount;
		
	printf("Average word length: %.1f", average);
	
	return (0);
}