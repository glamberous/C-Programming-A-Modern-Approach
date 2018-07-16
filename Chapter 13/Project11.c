/* Double Commit */

/* calculates the average word length for a sentence */
#include <stdio.h>		// for typef & scanf
#include <ctype.h>		// for toupper

#define STR_MAX 100

double compute_average_word_length(const char *);

int main(void)
{
	char str[STR_MAX + 1];

	printf ("Enter a sentence: ");
	printf("Average word length: %.1f", compute_average_word_length(fgets(str, STR_MAX, stdin)));

	return 0;
}

double compute_average_word_length(const char *sentence)
{
	int i = 0, letterCount = 0, wordCount = 0;

	while (1)
	{
		while (isalpha(sentence[i]) == 0)
		{
			if (sentence[i] == '\n')
			{
				return ((float) letterCount / wordCount);
			}
			i++;
		}

		while (isalpha(sentence[i]) != 0)
		{
			letterCount++; i++;
		}
		wordCount++;
	}
}
